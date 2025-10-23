// =============================================================================
// SP_model.sv
// Behavioral model of Gowin SP (Single Port BRAM) for simulation
// =============================================================================

module SP #(
    parameter BIT_WIDTH = 16,
    parameter READ_MODE = 1'b0,    // 0=BYPASS, 1=PIPELINE
    parameter WRITE_MODE = 2'b00,  // 00=NORMAL
    parameter BLK_SEL = 3'b000,
    parameter RESET_MODE = "SYNC",
    parameter INIT_RAM_00 = 256'h0
) (
    output reg [BIT_WIDTH-1:0] DO,      // Data output
    input                      CLK,     // Clock
    input                      CE,      // Clock enable
    input                      OCE,     // Output clock enable
    input                      RESET,   // Reset
    input                      WRE,     // Write enable
    input [2:0]                BLKSEL,  // Block select
    input [13:0]               AD,      // Address (14-bit)
    input [BIT_WIDTH-1:0]      DI       // Data input
);

    // Memory array - 16K × BIT_WIDTH
    // Address [13:0] = 14 bits = 16384 locations
    reg [BIT_WIDTH-1:0] mem [0:16383];

    // Internal signals
    reg [BIT_WIDTH-1:0] data_out_reg;
    wire [13:0] addr = AD;

    // Initialize memory to zero
    integer i;
    initial begin
        for (i = 0; i < 16384; i = i + 1) begin
            mem[i] = {BIT_WIDTH{1'b0}};
        end
    end

    // Read/Write logic
    always @(posedge CLK) begin
        if (RESET) begin
            // Reset behavior
            data_out_reg <= {BIT_WIDTH{1'b0}};
            DO <= {BIT_WIDTH{1'b0}};
        end else if (CE) begin
            // Write operation
            if (WRE) begin
                mem[addr] <= DI;
            end

            // Read operation (BYPASS mode - combinatorial read)
            if (READ_MODE == 1'b0) begin
                // BYPASS: Output reflects current address immediately
                if (WRE) begin
                    // Write-through: output new data being written
                    DO <= DI;
                end else begin
                    // Normal read
                    DO <= mem[addr];
                end
            end else begin
                // PIPELINE mode: registered output
                data_out_reg <= mem[addr];
                if (OCE) begin
                    DO <= data_out_reg;
                end
            end
        end
    end

endmodule
