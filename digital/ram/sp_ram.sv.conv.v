// removed package "fpga_template_pkg"
module pingpong_sp_ram (
	clk_i,
	rst_ni,
	sample_i,
	sample_ready_i,
	read_data_o,
	buffer_ready_o,
	read_enable_o,
	read_ack_i
);
	reg _sv2v_0;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:2:15
	parameter [31:0] WIDTH = 16;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:3:15
	parameter [31:0] DEPTH = 256;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:5:5
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:6:5
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:8:5
	input wire [WIDTH - 1:0] sample_i;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:9:5
	input wire sample_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:11:5
	output reg [WIDTH - 1:0] read_data_o;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:12:5
	output reg buffer_ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:13:5
	output wire read_enable_o;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:14:5
	input wire read_ack_i;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:18:5
	localparam [31:0] AW = 8;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:20:5
	function automatic [13:0] pack_addr;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:20:47
		input reg [7:0] a8;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:21:9
		pack_addr = {2'b00, a8, 4'b0000};
	endfunction
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:25:5
	reg [7:0] write_address;
	reg [7:0] read_address;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:26:5
	reg [AW:0] read_count;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:27:5
	reg write_buffer_sel;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:28:5
	reg read_buffer_sel;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:29:5
	reg valid_read_out;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:30:5
	reg read_in_progress;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:31:5
	wire buffer_full;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:32:5
	wire sample_ready;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:34:5
	assign sample_ready = sample_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:35:5
	assign buffer_full = sample_ready && (write_address == (DEPTH - 1));
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:36:5
	assign read_enable_o = valid_read_out && !read_in_progress;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:38:5
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:39:9
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:40:13
			write_address <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:41:13
			read_address <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:42:13
			read_count <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:43:13
			write_buffer_sel <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:44:13
			read_buffer_sel <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:45:13
			valid_read_out <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:46:13
			read_in_progress <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:47:13
			buffer_ready_o <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:49:13
			buffer_ready_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:52:13
			if (sample_ready) begin
				begin
					// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:53:17
					if (buffer_full)
						// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:53:34
						write_address <= 1'sb0;
					else
						// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:54:34
						write_address <= write_address + 1'b1;
				end
			end
			if ((read_ack_i && valid_read_out) && !read_in_progress) begin
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:59:17
				read_count <= read_count + 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:60:17
				read_address <= read_address + 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:63:17
				if ((read_count + 1'b1) == DEPTH)
					// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:64:21
					read_in_progress <= 1'b1;
			end
			if (buffer_full) begin
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:70:17
				buffer_ready_o <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:71:17
				valid_read_out <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:72:17
				read_address <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:73:17
				read_count <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:74:17
				read_in_progress <= 1'b0;
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:75:17
				read_buffer_sel <= write_buffer_sel;
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:76:17
				write_buffer_sel <= ~write_buffer_sel;
			end
		end
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:82:5
	reg [13:0] address_RAM_0;
	reg [13:0] address_RAM_1;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:83:5
	wire write_enable_RAM_0 = sample_ready && (write_buffer_sel == 1'b0);
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:84:5
	wire write_enable_RAM_1 = sample_ready && (write_buffer_sel == 1'b1);
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:86:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:88:9
		address_RAM_0 = 1'sb0;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:89:9
		address_RAM_1 = 1'sb0;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:91:9
		if (write_buffer_sel == 1'b0) begin
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:93:13
			address_RAM_0 = pack_addr(write_address);
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:94:13
			address_RAM_1 = pack_addr(read_address);
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:97:13
			address_RAM_0 = pack_addr(read_address);
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:98:13
			address_RAM_1 = pack_addr(write_address);
		end
	end
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:104:5
	wire [31:0] data_out_RAM_32_0;
	wire [31:0] data_out_RAM_32_1;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:106:5
	wire data_out_RAM_16_0;
	assign data_out_RAM_16_0 = data_out_RAM_32_0[15:0];
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:107:5
	wire data_out_RAM_16_1;
	assign data_out_RAM_16_1 = data_out_RAM_32_1[15:0];
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:109:5
	SP u_ram0(
		.DO(data_out_RAM_32_0),
		.CLK(clk_i),
		.CE(1'b1),
		.OCE(1'b1),
		.RESET(!rst_ni),
		.WRE(write_enable_RAM_0),
		.BLKSEL(3'b000),
		.AD(address_RAM_0),
		.DI({16'b0000000000000000, sample_i})
	);
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:120:5
	defparam u_ram0.BIT_WIDTH = 16;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:121:5
	defparam u_ram0.READ_MODE = 1'b1;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:122:5
	defparam u_ram0.WRITE_MODE = 2'b00;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:123:5
	defparam u_ram0.BLK_SEL = 3'b000;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:124:5
	defparam u_ram0.RESET_MODE = "SYNC";
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:125:5
	defparam u_ram0.INIT_RAM_00 = 256'h00a000000000000b00a000000000000b00a000000000000b00a000000000000b;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:126:5
	defparam u_ram0.INIT_RAM_01 = 256'h00a000000000000b00a000000000000b00a000000000000b00a000000000000b;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:127:5
	defparam u_ram0.INIT_RAM_3F = 256'h00a000000000000b00a000000000000b00a000000000000b00a000000000000b;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:129:5
	SP u_ram1(
		.DO(data_out_RAM_32_1),
		.CLK(clk_i),
		.CE(1'b1),
		.OCE(1'b1),
		.RESET(!rst_ni),
		.WRE(write_enable_RAM_1),
		.BLKSEL(3'b000),
		.AD(address_RAM_1),
		.DI({16'b0000000000000000, sample_i})
	);
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:140:5
	defparam u_ram1.BIT_WIDTH = 16;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:141:5
	defparam u_ram1.READ_MODE = 1'b1;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:142:5
	defparam u_ram1.WRITE_MODE = 2'b00;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:143:5
	defparam u_ram1.BLK_SEL = 3'b000;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:144:5
	defparam u_ram1.RESET_MODE = "SYNC";
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:145:5
	defparam u_ram1.INIT_RAM_00 = 256'h00a000000000000b00a000000000000b00a000000000000b00a000000000000b;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:146:5
	defparam u_ram1.INIT_RAM_01 = 256'h00a000000000000b00a000000000000b00a000000000000b00a000000000000b;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:147:5
	defparam u_ram1.INIT_RAM_3F = 256'h00a000000000000b00a000000000000b00a000000000000b00a000000000000b;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:150:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:151:9
		read_data_o = 1'sb0;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:152:9
		if (valid_read_out)
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:153:13
			read_data_o = (read_buffer_sel == 1'b0 ? data_out_RAM_32_0[15:0] : data_out_RAM_32_1[15:0]);
	end
	initial _sv2v_0 = 0;
endmodule
