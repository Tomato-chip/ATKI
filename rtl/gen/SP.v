// SP_model.v
// Behavioral model of Gowin SP (Single Port) BRAM primitive
// For simulation purposes only
// Implements pipeline read mode and normal write mode as specified

`timescale 1ns/1ps

module SP (
    output reg  [31:0] DO,      // Data output
    input  wire        CLK,     // Clock
    input  wire        OCE,     // Output clock enable
    input  wire        CE,      // Clock enable
    input  wire        RESET,   // Reset (active-high)
    input  wire        WRE,     // Write enable
    input  wire [2:0]  BLKSEL,  // Block select
    input  wire [13:0] AD,      // Address
    input  wire [31:0] DI       // Data input
);

    // Parameters
    parameter READ_MODE = 1'b1;        // 1'b1 = Pipeline read mode
    parameter WRITE_MODE = 2'b00;      // 2'b00 = Normal write
    parameter BIT_WIDTH = 16;          // Data width
    parameter BLK_SEL = 3'b000;        // Block selection
    parameter RESET_MODE = "SYNC";     // SYNC or ASYNC reset

    // Initialization parameters (can be overridden)
    parameter [255:0] INIT_RAM_00 = 256'h0;
    parameter [255:0] INIT_RAM_01 = 256'h0;
    parameter [255:0] INIT_RAM_02 = 256'h0;
    parameter [255:0] INIT_RAM_03 = 256'h0;

    // Memory array - 16K bits organized based on BIT_WIDTH
    // For 16-bit width: 1024 locations (1K x 16)
    reg [31:0] mem [0:1023];

    // Internal registers for pipeline mode
    reg [31:0] do_reg;
    reg [31:0] do_pipe;

    // Address decoding - for 16-bit mode, use AD[13:4]
    // Lower 4 bits are tied to 0 in the instantiation
    wire [9:0] addr_index;
    assign addr_index = AD[13:4];

    integer i;

    // Initialize memory
    initial begin
        for (i = 0; i < 1024; i = i + 1) begin
            mem[i] = 32'h00000000;
        end
        do_reg = 32'h00000000;
        do_pipe = 32'h00000000;
    end

    // Memory operations
    always @(posedge CLK) begin
        if (RESET && RESET_MODE == "SYNC") begin
            // Synchronous reset
            do_pipe <= 32'h00000000;
        end else if (CE && OCE) begin
            // Write operation
            if (WRE) begin
                case (BIT_WIDTH)
                    16: mem[addr_index] <= {16'h0000, DI[15:0]};
                    32: mem[addr_index] <= DI;
                    default: mem[addr_index] <= {16'h0000, DI[15:0]};
                endcase
            end

            // Read operation - in pipeline mode, register the output
            if (READ_MODE == 1'b1) begin
                // Pipeline mode: 1 cycle latency
                case (BIT_WIDTH)
                    16: do_pipe <= {16'h0000, mem[addr_index][15:0]};
                    32: do_pipe <= mem[addr_index];
                    default: do_pipe <= {16'h0000, mem[addr_index][15:0]};
                endcase
            end
        end
    end

    // Output assignment based on read mode
    always @(*) begin
        if (READ_MODE == 1'b1) begin
            // Pipeline mode - output from pipeline register (1 cycle latency)
            DO = do_pipe;
        end else begin
            // Non-pipeline mode - combinatorial read (not used in this design)
            case (BIT_WIDTH)
                16: DO = {16'h0000, mem[addr_index][15:0]};
                32: DO = mem[addr_index];
                default: DO = {16'h0000, mem[addr_index][15:0]};
            endcase
        end
    end

endmodule
