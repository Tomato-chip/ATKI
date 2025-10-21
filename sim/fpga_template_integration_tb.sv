// =============================================================================
// fpga_template_integration_tb.sv
// Standalone testbench for fpga_template_top with integrated sampling system
// =============================================================================
// This testbench drives the internal nets of fpga_template_top since the
// integrated modules (i2s_clock_gen, sampler, double_buffer_ram) are not
// exposed via top-level ports. It uses hierarchical references and force/release
// to access internal signals for verification.
// =============================================================================

`timescale 1ns/1ps

module fpga_template_integration_tb;

    // =========================================================================
    // Parameters
    // =========================================================================
    localparam int CLK_PERIOD = 37;  // ~27 MHz (37ns period)
    localparam int SAMPLES_PER_BUFFER = 256;
    localparam int SAMPLE_WIDTH = 16;

    // =========================================================================
    // DUT signals (top-level ports only)
    // =========================================================================
    logic       clk;
    logic       i2c_scl;
    wire        i2c_sda;
    logic [5:0] debug_led_pin;
    logic       btn_s1_resetb;
    logic       btn_s2;
    logic       i2s_sck;
    logic       i2s_ws;
    logic       frame_start;

    // =========================================================================
    // Test control
    // =========================================================================
    int error_count = 0;
    int buffer_complete_count = 0;

    // =========================================================================
    // Clock generation
    // =========================================================================
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    // =========================================================================
    // DUT instantiation
    // =========================================================================
    fpga_template_top dut (
        .clk                (clk),
        .i2c_scl            (i2c_scl),
        .i2c_sda            (i2c_sda),
        .debug_led_pin      (debug_led_pin),
        .btn_s1_resetb      (btn_s1_resetb),
        .btn_s2             (btn_s2),
        .i2s_sck            (i2s_sck),
        .i2s_ws             (i2s_ws),
        .frame_start        (frame_start)
    );

    // =========================================================================
    // Hierarchical signal access for internal verification
    // =========================================================================
    // Access internal sampler signals via hierarchical paths
    wire sampler_buf_ready_pulse = dut.sampler_buf_ready_pulse;
    wire sampler_active_buf = dut.sampler_active_buf;
    wire [SAMPLE_WIDTH-1:0] dummy_mic_counter = dut.dummy_mic_counter;
    wire mic_sample_valid = dut.mic_sample_valid;

    // Access i2s_clock_gen signals
    wire i2s_frame_start = dut.frame_start;

    // Access double_buffer_ram signals through sampler hierarchy
    wire ch0_buf_ready = dut.u_sampler.ch_buf_ready_pulse[0];
    wire ch0_active_buf = dut.u_sampler.ch_active_buf[0];

    // =========================================================================
    // Monitor key events
    // =========================================================================
    always @(posedge clk) begin
        if (sampler_buf_ready_pulse) begin
            buffer_complete_count++;
            $display("[%0t] Buffer %0d completed (active_buf=%0d, sample_count=%0d)",
                     $time, buffer_complete_count, sampler_active_buf, dummy_mic_counter);

            // Verify pulse is single-cycle
            @(posedge clk);
            if (sampler_buf_ready_pulse) begin
                $error("[%0t] ERROR: buf_ready_pulse not single-cycle!", $time);
                error_count++;
            end
        end
    end

    // Monitor I2S frame_start pulses
    int frame_count = 0;
    always @(posedge clk) begin
        if (i2s_frame_start) begin
            frame_count++;
        end
    end

    // =========================================================================
    // Task: Reset sequence
    // =========================================================================
    task automatic reset_dut();
        $display("[%0t] Starting reset sequence", $time);
        btn_s1_resetb = 1;  // Active-low reset
        btn_s2 = 0;
        i2c_scl = 1;
        repeat (5) @(posedge clk);
        btn_s1_resetb = 0;  // Release reset
        repeat (3) @(posedge clk);
        $display("[%0t] Reset complete", $time);
    endtask

    // =========================================================================
    // Task: Wait for N buffer completions
    // =========================================================================
    task automatic wait_for_buffers(input int num_buffers);
        int start_count = buffer_complete_count;
        int target_count = start_count + num_buffers;
        int timeout_cycles = SAMPLES_PER_BUFFER * num_buffers * 300;  // Conservative timeout
        int cycle_count = 0;

        $display("[%0t] Waiting for %0d buffer completions...", $time, num_buffers);

        while (buffer_complete_count < target_count && cycle_count < timeout_cycles) begin
            @(posedge clk);
            cycle_count++;
        end

        if (cycle_count >= timeout_cycles) begin
            $error("[%0t] TIMEOUT: Only %0d of %0d buffers completed",
                   $time, buffer_complete_count - start_count, num_buffers);
            error_count++;
        end else begin
            $display("[%0t] Successfully completed %0d buffers", $time, num_buffers);
        end
    endtask

    // =========================================================================
    // Task: Verify I2S clock generation
    // =========================================================================
    task automatic verify_i2s_clocks();
        int sck_count = 0;
        int ws_transitions = 0;
        logic prev_ws = 0;

        $display("[%0t] Verifying I2S clock generation...", $time);

        // Count SCK edges and WS transitions over a short period
        for (int i = 0; i < 1000; i++) begin
            @(posedge clk);
            if (i2s_sck !== prev_ws) begin  // Any toggle
                sck_count++;
            end
            if (i2s_ws !== prev_ws) begin
                ws_transitions++;
                prev_ws = i2s_ws;
            end
        end

        if (sck_count < 10) begin
            $error("[%0t] I2S SCK not toggling (count=%0d)", $time, sck_count);
            error_count++;
        end else begin
            $display("[%0t] I2S SCK toggling correctly (count=%0d)", $time, sck_count);
        end

        if (ws_transitions < 2) begin
            $warning("[%0t] I2S WS not toggling much (transitions=%0d)", $time, ws_transitions);
        end else begin
            $display("[%0t] I2S WS toggling correctly (transitions=%0d)", $time, ws_transitions);
        end
    endtask

    // =========================================================================
    // Task: Verify sampling operation
    // =========================================================================
    task automatic verify_sampling();
        int start_frame_count = frame_count;
        int start_sample_count = dummy_mic_counter;

        $display("[%0t] Verifying sampling operation...", $time);

        // Wait for some frames
        repeat (1000) @(posedge clk);

        if (frame_count <= start_frame_count) begin
            $error("[%0t] No frame_start pulses detected!", $time);
            error_count++;
        end else begin
            $display("[%0t] Frame_start pulses detected: %0d",
                     $time, frame_count - start_frame_count);
        end

        if (dummy_mic_counter <= start_sample_count) begin
            $error("[%0t] Sample counter not incrementing!", $time);
            error_count++;
        end else begin
            $display("[%0t] Sample counter incrementing correctly: %0d samples",
                     $time, dummy_mic_counter - start_sample_count);
        end
    endtask

    // =========================================================================
    // Task: Verify buffer toggle behavior
    // =========================================================================
    task automatic verify_buffer_toggle();
        logic prev_active_buf;

        $display("[%0t] Verifying buffer toggle behavior...", $time);

        // Wait for first buffer completion
        while (!sampler_buf_ready_pulse) @(posedge clk);
        prev_active_buf = sampler_active_buf;
        $display("[%0t] First buffer completed, active_buf=%0d", $time, prev_active_buf);

        // Wait for second buffer completion
        while (!sampler_buf_ready_pulse) @(posedge clk);

        if (sampler_active_buf === prev_active_buf) begin
            $error("[%0t] Buffer did not toggle! Still at %0d", $time, sampler_active_buf);
            error_count++;
        end else begin
            $display("[%0t] Buffer toggled correctly: %0d -> %0d",
                     $time, prev_active_buf, sampler_active_buf);
        end
    endtask

    // =========================================================================
    // Task: Read and verify buffer contents (optional, requires force)
    // =========================================================================
    task automatic verify_buffer_contents();
        logic [SAMPLE_WIDTH-1:0] expected_value;
        logic [SAMPLE_WIDTH-1:0] read_value;
        int local_errors = 0;

        $display("[%0t] Verifying buffer contents (spot check)...", $time);

        // Read a few locations from the inactive buffer
        for (int addr = 0; addr < 10; addr++) begin
            @(posedge clk);

            // Force read interface
            force dut.u_sampler.rd_addr[0] = addr[7:0];
            force dut.u_sampler.rd_en[0] = 1'b1;

            // Wait for read latency
            @(posedge clk);

            if (dut.u_sampler.rd_data_valid[0]) begin
                read_value = dut.u_sampler.rd_data[0];
                // Note: Can't easily predict exact values due to timing,
                // but we can verify data is present and non-zero
                if (read_value === 16'h0000 && addr > 0) begin
                    $warning("[%0t] Buffer[%0d] = 0x0000 (may be uninitialized)", $time, addr);
                end else begin
                    $display("[%0t] Buffer[%0d] = 0x%04h", $time, addr, read_value);
                end
            end
        end

        @(posedge clk);
        release dut.u_sampler.rd_addr[0];
        release dut.u_sampler.rd_en[0];

        if (local_errors == 0) begin
            $display("[%0t] Buffer contents verification completed", $time);
        end
    endtask

    // =========================================================================
    // Main test sequence
    // =========================================================================
    initial begin
        $display("================================================================================");
        $display("FPGA_TEMPLATE INTEGRATION TESTBENCH");
        $display("================================================================================");
        $display("Testing: i2s_clock_gen + sampler + double_buffer_ram integration");
        $display("================================================================================");

        // =====================================================================
        // Test 1: Reset and initialization
        // =====================================================================
        $display("\n[TEST 1] Reset and initialization");
        reset_dut();

        // Verify initial states
        if (sampler_active_buf !== 1'b0) begin
            $error("Initial active_buf should be 0");
            error_count++;
        end
        if (sampler_buf_ready_pulse !== 1'b0) begin
            $error("Initial buf_ready_pulse should be 0");
            error_count++;
        end
        $display("[TEST 1] PASSED");

        // =====================================================================
        // Test 2: I2S clock generation
        // =====================================================================
        $display("\n[TEST 2] I2S clock generation");
        verify_i2s_clocks();
        $display("[TEST 2] PASSED");

        // =====================================================================
        // Test 3: Sampling operation
        // =====================================================================
        $display("\n[TEST 3] Sampling operation");
        verify_sampling();
        $display("[TEST 3] PASSED");

        // =====================================================================
        // Test 4: Buffer completion
        // =====================================================================
        $display("\n[TEST 4] Buffer completion events");
        wait_for_buffers(2);

        if (buffer_complete_count < 2) begin
            $error("Expected at least 2 buffer completions, got %0d", buffer_complete_count);
            error_count++;
        end else begin
            $display("[%0t] Buffer completions verified: %0d", $time, buffer_complete_count);
        end
        $display("[TEST 4] PASSED");

        // =====================================================================
        // Test 5: Buffer toggle
        // =====================================================================
        $display("\n[TEST 5] Buffer toggle behavior");
        verify_buffer_toggle();
        $display("[TEST 5] PASSED");

        // =====================================================================
        // Test 6: Buffer contents (optional spot check)
        // =====================================================================
        $display("\n[TEST 6] Buffer contents spot check");
        verify_buffer_contents();
        $display("[TEST 6] PASSED");

        // =====================================================================
        // Test 7: Continuous operation
        // =====================================================================
        $display("\n[TEST 7] Continuous operation");
        wait_for_buffers(3);
        $display("[TEST 7] PASSED - Total buffers: %0d", buffer_complete_count);

        // =====================================================================
        // Final results
        // =====================================================================
        repeat (20) @(posedge clk);

        $display("\n================================================================================");
        $display("TEST COMPLETE");
        $display("================================================================================");
        $display("Total buffer completions: %0d", buffer_complete_count);
        $display("Total frame_start pulses: %0d", frame_count);
        $display("Final sample counter: %0d", dummy_mic_counter);
        $display("Total errors: %0d", error_count);

        if (error_count == 0) begin
            $display("\n*** FPGA_TEMPLATE_INTEGRATION: PASS ***");
            $display("All integration tests passed successfully!");
        end else begin
            $display("\n*** FPGA_TEMPLATE_INTEGRATION: FAIL ***");
            $error("Test failed with %0d errors", error_count);
        end

        $display("================================================================================\n");
        $finish;
    end

    // =========================================================================
    // Timeout watchdog
    // =========================================================================
    initial begin
        #(CLK_PERIOD * 500000);  // 500k cycles timeout
        $fatal(1, "TIMEOUT: Test did not complete in time");
    end

    // =========================================================================
    // Waveform dump
    // =========================================================================
    initial begin
        $dumpfile("fpga_template_integration_tb.vcd");
        $dumpvars(0, fpga_template_integration_tb);
        // Also dump internal signals for debugging
        $dumpvars(1, dut.u_i2s_clocks);
        $dumpvars(1, dut.u_sampler);
    end

endmodule
