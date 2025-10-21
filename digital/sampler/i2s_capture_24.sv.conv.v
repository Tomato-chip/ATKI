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
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:12:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:13:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:14:3
	input wire sck_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:15:3
	input wire ws_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:16:3
	input wire sd_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:18:3
	output reg [23:0] left_o;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:19:3
	output reg [23:0] right_o;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:20:3
	output reg ready_o;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:24:3
	reg sck_d;
	reg ws_d;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:25:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:26:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:27:7
			sck_d <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:28:7
			ws_d <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:30:7
			sck_d <= sck_i;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:31:7
			ws_d <= ws_i;
		end
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:34:3
	wire sck_rise = ~sck_d & sck_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:35:3
	wire ws_edge = ws_d ^ ws_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:38:3
	reg [24:0] shift25_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:39:3
	reg [5:0] cnt_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:40:3
	reg left_done_q;
	reg right_done_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:42:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:43:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:44:7
			shift25_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:45:7
			cnt_q <= 6'd0;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:46:7
			left_o <= 24'h000000;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:47:7
			right_o <= 24'h000000;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:48:7
			left_done_q <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:49:7
			right_done_q <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:50:7
			ready_o <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:52:7
			ready_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:55:7
			if (ws_edge) begin
				// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:56:9
				cnt_q <= 6'd0;
				// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:57:9
				shift25_q <= 1'sb0;
			end
			else if (sck_rise) begin
				begin
					// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:59:9
					if (cnt_q < 6'd25) begin
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:60:11
						shift25_q <= {shift25_q[23:0], sd_i};
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:61:11
						cnt_q <= cnt_q + 6'd1;
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:65:11
						if (cnt_q == 6'd24) begin
							begin
								// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:66:13
								if (ws_i == 1'b0) begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:67:15
									left_o <= shift25_q[23:0];
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:68:15
									left_done_q <= 1'b1;
								end
								else begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:70:15
									right_o <= shift25_q[23:0];
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:71:15
									right_done_q <= 1'b1;
								end
							end
						end
					end
				end
			end
			if (left_done_q && right_done_q) begin
				// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:79:9
				ready_o <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:80:9
				left_done_q <= 1'b0;
				// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_capture_24.sv:81:9
				right_done_q <= 1'b0;
			end
		end
endmodule
