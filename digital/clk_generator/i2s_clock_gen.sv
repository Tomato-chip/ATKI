// ============================================================================
// I2S Clock Generator
// ============================================================================
// Generates SCK (Serial Clock) and WS (Word Select / LRCLK) for I2S audio
// interfaces. Provides precise clock division with configurable parameters.
//
// Default Configuration:
//   - System Clock: 27 MHz
//   - SCK: 3.375 MHz (27 MHz / 8)
//   - WS (Frame Rate): ~52.734 kHz (3.375 MHz / 64)
//   - Frame: 64 SCK cycles (32 bits per channel, 2 channels)
// ============================================================================

module i2s_clock_gen #(
  parameter int unsigned SYS_CLK_HZ      = 27_000_000,  // System clock frequency
  parameter int unsigned SCK_DIV         = 8,           // SCK divider (must be >= 2)
  parameter int unsigned SCKS_PER_FRAME  = 32,          // SCKs per full frame (L+R)
  parameter bit          WS_POL          = 1'b0,        // WS polarity: 0=left-low, 1=left-high
  parameter bit          FRAME_PULSE_EN  = 1'b1         // Enable frame_start_o output
) (
  input  logic clk_i,           // System clock (27 MHz)
  input  logic rst_ni,          // Active-low synchronous reset

  output logic sck_o,           // Serial Clock (bit clock)
  output logic ws_o,            // Word Select (LRCLK)
  output logic frame_start_o    // One-cycle pulse at left channel start
);

  // Calculated frequencies (for documentation/assertions)
  localparam int unsigned SCK_HZ = SYS_CLK_HZ / SCK_DIV;
  localparam int unsigned WS_HZ  = SCK_HZ / SCKS_PER_FRAME;

  // Counter widths
  localparam int unsigned SCK_CTR_WIDTH = $clog2(SCK_DIV);
  localparam int unsigned WS_CTR_WIDTH  = $clog2(SCKS_PER_FRAME);

  // SCK generation - 50% duty cycle
  localparam int unsigned SCK_HALF_HIGH = SCK_DIV / 2;
  localparam int unsigned SCK_HALF_LOW  = SCK_DIV - SCK_HALF_HIGH;

  // ============================================================================
  // SCK Generation
  // ============================================================================
  logic [SCK_CTR_WIDTH-1:0] sck_ctr_q;
  logic                     sck_q;
  logic                     sck_tick;  // Pulses on SCK toggles

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      sck_ctr_q <= '0;
      sck_q     <= 1'b0;
    end else begin
      if (sck_q) begin
        // SCK is currently high
        if (sck_ctr_q == (SCK_HALF_HIGH - 1)) begin
          sck_ctr_q <= '0;
          sck_q     <= 1'b0;  // Falling edge
        end else begin
          sck_ctr_q <= sck_ctr_q + 1'b1;
        end
      end else begin
        // SCK is currently low
        if (sck_ctr_q == (SCK_HALF_LOW - 1)) begin
          sck_ctr_q <= '0;
          sck_q     <= 1'b1;  // Rising edge
        end else begin
          sck_ctr_q <= sck_ctr_q + 1'b1;
        end
      end
    end
  end

  // Detect SCK edges
  logic sck_falling_edge;
  logic sck_prev_q;

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      sck_prev_q <= 1'b0;
    end else begin
      sck_prev_q <= sck_q;
    end
  end

  assign sck_falling_edge = sck_prev_q & ~sck_q;

  // ============================================================================
  // WS (Word Select) Generation
  // ============================================================================
  logic [WS_CTR_WIDTH-1:0] ws_ctr_q;
  logic                    ws_q;
  logic                    frame_start_q;

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      ws_ctr_q      <= '0;
      ws_q          <= WS_POL;  // Start with left channel
      frame_start_q <= 1'b0;
    end else begin
      frame_start_q <= 1'b0;  // Default: no pulse

      if (sck_falling_edge) begin
        if (ws_ctr_q == (SCKS_PER_FRAME - 1)) begin
          ws_ctr_q <= '0;
          ws_q     <= ~ws_q;  // Toggle at frame boundary

          // Pulse on transition to left channel
          if (ws_q == ~WS_POL) begin
            frame_start_q <= 1'b1;
          end
        end else begin
          ws_ctr_q <= ws_ctr_q + 1'b1;
        end
      end
    end
  end

  // ============================================================================
  // Output Assignments
  // ============================================================================
  assign sck_o = sck_q;
  assign ws_o  = ws_q;
  assign frame_start_o = FRAME_PULSE_EN ? frame_start_q : 1'b0;

  // ============================================================================
  // Assertions (Acceptance Checks)
  // ============================================================================

  // Check that SCK divider is valid
  initial begin
    assert (SCK_DIV >= 2) else
      $fatal(1, "SCK_DIV must be >= 2");
    assert (SCKS_PER_FRAME >= 2) else
      $fatal(1, "SCKS_PER_FRAME must be >= 2");
  end

  `ifndef SYNTHESIS

  // Track SCK period in system clock cycles
  int unsigned sck_period_cycles;
  int unsigned sck_last_toggle_time;

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      sck_last_toggle_time <= 0;
    end else if (sck_q != sck_prev_q) begin
      sck_period_cycles = $time / 1000 - sck_last_toggle_time;  // Convert from ps to cycles
      sck_last_toggle_time = $time / 1000;
    end
  end

  // SVA: SCK period matches SCK_DIV (half-period check)
  property sck_half_period_check;
    @(posedge clk_i) disable iff (!rst_ni)
    (sck_q && !$past(sck_q)) |->
      ($past(sck_ctr_q, 1) == (SCK_HALF_LOW - 1));
  endproperty

  property sck_low_period_check;
    @(posedge clk_i) disable iff (!rst_ni)
    (!sck_q && $past(sck_q)) |->
      ($past(sck_ctr_q, 1) == (SCK_HALF_HIGH - 1));
  endproperty

  // SVA: WS transitions only on SCK falling edges
  property ws_change_on_sck_fall;
    @(posedge clk_i) disable iff (!rst_ni)
    (ws_q != $past(ws_q)) |-> sck_falling_edge;
  endproperty

  // SVA: WS period check (toggles every SCKS_PER_FRAME SCK edges)
  property ws_toggle_period;
    @(posedge clk_i) disable iff (!rst_ni)
    (sck_falling_edge && (ws_ctr_q == (SCKS_PER_FRAME - 1))) |->
      ##1 (ws_q != $past(ws_q, 1));
  endproperty

  // SVA: Frame start pulse only when WS transitions to left channel
  property frame_start_check;
    @(posedge clk_i) disable iff (!rst_ni)
    frame_start_q |-> ((ws_q == WS_POL) && $past(ws_q) == ~WS_POL);
  endproperty

  assert_sck_half_period:   assert property (sck_half_period_check)
    else $error("SCK half-period violation");

  assert_sck_low_period:    assert property (sck_low_period_check)
    else $error("SCK low period violation");

  assert_ws_on_sck_fall:    assert property (ws_change_on_sck_fall)
    else $error("WS changed when SCK was not falling");

  assert_ws_toggle_period:  assert property (ws_toggle_period)
    else $error("WS toggle period incorrect");

  assert_frame_start:       assert property (frame_start_check)
    else $error("Frame start pulse at wrong time");

  `endif // SYNTHESIS

endmodule
