// removed package "fpga_template_pkg"
module i2s_transmit_24 (
	clk_i,
	rst_ni,
	sck_i,
	ws_i,
	ram_data_i,
	ram_valid_i,
	ram_ready_o,
	buffer_ready_i,
	sd_o,
	ws_o,
	debug_state_transmitting,
	debug_request_sample
);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:12:3
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:13:3
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:14:3
	input wire sck_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:15:3
	input wire ws_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:18:3
	input wire signed [23:0] ram_data_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:19:3
	input wire ram_valid_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:20:3
	output wire ram_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:21:3
	input wire buffer_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:23:3
	output reg sd_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:24:3
	output wire ws_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:27:3
	output wire debug_state_transmitting;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:28:3
	output wire debug_request_sample;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:32:3
	reg sck_d;
	reg ws_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:33:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:34:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:35:7
			sck_d <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:36:7
			ws_d <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:38:7
			sck_d <= sck_i;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:39:7
			ws_d <= ws_i;
		end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:42:3
	wire sck_rise = ~sck_d & sck_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:43:3
	wire ws_edge = ws_d != ws_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:46:3
	reg [24:0] shift25_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:47:3
	reg [5:0] cnt_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:50:3
	reg signed [23:0] sample_reg;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:53:3
	// removed localparam type state_t
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:58:3
	reg [1:0] state_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:59:3
	reg request_sample;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:60:3
	reg sample_consumed;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:63:3
	assign ram_ready_o = (state_q == 2'd1) && sample_consumed;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:66:3
	assign debug_state_transmitting = state_q == 2'd1;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:67:3
	assign debug_request_sample = request_sample;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:70:3
	assign ws_o = ws_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:72:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:73:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:74:7
			shift25_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:75:7
			cnt_q <= 6'd0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:76:7
			sample_reg <= 24'h000000;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:77:7
			sd_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:78:7
			state_q <= 2'd0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:79:7
			request_sample <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:80:7
			sample_consumed <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:84:7
			request_sample <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:87:7
			case (state_q)
				2'd0:
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:90:11
					if (buffer_ready_i) begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:91:13
						state_q <= 2'd1;
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:92:13
						sample_consumed <= 1'b1;
					end
				2'd1:
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:98:11
					if (!ram_valid_i && ws_edge) begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:100:13
						state_q <= 2'd0;
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:101:13
						sample_consumed <= 1'b0;
					end
			endcase
			if (ram_valid_i && ram_ready_o) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:108:9
				sample_reg <= ram_data_i;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:109:9
				sample_consumed <= 1'b0;
			end
			if (ws_edge) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:114:11
				cnt_q <= 6'd0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:115:11
				sd_o <= 1'b0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:118:11
				shift25_q <= {1'b0, sample_reg};
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:121:11
				if (state_q == 2'd1)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:122:13
					sample_consumed <= 1'b1;
			end
			else if (sck_rise) begin
				begin
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:126:9
					if (cnt_q < 6'd25) begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:128:11
						sd_o <= shift25_q[24];
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:129:11
						shift25_q <= {shift25_q[23:0], 1'b0};
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:130:11
						cnt_q <= cnt_q + 6'd1;
					end
					else
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:133:11
						sd_o <= 1'b0;
				end
			end
		end
endmodule
