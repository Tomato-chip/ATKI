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
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:25:15
	parameter [31:0] WIDTH = 32;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:26:15
	parameter [31:0] DEPTH = 256;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:27:15
	parameter [31:0] ADDR_WIDTH = $clog2(DEPTH);
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:30:5
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:31:5
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:36:5
	input wire [WIDTH - 1:0] write_data_i;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:37:5
	input wire write_valid_i;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:38:5
	output wire write_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:43:5
	output reg [WIDTH - 1:0] read_data_o;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:44:5
	input wire read_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:45:5
	output reg read_valid_o;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:50:5
	output reg buffer_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:51:5
	output reg buffer_overflow_o;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:52:5
	output wire [ADDR_WIDTH:0] write_count_o;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:53:5
	output wire [ADDR_WIDTH:0] read_count_o;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:61:5
	reg [ADDR_WIDTH - 1:0] write_address;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:62:5
	reg [ADDR_WIDTH - 1:0] read_address;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:65:5
	reg [ADDR_WIDTH:0] write_count;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:66:5
	reg [ADDR_WIDTH:0] read_count;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:69:5
	reg write_buffer_sel;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:70:5
	reg read_buffer_sel;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:73:5
	reg read_buffer_valid;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:74:5
	wire write_buffer_full;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:75:5
	reg read_in_progress;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:78:5
	wire write_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:79:5
	wire read_accepted;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:82:5
	reg [13:0] ram0_address;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:83:5
	reg [13:0] ram1_address;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:84:5
	wire ram0_write_enable;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:85:5
	wire ram1_write_enable;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:86:5
	wire [WIDTH - 1:0] ram0_data_out;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:87:5
	wire [WIDTH - 1:0] ram1_data_out;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:92:5
	function automatic [(14 - ADDR_WIDTH) - 1:0] sv2v_cast_19EF5;
		input reg [(14 - ADDR_WIDTH) - 1:0] inp;
		sv2v_cast_19EF5 = inp;
	endfunction
	function automatic [13:0] pack_address;
		// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:92:50
		input reg [ADDR_WIDTH - 1:0] addr;
		// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:95:9
		if (WIDTH == 32)
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:96:13
			pack_address = {1'b0, addr, 5'b00000};
		else if (WIDTH == 16)
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:98:13
			pack_address = {2'b00, addr, 4'b0000};
		else if (WIDTH == 8)
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:100:13
			pack_address = {1'b0, addr, 5'b00000};
		else
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:102:13
			pack_address = {addr, sv2v_cast_19EF5(1'sb0)};
	endfunction
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:129:5
	assign write_accepted = write_valid_i && write_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:130:5
	assign read_accepted = read_ready_i && read_valid_o;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:136:5
	assign write_ready_o = !write_buffer_full;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:141:5
	assign write_buffer_full = write_count >= DEPTH;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:146:5
	assign write_count_o = write_count;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:147:5
	assign read_count_o = read_count;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:152:5
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:153:9
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:155:13
			write_address <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:156:13
			read_address <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:157:13
			write_count <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:158:13
			read_count <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:159:13
			write_buffer_sel <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:160:13
			read_buffer_sel <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:161:13
			read_buffer_valid <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:162:13
			read_in_progress <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:163:13
			buffer_ready_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:164:13
			buffer_overflow_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:165:13
			read_valid_o <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:168:13
			buffer_ready_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:169:13
			buffer_overflow_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:174:13
			if (write_count == DEPTH) begin
				// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:176:17
				buffer_ready_o <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:177:17
				read_buffer_valid <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:178:17
				read_in_progress <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:179:17
				read_buffer_sel <= write_buffer_sel;
				// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:180:17
				write_buffer_sel <= ~write_buffer_sel;
				// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:183:17
				write_address <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:184:17
				write_count <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:187:17
				read_address <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:188:17
				read_count <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:189:17
				read_valid_o <= 1'b1;
			end
			else begin
				// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:194:17
				if (write_accepted) begin
					begin
						// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:195:21
						if (write_count < DEPTH) begin
							// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:197:25
							write_address <= write_address + 1'b1;
							// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:198:25
							write_count <= write_count + 1'b1;
						end
						else
							// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:201:25
							buffer_overflow_o <= 1'b1;
					end
				end
				if (read_accepted && read_buffer_valid) begin
					// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:210:21
					if (read_count < (DEPTH - 1)) begin
						// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:211:25
						read_address <= read_address + 1'b1;
						// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:212:25
						read_count <= read_count + 1'b1;
					end
					else begin
						// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:215:25
						read_address <= 1'sb0;
						// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:216:25
						read_count <= 1'sb0;
					end
					// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:220:21
					read_valid_o <= 1'b1;
				end
				else if (read_buffer_valid && read_in_progress)
					// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:223:21
					read_valid_o <= 1'b1;
				else
					// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:225:21
					read_valid_o <= 1'b0;
			end
		end
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:234:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:235:9
		if (write_buffer_sel == 1'b0) begin
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:237:13
			ram0_address = pack_address(write_address);
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:238:13
			ram1_address = pack_address(read_address);
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:241:13
			ram0_address = pack_address(read_address);
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:242:13
			ram1_address = pack_address(write_address);
		end
	end
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:249:5
	assign ram0_write_enable = write_accepted && (write_buffer_sel == 1'b0);
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:250:5
	assign ram1_write_enable = write_accepted && (write_buffer_sel == 1'b1);
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:255:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:256:9
		if (read_buffer_valid)
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:257:13
			read_data_o = (read_buffer_sel == 1'b0 ? ram0_data_out : ram1_data_out);
		else
			// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:259:13
			read_data_o = 1'sb0;
	end
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:266:5
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
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:277:5
	defparam u_ram0.BIT_WIDTH = WIDTH;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:278:5
	defparam u_ram0.READ_MODE = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:279:5
	defparam u_ram0.WRITE_MODE = 2'b00;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:280:5
	defparam u_ram0.BLK_SEL = 3'b000;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:285:5
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
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:296:5
	defparam u_ram1.BIT_WIDTH = WIDTH;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:297:5
	defparam u_ram1.READ_MODE = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:298:5
	defparam u_ram1.WRITE_MODE = 2'b00;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:299:5
	defparam u_ram1.BLK_SEL = 3'b000;
	// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:307:5
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/ram/ram_logic.sv:308:9
		if (rst_ni)
			;
	initial _sv2v_0 = 0;
endmodule
