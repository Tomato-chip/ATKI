// i2s_sd_edge_meter_led6.sv
// Tæl SD-flanker i de første 24 bit af en valgt kanal-halvramme.
// Forventet clocking: alt kører på din systemclk; sck/ws er synkede til clk_i.
// sample på SCK rising; SD ændres på falling i I2S.
module i2s_sd_edge_meter_led6 #(
  parameter bit USE_LEFT = 1'b0  // 1: mål i venstre halvramme (WS=pol), 0: højre
) (
  input  logic clk_i,
  input  logic rst_ni,
  input  logic sck_i,     // sck synkroniseret til clk_i
  input  logic ws_i,      // ws synkroniseret til clk_i
  input  logic sd_i,      // sd synkroniseret til clk_i
  output logic [5:0] level6_o
);
  // kantdetektering på SCK
  logic sck_q;
  always_ff @(posedge clk_i) begin
    if (!rst_ni) sck_q <= 1'b0; else sck_q <= sck_i;
  end
  wire sck_rise =  sck_i & ~sck_q;
  wire sck_fall = ~sck_i &  sck_q;

  // track halvramme og 24-bit vindue
  logic ws_q;  always_ff @(posedge clk_i) if (!rst_ni) ws_q <= 0; else ws_q <= ws_i;
  wire ws_edge = ws_i ^ ws_q;

  // vi starter “bit_count” én SCK efter WS-flanken (I2S MSB delay)
  logic       measure_en;
  logic [5:0] bit_count;
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      measure_en <= 1'b0;
      bit_count  <= '0;
    end else begin
      if (ws_edge) begin
        measure_en <= 1'b0;       // nulstil ved halvrammeskift
        bit_count  <= '0;
      end
      if (sck_rise) begin
        // start målevinduet én rising efter ws_edge (I2S)
        if (!measure_en) measure_en <= 1'b1;
        else if (bit_count != 6'd63) bit_count <= bit_count + 6'd1;
      end
      // stop efter 24 rising edges (24 data-bit)
      if (bit_count == 6'd24) measure_en <= 1'b0;
    end
  end

  // kantdetektering på SD (kun når measure_en er aktiv og vi er i ønsket halvramme)
  logic sd_q; always_ff @(posedge clk_i) if (!rst_ni) sd_q <= 0; else sd_q <= sd_i;
  wire  sd_toggle = sd_i ^ sd_q;
  wire  half_ok   = USE_LEFT ? (ws_i == 1'b? /* brug din WS-polaritet */) 
                             : (ws_i != 1'b? /* samme her */);
  // Hvis du ikke kender WS-pol: prøv begge instanser (USE_LEFT=1 og =0)

  // 6-bit “tæller per halvramme” + decay, så LEDs ikke flimrer
  logic [5:0] accum_q;
  always_ff @(posedge clk_i) begin
    if (!rst_ni) accum_q <= '0;
    else begin
      // decay lidt hver halvramme
      if (ws_edge) accum_q <= (accum_q - (accum_q >> 2)); // ~1/4 ned pr. halvramme
      // læg til ved SD-aktivitet i vores 24-bit vindue
      if (measure_en && sd_toggle && half_ok) begin
        if (accum_q != 6'h3F) accum_q <= accum_q + 6'd1;
      end
    end
  end

  assign level6_o = accum_q;
endmodule
