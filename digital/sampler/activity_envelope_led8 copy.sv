// activity_envelope_led8.sv
module activity_envelope_led8 #(
  // Skaler 24-bit input ned, så akkumuleringen ikke overflyder (typisk 8–12)
  parameter int unsigned IN_SHIFT      = 8,
  // Styrer decay: større = langsommere (≈ 2^DECAY_SHIFT samples)
  parameter int unsigned DECAY_SHIFT   = 10,
  // Skalerer den interne 32-bit accumulator ned til 8 bit (vælg så du sjældent klipper)
  parameter int unsigned SCALE_SHIFT   = 12,
  // Ekstra udjævning af det færdige 8-bit niveau (0 = ingen, 3–6 er fint)
  parameter int unsigned SMOOTH_SHIFT  = 3
) (
  input  logic               clk_i,
  input  logic               rst_ni,          // aktiv lav, synkron
  input  logic               sample_valid_i,  // 1 clk-puls pr. nyt sample (fx 48 kHz)
  input  logic signed [23:0] sample_i,        // signed I²S sample
  output logic        [7:0]  level8_o         // 0..255 til LED-bar, PWM, osv.
);

  // |x|
  wire [23:0] abs_sample = sample_i[23] ? (~sample_i + 24'd1) : sample_i;
  wire [23:0] abs_scaled = abs_sample >> IN_SHIFT;

  // 32-bit leaky accumulator: acc = acc - acc/2^DECAY_SHIFT + abs(x)
  logic [31:0] acc_q, acc_d;
  always_comb begin
    acc_d = acc_q;
    if (sample_valid_i) begin
      acc_d = acc_q - (acc_q >> DECAY_SHIFT) + {{8{1'b0}}, abs_scaled};
    end
  end

  // Registrér accumulator
  always_ff @(posedge clk_i) begin
    if (!rst_ni) acc_q <= '0;
    else         acc_q <= acc_d;
  end

  // Komprimer til 8 bit med shift + saturering
  wire [31:0] lvl_wide = acc_q >> SCALE_SHIFT; // grov skala
  wire [7:0]  lvl_raw  = (|lvl_wide[31:8]) ? 8'hFF : lvl_wide[7:0];

  // Lidt udjævning på selve 8-bit værdien (slår “spikes” ned, mindre flimmer)
  // level8 <= level8 - level8/2^SMOOTH_SHIFT + lvl_raw/2^SMOOTH_SHIFT
  logic [7:0] level8_q;
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      level8_q <= 8'd0;
    end else if (sample_valid_i) begin
      level8_q <= level8_q - (level8_q >> SMOOTH_SHIFT) + (lvl_raw >> SMOOTH_SHIFT);
    end
  end

  assign level8_o = level8_q;

endmodule
