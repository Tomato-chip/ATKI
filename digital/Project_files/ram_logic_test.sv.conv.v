// removed package "fpga_template_pkg"
module ram_logic (
	clk_i,
	rst_ni,
	write_data_i,
	write_valid_i,
	write_ready_o,
	read_data_o,
	read_ready_i,
	read_valid_o,
	buffer_ready_o,
	buffer_overflow_o,
	write_count_o,
	read_count_o,
	debug_leds_o
);
	reg _sv2v_0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:36:15
	parameter [31:0] WIDTH = 36;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:37:15
	parameter [31:0] DEPTH = 16;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:38:15
	parameter [31:0] ADDR_WIDTH = $clog2(DEPTH);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:40:5
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:41:5
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:42:5
	input wire signed [WIDTH - 1:0] write_data_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:43:5
	input wire write_valid_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:44:5
	output wire write_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:45:5
	output wire signed [WIDTH - 1:0] read_data_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:46:5
	input wire read_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:47:5
	output reg read_valid_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:48:5
	output reg buffer_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:49:5
	output reg buffer_overflow_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:50:5
	output wire [ADDR_WIDTH:0] write_count_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:51:5
	output wire [ADDR_WIDTH:0] read_count_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:52:5
	output wire [5:0] debug_leds_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:60:5
	// removed localparam type buffer_state_t
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:66:5
	reg [1:0] state_q;
	reg [1:0] state_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:69:5
	reg [ADDR_WIDTH - 1:0] write_addr_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:70:5
	reg [ADDR_WIDTH - 1:0] read_addr_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:73:5
	reg [ADDR_WIDTH:0] write_count_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:74:5
	reg [ADDR_WIDTH:0] read_count_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:77:5
	reg write_buf_sel_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:78:5
	reg read_buf_sel_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:81:5
	wire write_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:82:5
	wire read_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:85:5
	reg [5:0] write_valid_count_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:86:5
	reg [5:0] read_accepted_count_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:89:5
	reg [13:0] ram0_addr;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:90:5
	reg [13:0] ram1_addr;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:91:5
	wire ram0_we;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:92:5
	wire ram1_we;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:93:5
	wire [WIDTH - 1:0] ram0_dout;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:94:5
	wire [WIDTH - 1:0] ram1_dout;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:112:5
	function automatic [(14 - ADDR_WIDTH) - 1:0] sv2v_cast_19EF5;
		input reg [(14 - ADDR_WIDTH) - 1:0] inp;
		sv2v_cast_19EF5 = inp;
	endfunction
	function automatic [13:0] format_gowin_sp_ram_address;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:112:65
		input reg [ADDR_WIDTH - 1:0] addr;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:113:9
		if (WIDTH == 32)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:114:13
			format_gowin_sp_ram_address = {4'b0000, addr, 5'b00000};
		else if (WIDTH == 16)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:116:13
			format_gowin_sp_ram_address = {2'b00, addr, 4'b0000};
		else if (WIDTH == 8)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:118:13
			format_gowin_sp_ram_address = {1'b0, addr, 5'b00000};
		else if (WIDTH == 36)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:121:13
			format_gowin_sp_ram_address = {1'b0, addr, 5'b00000};
		else if (WIDTH == 18)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:123:13
			format_gowin_sp_ram_address = {2'b00, addr, 4'b0000};
		else
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:125:13
			format_gowin_sp_ram_address = {addr, sv2v_cast_19EF5(1'sb0)};
	endfunction
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:133:5
	assign write_accepted = write_valid_i && write_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:134:5
	assign read_accepted = read_ready_i && read_valid_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:140:5
	assign write_ready_o = write_count_q < DEPTH;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:145:5
	assign write_count_o = write_count_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:146:5
	assign read_count_o = read_count_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:156:5
	assign debug_leds_o = {write_buf_sel_q, read_buf_sel_q, state_q[1:0], write_count_q >= (DEPTH / 2), read_count_q >= (DEPTH / 2)};
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:169:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:171:9
		state_d = state_q;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:173:9
		case (state_q)
			2'd0:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:176:17
				if (write_count_q == DEPTH)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:178:21
					state_d = 2'd1;
			2'd1:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:185:17
				state_d = 2'd2;
			2'd2:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:191:17
				if (write_count_q == DEPTH)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:192:21
					state_d = 2'd1;
			default:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:196:22
				state_d = 2'd0;
		endcase
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:205:5
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:206:9
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:208:13
			state_q <= 2'd0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:209:13
			write_addr_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:210:13
			read_addr_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:211:13
			write_count_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:212:13
			read_count_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:215:13
			write_buf_sel_q <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:216:13
			read_buf_sel_q <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:219:13
			buffer_ready_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:220:13
			buffer_overflow_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:221:13
			read_valid_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:224:13
			write_valid_count_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:225:13
			read_accepted_count_q <= 1'sb0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:228:13
			if (write_valid_i)
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:229:17
				write_valid_count_q <= write_valid_count_q + 1'b1;
			if (read_accepted)
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:232:17
				read_accepted_count_q <= read_accepted_count_q + 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:235:13
			state_q <= state_d;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:238:13
			buffer_ready_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:239:13
			buffer_overflow_o <= 1'b0;
			if (state_q == 2'd1) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:246:17
				buffer_ready_o <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:247:17
				read_buf_sel_q <= write_buf_sel_q;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:248:17
				write_buf_sel_q <= ~write_buf_sel_q;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:251:17
				write_addr_q <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:252:17
				write_count_q <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:253:17
				read_addr_q <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:254:17
				read_count_q <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:255:17
				read_valid_o <= 1'b1;
			end
			else begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:260:17
				if (write_accepted) begin
					begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:261:21
						if (write_count_q < DEPTH) begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:262:25
							write_addr_q <= write_addr_q + 1'b1;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:263:25
							write_count_q <= write_count_q + 1'b1;
						end
						else
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:266:25
							buffer_overflow_o <= 1'b1;
					end
				end
				if (read_accepted && (state_q == 2'd2)) begin
					begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:274:21
						if (read_count_q < (DEPTH - 1)) begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:275:25
							read_addr_q <= read_addr_q + 1'b1;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:276:25
							read_count_q <= read_count_q + 1'b1;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:277:25
							read_valid_o <= 1'b1;
						end
						else begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:280:25
							read_addr_q <= 1'sb0;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:281:25
							read_count_q <= 1'sb0;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:282:25
							read_valid_o <= 1'b0;
						end
					end
				end
				else if (state_q == 2'd2)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:286:21
					read_valid_o <= (read_count_q < DEPTH ? 1'b1 : 1'b0);
				else
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:289:21
					read_valid_o <= 1'b0;
			end
		end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:302:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:303:9
		if (write_buf_sel_q == 1'b0) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:305:13
			ram0_addr = format_gowin_sp_ram_address(write_addr_q);
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:306:13
			ram1_addr = format_gowin_sp_ram_address(read_addr_q);
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:309:13
			ram0_addr = format_gowin_sp_ram_address(read_addr_q);
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:310:13
			ram1_addr = format_gowin_sp_ram_address(write_addr_q);
		end
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:320:5
	assign ram0_we = write_accepted && (write_buf_sel_q == 1'b0);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:321:5
	assign ram1_we = write_accepted && (write_buf_sel_q == 1'b1);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:329:5
	assign read_data_o = (state_q == 2'd2 ? (read_buf_sel_q == 1'b0 ? ram0_dout : ram1_dout) : {WIDTH {1'sb0}});
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:343:5
	SP pingpong_buffer_ram0(
		.CLK(clk_i),
		.CE(1'b1),
		.OCE(1'b0),
		.RESET(1'b0),
		.WRE(ram0_we),
		.BLKSEL(3'b000),
		.AD(ram0_addr),
		.DI(write_data_i),
		.DO(ram0_dout)
	);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:354:5
	defparam pingpong_buffer_ram0.BIT_WIDTH = WIDTH;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:355:5
	defparam pingpong_buffer_ram0.READ_MODE = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:356:5
	defparam pingpong_buffer_ram0.WRITE_MODE = 2'b00;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:357:5
	defparam pingpong_buffer_ram0.BLK_SEL = 3'b000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:365:5
	SP pingpong_buffer_ram1(
		.CLK(clk_i),
		.CE(1'b1),
		.OCE(1'b0),
		.RESET(1'b0),
		.WRE(ram1_we),
		.BLKSEL(3'b000),
		.AD(ram1_addr),
		.DI(write_data_i),
		.DO(ram1_dout)
	);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:376:5
	defparam pingpong_buffer_ram1.BIT_WIDTH = WIDTH;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:377:5
	defparam pingpong_buffer_ram1.READ_MODE = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:378:5
	defparam pingpong_buffer_ram1.WRITE_MODE = 2'b00;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:379:5
	defparam pingpong_buffer_ram1.BLK_SEL = 3'b000;
	initial _sv2v_0 = 0;
endmodule
