// =============================================================================
// i2s_transmit_24.sv
// Compact I²S 24-bit word transmitter (24 bits in 32-bit slot, MSB-first)
// =============================================================================
// Transmits 24-bit PCM samples as an I²S stream with a dummy MSB (25 bits total).
// The MSB is a dummy bit for compatibility with the capture module.
// Synchronizes to clk_i domain and outputs serial data on SCK rising edges.
// Interfaces with RAM module using ready/valid handshake protocol.
// =============================================================================

module i2s_transmit_24 (
  input  logic               clk_i,
  input  logic               rst_ni,     // active-low, synchronous to clk_i
  input  logic               sck_i,      // from i2s_clock_gen (synchronous to clk_i)
  input  logic               ws_i,       // 0=Left, 1=Right

  // RAM interface (ready/valid handshake)
  input  logic signed [23:0] ram_data_i,   // Data from RAM
  input  logic               ram_valid_i,  // RAM data valid
  output logic               ram_ready_o,  // Ready to accept RAM data
  input  logic               buffer_ready_i, // Buffer ready pulse from RAM

  output logic               sd_o,         // I²S serial data output (MSB-first)
  output logic               ws_o,         // WS output synchronized with transmitted data

  // Debug outputs
  output logic               debug_state_transmitting,
  output logic               debug_request_sample
);

  // Edge detection for SCK and WS (synchronized with clk 27 MHz)
  logic sck_d, ws_d;
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      sck_d <= 1'b0;
      ws_d  <= 1'b0;
    end else begin
      sck_d <= sck_i;
      ws_d  <= ws_i;
    end
  end
  wire sck_rise = ~sck_d & sck_i;
  wire ws_edge = (ws_d != ws_i);

  // 25-bit shift register + counter 0..24
  logic [24:0] shift25_q;
  logic [5:0]  cnt_q;           // counter to 25

  // Sample register - single mono channel, used for both L and R
  logic signed [23:0] sample_reg;

  // State machine for buffer management
  typedef enum logic [1:0] {
    IDLE,           // Waiting for buffer_ready pulse
    TRANSMITTING    // Actively reading from RAM and transmitting
  } state_t;

  state_t state_q;
  logic request_sample;  // Pulse to request sample from RAM
  logic sample_consumed; // Flag: we've used the current sample

  // RAM handshake: ready when we're in transmitting state AND have consumed previous sample
  assign ram_ready_o = (state_q == TRANSMITTING) && sample_consumed;

  // Debug outputs
  assign debug_state_transmitting = (state_q == TRANSMITTING);
  assign debug_request_sample = request_sample;

  // WS output - pass through the input WS
  assign ws_o = ws_i;

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      shift25_q       <= '0;
      cnt_q           <= 6'd0;
      sample_reg      <= 24'h0;
      sd_o            <= 1'b0;
      state_q         <= IDLE;
      request_sample  <= 1'b0;
      sample_consumed <= 1'b0;
    end else begin

      // Default: clear request pulse
      request_sample <= 1'b0;

      // State transitions
      case (state_q)
        IDLE: begin
          // Wait for buffer ready signal from RAM
          if (buffer_ready_i) begin
            state_q         <= TRANSMITTING;
            sample_consumed <= 1'b1;  // Ready to accept first sample
          end
        end

        TRANSMITTING: begin
          // Continue transmitting until RAM signals no more valid data
          if (!ram_valid_i && ws_edge) begin
            // RAM has no more data and we're at a frame boundary
            state_q         <= IDLE;
            sample_consumed <= 1'b0;
          end
        end
      endcase

      // Load sample from RAM when handshake completes
      if (ram_valid_i && ram_ready_o) begin
        sample_reg      <= ram_data_i;
        sample_consumed <= 1'b0;  // Mark as not consumed yet
      end

      // New half-frame: reset counter and load sample data
      if (ws_edge) begin
          cnt_q     <= 6'd0;
          sd_o      <= 1'b0;  // Clear output at WS edge

          // Load sample into shift register
          shift25_q <= {1'b0, sample_reg};

          // Mark sample as consumed, ready for next one
          if (state_q == TRANSMITTING) begin
            sample_consumed <= 1'b1;
          end
      end else if (sck_rise) begin
        // Shift out data on SCK rising edges
        if (cnt_q < 6'd25) begin
          // Shift out MSB on each SCK rising edge
          sd_o      <= shift25_q[24];           // Output MSB
          shift25_q <= {shift25_q[23:0], 1'b0}; // Shift left
          cnt_q     <= cnt_q + 6'd1;
        end else begin
          // After 25 bits, output 0 for remaining slot time (32-25 = 7 SCK cycles)
          sd_o <= 1'b0;
        end
      end
    end
  end

endmodule
