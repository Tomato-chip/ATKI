// Ping-Pong Buffer using two Gowin SP single-port BSRAMs
// 16-bit × 256-sample double-buffered memory with full handshaking
//
// Features:
// - Write to one RAM while reading from the other
// - Full AXI-Stream-like handshaking on both write and read sides
// - Backpressure support (wr_ready_o, rd_ready_i)
// - Buffer management (buf_ready_o, buf_take_i, buf_empty_o)
// - Error detection (overrun_o, underrun_o)
// - READ_MODE = BYPASS for zero-latency reads
// - WRITE_MODE = NORMAL for synchronous writes

module pingpong_buffer_sp #(
    parameter int unsigned SAMPLE_W = 16,   // Sample width in bits
    parameter int unsigned BUF_LEN  = 256   // Buffer length (samples per buffer)
) (
    // Clock & reset
    input  logic                clk_i,
    input  logic                rst_ni,     // Active-low synchronous reset

    // Write side (from sampler/producer)
    input  logic [SAMPLE_W-1:0] wr_data_i,
    input  logic                wr_valid_i,     // Producer has data
    output logic                wr_ready_o,     // Buffer can accept data
    input  logic                sample_ready_i, // Optional: 1-clk strobe per sample
    input  logic                frame_start_i,  // Optional: frame boundary marker

    // Read side (to consumer)
    output logic [SAMPLE_W-1:0] rd_data_o,
    output logic                rd_valid_o,     // Buffer has data for consumer
    input  logic                rd_ready_i,     // Consumer ready to accept
    output logic                rd_last_o,      // Last word (256th) of block

    // Buffer/status signals
    output logic                buf_ready_o,    // 1-clk pulse: buffer filled
    output logic                buf_id_o,       // Which RAM is ready (0/1)
    input  logic                buf_take_i,     // Consumer starts reading buffer
    output logic                buf_empty_o,    // No filled buffers available
    output logic                overrun_o,      // Writer stalled (both bufs occupied)
    output logic                underrun_o      // Reader requested but no data
);

    // Address width for BUF_LEN samples
    localparam int unsigned AW = $clog2(BUF_LEN);

    // Pack address for SP RAM: AD = {2'b00, addr[AW-1:0], 4'b0000}
    function automatic logic [13:0] pack_addr(input logic [AW-1:0] addr);
        return {2'b00, addr, 4'b0000};
    endfunction

    // =========================================================================
    // Internal state
    // =========================================================================

    // Buffer selection: 0 = RAM0, 1 = RAM1
    logic wr_buf_sel;           // Which RAM is currently being written
    logic rd_buf_sel;           // Which RAM is currently being read

    // Write address counter
    logic [AW-1:0] wr_addr;

    // Read address counter
    logic [AW-1:0] rd_addr;

    // Buffer state tracking
    typedef enum logic [1:0] {
        BUF_EMPTY,              // Buffer is empty (available for writing)
        BUF_WRITING,            // Buffer is being written
        BUF_READY,              // Buffer is full and ready for reading
        BUF_READING             // Buffer is being read
    } buf_state_t;

    buf_state_t buf0_state, buf1_state;

    // =========================================================================
    // Write-side logic
    // =========================================================================

    // Sample beat: when to accept a write
    // If sample_ready_i is used, only count on its strobe
    // If unused (tied high), count every valid/ready handshake
    logic sample_beat;
    assign sample_beat = wr_valid_i && wr_ready_o && sample_ready_i;

    // Write ready: asserted when current write buffer is accepting data
    logic wr_buf_accepting;
    always_comb begin
        if (wr_buf_sel == 1'b0) begin
            wr_buf_accepting = (buf0_state == BUF_EMPTY || buf0_state == BUF_WRITING);
        end else begin
            wr_buf_accepting = (buf1_state == BUF_EMPTY || buf1_state == BUF_WRITING);
        end
    end
    assign wr_ready_o = wr_buf_accepting;

    // Write logic
    logic wr_buf_complete;
    assign wr_buf_complete = sample_beat && (wr_addr == BUF_LEN-1);

    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            wr_addr      <= '0;
            wr_buf_sel   <= 1'b0;       // Start writing to RAM0
            buf_ready_o  <= 1'b0;
            buf_id_o     <= 1'b0;
            overrun_o    <= 1'b0;
        end else begin
            buf_ready_o  <= 1'b0;       // Pulse signal, default low

            // Increment write address on each sample beat
            if (sample_beat) begin
                if (wr_buf_complete) begin
                    wr_addr <= '0;
                end else begin
                    wr_addr <= wr_addr + 1'b1;
                end
            end

            // Buffer completion: emit buf_ready_o and swap write buffer
            if (wr_buf_complete) begin
                buf_ready_o <= 1'b1;
                buf_id_o    <= wr_buf_sel;
                wr_buf_sel  <= ~wr_buf_sel;     // Swap to other buffer
            end

            // Overrun detection: trying to write but both buffers occupied
            if (wr_valid_i && !wr_ready_o) begin
                overrun_o <= 1'b1;
            end else if (sample_beat) begin
                overrun_o <= 1'b0;              // Clear on progress
            end
        end
    end

    // =========================================================================
    // Read-side logic
    // =========================================================================

    // Read state machine
    typedef enum logic [1:0] {
        RD_IDLE,                // Waiting for a buffer to become ready
        RD_ACTIVE               // Actively streaming data
    } rd_state_t;

    rd_state_t rd_state;

    // Read beat: when a read transfer occurs
    logic rd_beat;
    assign rd_beat = rd_valid_o && rd_ready_i;

    // Last word of read block
    logic rd_buf_complete;
    assign rd_buf_complete = rd_beat && (rd_addr == BUF_LEN-1);

    // rd_last should be asserted when on the last address BEFORE the beat completes
    assign rd_last_o = (rd_state == RD_ACTIVE) && (rd_addr == BUF_LEN-1);

    // Buffer has data ready to read
    logic rd_buf_has_data;
    always_comb begin
        if (rd_buf_sel == 1'b0) begin
            rd_buf_has_data = (buf0_state == BUF_READY || buf0_state == BUF_READING);
        end else begin
            rd_buf_has_data = (buf1_state == BUF_READY || buf1_state == BUF_READING);
        end
    end

    // Read state machine
    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            rd_state    <= RD_IDLE;
            rd_addr     <= '0;
            rd_buf_sel  <= 1'b1;        // Start reading from RAM1 (after first write to RAM0)
            rd_valid_o  <= 1'b0;
            buf_empty_o <= 1'b1;
            underrun_o  <= 1'b0;
        end else begin
            case (rd_state)
                RD_IDLE: begin
                    rd_valid_o  <= 1'b0;
                    buf_empty_o <= 1'b1;

                    // Wait for buf_take_i to start reading a ready buffer
                    if (buf_take_i) begin
                        // Consumer is taking the buffer that was signaled via buf_ready_o
                        // The buf_id_o tells us which one
                        rd_buf_sel  <= buf_id_o;
                        rd_addr     <= '0;
                        rd_state    <= RD_ACTIVE;
                        rd_valid_o  <= 1'b1;
                        buf_empty_o <= 1'b0;
                    end

                    // Underrun: consumer wants data but none available
                    if (rd_ready_i && !rd_buf_has_data) begin
                        underrun_o <= 1'b1;
                    end
                end

                RD_ACTIVE: begin
                    rd_valid_o <= 1'b1;
                    underrun_o <= 1'b0;

                    // Advance read address on each beat
                    if (rd_beat) begin
                        if (rd_buf_complete) begin
                            rd_addr    <= '0;
                            rd_state   <= RD_IDLE;
                            rd_valid_o <= 1'b0;
                        end else begin
                            rd_addr <= rd_addr + 1'b1;
                        end
                    end
                end
            endcase
        end
    end

    // =========================================================================
    // Buffer state tracking
    // =========================================================================

    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            buf0_state <= BUF_EMPTY;
            buf1_state <= BUF_EMPTY;
        end else begin
            // Buffer 0 state transitions
            case (buf0_state)
                BUF_EMPTY: begin
                    if (wr_buf_sel == 1'b0 && sample_beat) begin
                        buf0_state <= BUF_WRITING;
                    end
                end
                BUF_WRITING: begin
                    if (wr_buf_sel == 1'b0 && wr_buf_complete) begin
                        buf0_state <= BUF_READY;
                    end
                end
                BUF_READY: begin
                    if (buf_take_i && buf_id_o == 1'b0) begin
                        buf0_state <= BUF_READING;
                    end
                end
                BUF_READING: begin
                    if (rd_buf_sel == 1'b0 && rd_buf_complete) begin
                        buf0_state <= BUF_EMPTY;
                    end
                end
            endcase

            // Buffer 1 state transitions
            case (buf1_state)
                BUF_EMPTY: begin
                    if (wr_buf_sel == 1'b1 && sample_beat) begin
                        buf1_state <= BUF_WRITING;
                    end
                end
                BUF_WRITING: begin
                    if (wr_buf_sel == 1'b1 && wr_buf_complete) begin
                        buf1_state <= BUF_READY;
                    end
                end
                BUF_READY: begin
                    if (buf_take_i && buf_id_o == 1'b1) begin
                        buf1_state <= BUF_READING;
                    end
                end
                BUF_READING: begin
                    if (rd_buf_sel == 1'b1 && rd_buf_complete) begin
                        buf1_state <= BUF_EMPTY;
                    end
                end
            endcase
        end
    end

    // =========================================================================
    // SP RAM instances
    // =========================================================================

    // RAM control signals
    logic [13:0] addr_ram0, addr_ram1;
    logic        wre_ram0, wre_ram1;
    logic [SAMPLE_W-1:0] do_ram0, do_ram1;

    // Address and write-enable muxing
    always_comb begin
        // Defaults
        addr_ram0 = '0;
        addr_ram1 = '0;
        wre_ram0  = 1'b0;
        wre_ram1  = 1'b0;

        if (wr_buf_sel == 1'b0) begin
            // RAM0 is write buffer, RAM1 is read buffer
            addr_ram0 = pack_addr(wr_addr);
            addr_ram1 = pack_addr(rd_addr);
            wre_ram0  = sample_beat;
            wre_ram1  = 1'b0;
        end else begin
            // RAM1 is write buffer, RAM0 is read buffer
            addr_ram0 = pack_addr(rd_addr);
            addr_ram1 = pack_addr(wr_addr);
            wre_ram0  = 1'b0;
            wre_ram1  = sample_beat;
        end
    end

    // Output data muxing (from read buffer)
    always_comb begin
        if (rd_buf_sel == 1'b0) begin
            rd_data_o = do_ram0;
        end else begin
            rd_data_o = do_ram1;
        end
    end

    // SP RAM instance 0
    SP u_ram0 (
        .DO     (do_ram0),
        .CLK    (clk_i),
        .CE     (1'b1),
        .OCE    (1'b0),
        .RESET  (!rst_ni),          // Active high, sync reset
        .WRE    (wre_ram0),
        .BLKSEL (3'b000),
        .AD     (addr_ram0),
        .DI     (wr_data_i)
    );
    defparam u_ram0.BIT_WIDTH  = SAMPLE_W;
    defparam u_ram0.READ_MODE  = 1'b1;      // BYPASS mode
    defparam u_ram0.WRITE_MODE = 2'b00;     // NORMAL mode
    defparam u_ram0.BLK_SEL    = 3'b000;
    defparam u_ram0.RESET_MODE = "SYNC";

    // SP RAM instance 1
    SP u_ram1 (
        .DO     (do_ram1),
        .CLK    (clk_i),
        .CE     (1'b1),
        .OCE    (1'b0),
        .RESET  (!rst_ni),          // Active high, sync reset
        .WRE    (wre_ram1),
        .BLKSEL (3'b000),
        .AD     (addr_ram1),
        .DI     (wr_data_i)
    );
    defparam u_ram1.BIT_WIDTH  = SAMPLE_W;
    defparam u_ram1.READ_MODE  = 1'b1;      // BYPASS mode
    defparam u_ram1.WRITE_MODE = 2'b00;     // NORMAL mode
    defparam u_ram1.BLK_SEL    = 3'b000;
    defparam u_ram1.RESET_MODE = "SYNC";

endmodule
