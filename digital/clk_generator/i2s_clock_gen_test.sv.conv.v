// removed package "fpga_template_pkg"
module i2s_clock_gen (
	clk_i,
	rst_ni,
	sck_o,
	ws_o,
	frame_start_o
);
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:15:13
	parameter [31:0] SYS_CLK_HZ = 27000000;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:16:13
	parameter [31:0] SCK_DIV = 8;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:17:13
	parameter [31:0] SCKS_PER_FRAME = 32;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:18:13
	parameter [0:0] WS_POL = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:19:13
	parameter [0:0] FRAME_PULSE_EN = 1'b1;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:21:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:22:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:24:3
	output wire sck_o;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:25:3
	output wire ws_o;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:26:3
	output wire frame_start_o;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:30:3
	localparam [31:0] SCK_HZ = SYS_CLK_HZ / SCK_DIV;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:31:3
	localparam [31:0] WS_HZ = SCK_HZ / SCKS_PER_FRAME;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:34:3
	localparam [31:0] SCK_CTR_WIDTH = $clog2(SCK_DIV);
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:35:3
	localparam [31:0] WS_CTR_WIDTH = 6;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:38:3
	localparam [31:0] SCK_HALF_HIGH = SCK_DIV / 2;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:39:3
	localparam [31:0] SCK_HALF_LOW = SCK_DIV - SCK_HALF_HIGH;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:44:3
	reg [SCK_CTR_WIDTH - 1:0] sck_ctr_q;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:45:3
	reg sck_q;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:46:3
	wire sck_tick;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:48:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:49:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:50:7
			sck_ctr_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:51:7
			sck_q <= 1'b0;
		end
		else
			// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:53:7
			if (sck_q) begin
				begin
					// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:55:9
					if (sck_ctr_q == (SCK_HALF_HIGH - 1)) begin
						// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:56:11
						sck_ctr_q <= 1'sb0;
						// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:57:11
						sck_q <= 1'b0;
					end
					else
						// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:59:11
						sck_ctr_q <= sck_ctr_q + 1'b1;
				end
			end
			else
				// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:63:9
				if (sck_ctr_q == (SCK_HALF_LOW - 1)) begin
					// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:64:11
					sck_ctr_q <= 1'sb0;
					// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:65:11
					sck_q <= 1'b1;
				end
				else
					// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:67:11
					sck_ctr_q <= sck_ctr_q + 1'b1;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:74:3
	wire sck_falling_edge;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:75:3
	reg sck_prev_q;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:77:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:78:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:79:7
			sck_prev_q <= 1'b0;
		else
			// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:81:7
			sck_prev_q <= sck_q;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:85:3
	assign sck_falling_edge = sck_prev_q & ~sck_q;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:90:3
	reg [5:0] ws_ctr_q;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:91:3
	reg ws_q;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:92:3
	reg frame_start_q;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:94:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:95:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:96:7
			ws_ctr_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:97:7
			ws_q <= WS_POL;
			// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:98:7
			frame_start_q <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:100:7
			frame_start_q <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:102:7
			if (sck_falling_edge) begin
				begin
					// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:103:9
					if (ws_ctr_q == (SCKS_PER_FRAME - 1)) begin
						// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:104:11
						ws_ctr_q <= 1'sb0;
						// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:105:11
						ws_q <= ~ws_q;
						// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:108:11
						if (ws_q == ~WS_POL)
							// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:109:13
							frame_start_q <= 1'b1;
					end
					else
						// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:112:11
						ws_ctr_q <= ws_ctr_q + 1'b1;
				end
			end
		end
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:121:3
	assign sck_o = sck_q;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:122:3
	assign ws_o = ws_q;
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:123:3
	assign frame_start_o = (FRAME_PULSE_EN ? frame_start_q : 1'b0);
	// Trace: /home/tomato-chip/ATKI/digital/clk_generator/i2s_clock_gen_test.sv:130:3
endmodule
