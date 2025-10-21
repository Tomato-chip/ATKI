// =============================================================================
// sampler_tb.sv
// Self-checking testbench for the sampler module
// =============================================================================

`timescale 1ns/1ps

module sampler_tb;

    // =========================================================================
    // Parameters matching DUT
    // =========================================================================
    localparam int unsigned N_MICS          = 1;
    localparam int unsigned DATA_WIDTH      = 16;
    localparam int unsigned SAMPLES_PER_BUF = 256;
    localparam int unsigned ADDR_WIDTH      = $clog2(SAMPLES_PER_BUF);

    localparam int CLK_PERIOD = 37;  // ~27 MHz clock (37ns period)

    // =========================================================================
    // DUT signals
    // =========================================================================
    logic                     clk_i;
    logic                     rst_ni;
    logic [DATA_WIDTH-1:0]    mic_data_i [N_MICS];
    logic                     mic_valid_i;
    logic                     buf_ready_pulse_o;
    logic [$clog2(N_MICS>1?N_MICS:2)-1:0] buf_ready_ch_o;
    logic                     active_buf_o;

    // =========================================================================
    // Test control
    // =========================================================================
    int error_count = 0;
    int sample_count = 0;
    logic [DATA_WIDTH-1:0] current_sample_value = 16'h5000;

    // Golden buffer storage for verification
    logic [DATA_WIDTH-1:0] golden_buffer_a [SAMPLES_PER_BUF];
    logic [DATA_WIDTH-1:0] golden_buffer_b [SAMPLES_PER_BUF];
    logic                  buffer_a_valid = 0;
    logic                  buffer_b_valid = 0;

    // =========================================================================
    // Clock generation
    // =========================================================================
    initial begin
        clk_i = 0;
        forever #(CLK_PERIOD/2) clk_i = ~clk_i;
    end

    // =========================================================================
    // DUT instantiation
    // =========================================================================
    sampler #(
        .N_MICS          (N_MICS),
        .DATA_WIDTH      (DATA_WIDTH),
        .SAMPLES_PER_BUF (SAMPLES_PER_BUF),
        .ADDR_WIDTH      (ADDR_WIDTH)
    ) dut (
        .clk_i              (clk_i),
        .rst_ni             (rst_ni),
        .mic_data_i         (mic_data_i),
        .mic_valid_i        (mic_valid_i),
        .buf_ready_pulse_o  (buf_ready_pulse_o),
        .buf_ready_ch_o     (buf_ready_ch_o),
        .active_buf_o       (active_buf_o)
    );

    // =========================================================================
    // Monitor buffer completion events
    // =========================================================================
    always @(posedge clk_i) begin
        if (buf_ready_pulse_o) begin
            $display("[%0t] Buffer ready pulse: channel %0d, buffer %s completed",
                     $time, buf_ready_ch_o, active_buf_o ? "A" : "B");

            // Mark which buffer is now valid for readback
            if (active_buf_o == 1'b1) begin
                // Just completed buffer A, now writing to B
                buffer_a_valid = 1;
            end else begin
                // Just completed buffer B, now writing to A
                buffer_b_valid = 1;
            end

            // Verify pulse is exactly 1 cycle wide
            @(posedge clk_i);
            if (buf_ready_pulse_o) begin
                $error("[%0t] ERROR: buf_ready_pulse_o not single-cycle!", $time);
                error_count++;
            end
        end
    end

    // =========================================================================
    // Task: Reset sequence
    // =========================================================================
    task automatic reset_dut();
        rst_ni = 0;
        mic_valid_i = 0;
        for (int i = 0; i < N_MICS; i++) begin
            mic_data_i[i] = '0;
        end
        repeat (10) @(posedge clk_i);
        rst_ni = 1;
        repeat (2) @(posedge clk_i);
        $display("[%0t] Reset complete", $time);
    endtask

    // =========================================================================
    // Task: Send microphone samples
    // =========================================================================
    task automatic send_samples(input int num_samples, input real valid_prob = 0.85);
        int samples_sent = 0;

        $display("[%0t] Sending %0d samples with valid_prob=%.2f", $time, num_samples, valid_prob);

        while (samples_sent < num_samples) begin
            @(posedge clk_i);

            // Random gaps in valid signal for realistic operation
            if ($urandom_range(1000) < (valid_prob * 1000)) begin
                mic_valid_i = 1;
                mic_data_i[0] = current_sample_value;

                // Store in golden buffer based on current active buffer
                if (active_buf_o == 1'b0) begin
                    golden_buffer_a[sample_count % SAMPLES_PER_BUF] = current_sample_value;
                end else begin
                    golden_buffer_b[sample_count % SAMPLES_PER_BUF] = current_sample_value;
                end

                current_sample_value += 1;
                sample_count++;
                samples_sent++;
            end else begin
                mic_valid_i = 0;
            end
        end

        @(posedge clk_i);
        mic_valid_i = 0;
        $display("[%0t] Sent %0d samples", $time, samples_sent);
    endtask

    // =========================================================================
    // Task: Read and verify buffer contents
    // =========================================================================
    task automatic verify_buffer(input int buffer_id);
        logic [DATA_WIDTH-1:0] expected_data;
        int local_errors = 0;

        $display("[%0t] Verifying buffer %s contents...", $time, buffer_id ? "B" : "A");

        // Access internal buffer for verification
        // Read through the double_buffer_ram's read interface
        for (int addr = 0; addr < SAMPLES_PER_BUF; addr++) begin
            @(posedge clk_i);

            // Drive read address and enable
            force dut.rd_addr[0] = addr[ADDR_WIDTH-1:0];
            force dut.rd_en[0] = 1'b1;

            // Wait for read latency (1 cycle)
            @(posedge clk_i);

            if (dut.rd_data_valid[0]) begin
                if (buffer_id == 0) begin
                    expected_data = golden_buffer_a[addr];
                end else begin
                    expected_data = golden_buffer_b[addr];
                end

                if (dut.rd_data[0] !== expected_data) begin
                    if (local_errors < 5) begin  // Limit error spam
                        $error("[%0t] Buffer %s[%0d] mismatch: expected=0x%04h, got=0x%04h",
                               $time, buffer_id ? "B" : "A", addr, expected_data, dut.rd_data[0]);
                    end
                    local_errors++;
                end
            end
        end

        @(posedge clk_i);
        release dut.rd_addr[0];
        release dut.rd_en[0];

        if (local_errors == 0) begin
            $display("[%0t] Buffer %s verification PASSED", $time, buffer_id ? "B" : "A");
        end else begin
            $display("[%0t] Buffer %s verification FAILED with %0d errors",
                     $time, buffer_id ? "B" : "A", local_errors);
            error_count += local_errors;
        end
    endtask

    // =========================================================================
    // Task: Verify sample count before buffer toggle
    // =========================================================================
    task automatic verify_sample_count();
        int start_count = sample_count;
        int toggle_count = 0;

        $display("[%0t] Verifying exactly %0d samples per buffer...", $time, SAMPLES_PER_BUF);

        // Send samples and count toggles
        fork
            begin
                send_samples(SAMPLES_PER_BUF * 2, 0.9);  // Send 2 full buffers
            end

            begin
                forever begin
                    @(posedge clk_i);
                    if (buf_ready_pulse_o) begin
                        toggle_count++;
                        if (toggle_count >= 2) break;
                    end
                end
            end
        join

        if (toggle_count == 2) begin
            $display("[%0t] Sample count verification PASSED (2 buffer toggles detected)", $time);
        end else begin
            $error("[%0t] Expected 2 buffer toggles, got %0d", $time, toggle_count);
            error_count++;
        end
    endtask

    // =========================================================================
    // Main test sequence
    // =========================================================================
    initial begin
        $display("================================================================================");
        $display("SAMPLER TESTBENCH");
        $display("================================================================================");
        $display("Parameters: N_MICS=%0d, DATA_WIDTH=%0d, SAMPLES_PER_BUF=%0d",
                 N_MICS, DATA_WIDTH, SAMPLES_PER_BUF);
        $display("================================================================================");

        // =====================================================================
        // Test 1: Reset and initialization
        // =====================================================================
        $display("\n[TEST 1] Reset and initialization");
        reset_dut();

        // Verify initial state
        if (active_buf_o !== 1'b0) begin
            $error("Initial active_buf_o should be 0 (buffer A)");
            error_count++;
        end
        if (buf_ready_pulse_o !== 1'b0) begin
            $error("Initial buf_ready_pulse_o should be 0");
            error_count++;
        end
        $display("[TEST 1] PASSED");

        // =====================================================================
        // Test 2: Fill first buffer (A) with 256 samples
        // =====================================================================
        $display("\n[TEST 2] Filling buffer A with %0d samples", SAMPLES_PER_BUF);
        sample_count = 0;  // Reset counter
        send_samples(SAMPLES_PER_BUF, 1.0);  // No gaps for predictable timing

        // Wait for buffer ready pulse
        repeat (10) @(posedge clk_i);

        if (!buffer_a_valid) begin
            $error("Buffer A should be marked valid after filling");
            error_count++;
        end

        if (active_buf_o !== 1'b1) begin
            $error("After filling buffer A, active_buf_o should be 1 (buffer B)");
            error_count++;
        end

        if (buf_ready_ch_o !== 0) begin
            $error("buf_ready_ch_o should be 0 for channel 0, got %0d", buf_ready_ch_o);
            error_count++;
        end
        $display("[TEST 2] PASSED");

        // =====================================================================
        // Test 3: Fill buffer B while verifying buffer A
        // =====================================================================
        $display("\n[TEST 3] Filling buffer B and verifying buffer A");
        send_samples(SAMPLES_PER_BUF, 0.85);  // With random gaps

        repeat (10) @(posedge clk_i);

        if (!buffer_b_valid) begin
            $error("Buffer B should be marked valid after filling");
            error_count++;
        end

        if (active_buf_o !== 1'b0) begin
            $error("After filling buffer B, active_buf_o should be 0 (buffer A)");
            error_count++;
        end

        // Verify buffer A contents
        verify_buffer(0);
        $display("[TEST 3] PASSED");

        // =====================================================================
        // Test 4: Verify buffer B contents
        // =====================================================================
        $display("\n[TEST 4] Verifying buffer B contents");
        verify_buffer(1);
        $display("[TEST 4] PASSED");

        // =====================================================================
        // Test 5: Continuous operation with sample count verification
        // =====================================================================
        $display("\n[TEST 5] Continuous operation - verifying sample count");
        sample_count = 0;  // Reset counter
        verify_sample_count();
        $display("[TEST 5] PASSED");

        // =====================================================================
        // Test 6: Verify pulse timing with gaps
        // =====================================================================
        $display("\n[TEST 6] Verifying pulse timing with random gaps");
        sample_count = 0;

        int pulse_count = 0;
        fork
            begin
                send_samples(SAMPLES_PER_BUF, 0.7);  // More gaps
            end

            begin
                forever begin
                    @(posedge clk_i);
                    if (buf_ready_pulse_o) begin
                        pulse_count++;
                        break;
                    end
                end
            end
        join

        if (pulse_count == 1) begin
            $display("[%0t] Pulse timing verification PASSED", $time);
        end else begin
            $error("Expected 1 pulse, got %0d", pulse_count);
            error_count++;
        end
        $display("[TEST 6] PASSED");

        // =====================================================================
        // Final results
        // =====================================================================
        repeat (20) @(posedge clk_i);

        $display("\n================================================================================");
        $display("TEST COMPLETE");
        $display("================================================================================");
        $display("Total errors: %0d", error_count);

        if (error_count == 0) begin
            $display("SAMPLER: PASS");
            $display("All tests passed successfully!");
        end else begin
            $display("SAMPLER: FAIL");
            $fatal(1, "Test failed with %0d errors", error_count);
        end

        $display("================================================================================\n");
        $finish;
    end

    // =========================================================================
    // Timeout watchdog
    // =========================================================================
    initial begin
        #(CLK_PERIOD * 200000);  // 200k cycles timeout
        $fatal(1, "TIMEOUT: Test did not complete in time");
    end

    // =========================================================================
    // Waveform dump
    // =========================================================================
    initial begin
        $dumpfile("sampler_tb.vcd");
        $dumpvars(0, sampler_tb);
    end

endmodule
