// Testbench for Ping-Pong Buffer SP
// Tests write/read handshaking, buffer swapping, backpressure, and error conditions

`timescale 1ns / 1ps

module pingpong_buffer_sp_tb;

    // Parameters matching DUT
    localparam int SAMPLE_W = 16;
    localparam int BUF_LEN  = 256;
    localparam int HALF_BUF = BUF_LEN / 2;

    // Clock and reset
    logic clk;
    logic rst_n;

    // Write interface
    logic [SAMPLE_W-1:0] wr_data;
    logic                wr_valid;
    logic                wr_ready;
    logic                sample_ready;
    logic                frame_start;

    // Read interface
    logic [SAMPLE_W-1:0] rd_data;
    logic                rd_valid;
    logic                rd_ready;
    logic                rd_last;

    // Buffer control
    logic                buf_ready;
    logic                buf_id;
    logic                buf_take;
    logic                buf_empty;
    logic                overrun;
    logic                underrun;

    // Test control
    int write_count = 0;
    int read_count = 0;
    int block_count = 0;
    int error_count = 0;

    // DUT instantiation
    pingpong_buffer_sp #(
        .SAMPLE_W(SAMPLE_W),
        .BUF_LEN(BUF_LEN)
    ) dut (
        .clk_i          (clk),
        .rst_ni         (rst_n),
        .wr_data_i      (wr_data),
        .wr_valid_i     (wr_valid),
        .wr_ready_o     (wr_ready),
        .sample_ready_i (sample_ready),
        .frame_start_i  (frame_start),
        .rd_data_o      (rd_data),
        .rd_valid_o     (rd_valid),
        .rd_ready_i     (rd_ready),
        .rd_last_o      (rd_last),
        .buf_ready_o    (buf_ready),
        .buf_id_o       (buf_id),
        .buf_take_i     (buf_take),
        .buf_empty_o    (buf_empty),
        .overrun_o      (overrun),
        .underrun_o     (underrun)
    );

    // Clock generation: 27 MHz (37 ns period)
    initial begin
        clk = 0;
        forever #18.5 clk = ~clk;
    end

    // =========================================================================
    // Test stimulus tasks
    // =========================================================================

    // Reset task
    task automatic reset_dut();
        $display("[%0t] Resetting DUT...", $time);
        rst_n = 0;
        wr_valid = 0;
        wr_data = 0;
        sample_ready = 1;  // Tie high for continuous operation
        frame_start = 0;
        rd_ready = 0;
        buf_take = 0;
        @(posedge clk);
        @(posedge clk);
        rst_n = 1;
        @(posedge clk);
        $display("[%0t] Reset complete", $time);
    endtask

    // Write a block of data (BUF_LEN samples)
    task automatic write_block(input int start_value, input bit with_backpressure = 0);
        int i;
        $display("[%0t] Writing block starting with value 0x%04h", $time, start_value);

        for (i = 0; i < BUF_LEN; i++) begin
            wr_data = 16'(start_value + i);
            wr_valid = 1;

            @(posedge clk);

            // Wait for ready
            while (!wr_ready) begin
                $display("[%0t] Write stalled - waiting for wr_ready", $time);
                @(posedge clk);
            end

            write_count++;

            // Optional: add backpressure (deassert valid randomly)
            if (with_backpressure && ($urandom() % 10 < 3)) begin
                wr_valid = 0;
                repeat($urandom() % 5 + 1) @(posedge clk);
            end
        end

        wr_valid = 0;
        $display("[%0t] Block write complete (%0d samples written)", $time, BUF_LEN);
    endtask

    // Read a block of data (BUF_LEN samples)
    task automatic read_block(input int expected_start, input bit with_backpressure = 0);
        int i;
        logic [SAMPLE_W-1:0] expected_val;

        $display("[%0t] Reading block expecting start value 0x%04h", $time, expected_start);

        for (i = 0; i < BUF_LEN; i++) begin
            rd_ready = 1;
            expected_val = 16'(expected_start + i);

            @(posedge clk);

            // Wait for valid
            while (!rd_valid) begin
                $display("[%0t] Read stalled - waiting for rd_valid", $time);
                @(posedge clk);
            end

            // Check data
            if (rd_data !== expected_val) begin
                $display("[%0t] ERROR: Read mismatch at sample %0d - Expected 0x%04h, Got 0x%04h",
                         $time, i, expected_val, rd_data);
                error_count++;
            end

            // Check rd_last on final word
            if (i == BUF_LEN-1 && !rd_last) begin
                $display("[%0t] ERROR: rd_last not asserted on final word", $time);
                error_count++;
            end else if (i < BUF_LEN-1 && rd_last) begin
                $display("[%0t] ERROR: rd_last asserted early at sample %0d", $time, i);
                error_count++;
            end

            read_count++;

            // Optional: add backpressure (deassert ready randomly)
            if (with_backpressure && ($urandom() % 10 < 3)) begin
                rd_ready = 0;
                repeat($urandom() % 5 + 1) @(posedge clk);
            end
        end

        rd_ready = 0;
        $display("[%0t] Block read complete (%0d samples read)", $time, BUF_LEN);
    endtask

    // Wait for buffer ready signal and take it
    task automatic wait_and_take_buffer();
        $display("[%0t] Waiting for buf_ready signal...", $time);

        @(posedge clk);
        while (!buf_ready) @(posedge clk);

        $display("[%0t] buf_ready asserted for buffer %0d", $time, buf_id);
        block_count++;

        // Take the buffer on next cycle
        @(posedge clk);
        buf_take = 1;
        @(posedge clk);
        buf_take = 0;

        $display("[%0t] Buffer taken, starting read", $time);
    endtask

    // =========================================================================
    // Test scenarios
    // =========================================================================

    initial begin
        $dumpfile("pingpong_buffer_sp_tb.vcd");
        $dumpvars(0, pingpong_buffer_sp_tb);

        $display("========================================");
        $display("Ping-Pong Buffer SP Testbench");
        $display("========================================");

        // Initialize
        reset_dut();

        // =====================================================================
        // TEST 1: Basic single block write/read
        // =====================================================================
        $display("\n=== TEST 1: Basic single block write/read ===");

        fork
            // Writer: write one block
            begin
                write_block(16'h1000, 0);
            end

            // Buffer manager: wait for ready and take
            begin
                wait_and_take_buffer();
            end

            // Reader: read one block
            begin
                @(buf_take);  // Wait for buffer to be taken
                @(posedge clk);
                read_block(16'h1000, 0);
            end
        join

        repeat(10) @(posedge clk);

        // =====================================================================
        // TEST 2: Ping-pong operation (two blocks)
        // =====================================================================
        $display("\n=== TEST 2: Ping-pong operation (two blocks) ===");

        fork
            // Writer: continuously write two blocks
            begin
                write_block(16'h2000, 0);
                write_block(16'h3000, 0);
            end

            // Buffer manager and reader
            begin
                // First block
                wait_and_take_buffer();
                read_block(16'h2000, 0);

                // Second block
                wait_and_take_buffer();
                read_block(16'h3000, 0);
            end
        join

        repeat(10) @(posedge clk);

        // =====================================================================
        // TEST 3: Write with backpressure on read side
        // =====================================================================
        $display("\n=== TEST 3: Write with backpressure on read side ===");

        fork
            // Writer: write block fast
            begin
                write_block(16'h4000, 0);
            end

            // Reader: read slow (with backpressure)
            begin
                wait_and_take_buffer();
                read_block(16'h4000, 1);  // Enable backpressure
            end
        join

        repeat(10) @(posedge clk);

        // =====================================================================
        // TEST 4: Overrun test (write faster than read, fill both buffers)
        // =====================================================================
        $display("\n=== TEST 4: Overrun test ===");

        fork
            // Writer: write two blocks back-to-back without reading
            begin
                write_block(16'h5000, 0);
                write_block(16'h6000, 0);

                // Try to write third block - should trigger overrun
                $display("[%0t] Attempting to write third block (should cause overrun)", $time);
                wr_data = 16'h7000;
                wr_valid = 1;
                repeat(10) @(posedge clk);

                if (overrun) begin
                    $display("[%0t] SUCCESS: Overrun detected as expected", $time);
                end else begin
                    $display("[%0t] ERROR: Overrun not detected!", $time);
                    error_count++;
                end

                wr_valid = 0;
            end

            // No reader - let buffers fill up
        join

        // Now drain the buffers
        wait_and_take_buffer();
        read_block(16'h5000, 0);
        wait_and_take_buffer();
        read_block(16'h6000, 0);

        repeat(10) @(posedge clk);

        // =====================================================================
        // TEST 5: Continuous operation (streaming)
        // =====================================================================
        $display("\n=== TEST 5: Continuous streaming operation (4 blocks) ===");

        fork
            // Writer: continuously write 4 blocks
            begin
                for (int b = 0; b < 4; b++) begin
                    write_block(16'h8000 + (b * 16'h400), 0);
                end
            end

            // Reader: continuously read 4 blocks
            begin
                for (int b = 0; b < 4; b++) begin
                    wait_and_take_buffer();
                    read_block(16'h8000 + (b * 16'h400), 0);
                end
            end
        join

        repeat(10) @(posedge clk);

        // =====================================================================
        // TEST 6: Backpressure on both sides
        // =====================================================================
        $display("\n=== TEST 6: Backpressure on both write and read sides ===");

        fork
            // Writer with backpressure
            begin
                write_block(16'hA000, 1);
            end

            // Reader with backpressure
            begin
                wait_and_take_buffer();
                read_block(16'hA000, 1);
            end
        join

        repeat(10) @(posedge clk);

        // =====================================================================
        // Test summary
        // =====================================================================
        $display("\n========================================");
        $display("Test Summary");
        $display("========================================");
        $display("Total samples written: %0d", write_count);
        $display("Total samples read:    %0d", read_count);
        $display("Total blocks completed: %0d", block_count);
        $display("Total errors:          %0d", error_count);

        if (error_count == 0) begin
            $display("\n*** ALL TESTS PASSED ***");
        end else begin
            $display("\n*** TESTS FAILED - %0d errors detected ***", error_count);
        end

        $display("========================================\n");

        repeat(20) @(posedge clk);
        $finish;
    end

    // Timeout watchdog
    initial begin
        #100ms;
        $display("\n*** TIMEOUT - Test did not complete ***");
        $finish;
    end

    // Monitor important signals
    logic overrun_prev, underrun_prev;
    initial begin
        overrun_prev = 0;
        underrun_prev = 0;
        forever begin
            @(posedge clk);
            if (buf_ready) begin
                $display("[%0t] MONITOR: Buffer %0d ready", $time, buf_id);
            end
            if (rd_last) begin
                $display("[%0t] MONITOR: Read block complete (rd_last asserted)", $time);
            end
            if (overrun && !overrun_prev) begin
                $display("[%0t] MONITOR: OVERRUN detected!", $time);
            end
            if (underrun && !underrun_prev) begin
                $display("[%0t] MONITOR: UNDERRUN detected!", $time);
            end
            overrun_prev = overrun;
            underrun_prev = underrun;
        end
    end

endmodule
