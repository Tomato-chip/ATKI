// ============================================================================
// I2S Clock Generator Simple Testbench (Verilator-compatible)
// ============================================================================

module i2s_clock_gen_tb_simple;

  localparam int unsigned SYS_CLK_HZ      = 27_000_000;
  localparam int unsigned SCK_DIV         = 8;
  localparam int unsigned SCKS_PER_FRAME  = 64;
  localparam bit          WS_POL          = 1'b0;
  localparam bit          FRAME_PULSE_EN  = 1'b1;

  localparam int unsigned EXPECTED_SCK_PERIOD    = SCK_DIV;
  localparam int unsigned EXPECTED_WS_HALF_PERIOD = SCKS_PER_FRAME * SCK_DIV;

  localparam int unsigned SIM_WS_PERIODS = 4;
  localparam int unsigned SIM_CYCLES = EXPECTED_WS_HALF_PERIOD * (SIM_WS_PERIODS * 2) + 1000;

  logic clk_i;
  logic rst_ni;
  logic sck_o;
  logic ws_o;
  logic frame_start_o;

  int unsigned cycle_count;
  int unsigned sck_toggle_count;
  int unsigned ws_toggle_count;
  logic sck_prev, ws_prev;

  // DUT instantiation
  i2s_clock_gen #(
    .SYS_CLK_HZ      ( SYS_CLK_HZ      ),
    .SCK_DIV         ( SCK_DIV         ),
    .SCKS_PER_FRAME  ( SCKS_PER_FRAME  ),
    .WS_POL          ( WS_POL          ),
    .FRAME_PULSE_EN  ( FRAME_PULSE_EN  )
  ) dut (
    .clk_i          ( clk_i          ),
    .rst_ni         ( rst_ni         ),
    .sck_o          ( sck_o          ),
    .ws_o           ( ws_o           ),
    .frame_start_o  ( frame_start_o  )
  );

  // Clock generation - Verilator compatible
  always #18.518 clk_i = ~clk_i;  // ~27 MHz (37.036 ns period)

  // Monitoring
  always @(posedge clk_i) begin
    if (!rst_ni) begin
      cycle_count = 0;
      sck_toggle_count = 0;
      ws_toggle_count = 0;
      sck_prev = 1'b0;
      ws_prev = WS_POL;
    end else begin
      cycle_count = cycle_count + 1;

      // Check for SCK toggle
      if (sck_o != sck_prev) begin
        sck_toggle_count = sck_toggle_count + 1;
      end
      sck_prev = sck_o;

      // Check for WS toggle
      if (ws_o != ws_prev) begin
        ws_toggle_count = ws_toggle_count + 1;
        $display("[%0t] WS toggled (count=%0d, cycle=%0d)", $time, ws_toggle_count, cycle_count);
      end
      ws_prev = ws_o;
    end
  end

  // Test sequence
  initial begin
    $display("=================================================================");
    $display("I2S Clock Generator Simple Test");
    $display("=================================================================");
    $display("Expected SCK period: %0d cycles", EXPECTED_SCK_PERIOD);
    $display("Expected WS half-period: %0d cycles", EXPECTED_WS_HALF_PERIOD);
    $display("Running for %0d cycles", SIM_CYCLES);
    $display("=================================================================\n");

    clk_i = 1'b0;
    rst_ni = 1'b0;
    #200;
    rst_ni = 1'b1;
    $display("[%0t] Reset released", $time);

    // Run for specified cycles
    repeat(SIM_CYCLES) @(posedge clk_i);

    $display("\n=================================================================");
    $display("Test Results");
    $display("=================================================================");
    $display("Total cycles:      %0d", cycle_count);
    $display("SCK toggles:       %0d", sck_toggle_count);
    $display("WS toggles:        %0d", ws_toggle_count);
    $display("Expected WS toggles: ~%0d", (SIM_WS_PERIODS * 2));

    if (ws_toggle_count >= (SIM_WS_PERIODS * 2 - 1) && ws_toggle_count <= (SIM_WS_PERIODS * 2 + 1)) begin
      $display("\n ████████╗███████╗███████╗████████╗   ██████╗  █████╗ ███████╗███████╗");
      $display(" ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝   ██╔══██╗██╔══██╗██╔════╝██╔════╝");
      $display("    ██║   █████╗  ███████╗   ██║      ██████╔╝███████║███████╗███████╗");
      $display("    ██║   ██╔══╝  ╚════██║   ██║      ██╔═══╝ ██╔══██║╚════██║╚════██║");
      $display("    ██║   ███████╗███████║   ██║      ██║     ██║  ██║███████║███████║");
      $display("    ╚═╝   ╚══════╝╚══════╝   ╚═╝      ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝\n");
    end else begin
      $display("\n ████████╗███████╗███████╗████████╗   ███████╗ █████╗ ██╗██╗     ");
      $display(" ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝   ██╔════╝██╔══██╗██║██║     ");
      $display("    ██║   █████╗  ███████╗   ██║      █████╗  ███████║██║██║     ");
      $display("    ██║   ██╔══╝  ╚════██║   ██║      ██╔══╝  ██╔══██║██║██║     ");
      $display("    ██║   ███████╗███████║   ██║      ██║     ██║  ██║██║███████╗");
      $display("    ╚═╝   ╚══════╝╚══════╝   ╚═╝      ╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝\n");
    end

    $display("=================================================================\n");
    $finish;
  end

endmodule
