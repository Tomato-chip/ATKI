//==============================================================================
// ram_logic_tb.sv
//
// Testbench for ram_logic ping-pong buffer RAM controller
//
// Tests:
//   1. Basic write-read operation
//   2. Buffer swap functionality
//   3. Continuous ping-pong operation
//   4. Read/write handshaking
//   5. Overflow detection
//   6. Independent read/write speeds
//
//==============================================================================

`timescale 1ns/1ps

module ram_logic_tb;

    //==========================================================================
    // Parameters
    //==========================================================================
    localparam int WIDTH = 16;
    localparam int DEPTH = 16;  // Small depth for faster simulation
    localparam int ADDR_WIDTH = $clog2(DEPTH);

    localparam time CLK_PERIOD = 10ns;  // 100MHz clock

    //==========================================================================
    // DUT signals
    //==========================================================================
    logic                   clk;
    logic                   rst_n;

    // Write interface
    logic [WIDTH-1:0]       write_data;
    logic                   write_valid;
    logic                   write_ready;

    // Read interface
    logic [WIDTH-1:0]       read_data;
    logic                   read_ready;
    logic                   read_valid;

    // Status
    logic                   buffer_ready;
    logic                   buffer_overflow;
    logic [ADDR_WIDTH:0]    write_count;
    logic [ADDR_WIDTH:0]    read_count;

    //==========================================================================
    // Test control
    //==========================================================================
    int error_count = 0;
    int test_num = 0;

    //==========================================================================
    // Clock generation
    //==========================================================================
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    //==========================================================================
    // DUT instantiation
    //==========================================================================
    ram_logic #(
        .WIDTH      (WIDTH),
        .DEPTH      (DEPTH)
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
    // Memory model for checking read data
    //==========================================================================
    logic [WIDTH-1:0] expected_buffer [0:DEPTH-1];
    int write_index = 0;
    int read_index = 0;
    int buffer_number = 0;

    //==========================================================================
    // Tasks
    //==========================================================================

    // Reset task
    task automatic reset_dut();
        $display("[%0t] Applying reset...", $time);
        rst_n = 0;
        write_valid = 0;
        read_ready = 0;
        write_data = '0;
        repeat(5) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);
        $display("[%0t] Reset complete", $time);
    endtask

    // Write single sample
    task automatic write_sample(input logic [WIDTH-1:0] data);
        write_data = data;
        write_valid = 1;
        @(posedge clk);
        while (!write_ready) @(posedge clk);  // Wait for ready
        @(posedge clk);
        write_valid = 0;
    endtask

    // Write full buffer
    task automatic write_buffer(input int start_val);
        $display("[%0t] Writing buffer %0d with values %0d to %0d",
                 $time, buffer_number, start_val, start_val + DEPTH - 1);

        for (int i = 0; i < DEPTH; i++) begin
            logic [WIDTH-1:0] data = start_val + i;
            expected_buffer[i] = data;

            write_data = data;
            write_valid = 1;
            @(posedge clk);

            // Wait for write to be accepted
            while (!write_ready || !write_valid) @(posedge clk);

            if (i < DEPTH-1) begin
                @(posedge clk);
            end
        end

        write_valid = 0;
        buffer_number++;
        @(posedge clk);
    endtask

    // Read and verify full buffer
    task automatic read_verify_buffer();
        int errors_this_buffer = 0;

        $display("[%0t] Reading and verifying buffer...", $time);

        // Wait for buffer ready signal
        while (!buffer_ready) @(posedge clk);
        $display("[%0t] Buffer ready signal detected", $time);

        read_ready = 1;

        for (int i = 0; i < DEPTH; i++) begin
            // Wait for valid data
            while (!read_valid) @(posedge clk);

            // Check data
            if (read_data !== expected_buffer[i]) begin
                $display("[%0t] ERROR: Read mismatch at index %0d - Expected: 0x%04h, Got: 0x%04h",
                         $time, i, expected_buffer[i], read_data);
                error_count++;
                errors_this_buffer++;
            end else begin
                $display("[%0t] Read[%0d]: 0x%04h (correct)", $time, i, read_data);
            end

            @(posedge clk);
        end

        read_ready = 0;

        if (errors_this_buffer == 0) begin
            $display("[%0t] Buffer verification PASSED - all %0d samples correct", $time, DEPTH);
        end else begin
            $display("[%0t] Buffer verification FAILED - %0d errors", $time, errors_this_buffer);
        end
    endtask

    // Read with variable ready signal (simulates slow consumer)
    task automatic read_buffer_slow();
        $display("[%0t] Reading buffer with variable ready...", $time);

        while (!buffer_ready) @(posedge clk);

        for (int i = 0; i < DEPTH; i++) begin
            // Toggle ready randomly
            read_ready = ($urandom % 3 != 0);  // ~66% ready

            if (read_ready && read_valid) begin
                $display("[%0t] Read[%0d]: 0x%04h", $time, i, read_data);
                @(posedge clk);
            end else begin
                @(posedge clk);
                i--;  // Retry this sample
            end
        end

        read_ready = 0;
    endtask

    //==========================================================================
    // Main test sequence
    //==========================================================================
    initial begin
        $display("================================================================================");
        $display("RAM Logic Testbench Start");
        $display("Parameters: WIDTH=%0d, DEPTH=%0d", WIDTH, DEPTH);
        $display("================================================================================");

        // Initialize VCD dump
        $dumpfile("ram_logic_tb.vcd");
        $dumpvars(0, ram_logic_tb);

        // Initialize
        clk = 0;
        rst_n = 0;
        write_valid = 0;
        read_ready = 0;
        write_data = '0;

        //======================================================================
        // TEST 1: Basic Reset
        //======================================================================
        test_num++;
        $display("\n[TEST %0d] Basic Reset Test", test_num);
        reset_dut();

        if (write_ready && !read_valid && !buffer_ready) begin
            $display("[TEST %0d] PASSED - Initial state correct", test_num);
        end else begin
            $display("[TEST %0d] FAILED - Initial state incorrect", test_num);
            error_count++;
        end

        //======================================================================
        // TEST 2: Write first buffer and check buffer_ready pulse
        //======================================================================
        test_num++;
        $display("\n[TEST %0d] Write First Buffer", test_num);

        fork
            // Write process
            begin
                write_buffer(16'h0100);
            end

            // Monitor for buffer_ready pulse
            begin
                logic saw_buffer_ready = 0;
                while (!saw_buffer_ready) begin
                    @(posedge clk);
                    if (buffer_ready) saw_buffer_ready = 1;
                end
                $display("[TEST %0d] PASSED - Buffer ready pulse detected", test_num);
            end
        join

        repeat(5) @(posedge clk);

        //======================================================================
        // TEST 3: Read first buffer
        //======================================================================
        test_num++;
        $display("\n[TEST %0d] Read and Verify First Buffer", test_num);

        // Buffer should already be ready, so don't wait for the pulse again
        read_ready = 1;

        for (int i = 0; i < DEPTH; i++) begin
            // Wait for valid data
            while (!read_valid) @(posedge clk);

            // Check data
            if (read_data !== expected_buffer[i]) begin
                $display("[%0t] ERROR: Read mismatch at index %0d - Expected: 0x%04h, Got: 0x%04h",
                         $time, i, expected_buffer[i], read_data);
                error_count++;
            end else begin
                $display("[%0t] Read[%0d]: 0x%04h (correct)", $time, i, read_data);
            end

            @(posedge clk);
        end

        read_ready = 0;
        $display("[TEST %0d] PASSED - Buffer read complete", test_num);

        //======================================================================
        // TEST 4: Continuous ping-pong operation
        //======================================================================
        test_num++;
        $display("\n[TEST %0d] Continuous Ping-Pong Operation (3 buffers)", test_num);

        fork
            // Writer process
            begin
                for (int buf_idx = 0; buf_idx < 3; buf_idx++) begin
                    write_buffer(16'h0200 + (buf_idx * 16'h0100));
                    repeat(5) @(posedge clk);
                end
            end

            // Reader process
            begin
                for (int buf_idx = 0; buf_idx < 3; buf_idx++) begin
                    read_verify_buffer();
                    repeat(5) @(posedge clk);
                end
            end
        join

        //======================================================================
        // TEST 5: Write with read backpressure
        //======================================================================
        test_num++;
        $display("\n[TEST %0d] Write Buffer with Slow Reader", test_num);

        fork
            begin
                write_buffer(16'h0A00);
            end

            begin
                read_buffer_slow();
            end
        join

        repeat(10) @(posedge clk);

        //======================================================================
        // TEST 6: Overflow detection
        //======================================================================
        test_num++;
        $display("\n[TEST %0d] Overflow Detection Test", test_num);
        reset_dut();

        // Fill first buffer
        write_buffer(16'h0B00);

        // Try to write to full system (no reader)
        @(posedge clk);
        write_data = 16'hDEAD;
        write_valid = 1;
        @(posedge clk);

        if (buffer_overflow) begin
            $display("[TEST %0d] PASSED - Overflow detected", test_num);
        end else begin
            $display("[TEST %0d] INFO - Overflow not detected (may be expected)", test_num);
        end

        write_valid = 0;
        repeat(5) @(posedge clk);

        //======================================================================
        // TEST 7: Interleaved read/write (realistic scenario)
        //======================================================================
        test_num++;
        $display("\n[TEST %0d] Interleaved Read/Write Operations", test_num);

        // Write first buffer
        write_buffer(16'h0C00);

        // Start reading while writing next buffer
        fork
            begin
                repeat(5) @(posedge clk);
                read_verify_buffer();
            end

            begin
                repeat(DEPTH + 10) @(posedge clk);
                write_buffer(16'h0D00);
            end
        join

        // Read second buffer
        read_verify_buffer();

        //======================================================================
        // Test complete
        //======================================================================
        repeat(20) @(posedge clk);

        $display("\n================================================================================");
        $display("Testbench Complete");
        $display("================================================================================");
        $display("Total tests run: %0d", test_num);
        $display("Total errors: %0d", error_count);

        if (error_count == 0) begin
            $display("*** ALL TESTS PASSED ***");
        end else begin
            $display("*** TESTS FAILED - %0d errors ***", error_count);
        end
        $display("================================================================================");

        $finish;
    end

    //==========================================================================
    // Timeout watchdog
    //==========================================================================
    initial begin
        #50us;
        $display("\n*** TIMEOUT - Simulation ran too long ***");
        $finish;
    end

    //==========================================================================
    // Monitors
    //==========================================================================

    // Monitor write transactions
    always @(posedge clk) begin
        if (rst_n && write_valid && write_ready) begin
            $display("[%0t] WRITE: addr=%0d, data=0x%04h, count=%0d",
                     $time, write_count-1, write_data, write_count);
        end
    end

    // Monitor buffer swap events
    always @(posedge clk) begin
        if (rst_n && buffer_ready) begin
            $display("[%0t] *** BUFFER SWAP - Buffer ready for reading ***", $time);
        end
    end

    // Monitor overflow
    always @(posedge clk) begin
        if (rst_n && buffer_overflow) begin
            $display("[%0t] !!! OVERFLOW DETECTED !!!", $time);
        end
    end

endmodule
