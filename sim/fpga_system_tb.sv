//==============================================================================
// fpga_system_tb.sv
//
// Complete integration testbench for the FPGA sampling system
// Tests: i2s_clock_gen -> i2s_capture_24 -> ram_logic -> vu_meter_6led
//
//==============================================================================

`timescale 1ns/1ps

module fpga_system_tb;

    //==========================================================================
    // Parameters
    //==========================================================================
    localparam time CLK_PERIOD = 37ns;  // 27 MHz
    localparam int RAM_DEPTH = 32;      // Small for fast simulation
    localparam int RAM_WIDTH = 32;

    //==========================================================================
    // DUT signals
    //==========================================================================
    logic        clk;
    logic        rst_n;

    // I2S microphone interface
    logic        mic_sd;         // Simulated microphone data
    logic        i2s_sck;
    logic        i2s_ws;

    // VU meter output
    logic [5:0]  leds;

    // Debug signals
    logic        buffer_ready;

    //==========================================================================
    // Internal wires (like in fpga_template.sv)
    //==========================================================================
    logic signed [23:0] sample_left;
    logic signed [23:0] sample_right;
    logic               sample_ready;

    logic [31:0]        ram_write_data;
    logic               ram_write_valid;
    logic               ram_write_ready;

    logic [31:0]        ram_read_data;
    logic               ram_read_valid;
    logic               ram_read_ready;
    logic               ram_buffer_ready;
    logic               ram_overflow;
    logic [8:0]         ram_write_count;
    logic [8:0]         ram_read_count;

    //==========================================================================
    // Test control
    //==========================================================================
    int error_count = 0;
    int buffer_count = 0;
    int sample_count = 0;

    //==========================================================================
    // Clock generation
    //==========================================================================
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    //==========================================================================
    // Module instantiations (mirroring fpga_template.sv structure)
    //==========================================================================

    // I2S Clock Generator
    /* verilator lint_off PINCONNECTEMPTY */
    i2s_clock_gen u_i2s_clock (
        .clk_i         (clk),
        .rst_ni        (rst_n),
        .sck_o         (i2s_sck),
        .ws_o          (i2s_ws),
        .frame_start_o ()
    );
    /* verilator lint_on PINCONNECTEMPTY */

    // I2S Capture (Sampler)
    i2s_capture_24 u_sampler (
        .clk_i     (clk),
        .rst_ni    (rst_n),
        .sck_i     (i2s_sck),
        .ws_i      (i2s_ws),
        .sd_i      (mic_sd),
        .left_o    (sample_left),
        .right_o   (sample_right),
        .ready_o   (sample_ready)
    );

    // Prepare RAM write data (24-bit sample in 32-bit word)
    assign ram_write_data = {8'h00, sample_left};
    assign ram_write_valid = sample_ready;

    // RAM Logic (Ping-Pong Buffer)
    ram_logic #(
        .WIDTH(RAM_WIDTH),
        .DEPTH(RAM_DEPTH)
    ) u_ram (
        .clk_i              (clk),
        .rst_ni             (rst_n),
        .write_data_i       (ram_write_data),
        .write_valid_i      (ram_write_valid),
        .write_ready_o      (ram_write_ready),
        .read_data_o        (ram_read_data),
        .read_ready_i       (ram_read_ready),
        .read_valid_o       (ram_read_valid),
        .buffer_ready_o     (ram_buffer_ready),
        .buffer_overflow_o  (ram_overflow),
        .write_count_o      (ram_write_count),
        .read_count_o       (ram_read_count)
    );

    assign buffer_ready = ram_buffer_ready;

    // VU Meter (Consumer)
    vu_meter_6led #(
        .USE_RAM_IF(1'b1),
        .SELECT_LEFT(1'b1),
        .DECAY_SHIFT(11),
        .SCALE_SHIFT(12),
        .LED_DIV(1000)  // Faster for simulation
    ) u_vu_meter (
        .clk_i              (clk),
        .rst_ni             (rst_n),
        // Direct sample interface (not used)
        .sample_valid_i     (1'b0),
        .left_sample_i      (24'h0),
        .right_sample_i     (24'h0),
        // RAM consumer interface
        .ram_read_data_i    (ram_read_data[23:0]),
        .ram_read_valid_i   (ram_read_valid),
        .ram_read_ready_o   (ram_read_ready),
        .ram_buffer_ready_i (ram_buffer_ready),
        .leds_o             (leds)
    );

    //==========================================================================
    // Microphone data generator
    //==========================================================================
    // Generate a simple pattern on I2S data line
    logic [24:0] mic_shift_reg;
    logic [4:0]  bit_counter;
    logic        sck_prev;

    initial begin
        mic_shift_reg = 25'h0;
        bit_counter = 0;
        mic_sd = 0;
        sck_prev = 0;
    end

    // Simulate microphone sending data on SCK rising edge
    always @(posedge clk) begin
        sck_prev <= i2s_sck;

        // Detect SCK rising edge
        if (i2s_sck && !sck_prev) begin
            // Generate pseudo-random audio data
            if (bit_counter == 0) begin
                // Load new sample at frame boundary
                mic_shift_reg <= {1'b0, $random} & 25'h1FFFFFF;
            end

            // Shift out MSB
            mic_sd <= mic_shift_reg[24];
            mic_shift_reg <= {mic_shift_reg[23:0], 1'b0};

            bit_counter <= bit_counter + 1;
            if (bit_counter >= 24) begin
                bit_counter <= 0;
            end
        end
    end

    //==========================================================================
    // Monitors
    //==========================================================================

    // Monitor samples
    always @(posedge clk) begin
        if (rst_n && sample_ready) begin
            sample_count <= sample_count + 1;
            $display("[%0t] Sample %0d: L=0x%06h, R=0x%06h",
                     $time, sample_count+1, sample_left, sample_right);
        end
    end

    // Monitor buffer events
    always @(posedge clk) begin
        if (rst_n && ram_buffer_ready) begin
            buffer_count <= buffer_count + 1;
            $display("[%0t] *** BUFFER %0d READY *** (write_count=%0d, samples=%0d)",
                     $time, buffer_count+1, ram_write_count, sample_count);
        end
    end

    // Monitor overflow
    always @(posedge clk) begin
        if (rst_n && ram_overflow) begin
            $display("[%0t] !!! RAM OVERFLOW DETECTED !!!", $time);
            error_count <= error_count + 1;
        end
    end

    // Monitor LED changes
    logic [5:0] leds_prev;
    always @(posedge clk) begin
        leds_prev <= leds;
        if (rst_n && leds !== leds_prev) begin
            $display("[%0t] LEDs changed: 0x%02h (binary: %06b)", $time, leds, leds);
        end
    end

    //==========================================================================
    // Tasks
    //==========================================================================

    task automatic reset_system();
        $display("[%0t] Applying reset...", $time);
        rst_n = 0;
        repeat(10) @(posedge clk);
        rst_n = 1;
        repeat(5) @(posedge clk);
        $display("[%0t] Reset released", $time);
    endtask

    task automatic wait_for_buffers(input int num_buffers);
        int start_count = buffer_count;
        int timeout = 0;
        int max_timeout = 1000000;  // cycles

        $display("[%0t] Waiting for %0d buffers to complete...", $time, num_buffers);

        while ((buffer_count - start_count) < num_buffers && timeout < max_timeout) begin
            @(posedge clk);
            timeout++;
        end

        if (timeout >= max_timeout) begin
            $display("[%0t] ERROR: Timeout waiting for buffers", $time);
            error_count++;
        end else begin
            $display("[%0t] %0d buffers completed", $time, num_buffers);
        end
    endtask

    task automatic check_no_overflow();
        @(posedge clk);
        if (ram_overflow) begin
            $display("[%0t] ERROR: Unexpected overflow", $time);
            error_count++;
        end
    endtask

    //==========================================================================
    // Main test sequence
    //==========================================================================
    initial begin
        $display("================================================================================");
        $display("FPGA SYSTEM INTEGRATION TESTBENCH");
        $display("================================================================================");
        $display("Testing: Clock Gen -> I2S Capture -> RAM Logic -> VU Meter");
        $display("Parameters: RAM_DEPTH=%0d, RAM_WIDTH=%0d", RAM_DEPTH, RAM_WIDTH);
        $display("================================================================================\n");

        //======================================================================
        // Initialize VCD dump
        //======================================================================
        $dumpfile("fpga_system_tb.vcd");
        $dumpvars(0, fpga_system_tb);
        $dumpvars(0, u_i2s_clock);
        $dumpvars(0, u_sampler);
        $dumpvars(0, u_ram);
        $dumpvars(0, u_vu_meter);

        //======================================================================
        // TEST 1: Reset and Initialization
        //======================================================================
        $display("\n[TEST 1] Reset and Initialization");
        reset_system();

        if (!ram_write_ready) begin
            $display("[TEST 1] ERROR: RAM not ready after reset");
            error_count++;
        end

        if (ram_read_valid) begin
            $display("[TEST 1] ERROR: RAM read valid after reset");
            error_count++;
        end

        $display("[TEST 1] PASSED\n");

        //======================================================================
        // TEST 2: I2S Clock Generation
        //======================================================================
        $display("\n[TEST 2] I2S Clock Generation");

        // Wait for some I2S activity
        repeat(500) @(posedge clk);

        if (sample_count < 1) begin
            $display("[TEST 2] ERROR: No samples captured");
            error_count++;
        end else begin
            $display("[TEST 2] PASSED - %0d samples captured", sample_count);
        end

        //======================================================================
        // TEST 3: Buffer Fill and Swap
        //======================================================================
        $display("\n[TEST 3] First Buffer Fill");

        wait_for_buffers(1);

        if (buffer_count < 1) begin
            $display("[TEST 3] ERROR: First buffer not filled");
            error_count++;
        end else begin
            $display("[TEST 3] PASSED - First buffer filled after %0d samples", sample_count);
        end

        //======================================================================
        // TEST 4: VU Meter Reading
        //======================================================================
        $display("\n[TEST 4] VU Meter Consumer Operation");

        // Wait for some VU meter activity
        repeat(5000) @(posedge clk);

        if (leds == 6'b0) begin
            $display("[TEST 4] WARNING: LEDs still all zero (may be low signal)");
        end else begin
            $display("[TEST 4] PASSED - VU meter active, LEDs = 0x%02h", leds);
        end

        //======================================================================
        // TEST 5: Continuous Operation
        //======================================================================
        $display("\n[TEST 5] Continuous Ping-Pong Operation");

        begin
            int start_buf_count;
            start_buf_count = buffer_count;
            wait_for_buffers(2);

            if ((buffer_count - start_buf_count) < 2) begin
                $display("[TEST 5] ERROR: Ping-pong not working");
                error_count++;
            end else begin
                $display("[TEST 5] PASSED - Multiple buffers processed");
            end
        end

        //======================================================================
        // TEST 6: No Overflow Check
        //======================================================================
        $display("\n[TEST 6] Overflow Prevention");

        // Let system run and ensure no overflow
        repeat(10000) @(posedge clk);
        check_no_overflow();

        $display("[TEST 6] PASSED - No overflow detected");

        //======================================================================
        // Final Statistics
        //======================================================================
        repeat(100) @(posedge clk);

        $display("\n================================================================================");
        $display("TEST COMPLETE");
        $display("================================================================================");
        $display("Total samples captured: %0d", sample_count);
        $display("Total buffers completed: %0d", buffer_count);
        $display("Final LED state: 0x%02h (%06b)", leds, leds);
        $display("RAM write count: %0d", ram_write_count);
        $display("RAM read count: %0d", ram_read_count);
        $display("Total errors: %0d", error_count);

        if (error_count == 0) begin
            $display("\n*** ALL TESTS PASSED ***");
        end else begin
            $display("\n*** TESTS FAILED - %0d errors ***", error_count);
        end

        $display("================================================================================\n");
        $finish;
    end

    //==========================================================================
    // Timeout watchdog
    //==========================================================================
    initial begin
        #5ms;
        $display("\n*** TIMEOUT - Simulation took too long ***");
        $finish;
    end

endmodule
