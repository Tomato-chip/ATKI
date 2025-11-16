// ============================================================================
// fpga_template_top - FPGA I2S Audio Capture System with FFT
// ============================================================================
// Top-level module integrating:
//   - I2S clock generation and audio capture (24-bit samples)
//   - Ping-pong RAM buffering (256 samples per buffer)
//   - FFT spectrum analysis (256-point)
//   - VU meter with 6-LED output
//
// Data Flow:
//   I2S Mic -> i2s_capture_24 -> RAM Ping-Pong Buffer -> FFT -> Spectrum Analysis
//
// Reset: Tang Nano 20K button pulls HIGH when pressed (inverted to active-high)
// ============================================================================

// import fpga_template_pkg::*; 

module fpga_template_top (
        input   clk,
    //---Debug---------
        output  [5:0] debug_led,
        input   btn_s1_resetb,     // Button 1 input
        input   btn_s2,            // Button 2 input
    //---I2S sampler outputs MIC---
        output logic       i2s_sck,
        output logic       i2s_ws,
        // input  logic       mic_sd_0,      // Mikrofon 0 + 1 (now driven by pcm_rom)
        output logic       buffer_full,
    //---Analog VU Meter Output for Oscilloscope---
        output logic       vu_analog_out,  // PWM output for scope viewing
    //---FFT Status Outputs---
        output logic       fft_busy,       // FFT computation in progress
        output logic       fft_output_valid // FFT output valid
    );
    logic resetb;
        assign resetb = ~btn_s1_resetb; 
//--------------------------------------------------------------------------------------------------------
//  Debug LED og registerbank
//--------------------------------------------------------------------------------------------------------

    // Switch between VU meter LEDs, RAM debug LEDs, and VU debug using button 2
    logic [5:0] ram_debug_leds;
    logic [5:0] vu_debug_leds;
    // assign debug_led =  ~debug_sample_led[5:0];  // Show VU meter output
    assign debug_led =  ~vu_debug_leds;  // Show debug: state machine


    logic signed [23:0] sample_left, sample_right;
    logic        [5:0]  debug_sample_led;
    logic               mic_sd_0;         // Internal I²S data from pcm_rom
//--------------------------------------------------------------------------------------------------------
//  PCM ROM for Test Input (I²S Microphone Emulator)
//--------------------------------------------------------------------------------------------------------

    pcm_rom #(
        .WIDTH(24),
        .ADDR_WIDTH(8)
    ) u_pcm_rom (
        .clk_i  (clk),
        .rst_ni (resetb),
        .sck_i  (i2s_sck),
        .ws_i   (i2s_ws),
        .sd_o   (mic_sd_0)
    );

//--------------------------------------------------------------------------------------------------------
//  Inter-module wiring
//--------------------------------------------------------------------------------------------------------
    logic               sample_ready; // Write valid from sampler
    logic signed [35:0] data_ram_o;         // 36-bit read data from RAM
    logic               read_valid;      // Read data valid
    logic               read_ready;      // VU meter ready to consume
    logic               buffer_ready;    // Buffer swap signal
//--------------------------------------------------------------------------------------------------------

    i2s_capture_24 u_sampler (
        .clk_i     (clk),               // input
        .rst_ni    (resetb),            // input
        .sck_i     (i2s_sck),           // input
        .ws_i      (i2s_ws),            // input
        .sd_i      (mic_sd_0),          // input
        .left_o    (sample_left),       // output [23:0]
        .right_o   (sample_right),      // output [23:0]
        .ready_o   (sample_ready)       // output
    );

    assign buffer_full = sample_ready;

    ram_logic u_ram (
        .clk_i              (clk),
        .rst_ni             (resetb),       // Active-low synchronous reset
        .write_data_i       ({sample_right[23:6], sample_left[23:6]}),      // bruger kun MSB 18bit 
        .write_valid_i      (sample_ready),       // Write request
        .write_ready_o      (),             // Ready to accept write
        .read_data_o        (data_ram_o),
        .read_ready_i       (read_ready),             // Reader ready for data
        .read_valid_o       (read_valid),             // Read data valid
        .buffer_ready_o     (buffer_ready),           // Pulse: full buffer ready for reading
        .buffer_overflow_o  (),   // Error: write to full system (drives top-level output)
        .write_count_o      (),              // Current write buffer fill level
        .read_count_o       (),              // Current read buffer position
        .debug_leds_o       (ram_debug_leds) // Debug LED outputs
    );

//--------------------------------------------------------------------------------------------------------
// FFT Module Integration
//--------------------------------------------------------------------------------------------------------
    logic signed [17:0] fft_data_real_o;
    logic signed [17:0] fft_data_imag_o;
    logic               fft_valid_o;
    logic               fft_ready_i;
    logic               fft_busy_o;

    // FFT reads from RAM buffer
    fft_256 #(
        .DATA_WIDTH(18),
        .FFT_SIZE(256),
        .STAGES(8)
    ) u_fft (
        .clk_i          (clk),
        .rst_ni         (resetb),
        .data_real_i    (data_ram_o[17:0]),   // Connect to RAM output (Only LEFT sample)
        .data_imag_i    (18'sd0),             // Real signal only
        .valid_i        (read_valid),         // RAM read valid
        .ready_o        (read_ready),         // FFT ready for input
        .data_real_o    (fft_data_real_o),    // Frequency bin real part
        .data_imag_o    (fft_data_imag_o),    // Frequency bin imaginary part
        .valid_o        (fft_valid_o),        // Output valid
        .ready_i        (fft_ready_i),        // Consumer ready
        .busy_o         (fft_busy_o)          // FFT busy computing
    );

    assign fft_busy = fft_busy_o;
    assign fft_output_valid = fft_valid_o;

    // FFT Output Consumer: Peak Detection
    logic [7:0] current_bin;
    logic [47:0] max_magnitude;
    logic [7:0] peak_bin;
    logic [5:0] fft_debug_leds;

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

    // Update debug LED display
    assign vu_debug_leds = fft_debug_leds;

    // VU meter analog output placeholder
    assign vu_analog_out = 1'b0;

//--------------------------------------------------------------------------------------------------------
// Clock Generator
//--------------------------------------------------------------------------------------------------------

    // Generate I2S clock
    i2s_clock_gen u_i2s_clock (
        .clk_i        ( clk),
        .rst_ni       ( resetb),
        .sck_o         ( i2s_sck),
        .ws_o          ( i2s_ws),
        .frame_start_o ( )
    );

endmodule
