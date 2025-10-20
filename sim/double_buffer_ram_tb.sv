// =============================================================================
// double_buffer_ram_tb.sv
// Self-checking testbench for double_buffer_ram
// =============================================================================

`timescale 1ns/1ps

module double_buffer_ram_tb;

    // =========================================================================
    // Parameters
    // =========================================================================
    localparam int unsigned DATA_WIDTH      = 16;
    localparam int unsigned SAMPLES_PER_BUF = 256;
    localparam int unsigned ADDR_WIDTH      = $clog2(SAMPLES_PER_BUF);
    localparam bit          SYNTH_USE_GOWIN_DPB = 1'b0; // Use generic for sim
    localparam bit          DROP_WRITES_ON_TOGGLE = 1'b1;

    localparam int CLK_PERIOD = 10; // 100 MHz

    // =========================================================================
    // DUT signals
    // =========================================================================
    logic                     clk_i;
    logic                     rst_ni;

    logic                     in_valid_i;
    logic [DATA_WIDTH-1:0]    in_data_i;
    logic                     in_ready_o;

    logic [ADDR_WIDTH-1:0]    rd_addr_i;
    logic                     rd_en_i;
    logic [DATA_WIDTH-1:0]    rd_data_o;
    logic                     rd_data_valid_o;

    logic                     active_buf_o;
    logic                     buf_ready_pulse_o;
    logic                     buf_ready_id_o;

    // =========================================================================
    // Test control
    // =========================================================================
    int error_count = 0;
    int test_phase = 0;

    // Golden data storage for verification
    logic [DATA_WIDTH-1:0] golden_buffer_a [SAMPLES_PER_BUF];
    logic [DATA_WIDTH-1:0] golden_buffer_b [SAMPLES_PER_BUF];
    logic buffer_a_valid = 0;
    logic buffer_b_valid = 0;

    int write_count = 0;
    logic [DATA_WIDTH-1:0] current_write_value = 16'h1000;

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
    double_buffer_ram #(
        .DATA_WIDTH           (DATA_WIDTH),
        .SAMPLES_PER_BUF      (SAMPLES_PER_BUF),
        .ADDR_WIDTH           (ADDR_WIDTH),
        .SYNTH_USE_GOWIN_DPB  (SYNTH_USE_GOWIN_DPB),
        .DROP_WRITES_ON_TOGGLE(DROP_WRITES_ON_TOGGLE)
    ) dut (
        .clk_i              (clk_i),
        .rst_ni             (rst_ni),
        .in_valid_i         (in_valid_i),
        .in_data_i          (in_data_i),
        .in_ready_o         (in_ready_o),
        .rd_addr_i          (rd_addr_i),
        .rd_en_i            (rd_en_i),
        .rd_data_o          (rd_data_o),
        .rd_data_valid_o    (rd_data_valid_o),
        .active_buf_o       (active_buf_o),
        .buf_ready_pulse_o  (buf_ready_pulse_o),
        .buf_ready_id_o     (buf_ready_id_o)
    );

    // =========================================================================
    // Monitor buffer ready pulses and store golden data
    // =========================================================================
    always @(posedge clk_i) begin
        if (buf_ready_pulse_o) begin
            $display("[%0t] Buffer ready pulse: buffer %s filled (ID=%0d)",
                     $time, buf_ready_id_o ? "B" : "A", buf_ready_id_o);

            // Verify pulse is for the correct buffer
            if (buf_ready_id_o == 1'b0) begin
                buffer_a_valid = 1;
            end else begin
                buffer_b_valid = 1;
            end

            // Verify active_buf has toggled
            @(posedge clk_i);
            if (buf_ready_id_o == active_buf_o) begin
                $error("[%0t] ERROR: active_buf did not toggle after buffer ready!", $time);
                error_count++;
            end
        end
    end

    // =========================================================================
    // Task: Reset sequence
    // =========================================================================
    task automatic reset_dut();
        rst_ni = 0;
        in_valid_i = 0;
        in_data_i = 0;
        rd_addr_i = 0;
        rd_en_i = 0;
        repeat (5) @(posedge clk_i);
        rst_ni = 1;
        repeat (2) @(posedge clk_i);
        $display("[%0t] Reset complete", $time);
    endtask

    // =========================================================================
    // Task: Write samples with random gaps
    // =========================================================================
    task automatic write_samples(input int num_samples, input real valid_prob = 0.8);
        int samples_written = 0;
        logic [DATA_WIDTH-1:0] write_val;

        while (samples_written < num_samples) begin
            @(posedge clk_i);

            // Random gaps in valid signal
            if ($urandom_range(100) < (valid_prob * 100)) begin
                in_valid_i = 1;
                write_val = current_write_value;
                in_data_i = write_val;

                if (in_ready_o) begin
                    // Store in golden buffer based on active buffer
                    if (active_buf_o == 1'b0) begin
                        golden_buffer_a[write_count % SAMPLES_PER_BUF] = write_val;
                    end else begin
                        golden_buffer_b[write_count % SAMPLES_PER_BUF] = write_val;
                    end

                    current_write_value += 1;
                    write_count++;
                    samples_written++;
                end
            end else begin
                in_valid_i = 0;
            end
        end

        @(posedge clk_i);
        in_valid_i = 0;
    endtask

    // =========================================================================
    // Task: Read and verify inactive buffer
    // =========================================================================
    task automatic read_and_verify_buffer(input int buffer_id);
        logic [DATA_WIDTH-1:0] expected_data;
        logic [DATA_WIDTH-1:0] read_data_q;
        int local_errors = 0;

        $display("[%0t] Reading and verifying buffer %s", $time, buffer_id ? "B" : "A");

        // Read all addresses
        for (int addr = 0; addr < SAMPLES_PER_BUF; addr++) begin
            @(posedge clk_i);
            rd_addr_i = addr[ADDR_WIDTH-1:0];
            rd_en_i = 1;

            // Wait for read data (1-cycle latency)
            @(posedge clk_i);
            if (rd_data_valid_o) begin
                if (buffer_id == 0) begin
                    expected_data = golden_buffer_a[addr];
                end else begin
                    expected_data = golden_buffer_b[addr];
                end

                if (rd_data_o !== expected_data) begin
                    $error("[%0t] Readback mismatch at addr=%0d: expected=0x%04h, got=0x%04h",
                           $time, addr, expected_data, rd_data_o);
                    local_errors++;
                end
            end else begin
                $error("[%0t] rd_data_valid_o not asserted when expected!", $time);
                local_errors++;
            end
        end

        @(posedge clk_i);
        rd_en_i = 0;

        if (local_errors == 0) begin
            $display("[%0t] Buffer %s verification PASSED (%0d samples)",
                     $time, buffer_id ? "B" : "A", SAMPLES_PER_BUF);
        end else begin
            $display("[%0t] Buffer %s verification FAILED with %0d errors",
                     $time, buffer_id ? "B" : "A", local_errors);
            error_count += local_errors;
        end
    endtask

    // =========================================================================
    // Task: Continuous read while writing
    // =========================================================================
    task automatic continuous_read_while_write();
        fork
            // Write process
            begin
                write_samples(SAMPLES_PER_BUF * 2, 0.9);
            end

            // Continuous read process
            begin
                repeat (SAMPLES_PER_BUF * 3) begin
                    @(posedge clk_i);
                    rd_addr_i = $urandom_range(SAMPLES_PER_BUF - 1);
                    rd_en_i = 1;
                end
                @(posedge clk_i);
                rd_en_i = 0;
            end
        join
    endtask

    // =========================================================================
    // Main test sequence
    // =========================================================================
    initial begin
        $display("================================================================================");
        $display("DOUBLE_BUFFER_RAM TESTBENCH");
        $display("================================================================================");
        $display("Parameters: DATA_WIDTH=%0d, SAMPLES_PER_BUF=%0d, ADDR_WIDTH=%0d",
                 DATA_WIDTH, SAMPLES_PER_BUF, ADDR_WIDTH);
        $display("================================================================================");

        // =====================================================================
        // Test 1: Reset and initialization
        // =====================================================================
        test_phase = 1;
        $display("\n[TEST 1] Reset and initialization");
        reset_dut();

        // Verify initial state
        if (active_buf_o !== 1'b0) begin
            $error("Initial active_buf should be 0 (buffer A)");
            error_count++;
        end
        if (buf_ready_pulse_o !== 1'b0) begin
            $error("Initial buf_ready_pulse_o should be 0");
            error_count++;
        end

        // =====================================================================
        // Test 2: Fill first buffer (A)
        // =====================================================================
        test_phase = 2;
        $display("\n[TEST 2] Filling buffer A with %0d samples", SAMPLES_PER_BUF);
        write_samples(SAMPLES_PER_BUF, 1.0);

        // Wait for buffer ready pulse
        repeat (10) @(posedge clk_i);

        if (!buffer_a_valid) begin
            $error("Buffer A should be marked valid after filling");
            error_count++;
        end

        if (active_buf_o !== 1'b1) begin
            $error("After filling buffer A, active_buf should be 1 (buffer B)");
            error_count++;
        end

        // =====================================================================
        // Test 3: Fill second buffer (B) while reading first (A)
        // =====================================================================
        test_phase = 3;
        $display("\n[TEST 3] Filling buffer B while reading buffer A");

        fork
            // Write to buffer B
            begin
                write_samples(SAMPLES_PER_BUF, 0.85);
            end

            // Read from buffer A (now inactive)
            begin
                repeat (5) @(posedge clk_i); // Small delay before reading
                read_and_verify_buffer(0); // Read buffer A
            end
        join

        repeat (10) @(posedge clk_i);

        if (!buffer_b_valid) begin
            $error("Buffer B should be marked valid after filling");
            error_count++;
        end

        // =====================================================================
        // Test 4: Verify buffer B while writing to A
        // =====================================================================
        test_phase = 4;
        $display("\n[TEST 4] Filling buffer A again while reading buffer B");

        fork
            // Write to buffer A
            begin
                write_samples(SAMPLES_PER_BUF, 0.8);
            end

            // Read from buffer B (now inactive)
            begin
                repeat (5) @(posedge clk_i);
                read_and_verify_buffer(1); // Read buffer B
            end
        join

        repeat (10) @(posedge clk_i);

        // =====================================================================
        // Test 5: Continuous operation with concurrent read/write
        // =====================================================================
        test_phase = 5;
        $display("\n[TEST 5] Continuous read/write for multiple buffers");
        continuous_read_while_write();

        repeat (20) @(posedge clk_i);

        // =====================================================================
        // Test 6: Verify buf_ready_pulse timing
        // =====================================================================
        test_phase = 6;
        $display("\n[TEST 6] Verifying buf_ready_pulse timing");

        // Reset write counter
        write_count = 0;

        fork
            begin
                // Write exactly SAMPLES_PER_BUF samples
                write_samples(SAMPLES_PER_BUF, 1.0);
            end

            begin
                int pulse_count = 0;
                int pulse_cycle = -1;

                for (int i = 0; i < SAMPLES_PER_BUF + 20; i++) begin
                    @(posedge clk_i);
                    if (buf_ready_pulse_o) begin
                        pulse_count++;
                        pulse_cycle = i;
                        $display("[%0t] Pulse detected at cycle %0d", $time, i);

                        // Check next cycle - pulse should be low
                        @(posedge clk_i);
                        if (buf_ready_pulse_o) begin
                            $error("buf_ready_pulse_o not 1-cycle wide!");
                            error_count++;
                        end
                    end
                end

                if (pulse_count != 1) begin
                    $error("Expected exactly 1 pulse, got %0d", pulse_count);
                    error_count++;
                end
            end
        join

        // =====================================================================
        // Final results
        // =====================================================================
        repeat (20) @(posedge clk_i);

        $display("\n================================================================================");
        $display("TEST COMPLETE");
        $display("================================================================================");
        $display("Total errors: %0d", error_count);

        if (error_count == 0) begin
            $display("DOUBLE_BUFFER_RAM: PASS");
            $display("All tests passed successfully!");
        end else begin
            $display("DOUBLE_BUFFER_RAM: FAIL");
            $fatal(1, "Test failed with %0d errors", error_count);
        end

        $display("================================================================================\n");
        $finish;
    end

    // =========================================================================
    // Timeout watchdog
    // =========================================================================
    initial begin
        #(CLK_PERIOD * 100000); // 100k cycles timeout
        $fatal(1, "TIMEOUT: Test did not complete in time");
    end

    // =========================================================================
    // Waveform dump (optional)
    // =========================================================================
    initial begin
        $dumpfile("double_buffer_ram_tb.vcd");
        $dumpvars(0, double_buffer_ram_tb);
    end

endmodule
