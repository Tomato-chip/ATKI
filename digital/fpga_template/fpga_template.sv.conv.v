// removed package "fpga_template_pkg"
// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:4:1
// removed ["import fpga_template_pkg::*;"]
module fpga_template_top (
	clk,
	uart_rx,
	uart_tx,
	uart_tx_mon,
	uart_rx_mon,
	debug_led,
	btn_s1_resetb,
	btn_s2,
	i2s_sck,
	i2s_ws,
	buffer_full,
	mic_sd_0
);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:7:5
	input clk;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:12:9
	input uart_rx;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:13:9
	output wire uart_tx;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:14:9
	output wire uart_tx_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:15:9
	output wire uart_rx_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:24:9
	output wire [5:0] debug_led;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:25:9
	input btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:26:9
	input btn_s2;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:28:9
	output wire i2s_sck;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:29:9
	output wire i2s_ws;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:30:9
	output wire buffer_full;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:32:9
	input wire mic_sd_0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:45:5
	wire [5:0] debug_sample_led;
	assign debug_led = ~debug_sample_led[5:0];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:46:5
	wire [23:0] debug_sample_l;
	assign sampler_cfg.chanel0_lsb = debug_sample_l[7:0];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:47:5
	assign sampler_cfg.chanel1_lsb = debug_sample_l[15:8];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:48:5
	assign sampler_cfg.chanel2_lsb = debug_sample_l[23:16];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:72:5
	wire [23:0] debug_sample_r;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:73:5
	wire [23:0] sample_ram_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:74:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:75:5
	wire sample_ready_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:77:5
	wire resetb;
	i2s_capture_24 u_sampler(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_i(i2s_sck),
		.ws_i(i2s_ws),
		.sd_i(mic_sd_0),
		.left_o(debug_sample_l),
		.right_o(debug_sample_r),
		.ready_o(sample_ready_w)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:87:5
	pingpong_sp_ram ram_a(
		.clk_i(clk),
		.rst_ni(resetb),
		.sample_i(debug_sample_l),
		.sample_ready_i(sample_ready_w),
		.read_data_o(sample_ram_o),
		.buffer_ready_o(buffer_full)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:98:5
	vu_meter_6led vu(
		.clk_i(clk),
		.rst_ni(resetb),
		.sample_stb_i(sample_ready_w),
		.left_sample_i(debug_sample_l),
		.right_sample_i(sample_ram_o),
		.leds_o(debug_sample_led)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:113:5
	i2s_clock_gen u_i2s_clock(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_o(i2s_sck),
		.ws_o(i2s_ws),
		.frame_start_o()
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:149:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:150:9
	assign resetb = ~btn_s1_resetb;
endmodule
