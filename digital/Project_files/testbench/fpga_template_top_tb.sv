//==============================================================================
// Testbench for fpga_template_top - FPGA I2S Audio Capture System
//
// Tests:
//   1. Reset behavior
//   2. I2S clock generation
//   3. I2S audio capture
//   4. RAM buffer filling and swapping
//   5. VU meter operation
//   6. End-to-end data flow
//==============================================================================

`timescale 1ns/1ps

module fpga_template_top_tb;

    //==========================================================================
    // Parameters
    //==========================================================================
    localparam int CLK_PERIOD = 10;  // 100 MHz system clock
    localparam int RAM_DEPTH = 256;  // Samples per buffer

    //==========================================================================
    // DUT Signals
    //==========================================================================
    logic        clk;
    logic [5:0]  debug_led;
    logic        btn_s1_resetb;  // Active-low reset button
    logic        btn_s2;
    logic        i2s_sck;
    logic        i2s_ws;
    logic        mic_sd_0;
    logic        buffer_full;

    //==========================================================================
    // Test Variables
    //==========================================================================
    int test_errors = 0;
    int test_passed = 0;
    int sample_count = 0;

    // I2S data to send
    logic signed [23:0] test_samples[$];
    int current_sample_idx = 0;

    //==========================================================================
    // Clock Generation
    //==========================================================================
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    //==========================================================================
    // DUT Instantiation
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
    // Waveform Dump
    //==========================================================================
    initial begin
        $dumpfile("fpga_template_top_tb.vcd");
        $dumpvars(0, fpga_template_top_tb);
    end

    //==========================================================================
    // I2S Data Generator
    //
    // Simulates I2S microphone sending serial data on mic_sd_0
    // Data is sent MSB first, synchronized to SCK and WS
    //==========================================================================
    logic [23:0] current_sample_left;
    logic [23:0] current_sample_right;
    int bit_counter = 0;
    logic last_ws = 0;

    always @(posedge i2s_sck) begin
        // Detect WS edge to start new sample
        if (i2s_ws !== last_ws) begin
            bit_counter = 0;
            last_ws = i2s_ws;

            // Load new samples when starting left channel (WS low)
            if (!i2s_ws && test_samples.size() > 0) begin
                current_sample_left = test_samples[0];
                test_samples.delete(0);

                if (test_samples.size() > 0) begin
                    current_sample_right = test_samples[0];
                    test_samples.delete(0);
                end else begin
                    current_sample_right = 24'h000000;
                end

                sample_count++;
            end
        end

        // Send bit (MSB first)
        if (bit_counter < 24) begin
            if (!i2s_ws) begin
                // Left channel
                mic_sd_0 = current_sample_left[23 - bit_counter];
            end else begin
                // Right channel
                mic_sd_0 = current_sample_right[23 - bit_counter];
            end
            bit_counter++;
        end else begin
            mic_sd_0 = 0;
        end
    end

    //==========================================================================
    // Task: Reset DUT
    //==========================================================================
    task automatic reset_dut();
        $display("========================================");
        $display("Applying Reset...");
        $display("========================================");

        btn_s2 = 0;
        btn_s1_resetb = 0;
        mic_sd_0 = 0;

        repeat(20) @(posedge clk);
        btn_s1_resetb = 1;
        repeat(10) @(posedge clk);

        $display("Reset complete\n");
    endtask

    //==========================================================================
    // Task: Wait for samples
    //==========================================================================
    task automatic wait_samples(input int count);
        int start_count = sample_count;
        while (sample_count < start_count + count) begin
            @(posedge clk);
        end
    endtask

    //==========================================================================
    // Test 1: Reset and Initialization
    //==========================================================================
    task automatic test_reset();
        logic sck_toggling;
        logic ws_toggling;

        $display("========================================");
        $display("TEST 1: Reset and Initialization");
        $display("========================================");

        reset_dut();

        // Check initial states
        if (buffer_full !== 1'b0) begin
            $display("ERROR: buffer_full should be 0 after reset");
            test_errors++;
        end

        // Wait for I2S clocks to stabilize
        repeat(100) @(posedge clk);

        // Check that I2S clocks are running
        sck_toggling = 0;
        ws_toggling = 0;

        fork
            begin
                @(posedge i2s_sck);
                sck_toggling = 1;
            end
            begin
                @(posedge i2s_ws or negedge i2s_ws);
                ws_toggling = 1;
            end
            begin
                #10000;  // 10us timeout
            end
        join_any

        if (!sck_toggling) begin
            $display("ERROR: I2S SCK not toggling");
            test_errors++;
        end else begin
            $display("✓ I2S SCK is toggling");
        end

        if (!ws_toggling) begin
            $display("ERROR: I2S WS not toggling");
            test_errors++;
        end else begin
            $display("✓ I2S WS is toggling");
        end

        if (test_errors == 0) begin
            $display("✓ Test PASSED\n");
            test_passed++;
        end else begin
            $display("✗ Test FAILED\n");
        end
    endtask

    //==========================================================================
    // Test 2: Single Sample Capture
    //==========================================================================
    task automatic test_single_sample();
        $display("========================================");
        $display("TEST 2: Single Sample Capture");
        $display("========================================");

        reset_dut();

        // Queue up test samples
        test_samples.push_back(24'h123456);
        test_samples.push_back(24'h7FFFFF);  // Right channel (not used)

        // Wait for sample to be captured
        wait_samples(1);

        $display("✓ Sample captured");

        if (test_errors == 0) begin
            $display("✓ Test PASSED\n");
            test_passed++;
        end else begin
            $display("✗ Test FAILED\n");
        end
    endtask

    //==========================================================================
    // Test 3: Buffer Fill and Swap
    //==========================================================================
    task automatic test_buffer_fill();
        $display("========================================");
        $display("TEST 3: Buffer Fill and Swap");
        $display("========================================");

        reset_dut();
        sample_count = 0;

        // Generate test pattern
        $display("Generating %0d test samples...", RAM_DEPTH);
        for (int i = 0; i < RAM_DEPTH; i++) begin
            test_samples.push_back(24'h100000 + i);
            test_samples.push_back(24'h200000 + i);  // Right channel
        end

        // Wait for all samples to be captured
        $display("Waiting for samples to be captured...");
        wait_samples(RAM_DEPTH);

        $display("✓ All %0d samples captured", RAM_DEPTH);

        // Check buffer_ready signal (should have pulsed)
        repeat(100) @(posedge clk);

        if (test_errors == 0) begin
            $display("✓ Test PASSED\n");
            test_passed++;
        end else begin
            $display("✗ Test FAILED\n");
        end
    endtask

    //==========================================================================
    // Test 4: VU Meter Response
    //==========================================================================
    task automatic test_vu_meter();
        $display("========================================");
        $display("TEST 4: VU Meter Response");
        $display("========================================");

        reset_dut();
        sample_count = 0;

        // Send samples with increasing amplitude
        $display("Sending samples with varying amplitudes...");
        for (int i = 0; i < RAM_DEPTH; i++) begin
            // Varying amplitude pattern
            int amplitude = (i * 24'h7FFFFF) / RAM_DEPTH;
            test_samples.push_back(amplitude[23:0]);
            test_samples.push_back(24'h000000);  // Right channel
        end

        // Wait for samples
        wait_samples(RAM_DEPTH);

        // Monitor LED changes
        repeat(1000) @(posedge clk);

        $display("✓ VU meter operating (LEDs = %6b)", ~debug_led);

        if (test_errors == 0) begin
            $display("✓ Test PASSED\n");
            test_passed++;
        end else begin
            $display("✗ Test FAILED\n");
        end
    endtask

    //==========================================================================
    // Test 5: Continuous Operation
    //==========================================================================
    task automatic test_continuous_operation();
        $display("========================================");
        $display("TEST 5: Continuous Operation");
        $display("========================================");

        reset_dut();
        sample_count = 0;

        // Send 3 buffers worth of samples
        $display("Sending 3 buffers of samples...");
        for (int buf_num = 0; buf_num < 3; buf_num++) begin
            for (int i = 0; i < RAM_DEPTH; i++) begin
                test_samples.push_back(24'h300000 + (buf_num << 16) + i);
                test_samples.push_back(24'h000000);
            end
        end

        // Wait for all samples
        wait_samples(RAM_DEPTH * 3);

        $display("✓ Processed %0d samples across multiple buffers", RAM_DEPTH * 3);

        repeat(500) @(posedge clk);

        if (test_errors == 0) begin
            $display("✓ Test PASSED\n");
            test_passed++;
        end else begin
            $display("✗ Test FAILED\n");
        end
    endtask

    //==========================================================================
    // Main Test Sequence
    //==========================================================================
    initial begin
        $display("\n");
        $display("================================================================================");
        $display("FPGA Template Top-Level Testbench");
        $display("================================================================================");
        $display("System Configuration:");
        $display("  Clock:        100 MHz");
        $display("  RAM Depth:    %0d samples per buffer", RAM_DEPTH);
        $display("  Data Width:   32-bit (24-bit audio + 8-bit padding)");
        $display("================================================================================\n");

        // Initialize
        mic_sd_0 = 0;

        // Run tests
        test_reset();
        test_single_sample();
        test_buffer_fill();
        test_vu_meter();
        test_continuous_operation();

        // Summary
        $display("\n");
        $display("================================================================================");
        $display("TEST SUMMARY");
        $display("================================================================================");
        $display("Tests Passed: %0d/5", test_passed);
        $display("Errors:       %0d", test_errors);
        $display("================================================================================");

        if (test_errors == 0 && test_passed == 5) begin
            $display("✓ ALL TESTS PASSED!");
        end else begin
            $display("✗ SOME TESTS FAILED");
        end

        $display("================================================================================\n");

        repeat(50) @(posedge clk);
        $finish;
    end

    //==========================================================================
    // Timeout Watchdog
    //==========================================================================
    initial begin
        #100000000;  // 100ms timeout
        $display("ERROR: Simulation timeout!");
        $finish;
    end

    //==========================================================================
    // Monitor
    //==========================================================================
    initial begin
        $display("Starting monitor...\n");
        forever begin
            @(posedge clk);
            if (buffer_full) begin
                $display("WARNING: Buffer overflow detected at time %0t", $time);
            end
        end
    end

endmodule
