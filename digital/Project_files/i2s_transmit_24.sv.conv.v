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
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:26:3
	output wire debug_state_transmitting;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:27:3
	output wire debug_request_sample;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:31:3
	reg sck_d;
	reg ws_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:32:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:33:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:34:7
			sck_d <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:35:7
			ws_d <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:37:7
			sck_d <= sck_i;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:38:7
			ws_d <= ws_i;
		end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:41:3
	wire sck_rise = ~sck_d & sck_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:42:3
	wire ws_edge = ws_d != ws_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:45:3
	reg [24:0] shift25_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:46:3
	reg [5:0] cnt_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:49:3
	reg signed [23:0] sample_reg;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:52:3
	// removed localparam type state_t
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:57:3
	reg [1:0] state_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:58:3
	reg request_sample;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:61:3
	assign ram_ready_o = request_sample;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:64:3
	assign debug_state_transmitting = state_q == 2'd1;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:65:3
	assign debug_request_sample = request_sample;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:67:3
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:68:5
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:69:7
			shift25_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:70:7
			cnt_q <= 6'd0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:71:7
			sample_reg <= 24'h000000;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:72:7
			sd_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:73:7
			state_q <= 2'd0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:74:7
			request_sample <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:78:7
			request_sample <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:81:7
			case (state_q)
				2'd0:
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:84:11
					if (buffer_ready_i) begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:85:13
						state_q <= 2'd1;
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:86:13
						request_sample <= 1'b1;
					end
				2'd1:
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:92:11
					if (!ram_valid_i && ws_edge)
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:94:13
						state_q <= 2'd0;
			endcase
			if (ram_valid_i && request_sample)
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:101:9
				sample_reg <= ram_data_i;
			if (ws_edge) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:106:11
				cnt_q <= 6'd0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:107:11
				shift25_q <= {1'b0, sample_reg};
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:108:11
				sd_o <= 1'b0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:111:11
				if (state_q == 2'd1)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:112:13
					request_sample <= 1'b1;
			end
			else if (sck_rise) begin
				begin
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:116:9
					if (cnt_q < 6'd25) begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:118:11
						sd_o <= shift25_q[24];
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:119:11
						shift25_q <= {shift25_q[23:0], 1'b0};
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:120:11
						cnt_q <= cnt_q + 6'd1;
					end
					else
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/i2s_transmit_24.sv:123:11
						sd_o <= 1'b0;
				end
			end
		end
endmodule
