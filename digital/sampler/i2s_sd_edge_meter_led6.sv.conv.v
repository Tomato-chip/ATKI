// removed package "fpga_template_pkg"
module i2s_sd_edge_meter_led6 (
	clk_i,
	rst_ni,
	sck_i,
	ws_i,
	sd_i,
	level6_o
);
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:6:13
	parameter [0:0] USE_LEFT = 1'b0;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:8:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:9:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:10:3
	input wire sck_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:11:3
	input wire ws_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:12:3
	input wire sd_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:13:3
	output wire [5:0] level6_o;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:16:3
	reg sck_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:17:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:18:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:18:18
			sck_q <= 1'b0;
		else
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:18:38
			sck_q <= sck_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:20:3
	wire sck_rise = sck_i & ~sck_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:21:3
	wire sck_fall = ~sck_i & sck_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:24:3
	reg ws_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:24:16
	always @(posedge clk_i)
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:24:56
			ws_q <= 0;
		else
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:24:72
			ws_q <= ws_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:25:3
	wire ws_edge = ws_i ^ ws_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:28:3
	reg measure_en;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:29:3
	reg [5:0] bit_count;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:30:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:31:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:32:7
			measure_en <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:33:7
			bit_count <= 1'sb0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:35:7
			if (ws_edge) begin
				// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:36:9
				measure_en <= 1'b0;
				// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:37:9
				bit_count <= 1'sb0;
			end
			if (sck_rise) begin
				begin
					// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:41:9
					if (!measure_en)
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:41:26
						measure_en <= 1'b1;
					else if (bit_count != 6'd63)
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:42:38
						bit_count <= bit_count + 6'd1;
				end
			end
			if (bit_count == 6'd24)
				// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:45:31
				measure_en <= 1'b0;
		end
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:50:3
	reg sd_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:50:15
	always @(posedge clk_i)
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:50:55
			sd_q <= 0;
		else
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:50:71
			sd_q <= sd_i;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:51:3
	wire sd_toggle = sd_i ^ sd_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:52:3
	wire half_ok = (USE_LEFT ? ws_i == 1'bz : ws_i != 1'bz);
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:57:3
	reg [5:0] accum_q;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:58:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:59:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:59:18
			accum_q <= 1'sb0;
		else begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:62:7
			if (ws_edge)
				// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:62:20
				accum_q <= accum_q - (accum_q >> 2);
			if ((measure_en && sd_toggle) && half_ok) begin
				begin
					// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:65:9
					if (accum_q != 6'h3f)
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:65:31
						accum_q <= accum_q + 6'd1;
				end
			end
		end
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/sampler/i2s_sd_edge_meter_led6.sv:70:3
	assign level6_o = accum_q;
endmodule
