module tb_i2s_top (
    input  logic        clk,
    input  logic        rst_n,
    input  logic        sck,
    input  logic        ws,
    input  logic        sd,
    output logic [23:0] data24,
    output logic        valid
);

    i2s_capture_24 #(
        .CAPTURE_LEFT(1'b1)
    ) dut (
        .clk_i    (clk),
        .rst_ni   (rst_n),
        .sck_i    (sck),
        .ws_i     (ws),
        .sd_i     (sd),
        .data24_o (data24),
        .valid_o  (valid)
    );

endmodule
