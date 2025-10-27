// ============================================================================
// fpga_template_top - FPGA I2S Audio Capture System
// ============================================================================
// Top-level module integrating:
//   - I2S clock generation and audio capture (24-bit samples)
//   - Ping-pong RAM buffering (256 samples per buffer)
//   - VU meter with 6-LED output
//
// Data Flow:
//   I2S Mic -> i2s_capture_24 -> RAM Ping-Pong Buffer -> VU Meter -> LEDs
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

        output logic       buffer_full

    );
    wire resetb;
        assign resetb = btn_s1_resetb; 
//--------------------------------------------------------------------------------------------------------
//  Debug LED og registerbank 
//--------------------------------------------------------------------------------------------------------

    assign debug_led = ~debug_sample_led[5:0];

    wire [23:0] sample_left, sample_right;
    wire [5:0]  debug_sample_led;
//--------------------------------------------------------------------------------------------------------
//  Inter-module wiring
//--------------------------------------------------------------------------------------------------------
    // Sampler -> RAM path (write interface)
    logic [31:0] sampler_to_ram_32_data_w;      // 32-bit data: {8'b0, sample_left[23:0]}
    logic        sampler_to_ram_write_request_w; // Write valid from sampler

    // RAM -> VU Meter path (read interface)
    logic [31:0] ram_to_6led_32_data_w;         // 32-bit read data from RAM
    logic        ram_to_6led_read_valid_w;      // Read data valid
    logic        ram_to_6led_read_ready_w;      // VU meter ready to consume
    logic        ram_to_6led_buffer_ready_w;    // Buffer swap signal

    // Zero-pad 24-bit sample to 32-bit RAM word
    assign sampler_to_ram_32_data_w = {8'b00000000, sample_left};    // Pad to 32-bit

//--------------------------------------------------------------------------------------------------------

    i2s_capture_24 u_sampler (
        .clk_i     (clk),               // input
        .rst_ni    (resetb),            // input
        .sck_i     (i2s_sck),           // input
        .ws_i      (i2s_ws),            // input
        .sd_i      (mic_sd_0),          // input
        .left_o    (sample_left),  // output [23:0]
        .right_o   (sample_right),      // output [23:0]
        .ready_o   (sampler_to_ram_write_request_w)        // output
    );

    ram_logic u_ram (
        .clk_i              (clk),
        .rst_ni             (resetb),       // Active-low synchronous reset
        .write_data_i       (sampler_to_ram_32_data_w),
        .write_valid_i      (sampler_to_ram_write_request_w),       // Write request
        .write_ready_o      (),             // Ready to accept write
        .read_data_o        (ram_to_6led_32_data_w),
        .read_ready_i       (ram_to_6led_read_ready_w),             // Reader ready for data
        .read_valid_o       (ram_to_6led_read_valid_w),             // Read data valid
        .buffer_ready_o     (ram_to_6led_buffer_ready_w),           // Pulse: full buffer ready for reading
        .buffer_overflow_o  (buffer_full),   // Error: write to full system (drives top-level output)
        .write_count_o      (),              // Current write buffer fill level
        .read_count_o       ()               // Current read buffer position
    );

    // VU-meter på KUN én kanal (vælg her: 1=venstre, 0=højre)
    vu_meter_6led vu (
        .clk_i          (clk),
        .rst_ni         (resetb),
        .sample_valid_i (ram_to_6led_read_valid_w), // fra cap.ready_o
        .left_sample_i  (sample_left),
        .right_sample_i (sample_right),
        .leds_o         (debug_sample_led),        // forbind til dine 6 LED pins i .cst

        .ram_read_data_i     (ram_to_6led_32_data_w[23:0]),       // From ram_logic.read_data_o
        .ram_read_valid_i    (ram_to_6led_read_valid_w),       // From ram_logic.read_valid_o
        .ram_read_ready_o    (ram_to_6led_read_ready_w),       // To ram_logic.read_ready_i
        .ram_buffer_ready_i  (ram_to_6led_buffer_ready_w)        // From ram_logic.buffer_ready_o (optional)
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
