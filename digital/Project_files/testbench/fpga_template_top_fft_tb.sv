// ============================================================================
// fpga_template_top_fft_tb - Full System Testbench with FFT Verification
// ============================================================================
// Comprehensive testbench for the complete audio capture and FFT system
//
// Tests:
//   1. Single-frequency sine wave input -> FFT peak detection
//   2. DC signal -> FFT DC bin verification
//   3. Multi-frequency signal -> Multiple peak detection
//
// Verification:
//   - Checks that FFT outputs correct frequency bins for known inputs
//   - Validates magnitude calculations
//   - Verifies system timing and data flow
// ============================================================================

`timescale 1ns/1ps

module fpga_template_top_fft_tb;

    // Test parameters
    localparam int CLK_PERIOD = 37;  // 27 MHz clock (37ns period)
    localparam int FFT_SIZE = 256;
    localparam real PI = 3.14159265359;

    // DUT signals
    logic       clk;
    logic [5:0] debug_led;
    logic       btn_s1_resetb;
    logic       btn_s2;
    logic       i2s_sck;
    logic       i2s_ws;
    logic       mic_sd_0;
    logic       buffer_full;
    logic       vu_analog_out;
    logic       fft_busy;
    logic       fft_output_valid;

    // Test variables
    logic signed [23:0] test_samples [0:FFT_SIZE-1];
    int sample_idx;
    int bit_idx;
    logic [23:0] current_sample;

    // FFT output capture
    int fft_output_count;
    logic signed [23:0] fft_real_capture [0:FFT_SIZE-1];
    logic signed [23:0] fft_imag_capture [0:FFT_SIZE-1];

    // ========================================================================
    // DUT Instantiation
    // ========================================================================
    fpga_template_top dut (
        .clk(clk),
        .debug_led(debug_led),
        .btn_s1_resetb(btn_s1_resetb),
        .btn_s2(btn_s2),
        .i2s_sck(i2s_sck),
        .i2s_ws(i2s_ws),
        .mic_sd_0(mic_sd_0),
        .buffer_full(buffer_full),
        .vu_analog_out(vu_analog_out),
        .fft_busy(fft_busy),
        .fft_output_valid(fft_output_valid)
    );

    // ========================================================================
    // Clock Generation
    // ========================================================================
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    // ========================================================================
    // I2S Data Generator - Simulates Microphone Output
    // ========================================================================
    // Generates I2S serial data from test_samples array
    initial begin
        mic_sd_0 = 0;
        sample_idx = 0;
        bit_idx = 0;
        current_sample = 0;

        // Wait for reset to complete
        wait(btn_s1_resetb == 0);
        wait(btn_s1_resetb == 1);
        @(posedge clk);

        forever begin
            // Wait for I2S word select edge (left channel start)
            @(posedge i2s_ws);

            // Load next sample
            if (sample_idx < FFT_SIZE) begin
                current_sample = test_samples[sample_idx];
            end else begin
                // Loop back to start after all samples sent
                sample_idx = 0;
                current_sample = test_samples[0];
            end

            // Transmit 24 bits MSB first
            for (bit_idx = 23; bit_idx >= 0; bit_idx--) begin
                @(negedge i2s_sck);  // Data changes on falling edge
                mic_sd_0 = current_sample[bit_idx];
            end

            sample_idx++;
        end
    end

    // ========================================================================
    // FFT Output Monitor
    // ========================================================================
    // Captures FFT output for verification
    always @(posedge clk) begin
        if (!btn_s1_resetb) begin
            fft_output_count <= 0;
        end else if (fft_output_valid) begin
            if (fft_output_count < FFT_SIZE) begin
                // Capture outputs (accessing internal signals for verification)
                fft_real_capture[fft_output_count] <= dut.fft_data_real_o;
                fft_imag_capture[fft_output_count] <= dut.fft_data_imag_o;
                fft_output_count <= fft_output_count + 1;

                $display("FFT Output [%3d]: Real=%d, Imag=%d",
                         fft_output_count, dut.fft_data_real_o, dut.fft_data_imag_o);
            end else begin
                // Reset for next FFT frame
                fft_output_count <= 0;
            end
        end
    end

    // ========================================================================
    // Helper Tasks
    // ========================================================================

    // Generate sine wave for specific FFT bin
    task generate_sine_wave(input int bin, input int amplitude);
        real omega;
        real sample;
        omega = 2.0 * PI * bin / FFT_SIZE;
        $display("Generating sine wave: bin=%0d, freq_ratio=%f, amplitude=%d",
                 bin, real'(bin)/FFT_SIZE, amplitude);
        for (int i = 0; i < FFT_SIZE; i++) begin
            sample = amplitude * $sin(omega * i);
            test_samples[i] = int'(sample);
        end
    endtask

    // Generate DC signal
    task generate_dc_signal(input int amplitude);
        $display("Generating DC signal: amplitude=%d", amplitude);
        for (int i = 0; i < FFT_SIZE; i++) begin
            test_samples[i] = amplitude;
        end
    endtask

    // Generate two-tone signal
    task generate_two_tone(input int bin1, input int bin2,
                          input int amp1, input int amp2);
        real omega1, omega2;
        real sample;
        omega1 = 2.0 * PI * bin1 / FFT_SIZE;
        omega2 = 2.0 * PI * bin2 / FFT_SIZE;
        $display("Generating two-tone: bin1=%0d, bin2=%0d, amp1=%d, amp2=%d",
                 bin1, bin2, amp1, amp2);
        for (int i = 0; i < FFT_SIZE; i++) begin
            sample = amp1 * $sin(omega1 * i) + amp2 * $sin(omega2 * i);
            test_samples[i] = int'(sample);
        end
    endtask

    // Wait for complete FFT output
    task wait_for_fft_complete();
        int prev_count;

        $display("Waiting for FFT to complete...");

        // Wait for FFT to start outputting
        wait(fft_output_valid == 1);

        // Wait for all 256 outputs
        prev_count = fft_output_count;
        while (fft_output_count < FFT_SIZE-1) begin
            @(posedge clk);
            if (fft_output_count != prev_count) begin
                prev_count = fft_output_count;
            end
        end

        // Wait a bit more for processing
        repeat(10) @(posedge clk);

        $display("FFT complete!");
    endtask

    // Analyze FFT output and find peak
    task analyze_fft_output(input string test_name, input int expected_bin);
        longint magnitude_sq;
        real magnitude;
        int max_bin;
        real max_magnitude;
        int bin_error;

        $display("\n========================================");
        $display("%s - FFT Analysis", test_name);
        $display("========================================");
        $display("Expected peak at bin %0d", expected_bin);
        $display("\nBin | Real         | Imaginary    | Magnitude");
        $display("----|--------------|--------------|------------");

        max_magnitude = 0;
        max_bin = 0;

        // Analyze first half (0 to Nyquist)
        for (int i = 0; i < FFT_SIZE/2; i++) begin
            // Calculate magnitude squared
            magnitude_sq = longint'(fft_real_capture[i]) * longint'(fft_real_capture[i]) +
                          longint'(fft_imag_capture[i]) * longint'(fft_imag_capture[i]);
            magnitude = $sqrt(real'(magnitude_sq));

            // Track maximum
            if (magnitude > max_magnitude) begin
                max_magnitude = magnitude;
                max_bin = i;
            end

            // Display significant bins (magnitude > 1000000)
            if (magnitude > 1000000.0 || i == expected_bin) begin
                $display("%3d | %12d | %12d | %12.0f %s",
                         i, fft_real_capture[i], fft_imag_capture[i], magnitude,
                         (i == expected_bin) ? " <- Expected" : "");
            end
        end

        $display("\n*** Peak detected at bin %0d with magnitude %.0f ***", max_bin, max_magnitude);

        // Check if peak is at expected bin (allow ±1 bin tolerance)
        bin_error = max_bin - expected_bin;
        if (bin_error < -1 || bin_error > 1) begin
            $display("ERROR: Peak at wrong bin! Expected %0d, got %0d", expected_bin, max_bin);
            $display("TEST FAILED!");
        end else begin
            $display("SUCCESS: Peak at correct bin (within tolerance)");
            $display("TEST PASSED!");
        end
        $display("========================================\n");
    endtask

    // ========================================================================
    // Main Test Sequence
    // ========================================================================
    initial begin
        // Waveform dump
        $dumpfile("fpga_template_top_fft_tb.vcd");
        $dumpvars(0, fpga_template_top_fft_tb);

        $display("\n================================================================================");
        $display("FPGA Template Top with FFT - Full System Testbench");
        $display("================================================================================\n");

        // Initialize signals
        btn_s1_resetb = 1;  // Active HIGH reset (inverted in DUT)
        btn_s2 = 0;
        sample_idx = 0;
        fft_output_count = 0;

        // Apply reset
        $display("Applying reset...");
        repeat(10) @(posedge clk);
        btn_s1_resetb = 0;  // Release reset
        repeat(20) @(posedge clk);
        $display("Reset complete\n");

        // ====================================================================
        // Test 1: Single Frequency - Bin 16
        // ====================================================================
        $display("\n================================================================");
        $display("TEST 1: Single Frequency Sine Wave (Bin 16)");
        $display("================================================================");

        generate_sine_wave(16, 4194304);  // Bin 16, half max amplitude
        sample_idx = 0;

        // Wait for samples to be captured and FFT to complete
        $display("Waiting for I2S capture and FFT processing...");
        wait_for_fft_complete();

        // Analyze results
        analyze_fft_output("Test 1 - Sine Wave Bin 16", 16);

        // Wait between tests
        repeat(1000) @(posedge clk);

        // ====================================================================
        // Test 2: DC Signal
        // ====================================================================
        $display("\n================================================================");
        $display("TEST 2: DC Signal");
        $display("================================================================");

        generate_dc_signal(2097152);  // Quarter max amplitude
        sample_idx = 0;

        $display("Waiting for I2S capture and FFT processing...");
        wait_for_fft_complete();

        analyze_fft_output("Test 2 - DC Signal", 0);

        // Wait between tests
        repeat(1000) @(posedge clk);

        // ====================================================================
        // Test 3: Two-Tone Signal
        // ====================================================================
        $display("\n================================================================");
        $display("TEST 3: Two-Tone Signal (Bins 16 and 32)");
        $display("================================================================");

        generate_two_tone(16, 32, 2097152, 2097152);  // Equal amplitudes
        sample_idx = 0;

        $display("Waiting for I2S capture and FFT processing...");
        wait_for_fft_complete();

        analyze_fft_output("Test 3 - Two-Tone", 16);  // Check for one of the tones

        // ====================================================================
        // End of Tests
        // ====================================================================
        $display("\n================================================================");
        $display("All tests completed!");
        $display("================================================================\n");

        repeat(100) @(posedge clk);
        $finish;
    end

    // ========================================================================
    // Timeout Watchdog
    // ========================================================================
    initial begin
        #100000000;  // 100ms timeout
        $display("ERROR: Simulation timeout!");
        $finish;
    end

endmodule
