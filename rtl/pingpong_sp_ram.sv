// =============================================================================
// pingpong_sp_ram.sv
// =============================================================================
// Dual-buffer ping-pong RAM using two Gowin SP (Single Port) BRAM primitives
//
// Features:
// - 16-bit data width (configurable via DATA_WIDTH parameter)
// - 256 samples per buffer (configurable via SAMPLES_PER_BUF parameter)
// - Pipeline read mode (1 cycle latency)
// - Normal write mode (write-through)
// - Synchronous active-low reset
// - Automatic buffer switching after SAMPLES_PER_BUF writes
//
// Operation:
// - One buffer is active for writing while the other is available for reading
// - After SAMPLES_PER_BUF samples are written, buffers automatically toggle
// - buf_ready_pulse_o pulses high for 1 cycle when a buffer becomes full
// - buf_ready_id_o indicates which buffer (0=A, 1=B) was just filled
// - Reads from the inactive buffer have 1 cycle pipeline latency
// =============================================================================

module pingpong_sp_ram #(
    parameter int unsigned DATA_WIDTH      = 16,   // Width of data bus
    parameter int unsigned SAMPLES_PER_BUF = 256,  // Number of samples per buffer
    parameter int unsigned ADDR_WIDTH      = $clog2(SAMPLES_PER_BUF)  // Address width (auto-calculated)
) (
    input  logic                   clk_i,    // System clock
    input  logic                   rst_ni,   // Synchronous active-low reset

    // Write interface - writes go to the ACTIVE buffer
    input  logic                   in_valid_i,  // Write enable
    input  logic [DATA_WIDTH-1:0]  in_data_i,   // Write data

    // Read interface - reads come from the INACTIVE buffer
    input  logic                   rd_en_i,                // Read enable
    input  logic [ADDR_WIDTH-1:0]  rd_addr_i,              // Read address
    output logic [DATA_WIDTH-1:0]  rd_data_o,              // Read data (valid after 1 cycle)
    output logic                   rd_valid_o,             // Read data valid flag

    // Status outputs
    output logic                   active_buf_o,           // Currently active buffer (0=A, 1=B)
    output logic                   buf_ready_pulse_o,      // Pulses high for 1 cycle when buffer is full
    output logic                   buf_ready_id_o          // ID of buffer that just became ready (0=A, 1=B)
);

    // =========================================================================
    // Internal Signal Declarations
    // =========================================================================

    // Write control
    logic [ADDR_WIDTH-1:0] write_addr;      // Current write address counter (0 to SAMPLES_PER_BUF-1)
    logic                  write_last;      // Indicates the last write in current buffer

    // RAM control signals
    logic                  we_a, we_b;      // Write enables for RAM A and B
    logic [ADDR_WIDTH-1:0] addr_a, addr_b;  // Addresses for RAM A and B
    logic [DATA_WIDTH-1:0] wdata;           // Write data (common to both RAMs)
    logic [31:0]           ram_a_do;        // Data output from RAM A (32-bit from primitive)
    logic [31:0]           ram_b_do;        // Data output from RAM B (32-bit from primitive)

    // Read pipeline
    logic rd_valid_q;  // Pipeline stage for read valid signal

    // =========================================================================
    // Constants
    // =========================================================================

    // Last valid address in each buffer (SAMPLES_PER_BUF - 1)
    // For SAMPLES_PER_BUF=256, LAST_ADDR=255 (0xFF)
    localparam logic [ADDR_WIDTH-1:0] LAST_ADDR = ADDR_WIDTH'(SAMPLES_PER_BUF - 1);

    // =========================================================================
    // Write Address Counter
    // =========================================================================
    // Increments from 0 to SAMPLES_PER_BUF-1, then wraps to 0
    // Only increments when in_valid_i is asserted

    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            write_addr <= '0;
        end else if (in_valid_i) begin
            if (write_addr == LAST_ADDR) begin
                write_addr <= '0;  // Wrap to 0 after last sample
            end else begin
                write_addr <= write_addr + 1'b1;
            end
        end
    end

    // =========================================================================
    // Last Write Detection
    // =========================================================================
    // Asserted when writing the last sample (address SAMPLES_PER_BUF-1)

    assign write_last = in_valid_i && (write_addr == LAST_ADDR);

    // =========================================================================
    // Buffer Management Logic
    // =========================================================================
    // Controls which buffer is active for writing
    // Toggles after SAMPLES_PER_BUF writes are complete
    // Generates ready pulse and captures buffer ID

    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            active_buf_o       <= 1'b0;  // Start with buffer A active
            buf_ready_pulse_o  <= 1'b0;
            buf_ready_id_o     <= 1'b0;
        end else begin
            buf_ready_pulse_o <= 1'b0;  // Default: pulse for only 1 cycle

            if (write_last) begin
                // Last sample written - signal buffer is ready and toggle
                buf_ready_pulse_o <= 1'b1;              // Pulse for 1 cycle
                buf_ready_id_o    <= active_buf_o;      // Capture which buffer just filled
                active_buf_o      <= ~active_buf_o;     // Toggle to other buffer
            end
        end
    end

    // =========================================================================
    // Write Enable and Address Routing
    // =========================================================================
    // Routes write data and address to the ACTIVE buffer
    // Routes read address to the INACTIVE buffer
    // Ensures no simultaneous read/write to the same RAM

    assign wdata = in_data_i;  // Common write data for both RAMs

    always_comb begin
        // Default: no operations
        we_a = 1'b0;
        we_b = 1'b0;
        addr_a = '0;
        addr_b = '0;

        // Write routing: direct writes to the active buffer
        if (in_valid_i) begin
            if (active_buf_o == 1'b0) begin
                // Buffer A is active - write to A
                we_a   = 1'b1;
                addr_a = write_addr;
            end else begin
                // Buffer B is active - write to B
                we_b   = 1'b1;
                addr_b = write_addr;
            end
        end

        // Read routing: direct reads to the inactive buffer
        if (rd_en_i) begin
            if (active_buf_o == 1'b0) begin
                // Buffer A is active (writing), so read from B
                addr_b = rd_addr_i;
            end else begin
                // Buffer B is active (writing), so read from A
                addr_a = rd_addr_i;
            end
        end
    end

    // =========================================================================
    // Read Pipeline - Valid Signal
    // =========================================================================
    // Creates 1-cycle pipeline for read valid to match RAM output latency

    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            rd_valid_q <= 1'b0;
        end else begin
            rd_valid_q <= rd_en_i;  // Delay read enable by 1 cycle
        end
    end

    assign rd_valid_o = rd_valid_q;

    // =========================================================================
    // Read Data Multiplexer
    // =========================================================================
    // Selects data from the inactive buffer (opposite of active buffer)
    // Registered output to match pipeline timing

    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            rd_data_o <= '0;
        end else if (rd_valid_q) begin
            if (active_buf_o == 1'b0) begin
                // Buffer A is active, so output data from buffer B
                rd_data_o <= ram_b_do[DATA_WIDTH-1:0];
            end else begin
                // Buffer B is active, so output data from buffer A
                rd_data_o <= ram_a_do[DATA_WIDTH-1:0];
            end
        end
    end

    // =========================================================================
    // Gowin SP RAM Instantiation - RAM A (Buffer A)
    // =========================================================================
    // Single Port Block RAM primitive from Gowin
    // - 16-bit data width (BIT_WIDTH = 16)
    // - Pipeline read mode (READ_MODE = 1'b1) adds 1 cycle latency
    // - Normal write mode (WRITE_MODE = 2'b00) for write-through operation
    // - Synchronous reset (RESET_MODE = "SYNC")
    // - Address format: For 16-bit width, AD[13:4] is used, AD[3:0] tied to 0

    SP ram_a (
        .DO     (ram_a_do),                                                     // [31:0] Data output (only [15:0] used)
        .CLK    (clk_i),                                                        // Clock input
        .OCE    (1'b1),                                                         // Output clock enable (always enabled for pipeline mode)
        .CE     (1'b1),                                                         // Chip enable (always enabled)
        .RESET  (!rst_ni),                                                      // Active-high reset (invert rst_ni)
        .WRE    (we_a),                                                         // Write enable
        .BLKSEL (3'b000),                                                       // Block select (default)
        .AD     ({{(14-ADDR_WIDTH-4){1'b0}}, addr_a[ADDR_WIDTH-1:0], 4'b0000}), // [13:0] Address: zero-extend to 14 bits
        .DI     ({{(32-DATA_WIDTH){1'b0}}, wdata})                             // [31:0] Data input: zero-extend to 32 bits
    );

    // RAM A Configuration Parameters
    defparam ram_a.READ_MODE   = 1'b1;     // 1'b1 = Pipeline read (1 cycle latency)
    defparam ram_a.WRITE_MODE  = 2'b00;    // 2'b00 = Normal write mode
    defparam ram_a.BIT_WIDTH   = 16;       // 16-bit data width
    defparam ram_a.BLK_SEL     = 3'b000;   // Block select (default)
    defparam ram_a.RESET_MODE  = "SYNC";   // Synchronous reset

    // =========================================================================
    // Gowin SP RAM Instantiation - RAM B (Buffer B)
    // =========================================================================
    // Identical configuration to RAM A
    // Second buffer for ping-pong operation

    SP ram_b (
        .DO     (ram_b_do),                                                     // [31:0] Data output (only [15:0] used)
        .CLK    (clk_i),                                                        // Clock input
        .OCE    (1'b1),                                                         // Output clock enable (always enabled for pipeline mode)
        .CE     (1'b1),                                                         // Chip enable (always enabled)
        .RESET  (!rst_ni),                                                      // Active-high reset (invert rst_ni)
        .WRE    (we_b),                                                         // Write enable
        .BLKSEL (3'b000),                                                       // Block select (default)
        .AD     ({{(14-ADDR_WIDTH-4){1'b0}}, addr_b[ADDR_WIDTH-1:0], 4'b0000}), // [13:0] Address: zero-extend to 14 bits
        .DI     ({{(32-DATA_WIDTH){1'b0}}, wdata})                             // [31:0] Data input: zero-extend to 32 bits
    );

    // RAM B Configuration Parameters
    defparam ram_b.READ_MODE   = 1'b1;     // 1'b1 = Pipeline read (1 cycle latency)
    defparam ram_b.WRITE_MODE  = 2'b00;    // 2'b00 = Normal write mode
    defparam ram_b.BIT_WIDTH   = 16;       // 16-bit data width
    defparam ram_b.BLK_SEL     = 3'b000;   // Block select (default)
    defparam ram_b.RESET_MODE  = "SYNC";   // Synchronous reset

endmodule
// =============================================================================
// End of pingpong_sp_ram.sv
// =============================================================================
