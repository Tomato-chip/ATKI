// =============================================================================
// i2s_capture_24.sv
// Compact I²S 24-bit word capture (24 bits in 32-bit slot, MSB-first)
// =============================================================================
// Captures 25-bit samples from an I²S stream and uses only the first 24 bits. 
// The MSB is a dummy bit, and is not used.
// It samples 25 for simplisity.
// Synchronizes I²S signals into clk_i domain.
// =============================================================================

module i2s_capture_24 (
  input  logic        clk_i,
  input  logic        rst_ni,     // aktiv-lav, synkron til clk_i
  input  logic        sck_i,      // fra i2s_clock_gen (synkron til clk_i)
  input  logic        ws_i,       // 0=Left, 1=Right
  input  logic        sd_i,       // I²S data (MSB-first, gyldig på SCK rising)

  output logic signed [23:0] left_o,   // Explicitly signed for PCM audio
  output logic signed [23:0] right_o,
  output logic        ready_o     // 1 clk_i-cycle når L+R begge er opdateret
);

  // kantdetektion fordi den er synkroniseret med clk 27 MHz.
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
  

  // 25-bit shifter + tæller 0..25
  logic [24:0] shift25_q;
  logic [5:0]  cnt_q;           // tæller til 25
  logic        left_done_q, right_done_q;
  logic        channel_q;       // Capture which channel we're in (0=left, 1=right)

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      shift25_q    <= '0;
      cnt_q        <= 6'd0;
      left_o       <= 24'h0;
      right_o      <= 24'h0;
      left_done_q  <= 1'b0;
      right_done_q <= 1'b0;
      ready_o      <= 1'b0;
      channel_q    <= 1'b0;
    end else begin
      ready_o <= 1'b0;

      // ny halvramme: nulstil tæller og shifter
      if (ws_edge) begin
        cnt_q     <= 6'd0;
        shift25_q <= '0;
        channel_q <= ws_i;  // Capture channel at WS edge
      end else if (sck_rise) begin
        // Shift in new bit and increment counter
        // Sample sd_i directly when SCK rises (both are synchronous to clk_i)
        if (cnt_q < 6'd25) begin
          shift25_q <= {shift25_q[23:0], sd_i}; // LSB-ind, sample current sd_i value
          cnt_q     <= cnt_q + 6'd1;
        end
        // resten af slotten (32-25 = 7 SCK) ignoreres automatisk
      end

      // når 25. bit er skubbet ind, er shift25_q[24] = dummy,
      // og shift25_q[23:0] = 24 gyldige bits (MSB..LSB)
      // Check AFTER counter reaches 25 (separate from increment logic)
      // left_done_q bruges til i begge if, for af ready_o igge togler hver gang der er ws_edge
      // cnt_q = 25 og fx channel_q = 0 er sande indtil næste ws_edge, og derfor vil left_done_q = 1 til lige efter at den er nulstillet i ready_o
      if (cnt_q == 6'd25) begin
        if (channel_q == 1'b0 && !left_done_q) begin  // Use captured channel, not current ws_i
          left_o      <= shift25_q[23:0];
          left_done_q <= 1'b1;
        end else if (channel_q == 1'b1 && left_done_q) begin
          right_o      <= shift25_q[23:0];
          right_done_q <= 1'b1;
        end
      end
      if (left_done_q && right_done_q) begin
        ready_o      <= 1'b1;   // én clk_i-cyklus
        left_done_q  <= 1'b0;
        right_done_q <= 1'b0;
      end
    end
  end
endmodule



      // if (cnt_q == 6'd25 ) begin
      //   if (channel_q == 1'b0) begin  // Use captured channel, not current ws_i
      //     left_o      <= shift25_q[23:0];
      //     left_done_q <= 1'b1;
      //   end else begin
      //     right_o      <= shift25_q[23:0];
      //     right_done_q <= 1'b1;
      //   end
      // end

      // if (left_done_q && right_done_q) begin
      //   ready_o      <= 1'b1;   // én clk_i-cyklus
      //   left_done_q  <= 1'b0;
      //   right_done_q <= 1'b0;
      // end
