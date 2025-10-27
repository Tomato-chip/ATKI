// removed package "fpga_template_pkg"
module vu_meter_6led (
	clk_i,
	rst_ni,
	sample_valid_i,
	left_sample_i,
	right_sample_i,
	ram_read_data_i,
	ram_read_valid_i,
	ram_read_ready_o,
	ram_buffer_ready_i,
	leds_o
);
	reg _sv2v_0;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:8:13
	parameter [0:0] SELECT_LEFT = 1'b1;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:9:13
	parameter signed [31:0] DECAY_SHIFT = 11;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:10:13
	parameter signed [31:0] SCALE_SHIFT = 12;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:12:13
	parameter [31:0] TH1 = 24'd1000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:13:13
	parameter [31:0] TH2 = 24'd3000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:14:13
	parameter [31:0] TH3 = 24'd9000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:15:13
	parameter [31:0] TH4 = 24'd20000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:16:13
	parameter [31:0] TH5 = 24'd40000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:17:13
	parameter [31:0] TH6 = 24'd80000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:19:13
	parameter signed [31:0] LED_DIV = 540000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:21:13
	parameter [0:0] USE_RAM_IF = 1'b1;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:23:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:24:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:27:3
	input wire sample_valid_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:28:3
	input wire signed [23:0] left_sample_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:29:3
	input wire signed [23:0] right_sample_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:32:3
	input wire signed [23:0] ram_read_data_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:33:3
	input wire ram_read_valid_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:34:3
	output wire ram_read_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:35:3
	input wire ram_buffer_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:37:3
	output reg [5:0] leds_o;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:43:3
	wire signed [23:0] sample;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:44:3
	wire sample_valid;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:45:3
	wire ram_read_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:46:3
	reg ram_ready_q;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:48:3
	generate
		if (USE_RAM_IF) begin : gen_ram_mode
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:52:7
			assign ram_read_ready_o = ram_ready_q;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:53:7
			assign ram_read_accepted = ram_read_valid_i && ram_read_ready_o;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:57:7
			assign sample = ram_read_data_i;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:58:7
			assign sample_valid = ram_read_accepted;
		end
		else begin : gen_direct_mode
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:62:7
			assign ram_read_ready_o = 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:63:7
			assign sample = (SELECT_LEFT ? left_sample_i : right_sample_i);
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:64:7
			assign sample_valid = sample_valid_i;
		end
	endgenerate
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:69:3
	reg [23:0] mag;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:70:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:70:15
		mag = (sample[23] ? ~sample + 1'b1 : sample);
	end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:73:3
	reg [31:0] level_q;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:77:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:78:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:79:7
			level_q <= 32'd0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:80:7
			ram_ready_q <= 1'b1;
		end
		else
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:82:7
			if (sample_valid) begin
				// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:84:9
				level_q <= (level_q - (level_q >> DECAY_SHIFT)) + (mag >> SCALE_SHIFT);
				// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:86:9
				ram_ready_q <= 1'b0;
			end
			else
				// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:88:9
				ram_ready_q <= 1'b1;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:94:3
	reg [$clog2(LED_DIV) - 1:0] div_q;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:95:3
	reg tick;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:96:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:97:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:98:7
			div_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:98:20
			tick <= 1'b0;
		end
		else if (div_q == (LED_DIV - 1)) begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:100:7
			div_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:100:20
			tick <= 1'b1;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:102:7
			div_q <= div_q + 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:102:30
			tick <= 1'b0;
		end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:107:3
	reg [5:0] leds_next;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:108:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:109:5
		leds_next[0] = level_q > TH1;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:110:5
		leds_next[1] = level_q > TH2;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:111:5
		leds_next[2] = level_q > TH3;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:112:5
		leds_next[3] = level_q > TH4;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:113:5
		leds_next[4] = level_q > TH5;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:114:5
		leds_next[5] = level_q > TH6;
	end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:117:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:118:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:118:25
			leds_o <= 6'b000000;
		else if (tick)
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:119:25
			leds_o <= leds_next;
	initial _sv2v_0 = 0;
endmodule
