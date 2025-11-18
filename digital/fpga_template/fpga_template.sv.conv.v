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
	buffer_full
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:42:5
	wire [5:0] ram_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:43:5
	wire [5:0] vu_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:45:5
	wire debug_ram;
	wire [7:0] rb_ram_add;
	wire sd_select_mux;
	assign debug_led = ~{sd_select_mux, rb_ram_add[0], debug_ram, ram_debug_leds[5], vu_debug_leds[0]};
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:48:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:49:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:50:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:52:5
	// removed localparam type fpga_template_pkg_rb_sampler_cfg_wire_t
	wire [26:0] sampler_cfg;
	assign debug_ram = sampler_cfg[25];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:53:5
	assign rb_ram_add = sampler_cfg[24-:8];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:56:5
	assign sd_select_mux = sampler_cfg[0];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:78:5
	wire signed [23:0] sample_left;
	wire signed [23:0] sample_right;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:79:5
	wire mic_sd;
	wire mic_sd_dummy;
	wire sd_mic;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:80:5
	assign sd_mic = mic_sd_0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:85:9
	wire resetb;
	pcm_rom u_pcm_rom(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_i(i2s_sck),
		.ws_i(i2s_ws),
		.sd_o(mic_sd_dummy)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:98:9
	wire sample_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:99:9
	wire signed [35:0] data_ram_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:100:9
	wire read_valid;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:101:9
	wire read_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:102:9
	wire buffer_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:105:9
	i2s_capture_24 u_sampler(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_i(i2s_sck),
		.ws_i(i2s_ws),
		.sd_i(mic_sd_dummy),
		.left_o(sample_left),
		.right_o(sample_right),
		.ready_o(sample_ready)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:116:9
	assign buffer_full = sample_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:118:9
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
		.manual_mode_i(1'b0),
		.manual_addr_i()
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:141:5
	wire debug_sample_led;
	wire vu_analog_out;
	vu_meter_6led vu(
		.clk_i(clk),
		.rst_ni(resetb),
		.ram_read_data_i(data_ram_o[23:0]),
		.ram_read_valid_i(read_valid),
		.ram_read_ready_o(read_ready),
		.ram_buffer_ready_i(buffer_ready),
		.leds_o(debug_sample_led),
		.analog_out_o(vu_analog_out),
		.debug_o(vu_debug_leds)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:233:9
	i2s_clock_gen u_i2s_clock(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_o(i2s_sck),
		.ws_o(i2s_ws),
		.frame_start_o()
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:247:5
	assign uart_rx_mon = uart_rx;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:248:5
	wire debug_rx_data_valid;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:251:5
	reg [20:0] clk_div_counter;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:252:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:253:9
		if (!resetb)
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:254:13
			clk_div_counter <= 0;
		else
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:256:13
			clk_div_counter <= clk_div_counter + 1;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:260:5
	assign uart_tx_mon = clk_div_counter[20];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:271:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:272:9
	assign resetb = ~btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:287:5
	// removed localparam type fpga_template_pkg_rb_sys_cfg_wire_t
	wire [42:0] sys_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:288:5
	assign sys_cfg[40] = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:290:5
	// removed localparam type fpga_template_pkg_rb_dsp_cfg_wire_t
	wire [7:0] dsp_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:291:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:295:5
	wire [7:0] rb_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:296:5
	wire [7:0] rb_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:297:5
	wire [7:0] rb_data_read_from_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:298:5
	wire rb_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:299:5
	wire rb_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:300:5
	wire [1:0] rb_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:303:5
	wire [7:0] i2c_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:304:5
	wire [7:0] i2c_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:305:5
	wire i2c_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:306:5
	wire i2c_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:307:5
	wire [1:0] i2c_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:310:5
	wire [7:0] uart_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:311:5
	wire [7:0] uart_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:312:5
	wire uart_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:313:5
	wire uart_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:314:5
	wire [1:0] uart_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:315:5
	wire [7:0] uart_debug_out;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:316:5
	wire [1:0] uart_tx_state_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:319:5
	reg debug_send;
	wire debug_uart_send;
	assign debug_uart_send = debug_send;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:320:5
	reg [7:0] debug_byte;
	wire debug_uart_data;
	assign debug_uart_data = debug_byte;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:341:5
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:371:5
	assign rb_address = uart_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:372:5
	assign rb_data_write_to_reg = uart_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:373:5
	assign rb_reg_en = uart_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:374:5
	assign rb_write_en = uart_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:375:5
	assign rb_streamSt_mon = uart_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:379:5
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:407:5
	reg [2:0] btn_s2_sync;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:408:5
	reg btn_s2_prev;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:409:5
	wire btn_s2_edge;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:411:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:412:9
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:413:13
			btn_s2_sync <= 3'b000;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:414:13
			btn_s2_prev <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:416:13
			btn_s2_sync <= {btn_s2_sync[1:0], btn_s2};
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:417:13
			btn_s2_prev <= btn_s2_sync[2];
		end
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:421:5
	assign btn_s2_edge = btn_s2_sync[2] & ~btn_s2_prev;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:424:5
	reg [3:0] debug_state;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:425:5
	reg [15:0] debug_counter;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:426:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:427:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:428:5
	reg debug_active;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:430:5
	localparam DEBUG_IDLE = 4'h0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:431:5
	localparam DEBUG_START = 4'h1;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:432:5
	localparam DEBUG_SEND = 4'h2;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:433:5
	localparam DEBUG_WAIT = 4'h3;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:436:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:437:9
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:439:13
			debug_state <= DEBUG_IDLE;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:440:13
			debug_counter <= 16'h0000;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:441:13
			debug_byte <= 8'h00;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:442:13
			debug_send <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:443:13
			debug_active <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:445:13
			debug_send <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:447:13
			case (debug_state)
				DEBUG_IDLE:
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:449:21
					if (!btn_s2_edge) begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:451:25
						debug_state <= DEBUG_START;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:452:25
						debug_counter <= 16'h0000;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:453:25
						debug_active <= 1'b1;
					end
				DEBUG_START:
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:458:21
					if (debug_counter < 16'h1000) begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:459:25
						debug_counter <= debug_counter + 1;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:462:25
						if (debug_counter[15:8] == 8'h00)
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:463:29
							case (debug_counter[7:0])
								8'h10: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:464:46
									debug_byte <= 8'h44;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:464:67
									debug_send <= 1'b1;
								end
								8'h20: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:465:46
									debug_byte <= 8'h42;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:465:67
									debug_send <= 1'b1;
								end
								8'h30: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:466:46
									debug_byte <= 8'h47;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:466:67
									debug_send <= 1'b1;
								end
								8'h40: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:467:46
									debug_byte <= 8'h3a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:467:67
									debug_send <= 1'b1;
								end
								8'h50: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:468:46
									debug_byte <= 8'h20;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:468:67
									debug_send <= 1'b1;
								end
								8'h60: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:469:46
									debug_byte <= 8'h00;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:469:67
									debug_send <= 1'b1;
								end
								8'h70: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:470:46
									debug_byte <= 8'h01;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:470:67
									debug_send <= 1'b1;
								end
								8'h80: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:471:46
									debug_byte <= 8'h02;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:471:67
									debug_send <= 1'b1;
								end
								8'h90: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:472:46
									debug_byte <= 8'h03;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:472:67
									debug_send <= 1'b1;
								end
								8'ha0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:473:46
									debug_byte <= 8'h04;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:473:67
									debug_send <= 1'b1;
								end
								8'hb0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:474:46
									debug_byte <= 8'h05;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:474:67
									debug_send <= 1'b1;
								end
								8'hc0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:475:46
									debug_byte <= 8'h06;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:475:67
									debug_send <= 1'b1;
								end
								8'hd0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:476:46
									debug_byte <= 8'h07;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:476:67
									debug_send <= 1'b1;
								end
								8'he0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:477:46
									debug_byte <= 8'h08;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:477:67
									debug_send <= 1'b1;
								end
								8'hf0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:478:46
									debug_byte <= 8'h09;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:478:67
									debug_send <= 1'b1;
								end
								default:
									;
							endcase
						else if (debug_counter[15:8] == 8'h01)
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:484:29
							case (debug_counter[7:0])
								8'h00: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:485:46
									debug_byte <= 8'h0a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:485:67
									debug_send <= 1'b1;
								end
								8'h10: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:486:46
									debug_byte <= 8'h0b;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:486:67
									debug_send <= 1'b1;
								end
								8'h20: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:487:46
									debug_byte <= 8'h0c;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:487:67
									debug_send <= 1'b1;
								end
								8'h30: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:488:46
									debug_byte <= 8'h0d;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:488:67
									debug_send <= 1'b1;
								end
								8'h40: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:489:46
									debug_byte <= 8'h0e;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:489:67
									debug_send <= 1'b1;
								end
								8'h50: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:490:46
									debug_byte <= 8'h0f;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:490:67
									debug_send <= 1'b1;
								end
								8'h60: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:491:46
									debug_byte <= 8'h0d;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:491:67
									debug_send <= 1'b1;
								end
								8'h70: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:492:46
									debug_byte <= 8'h0a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:492:67
									debug_send <= 1'b1;
								end
								8'h80: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:494:37
									debug_state <= DEBUG_IDLE;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:495:37
									debug_active <= 1'b0;
								end
								default:
									;
							endcase
						else begin
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:503:29
							debug_state <= DEBUG_IDLE;
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:504:29
							debug_active <= 1'b0;
						end
					end
					else begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:508:25
						debug_state <= DEBUG_IDLE;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:509:25
						debug_active <= 1'b0;
					end
			endcase
		end
endmodule
