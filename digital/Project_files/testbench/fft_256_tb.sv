// ============================================================================
// fft_256_tb - Testbench for 256-Point FFT Module
// ============================================================================
// Tests the FFT module with:
//   1. DC signal (all zeros except DC component)
//   2. Single frequency sine wave
//   3. Multi-frequency signal
// ============================================================================

`timescale 1ns/1ps

module fft_256_tb;

    // Parameters
    parameter int CLK_PERIOD = 10;  // 100 MHz clock
    parameter int DATA_WIDTH = 24;
    parameter int FFT_SIZE = 256;
    parameter real PI = 3.14159265359;

    // DUT signals
    logic                           clk;
    logic                           rst_n;
    logic signed [DATA_WIDTH-1:0]   data_real_i;
    logic signed [DATA_WIDTH-1:0]   data_imag_i;
    logic                           valid_i;
    logic                           ready_o;
    logic signed [DATA_WIDTH-1:0]   data_real_o;
    logic signed [DATA_WIDTH-1:0]   data_imag_o;
    logic                           valid_o;
    logic                           ready_i;
    logic                           busy_o;

    // Testbench variables
    logic signed [DATA_WIDTH-1:0] input_buffer [0:FFT_SIZE-1];
    logic signed [DATA_WIDTH-1:0] output_real [0:FFT_SIZE-1];
    logic signed [DATA_WIDTH-1:0] output_imag [0:FFT_SIZE-1];
    int input_idx;
    int output_idx;

    // ========================================================================
    // DUT Instantiation
    // ========================================================================
    fft_256 #(
        .DATA_WIDTH(DATA_WIDTH),
        .FFT_SIZE(FFT_SIZE),
        .STAGES(8)
    ) dut (
        .clk_i(clk),
        .rst_ni(rst_n),
        .data_real_i(data_real_i),
        .data_imag_i(data_imag_i),
        .valid_i(valid_i),
        .ready_o(ready_o),
        .data_real_o(data_real_o),
        .data_imag_o(data_imag_o),
        .valid_o(valid_o),
        .ready_i(ready_i),
        .busy_o(busy_o)
    );

    // ========================================================================
    // Clock Generation
    // ========================================================================
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    // ========================================================================
    // Test Stimulus
    // ========================================================================
    initial begin
        // Initialize
        rst_n = 0;
        valid_i = 0;
        ready_i = 1;
        data_real_i = 0;
        data_imag_i = 0;
        input_idx = 0;
        output_idx = 0;

        // Generate waveform file
        $dumpfile("fft_256_tb.vcd");
        $dumpvars(0, fft_256_tb);

        // Reset
        repeat(10) @(posedge clk);
        rst_n = 1;
        repeat(5) @(posedge clk);

        // ====================================================================
        // Test 1: Single Frequency Sine Wave (Bin 16 = 16/256 of sample rate)
        // ====================================================================
        $display("============================================");
        $display("Test 1: Single Frequency Sine Wave (Bin 16)");
        $display("============================================");

        // Generate sine wave at bin 16
        generate_sine_wave(16, 8388607/4); // Quarter amplitude

        // Send input samples
        send_fft_input();

        // Collect output
        collect_fft_output();

        // Analyze results
        analyze_spectrum("Test 1 - Sine Wave Bin 16");

        // Wait between tests
        repeat(100) @(posedge clk);

        // ====================================================================
        // Test 2: DC Signal
        // ====================================================================
        $display("============================================");
        $display("Test 2: DC Signal");
        $display("============================================");

        // Generate DC signal
        for (int i = 0; i < FFT_SIZE; i++) begin
            input_buffer[i] = 24'sd4194303; // Half max amplitude
        end

        // Send input samples
        send_fft_input();

        // Collect output
        collect_fft_output();

        // Analyze results
        analyze_spectrum("Test 2 - DC Signal");

        // Wait between tests
        repeat(100) @(posedge clk);

        // ====================================================================
        // Test 3: Two Frequency Signal (Bins 16 and 64)
        // ====================================================================
        $display("============================================");
        $display("Test 3: Two Frequency Signal");
        $display("============================================");

        // Generate two-tone signal
        generate_two_tone(16, 64, 8388607/8, 8388607/8);

        // Send input samples
        send_fft_input();

        // Collect output
        collect_fft_output();

        // Analyze results
        analyze_spectrum("Test 3 - Two Tone Signal");

        // End simulation
        repeat(100) @(posedge clk);
        $display("============================================");
        $display("All tests completed!");
        $display("============================================");
        $finish;
    end

    // ========================================================================
    // Helper Tasks
    // ========================================================================

    // Generate sine wave for specific FFT bin
    task generate_sine_wave(input int bin, input int amplitude);
        real omega;
        real sample;
        omega = 2.0 * PI * bin / FFT_SIZE;
        for (int i = 0; i < FFT_SIZE; i++) begin
            sample = amplitude * $sin(omega * i);
            input_buffer[i] = int'(sample);
        end
    endtask

    // Generate two-tone signal
    task generate_two_tone(input int bin1, input int bin2,
                           input int amp1, input int amp2);
        real omega1, omega2;
        real sample;
        omega1 = 2.0 * PI * bin1 / FFT_SIZE;
        omega2 = 2.0 * PI * bin2 / FFT_SIZE;
        for (int i = 0; i < FFT_SIZE; i++) begin
            sample = amp1 * $sin(omega1 * i) + amp2 * $sin(omega2 * i);
            input_buffer[i] = int'(sample);
        end
    endtask

    // Send input samples to FFT
    task send_fft_input();
        input_idx = 0;
        valid_i = 1;

        for (int i = 0; i < FFT_SIZE; i++) begin
            @(posedge clk);
            while (!ready_o) @(posedge clk);

            data_real_i = input_buffer[i];
            data_imag_i = 0; // Real signal only
            valid_i = 1;
        end

        @(posedge clk);
        valid_i = 0;
        data_real_i = 0;
    endtask

    // Collect FFT output
    task collect_fft_output();
        output_idx = 0;
        ready_i = 1;

        while (output_idx < FFT_SIZE) begin
            @(posedge clk);
            if (valid_o && ready_i) begin
                output_real[output_idx] = data_real_o;
                output_imag[output_idx] = data_imag_o;
                output_idx++;
            end
        end
    endtask

    // Analyze and display spectrum
    task analyze_spectrum(input string test_name);
        longint magnitude_sq;
        real magnitude;
        int max_bin;
        real max_magnitude;

        $display("\n%s - Spectrum Analysis:", test_name);
        $display("Bin | Real         | Imaginary    | Magnitude");
        $display("----|--------------|--------------|------------");

        max_magnitude = 0;
        max_bin = 0;

        for (int i = 0; i < 32; i++) begin // Show first 32 bins
            // Calculate magnitude (approximation to save time)
            magnitude_sq = longint'(output_real[i]) * longint'(output_real[i]) +
                          longint'(output_imag[i]) * longint'(output_imag[i]);
            magnitude = $sqrt(real'(magnitude_sq));

            // Track maximum
            if (magnitude > max_magnitude) begin
                max_magnitude = magnitude;
                max_bin = i;
            end

            // Display significant bins
            if (magnitude > 10000000) begin // Threshold for display
                $display("%3d | %12d | %12d | %12.0f",
                         i, output_real[i], output_imag[i], magnitude);
            end
        end

        $display("\nPeak detected at bin %0d with magnitude %.0f", max_bin, max_magnitude);
    endtask

    // ========================================================================
    // Timeout Watchdog
    // ========================================================================
    initial begin
        #(CLK_PERIOD * 1000000); // 10ms timeout
        $display("ERROR: Simulation timeout!");
        $finish;
    end

endmodule
