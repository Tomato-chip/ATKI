// removed package "fpga_template_pkg"
module fpga_template_top (
	clk,
	debug_led,
	btn_s1_resetb,
	btn_s2,
	i2s_sck,
	i2s_ws,
	mic_sd_0,
	buffer_full
);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:18:5
	input clk;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:35:9
	output wire [5:0] debug_led;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:36:9
	input btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:37:9
	input btn_s2;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:39:9
	output wire i2s_sck;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:40:9
	output wire i2s_ws;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:41:9
	input wire mic_sd_0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:43:9
	output wire buffer_full;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:55:5
	wire [5:0] debug_sample_led;
	assign debug_led = ~debug_sample_led[5:0];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:58:5
	wire [23:0] sample_left;
	wire [23:0] sample_right;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:59:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:64:5
	wire [31:0] sampler_to_ram_32_data_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:65:5
	wire sampler_to_ram_write_request_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:68:5
	wire [31:0] ram_to_6led_32_data_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:69:5
	wire ram_to_6led_read_valid_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:70:5
	wire ram_to_6led_read_ready_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:71:5
	wire ram_to_6led_buffer_ready_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:74:5
	assign sampler_to_ram_32_data_w = {8'b00000000, sample_left};
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:83:5
	wire resetb;
	i2s_capture_24 u_sampler(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_i(i2s_sck),
		.ws_i(i2s_ws),
		.sd_i(mic_sd_0),
		.left_o(sample_left),
		.right_o(sample_right),
		.ready_o(sampler_to_ram_write_request_w)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:96:5
	ram_logic #(.DEPTH(256)) u_ram(
		.clk_i(clk),
		.rst_ni(resetb),
		.write_data_i(sampler_to_ram_32_data_w),
		.write_valid_i(sampler_to_ram_write_request_w),
		.write_ready_o(),
		.read_data_o(ram_to_6led_32_data_w),
		.read_ready_i(ram_to_6led_read_ready_w),
		.read_valid_o(ram_to_6led_read_valid_w),
		.buffer_ready_o(ram_to_6led_buffer_ready_w),
		.buffer_overflow_o(buffer_full),
		.write_count_o(),
		.read_count_o()
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:114:5
	vu_meter_6led #(.USE_RAM_IF(1'b1)) vu(
		.clk_i(clk),
		.rst_ni(resetb),
		.sample_valid_i(sampler_to_ram_write_request_w),
		.left_sample_i(sample_left),
		.right_sample_i(sample_right),
		.leds_o(debug_sample_led),
		.ram_read_data_i(ram_to_6led_32_data_w[23:0]),
		.ram_read_valid_i(ram_to_6led_read_valid_w),
		.ram_read_ready_o(ram_to_6led_read_ready_w),
		.ram_buffer_ready_i(ram_to_6led_buffer_ready_w)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:135:5
	i2s_clock_gen u_i2s_clock(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_o(i2s_sck),
		.ws_o(i2s_ws),
		.frame_start_o()
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:171:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:172:9
	assign resetb = ~btn_s1_resetb;
endmodule
