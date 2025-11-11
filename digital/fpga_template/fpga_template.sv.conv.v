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
	vu_analog_out
);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:18:5
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:27:9
	input wire mic_sd_0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:29:9
	output wire buffer_full;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:32:9
	output wire vu_analog_out;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:35:5
	wire resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:36:9
	assign resetb = ~btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:41:5
	wire [5:0] debug_sample_led;
	assign debug_led = ~debug_sample_led[5:0];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:43:5
	wire signed [23:0] sample_left;
	wire signed [23:0] sample_right;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:44:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:49:5
	wire signed [31:0] sampler_to_ram_32_data_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:50:5
	wire signed [31:0] sampler_test_32_data_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:52:5
	wire sampler_to_ram_write_request_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:55:5
	wire signed [31:0] ram_to_6led_32_data_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:56:5
	wire ram_to_6led_read_valid_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:57:5
	wire ram_to_6led_read_ready_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:58:5
	wire ram_to_6led_buffer_ready_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:61:5
	assign sampler_to_ram_32_data_w = {8'b00000000, sample_left};
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:62:5
	assign sampler_test_32_data_w = {8'b00000000, sample_right};
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:67:5
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:80:5
	ram_logic #(
		.WIDTH(32),
		.DEPTH(256),
		.ADDR_WIDTH(8)
	) u_ram(
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:103:5
	vu_meter_6led vu(
		.clk_i(clk),
		.rst_ni(resetb),
		.ram_read_data_i(ram_to_6led_32_data_w[23:0]),
		.ram_read_valid_i(ram_to_6led_read_valid_w),
		.ram_read_ready_o(ram_to_6led_read_ready_w),
		.ram_buffer_ready_i(ram_to_6led_buffer_ready_w),
		.leds_o(debug_sample_led),
		.analog_out_o(vu_analog_out)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:124:5
	i2s_clock_gen u_i2s_clock(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_o(i2s_sck),
		.ws_o(i2s_ws),
		.frame_start_o()
	);
endmodule
