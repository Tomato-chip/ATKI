// Debug testbench
module i2s_clock_gen_tb_debug;

  localparam int unsigned SCK_DIV = 8;
  localparam int unsigned SCKS_PER_FRAME = 64;

  logic clk_i, rst_ni;
  logic sck_o, ws_o, frame_start_o;

  i2s_clock_gen #(
    .SYS_CLK_HZ(27_000_000),
    .SCK_DIV(SCK_DIV),
    .SCKS_PER_FRAME(SCKS_PER_FRAME)
  ) dut (.*);

  always #18.518 clk_i = ~clk_i;

  initial begin
    clk_i = 0;
    rst_ni = 0;
    #100;
    rst_ni = 1;

    repeat(200) begin
      @(posedge clk_i);
      $display("cyc=%0d sck_ctr=%0d sck=%0b ws=%0d",
               $time/37, dut.sck_ctr_q, sck_o, ws_o);
    end

    $finish;
  end

endmodule
