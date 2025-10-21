// removed package "fpga_template_pkg"
module i2s_clock_gen (
	clk_i,
	rst_ni,
	sck_o,
	ws_o,
	frame_start_o
);
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:15:13
	parameter [31:0] SYS_CLK_HZ = 27000000;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:16:13
	parameter [31:0] SCK_DIV = 8;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:17:13
	parameter [31:0] SCKS_PER_FRAME = 32;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:18:13
	parameter [0:0] WS_POL = 1'b0;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:19:13
	parameter [0:0] FRAME_PULSE_EN = 1'b1;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:21:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:22:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:24:3
	output wire sck_o;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:25:3
	output wire ws_o;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:26:3
	output wire frame_start_o;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:30:3
	localparam [31:0] SCK_HZ = SYS_CLK_HZ / SCK_DIV;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:31:3
	localparam [31:0] WS_HZ = SCK_HZ / SCKS_PER_FRAME;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:34:3
	localparam [31:0] SCK_CTR_WIDTH = $clog2(SCK_DIV);
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:35:3
	localparam [31:0] WS_CTR_WIDTH = $clog2(SCKS_PER_FRAME);
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:38:3
	localparam [31:0] SCK_HALF_HIGH = SCK_DIV / 2;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:39:3
	localparam [31:0] SCK_HALF_LOW = SCK_DIV - SCK_HALF_HIGH;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:44:3
	reg [SCK_CTR_WIDTH - 1:0] sck_ctr_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:45:3
	reg sck_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:46:3
	wire sck_tick;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:48:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:49:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:50:7
			sck_ctr_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:51:7
			sck_q <= 1'b0;
		end
		else
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:53:7
			if (sck_q) begin
				begin
					// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:55:9
					if (sck_ctr_q == (SCK_HALF_HIGH - 1)) begin
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:56:11
						sck_ctr_q <= 1'sb0;
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:57:11
						sck_q <= 1'b0;
					end
					else
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:59:11
						sck_ctr_q <= sck_ctr_q + 1'b1;
				end
			end
			else
				// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:63:9
				if (sck_ctr_q == (SCK_HALF_LOW - 1)) begin
					// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:64:11
					sck_ctr_q <= 1'sb0;
					// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:65:11
					sck_q <= 1'b1;
				end
				else
					// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:67:11
					sck_ctr_q <= sck_ctr_q + 1'b1;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:74:3
	wire sck_falling_edge;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:75:3
	reg sck_prev_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:77:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:78:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:79:7
			sck_prev_q <= 1'b0;
		else
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:81:7
			sck_prev_q <= sck_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:85:3
	assign sck_falling_edge = sck_prev_q & ~sck_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:90:3
	reg [WS_CTR_WIDTH - 1:0] ws_ctr_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:91:3
	reg ws_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:92:3
	reg frame_start_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:94:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:95:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:96:7
			ws_ctr_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:97:7
			ws_q <= WS_POL;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:98:7
			frame_start_q <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:100:7
			frame_start_q <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:102:7
			if (sck_falling_edge) begin
				begin
					// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:103:9
					if (ws_ctr_q == (SCKS_PER_FRAME - 1)) begin
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:104:11
						ws_ctr_q <= 1'sb0;
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:105:11
						ws_q <= ~ws_q;
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:108:11
						if (ws_q == ~WS_POL)
							// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:109:13
							frame_start_q <= 1'b1;
					end
					else
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:112:11
						ws_ctr_q <= ws_ctr_q + 1'b1;
				end
			end
		end
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:121:3
	assign sck_o = sck_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:122:3
	assign ws_o = ws_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:123:3
	assign frame_start_o = (FRAME_PULSE_EN ? frame_start_q : 1'b0);
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:130:3
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:140:3
	reg [31:0] sck_period_cycles;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:141:3
	reg [31:0] sck_last_toggle_time;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:143:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:144:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:145:7
			sck_last_toggle_time <= 0;
		else if (sck_q != sck_prev_q) begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:147:7
			sck_period_cycles = ($time / 1000) - sck_last_toggle_time;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:148:7
			sck_last_toggle_time = $time / 1000;
		end
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:153:3
	// removed an assertion item
	// property sck_half_period_check;
	// 	@(posedge clk_i) disable iff (!rst_ni)
	// 		(sck_q && !$past(sck_q) |-> $past(sck_ctr_q, 1) == (SCK_HALF_LOW - 1))
	// endproperty
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:159:3
	// removed an assertion item
	// property sck_low_period_check;
	// 	@(posedge clk_i) disable iff (!rst_ni)
	// 		(!sck_q && $past(sck_q) |-> $past(sck_ctr_q, 1) == (SCK_HALF_HIGH - 1))
	// endproperty
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:166:3
	// removed an assertion item
	// property ws_change_on_sck_fall;
	// 	@(posedge clk_i) disable iff (!rst_ni)
	// 		(ws_q != $past(ws_q) |-> sck_falling_edge)
	// endproperty
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:172:3
	// removed an assertion item
	// property ws_toggle_period;
	// 	@(posedge clk_i) disable iff (!rst_ni)
	// 		(sck_falling_edge && (ws_ctr_q == (SCKS_PER_FRAME - 1)) |-> ##(1) ws_q != $past(ws_q, 1))
	// endproperty
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:179:3
	// removed an assertion item
	// property frame_start_check;
	// 	@(posedge clk_i) disable iff (!rst_ni)
	// 		(frame_start_q |-> (ws_q == WS_POL) && ($past(ws_q) == ~WS_POL))
	// endproperty
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:184:3
	// removed an assertion item
	// assert_sck_half_period : assert property (
	// 	sck_half_period_check
	// ) else begin
	// 	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:185:10
	// 	$error("SCK half-period violation");
	// end
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:187:3
	// removed an assertion item
	// assert_sck_low_period : assert property (
	// 	sck_low_period_check
	// ) else begin
	// 	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:188:10
	// 	$error("SCK low period violation");
	// end
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:190:3
	// removed an assertion item
	// assert_ws_on_sck_fall : assert property (
	// 	ws_change_on_sck_fall
	// ) else begin
	// 	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:191:10
	// 	$error("WS changed when SCK was not falling");
	// end
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:193:3
	// removed an assertion item
	// assert_ws_toggle_period : assert property (
	// 	ws_toggle_period
	// ) else begin
	// 	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:194:10
	// 	$error("WS toggle period incorrect");
	// end
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:196:3
	// removed an assertion item
	// assert_frame_start : assert property (
	// 	frame_start_check
	// ) else begin
	// 	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/clk_generator/i2s_clock_gen.sv:197:10
	// 	$error("Frame start pulse at wrong time");
	// end
endmodule
