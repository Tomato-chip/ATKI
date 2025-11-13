// ============================================================================
// fft_256 - 256-Point FFT with 24-bit Fixed-Point Precision
// ============================================================================
// Radix-2 Decimation-In-Time (DIT) FFT implementation
//
// Features:
//   - 256-point FFT (8 stages)
//   - 24-bit signed fixed-point arithmetic (Q1.23 format)
//   - Pipelined butterfly operations
//   - Streaming input/output with valid/ready handshaking
//   - Full complex output (real and imaginary)
//
// Timing:
//   - Input: 256 samples (streamed)
//   - Processing: ~512 cycles for 8 stages
//   - Output: 256 frequency bins (streamed)
//
// ============================================================================

module fft_256 #(
    parameter int DATA_WIDTH = 24,      // Bit width for real/imaginary parts
    parameter int FFT_SIZE = 256,       // FFT length
    parameter int STAGES = 8            // log2(256) = 8
) (
    input  logic                    clk_i,
    input  logic                    rst_ni,

    // Input stream (time-domain samples)
    input  logic signed [DATA_WIDTH-1:0] data_real_i,    // Real input
    input  logic signed [DATA_WIDTH-1:0] data_imag_i,    // Imaginary input (0 for real signals)
    input  logic                         valid_i,         // Input valid
    output logic                         ready_o,         // Ready to accept input

    // Output stream (frequency-domain bins)
    output logic signed [DATA_WIDTH-1:0] data_real_o,    // Real output
    output logic signed [DATA_WIDTH-1:0] data_imag_o,    // Imaginary output
    output logic                         valid_o,         // Output valid
    input  logic                         ready_i,         // Consumer ready

    // Status
    output logic                         busy_o           // FFT computation in progress
);

    // FSM States
    typedef enum logic [2:0] {
        IDLE,           // Waiting for input
        LOADING,        // Loading input samples
        BIT_REVERSE,    // Bit-reversal reordering
        PROCESSING,     // FFT computation stages
        OUTPUTTING      // Streaming results
    } state_t;

    state_t state, next_state;

    // Memory for ping-pong buffering
    logic signed [DATA_WIDTH-1:0] buffer_real [0:FFT_SIZE-1];
    logic signed [DATA_WIDTH-1:0] buffer_imag [0:FFT_SIZE-1];
    logic signed [DATA_WIDTH-1:0] buffer_real_tmp [0:FFT_SIZE-1];
    logic signed [DATA_WIDTH-1:0] buffer_imag_tmp [0:FFT_SIZE-1];

    // Control signals
    logic [7:0] input_count;        // Input sample counter
    logic [7:0] output_count;       // Output sample counter
    logic [2:0] stage;              // Current FFT stage
    logic [7:0] butterfly_idx;      // Butterfly index within stage

    // Butterfly computation signals
    logic signed [DATA_WIDTH-1:0] bf_in_a_real, bf_in_a_imag;
    logic signed [DATA_WIDTH-1:0] bf_in_b_real, bf_in_b_imag;
    logic signed [DATA_WIDTH-1:0] bf_out_a_real, bf_out_a_imag;
    logic signed [DATA_WIDTH-1:0] bf_out_b_real, bf_out_b_imag;
    logic signed [DATA_WIDTH-1:0] twiddle_real, twiddle_imag;
    logic [7:0] twiddle_idx;
    logic butterfly_valid;

    // Bit-reversal function
    function automatic logic [7:0] bit_reverse(input logic [7:0] in);
        logic [7:0] out;
        for (int i = 0; i < 8; i++) begin
            out[i] = in[7-i];
        end
        return out;
    endfunction

    // ========================================================================
    // FSM - State Register
    // ========================================================================
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end

    // ========================================================================
    // FSM - Next State Logic
    // ========================================================================
    always_comb begin
        next_state = state;

        case (state)
            IDLE: begin
                if (valid_i) begin
                    next_state = LOADING;
                end
            end

            LOADING: begin
                if (input_count == FFT_SIZE - 1 && valid_i) begin
                    next_state = BIT_REVERSE;
                end
            end

            BIT_REVERSE: begin
                next_state = PROCESSING;
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

    // ========================================================================
    // Input Loading
    // ========================================================================
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            input_count <= 0;
            for (int i = 0; i < FFT_SIZE; i++) begin
                buffer_real[i] <= 0;
                buffer_imag[i] <= 0;
            end
        end else begin
            if (state == LOADING && valid_i) begin
                buffer_real[input_count] <= data_real_i;
                buffer_imag[input_count] <= data_imag_i;
                input_count <= input_count + 1;
            end else if (state == IDLE) begin
                input_count <= 0;
            end
        end
    end

    // ========================================================================
    // Bit-Reversal Reordering
    // ========================================================================
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            for (int i = 0; i < FFT_SIZE; i++) begin
                buffer_real_tmp[i] <= 0;
                buffer_imag_tmp[i] <= 0;
            end
        end else if (state == BIT_REVERSE) begin
            for (int i = 0; i < FFT_SIZE; i++) begin
                logic [7:0] rev_idx = bit_reverse(i[7:0]);
                buffer_real_tmp[i] <= buffer_real[rev_idx];
                buffer_imag_tmp[i] <= buffer_imag[rev_idx];
            end
        end
    end

    // ========================================================================
    // FFT Stage Processing
    // ========================================================================
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            stage <= 0;
            butterfly_idx <= 0;
        end else begin
            if (state == PROCESSING) begin
                // Process butterflies in current stage
                if (butterfly_idx < (FFT_SIZE >> 1)) begin
                    // Compute butterfly
                    logic [7:0] group_size = 1 << (stage + 1);
                    logic [7:0] group_idx = butterfly_idx / (group_size >> 1);
                    logic [7:0] bf_pos = butterfly_idx % (group_size >> 1);
                    logic [7:0] idx_a = group_idx * group_size + bf_pos;
                    logic [7:0] idx_b = idx_a + (group_size >> 1);

                    // Read butterfly inputs
                    if (stage == 0) begin
                        bf_in_a_real <= buffer_real_tmp[idx_a];
                        bf_in_a_imag <= buffer_imag_tmp[idx_a];
                        bf_in_b_real <= buffer_real_tmp[idx_b];
                        bf_in_b_imag <= buffer_imag_tmp[idx_b];
                    end else begin
                        bf_in_a_real <= buffer_real[idx_a];
                        bf_in_a_imag <= buffer_imag[idx_a];
                        bf_in_b_real <= buffer_real[idx_b];
                        bf_in_b_imag <= buffer_imag[idx_b];
                    end

                    // Twiddle factor index
                    twiddle_idx <= (bf_pos * (FFT_SIZE >> (stage + 1)));

                    butterfly_idx <= butterfly_idx + 1;
                end else begin
                    // Move to next stage
                    butterfly_idx <= 0;
                    if (stage < STAGES - 1) begin
                        stage <= stage + 1;
                    end else begin
                        stage <= STAGES; // Signal completion
                    end
                end
            end else if (state == IDLE || state == BIT_REVERSE) begin
                stage <= 0;
                butterfly_idx <= 0;
            end
        end
    end

    // ========================================================================
    // Butterfly Computation (Radix-2 DIT)
    // ========================================================================
    // Butterfly equations:
    //   A' = A + W * B
    //   B' = A - W * B
    // Where W is the twiddle factor e^(-j*2*pi*k/N)

    always_comb begin
        // Complex multiplication: (b_real + j*b_imag) * (w_real + j*w_imag)
        logic signed [2*DATA_WIDTH-1:0] mult_real, mult_imag;

        mult_real = (bf_in_b_real * twiddle_real - bf_in_b_imag * twiddle_imag);
        mult_imag = (bf_in_b_real * twiddle_imag + bf_in_b_imag * twiddle_real);

        // Scale back to DATA_WIDTH (Q1.23 format)
        logic signed [DATA_WIDTH-1:0] wb_real = mult_real[2*DATA_WIDTH-2 -: DATA_WIDTH];
        logic signed [DATA_WIDTH-1:0] wb_imag = mult_imag[2*DATA_WIDTH-2 -: DATA_WIDTH];

        // Butterfly outputs
        bf_out_a_real = bf_in_a_real + wb_real;
        bf_out_a_imag = bf_in_a_imag + wb_imag;
        bf_out_b_real = bf_in_a_real - wb_real;
        bf_out_b_imag = bf_in_a_imag - wb_imag;
    end

    // Write butterfly results back to buffer
    always_ff @(posedge clk_i) begin
        if (state == PROCESSING && butterfly_idx > 0) begin
            logic [7:0] group_size = 1 << (stage + 1);
            logic [7:0] group_idx = (butterfly_idx - 1) / (group_size >> 1);
            logic [7:0] bf_pos = (butterfly_idx - 1) % (group_size >> 1);
            logic [7:0] idx_a = group_idx * group_size + bf_pos;
            logic [7:0] idx_b = idx_a + (group_size >> 1);

            buffer_real[idx_a] <= bf_out_a_real;
            buffer_imag[idx_a] <= bf_out_a_imag;
            buffer_real[idx_b] <= bf_out_b_real;
            buffer_imag[idx_b] <= bf_out_b_imag;
        end
    end

    // ========================================================================
    // Twiddle Factor ROM
    // ========================================================================
    fft_twiddle_256 u_twiddle (
        .clk_i(clk_i),
        .addr_i(twiddle_idx),
        .cos_o(twiddle_real),
        .sin_o(twiddle_imag)
    );

    // ========================================================================
    // Output Streaming
    // ========================================================================
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            output_count <= 0;
            data_real_o <= 0;
            data_imag_o <= 0;
            valid_o <= 0;
        end else begin
            if (state == OUTPUTTING) begin
                if (ready_i || !valid_o) begin
                    data_real_o <= buffer_real[output_count];
                    data_imag_o <= buffer_imag[output_count];
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

    // ========================================================================
    // Control Outputs
    // ========================================================================
    assign ready_o = (state == IDLE) || (state == LOADING && input_count < FFT_SIZE);
    assign busy_o = (state != IDLE);

endmodule
