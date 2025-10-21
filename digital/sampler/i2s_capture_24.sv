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

  output logic [23:0] left_o,
  output logic [23:0] right_o,
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
  wire ws_edge  = ws_d ^ ws_i;

  // 25-bit shifter + tæller 0..25
  logic [24:0] shift25_q;
  logic [5:0]  cnt_q;           // tæller til 25
  logic        left_done_q, right_done_q;

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      shift25_q    <= '0;
      cnt_q        <= 6'd0;
      left_o       <= 24'h0;
      right_o      <= 24'h0;
      left_done_q  <= 1'b0;
      right_done_q <= 1'b0;
      ready_o      <= 1'b0;
    end else begin
      ready_o <= 1'b0;

      // ny halvramme: nulstil tæller og shifter
      if (ws_edge) begin
        cnt_q     <= 6'd0;
        shift25_q <= '0;
      end else if (sck_rise) begin
        if (cnt_q < 6'd25) begin
          shift25_q <= {shift25_q[23:0], sd_i}; // LSB-ind
          cnt_q     <= cnt_q + 6'd1;

          // når 25. bit er skubbet ind, er shift25_q[24] = dummy,
          // og shift25_q[23:0] = 24 gyldige bits (MSB..LSB)
          if (cnt_q == 6'd24) begin
            if (ws_i == 1'b0) begin
              left_o      <= shift25_q[23:0];
              left_done_q <= 1'b1;
            end else begin
              right_o      <= shift25_q[23:0];
              right_done_q <= 1'b1;
            end
          end
        end
        // resten af slotten (32-25 = 7 SCK) ignoreres automatisk
      end

      if (left_done_q && right_done_q) begin
        ready_o      <= 1'b1;   // én clk_i-cyklus
        left_done_q  <= 1'b0;
        right_done_q <= 1'b0;
      end
    end
  end
endmodule

