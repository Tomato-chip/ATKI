// removed package "fpga_template_pkg"
module i2s_capture_24 (
	clk_i,
	rst_ni,
	sck_i,
	ws_i,
	sd_i,
	left_o,
	right_o,
	ready_o
);
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:12:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:13:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:14:3
	input wire sck_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:15:3
	input wire ws_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:16:3
	input wire sd_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:18:3
	output reg signed [23:0] left_o;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:19:3
	output reg signed [23:0] right_o;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:20:3
	output reg ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:24:3
	reg sck_d;
	reg ws_d;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:25:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:26:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:27:7
			sck_d <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:28:7
			ws_d <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:30:7
			sck_d <= sck_i;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:31:7
			ws_d <= ws_i;
		end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:34:3
	wire sck_rise = ~sck_d & sck_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:35:3
	wire ws_edge = ws_d != ws_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:39:3
	reg [24:0] shift25_q;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:40:3
	reg [5:0] cnt_q;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:41:3
	reg left_done_q;
	reg right_done_q;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:42:3
	reg channel_q;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:44:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:45:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:46:7
			shift25_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:47:7
			cnt_q <= 6'd0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:48:7
			left_o <= 24'h000000;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:49:7
			right_o <= 24'h000000;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:50:7
			left_done_q <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:51:7
			right_done_q <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:52:7
			ready_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:53:7
			channel_q <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:55:7
			ready_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:58:7
			if (ws_edge) begin
				// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:59:9
				cnt_q <= 6'd0;
				// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:60:9
				shift25_q <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:61:9
				channel_q <= ws_i;
			end
			else if (sck_rise) begin
				begin
					// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:65:9
					if (cnt_q < 6'd25) begin
						// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:66:11
						shift25_q <= {shift25_q[23:0], sd_i};
						// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:67:11
						cnt_q <= cnt_q + 6'd1;
					end
				end
			end
			if (cnt_q == 6'd25) begin
				begin
					// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:78:9
					if ((channel_q == 1'b0) && !left_done_q) begin
						// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:79:11
						left_o <= shift25_q[23:0];
						// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:80:11
						left_done_q <= 1'b1;
					end
					else if ((channel_q == 1'b1) && left_done_q) begin
						// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:82:11
						right_o <= shift25_q[23:0];
						// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:83:11
						right_done_q <= 1'b1;
					end
				end
			end
			if (left_done_q && right_done_q) begin
				// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:87:9
				ready_o <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:88:9
				left_done_q <= 1'b0;
				// Trace: /home/tomato-chip/ATKI/digital/sampler/i2s_capture_24_test.sv:89:9
				right_done_q <= 1'b0;
			end
		end
endmodule
