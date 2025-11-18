// removed package "fpga_template_pkg"
// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:2:1
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:5:5
	input clk;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:10:9
	input uart_rx;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:11:9
	output wire uart_tx;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:12:9
	output wire uart_tx_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:13:9
	output wire uart_rx_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:19:9
	output wire [5:0] debug_led;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:20:9
	input btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:21:9
	input btn_s2;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:23:9
	output wire i2s_sck;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:24:9
	output wire i2s_ws;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:25:9
	output wire buffer_full;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:26:9
	input wire mic_sd_0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:32:5
	wire [5:0] debug_sample_led;
	assign debug_led = ~debug_sample_led[5:0];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:52:5
	wire [23:0] debug_sample_l;
	wire [23:0] debug_sample_r;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:53:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:55:5
	wire resetb = ~btn_s1_resetb;
	i2s_capture_24 u_sampler(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_i(i2s_sck),
		.ws_i(i2s_ws),
		.sd_i(mic_sd_0),
		.left_o(debug_sample_l),
		.right_o(debug_sample_r),
		.ready_o(buffer_full)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:66:5
	vu_meter_6led vu(
		.clk_i(clk),
		.rst_ni(resetb),
		.sample_stb_i(buffer_full),
		.left_sample_i(debug_sample_l),
		.right_sample_i(debug_sample_r),
		.leds_o(debug_sample_led)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:80:5
	i2s_clock_gen u_i2s_clock(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_o(i2s_sck),
		.ws_o(i2s_ws),
		.frame_start_o()
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:91:5
	// removed localparam type fpga_template_pkg_rb_sys_cfg_wire_t
	wire [42:0] sys_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:92:5
	// removed localparam type fpga_template_pkg_rb_dsp_cfg_wire_t
	wire [7:0] dsp_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:93:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:95:5
	fpga_template_comm u_comm(
		.clk(clk),
		.btn_s1_resetb(btn_s1_resetb),
		.btn_s2(btn_s2),
		.uart_rx(uart_rx),
		.uart_tx(uart_tx),
		.uart_tx_mon(uart_tx_mon),
		.uart_rx_mon(uart_rx_mon),
		.sys_cfg(sys_cfg),
		.dsp_cfg(dsp_cfg)
	);
endmodule
