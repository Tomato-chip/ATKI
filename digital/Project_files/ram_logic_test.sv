//==============================================================================
// ram_logic.sv
//
// Ping-pong buffer RAM controller with flexible read/write interface
//
// Features:
//   - Dual-buffer architecture (write to one while reading from the other)
//   - Configurable data width and buffer depth
//   - Independent read/write handshaking interfaces
//   - Buffer overflow protection
//   - Automatic buffer swapping when full
//   - Read pointer management with ready/valid protocol
//   - Supports both streaming and burst read modes
//
// Operation:
//   - Writes accumulate in one buffer until DEPTH samples are collected
//   - When write buffer fills, buffers automatically swap
//   - Read buffer becomes available with buffer_ready_o pulse
//   - Reads can proceed independently of writes after swap
//   - Supports continuous operation with alternating buffers
//
//==============================================================================

module ram_logic #(
    parameter int unsigned WIDTH = 32,          // Data width in bits
    parameter int unsigned DEPTH = 16,         // Buffer depth (samples per buffer)
    parameter int unsigned ADDR_WIDTH = $clog2(DEPTH)  // Address width (auto-calculated)
) (
    // Clock and reset
    input  logic                    clk_i,
    input  logic                    rst_ni,     // Active-low synchronous reset

    //==========================================================================
    // Write interface
    //==========================================================================
    input  logic signed [WIDTH-1:0]        write_data_i,
    input  logic                    write_valid_i,   // Write request
    output logic                    write_ready_o,   // Ready to accept write

    //==========================================================================
    // Read interface
    //==========================================================================
    output logic signed [WIDTH-1:0]        read_data_o,
    input  logic                    read_ready_i,    // Reader ready for data
    output logic                    read_valid_o,    // Read data valid

    //==========================================================================
    // Status and control
    //==========================================================================
    output logic                    buffer_ready_o,  // Pulse: full buffer ready for reading
    output logic                    buffer_overflow_o, // Error: write to full system
    output logic [ADDR_WIDTH:0]     write_count_o,   // Current write buffer fill level
    output logic [ADDR_WIDTH:0]     read_count_o     // Current read buffer position
);

    //==========================================================================
    // Internal registers and signals
    //==========================================================================

    // Address counters
    logic [ADDR_WIDTH-1:0]  write_address;
    logic [ADDR_WIDTH-1:0]  read_address;

    // Sample counters
    logic [ADDR_WIDTH:0]    write_count;
    logic [ADDR_WIDTH:0]    read_count;

    // Buffer selection
    logic                   write_buffer_sel;   // 0=RAM0, 1=RAM1
    logic                   read_buffer_sel;    // 0=RAM0, 1=RAM1

    // State flags
    logic                   read_buffer_valid;  // Read buffer has valid data
    logic                   write_buffer_full;  // Write buffer is full
    logic                   read_in_progress;   // Read operation in progress

    // Handshaking
    logic                   write_accepted;
    logic                   read_accepted;

    // RAM interface signals
    logic [13:0]            ram0_address;
    logic [13:0]            ram1_address;
    logic                   ram0_write_enable;
    logic                   ram1_write_enable;
    logic [WIDTH-1:0]       ram0_data_out;
    logic [WIDTH-1:0]       ram1_data_out;

    // ==========================================================================
    // Address packing function (for 14-bit Gowin SP RAM address format)
    // ==========================================================================
    function automatic logic [13:0] pack_address(input logic [ADDR_WIDTH-1:0] addr);
        // Pack address into 14-bit format with lower bits zero-padded
        // Format: [unused bits][address][zero padding]
        if (WIDTH == 32) begin
            return {1'b0, addr, 5'b00000};
        end else if (WIDTH == 16) begin
            return {2'b00, addr, 4'b0000};
        end else if (WIDTH == 8) begin
            return {1'b0, addr, 5'b00000};
        end else begin
            return {addr, (14-ADDR_WIDTH)'('0)};
        end
    endfunction
    //==========================================================================

        // function automatic logic [13:0] pack_address(input logic [13:0] addr);
        //     // Pack address into 14-bit format with lower bits zero-padded
        //     // Format: [unused bits][address][zero padding]
        //     if (WIDTH == 32) begin
        //         return {addr, 5'b00000};
        //     end else if (WIDTH == 16) begin
        //         return {addr, 4'b0000};
        //     end else if (WIDTH == 8 ) begin
        //         return {addr, 3'b000};
        //     end else if (WIDTH == 4 ) begin
        //         return {addr, 2'b00};
        //     end else if (WIDTH == 2 ) begin
        //         return {addr, 1'b0};
        //     end else if (WIDTH == 1 ) begin
        //         return {addr};
        //     end else begin
        //         return {addr, (14-ADDR_WIDTH)'('0)};
        //     end
        // endfunction

    //==========================================================================
    // Handshaking logic
    //==========================================================================
    assign write_accepted = write_valid_i && write_ready_o;
    assign read_accepted  = read_ready_i && read_valid_o;

    //==========================================================================
    // Write ready generation
    //==========================================================================
    // Ready to accept writes when write buffer is not full
    assign write_ready_o = !write_buffer_full;

    //==========================================================================
    // Buffer full detection
    //==========================================================================
    assign write_buffer_full = (write_count >= DEPTH);

    //==========================================================================
    // Status outputs
    //==========================================================================
    assign write_count_o = write_count;
    assign read_count_o  = read_count;

    //==========================================================================
    // Main control FSM
    //==========================================================================
    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            // Reset all state
            write_address       <= '0;
            read_address        <= '0;
            write_count         <= '0;
            read_count          <= '0;
            write_buffer_sel    <= 1'b0;    // Start writing to RAM0
            read_buffer_sel     <= 1'b1;    // Start reading from RAM1 (initially empty)
            read_buffer_valid   <= 1'b0;    // No valid read data initially
            read_in_progress    <= 1'b0;
            buffer_ready_o      <= 1'b0;
            buffer_overflow_o   <= 1'b0;
            read_valid_o        <= 1'b0;
        end else begin
            // Default: clear single-cycle pulses
            buffer_ready_o    <= 1'b0;
            buffer_overflow_o <= 1'b0;

            //==================================================================
            // Buffer swap on write buffer full - must happen BEFORE other logic
            //==================================================================
            if (write_count == DEPTH) begin
                // Swap buffers
                buffer_ready_o      <= 1'b1;                    // Signal new buffer ready
                read_buffer_valid   <= 1'b1;                    // Mark read buffer as valid
                read_in_progress    <= 1'b1;                    // Start read phase
                read_buffer_sel     <= write_buffer_sel;        // Read from just-filled buffer
                write_buffer_sel    <= ~write_buffer_sel;       // Write to other buffer

                // Reset counters
                write_address       <= '0;
                write_count         <= '0;
                read_address        <= '0;
                read_count          <= '0;
                read_valid_o        <= 1'b0;                    // Clear read valid on swap
            end else begin
                //==============================================================
                // Write path management
                //==============================================================
                if (write_accepted) begin
                    if (write_count < DEPTH) begin
                        // Normal write operation
                        write_address <= write_address + 1'b1;
                        write_count   <= write_count + 1'b1;
                    end else begin
                        // Overflow condition - write when buffer full
                        buffer_overflow_o <= 1'b1;
                    end
                end

                //==============================================================
                // Read path management
                //==============================================================
                if (read_accepted && read_buffer_valid) begin
                    if (read_count < DEPTH - 1) begin
                        read_address <= read_address + 1'b1;
                        read_count   <= read_count + 1'b1;
                    end else begin
                        // Last read complete
                        read_in_progress <= 1'b0;
                        read_count       <= '0;
                        read_address     <= '0;
                    end
                end

                //==============================================================
                // Read valid output control
                //==============================================================
                // Data is valid when read buffer is valid and in progress
                if (read_buffer_valid && read_in_progress) begin
                    read_valid_o <= 1'b1;
                end else begin
                    read_valid_o <= 1'b0;
                end
            end
        end
    end

    //==========================================================================
    // RAM address multiplexing
    //==========================================================================
    always_comb begin
        if (write_buffer_sel == 1'b0) begin
            // Writing to RAM0, reading from RAM1
            ram0_address = pack_address(write_address);
            ram1_address = pack_address(read_address);
        end else begin
            // Writing to RAM1, reading from RAM0
            ram0_address = pack_address(read_address);
            ram1_address = pack_address(write_address);
        end
    end

    //==========================================================================
    // RAM write enable generation
    //==========================================================================
    assign ram0_write_enable = write_accepted && (write_buffer_sel == 1'b0);
    assign ram1_write_enable = write_accepted && (write_buffer_sel == 1'b1);

    //==========================================================================
    // RAM output multiplexing
    //==========================================================================
    always_comb begin
        if (read_buffer_valid) begin
            read_data_o = (read_buffer_sel == 1'b0) ? ram0_data_out : ram1_data_out;
        end else begin
            read_data_o = '0;
        end
    end

    //==========================================================================
    // RAM instantiation - RAM0
    //==========================================================================
    SP u_ram0 (
        .CLK    (clk_i),
        .CE     (1'b1),                     // Chip enable always on
        .OCE    (1'b0),                     // Output clock enable (bypass mode)
        .RESET  (1'b0),                     // Use synchronous reset instead
        .WRE    (ram0_write_enable),
        .BLKSEL (3'b000),
        .AD     (ram0_address),
        .DI     (write_data_i),
        .DO     (ram0_data_out)
    );
    defparam u_ram0.BIT_WIDTH  = WIDTH;
    defparam u_ram0.READ_MODE  = 1'b0;      // BYPASS mode for low latency
    defparam u_ram0.WRITE_MODE = 2'b00;     // NORMAL write mode
    defparam u_ram0.BLK_SEL    = 3'b000;

    //==========================================================================
    // RAM instantiation - RAM1
    //==========================================================================
    SP u_ram1 (
        .CLK    (clk_i),
        .CE     (1'b1),                     // Chip enable always on
        .OCE    (1'b0),                     // Output clock enable (bypass mode)
        .RESET  (1'b0),                     // Use synchronous reset instead
        .WRE    (ram1_write_enable),
        .BLKSEL (3'b000),
        .AD     (ram1_address),
        .DI     (write_data_i),
        .DO     (ram1_data_out)
    );
    defparam u_ram1.BIT_WIDTH  = WIDTH;
    defparam u_ram1.READ_MODE  = 1'b0;      // BYPASS mode for low latency
    defparam u_ram1.WRITE_MODE = 2'b00;     // NORMAL write mode
    defparam u_ram1.BLK_SEL    = 3'b000;

    //==========================================================================
    // Assertions for debugging (synthesis tools will ignore these)
    //==========================================================================
    // synopsys translate_off
    // verilator lint_off UNUSED

    always_ff @(posedge clk_i) begin
        if (rst_ni) begin
            // Check for illegal buffer operations
            assert (!(write_buffer_full && write_accepted)) else
                $error("ram_logic: Write to full buffer detected!");

            assert (DEPTH > 0) else
                $error("ram_logic: DEPTH must be greater than 0");

            assert (WIDTH inside {8, 16, 32}) else
                $warning("ram_logic: WIDTH=%0d may not be optimal for Gowin SP RAM", WIDTH);
        end
    end

    // verilator lint_on UNUSED
    // synopsys translate_on

endmodule
