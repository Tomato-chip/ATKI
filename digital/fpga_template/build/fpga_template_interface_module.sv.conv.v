// removed package "fpga_template_pkg"
// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:1:1
// removed ["import fpga_template_pkg::*;"]
module fpga_template_comm (
	clk,
	btn_s1_resetb,
	btn_s2,
	uart_rx,
	uart_tx,
	uart_tx_mon,
	uart_rx_mon,
	sys_cfg,
	sampler_cfg,
	dsp_cfg
);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:4:5
	input wire clk;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:5:5
	input wire btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:6:5
	input wire btn_s2;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:7:5
	input wire uart_rx;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:8:5
	output wire uart_tx;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:9:5
	output wire uart_tx_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:10:5
	output wire uart_rx_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:12:5
	// removed localparam type fpga_template_pkg_rb_sys_cfg_wire_t
	output wire [42:0] sys_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:13:5
	// removed localparam type fpga_template_pkg_rb_sampler_cfg_wire_t
	output wire [24:0] sampler_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:14:5
	// removed localparam type fpga_template_pkg_rb_dsp_cfg_wire_t
	output wire [7:0] dsp_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:21:5
	assign uart_rx_mon = uart_rx;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:22:5
	wire debug_rx_data_valid;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:25:5
	reg [20:0] clk_div_counter;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:26:5
	wire resetb;
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:27:9
		if (!resetb)
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:28:13
			clk_div_counter <= 0;
		else
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:30:13
			clk_div_counter <= clk_div_counter + 1;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:34:5
	assign uart_tx_mon = clk_div_counter[20];
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:45:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:46:9
	assign resetb = ~btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:61:5
	assign sys_cfg[40] = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:66:5
	wire [7:0] rb_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:67:5
	wire [7:0] rb_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:68:5
	wire [7:0] rb_data_read_from_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:69:5
	wire rb_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:70:5
	wire rb_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:71:5
	wire [1:0] rb_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:74:5
	wire [7:0] i2c_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:75:5
	wire [7:0] i2c_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:76:5
	wire i2c_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:77:5
	wire i2c_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:78:5
	wire [1:0] i2c_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:81:5
	wire [7:0] uart_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:82:5
	wire [7:0] uart_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:83:5
	wire uart_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:84:5
	wire uart_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:85:5
	wire [1:0] uart_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:86:5
	wire [7:0] uart_debug_out;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:87:5
	wire [1:0] uart_tx_state_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:90:5
	reg debug_send;
	wire debug_uart_send;
	assign debug_uart_send = debug_send;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:91:5
	reg [7:0] debug_byte;
	wire debug_uart_data;
	assign debug_uart_data = debug_byte;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:112:5
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
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:142:5
	assign rb_address = uart_address;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:143:5
	assign rb_data_write_to_reg = uart_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:144:5
	assign rb_reg_en = uart_reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:145:5
	assign rb_write_en = uart_write_en;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:146:5
	assign rb_streamSt_mon = uart_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:150:5
	rb_fpga_template rb_fpga_template_inst(
		.clk(clk),
		.resetb(resetb),
		.address(rb_address),
		.data_write_in(rb_data_write_to_reg),
		.data_read_out(rb_data_read_from_reg),
		.reg_en(rb_reg_en),
		.write_en(rb_write_en),
		.sys_cfg(sys_cfg),
		.sampler_cfg(sampler_cfg),
		.dsp_cfg(dsp_cfg)
	);
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:168:5
	reg [2:0] btn_s2_sync;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:169:5
	reg btn_s2_prev;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:170:5
	wire btn_s2_edge;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:172:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:173:9
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:174:13
			btn_s2_sync <= 3'b000;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:175:13
			btn_s2_prev <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:177:13
			btn_s2_sync <= {btn_s2_sync[1:0], btn_s2};
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:178:13
			btn_s2_prev <= btn_s2_sync[2];
		end
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:182:5
	assign btn_s2_edge = btn_s2_sync[2] & ~btn_s2_prev;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:185:5
	reg [3:0] debug_state;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:186:5
	reg [15:0] debug_counter;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:187:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:188:5
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:189:5
	reg debug_active;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:191:5
	localparam DEBUG_IDLE = 4'h0;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:192:5
	localparam DEBUG_START = 4'h1;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:193:5
	localparam DEBUG_SEND = 4'h2;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:194:5
	localparam DEBUG_WAIT = 4'h3;
	// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:197:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:198:9
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:200:13
			debug_state <= DEBUG_IDLE;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:201:13
			debug_counter <= 16'h0000;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:202:13
			debug_byte <= 8'h00;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:203:13
			debug_send <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:204:13
			debug_active <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:206:13
			debug_send <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:208:13
			case (debug_state)
				DEBUG_IDLE:
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:210:21
					if (!btn_s2_edge) begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:212:25
						debug_state <= DEBUG_START;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:213:25
						debug_counter <= 16'h0000;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:214:25
						debug_active <= 1'b1;
					end
				DEBUG_START:
					// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:219:21
					if (debug_counter < 16'h1000) begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:220:25
						debug_counter <= debug_counter + 1;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:223:25
						if (debug_counter[15:8] == 8'h00)
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:224:29
							case (debug_counter[7:0])
								8'h10: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:225:46
									debug_byte <= 8'h44;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:225:67
									debug_send <= 1'b1;
								end
								8'h20: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:226:46
									debug_byte <= 8'h42;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:226:67
									debug_send <= 1'b1;
								end
								8'h30: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:227:46
									debug_byte <= 8'h47;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:227:67
									debug_send <= 1'b1;
								end
								8'h40: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:228:46
									debug_byte <= 8'h3a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:228:67
									debug_send <= 1'b1;
								end
								8'h50: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:229:46
									debug_byte <= 8'h20;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:229:67
									debug_send <= 1'b1;
								end
								8'h60: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:230:46
									debug_byte <= 8'h00;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:230:67
									debug_send <= 1'b1;
								end
								8'h70: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:231:46
									debug_byte <= 8'h01;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:231:67
									debug_send <= 1'b1;
								end
								8'h80: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:232:46
									debug_byte <= 8'h02;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:232:67
									debug_send <= 1'b1;
								end
								8'h90: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:233:46
									debug_byte <= 8'h03;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:233:67
									debug_send <= 1'b1;
								end
								8'ha0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:234:46
									debug_byte <= 8'h04;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:234:67
									debug_send <= 1'b1;
								end
								8'hb0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:235:46
									debug_byte <= 8'h05;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:235:67
									debug_send <= 1'b1;
								end
								8'hc0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:236:46
									debug_byte <= 8'h06;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:236:67
									debug_send <= 1'b1;
								end
								8'hd0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:237:46
									debug_byte <= 8'h07;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:237:67
									debug_send <= 1'b1;
								end
								8'he0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:238:46
									debug_byte <= 8'h08;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:238:67
									debug_send <= 1'b1;
								end
								8'hf0: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:239:46
									debug_byte <= 8'h09;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:239:67
									debug_send <= 1'b1;
								end
								default:
									;
							endcase
						else if (debug_counter[15:8] == 8'h01)
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:245:29
							case (debug_counter[7:0])
								8'h00: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:246:46
									debug_byte <= 8'h0a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:246:67
									debug_send <= 1'b1;
								end
								8'h10: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:247:46
									debug_byte <= 8'h0b;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:247:67
									debug_send <= 1'b1;
								end
								8'h20: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:248:46
									debug_byte <= 8'h0c;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:248:67
									debug_send <= 1'b1;
								end
								8'h30: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:249:46
									debug_byte <= 8'h0d;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:249:67
									debug_send <= 1'b1;
								end
								8'h40: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:250:46
									debug_byte <= 8'h0e;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:250:67
									debug_send <= 1'b1;
								end
								8'h50: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:251:46
									debug_byte <= 8'h0f;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:251:67
									debug_send <= 1'b1;
								end
								8'h60: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:252:46
									debug_byte <= 8'h0d;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:252:67
									debug_send <= 1'b1;
								end
								8'h70: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:253:46
									debug_byte <= 8'h0a;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:253:67
									debug_send <= 1'b1;
								end
								8'h80: begin
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:255:37
									debug_state <= DEBUG_IDLE;
									// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:256:37
									debug_active <= 1'b0;
								end
								default:
									;
							endcase
						else begin
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:264:29
							debug_state <= DEBUG_IDLE;
							// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:265:29
							debug_active <= 1'b0;
						end
					end
					else begin
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:269:25
						debug_state <= DEBUG_IDLE;
						// Trace: /home/tomato-chip/ATKI/digital/fpga_template/fpga_template_interface_module.sv:270:25
						debug_active <= 1'b0;
					end
			endcase
		end
endmodule
