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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:45:1
	wire [5:0] debug_sample_led;
	assign debug_led = ~debug_sample_led[5:0];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:46:1
	wire [23:0] debug_sample_l;
	assign sampler_cfg.chanel0_lsb = debug_sample_l[7:0];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:47:1
	assign sampler_cfg.chanel1_lsb = debug_sample_l[15:8];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:48:1
	assign sampler_cfg.chanel2_lsb = debug_sample_l[23:16];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:72:5
	wire [23:0] debug_sample_r;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:73:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:84:5
	wire resetb;
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:95:5
	vu_meter_6led vu(
		.clk_i(clk),
		.rst_ni(resetb),
		.sample_stb_i(buffer_full),
		.left_sample_i(debug_sample_l),
		.right_sample_i(debug_sample_r),
		.leds_o(debug_sample_led)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:117:5
	i2s_clock_gen u_i2s_clock(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_o(i2s_sck),
		.ws_o(i2s_ws),
		.frame_start_o()
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:129:5
	assign uart_rx_mon = uart_rx;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:130:5
	wire debug_rx_data_valid;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:133:5
	reg [20:0] clk_div_counter;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:134:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:135:9
		if (!resetb)
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:136:13
			clk_div_counter <= 0;
		else
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:138:13
			clk_div_counter <= clk_div_counter + 1;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:142:5
	assign uart_tx_mon = clk_div_counter[20];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:153:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:154:9
	assign resetb = ~btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:169:5
	// removed localparam type fpga_template_pkg_rb_sys_cfg_wire_t
	wire [42:0] sys_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:170:5
	assign sys_cfg[40] = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:172:5
	// removed localparam type fpga_template_pkg_rb_dsp_cfg_wire_t
	wire [7:0] dsp_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:177:5
	wire [7:0] rb_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:178:5
	wire [7:0] rb_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:179:5
	wire [7:0] rb_data_read_from_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:180:5
	wire rb_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:181:5
	wire rb_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:182:5
	wire [1:0] rb_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:185:5
	wire [7:0] i2c_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:186:5
	wire [7:0] i2c_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:187:5
	wire i2c_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:188:5
	wire i2c_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:189:5
	wire [1:0] i2c_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:192:5
	wire [7:0] uart_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:193:5
	wire [7:0] uart_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:194:5
	wire uart_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:195:5
	wire uart_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:196:5
	wire [1:0] uart_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:197:5
	wire [7:0] uart_debug_out;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:198:5
	wire [1:0] uart_tx_state_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:201:5
	reg debug_send;
	wire debug_uart_send;
	assign debug_uart_send = debug_send;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:202:5
	reg [7:0] debug_byte;
	wire debug_uart_data;
	assign debug_uart_data = debug_byte;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:223:5
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:253:5
	assign rb_address = uart_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:254:5
	assign rb_data_write_to_reg = uart_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:255:5
	assign rb_reg_en = uart_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:256:5
	assign rb_write_en = uart_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:257:5
	assign rb_streamSt_mon = uart_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:261:5
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:276:5
	wire pwm_out;
	pwm pwm_inst(
		.clock_in(clk),
		.reset(!resetb),
		.duty_cycle(sys_cfg[39-:8]),
		.pwm_out(pwm_out)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:288:5
	reg [2:0] btn_s2_sync;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:289:5
	reg btn_s2_prev;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:290:5
	wire btn_s2_edge;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:292:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:293:9
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:294:13
			btn_s2_sync <= 3'b000;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:295:13
			btn_s2_prev <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:297:13
			btn_s2_sync <= {btn_s2_sync[1:0], btn_s2};
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:298:13
			btn_s2_prev <= btn_s2_sync[2];
		end
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:302:5
	assign btn_s2_edge = btn_s2_sync[2] & ~btn_s2_prev;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:305:5
	reg [3:0] debug_state;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:306:5
	reg [15:0] debug_counter;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:307:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:308:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:309:5
	reg debug_active;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:311:5
	localparam DEBUG_IDLE = 4'h0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:312:5
	localparam DEBUG_START = 4'h1;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:313:5
	localparam DEBUG_SEND = 4'h2;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:314:5
	localparam DEBUG_WAIT = 4'h3;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:317:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:318:9
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:320:13
			debug_state <= DEBUG_IDLE;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:321:13
			debug_counter <= 16'h0000;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:322:13
			debug_byte <= 8'h00;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:323:13
			debug_send <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:324:13
			debug_active <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:326:13
			debug_send <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:328:13
			case (debug_state)
				DEBUG_IDLE:
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:330:21
					if (!btn_s2_edge) begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:332:25
						debug_state <= DEBUG_START;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:333:25
						debug_counter <= 16'h0000;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:334:25
						debug_active <= 1'b1;
					end
				DEBUG_START:
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:339:21
					if (debug_counter < 16'h1000) begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:340:25
						debug_counter <= debug_counter + 1;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:343:25
						if (debug_counter[15:8] == 8'h00)
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:344:29
							case (debug_counter[7:0])
								8'h10: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:345:46
									debug_byte <= 8'h44;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:345:67
									debug_send <= 1'b1;
								end
								8'h20: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:346:46
									debug_byte <= 8'h42;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:346:67
									debug_send <= 1'b1;
								end
								8'h30: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:347:46
									debug_byte <= 8'h47;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:347:67
									debug_send <= 1'b1;
								end
								8'h40: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:348:46
									debug_byte <= 8'h3a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:348:67
									debug_send <= 1'b1;
								end
								8'h50: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:349:46
									debug_byte <= 8'h20;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:349:67
									debug_send <= 1'b1;
								end
								8'h60: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:350:46
									debug_byte <= 8'h00;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:350:67
									debug_send <= 1'b1;
								end
								8'h70: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:351:46
									debug_byte <= 8'h01;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:351:67
									debug_send <= 1'b1;
								end
								8'h80: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:352:46
									debug_byte <= 8'h02;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:352:67
									debug_send <= 1'b1;
								end
								8'h90: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:353:46
									debug_byte <= 8'h03;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:353:67
									debug_send <= 1'b1;
								end
								8'ha0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:354:46
									debug_byte <= 8'h04;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:354:67
									debug_send <= 1'b1;
								end
								8'hb0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:355:46
									debug_byte <= 8'h05;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:355:67
									debug_send <= 1'b1;
								end
								8'hc0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:356:46
									debug_byte <= 8'h06;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:356:67
									debug_send <= 1'b1;
								end
								8'hd0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:357:46
									debug_byte <= 8'h07;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:357:67
									debug_send <= 1'b1;
								end
								8'he0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:358:46
									debug_byte <= 8'h08;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:358:67
									debug_send <= 1'b1;
								end
								8'hf0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:359:46
									debug_byte <= 8'h09;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:359:67
									debug_send <= 1'b1;
								end
								default:
									;
							endcase
						else if (debug_counter[15:8] == 8'h01)
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:365:29
							case (debug_counter[7:0])
								8'h00: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:366:46
									debug_byte <= 8'h0a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:366:67
									debug_send <= 1'b1;
								end
								8'h10: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:367:46
									debug_byte <= 8'h0b;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:367:67
									debug_send <= 1'b1;
								end
								8'h20: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:368:46
									debug_byte <= 8'h0c;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:368:67
									debug_send <= 1'b1;
								end
								8'h30: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:369:46
									debug_byte <= 8'h0d;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:369:67
									debug_send <= 1'b1;
								end
								8'h40: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:370:46
									debug_byte <= 8'h0e;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:370:67
									debug_send <= 1'b1;
								end
								8'h50: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:371:46
									debug_byte <= 8'h0f;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:371:67
									debug_send <= 1'b1;
								end
								8'h60: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:372:46
									debug_byte <= 8'h0d;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:372:67
									debug_send <= 1'b1;
								end
								8'h70: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:373:46
									debug_byte <= 8'h0a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:373:67
									debug_send <= 1'b1;
								end
								8'h80: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:375:37
									debug_state <= DEBUG_IDLE;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:376:37
									debug_active <= 1'b0;
								end
								default:
									;
							endcase
						else begin
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:384:29
							debug_state <= DEBUG_IDLE;
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:385:29
							debug_active <= 1'b0;
						end
					end
					else begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:389:25
						debug_state <= DEBUG_IDLE;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:390:25
						debug_active <= 1'b0;
					end
			endcase
		end
endmodule
