// activity_envelope_led6.sv
module activity_envelope_led6 #(
  parameter int unsigned IN_SHIFT      = 8,
  parameter int unsigned DECAY_SHIFT   = 10,
  parameter int unsigned SCALE_SHIFT   = 18,  // lidt mere for at komprimere til 6 bit
  parameter int unsigned SMOOTH_SHIFT  = 3
) (
  input  logic               clk_i,
  input  logic               rst_ni,
  input  logic               sample_valid_i,
  input  logic signed [23:0] sample_i,
  output logic        [5:0]  level6_o
);

  // |x|
  wire [23:0] abs_sample = sample_i[23] ? (~sample_i + 24'd1) : sample_i;
  wire [23:0] abs_scaled = abs_sample >> IN_SHIFT;

  // leaky integrator: acc = acc - acc/2^DECAY_SHIFT + abs(x)
  logic [31:0] acc_q, acc_d;
  always_comb begin
    acc_d = acc_q;
    if (sample_valid_i)
      acc_d = acc_q - (acc_q >> DECAY_SHIFT) + {{8{1'b0}}, abs_scaled};
  end

  always_ff @(posedge clk_i) begin
    if (!rst_ni)
      acc_q <= '0;
    else
      acc_q <= acc_d;
  end

  // komprimer til 6 bit
  wire [31:0] lvl_wide = acc_q >> SCALE_SHIFT;
  wire [5:0]  lvl_raw  = (|lvl_wide[31:6]) ? 6'h3F : lvl_wide[5:0];

  // udjævn lidt mod flimmer
  logic [5:0] level6_q;
  always_ff @(posedge clk_i) begin
    if (!rst_ni)
      level6_q <= 6'd0;
    else if (sample_valid_i)
      level6_q <= level6_q - (level6_q >> SMOOTH_SHIFT) + (lvl_raw >> SMOOTH_SHIFT);
  end

  assign level6_o = level6_q;
endmodule
