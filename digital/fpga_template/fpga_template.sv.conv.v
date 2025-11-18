// removed package "fpga_template_pkg"
// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:3:5
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:6:9
	input clk;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:11:13
	input uart_rx;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:12:13
	output wire uart_tx;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:13:13
	output wire uart_tx_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:14:13
	output wire uart_rx_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:23:13
	output wire [5:0] debug_led;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:24:13
	input btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:25:13
	input btn_s2;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:27:13
	output wire i2s_sck;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:28:13
	output wire i2s_ws;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:29:13
	output wire buffer_full;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:31:13
	input wire mic_sd_0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:45:5
	wire [5:0] ram_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:46:5
	wire [5:0] vu_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:48:5
	wire debug_ram;
	wire [7:0] rb_ram_add;
	wire sd_select_mux;
	assign debug_led = ~{sd_select_mux, rb_ram_add[0], debug_ram, ram_debug_leds[5], vu_debug_leds[0]};
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:51:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:52:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:53:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:55:5
	// removed localparam type fpga_template_pkg_rb_sampler_cfg_wire_t
	wire [26:0] sampler_cfg;
	assign debug_ram = sampler_cfg[25];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:56:5
	assign rb_ram_add = sampler_cfg[24-:8];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:59:5
	assign sd_select_mux = sampler_cfg[0];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:81:5
	wire signed [23:0] sample_left;
	wire signed [23:0] sample_right;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:82:5
	wire mic_sd;
	wire mic_sd_dummy;
	wire sd_mic;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:83:5
	assign sd_mic = mic_sd_0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:88:9
	wire resetb;
	pcm_rom u_pcm_rom(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_i(i2s_sck),
		.ws_i(i2s_ws),
		.sd_o(mic_sd_dummy)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:96:5
	assign mic_sd = (sd_select_mux == 1'b0 ? sd_mic : mic_sd_dummy);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:101:9
	wire sample_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:102:9
	wire signed [35:0] data_ram_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:103:9
	wire read_valid;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:104:9
	wire read_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:105:9
	wire buffer_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:108:9
	i2s_capture_24 u_sampler(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_i(i2s_sck),
		.ws_i(i2s_ws),
		.sd_i(mic_sd),
		.left_o(sample_left),
		.right_o(sample_right),
		.ready_o(sample_ready)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:119:9
	assign buffer_full = sample_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:121:9
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
		.debug_leds_o(ram_debug_leds),
		.manual_mode_i(debug_ram),
		.manual_addr_i(rb_ram_add)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:144:5
	wire debug_sample_led;
	wire vu_analog_out;
	vu_meter_6led vu(
		.clk_i(clk),
		.rst_ni(resetb),
		.ram_read_data_i(data_ram_o[17:0]),
		.ram_read_valid_i(read_valid),
		.ram_read_ready_o(read_ready),
		.ram_buffer_ready_i(buffer_ready),
		.leds_o(debug_sample_led),
		.analog_out_o(vu_analog_out),
		.debug_o(vu_debug_leds)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:236:9
	i2s_clock_gen u_i2s_clock(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_o(i2s_sck),
		.ws_o(i2s_ws),
		.frame_start_o()
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:250:5
	assign uart_rx_mon = uart_rx;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:251:5
	wire debug_rx_data_valid;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:254:5
	reg [20:0] clk_div_counter;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:255:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:256:9
		if (!resetb)
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:257:13
			clk_div_counter <= 0;
		else
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:259:13
			clk_div_counter <= clk_div_counter + 1;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:263:5
	assign uart_tx_mon = clk_div_counter[20];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:274:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:275:9
	assign resetb = ~btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:290:5
	// removed localparam type fpga_template_pkg_rb_sys_cfg_wire_t
	wire [42:0] sys_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:291:5
	assign sys_cfg[40] = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:293:5
	// removed localparam type fpga_template_pkg_rb_dsp_cfg_wire_t
	wire [7:0] dsp_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:294:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:298:5
	wire [7:0] rb_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:299:5
	wire [7:0] rb_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:300:5
	wire [7:0] rb_data_read_from_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:301:5
	wire rb_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:302:5
	wire rb_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:303:5
	wire [1:0] rb_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:306:5
	wire [7:0] i2c_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:307:5
	wire [7:0] i2c_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:308:5
	wire i2c_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:309:5
	wire i2c_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:310:5
	wire [1:0] i2c_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:313:5
	wire [7:0] uart_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:314:5
	wire [7:0] uart_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:315:5
	wire uart_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:316:5
	wire uart_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:317:5
	wire [1:0] uart_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:318:5
	wire [7:0] uart_debug_out;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:319:5
	wire [1:0] uart_tx_state_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:322:5
	reg debug_send;
	wire debug_uart_send;
	assign debug_uart_send = debug_send;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:323:5
	reg [7:0] debug_byte;
	wire debug_uart_data;
	assign debug_uart_data = debug_byte;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:344:5
	uart_if uart_inst(
		.clk(clk),
		.resetb(resetb),
		.uart_rx(uart_rx),
		.uart_tx(uart_tx),
		.address(uart_address),
		.data_write_to_reg(uart_data_write_to_reg),
		.data_read_from_reg(rb_data_read_from_reg),
		.reg_en(uart_reg_en),
		.write_en(uart_write_en),
		.streamSt_mon(uart_streamSt_mon),
		.debug_send(debug_uart_send),
		.debug_data(debug_uart_data),
		.debug_out(uart_debug_out),
		.debug_rx_data_valid(debug_rx_data_valid),
		.rx_state_mon(),
		.proto_state_mon(),
		.tx_state_mon(uart_tx_state_mon)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:374:5
	assign rb_address = uart_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:375:5
	assign rb_data_write_to_reg = uart_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:376:5
	assign rb_reg_en = uart_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:377:5
	assign rb_write_en = uart_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:378:5
	assign rb_streamSt_mon = uart_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:382:5
	rb_fpga_template rb_fpga_template_inst(
		.clk(clk),
		.resetb(resetb),
		.address(rb_address),
		.data_write_in(rb_data_write_to_reg),
		.data_read_out(rb_data_read_from_reg),
		.reg_en(rb_reg_en),
		.write_en(rb_write_en),
		.sys_cfg(sys_cfg),
		.dsp_cfg(dsp_cfg),
		.sampler_cfg(sampler_cfg)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:410:5
	reg [2:0] btn_s2_sync;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:411:5
	reg btn_s2_prev;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:412:5
	wire btn_s2_edge;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:414:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:415:9
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:416:13
			btn_s2_sync <= 3'b000;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:417:13
			btn_s2_prev <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:419:13
			btn_s2_sync <= {btn_s2_sync[1:0], btn_s2};
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:420:13
			btn_s2_prev <= btn_s2_sync[2];
		end
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:424:5
	assign btn_s2_edge = btn_s2_sync[2] & ~btn_s2_prev;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:427:5
	reg [3:0] debug_state;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:428:5
	reg [15:0] debug_counter;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:429:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:430:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:431:5
	reg debug_active;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:433:5
	localparam DEBUG_IDLE = 4'h0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:434:5
	localparam DEBUG_START = 4'h1;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:435:5
	localparam DEBUG_SEND = 4'h2;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:436:5
	localparam DEBUG_WAIT = 4'h3;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:439:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:440:9
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:442:13
			debug_state <= DEBUG_IDLE;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:443:13
			debug_counter <= 16'h0000;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:444:13
			debug_byte <= 8'h00;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:445:13
			debug_send <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:446:13
			debug_active <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:448:13
			debug_send <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:450:13
			case (debug_state)
				DEBUG_IDLE:
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:452:21
					if (!btn_s2_edge) begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:454:25
						debug_state <= DEBUG_START;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:455:25
						debug_counter <= 16'h0000;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:456:25
						debug_active <= 1'b1;
					end
				DEBUG_START:
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:461:21
					if (debug_counter < 16'h1000) begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:462:25
						debug_counter <= debug_counter + 1;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:465:25
						if (debug_counter[15:8] == 8'h00)
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:466:29
							case (debug_counter[7:0])
								8'h10: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:467:46
									debug_byte <= 8'h44;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:467:67
									debug_send <= 1'b1;
								end
								8'h20: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:468:46
									debug_byte <= 8'h42;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:468:67
									debug_send <= 1'b1;
								end
								8'h30: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:469:46
									debug_byte <= 8'h47;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:469:67
									debug_send <= 1'b1;
								end
								8'h40: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:470:46
									debug_byte <= 8'h3a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:470:67
									debug_send <= 1'b1;
								end
								8'h50: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:471:46
									debug_byte <= 8'h20;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:471:67
									debug_send <= 1'b1;
								end
								8'h60: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:472:46
									debug_byte <= 8'h00;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:472:67
									debug_send <= 1'b1;
								end
								8'h70: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:473:46
									debug_byte <= 8'h01;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:473:67
									debug_send <= 1'b1;
								end
								8'h80: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:474:46
									debug_byte <= 8'h02;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:474:67
									debug_send <= 1'b1;
								end
								8'h90: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:475:46
									debug_byte <= 8'h03;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:475:67
									debug_send <= 1'b1;
								end
								8'ha0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:476:46
									debug_byte <= 8'h04;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:476:67
									debug_send <= 1'b1;
								end
								8'hb0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:477:46
									debug_byte <= 8'h05;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:477:67
									debug_send <= 1'b1;
								end
								8'hc0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:478:46
									debug_byte <= 8'h06;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:478:67
									debug_send <= 1'b1;
								end
								8'hd0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:479:46
									debug_byte <= 8'h07;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:479:67
									debug_send <= 1'b1;
								end
								8'he0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:480:46
									debug_byte <= 8'h08;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:480:67
									debug_send <= 1'b1;
								end
								8'hf0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:481:46
									debug_byte <= 8'h09;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:481:67
									debug_send <= 1'b1;
								end
								default:
									;
							endcase
						else if (debug_counter[15:8] == 8'h01)
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:487:29
							case (debug_counter[7:0])
								8'h00: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:488:46
									debug_byte <= 8'h0a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:488:67
									debug_send <= 1'b1;
								end
								8'h10: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:489:46
									debug_byte <= 8'h0b;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:489:67
									debug_send <= 1'b1;
								end
								8'h20: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:490:46
									debug_byte <= 8'h0c;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:490:67
									debug_send <= 1'b1;
								end
								8'h30: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:491:46
									debug_byte <= 8'h0d;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:491:67
									debug_send <= 1'b1;
								end
								8'h40: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:492:46
									debug_byte <= 8'h0e;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:492:67
									debug_send <= 1'b1;
								end
								8'h50: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:493:46
									debug_byte <= 8'h0f;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:493:67
									debug_send <= 1'b1;
								end
								8'h60: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:494:46
									debug_byte <= 8'h0d;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:494:67
									debug_send <= 1'b1;
								end
								8'h70: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:495:46
									debug_byte <= 8'h0a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:495:67
									debug_send <= 1'b1;
								end
								8'h80: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:497:37
									debug_state <= DEBUG_IDLE;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:498:37
									debug_active <= 1'b0;
								end
								default:
									;
							endcase
						else begin
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:506:29
							debug_state <= DEBUG_IDLE;
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:507:29
							debug_active <= 1'b0;
						end
					end
					else begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:511:25
						debug_state <= DEBUG_IDLE;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:512:25
						debug_active <= 1'b0;
					end
			endcase
		end
endmodule
