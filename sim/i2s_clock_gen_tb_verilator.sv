// ============================================================================
// I2S Clock Generator Testbench (Verilator-compatible)
// ============================================================================
// Self-checking testbench with:
//   - Period measurement and verification
//   - Duty cycle checking
//   - WS/SCK timing relationship verification
//   - Clear PASS/FAIL reporting
// ============================================================================

`timescale 1ns/1ps

module i2s_clock_gen_tb_verilator;

  // ============================================================================
  // Parameters
  // ============================================================================
  localparam int unsigned SYS_CLK_HZ      = 27_000_000;
  localparam int unsigned SCK_DIV         = 8;
  localparam int unsigned SCKS_PER_FRAME  = 64;
  localparam bit          WS_POL          = 1'b0;
  localparam bit          FRAME_PULSE_EN  = 1'b1;

  // Calculated expected values
  localparam int unsigned EXPECTED_SCK_PERIOD    = SCK_DIV;           // in sysclk cycles
  localparam int unsigned EXPECTED_WS_HALF_PERIOD = SCKS_PER_FRAME * SCK_DIV;  // half-period
  localparam int unsigned EXPECTED_WS_PERIOD      = 2 * EXPECTED_WS_HALF_PERIOD;

  localparam real SYS_CLK_PERIOD_NS = 1_000_000_000.0 / SYS_CLK_HZ;  // 37.037 ns
  localparam real SCK_FREQ_HZ       = real'(SYS_CLK_HZ) / real'(SCK_DIV);
  localparam real WS_FREQ_HZ        = SCK_FREQ_HZ / real'(SCKS_PER_FRAME);

  // Simulation parameters
  localparam int unsigned SIM_WS_PERIODS = 4;  // Measure 4 complete WS periods
  localparam int unsigned SIM_TIMEOUT_CYCLES = EXPECTED_WS_PERIOD * (SIM_WS_PERIODS + 2) * 2;

  // ============================================================================
  // DUT Signals
  // ============================================================================
  logic clk_i;
  logic rst_ni;
  logic sck_o;
  logic ws_o;
  logic frame_start_o;

  // ============================================================================
  // Clock Generation
  // ============================================================================
  initial begin
    clk_i = 1'b0;
    forever #(SYS_CLK_PERIOD_NS/2) clk_i = ~clk_i;
  end

  // ============================================================================
  // DUT Instantiation
  // ============================================================================
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

  // ============================================================================
  // Measurement Variables
  // ============================================================================
  int unsigned sck_toggle_count;
  int unsigned sck_period_sum;
  int unsigned sck_period_count;
  int unsigned sck_high_time, sck_low_time;
  int unsigned sck_last_toggle_cycle;
  logic        sck_prev;

  int unsigned ws_toggle_count;
  int unsigned ws_period_sum;
  int unsigned ws_period_count;
  int unsigned ws_last_toggle_cycle;
  logic        ws_prev;

  int unsigned cycle_count;
  int unsigned frame_start_count;

  bit test_passed;
  int errors;

  // For checking WS changes only on SCK low
  int ws_change_on_sck_high_count;

  // Test variables for analysis
  int unsigned duty_diff_val;
  real ws_to_sck_ratio_val;

  // ============================================================================
  // SCK Period Measurement
  // ============================================================================
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      sck_prev              = 1'b0;
      sck_toggle_count      = 0;
      sck_last_toggle_cycle = 0;
      sck_high_time         = 0;
      sck_low_time          = 0;
      sck_period_sum        = 0;
      sck_period_count      = 0;
    end else begin
      sck_prev = sck_o;

      // Detect SCK toggle (rising or falling edge)
      if (sck_o != sck_prev && cycle_count > 10) begin
        int unsigned period;
        period = cycle_count - sck_last_toggle_cycle;
        sck_period_sum = sck_period_sum + period;
        sck_period_count = sck_period_count + 1;
        sck_last_toggle_cycle = cycle_count;
        sck_toggle_count = sck_toggle_count + 1;

        // Track high and low times separately
        if (sck_o) begin
          sck_low_time = period;  // Just measured a low period
        end else begin
          sck_high_time = period;  // Just measured a high period
        end
      end
    end
  end

  // ============================================================================
  // WS Period Measurement
  // ============================================================================
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      ws_prev              = WS_POL;
      ws_toggle_count      = 0;
      ws_last_toggle_cycle = 0;
      ws_period_sum        = 0;
      ws_period_count      = 0;
      ws_change_on_sck_high_count = 0;
    end else begin
      ws_prev = ws_o;

      // Detect WS toggle
      if (ws_o != ws_prev && cycle_count > 10) begin
        int unsigned period;
        period = cycle_count - ws_last_toggle_cycle;
        ws_period_sum = ws_period_sum + period;
        ws_period_count = ws_period_count + 1;
        ws_last_toggle_cycle = cycle_count;
        ws_toggle_count = ws_toggle_count + 1;

        // Check if WS changed when SCK was high (should not happen)
        if (sck_o) begin
          ws_change_on_sck_high_count = ws_change_on_sck_high_count + 1;
          $error("[ERROR] WS changed when SCK was high at cycle %0d", cycle_count);
        end
      end
    end
  end

  // ============================================================================
  // Frame Start Pulse Counter
  // ============================================================================
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      frame_start_count = 0;
    end else if (frame_start_o) begin
      frame_start_count = frame_start_count + 1;

      // Check that frame start occurs at left channel
      if (ws_o != WS_POL) begin
        $error("[ERROR] Frame start when not at left channel at cycle %0d", cycle_count);
        errors = errors + 1;
      end
    end
  end

  // ============================================================================
  // Cycle Counter
  // ============================================================================
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      cycle_count = 0;
    end else begin
      cycle_count = cycle_count + 1;
    end
  end

  // ============================================================================
  // Test Sequence
  // ============================================================================
  initial begin
    test_passed = 1'b1;
    errors = 0;

    $display("=================================================================");
    $display("I2S Clock Generator Testbench");
    $display("=================================================================");
    $display("Configuration:");
    $display("  System Clock:      %0d Hz (%.3f ns period)", SYS_CLK_HZ, SYS_CLK_PERIOD_NS);
    $display("  SCK Divider:       %0d", SCK_DIV);
    $display("  SCKs per Frame:    %0d", SCKS_PER_FRAME);
    $display("  Expected SCK:      %.3f MHz", SCK_FREQ_HZ / 1_000_000.0);
    $display("  Expected WS:       %.3f kHz", WS_FREQ_HZ / 1_000.0);
    $display("=================================================================\n");

    // Apply reset
    rst_ni = 1'b0;
    repeat (10) @(posedge clk_i);
    rst_ni = 1'b1;
    $display("[%0t] Reset released", $time);

    // Wait for multiple WS periods
    wait (ws_toggle_count >= (SIM_WS_PERIODS * 2));  // *2 because WS toggles twice per period
    repeat (100) @(posedge clk_i);  // Extra cycles for measurement

    $display("\n=================================================================");
    $display("Measurement Results");
    $display("=================================================================");

    // Analyze SCK measurements
    if (sck_period_count > 0) begin
      real sck_period_avg;
      sck_period_avg = real'(sck_period_sum) / real'(sck_period_count);

      $display("\nSCK Half-Period (sysclk cycles):");
      $display("  Expected:   %0d", EXPECTED_SCK_PERIOD / 2);
      $display("  Measured:   %.2f (avg)", sck_period_avg);
      $display("  High Time:  %0d cycles", sck_high_time);
      $display("  Low Time:   %0d cycles", sck_low_time);
      $display("  Full Period: %0d cycles", sck_high_time + sck_low_time);

      // Check SCK period
      if (sck_high_time + sck_low_time != EXPECTED_SCK_PERIOD) begin
        $error("[FAIL] SCK full period is %0d, expected %0d",
               sck_high_time + sck_low_time, EXPECTED_SCK_PERIOD);
        test_passed = 1'b0;
        errors = errors + 1;
      end else begin
        $display("  [PASS] SCK period matches expected value");
      end

      // Check duty cycle (should be within 1 cycle of 50%)
      duty_diff_val = sck_high_time > sck_low_time ?
                      sck_high_time - sck_low_time : sck_low_time - sck_high_time;
      if (duty_diff_val > 1) begin
        $error("[FAIL] SCK duty cycle not balanced (diff = %0d cycles)", duty_diff_val);
        test_passed = 1'b0;
        errors = errors + 1;
      end else begin
        $display("  [PASS] SCK duty cycle is balanced (diff = %0d cycle)", duty_diff_val);
      end
    end

    // Analyze WS measurements
    if (ws_period_count > 0) begin
      real ws_period_avg;
      ws_period_avg = real'(ws_period_sum) / real'(ws_period_count);

      $display("\nWS Half-Period (sysclk cycles):");
      $display("  Expected:   %0d", EXPECTED_WS_HALF_PERIOD);
      $display("  Measured:   %.2f (avg)", ws_period_avg);

      // Check WS period (allow ±1 cycle tolerance due to measurement sampling)
      if (ws_period_avg < EXPECTED_WS_HALF_PERIOD - 1 ||
          ws_period_avg > EXPECTED_WS_HALF_PERIOD + 1) begin
        $error("[FAIL] WS period is %.2f, expected %0d", ws_period_avg, EXPECTED_WS_HALF_PERIOD);
        test_passed = 1'b0;
        errors = errors + 1;
      end else begin
        $display("  [PASS] WS period matches expected value");
      end

      // Check that WS period is exactly SCKS_PER_FRAME * SCK_PERIOD
      ws_to_sck_ratio_val = ws_period_avg / real'(sck_high_time + sck_low_time);
      $display("\nWS to SCK Relationship:");
      $display("  Expected SCKs per half-frame: %0d", SCKS_PER_FRAME);
      $display("  Measured ratio: %.2f", ws_to_sck_ratio_val);

      if (ws_to_sck_ratio_val < SCKS_PER_FRAME - 0.5 || ws_to_sck_ratio_val > SCKS_PER_FRAME + 0.5) begin
        $error("[FAIL] WS to SCK ratio incorrect");
        test_passed = 1'b0;
        errors = errors + 1;
      end else begin
        $display("  [PASS] WS to SCK ratio correct");
      end
    end

    // Check WS transition timing
    $display("\nWS Transition Timing:");
    $display("  WS changes on SCK high: %0d", ws_change_on_sck_high_count);
    if (ws_change_on_sck_high_count > 0) begin
      $error("[FAIL] WS changed when SCK was high");
      test_passed = 1'b0;
      errors = errors + ws_change_on_sck_high_count;
    end else begin
      $display("  [PASS] All WS transitions occurred on SCK falling edge");
    end

    // Check frame start pulses
    $display("\nFrame Start Pulses:");
    $display("  Total pulses: %0d", frame_start_count);
    $display("  Expected:     ~%0d", SIM_WS_PERIODS);
    if (frame_start_count < SIM_WS_PERIODS - 1 || frame_start_count > SIM_WS_PERIODS + 1) begin
      $error("[FAIL] Frame start pulse count unexpected");
      test_passed = 1'b0;
      errors = errors + 1;
    end else begin
      $display("  [PASS] Frame start pulse count correct");
    end

    // Final result
    $display("\n=================================================================");
    $display("Test Summary");
    $display("=================================================================");
    if (test_passed && errors == 0) begin
      $display("  ████████╗███████╗███████╗████████╗    ██████╗  █████╗ ███████╗███████╗");
      $display("  ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝    ██╔══██╗██╔══██╗██╔════╝██╔════╝");
      $display("     ██║   █████╗  ███████╗   ██║       ██████╔╝███████║███████╗███████╗");
      $display("     ██║   ██╔══╝  ╚════██║   ██║       ██╔═══╝ ██╔══██║╚════██║╚════██║");
      $display("     ██║   ███████╗███████║   ██║       ██║     ██║  ██║███████║███████║");
      $display("     ╚═╝   ╚══════╝╚══════╝   ╚═╝       ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝");
      $display("\n  All tests passed successfully!");
      $display("  Errors: 0");
    end else begin
      $display("  ████████╗███████╗███████╗████████╗    ███████╗ █████╗ ██╗██╗     ");
      $display("  ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝    ██╔════╝██╔══██╗██║██║     ");
      $display("     ██║   █████╗  ███████╗   ██║       █████╗  ███████║██║██║     ");
      $display("     ██║   ██╔══╝  ╚════██║   ██║       ██╔══╝  ██╔══██║██║██║     ");
      $display("     ██║   ███████╗███████║   ██║       ██║     ██║  ██║██║███████╗");
      $display("     ╚═╝   ╚══════╝╚══════╝   ╚═╝       ╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝");
      $display("\n  Test failed with %0d errors", errors);
    end
    $display("=================================================================\n");

    $finish;
  end

  // Timeout watchdog
  initial begin
    repeat (SIM_TIMEOUT_CYCLES) @(posedge clk_i);
    $error("[TIMEOUT] Simulation exceeded maximum cycles");
    $display("\n=================================================================");
    $display("TEST FAIL - TIMEOUT");
    $display("=================================================================\n");
    $finish;
  end

  // VCD dump for waveform viewing
  initial begin
    $dumpfile("i2s_clock_gen_tb.vcd");
    $dumpvars(0, i2s_clock_gen_tb_verilator);
  end

endmodule
