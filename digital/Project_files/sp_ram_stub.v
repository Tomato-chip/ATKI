//==============================================================================
// sp_ram_stub.v
//
// Behavioral model stub for Gowin SP (Single Port) RAM primitive
// Used for simulation only - replaced with actual primitive during synthesis
//
// This models the basic behavior of the Gowin SP RAM block:
// - Synchronous write
// - Configurable read mode (BYPASS or PIPELINE)
// - Configurable bit width
//
//==============================================================================

module SP (
    input  wire         CLK,
    input  wire         CE,      // Chip enable
    input  wire         OCE,     // Output clock enable
    input  wire         RESET,   // Reset
    input  wire         WRE,     // Write enable
    input  wire [2:0]   BLKSEL,  // Block select
    input  wire [13:0]  AD,      // Address (14-bit)
    input  wire [31:0]  DI,      // Data input (max 32-bit)
    output reg  [31:0]  DO       // Data output (max 32-bit)
);

    // Parameters
    parameter BIT_WIDTH = 16;           // 1, 2, 4, 8, 16, 32
    parameter READ_MODE = 1'b0;         // 0=BYPASS, 1=PIPELINE
    parameter WRITE_MODE = 2'b00;       // 00=NORMAL, 01=WRITE_THROUGH, 10=READ_BEFORE_WRITE
    parameter BLK_SEL = 3'b000;
    parameter RESET_MODE = "SYNC";
    parameter INIT_RAM_00 = 256'h0;     // Initial RAM contents (not used in this sim)

    // Calculate memory depth based on bit width
    // Gowin SP RAM is 16Kb total
    localparam MEM_DEPTH = (BIT_WIDTH == 32) ? 512 :
                           (BIT_WIDTH == 16) ? 1024 :
                           (BIT_WIDTH == 8)  ? 2048 :
                           (BIT_WIDTH == 4)  ? 4096 :
                           (BIT_WIDTH == 2)  ? 8192 :
                           (BIT_WIDTH == 1)  ? 16384 : 1024;

    // Calculate address width
    localparam ADDR_BITS = $clog2(MEM_DEPTH);

    // Memory array
    reg [31:0] mem [0:MEM_DEPTH-1];

    // Pipeline register for PIPELINE read mode
    reg [31:0] do_pipeline;

    // Extract actual address from 14-bit AD input
    // Must match pack_address() in ram_logic.sv:
    //   - WIDTH=32: {1'b0, addr[7:0], 5'b00000} -> extract from AD[12:5]
    //   - WIDTH=16: {2'b00, addr[9:0], 4'b0000} -> extract from AD[13:4]
    //   - WIDTH=8:  {1'b0, addr[10:0], 5'b00000} -> extract from AD[15:5] (impossible, use [13:5])
    wire [ADDR_BITS-1:0] addr;

    generate
        if (BIT_WIDTH == 32) begin
            assign addr = AD[12:5];  // Matches {1'b0, addr[7:0], 5'b00000}
        end else if (BIT_WIDTH == 16) begin
            assign addr = AD[13:4];  // Matches {2'b00, addr[9:0], 4'b0000}
        end else if (BIT_WIDTH == 8) begin
            assign addr = AD[13:5];  // Matches {1'b0, addr[10:0], 5'b00000} (limited by 14-bit AD)
        end else begin
            assign addr = AD[ADDR_BITS-1:0];
        end
    endgenerate

    // Mask for valid data bits
    wire [31:0] data_mask = (BIT_WIDTH == 32) ? 32'hFFFFFFFF :
                            (BIT_WIDTH == 16) ? 32'h0000FFFF :
                            (BIT_WIDTH == 8)  ? 32'h000000FF :
                            (BIT_WIDTH == 4)  ? 32'h0000000F :
                            (BIT_WIDTH == 2)  ? 32'h00000003 :
                            (BIT_WIDTH == 1)  ? 32'h00000001 : 32'hFFFFFFFF;

    integer i;

    // Initialize memory to zero
    initial begin
        for (i = 0; i < MEM_DEPTH; i = i + 1) begin
            mem[i] = 32'h0;
        end
        DO = 32'h0;
        do_pipeline = 32'h0;
    end

    // Main memory operation
    always @(posedge CLK) begin
        if (RESET) begin
            // Synchronous reset
            DO <= 32'h0;
            do_pipeline <= 32'h0;
            // Optionally clear memory on reset
            // for (i = 0; i < MEM_DEPTH; i = i + 1) begin
            //     mem[i] <= 32'h0;
            // end
        end else if (CE) begin
            // Write operation
            if (WRE) begin
                mem[addr] <= DI & data_mask;

                // Write modes
                case (WRITE_MODE)
                    2'b00: begin // NORMAL - write only
                        // Do nothing extra
                    end
                    2'b01: begin // WRITE_THROUGH - write and read
                        if (READ_MODE == 1'b0) begin // BYPASS
                            DO <= DI & data_mask;
                        end else begin // PIPELINE
                            do_pipeline <= DI & data_mask;
                        end
                    end
                    2'b10: begin // READ_BEFORE_WRITE - read old value
                        if (READ_MODE == 1'b0) begin // BYPASS
                            DO <= mem[addr];
                        end else begin // PIPELINE
                            do_pipeline <= mem[addr];
                        end
                    end
                endcase
            end else begin
                // Read operation (when not writing)
                if (READ_MODE == 1'b0) begin
                    // BYPASS mode - combinational read
                    DO <= mem[addr];
                end else begin
                    // PIPELINE mode - registered read
                    do_pipeline <= mem[addr];
                end
            end
        end
    end

    // Output pipeline stage (for PIPELINE read mode)
    always @(posedge CLK) begin
        if (RESET) begin
            if (READ_MODE == 1'b1) begin
                DO <= 32'h0;
            end
        end else if (OCE || (READ_MODE == 1'b0)) begin
            if (READ_MODE == 1'b1) begin
                DO <= do_pipeline;
            end
        end
    end

endmodule
