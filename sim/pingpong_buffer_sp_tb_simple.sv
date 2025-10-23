// Simplified testbench for Ping-Pong Buffer SP
// Tests basic write/read with proper timing

`timescale 1ns / 1ps

module pingpong_buffer_sp_tb_simple;

    localparam int SAMPLE_W = 16;
    localparam int BUF_LEN  = 256;

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

    // DUT
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

    // Clock generation
    initial begin
        clk = 0;
        forever #18.5 clk = ~clk;  // 27 MHz
    end

    // Test
    int errors = 0;
    int words_written = 0;
    int words_read = 0;
    logic [15:0] expected_data;

    initial begin
        $dumpfile("pingpong_buffer_sp_tb_simple.vcd");
        $dumpvars(0, pingpong_buffer_sp_tb_simple);

        $display("===================================");
        $display("Ping-Pong Buffer Simple Test");
        $display("===================================\n");

        // Reset
        rst_n = 0;
        wr_valid = 0;
        wr_data = 0;
        sample_ready = 1;  // Tie high
        frame_start = 0;
        rd_ready = 0;
        buf_take = 0;

        repeat(5) @(posedge clk);
        rst_n = 1;
        @(posedge clk);

        $display("[%0t] Reset complete\n", $time);

        // Write 256 samples
        $display("[%0t] Writing 256 samples...", $time);
        for (int i = 0; i < BUF_LEN; i++) begin
            @(posedge clk);
            wr_valid = 1;
            wr_data = 16'h1000 + i;
            if (!wr_ready) begin
                $display("ERROR: wr_ready low during write!");
                errors++;
            end
            words_written++;
        end
        wr_valid = 0;
        $display("[%0t] Write complete: %0d words\n", $time, words_written);

        // Wait for buf_ready
        @(posedge clk);
        if (!buf_ready) begin
            $display("ERROR: buf_ready not asserted after 256 writes!");
            errors++;
        end else begin
            $display("[%0t] buf_ready asserted, buf_id=%0d\n", $time, buf_id);
        end

        // Take buffer
        @(posedge clk);
        buf_take = 1;
        @(posedge clk);
        buf_take = 0;
        $display("[%0t] Buffer taken\n", $time);

        // Read 256 samples
        $display("[%0t] Reading 256 samples...", $time);
        rd_ready = 1;
        for (int i = 0; i < BUF_LEN; i++) begin
            @(posedge clk);

            // Wait for valid (should be immediate)
            if (!rd_valid) begin
                $display("ERROR: rd_valid not asserted for word %0d!", i);
                errors++;
                // Wait for it
                while (!rd_valid) @(posedge clk);
            end

            // On the last word, check rd_last
            if (i == BUF_LEN-1) begin
                if (!rd_last) begin
                    $display("ERROR: rd_last not asserted on final word!");
                    errors++;
                end else begin
                    $display("[%0t] rd_last asserted correctly on word %0d", $time, i);
                end
            end

            // Check data (note: data reflects current address before increment)
            expected_data = 16'h1000 + i;
            if (rd_data !== expected_data) begin
                $display("ERROR: Word %0d mismatch! Expected 0x%04h, got 0x%04h",
                         i, expected_data, rd_data);
                errors++;
            end

            words_read++;
        end
        rd_ready = 0;
        $display("[%0t] Read complete: %0d words\n", $time, words_read);

        // Check that rd_valid went low
        @(posedge clk);
        if (rd_valid) begin
            $display("ERROR: rd_valid still high after read complete!");
            errors++;
        end

        // Summary
        repeat(10) @(posedge clk);
        $display("\n===================================");
        $display("Test Summary");
        $display("===================================");
        $display("Words written: %0d", words_written);
        $display("Words read:    %0d", words_read);
        $display("Errors:        %0d", errors);

        if (errors == 0) begin
            $display("\n*** ALL TESTS PASSED ***\n");
        end else begin
            $display("\n*** TESTS FAILED ***\n");
        end

        $finish;
    end

    // Timeout
    initial begin
        #10ms;
        $display("\n*** TIMEOUT ***");
        $finish;
    end

endmodule
