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
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:25:15
	parameter [31:0] WIDTH = 32;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:26:15
	parameter [31:0] DEPTH = 16;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:27:15
	parameter [31:0] ADDR_WIDTH = $clog2(DEPTH);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:30:5
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:31:5
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:36:5
	input wire signed [WIDTH - 1:0] write_data_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:37:5
	input wire write_valid_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:38:5
	output wire write_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:43:5
	output reg signed [WIDTH - 1:0] read_data_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:44:5
	input wire read_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:45:5
	output reg read_valid_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:50:5
	output reg buffer_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:51:5
	output reg buffer_overflow_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:52:5
	output wire [ADDR_WIDTH:0] write_count_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:53:5
	output wire [ADDR_WIDTH:0] read_count_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:61:5
	reg [ADDR_WIDTH - 1:0] write_address;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:62:5
	reg [ADDR_WIDTH - 1:0] read_address;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:65:5
	reg [ADDR_WIDTH:0] write_count;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:66:5
	reg [ADDR_WIDTH:0] read_count;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:69:5
	reg write_buffer_sel;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:70:5
	reg read_buffer_sel;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:73:5
	reg read_buffer_valid;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:74:5
	wire write_buffer_full;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:75:5
	reg read_in_progress;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:78:5
	wire write_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:79:5
	wire read_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:82:5
	reg [13:0] ram0_address;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:83:5
	reg [13:0] ram1_address;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:84:5
	wire ram0_write_enable;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:85:5
	wire ram1_write_enable;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:86:5
	wire [WIDTH - 1:0] ram0_data_out;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:87:5
	wire [WIDTH - 1:0] ram1_data_out;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:92:5
	function automatic [(14 - ADDR_WIDTH) - 1:0] sv2v_cast_19EF5;
		input reg [(14 - ADDR_WIDTH) - 1:0] inp;
		sv2v_cast_19EF5 = inp;
	endfunction
	function automatic [13:0] pack_address;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:92:50
		input reg [ADDR_WIDTH - 1:0] addr;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:95:9
		if (WIDTH == 32)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:96:13
			pack_address = {1'b0, addr, 5'b00000};
		else if (WIDTH == 16)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:98:13
			pack_address = {2'b00, addr, 4'b0000};
		else if (WIDTH == 8)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:100:13
			pack_address = {1'b0, addr, 5'b00000};
		else
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:102:13
			pack_address = {addr, sv2v_cast_19EF5(1'sb0)};
	endfunction
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:130:5
	assign write_accepted = write_valid_i && write_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:131:5
	assign read_accepted = read_ready_i && read_valid_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:137:5
	assign write_ready_o = !write_buffer_full;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:142:5
	assign write_buffer_full = write_count >= DEPTH;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:147:5
	assign write_count_o = write_count;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:148:5
	assign read_count_o = read_count;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:153:5
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:154:9
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:156:13
			write_address <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:157:13
			read_address <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:158:13
			write_count <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:159:13
			read_count <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:160:13
			write_buffer_sel <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:161:13
			read_buffer_sel <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:162:13
			read_buffer_valid <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:163:13
			read_in_progress <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:164:13
			buffer_ready_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:165:13
			buffer_overflow_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:166:13
			read_valid_o <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:169:13
			buffer_ready_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:170:13
			buffer_overflow_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:175:13
			if (write_count == DEPTH) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:177:17
				buffer_ready_o <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:178:17
				read_buffer_valid <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:179:17
				read_in_progress <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:180:17
				read_buffer_sel <= write_buffer_sel;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:181:17
				write_buffer_sel <= ~write_buffer_sel;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:184:17
				write_address <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:185:17
				write_count <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:186:17
				read_address <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:187:17
				read_count <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:188:17
				read_valid_o <= 1'b0;
			end
			else begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:193:17
				if (write_accepted) begin
					begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:194:21
						if (write_count < DEPTH) begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:196:25
							write_address <= write_address + 1'b1;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:197:25
							write_count <= write_count + 1'b1;
						end
						else
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:200:25
							buffer_overflow_o <= 1'b1;
					end
				end
				if (read_accepted && read_buffer_valid) begin
					begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:208:21
						if (read_count < (DEPTH - 1)) begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:209:25
							read_address <= read_address + 1'b1;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:210:25
							read_count <= read_count + 1'b1;
						end
						else begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:213:25
							read_in_progress <= 1'b0;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:214:25
							read_count <= 1'sb0;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:215:25
							read_address <= 1'sb0;
						end
					end
				end
				if (read_buffer_valid && read_in_progress)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:224:21
					read_valid_o <= 1'b1;
				else
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:226:21
					read_valid_o <= 1'b0;
			end
		end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:235:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:236:9
		if (write_buffer_sel == 1'b0) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:238:13
			ram0_address = pack_address(write_address);
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:239:13
			ram1_address = pack_address(read_address);
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:242:13
			ram0_address = pack_address(read_address);
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:243:13
			ram1_address = pack_address(write_address);
		end
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:250:5
	assign ram0_write_enable = write_accepted && (write_buffer_sel == 1'b0);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:251:5
	assign ram1_write_enable = write_accepted && (write_buffer_sel == 1'b1);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:256:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:257:9
		if (read_buffer_valid)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:258:13
			read_data_o = (read_buffer_sel == 1'b0 ? ram0_data_out : ram1_data_out);
		else
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:260:13
			read_data_o = 1'sb0;
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:267:5
	SP u_ram0(
		.CLK(clk_i),
		.CE(1'b1),
		.OCE(1'b0),
		.RESET(1'b0),
		.WRE(ram0_write_enable),
		.BLKSEL(3'b000),
		.AD(ram0_address),
		.DI(write_data_i),
		.DO(ram0_data_out)
	);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:278:5
	defparam u_ram0.BIT_WIDTH = WIDTH;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:279:5
	defparam u_ram0.READ_MODE = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:280:5
	defparam u_ram0.WRITE_MODE = 2'b00;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:281:5
	defparam u_ram0.BLK_SEL = 3'b000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:286:5
	SP u_ram1(
		.CLK(clk_i),
		.CE(1'b1),
		.OCE(1'b0),
		.RESET(1'b0),
		.WRE(ram1_write_enable),
		.BLKSEL(3'b000),
		.AD(ram1_address),
		.DI(write_data_i),
		.DO(ram1_data_out)
	);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:297:5
	defparam u_ram1.BIT_WIDTH = WIDTH;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:298:5
	defparam u_ram1.READ_MODE = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:299:5
	defparam u_ram1.WRITE_MODE = 2'b00;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:300:5
	defparam u_ram1.BLK_SEL = 3'b000;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:308:5
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/ram_logic_test.sv:309:9
		if (rst_ni)
			;
	initial _sv2v_0 = 0;
endmodule
