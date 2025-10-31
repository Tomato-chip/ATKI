//==============================================================================
// fpga_template_top_tb.sv
//
// Comprehensive testbench for FPGA I2S Audio Capture System
//
// Tests:
//   1. I2S clock generation and audio capture
//   2. Ping-pong RAM buffering (256 samples per buffer)
//   3. VU meter handshake timing (2-cycle ready delay)
//   4. VU meter LED response to audio levels
//   5. Buffer overflow protection
//
//==============================================================================

`timescale 1ns/1ps

module fpga_template_top_tb;

    //==========================================================================
    // Parameters
    //==========================================================================
    localparam CLK_PERIOD = 37.037;  // 27 MHz = 37.037ns period
    localparam real CLK_FREQ = 27.0e6;

    // Test configuration
    localparam NUM_TEST_SAMPLES = 80;   // Test with 80 samples (5 buffer swaps)
    localparam RAM_DEPTH = 16;          // Must match ram_logic DEPTH parameter

    //==========================================================================
    // DUT signals
    //==========================================================================
    logic        clk;
    logic [5:0]  debug_led;
    logic        btn_s1_resetb;
    logic        btn_s2;
    logic        i2s_sck;
    logic        i2s_ws;
    logic        mic_sd_0;
    logic        buffer_full;

    //==========================================================================
    // Test control signals
    //==========================================================================
    int          sample_count;
    int          buffer_swap_count;
    int          handshake_count;
    int          ready_low_cycles;
    logic        monitor_handshake;
    logic [23:0] test_audio_value;

    //==========================================================================
    // Instantiate DUT
    //==========================================================================
    fpga_template_top dut (
        .clk            (clk),
        .debug_led      (debug_led),
        .btn_s1_resetb  (btn_s1_resetb),
        .btn_s2         (btn_s2),
        .i2s_sck        (i2s_sck),
        .i2s_ws         (i2s_ws),
        .mic_sd_0       (mic_sd_0),
        .buffer_full    (buffer_full)
    );

    //==========================================================================
    // Clock generation - 27 MHz
    //==========================================================================
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    //==========================================================================
    // Reset generation
    //==========================================================================
    initial begin
        btn_s1_resetb = 1'b0;  // Active low reset
        btn_s2 = 1'b0;
        repeat(10) @(posedge clk);
        btn_s1_resetb = 1'b1;  // Release reset
        $display("[%0t] Reset released", $time);
    end

    //==========================================================================
    // Simulated I2S Microphone
    //==========================================================================
    // Generate realistic I2S serial data stream

    int bit_counter;
    logic [24:0] left_shift_reg;
    logic [24:0] right_shift_reg;
    logic [23:0] left_sample;
    logic [23:0] right_sample;

    // Audio test pattern generator
    initial begin
        left_sample = 24'h000000;
        right_sample = 24'h000000;

        // Wait for reset
        wait(btn_s1_resetb == 1'b1);
        repeat(5) @(posedge clk);

        forever begin
            @(negedge i2s_ws);  // Left channel starts

            // Generate test patterns
            // Ramp up pattern to test VU meter levels
            if (sample_count < 50)
                left_sample = 24'h001000;  // Low level
            else if (sample_count < 100)
                left_sample = 24'h010000;  // Medium level
            else if (sample_count < 150)
                left_sample = 24'h050000;  // High level
            else if (sample_count < 200)
                left_sample = 24'h100000;  // Very high level
            else
                left_sample = 24'h200000;  // Maximum level

            right_sample = left_sample;  // Same for both channels
            sample_count++;
        end
    end

    // Shift data out on SCK rising edge (MSB first)
    always @(posedge i2s_sck or negedge btn_s1_resetb) begin
        if (!btn_s1_resetb) begin
            bit_counter = 0;
            left_shift_reg = 25'h0;
            right_shift_reg = 25'h0;
            mic_sd_0 = 1'b0;
        end else begin
            // Detect channel switch
            if (i2s_ws == 1'b0 && bit_counter == 0) begin
                // Left channel - load new data
                left_shift_reg = {1'b0, left_sample};  // 25 bits (dummy + 24 data)
                bit_counter = 1;
                mic_sd_0 = left_shift_reg[24];  // Output MSB
            end else if (i2s_ws == 1'b1 && bit_counter == 0) begin
                // Right channel - load new data
                right_shift_reg = {1'b0, right_sample};
                bit_counter = 1;
                mic_sd_0 = right_shift_reg[24];  // Output MSB
            end else if (bit_counter > 0 && bit_counter < 25) begin
                // Shift out bits
                if (i2s_ws == 1'b0) begin
                    left_shift_reg = {left_shift_reg[23:0], 1'b0};
                    mic_sd_0 = left_shift_reg[24];
                end else begin
                    right_shift_reg = {right_shift_reg[23:0], 1'b0};
                    mic_sd_0 = right_shift_reg[24];
                end
                bit_counter++;
            end else if (bit_counter >= 25) begin
                // End of 25-bit word, wait for WS change
                bit_counter = 0;
                mic_sd_0 = 1'b0;
            end
        end
    end

    //==========================================================================
    // Monitors and Checkers
    //==========================================================================

    // Monitor I2S sample capture
    initial begin
        sample_count = 0;
        wait(btn_s1_resetb == 1'b1);

        forever begin
            @(posedge dut.u_sampler.ready_o);
            $display("[%0t] Sample %0d captured: L=0x%06h R=0x%06h",
                     $time, sample_count,
                     dut.u_sampler.left_o,
                     dut.u_sampler.right_o);
        end
    end

    // Monitor RAM buffer swaps
    initial begin
        buffer_swap_count = 0;
        wait(btn_s1_resetb == 1'b1);

        forever begin
            @(posedge dut.u_ram.buffer_ready_o);
            buffer_swap_count++;
            $display("[%0t] === Buffer swap %0d - Write buffer full, starting read phase ===",
                     $time, buffer_swap_count);
            $display("         Write buffer was: RAM%0d, Read buffer now: RAM%0d",
                     dut.u_ram.write_buffer_sel, dut.u_ram.read_buffer_sel);
        end
    end

    // Monitor VU meter handshake timing - verify 2-cycle ready delay
    logic prev_sample_valid;
    initial begin
        handshake_count = 0;
        ready_low_cycles = 0;
        monitor_handshake = 0;
        prev_sample_valid = 0;

        wait(btn_s1_resetb == 1'b1);
        @(posedge clk);  // Sync to clock

        forever begin
            @(posedge clk);
            #1;  // Wait for signals to settle

            // Detect rising edge of sample_valid (handshake acceptance)
            if (dut.vu.sample_valid && !prev_sample_valid) begin
                handshake_count++;
                monitor_handshake = 1;
                ready_low_cycles = 0;
                if (handshake_count <= 5) begin // Only print first few to avoid spam
                    $display("[%0t] VU Handshake %0d: Sample accepted", $time, handshake_count);
                end
            end
            prev_sample_valid = dut.vu.sample_valid;

            // Monitor the ready signal for 3 cycles after handshake starts
            if (monitor_handshake) begin
                // Check ready_q value AFTER the handshake cycle
                if (ready_low_cycles == 0 && !prev_sample_valid) begin
                    // First cycle after handshake - ready should be LOW
                    if (!dut.vu.ram_ready_q) begin
                        ready_low_cycles = 1;
                    end else begin
                        $error("[%0t] TIMING ERROR: Ready should be LOW in cycle 1 after handshake!",  $time);
                        monitor_handshake = 0;
                    end
                end else if (ready_low_cycles == 1) begin
                    // Second cycle after handshake - ready should still be LOW
                    if (!dut.vu.ram_ready_q) begin
                        ready_low_cycles = 2;
                    end else begin
                        $error("[%0t] TIMING ERROR: Ready should be LOW in cycle 2 after handshake!", $time);
                        monitor_handshake = 0;
                    end
                end else if (ready_low_cycles == 2) begin
                    // Third cycle after handshake - ready should be HIGH again
                    if (dut.vu.ram_ready_q) begin
                        if (handshake_count <= 5) begin
                            $display("[%0t]    PASS: Correct 2-cycle handshake delay (ready LOW for 2 cycles)", $time);
                        end
                    end else begin
                        $error("[%0t] TIMING ERROR: Ready should be HIGH in cycle 3 after handshake!", $time);
                    end
                    monitor_handshake = 0;
                end
            end
        end
    end

    // Monitor VU meter LED outputs
    logic [5:0] prev_leds;
    initial begin
        prev_leds = 6'b0;
        wait(btn_s1_resetb == 1'b1);

        forever begin
            @(posedge clk);
            if (dut.vu.leds_o != prev_leds) begin
                $display("[%0t] VU LEDs changed: %06b (level=%0d)",
                         $time, dut.vu.leds_o, dut.vu.level_q);
                prev_leds = dut.vu.leds_o;
            end
        end
    end

    // Check for buffer overflows
    initial begin
        wait(btn_s1_resetb == 1'b1);

        forever begin
            @(posedge buffer_full);
            $error("[%0t] BUFFER OVERFLOW DETECTED!", $time);
        end
    end

    //==========================================================================
    // Test sequence
    //==========================================================================
    initial begin
        $display("=================================================================");
        $display("FPGA I2S Audio Capture System Testbench");
        $display("=================================================================");
        $display("Clock: %.3f MHz", CLK_FREQ/1e6);
        $display("Test samples: %0d (%.1f buffers)",
                 NUM_TEST_SAMPLES, real'(NUM_TEST_SAMPLES)/real'(RAM_DEPTH));
        $display("=================================================================");

        // Wait for reset
        wait(btn_s1_resetb == 1'b1);
        $display("[%0t] Test started", $time);

        // Wait for enough samples to test multiple buffer swaps
        wait(sample_count >= NUM_TEST_SAMPLES);

        // Allow time for VU meter to process
        repeat(1000) @(posedge clk);

        // Final statistics
        $display("");
        $display("=================================================================");
        $display("Test Complete");
        $display("=================================================================");
        $display("Samples captured:      %0d", sample_count);
        $display("Buffer swaps:          %0d", buffer_swap_count);
        $display("VU handshakes:         %0d", handshake_count);
        $display("Expected buffer swaps: %0d", NUM_TEST_SAMPLES / RAM_DEPTH);
        $display("=================================================================");

        // Check results
        if (buffer_swap_count < 1) begin
            $error("FAIL: No buffer swaps occurred!");
        end else if (handshake_count < buffer_swap_count) begin
            $error("FAIL: VU meter did not consume data!");
        end else begin
            $display("PASS: All major tests passed");
        end

        $display("");
        $finish;
    end

    // Timeout watchdog
    initial begin
        #50ms;
        $error("TIMEOUT: Simulation ran too long!");
        $finish;
    end

    //==========================================================================
    // Waveform dump for GTKWave
    //==========================================================================
    initial begin
        $dumpfile("fpga_template_top_tb.vcd");
        $dumpvars(0, fpga_template_top_tb);
        $dumpvars(0, dut.u_sampler);
        $dumpvars(0, dut.u_ram);
        $dumpvars(0, dut.vu);
    end

endmodule
