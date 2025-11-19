// removed package "fpga_template_pkg"
module fft_256 (
	clk_i,
	rst_ni,
	data_real_i,
	data_imag_i,
	valid_i,
	ready_o,
	data_real_o,
	data_imag_o,
	valid_o,
	ready_i,
	busy_o
);
	reg _sv2v_0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:2:15
	parameter signed [31:0] DATA_WIDTH = 18;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:3:15
	parameter signed [31:0] FFT_SIZE = 256;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:4:15
	parameter signed [31:0] STAGES = 8;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:6:5
	input wire clk_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:7:5
	input wire rst_ni;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:8:5
	input wire signed [DATA_WIDTH - 1:0] data_real_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:9:5
	input wire signed [DATA_WIDTH - 1:0] data_imag_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:10:5
	input wire valid_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:11:5
	output wire ready_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:12:5
	output reg signed [DATA_WIDTH - 1:0] data_real_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:13:5
	output reg signed [DATA_WIDTH - 1:0] data_imag_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:14:5
	output reg valid_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:15:5
	input wire ready_i;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:16:5
	output wire busy_o;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:19:5
	localparam signed [31:0] BUTTERFLY_LATENCY = 3;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:21:5
	// removed localparam type state_t
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:29:5
	reg [2:0] state;
	reg [2:0] next_state;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:31:5
	reg signed [DATA_WIDTH - 1:0] buffer_real [0:FFT_SIZE - 1];
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:32:5
	reg signed [DATA_WIDTH - 1:0] buffer_imag [0:FFT_SIZE - 1];
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:33:5
	reg signed [DATA_WIDTH - 1:0] buffer_real_tmp [0:FFT_SIZE - 1];
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:34:5
	reg signed [DATA_WIDTH - 1:0] buffer_imag_tmp [0:FFT_SIZE - 1];
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:36:5
	reg [8:0] input_count;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:37:5
	reg [8:0] output_count;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:38:5
	reg [8:0] bit_reverse_count;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:39:5
	reg [3:0] stage;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:40:5
	reg [8:0] butterfly_idx;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:41:5
	reg [7:0] idx_a;
	reg [7:0] idx_b;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:42:5
	reg [8:0] group_size;
	reg [8:0] group_idx;
	reg [8:0] bf_pos;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:44:5
	reg signed [DATA_WIDTH - 1:0] bf_in_a_real;
	reg signed [DATA_WIDTH - 1:0] bf_in_a_imag;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:45:5
	reg signed [DATA_WIDTH - 1:0] bf_in_b_real;
	reg signed [DATA_WIDTH - 1:0] bf_in_b_imag;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:46:5
	reg signed [DATA_WIDTH - 1:0] bf_out_a_real;
	reg signed [DATA_WIDTH - 1:0] bf_out_a_imag;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:47:5
	reg signed [DATA_WIDTH - 1:0] bf_out_b_real;
	reg signed [DATA_WIDTH - 1:0] bf_out_b_imag;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:48:5
	wire signed [DATA_WIDTH - 1:0] twiddle_real;
	wire signed [DATA_WIDTH - 1:0] twiddle_imag;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:49:5
	reg [7:0] twiddle_idx;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:51:5
	reg signed [DATA_WIDTH - 1:0] bf_in_a_real_d;
	reg signed [DATA_WIDTH - 1:0] bf_in_a_imag_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:52:5
	reg signed [DATA_WIDTH - 1:0] bf_in_b_real_d;
	reg signed [DATA_WIDTH - 1:0] bf_in_b_imag_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:53:5
	reg [7:0] idx_a_d;
	reg [7:0] idx_b_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:54:5
	reg [3:0] stage_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:55:5
	reg bf_valid;
	reg bf_valid_d;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:58:5
	integer cycle_count = 0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:61:5
	function automatic [7:0] bit_reverse;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:61:48
		input reg [7:0] in;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:62:9
		reg [7:0] out;
		begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:63:9
			begin : sv2v_autoblock_1
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:63:14
				reg signed [31:0] i;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:63:14
				for (i = 0; i < 8; i = i + 1)
					begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:64:13
						out[i] = in[7 - i];
					end
			end
			bit_reverse = out;
		end
	endfunction
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:69:5
	always @(posedge clk_i or negedge rst_ni)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:70:9
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:71:13
			state <= 3'd0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:73:13
			cycle_count <= 0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:76:13
			state <= next_state;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:78:13
			cycle_count <= cycle_count + 1;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:79:13
			if (state != next_state)
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:80:17
				$display("FFT: Cycle %0d: State transition %0d -> %0d (stage=%0d, butterfly_idx=%0d)", cycle_count, state, next_state, stage, butterfly_idx);
		end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:87:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:88:9
		next_state = state;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:90:9
		case (state)
			3'd0:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:92:17
				if (valid_i)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:93:21
					next_state = 3'd1;
			3'd1:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:98:17
				if (input_count >= FFT_SIZE)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:99:21
					next_state = 3'd2;
			3'd2:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:104:17
				if (bit_reverse_count >= (FFT_SIZE - 1))
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:105:21
					next_state = 3'd3;
			3'd3:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:110:17
				if ((stage == STAGES) && (butterfly_idx == 0))
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:111:21
					next_state = 3'd4;
			3'd4:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:116:17
				if ((output_count == (FFT_SIZE - 1)) && ready_i)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:117:21
					next_state = 3'd0;
			default:
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:121:22
				next_state = 3'd0;
		endcase
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:125:5
	initial begin
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:126:9
		begin : sv2v_autoblock_2
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:126:14
			reg signed [31:0] i;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:126:14
			for (i = 0; i < FFT_SIZE; i = i + 1)
				begin
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:127:13
					buffer_real[i] = 0;
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:128:13
					buffer_imag[i] = 0;
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:129:13
					buffer_real_tmp[i] = 0;
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:130:13
					buffer_imag_tmp[i] = 0;
				end
		end
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:134:5
	always @(posedge clk_i or negedge rst_ni)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:135:9
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:136:13
			input_count <= 0;
		else
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:138:13
			if (((state == 3'd1) || (state == 3'd0)) && valid_i) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:139:17
				buffer_real[input_count] <= data_real_i;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:140:17
				buffer_imag[input_count] <= data_imag_i;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:143:17
				if ((input_count < 4) || (input_count >= (FFT_SIZE - 2)))
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:144:21
					$display("FFT: Loading [%0d] = %0d", input_count, data_real_i);
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:148:17
				input_count <= input_count + 1;
			end
			else if ((state == 3'd0) && !valid_i)
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:150:17
				input_count <= 0;
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:155:5
	always @(posedge clk_i or negedge rst_ni)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:156:9
		if (!rst_ni)
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:157:13
			bit_reverse_count <= 0;
		else
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:159:13
			if (state == 3'd0)
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:160:17
				bit_reverse_count <= 0;
			else if ((state == 3'd2) && (bit_reverse_count < FFT_SIZE)) begin : sv2v_autoblock_3
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:162:17
				reg [7:0] rev_idx;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:163:17
				rev_idx = bit_reverse(bit_reverse_count[7:0]);
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:164:17
				buffer_real_tmp[bit_reverse_count] <= buffer_real[rev_idx];
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:165:17
				buffer_imag_tmp[bit_reverse_count] <= buffer_imag[rev_idx];
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:168:17
				if (bit_reverse_count < 4)
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:169:21
					$display("FFT: Bit-reverse [%0d] <- [%0d], value=%0d", bit_reverse_count, rev_idx, buffer_real[rev_idx]);
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:173:17
				bit_reverse_count <= bit_reverse_count + 1;
			end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:178:5
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:179:9
		group_size = 1 << (stage + 1);
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:180:9
		group_idx = butterfly_idx / (group_size >> 1);
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:181:9
		bf_pos = butterfly_idx % (group_size >> 1);
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:184:5
	always @(posedge clk_i or negedge rst_ni)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:185:9
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:186:13
			stage <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:187:13
			butterfly_idx <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:188:13
			bf_in_a_real <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:189:13
			bf_in_a_imag <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:190:13
			bf_in_b_real <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:191:13
			bf_in_b_imag <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:192:13
			twiddle_idx <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:193:13
			idx_a <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:194:13
			idx_b <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:195:13
			bf_valid <= 0;
		end
		else
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:197:13
			if (state == 3'd3) begin
				begin
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:198:17
					if (stage >= STAGES) begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:199:21
						stage <= STAGES;
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:200:21
						butterfly_idx <= 0;
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:201:21
						bf_valid <= 0;
					end
					else if (butterfly_idx < (FFT_SIZE >> 1)) begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:203:21
						idx_a <= (group_idx * group_size) + bf_pos;
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:204:21
						idx_b <= ((group_idx * group_size) + bf_pos) + (group_size >> 1);
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:206:21
						if (stage[0] == 0) begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:207:25
							bf_in_a_real <= buffer_real_tmp[(group_idx * group_size) + bf_pos];
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:208:25
							bf_in_a_imag <= buffer_imag_tmp[(group_idx * group_size) + bf_pos];
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:209:25
							bf_in_b_real <= buffer_real_tmp[((group_idx * group_size) + bf_pos) + (group_size >> 1)];
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:210:25
							bf_in_b_imag <= buffer_imag_tmp[((group_idx * group_size) + bf_pos) + (group_size >> 1)];
						end
						else begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:212:25
							bf_in_a_real <= buffer_real[(group_idx * group_size) + bf_pos];
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:213:25
							bf_in_a_imag <= buffer_imag[(group_idx * group_size) + bf_pos];
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:214:25
							bf_in_b_real <= buffer_real[((group_idx * group_size) + bf_pos) + (group_size >> 1)];
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:215:25
							bf_in_b_imag <= buffer_imag[((group_idx * group_size) + bf_pos) + (group_size >> 1)];
						end
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:218:21
						twiddle_idx <= bf_pos * (FFT_SIZE >> (stage + 1));
						if ((stage == 0) && (butterfly_idx <= 5))
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:222:25
							$display("FFT: Cycle %0d: Addr gen bf_idx=%0d -> idx_a=%0d, idx_b=%0d", cycle_count, butterfly_idx, (group_idx * group_size) + bf_pos, ((group_idx * group_size) + bf_pos) + (group_size >> 1));
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:228:21
						bf_valid <= 1;
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:229:21
						butterfly_idx <= butterfly_idx + 1;
					end
					else begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:231:21
						bf_valid <= 0;
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:232:21
						if (butterfly_idx == ((FFT_SIZE >> 1) + BUTTERFLY_LATENCY)) begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:233:25
							butterfly_idx <= 0;
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:234:25
							if (stage < (STAGES - 1)) begin
								// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:236:29
								$display("FFT: Cycle %0d: Stage %0d -> %0d transition", cycle_count, stage, stage + 1);
								// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:237:29
								if (stage[0] == 0)
									// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:238:33
									$display("  Stage %0d output (in main buffer): [0]=%0d, [1]=%0d, [16]=%0d", stage, buffer_real[0], buffer_real[1], buffer_real[16]);
								else
									// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:241:33
									$display("  Stage %0d output (in tmp buffer): [0]=%0d, [1]=%0d, [16]=%0d", stage, buffer_real_tmp[0], buffer_real_tmp[1], buffer_real_tmp[16]);
								// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:245:29
								stage <= stage + 1;
							end
							else begin
								// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:248:29
								$display("FFT: Cycle %0d: All stages complete", cycle_count);
								// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:250:29
								stage <= STAGES;
							end
						end
						else
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:253:25
							butterfly_idx <= butterfly_idx + 1;
					end
				end
			end
			else if ((state == 3'd0) || (state == 3'd2)) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:257:17
				stage <= 0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:258:17
				butterfly_idx <= 0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:259:17
				bf_valid <= 0;
			end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:264:5
	always @(posedge clk_i or negedge rst_ni)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:265:9
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:266:13
			bf_in_a_real_d <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:267:13
			bf_in_a_imag_d <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:268:13
			bf_in_b_real_d <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:269:13
			bf_in_b_imag_d <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:270:13
			idx_a_d <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:271:13
			idx_b_d <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:272:13
			stage_d <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:273:13
			bf_valid_d <= 0;
		end
		else begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:275:13
			bf_in_a_real_d <= bf_in_a_real;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:276:13
			bf_in_a_imag_d <= bf_in_a_imag;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:277:13
			bf_in_b_real_d <= bf_in_b_real;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:278:13
			bf_in_b_imag_d <= bf_in_b_imag;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:279:13
			idx_a_d <= idx_a;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:280:13
			idx_b_d <= idx_b;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:281:13
			stage_d <= stage;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:282:13
			bf_valid_d <= bf_valid;
		end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:286:5
	always @(*) begin : sv2v_autoblock_4
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:287:9
		reg signed [(2 * DATA_WIDTH) - 1:0] mult_real;
		reg signed [(2 * DATA_WIDTH) - 1:0] mult_imag;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:288:9
		reg signed [DATA_WIDTH - 1:0] wb_real;
		reg signed [DATA_WIDTH - 1:0] wb_imag;
		if (_sv2v_0)
			;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:290:9
		mult_real = (bf_in_b_real_d * twiddle_real) - (bf_in_b_imag_d * twiddle_imag);
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:291:9
		mult_imag = (bf_in_b_real_d * twiddle_imag) + (bf_in_b_imag_d * twiddle_real);
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:293:9
		wb_real = mult_real[(2 * DATA_WIDTH) - 2-:DATA_WIDTH];
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:294:9
		wb_imag = mult_imag[(2 * DATA_WIDTH) - 2-:DATA_WIDTH];
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:296:9
		bf_out_a_real = (bf_in_a_real_d + wb_real) >>> 1;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:297:9
		bf_out_a_imag = (bf_in_a_imag_d + wb_imag) >>> 1;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:298:9
		bf_out_b_real = (bf_in_a_real_d - wb_real) >>> 1;
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:299:9
		bf_out_b_imag = (bf_in_a_imag_d - wb_imag) >>> 1;
	end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:302:5
	always @(posedge clk_i or negedge rst_ni)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:303:9
		if (!rst_ni)
			;
		else
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:305:13
			if (((state == 3'd3) && bf_valid_d) && (stage_d < STAGES)) begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:306:17
				if (stage_d[0] == 0) begin
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:307:21
					buffer_real[idx_a_d] <= bf_out_a_real;
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:308:21
					buffer_imag[idx_a_d] <= bf_out_a_imag;
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:309:21
					buffer_real[idx_b_d] <= bf_out_b_real;
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:310:21
					buffer_imag[idx_b_d] <= bf_out_b_imag;
				end
				else begin
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:312:21
					buffer_real_tmp[idx_a_d] <= bf_out_a_real;
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:313:21
					buffer_imag_tmp[idx_a_d] <= bf_out_a_imag;
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:314:21
					buffer_real_tmp[idx_b_d] <= bf_out_b_real;
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:315:21
					buffer_imag_tmp[idx_b_d] <= bf_out_b_imag;
				end
				if ((stage_d == 0) && (idx_a_d <= 6))
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:320:21
					$display("FFT: Cycle %0d: Writing stage=%0d, bf_idx=%0d: [%0d]=%0d+j%0d, [%0d]=%0d+j%0d (bf_in_a=%0d, bf_in_b=%0d, tw=%0d+j%0d)", cycle_count, stage_d, butterfly_idx, idx_a_d, bf_out_a_real, bf_out_a_imag, idx_b_d, bf_out_b_real, bf_out_b_imag, bf_in_a_real_d, bf_in_b_real_d, twiddle_real, twiddle_imag);
			end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:330:5
	fft_twiddle_256 u_twiddle(
		.clk_i(clk_i),
		.addr_i(twiddle_idx),
		.cos_o(twiddle_real),
		.sin_o(twiddle_imag)
	);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:337:5
	always @(posedge clk_i or negedge rst_ni)
		// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:338:9
		if (!rst_ni) begin
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:339:13
			output_count <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:340:13
			data_real_o <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:341:13
			data_imag_o <= 0;
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:342:13
			valid_o <= 0;
		end
		else
			// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:344:13
			if (state == 3'd4) begin
				begin
					// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:345:17
					if (ready_i || !valid_o) begin
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:346:21
						if (STAGES[0] == 0) begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:347:25
							data_real_o <= buffer_real_tmp[output_count];
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:348:25
							data_imag_o <= buffer_imag_tmp[output_count];
						end
						else begin
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:350:25
							data_real_o <= buffer_real[output_count];
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:351:25
							data_imag_o <= buffer_imag[output_count];
						end
						// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:353:21
						valid_o <= 1;
						if (output_count < (FFT_SIZE - 1))
							// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:356:25
							output_count <= output_count + 1;
					end
				end
			end
			else begin
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:360:17
				output_count <= 0;
				// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:361:17
				valid_o <= 0;
			end
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:366:5
	assign ready_o = (state == 3'd0) || (state == 3'd1);
	// Trace: /home/tomato-chip/ATKI/digital/Project_files/fft/fft_256.sv:367:5
	assign busy_o = state != 3'd0;
	initial _sv2v_0 = 0;
endmodule
