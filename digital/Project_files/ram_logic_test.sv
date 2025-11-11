//==============================================================================
// Module: ram_logic

    // Description:
    //   Ping-pong buffer RAM controller with flexible read/write interface.
    //   Implements a dual-buffer architecture where data is written to one buffer
    //   while the other is being read, enabling continuous streaming operation.
    //
    // Features:
    //   - Dual-buffer architecture (write to one while reading from the other)
    //   - Configurable data width and buffer depth
    //   - Independent read/write handshaking interfaces (ready/valid protocol)
    //   - Buffer overflow protection with error signaling
    //   - Automatic buffer swapping when write buffer fills to DEPTH samples
    //   - Supports continuous operation with alternating buffers
    //
    // Operation:
    //   1. Writes accumulate in one buffer until DEPTH samples are collected
    //   2. When write buffer fills, buffers automatically swap
    //   3. Read buffer becomes available with buffer_ready_o pulse
    //   4. Reads proceed independently from writes after swap
    //   5. Process repeats with buffers alternating roles
    //
    // Parameters:
    //   WIDTH      - Data width in bits (optimized for 8, 16, or 32 bits)
    //   DEPTH      - Buffer depth (number of samples per buffer)
    //   ADDR_WIDTH - Address width (auto-calculated as log2(DEPTH))
    //
    // Timing:
    //   - All signals are synchronous to clk_i
    //   - Reset is active-low synchronous (rst_ni)
    //   - RAM operates in BYPASS mode for low latency
    //
