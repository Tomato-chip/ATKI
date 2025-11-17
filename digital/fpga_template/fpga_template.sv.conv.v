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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:45:5
	assign sampler_cfg.chanel0_lsb = debug_sample_l[7:0];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:46:5
	assign sampler_cfg.chanel1_lsb = debug_sample_l[15:8];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:47:5
	assign sampler_cfg.chanel2_lsb = debug_sample_l[23:16];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:71:5
	wire signed [23:0] sample_left;
	wire signed [23:0] sample_right;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:72:5
	wire mic_sd_0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:77:9
	wire resetb;
	pcm_rom u_pcm_rom(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_i(i2s_sck),
		.ws_i(i2s_ws),
		.sd_o(mic_sd_0)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:87:9
	wire sample_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:88:9
	wire signed [35:0] data_ram_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:89:9
	wire read_valid;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:90:9
	wire read_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:91:9
	wire buffer_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:94:9
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:105:9
	assign buffer_full = sample_ready;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:107:9
	wire ram_debug_leds;
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:126:9
	wire signed [17:0] fft_data_real_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:127:9
	wire signed [17:0] fft_data_imag_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:128:9
	wire fft_valid_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:129:9
	reg fft_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:130:9
	wire fft_busy_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:133:9
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:151:9
	wire fft_busy;
	assign fft_busy = fft_busy_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:152:9
	wire fft_output_valid;
	assign fft_output_valid = fft_valid_o;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:155:9
	reg [7:0] current_bin;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:156:9
	reg [47:0] max_magnitude;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:157:9
	reg [7:0] peak_bin;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:158:9
	wire [5:0] fft_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:160:9
	always @(posedge clk or negedge resetb)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:161:13
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:162:17
			current_bin <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:163:17
			max_magnitude <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:164:17
			peak_bin <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:165:17
			fft_ready_i <= 1;
		end
		else
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:167:17
			if (fft_valid_o && fft_ready_i) begin : sv2v_autoblock_1
				// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:169:21
				reg [47:0] mag_sq;
				// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:170:21
				mag_sq = (fft_data_real_o * fft_data_real_o) + (fft_data_imag_o * fft_data_imag_o);
				// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:174:21
				if (current_bin < 128) begin
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:175:25
					if (mag_sq > max_magnitude) begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:176:29
						max_magnitude <= mag_sq;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:177:29
						peak_bin <= current_bin;
					end
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:179:25
					current_bin <= current_bin + 1;
				end
				else begin
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:182:25
					current_bin <= 0;
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:183:25
					max_magnitude <= 0;
				end
			end
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:190:9
	assign fft_debug_leds = peak_bin[7:2];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:193:9
	wire vu_debug_leds;
	assign vu_debug_leds = fft_debug_leds;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:196:9
	wire vu_analog_out;
	assign vu_analog_out = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:203:9
	i2s_clock_gen u_i2s_clock(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_o(i2s_sck),
		.ws_o(i2s_ws),
		.frame_start_o()
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:217:5
	assign uart_rx_mon = uart_rx;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:218:5
	wire debug_rx_data_valid;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:221:5
	reg [20:0] clk_div_counter;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:222:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:223:9
		if (!resetb)
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:224:13
			clk_div_counter <= 0;
		else
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:226:13
			clk_div_counter <= clk_div_counter + 1;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:230:5
	assign uart_tx_mon = clk_div_counter[20];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:241:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:242:9
	assign resetb = ~btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:257:5
	// removed localparam type fpga_template_pkg_rb_sys_cfg_wire_t
	wire [42:0] sys_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:258:5
	assign sys_cfg[40] = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:260:5
	// removed localparam type fpga_template_pkg_rb_dsp_cfg_wire_t
	wire [7:0] dsp_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:265:5
	wire [7:0] rb_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:266:5
	wire [7:0] rb_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:267:5
	wire [7:0] rb_data_read_from_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:268:5
	wire rb_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:269:5
	wire rb_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:270:5
	wire [1:0] rb_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:273:5
	wire [7:0] i2c_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:274:5
	wire [7:0] i2c_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:275:5
	wire i2c_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:276:5
	wire i2c_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:277:5
	wire [1:0] i2c_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:280:5
	wire [7:0] uart_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:281:5
	wire [7:0] uart_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:282:5
	wire uart_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:283:5
	wire uart_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:284:5
	wire [1:0] uart_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:285:5
	wire [7:0] uart_debug_out;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:286:5
	wire [1:0] uart_tx_state_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:289:5
	reg debug_send;
	wire debug_uart_send;
	assign debug_uart_send = debug_send;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:290:5
	reg [7:0] debug_byte;
	wire debug_uart_data;
	assign debug_uart_data = debug_byte;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:311:5
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:341:5
	assign rb_address = uart_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:342:5
	assign rb_data_write_to_reg = uart_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:343:5
	assign rb_reg_en = uart_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:344:5
	assign rb_write_en = uart_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:345:5
	assign rb_streamSt_mon = uart_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:349:5
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:376:5
	reg [2:0] btn_s2_sync;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:377:5
	reg btn_s2_prev;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:378:5
	wire btn_s2_edge;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:380:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:381:9
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:382:13
			btn_s2_sync <= 3'b000;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:383:13
			btn_s2_prev <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:385:13
			btn_s2_sync <= {btn_s2_sync[1:0], btn_s2};
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:386:13
			btn_s2_prev <= btn_s2_sync[2];
		end
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:390:5
	assign btn_s2_edge = btn_s2_sync[2] & ~btn_s2_prev;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:393:5
	reg [3:0] debug_state;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:394:5
	reg [15:0] debug_counter;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:395:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:396:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:397:5
	reg debug_active;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:399:5
	localparam DEBUG_IDLE = 4'h0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:400:5
	localparam DEBUG_START = 4'h1;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:401:5
	localparam DEBUG_SEND = 4'h2;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:402:5
	localparam DEBUG_WAIT = 4'h3;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:405:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:406:9
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:408:13
			debug_state <= DEBUG_IDLE;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:409:13
			debug_counter <= 16'h0000;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:410:13
			debug_byte <= 8'h00;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:411:13
			debug_send <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:412:13
			debug_active <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:414:13
			debug_send <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:416:13
			case (debug_state)
				DEBUG_IDLE:
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:418:21
					if (!btn_s2_edge) begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:420:25
						debug_state <= DEBUG_START;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:421:25
						debug_counter <= 16'h0000;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:422:25
						debug_active <= 1'b1;
					end
				DEBUG_START:
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:427:21
					if (debug_counter < 16'h1000) begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:428:25
						debug_counter <= debug_counter + 1;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:431:25
						if (debug_counter[15:8] == 8'h00)
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:432:29
							case (debug_counter[7:0])
								8'h10: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:433:46
									debug_byte <= 8'h44;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:433:67
									debug_send <= 1'b1;
								end
								8'h20: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:434:46
									debug_byte <= 8'h42;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:434:67
									debug_send <= 1'b1;
								end
								8'h30: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:435:46
									debug_byte <= 8'h47;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:435:67
									debug_send <= 1'b1;
								end
								8'h40: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:436:46
									debug_byte <= 8'h3a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:436:67
									debug_send <= 1'b1;
								end
								8'h50: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:437:46
									debug_byte <= 8'h20;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:437:67
									debug_send <= 1'b1;
								end
								8'h60: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:438:46
									debug_byte <= 8'h00;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:438:67
									debug_send <= 1'b1;
								end
								8'h70: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:439:46
									debug_byte <= 8'h01;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:439:67
									debug_send <= 1'b1;
								end
								8'h80: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:440:46
									debug_byte <= 8'h02;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:440:67
									debug_send <= 1'b1;
								end
								8'h90: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:441:46
									debug_byte <= 8'h03;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:441:67
									debug_send <= 1'b1;
								end
								8'ha0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:442:46
									debug_byte <= 8'h04;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:442:67
									debug_send <= 1'b1;
								end
								8'hb0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:443:46
									debug_byte <= 8'h05;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:443:67
									debug_send <= 1'b1;
								end
								8'hc0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:444:46
									debug_byte <= 8'h06;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:444:67
									debug_send <= 1'b1;
								end
								8'hd0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:445:46
									debug_byte <= 8'h07;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:445:67
									debug_send <= 1'b1;
								end
								8'he0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:446:46
									debug_byte <= 8'h08;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:446:67
									debug_send <= 1'b1;
								end
								8'hf0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:447:46
									debug_byte <= 8'h09;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:447:67
									debug_send <= 1'b1;
								end
								default:
									;
							endcase
						else if (debug_counter[15:8] == 8'h01)
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:453:29
							case (debug_counter[7:0])
								8'h00: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:454:46
									debug_byte <= 8'h0a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:454:67
									debug_send <= 1'b1;
								end
								8'h10: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:455:46
									debug_byte <= 8'h0b;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:455:67
									debug_send <= 1'b1;
								end
								8'h20: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:456:46
									debug_byte <= 8'h0c;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:456:67
									debug_send <= 1'b1;
								end
								8'h30: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:457:46
									debug_byte <= 8'h0d;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:457:67
									debug_send <= 1'b1;
								end
								8'h40: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:458:46
									debug_byte <= 8'h0e;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:458:67
									debug_send <= 1'b1;
								end
								8'h50: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:459:46
									debug_byte <= 8'h0f;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:459:67
									debug_send <= 1'b1;
								end
								8'h60: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:460:46
									debug_byte <= 8'h0d;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:460:67
									debug_send <= 1'b1;
								end
								8'h70: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:461:46
									debug_byte <= 8'h0a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:461:67
									debug_send <= 1'b1;
								end
								8'h80: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:463:37
									debug_state <= DEBUG_IDLE;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:464:37
									debug_active <= 1'b0;
								end
								default:
									;
							endcase
						else begin
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:472:29
							debug_state <= DEBUG_IDLE;
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:473:29
							debug_active <= 1'b0;
						end
					end
					else begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:477:25
						debug_state <= DEBUG_IDLE;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template.sv:478:25
						debug_active <= 1'b0;
					end
			endcase
		end
endmodule
