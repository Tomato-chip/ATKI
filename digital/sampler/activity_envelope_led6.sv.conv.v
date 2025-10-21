// removed package "fpga_template_pkg"
module activity_envelope_led6 (
	clk_i,
	rst_ni,
	sample_valid_i,
	sample_i,
	level6_o
);
	reg _sv2v_0;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:3:13
	parameter [31:0] IN_SHIFT = 8;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:4:13
	parameter [31:0] DECAY_SHIFT = 10;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:5:13
	parameter [31:0] SCALE_SHIFT = 18;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:6:13
	parameter [31:0] SMOOTH_SHIFT = 3;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:8:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:9:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:10:3
	input wire sample_valid_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:11:3
	input wire signed [23:0] sample_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:12:3
	output wire [5:0] level6_o;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:16:3
	wire [23:0] abs_sample = (sample_i[23] ? ~sample_i + 24'd1 : sample_i);
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:17:3
	wire [23:0] abs_scaled = abs_sample >> IN_SHIFT;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:20:3
	reg [31:0] acc_q;
	reg [31:0] acc_d;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:21:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:22:5
		acc_d = acc_q;
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:23:5
		if (sample_valid_i)
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:24:7
			acc_d = (acc_q - (acc_q >> DECAY_SHIFT)) + {{8 {1'b0}}, abs_scaled};
	end
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:27:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:28:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:29:7
			acc_q <= 1'sb0;
		else
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:31:7
			acc_q <= acc_d;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:35:3
	wire [31:0] lvl_wide = acc_q >> SCALE_SHIFT;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:36:3
	wire [5:0] lvl_raw = (|lvl_wide[31:6] ? 6'h3f : lvl_wide[5:0]);
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:39:3
	reg [5:0] level6_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:40:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:41:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:42:7
			level6_q <= 6'd0;
		else if (sample_valid_i)
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:44:7
			level6_q <= (level6_q - (level6_q >> SMOOTH_SHIFT)) + (lvl_raw >> SMOOTH_SHIFT);
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/activity_envelope_led6.sv:47:3
	assign level6_o = level6_q;
	initial _sv2v_0 = 0;
endmodule
