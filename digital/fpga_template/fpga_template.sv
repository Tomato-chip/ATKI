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
        output logic       buffer_full,
    //---Analog VU Meter Output for Oscilloscope---
        output logic       vu_analog_out   // PWM output for scope viewing
    );
    logic resetb;
        assign resetb = ~btn_s1_resetb; 
//--------------------------------------------------------------------------------------------------------
//  Debug LED og registerbank
//--------------------------------------------------------------------------------------------------------

    // Switch between VU meter LEDs, RAM debug LEDs, and VU debug using button 2
    logic [5:0] ram_debug_leds;
    logic [5:0] vu_debug_leds;
    // assign debug_led =  ~debug_sample_led[5:0];
    assign debug_led =  ~vu_debug_leds;  // Show VU meter debug


    logic signed [23:0] sample_left, sample_right;
    logic        [5:0]  debug_sample_led;
//--------------------------------------------------------------------------------------------------------
//  Inter-module wiring
//--------------------------------------------------------------------------------------------------------
    logic               sample_ready; // Write valid from sampler
    // logic signed [31:0] data_ram_o;         // 32-bit read data from RAM
    logic signed [35:0] data_ram_o;         // 32-bit read data from RAM
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
assign buffer_full = sample_ready;
    ram_logic u_ram (
        .clk_i              (clk),
        .rst_ni             (resetb),       // Active-low synchronous reset
        // .write_data_i       ({8'b00000000, sample_left}),
        .write_data_i       ({sample_right[23:6], sample_left[23:6]}),
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

    // VU-meter (RAM consumer mode only)
    vu_meter_6led vu (
        .clk_i               (clk),
        .rst_ni              (resetb),
        .ram_read_data_i     (data_ram_o[23:0]),       // From ram_logic.read_data_o
        .ram_read_valid_i    (read_valid),          // From ram_logic.read_valid_o
        .ram_read_ready_o    (read_ready),          // To ram_logic.read_ready_i
        .ram_buffer_ready_i  (buffer_ready),        // From ram_logic.buffer_ready_o
        .leds_o              (debug_sample_led),                   // 6-LED output
        .analog_out_o        (vu_analog_out),                      // PWM analog output for scope
        .debug_o             (vu_debug_leds)                       // Debug output
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
