// =============================================================================
// sp_ram_integration_tb.sv
// Integration testbench for pingpong RAM with I2S sampler and VU meter
// =============================================================================

`timescale 1ns/1ps

module sp_ram_integration_tb;

    // Clock and reset
    logic clk_27mhz;
    logic rst_n;

    // I2S signals
    logic i2s_sck;
    logic i2s_ws;
    logic mic_sd;

    // I2S capture outputs
    logic signed [23:0] left_sample;
    logic signed [23:0] right_sample;
    logic sample_ready;

    // RAM signals
    logic [15:0] ram_read_data;
    logic buffer_ready;

    // VU meter signals
    logic [5:0] vu_leds;

    // Test control
    integer sample_count;
    integer cycle_count;
    logic [23:0] test_pattern;

    // Clock generation - 27 MHz
    initial begin
        clk_27mhz = 0;
        forever #18.518 clk_27mhz = ~clk_27mhz; // ~27 MHz (18.518ns half period)
    end

    // I2S Clock Generator
    i2s_clock_gen u_i2s_clock (
        .clk_i        (clk_27mhz),
        .rst_ni       (rst_n),
        .sck_o        (i2s_sck),
        .ws_o         (i2s_ws),
        .frame_start_o()
    );

    // I2S Capture module
    i2s_capture_24 u_sampler (
        .clk_i    (clk_27mhz),
        .rst_ni   (rst_n),
        .sck_i    (i2s_sck),
        .ws_i     (i2s_ws),
        .sd_i     (mic_sd),
        .left_o   (left_sample),
        .right_o  (right_sample),
        .ready_o  (sample_ready)
    );

    // Ping-pong RAM module
    pingpong_sp_ram #(
        .WIDTH(16),
        .DEPTH(10)  // Small depth for faster testing
    ) u_ram (
        .clk_i          (clk_27mhz),
        .rst_ni         (rst_n),
        .sample_i       (left_sample[23:8]), // Use upper 16 bits
        .sample_ready_i (sample_ready),
        .read_data_o    (ram_read_data),
        .buffer_ready_o (buffer_ready)
    );

    // VU Meter module
    vu_meter_6led #(
        .SELECT_LEFT (1'b1),      // Select left channel
        .DECAY_SHIFT (8),          // Faster decay for testing
        .SCALE_SHIFT (6),          // More sensitive for testing
        .LED_DIV     (10000)       // Faster LED update for testing
    ) u_vu_meter (
        .clk_i          (clk_27mhz),
        .rst_ni         (rst_n),
        .sample_stb_i   (sample_ready),
        .left_sample_i  (left_sample),
        .right_sample_i (right_sample),
        .leds_o         (vu_leds)
    );

    // I2S data pattern generator
    // Generate a simple pattern on mic_sd to simulate microphone data
    logic [24:0] shift_pattern;
    logic [5:0] bit_counter;
    logic current_channel;

    initial begin
        mic_sd = 0;
        shift_pattern = 25'h0;
        bit_counter = 0;
        current_channel = 0;
    end

    // Detect I2S word select edges to load new test pattern
    logic ws_prev;
    always_ff @(posedge clk_27mhz) begin
        ws_prev <= i2s_ws;
    end

    wire ws_edge = (ws_prev != i2s_ws);

    // Generate I2S data stream
    always_ff @(posedge clk_27mhz) begin
        if (!rst_n) begin
            shift_pattern <= 25'h0;
            bit_counter <= 0;
            current_channel <= 0;
        end else begin
            // Detect WS edge - load new pattern
            if (ws_edge) begin
                current_channel <= i2s_ws;
                bit_counter <= 0;

                // Generate different patterns for left/right
                if (i2s_ws == 0) begin  // Left channel
                    // Gradually increasing amplitude
                    shift_pattern <= {1'b0, test_pattern};
                end else begin  // Right channel
                    // Different pattern for right
                    shift_pattern <= {1'b0, test_pattern ^ 24'hAAAAAA};
                end
            end else if (i2s_sck && !$isunknown(i2s_sck)) begin
                // On SCK rising edge, shift out MSB
                if (bit_counter < 25) begin
                    mic_sd <= shift_pattern[24];
                    shift_pattern <= {shift_pattern[23:0], 1'b0};
                    bit_counter <= bit_counter + 1;
                end else begin
                    mic_sd <= 0; // Padding bits
                end
            end
        end
    end

    // Test stimulus
    initial begin
        // Initialize waveform dump
        $dumpfile("sp_ram_integration_tb.vcd");
        $dumpvars(0, sp_ram_integration_tb);

        // Initialize
        rst_n = 0;
        sample_count = 0;
        cycle_count = 0;
        test_pattern = 24'h100000; // Start with small amplitude

        // Reset sequence
        repeat(10) @(posedge clk_27mhz);
        rst_n = 1;
        $display("=== Reset released at time %t ===", $time);

        // Monitor samples
        fork
            // Sample counter
            begin
                forever begin
                    @(posedge sample_ready);
                    sample_count = sample_count + 1;
                    $display("[%t] Sample %0d: L=%h R=%h", $time, sample_count, left_sample, right_sample);
                end
            end

            // Buffer ready monitor
            begin
                forever begin
                    @(posedge buffer_ready);
                    cycle_count = cycle_count + 1;
                    $display("[%t] === BUFFER %0d READY === RAM output: %h", $time, cycle_count, ram_read_data);
                end
            end

            // VU meter monitor
            begin
                logic [5:0] prev_leds = 0;
                forever begin
                    @(posedge clk_27mhz);
                    if (vu_leds != prev_leds) begin
                        $display("[%t] VU LEDs changed: %06b", $time, vu_leds);
                        prev_leds = vu_leds;
                    end
                end
            end

            // Gradually increase amplitude
            begin
                repeat(5) begin
                    #100000; // Wait some time
                    test_pattern = test_pattern + 24'h080000;
                    if (test_pattern > 24'h7FFFFF) test_pattern = 24'h100000;
                    $display("[%t] Increasing test amplitude to %h", $time, test_pattern);
                end
            end
        join_any

        // Run for enough time to fill multiple buffers
        #5000000; // 5ms should be enough for several buffer cycles

        // Final checks
        $display("\n=== Test Summary ===");
        $display("Total samples captured: %0d", sample_count);
        $display("Total buffer ready cycles: %0d", cycle_count);
        $display("Final VU meter LEDs: %06b", vu_leds);

        if (sample_count > 20 && cycle_count >= 2) begin
            $display("=== TEST PASSED ===");
        end else begin
            $display("=== TEST FAILED ===");
            $display("Expected at least 20 samples and 2 buffer cycles");
        end

        $finish;
    end

    // Timeout watchdog
    initial begin
        #10000000; // 10ms timeout
        $display("ERROR: Simulation timeout!");
        $finish;
    end

    // Monitor for read_data_o stuck at zero
    logic data_changed;
    initial begin
        data_changed = 0;
        forever begin
            @(posedge buffer_ready);
            if (ram_read_data !== 16'h0000) begin
                data_changed = 1;
                $display("[%t] GOOD: read_data_o changed to non-zero value: %h", $time, ram_read_data);
            end
        end
    end

    // Final check that data changed
    final begin
        if (!data_changed) begin
            $display("WARNING: read_data_o was stuck at zero throughout test!");
        end
    end

endmodule
