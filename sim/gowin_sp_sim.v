// Behavioral simulation model for Gowin SP (Single-Port BSRAM) primitive
// For use in testbenches only - not for synthesis
//
// Supports the modes used in pingpong_buffer_sp:
// - READ_MODE = 1'b1 (BYPASS mode - output without register)
// - WRITE_MODE = 2'b00 (NORMAL mode)
// - RESET_MODE = "SYNC"
// - BIT_WIDTH configurable via defparam

`timescale 1ns / 1ps

module SP (
    output reg [31:0] DO,       // Data output (max 32-bit, actual width set by BIT_WIDTH)
    input      [13:0] AD,       // Address input (14-bit for flexibility)
    input      [31:0] DI,       // Data input (max 32-bit, actual width set by BIT_WIDTH)
    input             CLK,      // Clock
    input             CE,       // Clock enable
    input             OCE,      // Output clock enable (not used in BYPASS mode)
    input             RESET,    // Reset (active high, sync)
    input             WRE,      // Write enable
    input      [2:0]  BLKSEL    // Block select (not used in basic config)
);

    // Parameters that can be set via defparam
    parameter BIT_WIDTH = 16;
    parameter READ_MODE = 1'b0;     // 0 = output register, 1 = BYPASS
    parameter [1:0] WRITE_MODE = 2'b00;  // 00 = NORMAL
    parameter [2:0] BLK_SEL = 3'b000;
    parameter RESET_MODE = "SYNC";

    // Memory array - 16K words × 32-bit (overkill but covers all cases)
    // In reality, Gowin SP is 16Kb total, so bit_width × depth = 16384
    // For 16-bit width: 1024 words
    // We'll allocate generously for simulation
    localparam MEM_DEPTH = 16384 / BIT_WIDTH;
    reg [31:0] mem [0:MEM_DEPTH-1];

    // Extract word address from AD
    // For 16-bit words: AD = {2'b00, addr[9:0], 4'b0000}
    // So word address is AD[13:4]
    wire [9:0] word_addr = AD[13:4];

    // Internal signals
    reg [31:0] read_data;
    integer i;

    // Initialize memory to zero
    initial begin
        for (i = 0; i < MEM_DEPTH; i = i + 1) begin
            mem[i] = 32'h0;
        end
        DO = 32'h0;
        read_data = 32'h0;
    end

    // Main memory operation
    always @(posedge CLK) begin
        if (CE) begin
            if (RESET) begin
                // Synchronous reset
                if (READ_MODE == 1'b1) begin
                    // BYPASS mode - output drives 0 after reset
                    read_data <= 32'h0;
                end else begin
                    // Registered mode - output register cleared
                    DO <= 32'h0;
                end
            end else begin
                // Write operation (NORMAL mode)
                if (WRE) begin
                    mem[word_addr] <= DI;
                end

                // Read operation
                read_data <= mem[word_addr];

                // Output register (only used if READ_MODE = 0)
                if (READ_MODE == 1'b0) begin
                    DO <= read_data;
                end
            end
        end
    end

    // Output assignment for BYPASS mode (READ_MODE = 1)
    // In BYPASS mode, output reflects memory content without register
    always @(*) begin
        if (READ_MODE == 1'b1) begin
            DO = read_data;
        end
    end

    // Mask output to actual bit width for cleaner simulation
    // Note: In real hardware this is handled by width configuration
    // Here we just mask for simulation clarity
    always @(*) begin
        case (BIT_WIDTH)
            1:  DO = DO & 32'h00000001;
            2:  DO = DO & 32'h00000003;
            4:  DO = DO & 32'h0000000F;
            8:  DO = DO & 32'h000000FF;
            16: DO = DO & 32'h0000FFFF;
            32: DO = DO & 32'hFFFFFFFF;
            default: DO = DO;  // Leave as-is for other widths
        endcase
    end

endmodule
