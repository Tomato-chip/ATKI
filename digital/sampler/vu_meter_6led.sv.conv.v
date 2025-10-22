// removed package "fpga_template_pkg"
module vu_meter_6led (
	clk_i,
	rst_ni,
	buffer_ready_i,
	read_enable_i,
	ram_sample_i,
	read_ack_o,
	leds_o
);
	reg _sv2v_0;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:7:13
	parameter signed [31:0] SAMPLE_WIDTH = 16;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:8:13
	parameter signed [31:0] DECAY_SHIFT = 11;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:9:13
	parameter signed [31:0] SCALE_SHIFT = 2;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:11:13
	parameter [31:0] TH1 = 16'd100;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:12:13
	parameter [31:0] TH2 = 16'd300;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:13:13
	parameter [31:0] TH3 = 16'd900;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:14:13
	parameter [31:0] TH4 = 16'd2000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:15:13
	parameter [31:0] TH5 = 16'd4000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:16:13
	parameter [31:0] TH6 = 16'd8000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:18:13
	parameter signed [31:0] LED_DIV = 540000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:20:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:21:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:24:3
	input wire buffer_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:25:3
	input wire read_enable_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:26:3
	input wire [SAMPLE_WIDTH - 1:0] ram_sample_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:27:3
	output reg read_ack_o;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:29:3
	output reg [5:0] leds_o;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:32:3
	// removed localparam type read_state_t
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:38:3
	reg [1:0] read_state_q;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:39:3
	wire read_req;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:42:3
	wire signed [SAMPLE_WIDTH - 1:0] sample;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:43:3
	assign sample = ram_sample_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:46:3
	reg [SAMPLE_WIDTH - 1:0] mag;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:47:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:48:5
		mag = (sample[SAMPLE_WIDTH - 1] ? ~sample + 1'b1 : sample);
	end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:52:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:53:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:54:7
			read_state_q <= 2'd0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:55:7
			read_ack_o <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:57:7
			read_ack_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:59:7
			case (read_state_q)
				2'd0:
					// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:62:11
					if (buffer_ready_i) begin
						// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:63:13
						read_state_q <= 2'd1;
						// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:64:13
						read_ack_o <= 1'b1;
					end
				2'd1:
					// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:69:11
					if (!read_enable_i)
						// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:71:13
						read_state_q <= 2'd2;
					else
						// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:75:13
						read_ack_o <= 1'b1;
				2'd2:
					// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:81:11
					if (buffer_ready_i) begin
						// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:82:13
						read_state_q <= 2'd1;
						// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:83:13
						read_ack_o <= 1'b1;
					end
				default:
					// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:87:18
					read_state_q <= 2'd0;
			endcase
		end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:94:3
	reg [31:0] level_q;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:95:3
	wire sample_valid;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:96:3
	assign sample_valid = (read_state_q == 2'd1) && read_enable_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:98:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:99:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:100:7
			level_q <= 32'd0;
		else if (sample_valid && read_ack_o)
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:103:7
			level_q <= (level_q - (level_q >> DECAY_SHIFT)) + (mag >> SCALE_SHIFT);
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:109:3
	reg [$clog2(LED_DIV) - 1:0] div_q;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:110:3
	reg tick;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:111:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:112:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:113:7
			div_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:113:20
			tick <= 1'b0;
		end
		else if (div_q == (LED_DIV - 1)) begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:115:7
			div_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:115:20
			tick <= 1'b1;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:117:7
			div_q <= div_q + 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:117:30
			tick <= 1'b0;
		end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:122:3
	reg [5:0] leds_next;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:123:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:124:5
		leds_next[0] = level_q > TH1;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:125:5
		leds_next[1] = level_q > TH2;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:126:5
		leds_next[2] = level_q > TH3;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:127:5
		leds_next[3] = level_q > TH4;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:128:5
		leds_next[4] = level_q > TH5;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:129:5
		leds_next[5] = level_q > TH6;
	end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:132:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:133:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:133:25
			leds_o <= 6'b000000;
		else if (tick)
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:134:25
			leds_o <= leds_next;
	initial _sv2v_0 = 0;
endmodule
