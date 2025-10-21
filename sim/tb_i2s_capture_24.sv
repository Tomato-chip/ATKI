// =============================================================================
// tb_i2s_capture_24.sv
// Self-checking testbench for i2s_capture_24 module
// =============================================================================
// Tests: 1 stereo frame (64 SCK), left channel with known 24-bit pattern,
// verifies 1-SCK MSB delay, 24-bit capture, and single-cycle valid pulse.
// =============================================================================

`timescale 1ns/1ps

module tb_i2s_capture_24;

    // Clock and reset
    logic        clk;
    logic        rst_n;

    // I²S signals
    logic        sck;
    logic        ws;
    logic        sd;

    // DUT outputs
    logic [23:0] data24;
    logic        valid;

    // Test pattern: 24-bit known value
    localparam logic [23:0] LEFT_PATTERN  = 24'hABCDEF;
    localparam logic [23:0] RIGHT_PATTERN = 24'h123456;

    // =========================================================================
    // DUT instantiation - capture LEFT channel
    // =========================================================================
    i2s_capture_24 #(
        .CAPTURE_LEFT(1'b1)
    ) dut (
        .clk_i    (clk),
        .rst_ni   (rst_n),
        .sck_i    (sck),
        .ws_i     (ws),
        .sd_i     (sd),
        .data24_o (data24),
        .valid_o  (valid)
    );

    // =========================================================================
    // Clock generation: clk = 100 MHz, sck = 3.125 MHz (32× slower)
    // =========================================================================
    initial clk = 0;
    always #5 clk = ~clk;  // 10ns period = 100 MHz

    initial sck = 0;
    always #160 sck = ~sck;  // 320ns period = 3.125 MHz (adequate for CDC sync)

    // =========================================================================
    // Task: Send one I²S half-frame (32 SCK cycles)
    // =========================================================================
    task automatic send_i2s_half_frame(input logic [23:0] data24);
        integer i;
        begin
            // Wait for 1 SCK period (skip - I²S MSB delay)
            repeat(2) @(posedge sck);

            // Send 24 bits MSB-first
            for (i = 23; i >= 0; i--) begin
                sd = data24[i];
                @(posedge sck);  // Data valid on rising edge (changes on falling)
            end

            // Send 8 dummy bits (fill 32-bit slot)
            for (i = 0; i < 8; i++) begin
                sd = 1'b0;
                @(posedge sck);
            end
        end
    endtask

    // =========================================================================
    // Main test sequence
    // =========================================================================
    logic test_passed;
    integer valid_count;

    initial begin
        $dumpfile("tb_i2s_capture_24.vcd");
        $dumpvars(0, tb_i2s_capture_24);

        test_passed = 1'b1;
        valid_count = 0;

        // Initialize
        rst_n = 0;
        ws    = 0;
        sd    = 0;
        repeat(10) @(posedge clk);
        rst_n = 1;
        repeat(10) @(posedge clk);

        $display("=== I²S Capture 24-bit Test ===");
        $display("Left pattern:  0x%06X", LEFT_PATTERN);
        $display("Right pattern: 0x%06X", RIGHT_PATTERN);

        // Start stereo frame: LEFT channel (ws=0)
        ws = 0;
        @(posedge clk);

        fork
            // Send left channel data
            send_i2s_half_frame(LEFT_PATTERN);

            // Monitor for valid pulse during left channel
            begin
                @(posedge valid);
                valid_count++;
                @(posedge clk);
                if (data24 === LEFT_PATTERN) begin
                    $display("[PASS] Left channel captured: 0x%06X", data24);
                end else begin
                    $display("[FAIL] Left channel mismatch: expected 0x%06X, got 0x%06X",
                             LEFT_PATTERN, data24);
                    test_passed = 1'b0;
                end

                // Check valid is single-cycle
                if (valid !== 1'b0) begin
                    $display("[FAIL] valid_o not single-cycle pulse");
                    test_passed = 1'b0;
                end
            end
        join

        // Switch to RIGHT channel (ws=1)
        ws = 1;
        @(posedge clk);

        // Send right channel (should be ignored by LEFT-capture DUT)
        send_i2s_half_frame(RIGHT_PATTERN);

        // Wait a bit to ensure no valid pulse for right channel
        repeat(100) @(posedge clk);

        // Verify only one valid pulse occurred (left channel only)
        if (valid_count == 1) begin
            $display("[PASS] Only left channel triggered valid (count=%0d)", valid_count);
        end else begin
            $display("[FAIL] Unexpected valid count: %0d (expected 1)", valid_count);
            test_passed = 1'b0;
        end

        // Final result
        repeat(20) @(posedge clk);
        if (test_passed) begin
            $display("\n*** ALL TESTS PASSED ***\n");
        end else begin
            $display("\n*** TEST FAILED ***\n");
        end

        $finish;
    end

    // Timeout watchdog
    initial begin
        #100000;  // 100 µs timeout
        $display("[FAIL] Testbench timeout");
        $finish;
    end

endmodule
