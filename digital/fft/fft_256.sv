module fft_256 #(
    parameter int DATA_WIDTH = 18,
    parameter int FFT_SIZE = 256,
    parameter int STAGES = 8
) (
    input  logic                         clk_i,
    input  logic                         rst_ni,
    input  logic signed [DATA_WIDTH-1:0] data_real_i,
    input  logic signed [DATA_WIDTH-1:0] data_imag_i,
    input  logic                         valid_i,
    output logic                         ready_o,
    output logic signed [DATA_WIDTH-1:0] data_real_o,
    output logic signed [DATA_WIDTH-1:0] data_imag_o,
    output logic                         valid_o,
    input  logic                         ready_i,
    output logic                         busy_o
);

    localparam int BUTTERFLY_LATENCY = 3;

    typedef enum logic [2:0] {
        IDLE,
        LOADING,
        BIT_REVERSE,
        PROCESSING,
        OUTPUTTING
    } state_t;

    state_t state, next_state;

    logic signed [DATA_WIDTH-1:0] buffer_real [0:FFT_SIZE-1];
    logic signed [DATA_WIDTH-1:0] buffer_imag [0:FFT_SIZE-1];
    logic signed [DATA_WIDTH-1:0] buffer_real_tmp [0:FFT_SIZE-1];
    logic signed [DATA_WIDTH-1:0] buffer_imag_tmp [0:FFT_SIZE-1];

    logic [8:0] input_count;
    logic [8:0] output_count;
    logic [8:0] bit_reverse_count;
    logic [3:0] stage;
    logic [8:0] butterfly_idx;
    logic [7:0] idx_a, idx_b;
    logic [8:0] group_size, group_idx, bf_pos;

    logic signed [DATA_WIDTH-1:0] bf_in_a_real, bf_in_a_imag;
    logic signed [DATA_WIDTH-1:0] bf_in_b_real, bf_in_b_imag;
    logic signed [DATA_WIDTH-1:0] bf_out_a_real, bf_out_a_imag;
    logic signed [DATA_WIDTH-1:0] bf_out_b_real, bf_out_b_imag;
    logic signed [DATA_WIDTH-1:0] twiddle_real, twiddle_imag;
    logic [7:0] twiddle_idx;

    logic signed [DATA_WIDTH-1:0] bf_in_a_real_d, bf_in_a_imag_d;
    logic signed [DATA_WIDTH-1:0] bf_in_b_real_d, bf_in_b_imag_d;
    logic [7:0] idx_a_d, idx_b_d;
    logic [3:0] stage_d;
    logic bf_valid, bf_valid_d;

    `ifndef SYNTHESIS
    integer cycle_count = 0;
    `endif

    function automatic logic [7:0] bit_reverse(input logic [7:0] in);
        logic [7:0] out;
        for (int i = 0; i < 8; i++) begin
            out[i] = in[7-i];
        end
        return out;
    endfunction

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            state <= IDLE;
            `ifndef SYNTHESIS
            cycle_count <= 0;
            `endif
        end else begin
            state <= next_state;
            `ifndef SYNTHESIS
            cycle_count <= cycle_count + 1;
            if (state != next_state) begin
                $display("FFT: Cycle %0d: State transition %s -> %s (stage=%0d, butterfly_idx=%0d)",
                         cycle_count, state.name(), next_state.name(), stage, butterfly_idx);
            end
            `endif
        end
    end

    always_comb begin
        next_state = state;

        case (state)
            IDLE: begin
                if (valid_i) begin
                    next_state = LOADING;
                end
            end

            LOADING: begin
                if (input_count >= FFT_SIZE) begin
                    next_state = BIT_REVERSE;
                end
            end

            BIT_REVERSE: begin
                if (bit_reverse_count >= FFT_SIZE - 1) begin
                    next_state = PROCESSING;
                end
            end

            PROCESSING: begin
                if (stage == STAGES && butterfly_idx == 0) begin
                    next_state = OUTPUTTING;
                end
            end

            OUTPUTTING: begin
                if (output_count == FFT_SIZE - 1 && ready_i) begin
                    next_state = IDLE;
                end
            end

            default: next_state = IDLE;
        endcase
    end

    initial begin
        for (int i = 0; i < FFT_SIZE; i++) begin
            buffer_real[i] = 0;
            buffer_imag[i] = 0;
            buffer_real_tmp[i] = 0;
            buffer_imag_tmp[i] = 0;
        end
    end

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            input_count <= 0;
        end else begin
            if ((state == LOADING || state == IDLE) && valid_i) begin
                buffer_real[input_count] <= data_real_i;
                buffer_imag[input_count] <= data_imag_i;

                `ifndef SYNTHESIS
                if (input_count < 4 || input_count >= FFT_SIZE - 2) begin
                    $display("FFT: Loading [%0d] = %0d", input_count, data_real_i);
                end
                `endif

                input_count <= input_count + 1;
            end else if (state == IDLE && !valid_i) begin
                input_count <= 0;
            end
        end
    end

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            bit_reverse_count <= 0;
        end else begin
            if (state == IDLE) begin
                bit_reverse_count <= 0;
            end else if (state == BIT_REVERSE && bit_reverse_count < FFT_SIZE) begin
                logic [7:0] rev_idx;
                rev_idx = bit_reverse(bit_reverse_count[7:0]);
                buffer_real_tmp[bit_reverse_count] <= buffer_real[rev_idx];
                buffer_imag_tmp[bit_reverse_count] <= buffer_imag[rev_idx];

                `ifndef SYNTHESIS
                if (bit_reverse_count < 4) begin
                    $display("FFT: Bit-reverse [%0d] <- [%0d], value=%0d", bit_reverse_count, rev_idx, buffer_real[rev_idx]);
                end
                `endif

                bit_reverse_count <= bit_reverse_count + 1;
            end
        end
    end

    always_comb begin
        group_size = 1 << (stage + 1);
        group_idx = butterfly_idx / (group_size >> 1);
        bf_pos = butterfly_idx % (group_size >> 1);
    end

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            stage <= 0;
            butterfly_idx <= 0;
            bf_in_a_real <= 0;
            bf_in_a_imag <= 0;
            bf_in_b_real <= 0;
            bf_in_b_imag <= 0;
            twiddle_idx <= 0;
            idx_a <= 0;
            idx_b <= 0;
            bf_valid <= 0;
        end else begin
            if (state == PROCESSING) begin
                if (stage >= STAGES) begin
                    stage <= STAGES;
                    butterfly_idx <= 0;
                    bf_valid <= 0;
                end else if (butterfly_idx < (FFT_SIZE >> 1)) begin
                    idx_a <= group_idx * group_size + bf_pos;
                    idx_b <= (group_idx * group_size + bf_pos) + (group_size >> 1);

                    if (stage[0] == 0) begin
                        bf_in_a_real <= buffer_real_tmp[group_idx * group_size + bf_pos];
                        bf_in_a_imag <= buffer_imag_tmp[group_idx * group_size + bf_pos];
                        bf_in_b_real <= buffer_real_tmp[(group_idx * group_size + bf_pos) + (group_size >> 1)];
                        bf_in_b_imag <= buffer_imag_tmp[(group_idx * group_size + bf_pos) + (group_size >> 1)];
                    end else begin
                        bf_in_a_real <= buffer_real[group_idx * group_size + bf_pos];
                        bf_in_a_imag <= buffer_imag[group_idx * group_size + bf_pos];
                        bf_in_b_real <= buffer_real[(group_idx * group_size + bf_pos) + (group_size >> 1)];
                        bf_in_b_imag <= buffer_imag[(group_idx * group_size + bf_pos) + (group_size >> 1)];
                    end

                    twiddle_idx <= (bf_pos * (FFT_SIZE >> (stage + 1)));

                    `ifndef SYNTHESIS
                    if (stage == 0 && butterfly_idx <= 5) begin
                        $display("FFT: Cycle %0d: Addr gen bf_idx=%0d -> idx_a=%0d, idx_b=%0d",
                                 cycle_count, butterfly_idx, group_idx * group_size + bf_pos,
                                 (group_idx * group_size + bf_pos) + (group_size >> 1));
                    end
                    `endif

                    bf_valid <= 1;
                    butterfly_idx <= butterfly_idx + 1;
                end else begin
                    bf_valid <= 0;
                    if (butterfly_idx == (FFT_SIZE >> 1) + BUTTERFLY_LATENCY) begin
                        butterfly_idx <= 0;
                        if (stage < STAGES - 1) begin
                            `ifndef SYNTHESIS
                            $display("FFT: Cycle %0d: Stage %0d -> %0d transition", cycle_count, stage, stage + 1);
                            if (stage[0] == 0) begin
                                $display("  Stage %0d output (in main buffer): [0]=%0d, [1]=%0d, [16]=%0d",
                                         stage, buffer_real[0], buffer_real[1], buffer_real[16]);
                            end else begin
                                $display("  Stage %0d output (in tmp buffer): [0]=%0d, [1]=%0d, [16]=%0d",
                                         stage, buffer_real_tmp[0], buffer_real_tmp[1], buffer_real_tmp[16]);
                            end
                            `endif
                            stage <= stage + 1;
                        end else begin
                            `ifndef SYNTHESIS
                            $display("FFT: Cycle %0d: All stages complete", cycle_count);
                            `endif
                            stage <= STAGES; 
                        end
                    end else begin
                        butterfly_idx <= butterfly_idx + 1;
                    end
                end
            end else if (state == IDLE || state == BIT_REVERSE) begin
                stage <= 0;
                butterfly_idx <= 0;
                bf_valid <= 0;
            end
        end
    end

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            bf_in_a_real_d <= 0;
            bf_in_a_imag_d <= 0;
            bf_in_b_real_d <= 0;
            bf_in_b_imag_d <= 0;
            idx_a_d <= 0;
            idx_b_d <= 0;
            stage_d <= 0;
            bf_valid_d <= 0;
        end else begin
            bf_in_a_real_d <= bf_in_a_real;
            bf_in_a_imag_d <= bf_in_a_imag;
            bf_in_b_real_d <= bf_in_b_real;
            bf_in_b_imag_d <= bf_in_b_imag;
            idx_a_d <= idx_a;
            idx_b_d <= idx_b;
            stage_d <= stage;
            bf_valid_d <= bf_valid;
        end
    end

    always_comb begin
        logic signed [2*DATA_WIDTH-1:0] mult_real, mult_imag;
        logic signed [DATA_WIDTH-1:0] wb_real, wb_imag;

        mult_real = (bf_in_b_real_d * twiddle_real - bf_in_b_imag_d * twiddle_imag);
        mult_imag = (bf_in_b_real_d * twiddle_imag + bf_in_b_imag_d * twiddle_real);

        wb_real = mult_real[2*DATA_WIDTH-2 -: DATA_WIDTH];
        wb_imag = mult_imag[2*DATA_WIDTH-2 -: DATA_WIDTH];

        bf_out_a_real = (bf_in_a_real_d + wb_real) >>> 1;
        bf_out_a_imag = (bf_in_a_imag_d + wb_imag) >>> 1;
        bf_out_b_real = (bf_in_a_real_d - wb_real) >>> 1;
        bf_out_b_imag = (bf_in_a_imag_d - wb_imag) >>> 1;
    end

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
        end else begin
            if (state == PROCESSING && bf_valid_d && stage_d < STAGES) begin
                if (stage_d[0] == 0) begin
                    buffer_real[idx_a_d] <= bf_out_a_real;
                    buffer_imag[idx_a_d] <= bf_out_a_imag;
                    buffer_real[idx_b_d] <= bf_out_b_real;
                    buffer_imag[idx_b_d] <= bf_out_b_imag;
                end else begin
                    buffer_real_tmp[idx_a_d] <= bf_out_a_real;
                    buffer_imag_tmp[idx_a_d] <= bf_out_a_imag;
                    buffer_real_tmp[idx_b_d] <= bf_out_b_real;
                    buffer_imag_tmp[idx_b_d] <= bf_out_b_imag;
                end

                `ifndef SYNTHESIS
                if (stage_d == 0 && idx_a_d <= 6) begin
                    $display("FFT: Cycle %0d: Writing stage=%0d, bf_idx=%0d: [%0d]=%0d+j%0d, [%0d]=%0d+j%0d (bf_in_a=%0d, bf_in_b=%0d, tw=%0d+j%0d)",
                             cycle_count, stage_d, butterfly_idx, idx_a_d, bf_out_a_real, bf_out_a_imag,
                             idx_b_d, bf_out_b_real, bf_out_b_imag,
                             bf_in_a_real_d, bf_in_b_real_d, twiddle_real, twiddle_imag);
                end
                `endif
            end
        end
    end

    fft_twiddle_256 u_twiddle (
        .clk_i(clk_i),
        .addr_i(twiddle_idx),
        .cos_o(twiddle_real),
        .sin_o(twiddle_imag)
    );

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            output_count <= 0;
            data_real_o <= 0;
            data_imag_o <= 0;
            valid_o <= 0;
        end else begin
            if (state == OUTPUTTING) begin
                if (ready_i || !valid_o) begin
                    if (STAGES[0] == 0) begin
                        data_real_o <= buffer_real_tmp[output_count];
                        data_imag_o <= buffer_imag_tmp[output_count];
                    end else begin
                        data_real_o <= buffer_real[output_count];
                        data_imag_o <= buffer_imag[output_count];
                    end
                    valid_o <= 1;

                    if (output_count < FFT_SIZE - 1) begin
                        output_count <= output_count + 1;
                    end
                end
            end else begin
                output_count <= 0;
                valid_o <= 0;
            end
        end
    end

    assign ready_o = (state == IDLE) || (state == LOADING);
    assign busy_o = (state != IDLE);

endmodule
