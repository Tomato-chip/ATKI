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
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:8:13
	parameter signed [31:0] BUFFER_DEPTH = 256;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:11:13
	parameter signed [31:0] DECAY_SHIFT = 14;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:12:13
	parameter signed [31:0] SCALE_SHIFT = 2;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:15:13
	parameter [31:0] TH1 = 32'd500;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:16:13
	parameter [31:0] TH2 = 32'd2000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:17:13
	parameter [31:0] TH3 = 32'd6000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:18:13
	parameter [31:0] TH4 = 32'd15000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:19:13
	parameter [31:0] TH5 = 32'd35000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:20:13
	parameter [31:0] TH6 = 32'd70000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:23:13
	parameter signed [31:0] LED_DIV = 540000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:25:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:26:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:29:3
	input wire signed [23:0] ram_read_data_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:30:3
	input wire ram_read_valid_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:31:3
	output wire ram_read_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:32:3
	input wire ram_buffer_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:34:3
	output reg [5:0] leds_o;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:37:3
	output reg analog_out_o;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:40:3
	output wire [5:0] debug_o;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:48:3
	// removed localparam type state_t
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:55:3
	reg [1:0] state_q;
	reg [1:0] state_d;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:58:3
	reg [$clog2(BUFFER_DEPTH):0] sample_count_q;
	reg [$clog2(BUFFER_DEPTH):0] sample_count_d;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:59:3
	wire sample_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:62:3
	reg [23:0] magnitude;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:63:3
	reg [23:0] peak_magnitude_q;
	reg [23:0] peak_magnitude_d;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:66:3
	reg [31:0] level_q;
	reg [31:0] level_d;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:69:3
	reg [$clog2(LED_DIV) - 1:0] refresh_counter_q;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:70:3
	reg led_update_tick;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:75:3
	assign sample_accepted = ram_read_valid_i && ram_read_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:76:3
	assign ram_read_ready_o = state_q == 2'd1;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:81:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:82:5
		magnitude = (ram_read_data_i[23] ? ~ram_read_data_i + 24'b000000000000000000000001 : ram_read_data_i);
	end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:88:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:90:5
		state_d = state_q;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:91:5
		level_d = level_q;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:92:5
		sample_count_d = sample_count_q;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:93:5
		peak_magnitude_d = peak_magnitude_q;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:95:5
		case (state_q)
			2'd0:
				// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:98:9
				if (ram_buffer_ready_i) begin
					// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:100:11
					state_d = 2'd1;
					// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:101:11
					sample_count_d = 1'sb0;
					// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:102:11
					peak_magnitude_d = 1'sb0;
				end
			2'd1:
				// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:108:9
				if (sample_accepted) begin
					// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:110:11
					if (magnitude > peak_magnitude_q)
						// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:111:13
						peak_magnitude_d = magnitude;
					// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:115:11
					sample_count_d = sample_count_q + 1'b1;
					if (sample_count_q >= (BUFFER_DEPTH - 1))
						// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:119:13
						state_d = 2'd2;
				end
			2'd2: begin
				// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:126:9
				level_d = (level_q - (level_q >> DECAY_SHIFT)) + (peak_magnitude_q >> SCALE_SHIFT);
				// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:127:9
				state_d = 2'd3;
			end
			2'd3:
				// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:132:9
				state_d = 2'd0;
			default:
				// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:135:16
				state_d = 2'd0;
		endcase
	end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:140:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:141:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:142:7
			state_q <= 2'd0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:143:7
			level_q <= 32'd0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:144:7
			sample_count_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:145:7
			peak_magnitude_q <= 1'sb0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:147:7
			state_q <= state_d;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:148:7
			level_q <= level_d;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:149:7
			sample_count_q <= sample_count_d;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:150:7
			peak_magnitude_q <= peak_magnitude_d;
		end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:157:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:158:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:159:7
			refresh_counter_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:160:7
			led_update_tick <= 1'b0;
		end
		else
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:162:7
			if (refresh_counter_q == (LED_DIV - 1)) begin
				// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:163:9
				refresh_counter_q <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:164:9
				led_update_tick <= 1'b1;
			end
			else begin
				// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:166:9
				refresh_counter_q <= refresh_counter_q + 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:167:9
				led_update_tick <= 1'b0;
			end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:175:3
	reg [5:0] leds_d;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:177:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:178:5
		leds_d[0] = level_q >= TH1;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:179:5
		leds_d[1] = level_q >= TH2;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:180:5
		leds_d[2] = level_q >= TH3;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:181:5
		leds_d[3] = level_q >= TH4;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:182:5
		leds_d[4] = level_q >= TH5;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:183:5
		leds_d[5] = level_q >= TH6;
	end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:187:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:188:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:189:7
			leds_o <= 6'b000000;
		else if (led_update_tick)
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:191:7
			leds_o <= leds_d;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:209:3
	localparam signed [31:0] PWM_BITS = 10;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:210:3
	localparam signed [31:0] PWM_MAX = 1023;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:211:3
	localparam signed [31:0] LEVEL_MAX = 100000;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:213:3
	reg [9:0] pwm_counter_q;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:214:3
	reg [9:0] pwm_duty_cycle;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:220:3
	wire [31:0] level_clamped;
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:221:3
	assign level_clamped = (level_q > LEVEL_MAX ? LEVEL_MAX : level_q);
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:226:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:229:5
		pwm_duty_cycle = level_clamped[16:7];
	end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:233:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:234:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:235:7
			pwm_counter_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:236:7
			analog_out_o <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:239:7
			pwm_counter_q <= pwm_counter_q + 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:242:7
			analog_out_o <= pwm_counter_q < pwm_duty_cycle;
		end
	// Trace: /home/tomato-chip/ATKI/digital/sampler/vu_meter_6led.sv:254:3
	assign debug_o = {ram_buffer_ready_i, ram_read_valid_i, ram_read_ready_o, sample_accepted, state_q[1:0]};
	initial _sv2v_0 = 0;
endmodule
