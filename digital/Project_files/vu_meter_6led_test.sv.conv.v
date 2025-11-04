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
	parameter signed [31:0] DECAY_SHIFT = 14;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:10:13
	parameter signed [31:0] SCALE_SHIFT = 2;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:12:13
	parameter [31:0] TH1 = 24'd500;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:13:13
	parameter [31:0] TH2 = 24'd2000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:14:13
	parameter [31:0] TH3 = 24'd6000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:15:13
	parameter [31:0] TH4 = 24'd15000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:16:13
	parameter [31:0] TH5 = 24'd35000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:17:13
	parameter [31:0] TH6 = 24'd70000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:19:13
	parameter signed [31:0] LED_DIV = 2700000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:23:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:24:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:25:3
	input wire signed [23:0] ram_read_data_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:26:3
	input wire ram_read_valid_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:27:3
	output wire ram_read_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:28:3
	input wire ram_buffer_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:29:3
	output reg [5:0] leds_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:35:3
	wire signed [23:0] sample;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:36:3
	wire sample_valid;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:37:3
	wire ram_read_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:38:3
	reg ram_ready_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:39:3
	reg processing_delay_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:45:7
	assign ram_read_ready_o = ram_ready_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:46:7
	assign ram_read_accepted = ram_read_valid_i && ram_read_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:50:7
	assign sample = ram_read_data_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:51:7
	assign sample_valid = ram_read_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:62:3
	reg [23:0] mag;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:63:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:63:15
		mag = (sample[23] ? ~sample + 1'b1 : sample);
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:66:3
	reg [31:0] level_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:70:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:71:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:72:7
			level_q <= 32'd0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:73:7
			ram_ready_q <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:74:7
			processing_delay_q <= 1'b0;
		end
		else
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:76:7
			if (sample_valid) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:78:9
				level_q <= (level_q - (level_q >> DECAY_SHIFT)) + (mag >> SCALE_SHIFT);
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:80:9
				ram_ready_q <= 1'b0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:81:9
				processing_delay_q <= 1'b1;
			end
			else if (processing_delay_q) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:84:9
				ram_ready_q <= 1'b0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:85:9
				processing_delay_q <= 1'b0;
			end
			else
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:88:9
				ram_ready_q <= 1'b1;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:94:3
	reg [$clog2(LED_DIV) - 1:0] div_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:95:3
	reg tick;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:96:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:97:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:98:7
			div_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:98:20
			tick <= 1'b0;
		end
		else if (div_q == (LED_DIV - 1)) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:100:7
			div_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:100:20
			tick <= 1'b1;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:102:7
			div_q <= div_q + 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:102:30
			tick <= 1'b0;
		end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:107:3
	reg [5:0] leds_next;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:108:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:109:5
		leds_next[0] = level_q > TH1;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:110:5
		leds_next[1] = level_q > TH2;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:111:5
		leds_next[2] = level_q > TH3;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:112:5
		leds_next[3] = level_q > TH4;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:113:5
		leds_next[4] = level_q > TH5;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:114:5
		leds_next[5] = level_q > TH6;
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:117:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:118:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:118:25
			leds_o <= 6'b000000;
		else if (tick)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:119:25
			leds_o <= leds_next;
	initial _sv2v_0 = 0;
endmodule
