// =============================================================================
// i2s_capture_24_tb.sv
// Testbench for i2s_capture_24 module
// =============================================================================
// Verifies:
//   1. Correct I²S timing (64 SCK per frame, WS toggles every 32 SCK)
//   2. 24-bit pattern capture on left and right channels
//   3. MSB-first data format with 1 SCK delay from WS edge
//   4. ready_o pulse timing
//   5. Synchronization and edge detection logic
// =============================================================================

`timescale 1ns / 1ps

module i2s_capture_24_tb;

  // =========================================================================
  // Clock and Reset
  // =========================================================================
  logic clk_i;
  logic rst_ni;

  // System clock: 27 MHz (period = 37.037 ns)
  localparam real CLK_PERIOD_NS = 37.037;

  initial begin
    clk_i = 1'b0;
    forever #(CLK_PERIOD_NS/2) clk_i = ~clk_i;
  end

  // =========================================================================
  // DUT Signals
  // =========================================================================
  logic        sck_i;
  logic        ws_i;
  logic        sd_i;
  logic signed [23:0] left_o;
  logic signed [23:0] right_o;
  logic        ready_o;

  // =========================================================================
  // I²S Timing Parameters
  // =========================================================================
  // SCK: 3.375 MHz (27 MHz / 8) = 296.296 ns period
  localparam int SCK_DIV = 8;
  localparam real SCK_PERIOD_NS = CLK_PERIOD_NS * SCK_DIV;

  // Frame timing: 64 SCK cycles per frame (32 per channel)
  localparam int SCKS_PER_CHANNEL = 32;
  localparam int SCKS_PER_FRAME = 64;

  // =========================================================================
  // Test Patterns
  // =========================================================================
  // Test pattern 1: Incrementing values
  logic [23:0] left_pattern_1  = 24'h123456;
  logic [23:0] right_pattern_1 = 24'hABCDEF;

  // Test pattern 2: Edge cases
  logic [23:0] left_pattern_2  = 24'h000000;  // Zero
  logic [23:0] right_pattern_2 = 24'hFFFFFF;  // Max value

  // Test pattern 3: Alternating bits
  logic [23:0] left_pattern_3  = 24'hAAAAAA;
  logic [23:0] right_pattern_3 = 24'h555555;

  // Test pattern 4: Signed values (two's complement)
  logic [23:0] left_pattern_4  = 24'h7FFFFF;  // Max positive
  logic [23:0] right_pattern_4 = 24'h800000;  // Min negative

  // =========================================================================
  // DUT Instantiation
  // =========================================================================
  i2s_capture_24 dut (
    .clk_i    (clk_i),
    .rst_ni   (rst_ni),
    .sck_i    (sck_i),
    .ws_i     (ws_i),
    .sd_i     (sd_i),
    .left_o   (left_o),
    .right_o  (right_o),
    .ready_o  (ready_o)
  );

  // =========================================================================
  // SCK Generation (divided from clk_i)
  // =========================================================================
  logic [2:0] sck_counter;
  logic       sck_reg;

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      sck_counter <= 3'd0;
      sck_reg <= 1'b0;
    end else begin
      if (sck_counter == (SCK_DIV/2 - 1)) begin
        sck_counter <= 3'd0;
        sck_reg <= ~sck_reg;
      end else begin
        sck_counter <= sck_counter + 1'b1;
      end
    end
  end

  assign sck_i = sck_reg;

  // =========================================================================
  // WS (Word Select) Generation
  // =========================================================================
  // WS toggles every 32 SCK cycles
  // WS = 0 for left channel, WS = 1 for right channel
  logic [5:0] sck_edge_counter;
  logic       ws_reg;
  logic       sck_prev;

  wire sck_rising = (sck_i && !sck_prev);
  wire sck_falling = (!sck_i && sck_prev);

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      sck_edge_counter <= 6'd0;
      ws_reg <= 1'b0;
      sck_prev <= 1'b0;
    end else begin
      sck_prev <= sck_i;

      if (sck_rising) begin
        if (sck_edge_counter == (SCKS_PER_CHANNEL - 1)) begin
          sck_edge_counter <= 6'd0;
          ws_reg <= ~ws_reg;  // Toggle WS every 32 SCK
        end else begin
          sck_edge_counter <= sck_edge_counter + 1'b1;
        end
      end
    end
  end

  assign ws_i = ws_reg;

  // =========================================================================
  // SD (Serial Data) Generation
  // =========================================================================
  // I²S format: MSB-first, data delayed by 1 SCK from WS edge
  logic [4:0]  bit_index;      // 0-24 for 25 bits transmitted
  logic [23:0] current_pattern;
  logic        ws_prev;
  logic        new_channel;

  wire ws_edge_det = (ws_i != ws_prev);

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      bit_index <= 5'd0;
      current_pattern <= left_pattern_1;
      ws_prev <= 1'b0;
      sd_i <= 1'b0;
      new_channel <= 1'b0;
    end else begin
      ws_prev <= ws_i;

      // Detect WS edge (channel transition)
      if (ws_edge_det) begin
        bit_index <= 5'd0;
        new_channel <= 1'b1;

        // Load new pattern based on channel
        if (ws_i == 1'b0) begin
          // Entering left channel
          current_pattern <= left_pattern_1;
        end else begin
          // Entering right channel
          current_pattern <= right_pattern_1;
        end
        // Set first bit (dummy) immediately
        sd_i <= 1'b0;
      end else if (sck_falling) begin
        // Update sd_i on falling edge so it's stable for next rising edge
        new_channel <= 1'b0;

        if (bit_index < 5'd24) begin
          // Prepare next bit (will be sampled on upcoming rising edge)
          // bit_index 0: prepare bit 23 (MSB)
          // bit_index 1: prepare bit 22
          // ...
          // bit_index 23: prepare bit 0 (LSB)
          sd_i <= current_pattern[23 - bit_index];
          bit_index <= bit_index + 1'b1;
        end else begin
          // After 24 data bits, tristate (drive low in simulation)
          sd_i <= 1'b0;
          if (bit_index < 5'd25) begin
            bit_index <= bit_index + 1'b1;
          end
        end
      end
    end
  end

  // =========================================================================
  // Test Sequence Control
  // =========================================================================
  int test_phase;
  int frame_count;
  logic test_running;

  // Verification counters
  int left_captures;
  int right_captures;
  int ready_pulses;
  int errors;
  int ready_pulse_width;  // For pulse width verification

  // =========================================================================
  // Stimulus and Verification
  // =========================================================================
  initial begin
    // Initialize
    rst_ni = 1'b0;
    test_phase = 0;
    frame_count = 0;
    test_running = 1'b0;
    left_captures = 0;
    right_captures = 0;
    ready_pulses = 0;
    errors = 0;

    $display("=============================================================================");
    $display("I2S Capture 24-bit Testbench");
    $display("=============================================================================");
    $display("System Clock: %.3f MHz (period = %.3f ns)", 1000.0/CLK_PERIOD_NS, CLK_PERIOD_NS);
    $display("SCK Clock:    %.3f MHz (period = %.3f ns)", 1000.0/SCK_PERIOD_NS, SCK_PERIOD_NS);
    $display("Frame: %0d SCK cycles (%0d per channel)", SCKS_PER_FRAME, SCKS_PER_CHANNEL);
    $display("=============================================================================\n");

    // Waveform dump
    `ifdef VERILATOR
      $dumpfile("sim/i2s_capture_24_tb/i2s_capture_24_tb.vcd");
      $dumpvars(0, i2s_capture_24_tb);
    `else
      $dumpfile("i2s_capture_24_tb.vcd");
      $dumpvars(0, i2s_capture_24_tb);
    `endif

    // -----------------------------------------------------------------------
    // TEST PHASE 1: Reset and Initialization
    // -----------------------------------------------------------------------
    test_phase = 1;
    $display("[%0t ns] TEST PHASE 1: Reset and Initialization", $time);

    @(posedge clk_i);
    @(posedge clk_i);
    @(posedge clk_i);

    // Verify reset state
    if (left_o !== 24'h0 || right_o !== 24'h0 || ready_o !== 1'b0) begin
      $display("  [ERROR] Outputs not zero during reset!");
      $display("    left_o  = 0x%06h (expected 0x000000)", left_o);
      $display("    right_o = 0x%06h (expected 0x000000)", right_o);
      $display("    ready_o = %b (expected 0)", ready_o);
      errors++;
    end else begin
      $display("  [PASS] Reset state verified");
    end

    // Release reset
    rst_ni = 1'b1;
    @(posedge clk_i);
    @(posedge clk_i);

    $display("  [INFO] Reset released\n");

    // -----------------------------------------------------------------------
    // TEST PHASE 2: First Frame Capture (Pattern 1)
    // -----------------------------------------------------------------------
    test_phase = 2;
    $display("[%0t ns] TEST PHASE 2: First Frame Capture", $time);
    $display("  Testing pattern: Left=0x%06h, Right=0x%06h", left_pattern_1, right_pattern_1);

    test_running = 1'b1;

    // Wait for first complete frame (left + right)
    wait(ready_o == 1'b1);
    @(posedge clk_i);

    // Verify captured data
    if (left_o !== left_pattern_1) begin
      $display("  [ERROR] Left channel mismatch!");
      $display("    Expected: 0x%06h", left_pattern_1);
      $display("    Got:      0x%06h", left_o);
      errors++;
    end else begin
      $display("  [PASS] Left channel captured correctly: 0x%06h", left_o);
      left_captures++;
    end

    if (right_o !== right_pattern_1) begin
      $display("  [ERROR] Right channel mismatch!");
      $display("    Expected: 0x%06h", right_pattern_1);
      $display("    Got:      0x%06h", right_o);
      errors++;
    end else begin
      $display("  [PASS] Right channel captured correctly: 0x%06h", right_o);
      right_captures++;
    end

    ready_pulses++;
    frame_count++;
    $display("  [INFO] Frame %0d complete\n", frame_count);

    // -----------------------------------------------------------------------
    // TEST PHASE 3: Pattern 2 - Edge Cases (Zero and Max)
    // -----------------------------------------------------------------------
    test_phase = 3;
    $display("[%0t ns] TEST PHASE 3: Edge Case Patterns", $time);
    $display("  Testing pattern: Left=0x%06h, Right=0x%06h", left_pattern_2, right_pattern_2);

    // Update patterns - wait for ready_o to deassert first to ensure clean state
    wait(ready_o == 1'b0);
    @(posedge clk_i);
    left_pattern_1 = left_pattern_2;
    right_pattern_1 = right_pattern_2;

    // Wait for next frame
    wait(ready_o == 1'b1);
    @(posedge clk_i);

    if (left_o !== left_pattern_2) begin
      $display("  [ERROR] Left channel (zero) mismatch!");
      $display("    Expected: 0x%06h", left_pattern_2);
      $display("    Got:      0x%06h", left_o);
      errors++;
    end else begin
      $display("  [PASS] Left channel (zero) captured: 0x%06h", left_o);
      left_captures++;
    end

    if (right_o !== right_pattern_2) begin
      $display("  [ERROR] Right channel (max) mismatch!");
      $display("    Expected: 0x%06h", right_pattern_2);
      $display("    Got:      0x%06h", right_o);
      errors++;
    end else begin
      $display("  [PASS] Right channel (max) captured: 0x%06h", right_o);
      right_captures++;
    end

    ready_pulses++;
    frame_count++;
    $display("  [INFO] Frame %0d complete\n", frame_count);

    // -----------------------------------------------------------------------
    // TEST PHASE 4: Pattern 3 - Alternating Bits
    // -----------------------------------------------------------------------
    test_phase = 4;
    $display("[%0t ns] TEST PHASE 4: Alternating Bit Patterns", $time);
    $display("  Testing pattern: Left=0x%06h, Right=0x%06h", left_pattern_3, right_pattern_3);

    wait(ready_o == 1'b0);
    @(posedge clk_i);
    left_pattern_1 = left_pattern_3;
    right_pattern_1 = right_pattern_3;

    wait(ready_o == 1'b1);
    @(posedge clk_i);

    if (left_o !== left_pattern_3) begin
      $display("  [ERROR] Left channel (0xAAAAAA) mismatch!");
      $display("    Expected: 0x%06h", left_pattern_3);
      $display("    Got:      0x%06h", left_o);
      errors++;
    end else begin
      $display("  [PASS] Left channel (0xAAAAAA) captured: 0x%06h", left_o);
      left_captures++;
    end

    if (right_o !== right_pattern_3) begin
      $display("  [ERROR] Right channel (0x555555) mismatch!");
      $display("    Expected: 0x%06h", right_pattern_3);
      $display("    Got:      0x%06h", right_o);
      errors++;
    end else begin
      $display("  [PASS] Right channel (0x555555) captured: 0x%06h", right_o);
      right_captures++;
    end

    ready_pulses++;
    frame_count++;
    $display("  [INFO] Frame %0d complete\n", frame_count);

    // -----------------------------------------------------------------------
    // TEST PHASE 5: Pattern 4 - Signed Values
    // -----------------------------------------------------------------------
    test_phase = 5;
    $display("[%0t ns] TEST PHASE 5: Signed Value Patterns", $time);
    $display("  Testing pattern: Left=0x%06h (max+), Right=0x%06h (min-)",
             left_pattern_4, right_pattern_4);

    wait(ready_o == 1'b0);
    @(posedge clk_i);
    left_pattern_1 = left_pattern_4;
    right_pattern_1 = right_pattern_4;

    wait(ready_o == 1'b1);
    @(posedge clk_i);

    if (left_o !== $signed(left_pattern_4)) begin
      $display("  [ERROR] Left channel (max positive) mismatch!");
      $display("    Expected: 0x%06h (%0d)", left_pattern_4, $signed(left_pattern_4));
      $display("    Got:      0x%06h (%0d)", left_o, left_o);
      errors++;
    end else begin
      $display("  [PASS] Left channel (max positive) captured: 0x%06h (%0d)",
               left_o, left_o);
      left_captures++;
    end

    if (right_o !== $signed(right_pattern_4)) begin
      $display("  [ERROR] Right channel (min negative) mismatch!");
      $display("    Expected: 0x%06h (%0d)", right_pattern_4, $signed(right_pattern_4));
      $display("    Got:      0x%06h (%0d)", right_o, right_o);
      errors++;
    end else begin
      $display("  [PASS] Right channel (min negative) captured: 0x%06h (%0d)",
               right_o, right_o);
      right_captures++;
    end

    ready_pulses++;
    frame_count++;
    $display("  [INFO] Frame %0d complete\n", frame_count);

    // -----------------------------------------------------------------------
    // TEST PHASE 6: Ready Pulse Timing Verification
    // -----------------------------------------------------------------------
    test_phase = 6;
    $display("[%0t ns] TEST PHASE 6: Ready Pulse Timing", $time);

    // Monitor ready_o pulse width (should be exactly 1 clock cycle)
    @(posedge clk_i);
    while (!ready_o) @(posedge clk_i);

    ready_pulse_width = 0;
    while (ready_o) begin
      ready_pulse_width++;
      @(posedge clk_i);
    end

    if (ready_pulse_width != 1) begin
      $display("  [ERROR] ready_o pulse width incorrect!");
      $display("    Expected: 1 cycle");
      $display("    Got:      %0d cycles", ready_pulse_width);
      errors++;
    end else begin
      $display("  [PASS] ready_o pulse width correct: %0d cycle", ready_pulse_width);
    end

    ready_pulses++;
    frame_count++;
    $display("  [INFO] Frame %0d complete\n", frame_count);

    // -----------------------------------------------------------------------
    // Test Complete - Wait for final frame to finish
    // -----------------------------------------------------------------------
    repeat(100) @(posedge clk_i);

    test_running = 1'b0;

    // -----------------------------------------------------------------------
    // Final Report
    // -----------------------------------------------------------------------
    $display("=============================================================================");
    $display("TEST COMPLETE");
    $display("=============================================================================");
    $display("Frames processed:      %0d", frame_count);
    $display("Left captures:         %0d", left_captures);
    $display("Right captures:        %0d", right_captures);
    $display("Ready pulses observed: %0d", ready_pulses);
    $display("Total errors:          %0d", errors);
    $display("=============================================================================");

    if (errors == 0) begin
      $display(">>> ALL TESTS PASSED <<<");
    end else begin
      $display(">>> %0d TEST(S) FAILED <<<", errors);
    end

    $display("=============================================================================\n");
    $display("Waveform saved to: sim/i2s_capture_24_tb/i2s_capture_24_tb.vcd");

    $finish;
  end

  // =========================================================================
  // Continuous Monitoring
  // =========================================================================

  // Monitor ready_o assertions
  always @(posedge clk_i) begin
    if (test_running && ready_o) begin
      $display("  [%0t ns] ready_o asserted (L=0x%06h, R=0x%06h)",
               $time, left_o, right_o);
    end
  end

  // Timeout watchdog (prevent infinite simulation)
  initial begin
    #1000000;  // 1 ms timeout
    $display("\n[ERROR] Simulation timeout! Test did not complete in time.");
    $display("This may indicate a hang or timing issue.\n");
    $finish;
  end

endmodule
