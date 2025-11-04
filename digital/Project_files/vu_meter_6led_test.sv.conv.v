// removed package "fpga_template_pkg"
module vu_meter_6led (
	clk_i,
	rst_ni,
	ram_read_data_i,
	ram_read_valid_i,
	ram_read_ready_o,
	ram_buffer_ready_i,
	leds_o
);
	reg _sv2v_0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:8:13
	parameter [0:0] SELECT_LEFT = 1'b1;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:9:13
	parameter signed [31:0] DECAY_SHIFT = 11;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:10:13
	parameter signed [31:0] SCALE_SHIFT = 10;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:12:13
	parameter [31:0] TH1 = 24'd1000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:13:13
	parameter [31:0] TH2 = 24'd3000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:14:13
	parameter [31:0] TH3 = 24'd9000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:15:13
	parameter [31:0] TH4 = 24'd20000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:16:13
	parameter [31:0] TH5 = 24'd40000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:17:13
	parameter [31:0] TH6 = 24'd80000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:19:13
	parameter signed [31:0] LED_DIV = 540000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:23:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:24:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:32:3
	input wire signed [23:0] ram_read_data_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:33:3
	input wire ram_read_valid_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:34:3
	output wire ram_read_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:35:3
	input wire ram_buffer_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:37:3
	output reg [5:0] leds_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:43:3
	wire signed [23:0] sample;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:44:3
	wire sample_valid;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:45:3
	wire ram_read_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:46:3
	reg ram_ready_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:47:3
	reg processing_delay_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:53:7
	assign ram_read_ready_o = ram_ready_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:54:7
	assign ram_read_accepted = ram_read_valid_i && ram_read_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:58:7
	assign sample = ram_read_data_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:59:7
	assign sample_valid = ram_read_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:70:3
	reg [23:0] mag;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:71:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:71:15
		mag = (sample[23] ? ~sample + 1'b1 : sample);
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:74:3
	reg [31:0] level_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:78:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:79:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:80:7
			level_q <= 32'd0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:81:7
			ram_ready_q <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:82:7
			processing_delay_q <= 1'b0;
		end
		else
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:84:7
			if (sample_valid) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:86:9
				level_q <= (level_q - (level_q >> DECAY_SHIFT)) + (mag >> SCALE_SHIFT);
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:88:9
				ram_ready_q <= 1'b0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:89:9
				processing_delay_q <= 1'b1;
			end
			else if (processing_delay_q) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:92:9
				ram_ready_q <= 1'b0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:93:9
				processing_delay_q <= 1'b0;
			end
			else
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:96:9
				ram_ready_q <= 1'b1;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:102:3
	reg [$clog2(LED_DIV) - 1:0] div_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:103:3
	reg tick;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:104:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:105:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:106:7
			div_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:106:20
			tick <= 1'b0;
		end
		else if (div_q == (LED_DIV - 1)) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:108:7
			div_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:108:20
			tick <= 1'b1;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:110:7
			div_q <= div_q + 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:110:30
			tick <= 1'b0;
		end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:115:3
	reg [5:0] leds_next;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:116:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:117:5
		leds_next[0] = level_q > TH1;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:118:5
		leds_next[1] = level_q > TH2;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:119:5
		leds_next[2] = level_q > TH3;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:120:5
		leds_next[3] = level_q > TH4;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:121:5
		leds_next[4] = level_q > TH5;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:122:5
		leds_next[5] = level_q > TH6;
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:125:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:126:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:126:25
			leds_o <= 6'b000000;
		else if (tick)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:127:25
			leds_o <= leds_next;
	initial _sv2v_0 = 0;
endmodule
