// ============================================================================
// fpga_template_fft_example - Audio Capture with FFT Spectrum Analysis
// ============================================================================
// Example integration of the FFT module with the existing audio capture system
//
// This module extends fpga_template_top by adding FFT spectrum analysis
// to the audio data from the RAM buffer.
//
// Data Flow:
//   I2S Mic -> i2s_capture_24 -> RAM Buffer -> FFT -> Spectrum Output
//                                           \-> VU Meter -> LEDs
//
// Usage:
//   - Connect the FFT module to the RAM read output
//   - FFT processes each 256-sample buffer automatically
//   - Output provides 256 frequency bins (real + imaginary)
// ============================================================================

module fpga_template_fft_example (
    input   clk,

    //---Debug---------
    output  [5:0] debug_led,
    input   btn_s1_resetb,     // Button 1 input (reset)
    input   btn_s2,            // Button 2 input (mode select)

    //---I2S sampler outputs MIC---
    output logic       i2s_sck,
    output logic       i2s_ws,
    input  logic       mic_sd_0,
    output logic       buffer_full,

    //---Analog VU Meter Output---
    output logic       vu_analog_out,

    //---FFT Status---
    output logic       fft_busy,
    output logic       fft_valid
);

    logic resetb;
    assign resetb = ~btn_s1_resetb;

    // ========================================================================
    // Audio Capture and RAM Buffering (existing system)
    // ========================================================================
    logic signed [23:0] sample_left, sample_right;
    logic [5:0] debug_sample_led;
    logic [5:0] ram_debug_leds;
    logic [5:0] vu_debug_leds;

    logic               sample_ready;
    logic signed [31:0] data_ram_o;
    logic               read_valid;
    logic               read_ready;
    logic               buffer_ready;

    // I2S Audio Capture
    i2s_capture_24 u_sampler (
        .clk_i     (clk),
        .rst_ni    (resetb),
        .sck_i     (i2s_sck),
        .ws_i      (i2s_ws),
        .sd_i      (mic_sd_0),
        .left_o    (sample_left),
        .right_o   (sample_right),
        .ready_o   (sample_ready)
    );

    assign buffer_full = sample_ready;

    // RAM Ping-Pong Buffer
    ram_logic u_ram (
        .clk_i              (clk),
        .rst_ni             (resetb),
        .write_data_i       ({8'b00000000, sample_left}),
        .write_valid_i      (sample_ready),
        .write_ready_o      (),
        .read_data_o        (data_ram_o),
        .read_ready_i       (read_ready),
        .read_valid_o       (read_valid),
        .buffer_ready_o     (buffer_ready),
        .buffer_overflow_o  (),
        .write_count_o      (),
        .read_count_o       (),
        .debug_leds_o       (ram_debug_leds)
    );

    // ========================================================================
    // FFT Module Integration
    // ========================================================================
    logic signed [23:0] fft_data_real_o;
    logic signed [23:0] fft_data_imag_o;
    logic               fft_valid_o;
    logic               fft_ready_i;
    logic               fft_busy_o;

    // FFT reads from RAM buffer when buffer is ready
    fft_256 #(
        .DATA_WIDTH(24),
        .FFT_SIZE(256),
        .STAGES(8)
    ) u_fft (
        .clk_i          (clk),
        .rst_ni         (resetb),
        .data_real_i    (data_ram_o[23:0]),  // Connect to RAM output
        .data_imag_i    (24'sd0),             // Real signal only
        .valid_i        (read_valid),         // RAM read valid
        .ready_o        (read_ready),         // FFT ready for input
        .data_real_o    (fft_data_real_o),    // Frequency bin real part
        .data_imag_o    (fft_data_imag_o),    // Frequency bin imaginary part
        .valid_o        (fft_valid_o),        // Output valid
        .ready_i        (fft_ready_i),        // Consumer ready
        .busy_o         (fft_busy_o)          // FFT busy computing
    );

    assign fft_busy = fft_busy_o;
    assign fft_valid = fft_valid_o;

    // ========================================================================
    // FFT Output Processing (Example: Peak Detection)
    // ========================================================================
    logic [7:0] current_bin;
    logic [47:0] max_magnitude;
    logic [7:0] peak_bin;
    logic [5:0] fft_debug_leds;

    // Simple consumer: find peak frequency
    always_ff @(posedge clk or negedge resetb) begin
        if (!resetb) begin
            current_bin <= 0;
            max_magnitude <= 0;
            peak_bin <= 0;
            fft_ready_i <= 1;
        end else begin
            if (fft_valid_o && fft_ready_i) begin
                // Calculate magnitude squared (real^2 + imag^2)
                logic [47:0] mag_sq;
                mag_sq = (fft_data_real_o * fft_data_real_o) +
                         (fft_data_imag_o * fft_data_imag_o);

                // Track maximum (peak detection)
                if (current_bin < 128) begin // Only check first half (Nyquist)
                    if (mag_sq > max_magnitude) begin
                        max_magnitude <= mag_sq;
                        peak_bin <= current_bin;
                    end
                    current_bin <= current_bin + 1;
                end else begin
                    // End of FFT frame - reset for next buffer
                    current_bin <= 0;
                    max_magnitude <= 0;
                end
            end
        end
    end

    // Display peak bin on LEDs (scaled to 6 LEDs)
    assign fft_debug_leds = peak_bin[7:2]; // Divide by 4 to fit in 6 bits

    // ========================================================================
    // VU Meter (parallel processing)
    // ========================================================================
    // Note: This example removes VU meter to simplify. You can add it back
    // by creating a second RAM consumer or using a multiplexer to share
    // the RAM output between FFT and VU meter.

    // ========================================================================
    // Debug LED Selection
    // ========================================================================
    // Use button 2 to toggle between RAM debug and FFT debug
    logic display_mode;
    always_ff @(posedge clk or negedge resetb) begin
        if (!resetb) begin
            display_mode <= 0;
        end else if (btn_s2) begin
            display_mode <= ~display_mode;
        end
    end

    assign debug_led = display_mode ? ~fft_debug_leds : ~ram_debug_leds;

    // ========================================================================
    // I2S Clock Generator
    // ========================================================================
    i2s_clock_gen u_i2s_clock (
        .clk_i        (clk),
        .rst_ni       (resetb),
        .sck_o        (i2s_sck),
        .ws_o         (i2s_ws),
        .frame_start_o()
    );

    // VU meter analog output (placeholder)
    assign vu_analog_out = 1'b0;

endmodule


// ============================================================================
// Integration Notes
// ============================================================================
// To integrate the FFT module into your existing fpga_template_top:
//
// 1. Add the FFT instance as shown above
// 2. Connect the FFT input to the RAM read output (data_ram_o)
// 3. The FFT will automatically process each 256-sample buffer
// 4. Process FFT output bins as needed (e.g., peak detection, visualization)
//
// For dual consumers (VU meter + FFT):
// - Option A: Use an arbiter to time-multiplex RAM access
// - Option B: Add a second RAM buffer
// - Option C: Tap the data stream before RAM and feed both modules
//
// FFT Output Interpretation:
// - Bins 0-127: Positive frequencies (0 to Nyquist)
// - Bin 0: DC component
// - Bin k: Frequency = k * (sample_rate / 256)
// - Example: If sample rate is 48kHz, bin 16 = 16 * (48000/256) = 3kHz
//
// Performance:
// - Processing latency: ~512 clock cycles per FFT
// - For 27MHz clock: ~19μs per FFT
// - At 3.3kHz buffer rate: FFT completes well before next buffer
// ============================================================================
