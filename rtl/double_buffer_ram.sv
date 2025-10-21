// =============================================================================
// double_buffer_ram.sv
// Double-buffer (ping-pong) RAM controller for continuous sampling
// =============================================================================
// Implements two RAM buffers (A/B) that alternate between write and read.
// While one buffer is being written with incoming samples, the other can be
// read by an external reader. When SAMPLES_PER_BUF samples are written,
// buffers swap roles and a buf_ready_pulse indicates completion.
// =============================================================================

module double_buffer_ram #(
    parameter int unsigned DATA_WIDTH      = 16,
    parameter int unsigned SAMPLES_PER_BUF = 256,
    parameter int unsigned ADDR_WIDTH      = $clog2(SAMPLES_PER_BUF),
    parameter bit          SYNTH_USE_GOWIN_DPB = 1'b1,  // 1=Gowin DPB, 0=generic
    parameter bit          DROP_WRITES_ON_TOGGLE = 1'b1 // Drop writes during toggle cycle
)(
    input  logic                     clk_i,
    input  logic                     rst_ni,           // Active-low synchronous reset

    // Write side (sampling in)
    input  logic                     in_valid_i,       // Write enable
    input  logic [DATA_WIDTH-1:0]    in_data_i,        // Sample data
    output logic                     in_ready_o,       // Back-pressure (1=can accept)

    // Read side (from inactive buffer)
    input  logic [ADDR_WIDTH-1:0]    rd_addr_i,        // External read address
    input  logic                     rd_en_i,          // Read enable
    output logic [DATA_WIDTH-1:0]    rd_data_o,        // Read data from inactive buffer
    output logic                     rd_data_valid_o,  // Read data valid (pipelined)

    // Status / control
    output logic                     active_buf_o,     // 0=A writing, 1=B writing
    output logic                     buf_ready_pulse_o,// 1-cycle pulse when buffer full
    output logic                     buf_ready_id_o    // 0=A filled, 1=B filled
);

    // =========================================================================
    // Internal signals
    // =========================================================================
    logic [ADDR_WIDTH-1:0]  write_addr;
    logic [ADDR_WIDTH-1:0]  write_addr_q;  // Delayed by 1 cycle for RAM write
    logic                   write_enable;
    logic                   buffer_full;
    logic                   toggle_buffers;

    // RAM signals for buffer A
    logic                   ram_a_wea;
    logic [ADDR_WIDTH-1:0]  ram_a_waddr;
    logic [DATA_WIDTH-1:0]  ram_a_wdata;
    logic [ADDR_WIDTH-1:0]  ram_a_raddr;
    logic                   ram_a_reb;
    logic [DATA_WIDTH-1:0]  ram_a_rdata;

    // RAM signals for buffer B
    logic                   ram_b_wea;
    logic [ADDR_WIDTH-1:0]  ram_b_waddr;
    logic [DATA_WIDTH-1:0]  ram_b_wdata;
    logic [ADDR_WIDTH-1:0]  ram_b_raddr;
    logic                   ram_b_reb;
    logic [DATA_WIDTH-1:0]  ram_b_rdata;

    // Read data valid pipeline
    logic                   rd_en_q;

    // =========================================================================
    // Write control logic
    // =========================================================================

    // Write enable - accept incoming writes
    assign write_enable = in_valid_i;
    assign in_ready_o = 1'b1;  // Always ready (could add overflow protection here)

    // Write address counter
    // Maintains the current write address, increments after each successful write
    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            write_addr <= '0;
            write_addr_q <= '0;
        end else begin
            write_addr_q <= write_addr;  // Pipeline previous address
            if (write_enable) begin
                if (write_addr == SAMPLES_PER_BUF - 1) begin
                    write_addr <= '0;
                end else begin
                    write_addr <= write_addr + 1'b1;
                end
            end
        end
    end

    // Detect when buffer is full - write enable at last address
    assign buffer_full = (write_addr == SAMPLES_PER_BUF - 1) && write_enable;
    assign toggle_buffers = buffer_full;

    // Active buffer toggle
    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            active_buf_o <= 1'b0;  // Start with buffer A
        end else if (toggle_buffers) begin
            active_buf_o <= ~active_buf_o;
        end
    end

    // Buffer ready pulse (1 cycle)
    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            buf_ready_pulse_o <= 1'b0;
            buf_ready_id_o    <= 1'b0;
        end else begin
            buf_ready_pulse_o <= toggle_buffers;
            buf_ready_id_o    <= active_buf_o;  // ID of buffer that just filled
        end
    end

    // =========================================================================
    // RAM port assignment
    // =========================================================================

    // Write to active buffer - use current write_addr
    assign ram_a_wea   = write_enable && (active_buf_o == 1'b0);
    assign ram_a_waddr = write_addr;
    assign ram_a_wdata = in_data_i;

    assign ram_b_wea   = write_enable && (active_buf_o == 1'b1);
    assign ram_b_waddr = write_addr;
    assign ram_b_wdata = in_data_i;

    // Read from inactive buffer
    assign ram_a_raddr = rd_addr_i;
    assign ram_a_reb   = rd_en_i && (active_buf_o == 1'b1);  // Read A when B is active

    assign ram_b_raddr = rd_addr_i;
    assign ram_b_reb   = rd_en_i && (active_buf_o == 1'b0);  // Read B when A is active

    // Mux read data from inactive buffer
    assign rd_data_o = (active_buf_o == 1'b0) ? ram_b_rdata : ram_a_rdata;

    // Pipeline read valid signal (DPB has 1-cycle read latency)
    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            rd_en_q <= 1'b0;
        end else begin
            rd_en_q <= rd_en_i;
        end
    end
    assign rd_data_valid_o = rd_en_q;

    // =========================================================================
    // RAM instantiation (Gowin DPB or generic)
    // =========================================================================

    generate
        if (SYNTH_USE_GOWIN_DPB) begin : gen_gowin_dpb
            // Gowin DPB requires 14-bit address (concatenate with zeros)
            logic [13:0] dpb_a_waddr, dpb_a_raddr;
            logic [13:0] dpb_b_waddr, dpb_b_raddr;

            assign dpb_a_waddr = {{(14-ADDR_WIDTH){1'b0}}, ram_a_waddr};
            assign dpb_a_raddr = {{(14-ADDR_WIDTH){1'b0}}, ram_a_raddr};
            assign dpb_b_waddr = {{(14-ADDR_WIDTH){1'b0}}, ram_b_waddr};
            assign dpb_b_raddr = {{(14-ADDR_WIDTH){1'b0}}, ram_b_raddr};

            // Buffer A - Gowin DPB
            DPB #(
                .READ_MODE0  (1'b0),        // Normal read mode
                .READ_MODE1  (1'b0),
                .WRITE_MODE0 (2'b00),       // Normal write
                .WRITE_MODE1 (2'b00),
                .BIT_WIDTH_0 (DATA_WIDTH),  // Port A width
                .BIT_WIDTH_1 (DATA_WIDTH),  // Port B width
                .BLK_SEL_0   (3'b000),
                .BLK_SEL_1   (3'b000),
                .RESET_MODE  ("SYNC")       // Synchronous reset
            ) dpb_buffer_a (
                // Port A - Write
                .CLKA   (clk_i),
                .CEA    (1'b1),
                .RESETA (!rst_ni),          // Active-high reset
                .ADA    (dpb_a_waddr),
                .DIA    (ram_a_wdata),
                .WREA   (ram_a_wea),
                .DOA    (),                 // Unused

                // Port B - Read
                .CLKB   (clk_i),
                .CEB    (1'b1),
                .RESETB (!rst_ni),
                .ADB    (dpb_a_raddr),
                .DIB    ({DATA_WIDTH{1'b0}}),
                .WREB   (1'b0),
                .DOB    (ram_a_rdata)
            );

            // Buffer B - Gowin DPB
            DPB #(
                .READ_MODE0  (1'b0),
                .READ_MODE1  (1'b0),
                .WRITE_MODE0 (2'b00),
                .WRITE_MODE1 (2'b00),
                .BIT_WIDTH_0 (DATA_WIDTH),
                .BIT_WIDTH_1 (DATA_WIDTH),
                .BLK_SEL_0   (3'b000),
                .BLK_SEL_1   (3'b000),
                .RESET_MODE  ("SYNC")
            ) dpb_buffer_b (
                // Port A - Write
                .CLKA   (clk_i),
                .CEA    (1'b1),
                .RESETA (!rst_ni),
                .ADA    (dpb_b_waddr),
                .DIA    (ram_b_wdata),
                .WREA   (ram_b_wea),
                .DOA    (),

                // Port B - Read
                .CLKB   (clk_i),
                .CEB    (1'b1),
                .RESETB (!rst_ni),
                .ADB    (dpb_b_raddr),
                .DIB    ({DATA_WIDTH{1'b0}}),
                .WREB   (1'b0),
                .DOB    (ram_b_rdata)
            );

        end else begin : gen_generic_dpram
            // Generic dual-port RAM for simulation/portability
            generic_dpram #(
                .DATA_WIDTH   (DATA_WIDTH),
                .DEPTH        (SAMPLES_PER_BUF),
                .ADDR_WIDTH   (ADDR_WIDTH)
            ) dpram_buffer_a (
                .clk_i        (clk_i),
                .rst_ni       (rst_ni),
                .wr_en_i      (ram_a_wea),
                .wr_addr_i    (ram_a_waddr),
                .wr_data_i    (ram_a_wdata),
                .rd_en_i      (ram_a_reb),
                .rd_addr_i    (ram_a_raddr),
                .rd_data_o    (ram_a_rdata)
            );

            generic_dpram #(
                .DATA_WIDTH   (DATA_WIDTH),
                .DEPTH        (SAMPLES_PER_BUF),
                .ADDR_WIDTH   (ADDR_WIDTH)
            ) dpram_buffer_b (
                .clk_i        (clk_i),
                .rst_ni       (rst_ni),
                .wr_en_i      (ram_b_wea),
                .wr_addr_i    (ram_b_waddr),
                .wr_data_i    (ram_b_wdata),
                .rd_en_i      (ram_b_reb),
                .rd_addr_i    (ram_b_raddr),
                .rd_data_o    (ram_b_rdata)
            );
        end
    endgenerate

    // =========================================================================
    // Assertions
    // =========================================================================

    `ifndef SYNTHESIS
        // Write address should never exceed SAMPLES_PER_BUF-1
        assert property (@(posedge clk_i) disable iff (!rst_ni)
            write_addr < SAMPLES_PER_BUF)
        else $error("write_addr exceeded SAMPLES_PER_BUF-1");

        // buf_ready_pulse should be 1 cycle wide
        assert property (@(posedge clk_i) disable iff (!rst_ni)
            buf_ready_pulse_o |=> !buf_ready_pulse_o)
        else $error("buf_ready_pulse_o not 1-cycle wide");

        // Only one buffer should have write enable at a time
        assert property (@(posedge clk_i) disable iff (!rst_ni)
            !(ram_a_wea && ram_b_wea))
        else $error("Both buffers enabled for write simultaneously");

        // Active buffer toggles only on buffer full
        assert property (@(posedge clk_i) disable iff (!rst_ni)
            $changed(active_buf_o) |-> $past(buffer_full))
        else $error("active_buf_o toggled without buffer_full");
    `endif

endmodule
