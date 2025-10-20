// =============================================================================
// generic_dpram.sv
// Generic synthesizable dual-port RAM with separate write and read ports
// =============================================================================
// Simple dual-port RAM (1W1R) with synchronous read.
// Mimics Gowin DPB behavior for simulation and portability.
// Write port (A): synchronous write
// Read port (B): synchronous read with 1-cycle latency
// =============================================================================

module generic_dpram #(
    parameter int unsigned DATA_WIDTH = 16,
    parameter int unsigned DEPTH      = 256,
    parameter int unsigned ADDR_WIDTH = $clog2(DEPTH)
)(
    input  logic                     clk_i,
    input  logic                     rst_ni,      // Active-low synchronous reset

    // Write port
    input  logic                     wr_en_i,
    input  logic [ADDR_WIDTH-1:0]    wr_addr_i,
    input  logic [DATA_WIDTH-1:0]    wr_data_i,

    // Read port
    input  logic                     rd_en_i,
    input  logic [ADDR_WIDTH-1:0]    rd_addr_i,
    output logic [DATA_WIDTH-1:0]    rd_data_o
);

    // =========================================================================
    // RAM array
    // =========================================================================
    logic [DATA_WIDTH-1:0] mem [DEPTH];

    // =========================================================================
    // Write logic
    // =========================================================================
    always_ff @(posedge clk_i) begin
        if (wr_en_i) begin
            mem[wr_addr_i] <= wr_data_i;
        end
    end

    // =========================================================================
    // Read logic (synchronous with 1-cycle latency)
    // Read always happens, rd_en_i just gates the output valid signal
    // =========================================================================
    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            rd_data_o <= '0;
        end else begin
            rd_data_o <= mem[rd_addr_i];
        end
    end

    // =========================================================================
    // Optional memory initialization for simulation
    // =========================================================================
    `ifndef SYNTHESIS
        initial begin
            for (int i = 0; i < DEPTH; i++) begin
                mem[i] = '0;
            end
        end
    `endif

endmodule
