// removed package "fpga_template_pkg"
module vu_meter_6led (
	clk_i,
	rst_ni,
	ram_read_data_i,
	ram_read_valid_i,
	ram_read_ready_o,
	ram_buffer_ready_i,
	leds_o,
	analog_out_o
);
	reg _sv2v_0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:8:13
	parameter signed [31:0] DECAY_SHIFT = 14;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:9:13
	parameter signed [31:0] SCALE_SHIFT = 2;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:12:13
	parameter [31:0] TH1 = 32'd500;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:13:13
	parameter [31:0] TH2 = 32'd2000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:14:13
	parameter [31:0] TH3 = 32'd6000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:15:13
	parameter [31:0] TH4 = 32'd15000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:16:13
	parameter [31:0] TH5 = 32'd35000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:17:13
	parameter [31:0] TH6 = 32'd70000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:20:13
	parameter signed [31:0] LED_DIV = 540000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:22:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:23:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:26:3
	input wire signed [23:0] ram_read_data_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:27:3
	input wire ram_read_valid_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:28:3
	output wire ram_read_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:30:3
	input wire ram_buffer_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:33:3
	output reg [5:0] leds_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:36:3
	output reg analog_out_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:44:3
	// removed localparam type state_t
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:50:3
	reg [1:0] state_q;
	reg [1:0] state_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:53:3
	reg signed [23:0] sample_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:54:3
	reg [23:0] magnitude;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:55:3
	wire sample_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:58:3
	reg [31:0] level_q;
	reg [31:0] level_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:61:3
	reg [$clog2(LED_DIV) - 1:0] refresh_counter_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:62:3
	reg led_update_tick;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:67:3
	assign sample_accepted = ram_read_valid_i && ram_read_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:68:3
	assign ram_read_ready_o = state_q == 2'd0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:73:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:74:5
		magnitude = (sample_q[23] ? ~sample_q + 24'b000000000000000000000001 : sample_q);
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:80:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:82:5
		state_d = state_q;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:83:5
		level_d = level_q;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:85:5
		case (state_q)
			2'd0:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:87:9
				if (sample_accepted)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:89:11
					state_d = 2'd1;
			2'd1: begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:95:9
				level_d = (level_q - (level_q >> DECAY_SHIFT)) + (magnitude >> SCALE_SHIFT);
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:96:9
				state_d = 2'd2;
			end
			2'd2:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:101:9
				state_d = 2'd0;
			default:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:104:16
				state_d = 2'd0;
		endcase
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:109:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:110:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:111:7
			state_q <= 2'd0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:112:7
			level_q <= 32'd0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:113:7
			sample_q <= 24'd0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:115:7
			state_q <= state_d;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:116:7
			level_q <= level_d;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:117:7
			if (sample_accepted)
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:118:9
				sample_q <= ram_read_data_i;
		end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:126:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:127:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:128:7
			refresh_counter_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:129:7
			led_update_tick <= 1'b0;
		end
		else
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:131:7
			if (refresh_counter_q == (LED_DIV - 1)) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:132:9
				refresh_counter_q <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:133:9
				led_update_tick <= 1'b1;
			end
			else begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:135:9
				refresh_counter_q <= refresh_counter_q + 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:136:9
				led_update_tick <= 1'b0;
			end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:144:3
	reg [5:0] leds_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:146:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:147:5
		leds_d[0] = level_q >= TH1;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:148:5
		leds_d[1] = level_q >= TH2;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:149:5
		leds_d[2] = level_q >= TH3;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:150:5
		leds_d[3] = level_q >= TH4;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:151:5
		leds_d[4] = level_q >= TH5;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:152:5
		leds_d[5] = level_q >= TH6;
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:156:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:157:5
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:158:7
			leds_o <= 6'b000000;
		else if (led_update_tick)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:160:7
			leds_o <= leds_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:178:3
	localparam signed [31:0] PWM_BITS = 10;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:179:3
	localparam signed [31:0] PWM_MAX = 1023;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:180:3
	localparam signed [31:0] LEVEL_MAX = 100000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:182:3
	reg [9:0] pwm_counter_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:183:3
	reg [9:0] pwm_duty_cycle;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:189:3
	wire [31:0] level_clamped;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:190:3
	assign level_clamped = (level_q > LEVEL_MAX ? LEVEL_MAX : level_q);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:195:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:198:5
		pwm_duty_cycle = level_clamped[16:7];
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:202:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:203:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:204:7
			pwm_counter_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:205:7
			analog_out_o <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:208:7
			pwm_counter_q <= pwm_counter_q + 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/vu_meter_6led_test.sv:211:7
			analog_out_o <= pwm_counter_q < pwm_duty_cycle;
		end
	initial _sv2v_0 = 0;
endmodule
