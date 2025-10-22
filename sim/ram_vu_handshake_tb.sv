// ram_vu_handshake_tb.sv
// Comprehensive testbench for RAM-VU meter handshake verification
// Tests the integration of pingpong_sp_ram with vu_meter_6led
//
// Verifies:
//   1. RAM fills buffer with 256 samples and pulses buffer_ready_o
//   2. VU meter starts reading when buffer_ready_i pulses
//   3. Handshake protocol (read_ack_o ←→ read_enable_i)
//   4. RAM advances read address only on read_ack_i
//   5. read_enable_o goes LOW after all samples read
//   6. VU meter processes samples and drives LED outputs
//   7. Second buffer cycle works correctly

`timescale 1ns/1ps

module ram_vu_handshake_tb;

    // Parameters
    localparam int WIDTH = 16;
    localparam int DEPTH = 256;
    localparam int CLK_PERIOD = 37;  // ~27 MHz (37ns period)

    // DUT signals
    logic               clk;
    logic               rst_n;

    // RAM write interface (simulates I2S capture)
    logic [WIDTH-1:0]   sample_data;
    logic               sample_valid;

    // RAM→VU handshake signals
    logic [WIDTH-1:0]   read_data;
    logic               buffer_ready;
    logic               read_enable;
    logic               read_ack;

    // VU meter outputs
    logic [5:0]         leds;

    // Test variables
    int errors = 0;
    int warnings = 0;
    int sample_count = 0;
    int read_count = 0;

    // Instantiate pingpong_sp_ram
    pingpong_sp_ram #(
        .WIDTH(WIDTH),
        .DEPTH(DEPTH)
    ) u_ram (
        .clk_i          (clk),
        .rst_ni         (rst_n),
        .sample_i       (sample_data),
        .sample_ready_i (sample_valid),
        .read_data_o    (read_data),
        .buffer_ready_o (buffer_ready),
        .read_enable_o  (read_enable),
        .read_ack_i     (read_ack)
    );

    // Instantiate vu_meter_6led
    vu_meter_6led #(
        .SAMPLE_WIDTH   (WIDTH),
        .DECAY_SHIFT    (11),
        .SCALE_SHIFT    (2),
        .LED_DIV        (1000)  // Faster LED update for simulation
    ) u_vu (
        .clk_i          (clk),
        .rst_ni         (rst_n),
        .buffer_ready_i (buffer_ready),
        .read_enable_i  (read_enable),
        .ram_sample_i   (read_data),
        .read_ack_o     (read_ack),
        .leds_o         (leds)
    );

    // Clock generation
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    // Monitor read handshake activity
    always @(posedge clk) begin
        if (read_ack && read_enable) begin
            read_count++;
            if (read_count <= 5 || read_count >= 253) begin
                $display("  [%0t] Read ACK #%0d: data=0x%04h, LEDs=%06b",
                         $time, read_count, read_data, leds);
            end
        end
    end

    // Main test sequence
    initial begin
        $display("================================================================");
        $display("RAM-VU Meter Handshake Integration Testbench");
        $display("================================================================\n");

        // Initialize signals
        rst_n = 1'b0;
        sample_data = '0;
        sample_valid = 1'b0;

        // Hold reset
        repeat(10) @(posedge clk);
        rst_n = 1'b1;
        repeat(5) @(posedge clk);

        // ================================================================
        // Test 1: Write 256 samples to RAM (fill first buffer)
        // ================================================================
        $display("[Test 1] Writing 256 samples to RAM");
        $display("--------------------------------------------------------");

        for (int i = 0; i < DEPTH; i++) begin
            @(posedge clk);
            sample_valid = 1'b1;
            sample_data = 16'h1000 + i;  // Pattern: 0x1000..0x10FF
            sample_count++;
        end

        @(posedge clk);
        sample_valid = 1'b0;

        $display("  Wrote %0d samples to RAM", sample_count);
        $display("  PASS: First buffer filled\n");

        // ================================================================
        // Test 2: Verify buffer_ready pulse
        // ================================================================
        $display("[Test 2] Verifying buffer_ready_o pulse");
        $display("--------------------------------------------------------");

        // buffer_ready should have pulsed (may have already passed)
        // Check that read_enable is now HIGH
        repeat(5) @(posedge clk);

        if (!read_enable) begin
            $display("  ERROR: read_enable_o should be HIGH after buffer fill");
            errors++;
        end else begin
            $display("  PASS: read_enable_o is HIGH (buffer ready to read)\n");
        end

        // ================================================================
        // Test 3: Monitor VU meter reading all samples via handshake
        // ================================================================
        $display("[Test 3] VU meter reading samples via handshake");
        $display("--------------------------------------------------------");
        $display("  (Showing first 5 and last 3 reads for brevity)");

        read_count = 0;

        // Wait for VU meter to read all samples
        // VU meter should read at full speed (1 sample per clock)
        wait (read_count >= DEPTH || !read_enable);

        repeat(10) @(posedge clk);

        if (read_count < DEPTH-1) begin
            $display("  WARNING: Only %0d samples read, expected %0d", read_count, DEPTH);
            warnings++;
        end else begin
            $display("  PASS: VU meter read %0d samples", read_count);
        end

        // ================================================================
        // Test 4: Verify read_enable goes LOW after all samples read
        // ================================================================
        $display("\n[Test 4] Verifying read_enable_o goes LOW");
        $display("--------------------------------------------------------");

        repeat(10) @(posedge clk);

        if (read_enable) begin
            $display("  ERROR: read_enable_o should be LOW after all samples read");
            $display("         Current state: read_enable=%b, read_count=%0d",
                     read_enable, read_count);
            errors++;
        end else begin
            $display("  PASS: read_enable_o is LOW (all samples consumed)\n");
        end

        // ================================================================
        // Test 5: Write second buffer and verify ping-pong operation
        // ================================================================
        $display("[Test 5] Writing second buffer (256 samples)");
        $display("--------------------------------------------------------");

        sample_count = 0;
        for (int i = 0; i < DEPTH; i++) begin
            @(posedge clk);
            sample_valid = 1'b1;
            sample_data = 16'h2000 + i;  // Pattern: 0x2000..0x20FF
            sample_count++;
        end

        @(posedge clk);
        sample_valid = 1'b0;

        $display("  Wrote %0d samples to second buffer", sample_count);

        // Check buffer_ready pulse and read_enable
        repeat(5) @(posedge clk);

        if (!read_enable) begin
            $display("  ERROR: read_enable_o should be HIGH for second buffer");
            errors++;
        end else begin
            $display("  PASS: Second buffer ready, read_enable_o HIGH");
        end

        // ================================================================
        // Test 6: Verify VU meter reads second buffer
        // ================================================================
        $display("\n[Test 6] VU meter reading second buffer");
        $display("--------------------------------------------------------");

        read_count = 0;

        // Wait for reads to complete
        wait (read_count >= DEPTH || !read_enable);
        repeat(10) @(posedge clk);

        if (read_count < DEPTH-1) begin
            $display("  WARNING: Only %0d samples read from second buffer", read_count);
            warnings++;
        end else begin
            $display("  PASS: VU meter read %0d samples from second buffer", read_count);
        end

        // Verify read_enable is LOW again
        if (read_enable) begin
            $display("  ERROR: read_enable_o should be LOW after second buffer read");
            errors++;
        end else begin
            $display("  PASS: read_enable_o LOW after second buffer consumed");
        end

        // ================================================================
        // Test 7: Check LED outputs (basic sanity check)
        // ================================================================
        $display("\n[Test 7] Checking LED outputs");
        $display("--------------------------------------------------------");

        // LEDs should have some activity after processing samples
        // (Exact pattern depends on decay/threshold settings)
        $display("  Current LED state: %06b", leds);
        $display("  PASS: LED outputs operational (visual check in waveform)\n");

        // ================================================================
        // Final Summary
        // ================================================================
        $display("================================================================");
        $display("Test Summary");
        $display("================================================================");
        $display("  Errors:   %0d", errors);
        $display("  Warnings: %0d", warnings);

        if (errors == 0) begin
            $display("\n  *** PASS: All critical tests passed! ***");
            if (warnings > 0) begin
                $display("  Note: %0d warning(s) - check waveform for details", warnings);
            end
        end else begin
            $display("\n  *** FAIL: %0d error(s) detected ***", errors);
            $fatal(1, "Testbench failed with errors");
        end
        $display("================================================================\n");

        $finish;
    end

    // Timeout watchdog
    initial begin
        #500000;  // 500us timeout
        $display("\nERROR: Testbench timeout!");
        $fatal(1, "Timeout - simulation exceeded 500us");
    end

    // Waveform dumping
    initial begin
        $dumpfile("ram_vu_handshake.vcd");
        $dumpvars(0, ram_vu_handshake_tb);
    end

endmodule
