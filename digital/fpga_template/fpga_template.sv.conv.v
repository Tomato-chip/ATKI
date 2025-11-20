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
	sd_ad2_test,
	debug_tx_transmitting,
	debug_tx_request,
	sample_ready_o
);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:19:5
	input clk;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:22:9
	output wire [5:0] debug_led;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:23:9
	input btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:24:9
	input btn_s2;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:27:9
	output wire i2s_sck;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:28:9
	output wire i2s_ws;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:29:9
	input wire mic_sd_0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:32:9
	output wire buffer_full;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:33:9
	output wire sd_ad2_test;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:34:9
	output wire debug_tx_transmitting;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:35:9
	output wire debug_tx_request;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:36:9
	output wire sample_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:43:5
	wire resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:44:9
	assign resetb = ~btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:50:5
	wire [5:0] ram_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:51:5
	wire [5:0] vu_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:54:5
	assign debug_led = ~ram_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:56:5
	wire signed [23:0] sample_left;
	wire signed [23:0] sample_right;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:57:5
	wire [5:0] debug_sample_led;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:61:5
	wire sample_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:62:5
	wire signed [31:0] data_ram_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:63:5
	wire read_valid;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:64:5
	wire read_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:65:5
	wire buffer_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:68:5
	i2s_capture_24 u_sampler(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_i(i2s_sck),
		.ws_i(i2s_ws),
		.sd_i(mic_sd_0),
		.left_o(sample_left),
		.right_o(sample_right),
		.ready_o(sample_ready)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:79:5
	assign buffer_full = buffer_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:80:5
	assign sample_ready_o = sample_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:82:5
	ram_logic u_ram(
		.clk_i(clk),
		.rst_ni(resetb),
		.write_data_i({8'b00000000, sample_left}),
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:98:5
	i2s_transmit_24 u_transmit(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_i(i2s_sck),
		.ws_i(i2s_ws),
		.ram_data_i(data_ram_o[23:0]),
		.ram_valid_i(read_valid),
		.ram_ready_o(read_ready),
		.buffer_ready_i(buffer_ready),
		.sd_o(sd_ad2_test),
		.debug_state_transmitting(debug_tx_transmitting),
		.debug_request_sample(debug_tx_request)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:117:5
	i2s_clock_gen u_i2s_clock(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_o(i2s_sck),
		.ws_o(i2s_ws),
		.frame_start_o()
	);
endmodule
