//==============================================================================
// Testbench for ram_logic ping-pong buffer
//
// Tests:
//   1. Reset behavior
//   2. Write operations
//   3. Buffer swap
//   4. Read operations
//   5. Full ping-pong operation
//   6. Overflow detection
//==============================================================================

`timescale 1ns/1ps

module ram_logic_tb;

    //==========================================================================
    // Parameters
    //==========================================================================
    localparam int WIDTH = 32;
    localparam int DEPTH = 16;
    localparam int ADDR_WIDTH = $clog2(DEPTH);

    localparam int CLK_PERIOD = 10;  // 100 MHz

    //==========================================================================
    // DUT Signals
    //==========================================================================
    logic                       clk;
    logic                       rst_n;

    logic signed [WIDTH-1:0]    write_data;
    logic                       write_valid;
    logic                       write_ready;

    logic signed [WIDTH-1:0]    read_data;
    logic                       read_ready;
    logic                       read_valid;

    logic                       buffer_ready;
    logic                       buffer_overflow;
    logic [ADDR_WIDTH:0]        write_count;
    logic [ADDR_WIDTH:0]        read_count;

    //==========================================================================
    // Test Variables
    //==========================================================================
    int test_errors = 0;
    int test_passed = 0;
    logic signed [WIDTH-1:0] test_data[DEPTH];
    logic signed [WIDTH-1:0] read_back[DEPTH];

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
    ram_logic #(
        .WIDTH      (WIDTH),
        .DEPTH      (DEPTH),
        .ADDR_WIDTH (ADDR_WIDTH)
    ) dut (
        .clk_i              (clk),
        .rst_ni             (rst_n),
        .write_data_i       (write_data),
        .write_valid_i      (write_valid),
        .write_ready_o      (write_ready),
        .read_data_o        (read_data),
        .read_ready_i       (read_ready),
        .read_valid_o       (read_valid),
        .buffer_ready_o     (buffer_ready),
        .buffer_overflow_o  (buffer_overflow),
        .write_count_o      (write_count),
        .read_count_o       (read_count)
    );

    //==========================================================================
    // Waveform Dump
    //==========================================================================
    initial begin
        $dumpfile("ram_logic_tb.vcd");
        $dumpvars(0, ram_logic_tb);
    end

    //==========================================================================
    // Task: Reset DUT
    //==========================================================================
    task automatic reset_dut();
        $display("========================================");
        $display("Applying Reset...");
        $display("========================================");

        write_valid = 0;
        read_ready = 0;
        write_data = 0;
        rst_n = 0;

        repeat(5) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);

        $display("Reset complete\n");
    endtask

    //==========================================================================
    // Task: Write Single Sample
    //==========================================================================
    task automatic write_sample(input logic signed [WIDTH-1:0] data);
        write_data = data;
        write_valid = 1;

        // Wait for write_ready
        while (!write_ready) @(posedge clk);

        @(posedge clk);
        write_valid = 0;
    endtask

    //==========================================================================
    // Task: Read Single Sample
    //==========================================================================
    task automatic read_sample(output logic signed [WIDTH-1:0] data);
        read_ready = 1;

        // Wait for read_valid
        while (!read_valid) @(posedge clk);

        data = read_data;
        @(posedge clk);
        read_ready = 0;
    endtask

    //==========================================================================
    // Test 1: Reset Behavior
    //==========================================================================
    task automatic test_reset();
        $display("========================================");
        $display("TEST 1: Reset Behavior");
        $display("========================================");

        reset_dut();

        // Check reset state
        if (write_ready !== 1'b1) begin
            $display("ERROR: write_ready should be 1 after reset");
            test_errors++;
        end

        if (read_valid !== 1'b0) begin
            $display("ERROR: read_valid should be 0 after reset");
            test_errors++;
        end

        if (write_count !== 0) begin
            $display("ERROR: write_count should be 0 after reset");
            test_errors++;
        end

        if (read_count !== 0) begin
            $display("ERROR: read_count should be 0 after reset");
            test_errors++;
        end

        if (test_errors == 0) begin
            $display("✓ Test PASSED\n");
            test_passed++;
        end else begin
            $display("✗ Test FAILED\n");
        end
    endtask

    //==========================================================================
    // Test 2: Write Operations
    //==========================================================================
    task automatic test_write_operations();
        $display("========================================");
        $display("TEST 2: Write Operations");
        $display("========================================");

        reset_dut();

        // Write DEPTH samples
        for (int i = 0; i < DEPTH; i++) begin
            test_data[i] = $signed(32'h1000 + i);
            $display("Writing sample %0d: 0x%08x", i, test_data[i]);
            write_sample(test_data[i]);

            @(posedge clk);

            // Check write count
            if (write_count !== (i + 1)) begin
                $display("ERROR: write_count = %0d, expected %0d", write_count, i + 1);
                test_errors++;
            end
        end

        if (test_errors == 0) begin
            $display("✓ Test PASSED\n");
            test_passed++;
        end else begin
            $display("✗ Test FAILED\n");
        end
    endtask

    //==========================================================================
    // Test 3: Buffer Swap
    //==========================================================================
    task automatic test_buffer_swap();
        $display("========================================");
        $display("TEST 3: Buffer Swap");
        $display("========================================");

        reset_dut();

        // Write DEPTH samples
        for (int i = 0; i < DEPTH; i++) begin
            write_sample($signed(32'h2000 + i));
        end

        @(posedge clk);

        // Check write_count reset
        if (write_count !== 0) begin
            $display("ERROR: write_count should reset to 0 after swap, got %0d", write_count);
            test_errors++;
        end

        // Check read_valid
        if (read_valid !== 1'b1) begin
            $display("ERROR: read_valid should be 1 after buffer swap");
            test_errors++;
        end

        if (test_errors == 0) begin
            $display("✓ Test PASSED\n");
            test_passed++;
        end else begin
            $display("✗ Test FAILED\n");
        end
    endtask

    //==========================================================================
    // Test 4: Read Operations
    //==========================================================================
    task automatic test_read_operations();
        $display("========================================");
        $display("TEST 4: Read Operations");
        $display("========================================");

        reset_dut();

        // Write test data
        for (int i = 0; i < DEPTH; i++) begin
            test_data[i] = $signed(32'h3000 + i);
            write_sample(test_data[i]);
        end

        @(posedge clk);

        // Read back data
        for (int i = 0; i < DEPTH; i++) begin
            read_sample(read_back[i]);
            $display("Read sample %0d: 0x%08x, expected: 0x%08x",
                     i, read_back[i], test_data[i]);

            if (read_back[i] !== test_data[i]) begin
                $display("ERROR: Data mismatch at %0d", i);
                test_errors++;
            end
        end

        if (test_errors == 0) begin
            $display("✓ Test PASSED\n");
            test_passed++;
        end else begin
            $display("✗ Test FAILED\n");
        end
    endtask

    //==========================================================================
    // Test 5: Ping-Pong Operation
    //==========================================================================
    task automatic test_ping_pong();
        $display("========================================");
        $display("TEST 5: Ping-Pong Operation");
        $display("========================================");

        reset_dut();

        // Fill first buffer
        $display("Filling first buffer...");
        for (int i = 0; i < DEPTH; i++) begin
            write_sample($signed(32'h4000 + i));
        end

        @(posedge clk);

        // Concurrent read/write for second buffer
        $display("Concurrent read/write for buffer 2...");
        fork
            // Write second buffer
            begin
                for (int i = 0; i < DEPTH; i++) begin
                    write_sample($signed(32'h5000 + i));
                end
            end

            // Read first buffer
            begin
                for (int i = 0; i < DEPTH; i++) begin
                    automatic logic signed [WIDTH-1:0] data;
                    read_sample(data);
                    if (data !== $signed(32'h4000 + i)) begin
                        $display("ERROR: Read mismatch at %0d: got 0x%08x, expected 0x%08x",
                                 i, data, 32'h4000 + i);
                        test_errors++;
                    end
                end
            end
        join

        if (test_errors == 0) begin
            $display("✓ Test PASSED\n");
            test_passed++;
        end else begin
            $display("✗ Test FAILED\n");
        end
    endtask

    //==========================================================================
    // Test 6: Overflow Detection
    //==========================================================================
    task automatic test_overflow();
        $display("========================================");
        $display("TEST 6: Overflow Detection");
        $display("========================================");

        reset_dut();

        // Fill first buffer
        for (int i = 0; i < DEPTH; i++) begin
            write_sample($signed(32'h6000 + i));
        end

        @(posedge clk);

        // Fill second buffer without reading
        for (int i = 0; i < DEPTH; i++) begin
            write_sample($signed(32'h7000 + i));
        end

        @(posedge clk);

        // write_ready should be low now
        if (write_ready !== 1'b0) begin
            $display("ERROR: write_ready should be 0 when buffer full");
            test_errors++;
        end

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
        $display("RAM Logic Ping-Pong Buffer Testbench");
        $display("================================================================================");
        $display("WIDTH = %0d, DEPTH = %0d", WIDTH, DEPTH);
        $display("================================================================================\n");

        // Run all tests
        test_reset();
        test_write_operations();
        test_buffer_swap();
        test_read_operations();
        test_ping_pong();
        test_overflow();

        // Summary
        $display("\n");
        $display("================================================================================");
        $display("TEST SUMMARY");
        $display("================================================================================");
        $display("Tests Passed: %0d/6", test_passed);
        $display("Errors:       %0d", test_errors);
        $display("================================================================================");

        if (test_errors == 0 && test_passed == 6) begin
            $display("✓ ALL TESTS PASSED!");
        end else begin
            $display("✗ SOME TESTS FAILED");
        end

        $display("================================================================================\n");

        repeat(10) @(posedge clk);
        $finish;
    end

    //==========================================================================
    // Timeout Watchdog
    //==========================================================================
    initial begin
        #1000000;  // 1ms timeout
        $display("ERROR: Simulation timeout!");
        $finish;
    end

endmodule
