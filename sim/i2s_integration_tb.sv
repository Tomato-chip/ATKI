// ============================================================================
// I2S Integration Testbench
// ============================================================================
// Tests the complete I2S capture pipeline:
//   - i2s_clock_gen: Generates SCK and WS signals
//   - i2s_capture_24: Captures 24-bit L/R samples from I2S stream
//
// Verification Strategy:
//   1. Generate proper I2S clock (64 SCK per frame, WS toggles every 32 SCK)
//   2. Feed deterministic 24-bit left/right patterns on sd_i
//   3. Verify left_o and right_o outputs match expected samples
//   4. Verify ready_o pulses once per completed L+R pair
// ============================================================================

`timescale 1ns/1ps

module i2s_integration_tb;

  // ============================================================================
  // Parameters
  // ============================================================================
  localparam int unsigned SYS_CLK_HZ      = 27_000_000;
  localparam int unsigned SCK_DIV         = 8;
  localparam int unsigned SCKS_PER_FRAME  = 32;  // Half frame (one channel)
  localparam bit          WS_POL          = 1'b0; // 0=left-low

  localparam real SYS_CLK_PERIOD_NS = 1_000_000_000.0 / SYS_CLK_HZ;  // 37.037 ns

  // Test patterns - deterministic 24-bit values
  localparam logic [23:0] TEST_LEFT_1  = 24'hA5A5A5;
  localparam logic [23:0] TEST_RIGHT_1 = 24'h5A5A5A;
  localparam logic [23:0] TEST_LEFT_2  = 24'h123456;
  localparam logic [23:0] TEST_RIGHT_2 = 24'h789ABC;
  localparam logic [23:0] TEST_LEFT_3  = 24'hDEF012;
  localparam logic [23:0] TEST_RIGHT_3 = 24'h345678;

  // ============================================================================
  // Signals
  // ============================================================================
  logic clk_i;
  logic rst_ni;

  // I2S signals
  logic sck_o;
  logic ws_o;
  logic frame_start_o;
  logic sd_i;

  // Capture outputs
  logic signed [23:0] left_o;
  logic signed [23:0] right_o;
  logic ready_o;

  // Test control
  int unsigned test_num;
  int unsigned error_count;
  int unsigned ready_count;

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

  // I2S Clock Generator
  i2s_clock_gen #(
    .SYS_CLK_HZ      ( SYS_CLK_HZ      ),
    .SCK_DIV         ( SCK_DIV         ),
    .SCKS_PER_FRAME  ( SCKS_PER_FRAME  ),
    .WS_POL          ( WS_POL          ),
    .FRAME_PULSE_EN  ( 1'b1            )
  ) u_clk_gen (
    .clk_i          ( clk_i          ),
    .rst_ni         ( rst_ni         ),
    .sck_o          ( sck_o          ),
    .ws_o           ( ws_o           ),
    .frame_start_o  ( frame_start_o  )
  );

  // I2S Capture
  i2s_capture_24 u_capture (
    .clk_i     ( clk_i     ),
    .rst_ni    ( rst_ni    ),
    .sck_i     ( sck_o     ),
    .ws_i      ( ws_o      ),
    .sd_i      ( sd_i      ),
    .left_o    ( left_o    ),
    .right_o   ( right_o   ),
    .ready_o   ( ready_o   )
  );

  // ============================================================================
  // I2S Data Generator
  // ============================================================================
  // Generate serial data on sd_i based on current test pattern

  logic [24:0] current_pattern;  // 25 bits (1 dummy + 24 data)
  int unsigned bit_index;

  // Track WS and SCK edges to know when to load new pattern and shift
  logic ws_prev;
  logic sck_prev;
  logic ws_edge;
  logic sck_rising;
  logic sck_falling;

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      ws_prev <= WS_POL;
      sck_prev <= 1'b0;
    end else begin
      ws_prev <= ws_o;
      sck_prev <= sck_o;
    end
  end

  assign ws_edge = (ws_o != ws_prev);
  assign sck_rising = (sck_o && !sck_prev);
  assign sck_falling = (!sck_o && sck_prev);

  // Load pattern on WS edge and shift on SCK rising
  logic init_done;
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      current_pattern <= {1'b0, TEST_LEFT_1};  // Start with first left pattern
      bit_index <= 24;
      init_done <= 1'b0;
    end else begin
      // On first clock after reset, mark init done
      if (!init_done) begin
        init_done <= 1'b1;
      end

      if (ws_edge) begin
        // Load new pattern based on which channel we're entering
        if (ws_o == WS_POL) begin
          // Entering left channel
          case (test_num)
            0: current_pattern <= {1'b0, TEST_LEFT_1};
            1: current_pattern <= {1'b0, TEST_LEFT_2};
            2: current_pattern <= {1'b0, TEST_LEFT_3};
            default: current_pattern <= {1'b0, TEST_LEFT_1};
          endcase
        end else begin
          // Entering right channel
          case (test_num)
            0: current_pattern <= {1'b0, TEST_RIGHT_1};
            1: current_pattern <= {1'b0, TEST_RIGHT_2};
            2: current_pattern <= {1'b0, TEST_RIGHT_3};
            default: current_pattern <= {1'b0, TEST_RIGHT_1};
          endcase
        end
        bit_index <= 24;  // Start from MSB (bit 24 is dummy, bit 23 is MSB of data)
      end else if (sck_falling) begin
        // On SCK falling edge, advance to next bit (so it's stable for next rising edge)
        if (bit_index > 0) begin
          bit_index <= bit_index - 1;
        end else begin
          bit_index <= 24;  // Wrap around (shouldn't normally happen)
        end
      end
    end
  end

  // Output current bit on sd_i (MSB first)
  assign sd_i = current_pattern[bit_index];

  // ============================================================================
  // Result Checking
  // ============================================================================

  logic check_enable;  // Only check when explicitly enabled

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      ready_count <= 0;
      error_count <= 0;
    end else if (ready_o) begin
      ready_count <= ready_count + 1;

      // Only check if enabled (to avoid transition periods)
      if (check_enable) begin
        // Check captured values
        case (test_num)
        0: begin
          if (left_o !== TEST_LEFT_1) begin
            $error("[FAIL] Test %0d: Left channel mismatch. Expected 0x%06h, got 0x%06h",
                   test_num, TEST_LEFT_1, left_o);
            error_count <= error_count + 1;
          end else begin
            $display("[PASS] Test %0d: Left channel = 0x%06h ✓", test_num, left_o);
          end

          if (right_o !== TEST_RIGHT_1) begin
            $error("[FAIL] Test %0d: Right channel mismatch. Expected 0x%06h, got 0x%06h",
                   test_num, TEST_RIGHT_1, right_o);
            error_count <= error_count + 1;
          end else begin
            $display("[PASS] Test %0d: Right channel = 0x%06h ✓", test_num, right_o);
          end
        end

        1: begin
          if (left_o !== TEST_LEFT_2) begin
            $error("[FAIL] Test %0d: Left channel mismatch. Expected 0x%06h, got 0x%06h",
                   test_num, TEST_LEFT_2, left_o);
            error_count <= error_count + 1;
          end else begin
            $display("[PASS] Test %0d: Left channel = 0x%06h ✓", test_num, left_o);
          end

          if (right_o !== TEST_RIGHT_2) begin
            $error("[FAIL] Test %0d: Right channel mismatch. Expected 0x%06h, got 0x%06h",
                   test_num, TEST_RIGHT_2, right_o);
            error_count <= error_count + 1;
          end else begin
            $display("[PASS] Test %0d: Right channel = 0x%06h ✓", test_num, right_o);
          end
        end

        2: begin
          if (left_o !== TEST_LEFT_3) begin
            $error("[FAIL] Test %0d: Left channel mismatch. Expected 0x%06h, got 0x%06h",
                   test_num, TEST_LEFT_3, left_o);
            error_count <= error_count + 1;
          end else begin
            $display("[PASS] Test %0d: Left channel = 0x%06h ✓", test_num, left_o);
          end

          if (right_o !== TEST_RIGHT_3) begin
            $error("[FAIL] Test %0d: Right channel mismatch. Expected 0x%06h, got 0x%06h",
                   test_num, TEST_RIGHT_3, right_o);
            error_count <= error_count + 1;
          end else begin
            $display("[PASS] Test %0d: Right channel = 0x%06h ✓", test_num, right_o);
          end
        end
        endcase
      end
    end
  end

  // ============================================================================
  // Test Sequence
  // ============================================================================
  initial begin
    $display("================================================================");
    $display("I2S Integration Testbench");
    $display("================================================================");
    $display("System Clock: %0d Hz (%.3f ns period)", SYS_CLK_HZ, SYS_CLK_PERIOD_NS);
    $display("SCK Divider: %0d", SCK_DIV);
    $display("SCKs per half-frame: %0d (64 SCK per full frame)", SCKS_PER_FRAME);
    $display("================================================================\n");

    // Initialize
    rst_ni = 1'b0;
    test_num = 0;
    check_enable = 1'b0;

    // Reset
    repeat (20) @(posedge clk_i);
    rst_ni = 1'b1;
    $display("[%0t] Reset released\n", $time);

    // Test 0: First pattern
    $display("[%0t] Starting Test 0: L=0x%06h, R=0x%06h", $time, TEST_LEFT_1, TEST_RIGHT_1);
    test_num = 0;
    check_enable = 1'b1;  // Enable checking
    wait (ready_o);
    @(posedge clk_i);
    check_enable = 1'b0;  // Disable checking during transition
    $display("[PASS] Test 0 completed\n");
    repeat (10) @(posedge clk_i);

    // Test 1: Second pattern
    test_num = 1;
    $display("\n[%0t] Starting Test 1: L=0x%06h, R=0x%06h", $time, TEST_LEFT_2, TEST_RIGHT_2);
    // Wait for TWO ready_o pulses, check only on the second one
    wait (!ready_o); @(posedge clk_i);
    wait (ready_o);  // First ready (skip - has old R)
    @(posedge clk_i);
    wait (!ready_o);
    check_enable = 1'b1;  // Enable checking BEFORE ready_o goes high
    @(posedge clk_i);
    wait (ready_o);  // Second ready (check - has new L and R)
    @(posedge clk_i);
    check_enable = 1'b0;  // Disable checking during transition
    $display("[PASS] Test 1 completed\n");
    repeat (10) @(posedge clk_i);

    // Test 2: Third pattern
    test_num = 2;
    $display("\n[%0t] Starting Test 2: L=0x%06h, R=0x%06h", $time, TEST_LEFT_3, TEST_RIGHT_3);
    // Wait for TWO ready_o pulses, check only on the second one
    wait (!ready_o); @(posedge clk_i);
    wait (ready_o);  // First ready (skip - has old R)
    @(posedge clk_i);
    wait (!ready_o);
    check_enable = 1'b1;  // Enable checking BEFORE ready_o goes high
    @(posedge clk_i);
    wait (ready_o);  // Second ready (check - has new L and R)
    @(posedge clk_i);
    check_enable = 1'b0;  // Disable checking
    $display("[PASS] Test 2 completed\n");
    repeat (10) @(posedge clk_i);

    // Final report
    $display("\n================================================================");
    $display("Test Summary");
    $display("================================================================");
    $display("Total ready_o pulses: %0d", ready_count);
    $display("Total errors: %0d", error_count);

    if (error_count == 0 && ready_count >= 3) begin
      $display("\n  ████████╗███████╗███████╗████████╗    ██████╗  █████╗ ███████╗███████╗");
      $display("  ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝    ██╔══██╗██╔══██╗██╔════╝██╔════╝");
      $display("     ██║   █████╗  ███████╗   ██║       ██████╔╝███████║███████╗███████╗");
      $display("     ██║   ██╔══╝  ╚════██║   ██║       ██╔═══╝ ██╔══██║╚════██║╚════██║");
      $display("     ██║   ███████╗███████║   ██║       ██║     ██║  ██║███████║███████║");
      $display("     ╚═╝   ╚══════╝╚══════╝   ╚═╝       ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝");
      $display("\n  All tests passed successfully!");
    end else begin
      $display("\n  ████████╗███████╗███████╗████████╗    ███████╗ █████╗ ██╗██╗     ");
      $display("  ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝    ██╔════╝██╔══██╗██║██║     ");
      $display("     ██║   █████╗  ███████╗   ██║       █████╗  ███████║██║██║     ");
      $display("     ██║   ██╔══╝  ╚════██║   ██║       ██╔══╝  ██╔══██║██║██║     ");
      $display("     ██║   ███████╗███████║   ██║       ██║     ██║  ██║██║███████╗");
      $display("     ╚═╝   ╚══════╝╚══════╝   ╚═╝       ╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝");
      $display("\n  Test failed with %0d errors", error_count);
    end
    $display("================================================================\n");

    $finish;
  end

  // Timeout watchdog
  initial begin
    #100000000;  // 100ms timeout
    $error("[TIMEOUT] Simulation exceeded maximum time");
    $finish;
  end

  // VCD dump for waveform viewing
  initial begin
    $dumpfile("sim/out/i2s_integration_run/i2s_integration.vcd");
    $dumpvars(0, i2s_integration_tb);
  end

  // Debug monitors (commented out for cleaner output)
  // always @(posedge clk_i) begin
  //   if (ws_edge && rst_ni) begin
  //     $display("[%0t] WS Edge: ws_o=%b, channel=%s, loading pattern=0x%07h",
  //              $time, ws_o, ws_o == WS_POL ? "LEFT" : "RIGHT", current_pattern);
  //   end
  //   if (sck_rising && rst_ni) begin
  //     $display("[%0t] SCK Rise: bit_index=%0d, sd_i=%b", $time, bit_index, sd_i);
  //   end
  // end

endmodule
