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
        input  logic       mic_sd_0,      // Mikrofon 0 + 1


        output logic       buffer_full,
        output logic       sd_ad2_test,  // I²S serial data output
        output logic       debug_tx_transmitting,  // Debug: TX state
        output logic       debug_tx_request,        // Debug: TX sample request
        output logic       sample_ready_o

    //---FFT Status Outputs---
        // output logic       fft_busy,       // FFT computation in progress
        // output logic       fft_output_valid // FFT output valid

    );
    logic resetb;
    assign resetb = ~btn_s1_resetb; 
    assign debug_led = ~debug_sample_led[5:0];

//--------------------------------------------------------------------------------------------------------
//  Debug LED og registerbank
//--------------------------------------------------------------------------------------------------------

    logic signed [23:0] sample_left, sample_right;
    logic        [5:0]  debug_sample_led;
//--------------------------------------------------------------------------------------------------------
//  Inter-module wiring
//--------------------------------------------------------------------------------------------------------
    logic               sample_ready; // Write valid from sampler
    logic signed [31:0] data_ram_o;         // 32-bit read data from RAM
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
        .ready_o   (sample_ready)        // output
    );

    assign buffer_full = buffer_ready;
    assign sample_ready_o = sample_ready;

    ram_logic u_ram (
        .clk_i              (clk),
        .rst_ni             (resetb),       // Active-low synchronous reset
        .write_data_i       ({8'b00000000, sample_left}),
        .write_valid_i      (sample_ready),       // Write request
        .write_ready_o      (),             // Ready to accept write
        .read_data_o        (data_ram_o),
        .read_ready_i       (read_ready),             // Reader ready for data
        .read_valid_o       (read_valid),             // Read data valid
        .buffer_ready_o     (buffer_ready),           // Pulse: full buffer ready for reading
        .buffer_overflow_o  (),   // Error: write to full system (drives top-level output)
        .write_count_o      (),              // Current write buffer fill level
        .read_count_o       (),              // Current read buffer position
        .debug_leds_o       () // Debug LED outputs
    );

    i2s_transmit_24 u_transmit (
        .clk_i                      (clk),
        .rst_ni                     (resetb),       // Active-low synchronous reset
        .sck_i                      (i2s_sck),           // input
        .ws_i                       (i2s_ws),            // input
        .ram_data_i                 (data_ram_o[23:0]),
        .ram_valid_i                (read_valid),
        .ram_ready_o                (read_ready),
        .buffer_ready_i             (buffer_ready),      // Buffer ready pulse from RAM
        .sd_o                       (sd_test_tansmit),
        .ws_o                       (ws_test_transmit),  // WS output for loopback
        .debug_state_transmitting   (debug_tx_transmitting),
        .debug_request_sample       (debug_tx_request)
    );

    logic signed [23:0] sample_left_ram, sample_right_ram;
    logic               buffer_ready_test;    // Buffer swap signal
    logic               sd_test_vu;           // I2S data to loopback capture
    logic               sd_test_tansmit;      // I2S data from transmit
    logic               ws_test_transmit;     // WS from transmit

    assign sd_ad2_test = sd_test_tansmit;
    assign sd_test_vu = sd_test_tansmit;


    i2s_capture_24 u_sampler_ram (
        .clk_i     (clk),               // input
        .rst_ni    (resetb),            // input
        .sck_i     (i2s_sck),           // input
        .ws_i      (ws_test_transmit),  // Use WS from transmitter for proper sync
        .sd_i      (sd_test_vu),        // input
        .left_o    (sample_left_ram),   // output [23:0]
        .right_o   (sample_right_ram),  // output [23:0]
        .ready_o   (buffer_ready_test)  // output
    );
    vu_meter_6led vu (
        .clk_i          (clk),
        .rst_ni         (resetb),
        .sample_stb_i   (buffer_ready_test),
        .left_sample_i  (sample_left_ram),
        .right_sample_i (sample_right_ram),
        .leds_o         (debug_sample_led)
    );
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



//--------------------------------------------------------------------------------------------------------
// FFT Module Integration
//--------------------------------------------------------------------------------------------------------
    // logic signed [23:0] fft_data_real_o;
    // logic signed [23:0] fft_data_imag_o;
    // logic               fft_valid_o;
    // logic               fft_ready_i;
    // logic               fft_busy_o;

    // // FFT reads from RAM buffer
    // fft_256 #(
    //     .DATA_WIDTH(24),
    //     .FFT_SIZE(256),
    //     .STAGES(8)
    // ) u_fft (
    //     .clk_i          (clk),
    //     .rst_ni         (resetb),
    //     .data_real_i    (data_ram_o[23:0]),  // Connect to RAM output
    //     .data_imag_i    (24'sd0),             // Real signal only
    //     .valid_i        (read_valid),         // RAM read valid
    //     .ready_o        (read_ready),         // FFT ready for input
    //     .data_real_o    (fft_data_real_o),    // Frequency bin real part
    //     .data_imag_o    (fft_data_imag_o),    // Frequency bin imaginary part
    //     .valid_o        (fft_valid_o),        // Output valid
    //     .ready_i        (fft_ready_i),        // Consumer ready
    //     .busy_o         (fft_busy_o)          // FFT busy computing
    // );

    // assign fft_busy = fft_busy_o;
    // assign fft_output_valid = fft_valid_o;

    // // FFT Output Consumer: Peak Detection
    // logic [7:0] current_bin;
    // logic [47:0] max_magnitude;
    // logic [7:0] peak_bin;
    // logic [5:0] fft_debug_leds;

    // always_ff @(posedge clk or negedge resetb) begin
    //     if (!resetb) begin
    //         current_bin <= 0;
    //         max_magnitude <= 0;
    //         peak_bin <= 0;
    //         fft_ready_i <= 1;
    //     end else begin
    //         if (fft_valid_o && fft_ready_i) begin
    //             // Calculate magnitude squared (real^2 + imag^2)
    //             logic [47:0] mag_sq;
    //             mag_sq = (fft_data_real_o * fft_data_real_o) +
    //                      (fft_data_imag_o * fft_data_imag_o);

    //             // Track maximum (peak detection)
    //             if (current_bin < 128) begin // Only check first half (Nyquist)
    //                 if (mag_sq > max_magnitude) begin
    //                     max_magnitude <= mag_sq;
    //                     peak_bin <= current_bin;
    //                 end
    //                 current_bin <= current_bin + 1;
    //             end else begin
    //                 // End of FFT frame - reset for next buffer
    //                 current_bin <= 0;
    //                 max_magnitude <= 0;
    //             end
    //         end
    //     end
    // end

    // // Display peak bin on LEDs (scaled to 6 LEDs)
    // assign fft_debug_leds = peak_bin[7:2]; // Divide by 4 to fit in 6 bits

    // // Update debug LED display
    // assign vu_debug_leds = fft_debug_leds;

    // // VU meter analog output placeholder
    // assign vu_analog_out = 1'b0;