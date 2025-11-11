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
	read_count_o
);
	reg _sv2v_0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:36:15
	parameter [31:0] WIDTH = 32;
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
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:59:5
	// removed localparam type buffer_state_t
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:65:5
	reg [1:0] state_q;
	reg [1:0] state_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:68:5
	reg [ADDR_WIDTH - 1:0] write_addr_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:69:5
	reg [ADDR_WIDTH - 1:0] read_addr_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:72:5
	reg [ADDR_WIDTH:0] write_count_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:73:5
	reg [ADDR_WIDTH:0] read_count_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:76:5
	reg write_buf_sel_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:77:5
	reg read_buf_sel_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:80:5
	wire write_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:81:5
	wire read_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:84:5
	reg [13:0] ram0_addr;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:85:5
	reg [13:0] ram1_addr;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:86:5
	wire ram0_we;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:87:5
	wire ram1_we;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:88:5
	wire [WIDTH - 1:0] ram0_dout;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:89:5
	wire [WIDTH - 1:0] ram1_dout;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:107:5
	function automatic [(14 - ADDR_WIDTH) - 1:0] sv2v_cast_19EF5;
		input reg [(14 - ADDR_WIDTH) - 1:0] inp;
		sv2v_cast_19EF5 = inp;
	endfunction
	function automatic [13:0] format_gowin_sp_ram_address;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:107:65
		input reg [ADDR_WIDTH - 1:0] addr;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:108:9
		if (WIDTH == 32)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:109:13
			format_gowin_sp_ram_address = {4'b0000, addr, 5'b00000};
		else if (WIDTH == 16)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:111:13
			format_gowin_sp_ram_address = {2'b00, addr, 4'b0000};
		else if (WIDTH == 8)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:113:13
			format_gowin_sp_ram_address = {1'b0, addr, 5'b00000};
		else
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:115:13
			format_gowin_sp_ram_address = {addr, sv2v_cast_19EF5(1'sb0)};
	endfunction
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:123:5
	assign write_accepted = write_valid_i && write_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:124:5
	assign read_accepted = read_ready_i && read_valid_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:130:5
	assign write_ready_o = write_count_q < DEPTH;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:135:5
	assign write_count_o = write_count_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:136:5
	assign read_count_o = read_count_q;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:143:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:145:9
		state_d = state_q;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:147:9
		case (state_q)
			2'd0:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:150:17
				if (write_count_q == DEPTH)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:152:21
					state_d = 2'd1;
			2'd1:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:159:17
				state_d = 2'd2;
			2'd2:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:165:17
				if (write_count_q == DEPTH)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:166:21
					state_d = 2'd1;
			default:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:170:22
				state_d = 2'd0;
		endcase
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:179:5
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:180:9
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:182:13
			state_q <= 2'd0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:183:13
			write_addr_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:184:13
			read_addr_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:185:13
			write_count_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:186:13
			read_count_q <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:189:13
			write_buf_sel_q <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:190:13
			read_buf_sel_q <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:193:13
			buffer_ready_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:194:13
			buffer_overflow_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:195:13
			read_valid_o <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:198:13
			state_q <= state_d;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:201:13
			buffer_ready_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:202:13
			buffer_overflow_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:207:13
			if (state_q == 2'd1) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:209:17
				buffer_ready_o <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:210:17
				read_buf_sel_q <= write_buf_sel_q;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:211:17
				write_buf_sel_q <= ~write_buf_sel_q;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:214:17
				write_addr_q <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:215:17
				write_count_q <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:216:17
				read_addr_q <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:217:17
				read_count_q <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:218:17
				read_valid_o <= 1'b1;
			end
			else begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:223:17
				if (write_accepted) begin
					begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:224:21
						if (write_count_q < DEPTH) begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:225:25
							write_addr_q <= write_addr_q + 1'b1;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:226:25
							write_count_q <= write_count_q + 1'b1;
						end
						else
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:229:25
							buffer_overflow_o <= 1'b1;
					end
				end
				if (read_accepted && (state_q == 2'd2)) begin
					begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:237:21
						if (read_count_q < (DEPTH - 1)) begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:238:25
							read_addr_q <= read_addr_q + 1'b1;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:239:25
							read_count_q <= read_count_q + 1'b1;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:240:25
							read_valid_o <= 1'b1;
						end
						else begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:243:25
							read_addr_q <= 1'sb0;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:244:25
							read_count_q <= 1'sb0;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:245:25
							read_valid_o <= 1'b0;
						end
					end
				end
				else if (state_q == 2'd2)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:249:21
					read_valid_o <= (read_count_q < DEPTH ? 1'b1 : 1'b0);
				else
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:252:21
					read_valid_o <= 1'b0;
			end
		end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:265:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:266:9
		if (write_buf_sel_q == 1'b0) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:268:13
			ram0_addr = format_gowin_sp_ram_address(write_addr_q);
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:269:13
			ram1_addr = format_gowin_sp_ram_address(read_addr_q);
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:272:13
			ram0_addr = format_gowin_sp_ram_address(read_addr_q);
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:273:13
			ram1_addr = format_gowin_sp_ram_address(write_addr_q);
		end
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:283:5
	assign ram0_we = write_accepted && (write_buf_sel_q == 1'b0);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:284:5
	assign ram1_we = write_accepted && (write_buf_sel_q == 1'b1);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:292:5
	assign read_data_o = (state_q == 2'd2 ? (read_buf_sel_q == 1'b0 ? ram0_dout : ram1_dout) : {WIDTH {1'sb0}});
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:306:5
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
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:317:5
	defparam pingpong_buffer_ram0.BIT_WIDTH = WIDTH;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:318:5
	defparam pingpong_buffer_ram0.READ_MODE = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:319:5
	defparam pingpong_buffer_ram0.WRITE_MODE = 2'b00;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:320:5
	defparam pingpong_buffer_ram0.BLK_SEL = 3'b000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:328:5
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
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:339:5
	defparam pingpong_buffer_ram1.BIT_WIDTH = WIDTH;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:340:5
	defparam pingpong_buffer_ram1.READ_MODE = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:341:5
	defparam pingpong_buffer_ram1.WRITE_MODE = 2'b00;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:342:5
	defparam pingpong_buffer_ram1.BLK_SEL = 3'b000;
	initial _sv2v_0 = 0;
endmodule
