//==============================================================================
// Behavioral Model: Gowin SP (Single-Port) RAM
//
// This is a simulation model of the Gowin SP RAM primitive for testbench use.
// It mimics the behavior of the actual Gowin SP RAM IP core.
//
// Parameters:
//   BIT_WIDTH  - Data width (1, 2, 4, 8, 16, 32)
//   READ_MODE  - 0: BYPASS (combinational read), 1: PIPELINE (registered read)
//   WRITE_MODE - Write mode (00: NORMAL)
//   BLK_SEL    - Block selection
//==============================================================================

module SP #(
    parameter BIT_WIDTH = 32,
    parameter READ_MODE = 1'b0,
    parameter WRITE_MODE = 2'b00,
    parameter BLK_SEL = 3'b000
) (
    input  logic        CLK,        // Clock
    input  logic        CE,         // Clock enable
    input  logic        OCE,        // Output clock enable
    input  logic        RESET,      // Reset
    input  logic        WRE,        // Write enable
    input  logic [2:0]  BLKSEL,     // Block select
    input  logic [13:0] AD,         // 14-bit address
    input  logic [BIT_WIDTH-1:0] DI,  // Data input
    output logic [BIT_WIDTH-1:0] DO   // Data output
);

    // Calculate memory depth based on BIT_WIDTH
    // Gowin SP RAM is 16K bits total
    localparam int DEPTH = 16384 / BIT_WIDTH;
    localparam int ADDR_BITS = $clog2(DEPTH);

    // Memory array
    logic [BIT_WIDTH-1:0] mem [0:DEPTH-1];

    // Extract actual address from 14-bit address format
    logic [ADDR_BITS-1:0] actual_addr;

    always_comb begin
        case (BIT_WIDTH)
            32: actual_addr = AD[8:4];   // 5 bits for 32-bit width (512 locations)
            16: actual_addr = AD[11:4];  // 8 bits for 16-bit width (1024 locations)
            8:  actual_addr = AD[12:5];  // 8 bits for 8-bit width (2048 locations)
            default: actual_addr = AD[ADDR_BITS-1:0];
        endcase
    end

    // BYPASS mode (READ_MODE = 0): Combinational read
    generate
        if (READ_MODE == 1'b0) begin : bypass_mode
            logic [BIT_WIDTH-1:0] read_data;

            always_comb begin
                if (CE) begin
                    read_data = mem[actual_addr];
                end else begin
                    read_data = '0;
                end
            end

            assign DO = read_data;

        end else begin : pipeline_mode
            // PIPELINE mode (READ_MODE = 1): Registered read
            logic [BIT_WIDTH-1:0] read_data_reg;

            always_ff @(posedge CLK) begin
                if (RESET) begin
                    read_data_reg <= '0;
                end else if (CE && OCE) begin
                    read_data_reg <= mem[actual_addr];
                end
            end

            assign DO = read_data_reg;
        end
    endgenerate

    // Write operation (synchronous)
    always_ff @(posedge CLK) begin
        if (RESET) begin
            // Clear memory on reset (optional for simulation)
            for (int i = 0; i < DEPTH; i++) begin
                mem[i] <= '0;
            end
        end else if (CE && WRE) begin
            mem[actual_addr] <= DI;
        end
    end

    // Initialize memory to zero
    initial begin
        for (int i = 0; i < DEPTH; i++) begin
            mem[i] = '0;
        end
    end

endmodule