//==============================================================================
module ram_logic #(
    parameter int unsigned WIDTH = 32,          // Data width in bits
    parameter int unsigned DEPTH = 16,          // Number of samples per buffer
    parameter int unsigned ADDR_WIDTH = $clog2(DEPTH)  // Address bits needed
) (
    input  logic                    clk_i,          // System clock
    input  logic                    rst_ni,         // Active-low synchronous reset
    input  logic signed [WIDTH-1:0] write_data_i,   // Write data input
    input  logic                    write_valid_i,  // Write data valid
    output logic                    write_ready_o,  // Ready to accept write
    output logic signed [WIDTH-1:0] read_data_o,    // Read data output
    input  logic                    read_ready_i,   // Reader ready for data
    output logic                    read_valid_o,   // Read data valid
    output logic                    buffer_ready_o,      // Pulse: full buffer ready
    output logic                    buffer_overflow_o,   // Error: write overflow
    output logic [ADDR_WIDTH:0]     write_count_o,       // Write buffer fill level
    output logic [ADDR_WIDTH:0]     read_count_o         // Read buffer position
);

    //==========================================================================
    // Internal Registers and Signals
    //==========================================================================

    // Buffer state machine
    typedef enum logic [1:0] {
        WRITING,        // Accumulating samples in write buffer
        SWAP_PENDING,   // Write buffer full, swap on next cycle
        READING         // Reading out buffer while writing to other
    } buffer_state_t;

    buffer_state_t state_q, state_d;

    // Address counters for accessing RAM locations
    logic [ADDR_WIDTH-1:0]  write_addr_q;       // Current write position in buffer
    logic [ADDR_WIDTH-1:0]  read_addr_q;        // Current read position in buffer

    // Sample counters (one bit wider to detect when count == DEPTH)
    logic [ADDR_WIDTH:0]    write_count_q;      // Number of samples written
    logic [ADDR_WIDTH:0]    read_count_q;       // Number of samples read

    // Buffer selection (0 = RAM0, 1 = RAM1)
    logic                   write_buf_sel_q;    // Which RAM is being written
    logic                   read_buf_sel_q;     // Which RAM is being read

    // Handshaking qualified signals (valid AND ready)
    logic                   write_accepted;     // Write transaction occurring
    logic                   read_accepted;      // Read transaction occurring

    // RAM interface signals (Gowin SP RAM uses 14-bit addresses)
    logic [13:0]            ram0_addr;          // Formatted address for RAM0
    logic [13:0]            ram1_addr;          // Formatted address for RAM1
    logic                   ram0_we;            // Write enable for RAM0
    logic                   ram1_we;            // Write enable for RAM1
    logic [WIDTH-1:0]       ram0_dout;          // Data output from RAM0
    logic [WIDTH-1:0]       ram1_dout;          // Data output from RAM1

    //==========================================================================
    // Function: format_gowin_sp_ram_address
    //
    // Purpose:
    //   Converts logical address to Gowin SP RAM's 14-bit physical address format.
    //   The Gowin SP RAM address format depends on the data width:
    //   - 32-bit: Uses bits [13:9] for address, bits [8:4] and [3:0] unused
    //   - 16-bit: Uses bits [13:8] for address, bits [7:4] and [3:0] unused
    //   - 8-bit:  Uses bits [13:8] for address, bits [7:3] and [2:0] unused
    //
    // Parameters:
    //   addr - Logical address [ADDR_WIDTH-1:0]
    //
    // Returns:
    //   14-bit formatted address for Gowin SP RAM
    //==========================================================================
    function automatic logic [13:0] format_gowin_sp_ram_address(input logic [ADDR_WIDTH-1:0] addr);
        if (WIDTH == 32) begin
            return {4'b0000, addr, 5'b00000};  // addr positioned at [8:4]
        end else if (WIDTH == 16) begin
            return {2'b00, addr, 4'b0000};     // addr positioned at [11:4]
        end else if (WIDTH == 8) begin
            return {1'b0, addr, 5'b00000};     // addr positioned at [12:5]
        end else begin
            return {addr, (14-ADDR_WIDTH)'('0)};  // Generic case
        end
    endfunction

    //==========================================================================
    // Handshaking Logic
    //==========================================================================
    // Transaction occurs when both valid and ready are high (AXI-Stream protocol)
    assign write_accepted = write_valid_i && write_ready_o;
    assign read_accepted  = read_ready_i && read_valid_o;

    //==========================================================================
    // Write Ready Generation
    //==========================================================================
    // Ready to accept writes when write buffer is not full
    assign write_ready_o = (write_count_q < DEPTH);

    //==========================================================================
    // Status Output Assignments
    //==========================================================================
    assign write_count_o = write_count_q;  // Current fill level of write buffer
    assign read_count_o  = read_count_q;   // Current position in read buffer

    //==========================================================================
    // State Machine - Combinational Logic
    //
    // Controls buffer swapping and determines read_valid state
    //==========================================================================
    always_comb begin
        // Default: maintain current state
        state_d = state_q;

        case (state_q)
            WRITING: begin
                // Accumulating samples in write buffer
                if (write_count_q == DEPTH) begin
                    // Write buffer full, prepare to swap
                    state_d = SWAP_PENDING;
                end
            end

            SWAP_PENDING: begin
                // Swap occurs: filled write buffer becomes read buffer
                // Always transition to READING state
                state_d = READING;
            end

            READING: begin
                // Reading out buffer while simultaneously writing to other buffer
                // When write buffer fills again, swap back
                if (write_count_q == DEPTH) begin
                    state_d = SWAP_PENDING;
                end
            end

            default: state_d = WRITING;
        endcase
    end

    //==========================================================================
    // State Machine - Sequential Logic
    //
    // Manages ping-pong buffer counters, addresses, and buffer selection
    //==========================================================================
    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            // Reset all counters and addresses
            state_q         <= WRITING;
            write_addr_q    <= '0;
            read_addr_q     <= '0;
            write_count_q   <= '0;
            read_count_q    <= '0;

            // Initialize buffer selection: write to RAM0, read from RAM1
            write_buf_sel_q <= 1'b0;
            read_buf_sel_q  <= 1'b1;

            // Clear output signals
            buffer_ready_o      <= 1'b0;
            buffer_overflow_o   <= 1'b0;
            read_valid_o        <= 1'b0;
        end else begin
            // Update state
            state_q <= state_d;

            // Default: clear single-cycle pulse signals
            buffer_ready_o    <= 1'b0;
            buffer_overflow_o <= 1'b0;

            //==================================================================
            // Buffer Swap Handling
            //==================================================================
            if (state_q == SWAP_PENDING) begin
                // Swap buffers: filled write buffer becomes read buffer
                buffer_ready_o  <= 1'b1;                    // Pulse: new buffer ready
                read_buf_sel_q  <= write_buf_sel_q;         // Switch to filled buffer
                write_buf_sel_q <= ~write_buf_sel_q;        // Switch write to other buffer

                // Reset counters and addresses for new cycle
                write_addr_q    <= '0;
                write_count_q   <= '0;
                read_addr_q     <= '0;
                read_count_q    <= '0;
                read_valid_o    <= 1'b1;                    // Assert read valid
            end else begin
                //==============================================================
                // Write Path Management
                //==============================================================
                if (write_accepted) begin
                    if (write_count_q < DEPTH) begin
                        write_addr_q  <= write_addr_q + 1'b1;   // Next write location
                        write_count_q <= write_count_q + 1'b1;  // Increment sample count
                    end else begin
                        // Safety: should never reach here due to write_ready_o
                        buffer_overflow_o <= 1'b1;              // Flag overflow error
                    end
                end

                //==============================================================
                // Read Path Management
                //==============================================================
                if (read_accepted && (state_q == READING)) begin
                    if (read_count_q < DEPTH - 1) begin
                        read_addr_q  <= read_addr_q + 1'b1;     // Next read location
                        read_count_q <= read_count_q + 1'b1;    // Increment read count
                        read_valid_o <= 1'b1;                   // Maintain read valid
                    end else begin
                        // Last sample read - prepare for next swap
                        read_addr_q  <= '0;
                        read_count_q <= '0;
                        read_valid_o <= 1'b0;                   // Deassert read valid
                    end
                end else if (state_q == READING) begin
                    // In reading state but no read transaction
                    read_valid_o <= (read_count_q < DEPTH) ? 1'b1 : 1'b0;
                end else begin
                    // Not in reading state
                    read_valid_o <= 1'b0;
                end
            end
        end
    end

    //==========================================================================
    // RAM Address Multiplexing
    //
    // Routes write and read addresses to the appropriate RAM based on buffer
    // selection. When write_buf_sel_q=0: writes go to RAM0, reads from RAM1.
    // When write_buf_sel_q=1: writes go to RAM1, reads from RAM0.
    //==========================================================================
    always_comb begin
        if (write_buf_sel_q == 1'b0) begin
            // Writing to RAM0, reading from RAM1
            ram0_addr = format_gowin_sp_ram_address(write_addr_q);
            ram1_addr = format_gowin_sp_ram_address(read_addr_q);
        end else begin
            // Writing to RAM1, reading from RAM0
            ram0_addr = format_gowin_sp_ram_address(read_addr_q);
            ram1_addr = format_gowin_sp_ram_address(write_addr_q);
        end
    end

    //==========================================================================
    // RAM Write Enable Generation
    //
    // Write enable is asserted only when a write transaction occurs
    // (write_accepted) AND the RAM is selected as the current write buffer.
    //==========================================================================
    assign ram0_we = write_accepted && (write_buf_sel_q == 1'b0);
    assign ram1_we = write_accepted && (write_buf_sel_q == 1'b1);

    //==========================================================================
    // RAM Output Multiplexing
    //
    // Selects data from the currently active read buffer (RAM0 or RAM1)
    // based on read_buf_sel_q. Returns zero when not in reading state.
    //==========================================================================
    assign read_data_o = (state_q == READING) ?
                         ((read_buf_sel_q == 1'b0) ? ram0_dout : ram1_dout) :
                         '0;

    //==========================================================================
    // RAM Instantiation - Buffer 0
    //
    // Gowin Single-Port RAM configured for ping-pong buffer operation.
    // Configuration:
    //   - BYPASS mode (READ_MODE=0): Data available same cycle (low latency)
    //   - NORMAL write mode (WRITE_MODE=00): Standard write operation
    //   - Clock enable (CE) always active for continuous operation
    //   - Output clock enable (OCE) disabled for bypass mode
    //==========================================================================
    SP pingpong_buffer_ram0 (
        .CLK    (clk_i),            // System clock
        .CE     (1'b1),             // Clock enable always on
        .OCE    (1'b0),             // Output clock enable (bypass mode)
        .RESET  (1'b0),             // Synchronous reset (using rst_ni instead)
        .WRE    (ram0_we),          // Write enable
        .BLKSEL (3'b000),           // Block select
        .AD     (ram0_addr),        // 14-bit address
        .DI     (write_data_i),     // Data input
        .DO     (ram0_dout)         // Data output
    );
    defparam pingpong_buffer_ram0.BIT_WIDTH  = WIDTH;   // Data width configuration
    defparam pingpong_buffer_ram0.READ_MODE  = 1'b0;    // BYPASS mode for low latency
    defparam pingpong_buffer_ram0.WRITE_MODE = 2'b00;   // NORMAL write mode
    defparam pingpong_buffer_ram0.BLK_SEL    = 3'b000;  // Block selection

    //==========================================================================
    // RAM Instantiation - Buffer 1
    //
    // Second Gowin Single-Port RAM for ping-pong buffer operation.
    // Configured identically to Buffer 0.
    //==========================================================================
    SP pingpong_buffer_ram1 (
        .CLK    (clk_i),            // System clock
        .CE     (1'b1),             // Clock enable always on
        .OCE    (1'b0),             // Output clock enable (bypass mode)
        .RESET  (1'b0),             // Synchronous reset (using rst_ni instead)
        .WRE    (ram1_we),          // Write enable
        .BLKSEL (3'b000),           // Block select
        .AD     (ram1_addr),        // 14-bit address
        .DI     (write_data_i),     // Data input
        .DO     (ram1_dout)         // Data output
    );
    defparam pingpong_buffer_ram1.BIT_WIDTH  = WIDTH;   // Data width configuration
    defparam pingpong_buffer_ram1.READ_MODE  = 1'b0;    // BYPASS mode for low latency
    defparam pingpong_buffer_ram1.WRITE_MODE = 2'b00;   // NORMAL write mode
    defparam pingpong_buffer_ram1.BLK_SEL    = 3'b000;  // Block selection

endmodule
