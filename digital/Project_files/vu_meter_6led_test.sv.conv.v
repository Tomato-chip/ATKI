// removed package "fpga_template_pkg"
module vu_meter_6led (
	clk_i,
	rst_ni,
	ram_read_data_i,
	ram_read_valid_i,
	ram_read_ready_o,
	ram_buffer_ready_i,
	leds_o,
	analog_out_o,
	debug_o
);
	reg _sv2v_0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:8:13
	parameter signed [31:0] BUFFER_DEPTH = 16;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:11:13
	parameter signed [31:0] DECAY_SHIFT = 14;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:12:13
	parameter signed [31:0] SCALE_SHIFT = 2;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:15:13
	parameter [31:0] TH1 = 32'd500;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:16:13
	parameter [31:0] TH2 = 32'd2000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:17:13
	parameter [31:0] TH3 = 32'd6000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:18:13
	parameter [31:0] TH4 = 32'd15000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:19:13
	parameter [31:0] TH5 = 32'd35000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:20:13
	parameter [31:0] TH6 = 32'd70000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:23:13
	parameter signed [31:0] LED_DIV = 540000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:25:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:26:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:29:3
	input wire signed [23:0] ram_read_data_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:30:3
	input wire ram_read_valid_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:31:3
	output wire ram_read_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:33:3
	input wire ram_buffer_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:36:3
	output reg [5:0] leds_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:39:3
	output reg analog_out_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:42:3
	output wire [5:0] debug_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:50:3
	// removed localparam type state_t
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:57:3
	reg [1:0] state_q;
	reg [1:0] state_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:60:3
	reg [$clog2(BUFFER_DEPTH):0] sample_count_q;
	reg [$clog2(BUFFER_DEPTH):0] sample_count_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:61:3
	wire sample_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:64:3
	reg [23:0] magnitude;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:65:3
	reg [23:0] peak_magnitude_q;
	reg [23:0] peak_magnitude_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:68:3
	reg [31:0] level_q;
	reg [31:0] level_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:71:3
	reg [$clog2(LED_DIV) - 1:0] refresh_counter_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:72:3
	reg led_update_tick;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:77:3
	assign sample_accepted = ram_read_valid_i && ram_read_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:78:3
	assign ram_read_ready_o = state_q == 2'd1;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:83:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:84:5
		magnitude = (ram_read_data_i[23] ? ~ram_read_data_i + 24'b000000000000000000000001 : ram_read_data_i);
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:90:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:92:5
		state_d = state_q;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:93:5
		level_d = level_q;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:94:5
		sample_count_d = sample_count_q;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:95:5
		peak_magnitude_d = peak_magnitude_q;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:97:5
		case (state_q)
			2'd0:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:100:9
				if (ram_buffer_ready_i) begin
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:102:11
					state_d = 2'd1;
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:103:11
					sample_count_d = 1'sb0;
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:104:11
					peak_magnitude_d = 1'sb0;
				end
			2'd1:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:110:9
				if (sample_accepted) begin
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:112:11
					if (magnitude > peak_magnitude_q)
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:113:13
						peak_magnitude_d = magnitude;
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:117:11
					sample_count_d = sample_count_q + 1'b1;
					if (sample_count_q >= (BUFFER_DEPTH - 1))
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:121:13
						state_d = 2'd2;
				end
			2'd2: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:128:9
				level_d = (level_q - (level_q >> DECAY_SHIFT)) + (peak_magnitude_q >> SCALE_SHIFT);
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:129:9
				state_d = 2'd3;
			end
			2'd3:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:134:9
				state_d = 2'd0;
			default:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:137:16
				state_d = 2'd0;
		endcase
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:142:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:143:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:144:7
			state_q <= 2'd0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:145:7
			level_q <= 32'd0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:146:7
			sample_count_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:147:7
			peak_magnitude_q <= 1'sb0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:149:7
			state_q <= state_d;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:150:7
			level_q <= level_d;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:151:7
			sample_count_q <= sample_count_d;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:152:7
			peak_magnitude_q <= peak_magnitude_d;
		end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:159:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:160:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:161:7
			refresh_counter_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:162:7
			led_update_tick <= 1'b0;
		end
		else
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:164:7
			if (refresh_counter_q == (LED_DIV - 1)) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:165:9
				refresh_counter_q <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:166:9
				led_update_tick <= 1'b1;
			end
			else begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:168:9
				refresh_counter_q <= refresh_counter_q + 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:169:9
				led_update_tick <= 1'b0;
			end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:177:3
	reg [5:0] leds_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:179:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:180:5
		leds_d[0] = level_q >= TH1;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:181:5
		leds_d[1] = level_q >= TH2;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:182:5
		leds_d[2] = level_q >= TH3;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:183:5
		leds_d[3] = level_q >= TH4;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:184:5
		leds_d[4] = level_q >= TH5;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:185:5
		leds_d[5] = level_q >= TH6;
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:189:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:190:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:191:7
			leds_o <= 6'b000000;
		else if (led_update_tick)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:193:7
			leds_o <= leds_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:211:3
	localparam signed [31:0] PWM_BITS = 10;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:212:3
	localparam signed [31:0] PWM_MAX = 1023;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:213:3
	localparam signed [31:0] LEVEL_MAX = 100000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:215:3
	reg [9:0] pwm_counter_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:216:3
	reg [9:0] pwm_duty_cycle;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:222:3
	wire [31:0] level_clamped;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:223:3
	assign level_clamped = (level_q > LEVEL_MAX ? LEVEL_MAX : level_q);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:228:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:231:5
		pwm_duty_cycle = level_clamped[16:7];
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:235:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:236:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:237:7
			pwm_counter_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:238:7
			analog_out_o <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:241:7
			pwm_counter_q <= pwm_counter_q + 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:244:7
			analog_out_o <= pwm_counter_q < pwm_duty_cycle;
		end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:256:3
	assign debug_o = {ram_buffer_ready_i, ram_read_valid_i, ram_read_ready_o, sample_accepted, state_q[1:0]};
	initial _sv2v_0 = 0;
endmodule
