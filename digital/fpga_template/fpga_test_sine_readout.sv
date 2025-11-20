//==============================================================================
// fpga_test_sine_readout.sv
// Test wrapper for RAM verification using internal sine wave generator
//==============================================================================
// This module replaces the external I2S microphone with an internal sine wave
// generator and provides readout capability for Analog Discovery 2 monitoring.
//
// Features:
//   - Internal 1 kHz sine wave generation (no external mic needed)
//   - RAM data readout interface on GPIO pins for logic analyzer
//   - Compatible with existing I2S capture and RAM logic modules
//   - Debug outputs for monitoring system state
//
// Test Flow:
//   Sine Generator -> I2S Capture -> RAM Buffer -> Parallel Readout + VU Meter
//
// Readout Interface (for Analog Discovery 2):
//   - 18 bits of parallel data output (upper 18 bits of 36-bit RAM word)
//   - Control signals: read_valid, buffer_ready, write_count
//   - Can be captured at each buffer swap or continuously
//==============================================================================

module fpga_test_sine_readout (
    input   clk,

    //---Debug and Control---
    output  [5:0] debug_led,
    input   btn_s1_resetb,     // Button 1: Reset (active when pressed)
    input   btn_s2,            // Button 2: Mode select

    //---Original I2S outputs (now internal)---
    // These are no longer used externally but kept for compatibility
    output logic       i2s_sck,
    output logic       i2s_ws,
    input  logic       mic_sd_0,      // Not used - using internal sine gen

    //---Status outputs---
    output logic       buffer_full,    // Buffer ready pulse

    //---Analog VU Meter Output---
    output logic       vu_analog_out,  // PWM for oscilloscope

    //---RAM Readout Interface (NEW)---
    // Connect these to Analog Discovery 2 for data capture
    output logic [17:0] ram_data_out,      // Upper 18 bits of RAM data
    output logic        ram_read_valid,    // Data valid indicator
    output logic        ram_buffer_ready,  // Buffer swap pulse
    output logic [8:0]  ram_write_count,   // Write progress counter
    output logic [8:0]  ram_read_count,    // Read progress counter

    //---I2S Test Signals (for verification)---
    output logic        test_i2s_sck,  // Generated SCK for monitoring
    output logic        test_i2s_ws,   // Generated WS for monitoring
    output logic        test_i2s_sd    // Generated SD for monitoring
);

    logic resetb;
    assign resetb = ~btn_s1_resetb;

    //==========================================================================
    // Internal I2S Signals from Sine Generator
    //==========================================================================
    logic internal_sck;
    logic internal_ws;
    logic internal_sd;

    // Instantiate sine wave generator
    i2s_sine_generator #(
        .CLK_FREQ    (27_000_000),  // 27 MHz clock
        .SAMPLE_RATE (48_000),      // 48 kHz audio
        .SINE_FREQ   (1_000)        // 1 kHz test tone
    ) sine_gen (
        .clk_i  (clk),
        .rst_ni (resetb),
        .sck_o  (internal_sck),
        .ws_o   (internal_ws),
        .sd_o   (internal_sd)
    );

    // Export test signals for external monitoring
    assign test_i2s_sck = internal_sck;
    assign test_i2s_ws  = internal_ws;
    assign test_i2s_sd  = internal_sd;

    // Also drive original I2S outputs for compatibility
    assign i2s_sck = internal_sck;
    assign i2s_ws  = internal_ws;

    //==========================================================================
    // I2S Capture Module
    //==========================================================================
    logic signed [23:0] sample_left, sample_right;
    logic               sample_ready;

    i2s_capture_24 u_sampler (
        .clk_i     (clk),
        .rst_ni    (resetb),
        .sck_i     (internal_sck),    // Use internal SCK
        .ws_i      (internal_ws),     // Use internal WS
        .sd_i      (internal_sd),     // Use internal SD (not mic_sd_0)
        .left_o    (sample_left),
        .right_o   (sample_right),
        .ready_o   (sample_ready)
    );

    assign buffer_full = sample_ready;

    //==========================================================================
    // RAM Ping-Pong Buffer
    //==========================================================================
    logic signed [35:0] data_ram_o;
    logic               read_valid;
    logic               read_ready;
    logic               buffer_ready;
    logic [5:0]         ram_debug_leds;
    logic [8:0]         write_count;
    logic [8:0]         read_count;

    ram_logic u_ram (
        .clk_i              (clk),
        .rst_ni             (resetb),
        .write_data_i       ({sample_right[23:6], sample_left[23:6]}),  // 18+18 = 36 bits
        .write_valid_i      (sample_ready),
        .write_ready_o      (),
        .read_data_o        (data_ram_o),
        .read_ready_i       (read_ready),
        .read_valid_o       (read_valid),
        .buffer_ready_o     (buffer_ready),
        .buffer_overflow_o  (),
        .write_count_o      (write_count),
        .read_count_o       (read_count),
        .debug_leds_o       (ram_debug_leds)
    );

    //==========================================================================
    // RAM Readout Interface
    //==========================================================================
    // Output upper 18 bits (left channel) for logic analyzer capture
    assign ram_data_out      = data_ram_o[35:18];  // Left channel data
    assign ram_read_valid    = read_valid;
    assign ram_buffer_ready  = buffer_ready;
    assign ram_write_count   = write_count;
    assign ram_read_count    = read_count;

    //==========================================================================
    // VU Meter (Optional - for visual feedback)
    //==========================================================================
    logic [5:0] debug_sample_led;
    logic [5:0] vu_debug_leds;

    vu_meter_6led vu (
        .clk_i               (clk),
        .rst_ni              (resetb),
        .ram_read_data_i     (data_ram_o[23:0]),
        .ram_read_valid_i    (read_valid),
        .ram_read_ready_o    (read_ready),
        .ram_buffer_ready_i  (buffer_ready),
        .leds_o              (debug_sample_led),
        .analog_out_o        (vu_analog_out),
        .debug_o             (vu_debug_leds)
    );

    // Debug LED selection: use btn_s2 to switch between VU and RAM debug
    assign debug_led = btn_s2 ? ~ram_debug_leds : ~debug_sample_led;

endmodule
