// removed package "fpga_template_pkg"
// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:4:1
// removed ["import fpga_template_pkg::*;"]
module fpga_template_top (
	clk,
	i2c_scl,
	i2c_sda,
	debug_led_pin,
	btn_s1_resetb,
	btn_s2,
	i2s_sck,
	i2s_ws,
	frame_start
);
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:7:5
	input clk;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:9:5
	input i2c_scl;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:10:5
	inout i2c_sda;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:24:5
	output wire [5:0] debug_led_pin;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:25:5
	input btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:26:5
	input btn_s2;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:29:5
	output wire i2s_sck;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:30:5
	output wire i2s_ws;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:31:5
	output wire frame_start;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:47:5
	wire resetb;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:48:5
	assign resetb = ~btn_s1_resetb;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:55:5
	// removed localparam type fpga_template_pkg_rb_sys_cfg_wire_t
	wire [42:0] sys_cfg;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:56:5
	assign sys_cfg[40] = 1'b0;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:61:5
	wire [7:0] rb_address;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:62:5
	wire [7:0] rb_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:63:5
	wire [7:0] rb_data_read_from_reg;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:64:5
	wire rb_reg_en;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:65:5
	wire rb_write_en;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:66:5
	wire [1:0] rb_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:69:5
	wire [7:0] i2c_address;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:70:5
	wire [7:0] i2c_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:71:5
	wire i2c_reg_en;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:72:5
	wire i2c_write_en;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:73:5
	wire [1:0] i2c_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:76:5
	wire [7:0] uart_address;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:77:5
	wire [7:0] uart_data_write_to_reg;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:78:5
	wire uart_reg_en;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:79:5
	wire uart_write_en;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:80:5
	wire [1:0] uart_streamSt_mon;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:81:5
	wire [7:0] uart_debug_out;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:84:5
	reg debug_send;
	wire debug_uart_send;
	assign debug_uart_send = debug_send;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:85:5
	reg [7:0] debug_byte;
	wire debug_uart_data;
	assign debug_uart_data = debug_byte;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:90:5
	i2c_if i2c_inst(
		.clk(clk),
		.resetb(resetb),
		.sda(i2c_sda),
		.scl(i2c_scl),
		.address(i2c_address),
		.data_write_to_reg(i2c_data_write_to_reg),
		.data_read_from_reg(rb_data_read_from_reg),
		.reg_en(i2c_reg_en),
		.write_en(i2c_write_en),
		.streamSt_mon(i2c_streamSt_mon)
	);
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:144:5
	rb_fpga_template rb_fpga_template_inst(
		.clk(clk),
		.resetb(resetb),
		.address(rb_address),
		.data_write_in(rb_data_write_to_reg),
		.data_read_out(rb_data_read_from_reg),
		.write_en(rb_write_en),
		.sys_cfg(sys_cfg)
	);
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:170:5
	i2s_clock_gen u_i2s_clocks(
		.clk_i(clk),
		.rst_ni(resetb),
		.sck_o(i2s_sck),
		.ws_o(i2s_ws),
		.frame_start_o(frame_start)
	);
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:186:5
	reg [2:0] btn_s2_sync;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:187:5
	reg btn_s2_prev;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:188:5
	wire btn_s2_edge;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:190:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:191:9
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:192:13
			btn_s2_sync <= 3'b000;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:193:13
			btn_s2_prev <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:195:13
			btn_s2_sync <= {btn_s2_sync[1:0], btn_s2};
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:196:13
			btn_s2_prev <= btn_s2_sync[2];
		end
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:200:5
	assign btn_s2_edge = btn_s2_sync[2] & ~btn_s2_prev;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:203:5
	reg [3:0] debug_state;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:204:5
	reg [15:0] debug_counter;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:205:5
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:206:5
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:207:5
	reg debug_active;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:209:5
	localparam DEBUG_IDLE = 4'h0;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:210:5
	localparam DEBUG_START = 4'h1;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:211:5
	localparam DEBUG_SEND = 4'h2;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:212:5
	localparam DEBUG_WAIT = 4'h3;
	// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:215:5
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:216:9
		if (!resetb) begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:218:13
			debug_state <= DEBUG_IDLE;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:219:13
			debug_counter <= 16'h0000;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:220:13
			debug_byte <= 8'h00;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:221:13
			debug_send <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:222:13
			debug_active <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:224:13
			debug_send <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:226:13
			case (debug_state)
				DEBUG_IDLE:
					// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:228:21
					if (!btn_s2_edge) begin
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:230:25
						debug_state <= DEBUG_START;
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:231:25
						debug_counter <= 16'h0000;
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:232:25
						debug_active <= 1'b1;
					end
				DEBUG_START:
					// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:237:21
					if (debug_counter < 16'h1000) begin
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:238:25
						debug_counter <= debug_counter + 1;
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:241:25
						if (debug_counter[15:8] == 8'h00)
							// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:242:29
							case (debug_counter[7:0])
								8'h10: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:243:46
									debug_byte <= 8'h44;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:243:67
									debug_send <= 1'b1;
								end
								8'h20: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:244:46
									debug_byte <= 8'h42;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:244:67
									debug_send <= 1'b1;
								end
								8'h30: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:245:46
									debug_byte <= 8'h47;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:245:67
									debug_send <= 1'b1;
								end
								8'h40: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:246:46
									debug_byte <= 8'h3a;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:246:67
									debug_send <= 1'b1;
								end
								8'h50: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:247:46
									debug_byte <= 8'h20;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:247:67
									debug_send <= 1'b1;
								end
								8'h60: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:248:46
									debug_byte <= 8'h00;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:248:67
									debug_send <= 1'b1;
								end
								8'h70: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:249:46
									debug_byte <= 8'h01;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:249:67
									debug_send <= 1'b1;
								end
								8'h80: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:250:46
									debug_byte <= 8'h02;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:250:67
									debug_send <= 1'b1;
								end
								8'h90: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:251:46
									debug_byte <= 8'h03;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:251:67
									debug_send <= 1'b1;
								end
								8'ha0: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:252:46
									debug_byte <= 8'h04;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:252:67
									debug_send <= 1'b1;
								end
								8'hb0: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:253:46
									debug_byte <= 8'h05;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:253:67
									debug_send <= 1'b1;
								end
								8'hc0: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:254:46
									debug_byte <= 8'h06;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:254:67
									debug_send <= 1'b1;
								end
								8'hd0: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:255:46
									debug_byte <= 8'h07;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:255:67
									debug_send <= 1'b1;
								end
								8'he0: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:256:46
									debug_byte <= 8'h08;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:256:67
									debug_send <= 1'b1;
								end
								8'hf0: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:257:46
									debug_byte <= 8'h09;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:257:67
									debug_send <= 1'b1;
								end
								default:
									;
							endcase
						else if (debug_counter[15:8] == 8'h01)
							// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:263:29
							case (debug_counter[7:0])
								8'h00: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:264:46
									debug_byte <= 8'h0a;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:264:67
									debug_send <= 1'b1;
								end
								8'h10: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:265:46
									debug_byte <= 8'h0b;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:265:67
									debug_send <= 1'b1;
								end
								8'h20: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:266:46
									debug_byte <= 8'h0c;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:266:67
									debug_send <= 1'b1;
								end
								8'h30: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:267:46
									debug_byte <= 8'h0d;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:267:67
									debug_send <= 1'b1;
								end
								8'h40: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:268:46
									debug_byte <= 8'h0e;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:268:67
									debug_send <= 1'b1;
								end
								8'h50: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:269:46
									debug_byte <= 8'h0f;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:269:67
									debug_send <= 1'b1;
								end
								8'h60: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:270:46
									debug_byte <= 8'h0d;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:270:67
									debug_send <= 1'b1;
								end
								8'h70: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:271:46
									debug_byte <= 8'h0a;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:271:67
									debug_send <= 1'b1;
								end
								8'h80: begin
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:273:37
									debug_state <= DEBUG_IDLE;
									// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:274:37
									debug_active <= 1'b0;
								end
								default:
									;
							endcase
						else begin
							// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:282:29
							debug_state <= DEBUG_IDLE;
							// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:283:29
							debug_active <= 1'b0;
						end
					end
					else begin
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:287:25
						debug_state <= DEBUG_IDLE;
						// Trace: /home/tomato-chip/ATKI/fpga_template/digital/fpga_template/fpga_template.sv:288:25
						debug_active <= 1'b0;
					end
			endcase
		end
endmodule
