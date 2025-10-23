// =============================================================================
// sp_ram_simple_tb.sv
// Simple testbench for pingpong RAM - Verilator compatible
// =============================================================================

`timescale 1ns/1ps

module sp_ram_simple_tb;

    // Clock and reset
    logic clk;
    logic rst_n;

    // RAM signals
    logic [15:0] sample_in;
    logic sample_ready;
    logic [15:0] read_data;
    logic buffer_ready;

    // Test signals
    integer sample_count;
    integer cycle_count;

    // Clock generation - 27 MHz
    initial begin
        clk = 0;
        forever #18.518 clk = ~clk; // ~27 MHz
    end

    // DUT - Device Under Test
    pingpong_sp_ram #(
        .WIDTH(16),
        .DEPTH(10)  // Small depth for faster testing
    ) dut (
        .clk_i          (clk),
        .rst_ni         (rst_n),
        .sample_i       (sample_in),
        .sample_ready_i (sample_ready),
        .read_data_o    (read_data),
        .buffer_ready_o (buffer_ready)
    );

    // Test stimulus
    initial begin
        // VCD dump for waveform viewing
        $dumpfile("sp_ram_simple_tb.vcd");
        $dumpvars(0, sp_ram_simple_tb);

        // Initialize signals
        rst_n = 0;
        sample_in = 16'h0000;
        sample_ready = 0;
        sample_count = 0;
        cycle_count = 0;

        // Reset sequence
        repeat(5) @(posedge clk);
        rst_n = 1;
        $display("[%0t] Reset released", $time);

        // Wait a bit after reset
        repeat(3) @(posedge clk);

        // Generate samples - write 3 full buffers (3 × 10 = 30 samples)
        for (int buffer = 0; buffer < 3; buffer++) begin
            $display("[%0t] Starting buffer %0d", $time, buffer);

            for (int i = 0; i < 10; i++) begin
                @(posedge clk);
                sample_in = 16'hA000 + (buffer * 256) + i; // Unique pattern
                sample_ready = 1;
                sample_count++;

                // Check if buffer became ready
                if (buffer_ready) begin
                    cycle_count++;
                    $display("[%0t] === BUFFER %0d READY === read_data=%04h",
                             $time, cycle_count, read_data);
                end
            end

            @(posedge clk);
            sample_ready = 0;

            // Small gap between buffers
            repeat(2) @(posedge clk);
        end

        // Continue reading for a few more cycles
        repeat(15) begin
            @(posedge clk);
            sample_ready = 1;
            sample_in = sample_in + 1;
        end

        // Final status
        repeat(5) @(posedge clk);
        $display("\n=== Test Complete ===");
        $display("Total samples: %0d", sample_count);
        $display("Buffer ready count: %0d", cycle_count);
        $display("Final read_data: %04h", read_data);

        if (cycle_count >= 2 && read_data != 16'h0000) begin
            $display("=== TEST PASSED ===");
        end else begin
            $display("=== TEST FAILED ===");
        end

        $finish;
    end

    // Monitor buffer_ready pulses
    always @(posedge clk) begin
        if (buffer_ready) begin
            $display("[%0t] buffer_ready pulse detected, read_data=%04h",
                     $time, read_data);
        end
    end

    // Monitor read_data changes
    logic [15:0] read_data_prev;
    always @(posedge clk) begin
        read_data_prev <= read_data;
        if (read_data !== read_data_prev && read_data !== 16'h0000) begin
            $display("[%0t] read_data changed: %04h -> %04h",
                     $time, read_data_prev, read_data);
        end
    end

    // Timeout watchdog
    initial begin
        #50000; // 50us timeout
        $display("ERROR: Simulation timeout!");
        $finish;
    end

endmodule
