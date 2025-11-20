//==============================================================================
// i2s_sine_generator.sv
// Generates I2S-compatible sine wave PCM audio for testing
//==============================================================================
// Generates SCK, WS, and SD signals for I2S interface with configurable
// sine wave frequency and amplitude.
//
// Features:
//   - Generates 24-bit signed PCM audio samples
//   - Configurable sine frequency via lookup table
//   - Outputs standard I2S timing: SCK, WS (Word Select), SD (Serial Data)
//   - Compatible with i2s_capture_24 module
//
// Parameters:
//   CLK_FREQ    - System clock frequency in Hz (default 27 MHz)
//   SAMPLE_RATE - Audio sample rate in Hz (default 48 kHz)
//   SINE_FREQ   - Sine wave frequency in Hz (default 1 kHz)
//
// I2S Timing:
//   - SCK = CLK_FREQ / 64 = 421.875 kHz (for 27 MHz clock)
//   - WS = SCK / 64 = 6.59 kHz frame rate (32 bits per channel)
//   - Actual sample rate determined by WS toggles
//==============================================================================

module i2s_sine_generator #(
    parameter int unsigned CLK_FREQ    = 27_000_000,  // 27 MHz system clock
    parameter int unsigned SAMPLE_RATE = 48_000,      // 48 kHz audio
    parameter int unsigned SINE_FREQ   = 1_000        // 1 kHz test tone
) (
    input  logic clk_i,        // System clock
    input  logic rst_ni,       // Active-low synchronous reset

    // I2S outputs (connect to I2S receiver inputs)
    output logic sck_o,        // Serial clock (bit clock)
    output logic ws_o,         // Word select (0=Left, 1=Right)
    output logic sd_o          // Serial data (MSB first)
);

    //==========================================================================
    // Clock Divider for SCK Generation
    //==========================================================================
    // Generate SCK at CLK_FREQ/64 (for 27 MHz: 421.875 kHz)
    // This provides 64 SCK cycles per frame (32 per channel)

    localparam int unsigned SCK_DIVIDER = 32;  // Divide by 64 (toggle every 32)
    logic [$clog2(SCK_DIVIDER)-1:0] sck_count_q;
    logic sck_q;

    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            sck_count_q <= '0;
            sck_q <= 1'b0;
        end else begin
            if (sck_count_q == SCK_DIVIDER - 1) begin
                sck_count_q <= '0;
                sck_q <= ~sck_q;
            end else begin
                sck_count_q <= sck_count_q + 1'b1;
            end
        end
    end

    assign sck_o = sck_q;

    // Edge detection for SCK
    logic sck_d;
    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            sck_d <= 1'b0;
        end else begin
            sck_d <= sck_q;
        end
    end
    wire sck_rising = ~sck_d & sck_q;

    //==========================================================================
    // Sine Wave Lookup Table
    //==========================================================================
    // 64-sample sine wave lookup table (one complete cycle)
    // Values are 24-bit signed PCM (-8388608 to +8388607)
    // Scaled to 80% amplitude to avoid clipping

    localparam int SINE_TABLE_SIZE = 64;
    logic signed [23:0] sine_table [0:SINE_TABLE_SIZE-1];

    initial begin
        // Pre-calculated sine values (80% amplitude)
        sine_table[0]  = 24'sd0;
        sine_table[1]  = 24'sd524287;
        sine_table[2]  = 24'sd1048319;
        sine_table[3]  = 24'sd1571839;
        sine_table[4]  = 24'sd2094079;
        sine_table[5]  = 24'sd2614783;
        sine_table[6]  = 24'sd3133695;
        sine_table[7]  = 24'sd3650559;
        sine_table[8]  = 24'sd4165119;
        sine_table[9]  = 24'sd4677119;
        sine_table[10] = 24'sd5186303;
        sine_table[11] = 24'sd5692415;
        sine_table[12] = 24'sd6195199;
        sine_table[13] = 24'sd6694399;
        sine_table[14] = 24'sd7189759;
        sine_table[15] = 24'sd7681023;
        sine_table[16] = 24'sd8167935;
        sine_table[17] = 24'sd8650239;
        sine_table[18] = 24'sd9127679;
        sine_table[19] = 24'sd9600000;
        sine_table[20] = 24'sd10066943;
        sine_table[21] = 24'sd10528255;
        sine_table[22] = 24'sd10983679;
        sine_table[23] = 24'sd11432959;
        sine_table[24] = 24'sd11875839;
        sine_table[25] = 24'sd12312063;
        sine_table[26] = 24'sd12741375;
        sine_table[27] = 24'sd13163519;
        sine_table[28] = 24'sd13578239;
        sine_table[29] = 24'sd13985279;
        sine_table[30] = 24'sd14384383;
        sine_table[31] = 24'sd14775295;
        sine_table[32] = 24'sd15157759;
        sine_table[33] = 24'sd15531519;
        sine_table[34] = 24'sd15896319;
        sine_table[35] = 24'sd16251903;
        sine_table[36] = 24'sd16598015;
        sine_table[37] = 24'sd16934399;
        sine_table[38] = 24'sd17260799;
        sine_table[39] = 24'sd17576959;
        sine_table[40] = 24'sd17882623;
        sine_table[41] = 24'sd18177535;
        sine_table[42] = 24'sd18461439;
        sine_table[43] = 24'sd18734079;
        sine_table[44] = 24'sd18995199;
        sine_table[45] = 24'sd19244543;
        sine_table[46] = 24'sd19481855;
        sine_table[47] = 24'sd19706879;
        sine_table[48] = 24'sd19919359;
        sine_table[49] = 24'sd20119039;
        sine_table[50] = 24'sd20305663;
        sine_table[51] = 24'sd20478975;
        sine_table[52] = 24'sd20638719;
        sine_table[53] = 24'sd20784639;
        sine_table[54] = 24'sd20916479;
        sine_table[55] = 24'sd21033983;
        sine_table[56] = 24'sd21136895;
        sine_table[57] = 24'sd21224959;
        sine_table[58] = 24'sd21297919;
        sine_table[59] = 24'sd21355519;
        sine_table[60] = 24'sd21397503;
        sine_table[61] = 24'sd21423615;
        sine_table[62] = 24'sd21433599;
        sine_table[63] = 24'sd21427199;
    end

    //==========================================================================
    // Sample Generation
    //==========================================================================
    // Calculate phase increment to achieve desired sine frequency
    // phase_inc = (SINE_FREQ * SINE_TABLE_SIZE) / SAMPLE_RATE
    // For 1 kHz sine at 48 kHz sample rate: (1000 * 64) / 48000 = 1.33

    localparam real PHASE_INCREMENT_REAL = (real'(SINE_FREQ) * real'(SINE_TABLE_SIZE)) / real'(SAMPLE_RATE);
    localparam int unsigned PHASE_INCREMENT = int'(PHASE_INCREMENT_REAL * 256.0);  // Fixed-point 8.8

    logic [15:0] phase_acc_q;  // Phase accumulator (8.8 fixed point)
    logic [5:0]  table_index;  // Index into sine table (0-63)

    assign table_index = phase_acc_q[13:8];  // Extract integer part

    logic signed [23:0] current_sample_q;

    //==========================================================================
    // WS (Word Select) and Frame Counter
    //==========================================================================
    // WS toggles every 32 SCK cycles (one channel per half-frame)
    // Counts to 64 for complete L+R frame

    logic [5:0] bit_count_q;    // Counts 0-63 (32 bits per channel)
    logic ws_q;

    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            bit_count_q <= '0;
            ws_q <= 1'b0;
            phase_acc_q <= '0;
            current_sample_q <= '0;
        end else begin
            if (sck_rising) begin
                bit_count_q <= bit_count_q + 1'b1;

                // Toggle WS every 32 bits (at end of each channel)
                if (bit_count_q == 6'd31 || bit_count_q == 6'd63) begin
                    ws_q <= ~ws_q;

                    // Generate new sample at start of left channel
                    if (bit_count_q == 6'd63) begin
                        current_sample_q <= sine_table[table_index];
                        phase_acc_q <= phase_acc_q + PHASE_INCREMENT[7:0];
                    end
                end
            end
        end
    end

    assign ws_o = ws_q;

    //==========================================================================
    // Serial Data Output (SD)
    //==========================================================================
    // Output 25 bits: 1 dummy bit + 24 PCM bits (MSB first)
    // Bits 0-24: actual transmission
    // Bits 25-31: padding (ignored by receiver)

    logic [24:0] shift_reg_q;
    logic [4:0]  bit_position;  // Position within 32-bit slot

    assign bit_position = bit_count_q[4:0];  // Lower 5 bits = position in channel

    always_ff @(posedge clk_i) begin
        if (!rst_ni) begin
            shift_reg_q <= '0;
            sd_o <= 1'b0;
        end else begin
            if (sck_rising) begin
                // Load shift register at start of each channel
                if (bit_position == 5'd0) begin
                    shift_reg_q <= {1'b0, current_sample_q};  // Add dummy MSB
                    sd_o <= 1'b0;  // Dummy bit = 0
                end else if (bit_position < 5'd25) begin
                    // Shift out bits 1-24
                    sd_o <= shift_reg_q[24];
                    shift_reg_q <= {shift_reg_q[23:0], 1'b0};
                end else begin
                    // Padding bits (25-31) = 0
                    sd_o <= 1'b0;
                end
            end
        end
    end

endmodule
