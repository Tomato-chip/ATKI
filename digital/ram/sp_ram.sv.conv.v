// removed package "fpga_template_pkg"
module pingpong_sp_ram (
	clk_i,
	rst_ni,
	sample_i,
	sample_ready_i,
	read_data_o,
	buffer_ready_o
);
	reg _sv2v_0;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:2:15
	parameter [31:0] WIDTH = 24;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:3:15
	parameter [31:0] DEPTH = 24;
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
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:17:5
	localparam [31:0] AW = 8;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:19:5
	function automatic [13:0] pack_addr;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:19:47
		input reg [7:0] a8;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:20:9
		pack_addr = {2'b00, a8, 4'b0000};
	endfunction
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:24:5
	reg [7:0] write_address;
	reg [7:0] read_address;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:25:5
	reg write_buffer_sel;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:26:5
	reg read_buffer_sel;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:27:5
	reg valid_read_out;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:28:5
	wire buffer_full;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:29:5
	wire sample_ready;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:31:5
	assign sample_ready = sample_ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:32:5
	assign buffer_full = sample_ready && (write_address == (DEPTH - 1));
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:35:5
	always @(posedge clk_i)
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:36:9
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:37:13
			write_address <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:38:13
			read_address <= 1'sb0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:39:13
			write_buffer_sel <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:40:13
			read_buffer_sel <= 1'b1;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:41:13
			valid_read_out <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:42:13
			buffer_ready_o <= 1'b0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:44:13
			buffer_ready_o <= 1'b0;
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:47:13
			if (sample_ready) begin
				begin
					// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:48:17
					if (buffer_full)
						// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:48:34
						write_address <= 1'sb0;
					else
						// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:49:34
						write_address <= write_address + 1'b1;
				end
			end
			if (sample_ready) begin
				begin
					// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:54:17
					if (buffer_full)
						// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:54:34
						read_address <= 1'sb0;
					else
						// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:55:34
						read_address <= read_address + 1'b1;
				end
			end
			if (buffer_full) begin
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:60:17
				buffer_ready_o <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:61:17
				valid_read_out <= 1'b1;
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:62:17
				read_address <= 1'sb0;
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:63:17
				read_buffer_sel <= write_buffer_sel;
				// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:64:17
				write_buffer_sel <= ~write_buffer_sel;
			end
		end
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:70:5
	reg [13:0] address_RAM_0;
	reg [13:0] address_RAM_1;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:71:5
	wire write_enable_RAM_0 = sample_ready && (write_buffer_sel == 1'b0);
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:72:5
	wire write_enable_RAM_1 = sample_ready && (write_buffer_sel == 1'b1);
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:74:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:76:9
		address_RAM_0 = 1'sb0;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:77:9
		address_RAM_1 = 1'sb0;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:79:9
		if (write_buffer_sel == 1'b0) begin
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:81:13
			address_RAM_0 = pack_addr(write_address);
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:82:13
			address_RAM_1 = pack_addr(read_address);
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:85:13
			address_RAM_0 = pack_addr(read_address);
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:86:13
			address_RAM_1 = pack_addr(write_address);
		end
	end
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:92:5
	wire [31:0] data_out_RAM_32_0;
	wire [31:0] data_out_RAM_32_1;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:95:5
	SP u_ram0(
		.DO(data_out_RAM_32_0),
		.CLK(clk_i),
		.CE(1'b1),
		.OCE(1'b0),
		.RESET(1'b0),
		.WRE(write_enable_RAM_0),
		.BLKSEL(3'b000),
		.AD(address_RAM_0),
		.DI({8'b00000000, sample_i})
	);
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:106:5
	defparam u_ram0.BIT_WIDTH = 32;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:107:5
	defparam u_ram0.READ_MODE = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:108:5
	defparam u_ram0.WRITE_MODE = 2'b00;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:109:5
	defparam u_ram0.BLK_SEL = 3'b000;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:112:5
	SP u_ram1(
		.DO(data_out_RAM_32_1),
		.CLK(clk_i),
		.CE(1'b1),
		.OCE(1'b0),
		.RESET(1'b0),
		.WRE(write_enable_RAM_1),
		.BLKSEL(3'b000),
		.AD(address_RAM_1),
		.DI({8'b00000000, sample_i})
	);
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:123:5
	defparam u_ram1.BIT_WIDTH = 32;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:124:5
	defparam u_ram1.READ_MODE = 1'b0;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:125:5
	defparam u_ram1.WRITE_MODE = 2'b00;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:126:5
	defparam u_ram1.BLK_SEL = 3'b000;
	// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:131:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:132:9
		read_data_o = 1'sb0;
		// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:133:9
		if (valid_read_out)
			// Trace: /home/tomato-chip/ATKI/digital/ram/sp_ram.sv:134:13
			read_data_o = (read_buffer_sel == 1'b0 ? data_out_RAM_32_0[23:0] : data_out_RAM_32_1[23:0]);
	end
	initial _sv2v_0 = 0;
endmodule
