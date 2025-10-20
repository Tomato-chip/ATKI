// ============================================================================
// I2S Clock Generator (Verilator-compatible)
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
  parameter int unsigned SCKS_PER_FRAME  = 64,          // SCKs per full frame (L+R)
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
  // Parameter Checks
  // ============================================================================
  initial begin
    if (SCK_DIV < 2) begin
      $fatal(1, "SCK_DIV must be >= 2");
    end
    if (SCKS_PER_FRAME < 2) begin
      $fatal(1, "SCKS_PER_FRAME must be >= 2");
    end
  end

endmodule
