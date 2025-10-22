// removed package "fpga_template_pkg"
// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:4:1
// removed ["import fpga_template_pkg::*;"]
module fpga_template_top (
	clk,
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:85:5
	wire sample_ready_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:86:5
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:98:5
	wire [15:0] ram_data_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:99:5
	wire ram_buffer_ready_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:100:5
	wire ram_read_enable_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:101:5
	wire ram_read_ack_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:103:5
	pingpong_sp_ram u_ram(
		.clk_i(clk),
		.rst_ni(resetb),
		.sample_i(debug_sample_l[15:0]),
		.sample_ready_i(sample_ready_w),
		.read_data_o(ram_data_w),
		.buffer_ready_o(ram_buffer_ready_w),
		.read_enable_o(ram_read_enable_w),
		.read_ack_i(ram_read_ack_w)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:115:5
	assign buffer_full = ram_buffer_ready_w;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:116:5
	vu_meter_6led vu(
		.clk_i(clk),
		.rst_ni(resetb),
		.buffer_ready_i(ram_buffer_ready_w),
		.read_enable_i(ram_read_enable_w),
		.ram_sample_i(ram_data_w),
		.read_ack_o(ram_read_ack_w),
		.leds_o(debug_sample_led)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:139:5
	i2s_clock_gen u_i2s_clock(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_o(i2s_sck),
		.ws_o(i2s_ws),
		.frame_start_o()
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:175:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:176:9
	assign resetb = ~btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:191:5
	// removed localparam type fpga_template_pkg_rb_sys_cfg_wire_t
	wire [42:0] sys_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:192:5
	assign sys_cfg[40] = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:194:5
	// removed localparam type fpga_template_pkg_rb_dsp_cfg_wire_t
	wire [7:0] dsp_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:199:5
	wire [7:0] rb_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:200:5
	wire [7:0] rb_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:201:5
	wire [7:0] rb_data_read_from_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:202:5
	wire rb_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:203:5
	wire rb_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:204:5
	wire [1:0] rb_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:207:5
	wire [7:0] i2c_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:208:5
	wire [7:0] i2c_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:209:5
	wire i2c_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:210:5
	wire i2c_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:211:5
	wire [1:0] i2c_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:214:5
	wire [7:0] uart_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:215:5
	wire [7:0] uart_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:216:5
	wire uart_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:217:5
	wire uart_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:218:5
	wire [1:0] uart_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:219:5
	wire [7:0] uart_debug_out;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:220:5
	wire [1:0] uart_tx_state_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:223:5
	wire debug_uart_send;
	assign debug_uart_send = debug_send;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:224:5
	wire debug_uart_data;
	assign debug_uart_data = debug_byte;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:275:5
	assign rb_address = uart_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:276:5
	assign rb_data_write_to_reg = uart_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:277:5
	assign rb_reg_en = uart_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:278:5
	assign rb_write_en = uart_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:279:5
	assign rb_streamSt_mon = uart_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:283:5
	rb_fpga_template rb_fpga_template_inst(
		.clk(clk),
		.resetb(resetb),
		.address(rb_address),
		.data_write_in(rb_data_write_to_reg),
		.data_read_out(rb_data_read_from_reg),
		.reg_en(rb_reg_en),
		.write_en(rb_write_en),
		.sys_cfg(sys_cfg),
		.dsp_cfg(dsp_cfg)
	);
endmodule
