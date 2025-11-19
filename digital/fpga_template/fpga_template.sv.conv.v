// removed package "fpga_template_pkg"
module fpga_template_top (
	clk,
	debug_led,
	btn_s1_resetb,
	btn_s2,
	i2s_sck,
	i2s_ws,
	mic_sd_0,
	buffer_full,
	vu_analog_out,
	fft_busy,
	fft_output_valid
);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:19:9
	input clk;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:21:9
	output wire [5:0] debug_led;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:22:9
	input btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:23:9
	input btn_s2;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:25:9
	output wire i2s_sck;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:26:9
	output wire i2s_ws;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:28:9
	output wire mic_sd_0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:30:9
	output wire buffer_full;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:32:9
	output wire vu_analog_out;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:34:9
	output wire fft_busy;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:35:9
	output wire fft_output_valid;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:37:5
	wire resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:38:9
	assign resetb = ~btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:44:5
	wire [5:0] ram_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:45:5
	wire [5:0] vu_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:47:5
	assign debug_led = ~vu_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:50:5
	wire signed [23:0] sample_left;
	wire signed [23:0] sample_right;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:51:5
	wire [5:0] debug_sample_led;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:52:5
	wire mic_sd_0_test;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:53:5
	assign mic_sd_0 = mic_sd_0_test;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:58:5
	pcm_rom #(
		.WIDTH(24),
		.ADDR_WIDTH(8)
	) u_pcm_rom(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_i(i2s_sck),
		.ws_i(i2s_ws),
		.sd_o(mic_sd_0_test)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:72:5
	wire sample_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:73:5
	wire signed [35:0] data_ram_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:74:5
	wire read_valid;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:75:5
	wire read_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:76:5
	wire buffer_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:79:5
	i2s_capture_24 u_sampler(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_i(i2s_sck),
		.ws_i(i2s_ws),
		.sd_i(mic_sd_0_test),
		.left_o(sample_left),
		.right_o(sample_right),
		.ready_o(sample_ready)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:90:5
	assign buffer_full = sample_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:92:5
	ram_logic u_ram(
		.clk_i(clk),
		.rst_ni(resetb),
		.write_data_i({sample_right[23:6], sample_left[23:6]}),
		.write_valid_i(sample_ready),
		.write_ready_o(),
		.read_data_o(data_ram_o),
		.read_ready_i(read_ready),
		.read_valid_o(read_valid),
		.buffer_ready_o(buffer_ready),
		.buffer_overflow_o(),
		.write_count_o(),
		.read_count_o(),
		.debug_leds_o(ram_debug_leds)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:111:5
	wire signed [17:0] fft_data_real_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:112:5
	wire signed [17:0] fft_data_imag_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:113:5
	wire fft_valid_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:114:5
	wire fft_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:115:5
	wire fft_busy_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:118:5
	fft_256 #(
		.DATA_WIDTH(18),
		.FFT_SIZE(256),
		.STAGES(8)
	) u_fft(
		.clk_i(clk),
		.rst_ni(resetb),
		.data_real_i(data_ram_o[17:0]),
		.data_imag_i(18'sd0),
		.valid_i(read_valid),
		.ready_o(read_ready),
		.data_real_o(fft_data_real_o),
		.data_imag_o(fft_data_imag_o),
		.valid_o(fft_valid_o),
		.ready_i(fft_ready_i),
		.busy_o(fft_busy_o)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:136:5
	assign fft_busy = fft_busy_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:137:5
	assign fft_output_valid = fft_valid_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:142:5
	wire signed [35:0] fft_ram_data_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:143:5
	wire fft_ram_read_valid;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:144:5
	reg fft_ram_read_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:145:5
	wire fft_ram_buffer_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:147:5
	ram_logic #(
		.WIDTH(36),
		.DEPTH(256)
	) u_fft_ram(
		.clk_i(clk),
		.rst_ni(resetb),
		.write_data_i({fft_data_imag_o, fft_data_real_o}),
		.write_valid_i(fft_valid_o),
		.write_ready_o(fft_ready_i),
		.read_data_o(fft_ram_data_o),
		.read_ready_i(fft_ram_read_ready),
		.read_valid_o(fft_ram_read_valid),
		.buffer_ready_o(fft_ram_buffer_ready),
		.buffer_overflow_o(),
		.write_count_o(),
		.read_count_o(),
		.debug_leds_o()
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:167:5
	reg [7:0] current_bin;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:168:5
	reg [47:0] max_magnitude;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:169:5
	reg [7:0] peak_bin;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:170:5
	wire [5:0] fft_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:171:5
	wire signed [17:0] fft_real_from_ram;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:172:5
	wire signed [17:0] fft_imag_from_ram;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:175:5
	assign fft_real_from_ram = fft_ram_data_o[17:0];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:176:5
	assign fft_imag_from_ram = fft_ram_data_o[35:18];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:178:5
	always @(posedge clk or negedge resetb)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:179:9
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:180:13
			current_bin <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:181:13
			max_magnitude <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:182:13
			peak_bin <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:183:13
			fft_ram_read_ready <= 1;
		end
		else
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:185:13
			if (fft_ram_read_valid && fft_ram_read_ready) begin : sv2v_autoblock_1
				// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:187:17
				reg [47:0] mag_sq;
				// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:188:17
				mag_sq = (fft_real_from_ram * fft_real_from_ram) + (fft_imag_from_ram * fft_imag_from_ram);
				// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:192:17
				if (current_bin < 128) begin
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:193:21
					if (mag_sq > max_magnitude) begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:194:25
						max_magnitude <= mag_sq;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:195:25
						peak_bin <= current_bin;
					end
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:197:21
					current_bin <= current_bin + 1;
				end
				else begin
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:200:21
					current_bin <= 0;
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:201:21
					max_magnitude <= 0;
				end
			end
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:208:5
	assign fft_debug_leds = peak_bin[7:2];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:211:5
	assign vu_debug_leds = fft_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:214:5
	assign vu_analog_out = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:221:5
	i2s_clock_gen u_i2s_clock(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_o(i2s_sck),
		.ws_o(i2s_ws),
		.frame_start_o()
	);
endmodule
