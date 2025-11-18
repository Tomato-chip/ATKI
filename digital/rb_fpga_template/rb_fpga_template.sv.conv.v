// removed package "fpga_template_pkg"
// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:6:1
// removed ["import fpga_template_pkg::*;"]
module rb_fpga_template (
	clk,
	resetb,
	address,
	data_write_in,
	data_read_out,
	reg_en,
	write_en,
	sys_cfg,
	dsp_cfg,
	sampler_cfg
);
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:9:13
	parameter ADR_BITS = 8;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:12:2
	input wire clk;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:13:2
	input wire resetb;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:14:2
	input wire [ADR_BITS - 1:0] address;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:15:2
	input wire [7:0] data_write_in;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:16:2
	output reg [7:0] data_read_out;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:17:2
	input wire reg_en;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:18:2
	input wire write_en;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:20:2
	// removed localparam type fpga_template_pkg_rb_sys_cfg_wire_t
	inout wire [42:0] sys_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:21:2
	// removed localparam type fpga_template_pkg_rb_dsp_cfg_wire_t
	inout wire [7:0] dsp_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:22:2
	// removed localparam type fpga_template_pkg_rb_sampler_cfg_wire_t
	inout wire [26:0] sampler_cfg;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:28:1
	reg reg__sys_cfg__enable_stuf;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:29:1
	reg reg__sys_cfg__enable_other;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:30:1
	reg [7:0] reg__sys_cfg__pwm_duty;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:31:1
	reg [7:0] reg__sys_cfg__debug_led;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:32:1
	reg [7:0] reg__sys_cfg__debug_data0;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:33:1
	reg [7:0] reg__sys_cfg__debug_data1;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:34:1
	reg [7:0] reg__sys_cfg__debug_data2;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:37:1
	reg reg__dsp_cfg__bypass_enable;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:38:1
	reg reg__dsp_cfg__dc_filter_enable;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:39:1
	reg reg__dsp_cfg__bp_filter_enable;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:40:1
	reg reg__dsp_cfg__dec_filter_enable;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:41:1
	reg reg__dsp_cfg__pli_filter_enable;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:42:1
	reg reg__dsp_cfg__placeholder1;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:43:1
	reg reg__dsp_cfg__placeholder2;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:44:1
	reg reg__dsp_cfg__placeholder3;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:47:1
	reg reg__sampler_cfg__sampler_start;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:48:1
	reg reg__sampler_cfg__debug_ram;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:49:1
	reg [7:0] reg__sampler_cfg__debug_ram_add;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:50:1
	reg [7:0] reg__sampler_cfg__debug_ram_value0;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:51:1
	reg [7:0] reg__sampler_cfg__debug_ram_value1;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:52:1
	reg reg__sampler_cfg__sd_input_sel;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:54:1
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:56:3
		if (resetb == 0) begin
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:60:5
			reg__sys_cfg__enable_stuf <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:61:5
			reg__sys_cfg__enable_other <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:62:5
			reg__sys_cfg__pwm_duty <= 8'b10000101;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:63:5
			reg__sys_cfg__debug_led <= 8'b00000010;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:64:5
			reg__sys_cfg__debug_data0 <= 8'b00000000;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:65:5
			reg__sys_cfg__debug_data1 <= 8'b00000001;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:66:5
			reg__sys_cfg__debug_data2 <= 8'b00000010;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:69:5
			reg__dsp_cfg__bypass_enable <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:70:5
			reg__dsp_cfg__dc_filter_enable <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:71:5
			reg__dsp_cfg__bp_filter_enable <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:72:5
			reg__dsp_cfg__dec_filter_enable <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:73:5
			reg__dsp_cfg__pli_filter_enable <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:74:5
			reg__dsp_cfg__placeholder1 <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:75:5
			reg__dsp_cfg__placeholder2 <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:76:5
			reg__dsp_cfg__placeholder3 <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:79:5
			reg__sampler_cfg__sampler_start <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:80:5
			reg__sampler_cfg__debug_ram <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:81:5
			reg__sampler_cfg__debug_ram_add <= 8'b00000000;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:82:5
			reg__sampler_cfg__debug_ram_value0 <= 8'b00000000;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:83:5
			reg__sampler_cfg__debug_ram_value1 <= 8'b00000000;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:84:5
			reg__sampler_cfg__sd_input_sel <= 1'b0;
		end
		else
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:88:5
			if (write_en)
				// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:90:7
				case (address)
					0: begin
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:92:15
						reg__sys_cfg__enable_stuf <= data_write_in[0:0];
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:93:15
						reg__sys_cfg__enable_other <= data_write_in[1:1];
					end
					1:
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:95:15
						reg__sys_cfg__pwm_duty <= data_write_in[7:0];
					2:
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:97:15
						reg__sys_cfg__debug_led <= data_write_in[7:0];
					4:
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:99:15
						reg__sys_cfg__debug_data0 <= data_write_in[7:0];
					5:
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:101:15
						reg__sys_cfg__debug_data1 <= data_write_in[7:0];
					6:
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:103:15
						reg__sys_cfg__debug_data2 <= data_write_in[7:0];
					32:
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:105:15
						reg__sampler_cfg__sampler_start <= data_write_in[0:0];
					33:
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:107:15
						reg__sampler_cfg__debug_ram <= data_write_in[0:0];
					34:
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:109:15
						reg__sampler_cfg__debug_ram_add <= data_write_in[7:0];
					35:
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:111:15
						reg__sampler_cfg__debug_ram_value0 <= data_write_in[7:0];
					36:
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:113:15
						reg__sampler_cfg__debug_ram_value1 <= data_write_in[7:0];
					37:
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:115:15
						reg__sampler_cfg__sd_input_sel <= data_write_in[0:0];
					64: begin
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:118:15
						reg__dsp_cfg__bypass_enable <= data_write_in[0:0];
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:119:15
						reg__dsp_cfg__dc_filter_enable <= data_write_in[1:1];
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:120:15
						reg__dsp_cfg__bp_filter_enable <= data_write_in[2:2];
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:121:15
						reg__dsp_cfg__dec_filter_enable <= data_write_in[3:3];
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:122:15
						reg__dsp_cfg__pli_filter_enable <= data_write_in[4:4];
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:123:15
						reg__dsp_cfg__placeholder1 <= data_write_in[5:5];
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:124:15
						reg__dsp_cfg__placeholder2 <= data_write_in[6:6];
						// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:125:15
						reg__dsp_cfg__placeholder3 <= data_write_in[7:7];
					end
				endcase
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:132:1
	always @(posedge clk)
		// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:134:3
		if (resetb == 0)
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:135:5
			data_read_out <= 8'b00000000;
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:138:5
			data_read_out <= 8'b00000000;
			// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:139:5
			case (address)
				0: begin
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:141:15
					data_read_out[0:0] <= reg__sys_cfg__enable_stuf;
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:142:15
					data_read_out[1:1] <= reg__sys_cfg__enable_other;
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:143:15
					data_read_out[2:2] <= sys_cfg[40];
				end
				1:
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:145:15
					data_read_out[7:0] <= reg__sys_cfg__pwm_duty;
				2:
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:147:15
					data_read_out[7:0] <= reg__sys_cfg__debug_led;
				4:
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:149:15
					data_read_out[7:0] <= reg__sys_cfg__debug_data0;
				5:
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:151:15
					data_read_out[7:0] <= reg__sys_cfg__debug_data1;
				6:
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:153:15
					data_read_out[7:0] <= reg__sys_cfg__debug_data2;
				32:
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:155:15
					data_read_out[0:0] <= reg__sampler_cfg__sampler_start;
				33:
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:157:15
					data_read_out[0:0] <= reg__sampler_cfg__debug_ram;
				34:
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:159:15
					data_read_out[7:0] <= reg__sampler_cfg__debug_ram_add;
				35:
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:161:15
					data_read_out[7:0] <= reg__sampler_cfg__debug_ram_value0;
				36:
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:163:15
					data_read_out[7:0] <= reg__sampler_cfg__debug_ram_value1;
				37:
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:165:15
					data_read_out[0:0] <= reg__sampler_cfg__sd_input_sel;
				64: begin
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:168:15
					data_read_out[0:0] <= reg__dsp_cfg__bypass_enable;
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:169:15
					data_read_out[1:1] <= reg__dsp_cfg__dc_filter_enable;
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:170:15
					data_read_out[2:2] <= reg__dsp_cfg__bp_filter_enable;
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:171:15
					data_read_out[3:3] <= reg__dsp_cfg__dec_filter_enable;
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:172:15
					data_read_out[4:4] <= reg__dsp_cfg__pli_filter_enable;
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:173:15
					data_read_out[5:5] <= reg__dsp_cfg__placeholder1;
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:174:15
					data_read_out[6:6] <= reg__dsp_cfg__placeholder2;
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:175:15
					data_read_out[7:7] <= reg__dsp_cfg__placeholder3;
				end
				default:
					// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:177:17
					data_read_out <= 8'b00000000;
			endcase
		end
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:182:1
	assign sys_cfg[42] = reg__sys_cfg__enable_stuf;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:183:1
	assign sys_cfg[41] = reg__sys_cfg__enable_other;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:184:1
	assign sys_cfg[39-:8] = reg__sys_cfg__pwm_duty;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:185:1
	assign sys_cfg[31-:8] = reg__sys_cfg__debug_led;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:186:1
	assign sys_cfg[23-:8] = reg__sys_cfg__debug_data0;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:187:1
	assign sys_cfg[15-:8] = reg__sys_cfg__debug_data1;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:188:1
	assign sys_cfg[7-:8] = reg__sys_cfg__debug_data2;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:189:1
	assign dsp_cfg[7] = reg__dsp_cfg__bypass_enable;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:190:1
	assign dsp_cfg[6] = reg__dsp_cfg__dc_filter_enable;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:191:1
	assign dsp_cfg[5] = reg__dsp_cfg__bp_filter_enable;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:192:1
	assign dsp_cfg[4] = reg__dsp_cfg__dec_filter_enable;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:193:1
	assign dsp_cfg[3] = reg__dsp_cfg__pli_filter_enable;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:194:1
	assign dsp_cfg[2] = reg__dsp_cfg__placeholder1;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:195:1
	assign dsp_cfg[1] = reg__dsp_cfg__placeholder2;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:196:1
	assign dsp_cfg[0] = reg__dsp_cfg__placeholder3;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:197:1
	assign sampler_cfg[26] = reg__sampler_cfg__sampler_start;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:198:1
	assign sampler_cfg[25] = reg__sampler_cfg__debug_ram;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:199:1
	assign sampler_cfg[24-:8] = reg__sampler_cfg__debug_ram_add;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:200:1
	assign sampler_cfg[16-:8] = reg__sampler_cfg__debug_ram_value0;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:201:1
	assign sampler_cfg[8-:8] = reg__sampler_cfg__debug_ram_value1;
	// Trace: /home/tomato-chip/ATKI/digital/rb_fpga_template/rb_fpga_template.sv:202:1
	assign sampler_cfg[0] = reg__sampler_cfg__sd_input_sel;
endmodule
