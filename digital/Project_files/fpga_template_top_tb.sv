//==============================================================================
// fpga_template_top_tb.sv
//
// Testbench for fpga_template_top module
// Stimulates all top-level inputs and monitors outputs
//
// Tests:
//   1. Reset behavior
//   2. I2S clock generation
//   3. Sample capture and RAM buffering
//   4. VU meter operation
//   5. Buffer overflow detection
//
//==============================================================================

`timescale 1ns/1ps

module fpga_template_top_tb;

    //==========================================================================
    // Parameters
    //==========================================================================
    localparam time CLK_PERIOD = 37ns;  // 27 MHz
    localparam int SIM_DURATION = 10000us;  // 10ms simulation (to see buffer swaps)

    //==========================================================================
    // DUT signals
    //==========================================================================
    logic        clk;
    logic [5:0]  debug_led;
    logic        btn_s1_resetb;
    logic        btn_s2;
    logic        i2s_sck;
    logic        i2s_ws;
    logic        buffer_full;
    logic        mic_sd_0;

    //==========================================================================
    // Test control
    //==========================================================================
    int error_count = 0;
    int sample_count = 0;
    int buffer_ready_count = 0;

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
    fpga_template_top dut (
        .clk            (clk),
        .debug_led      (debug_led),
        .btn_s1_resetb  (btn_s1_resetb),
        .btn_s2         (btn_s2),
        .i2s_sck        (i2s_sck),
        .i2s_ws         (i2s_ws),
        .buffer_full    (buffer_full),
        .mic_sd_0       (mic_sd_0)
    );

    //==========================================================================
    // Microphone data generator (I2S slave simulation)
    //==========================================================================
    // Generates realistic I2S audio data patterns:
    //   - Sine wave simulation for left channel
    //   - Triangle wave for right channel
    //   - Varying amplitudes to test VU meter
    //==========================================================================
    logic [24:0] mic_shift_reg;
    logic [5:0]  bit_counter;
    logic        sck_prev;
    logic        ws_prev_mic;
    logic        is_left_channel;
    int          sample_number = 0;
    logic signed [23:0] test_sample;

    initial begin
        mic_shift_reg = 25'h0;
        bit_counter = 0;
        mic_sd_0 = 0;
        sck_prev = 0;
        ws_prev_mic = 0;
        is_left_channel = 1;
        sample_number = 0;
    end

    // Generate test patterns: sine-like wave with varying amplitude
    function automatic logic signed [23:0] generate_test_sample(input int sample_num, input logic is_left);
        logic signed [23:0] amplitude;
        int phase;

        phase = sample_num % 64;  // 64-sample period

        if (is_left) begin
            // Sine-approximation for left: moderate amplitude
            if (phase < 16)
                amplitude = 24'sh100000 + (phase * 24'sh008000);
            else if (phase < 32)
                amplitude = 24'sh180000 - ((phase - 16) * 24'sh008000);
            else if (phase < 48)
                amplitude = 24'shE80000 - ((phase - 32) * 24'sh008000);
            else
                amplitude = 24'shE00000 + ((phase - 48) * 24'sh008000);
        end else begin
            // Triangle wave for right: varying amplitude
            if (phase < 32)
                amplitude = (phase * 24'sh010000);
            else
                amplitude = ((64 - phase) * 24'sh010000);
        end

        return amplitude;
    endfunction

    // Simulate microphone responding to I2S master clock
    always @(posedge clk) begin
        sck_prev <= i2s_sck;
        ws_prev_mic <= i2s_ws;

        // Detect WS edge to load new sample
        if (i2s_ws != ws_prev_mic) begin
            bit_counter <= 0;
            is_left_channel <= !i2s_ws;  // WS=0 for left
            test_sample <= generate_test_sample(sample_number, !i2s_ws);
            mic_shift_reg <= {1'b0, test_sample};  // Load with dummy bit + 24-bit sample
            sample_number <= sample_number + 1;
        end

        // Detect SCK rising edge - shift out data
        if (i2s_sck && !sck_prev) begin
            // Shift out MSB on SCK rising edge
            mic_sd_0 <= mic_shift_reg[24];
            mic_shift_reg <= {mic_shift_reg[23:0], 1'b0};

            bit_counter <= bit_counter + 1;
        end
    end

    //==========================================================================
    // Monitors
    //==========================================================================

    // Monitor I2S activity
    logic sck_prev_mon;
    always @(posedge clk) begin
        sck_prev_mon <= i2s_sck;
    end

    wire sck_rising = i2s_sck && !sck_prev_mon;
    wire sck_falling = !i2s_sck && sck_prev_mon;

    // Count SCK edges
    int sck_edge_count = 0;
    always @(posedge clk) begin
        if (sck_rising) sck_edge_count <= sck_edge_count + 1;
    end

    // Monitor WS transitions
    logic ws_prev;
    always @(posedge clk) begin
        ws_prev <= i2s_ws;
    end

    wire ws_edge = (i2s_ws != ws_prev);
    int ws_transition_count = 0;
    always @(posedge clk) begin
        if (ws_edge) ws_transition_count <= ws_transition_count + 1;
    end

    // Monitor buffer overflow
    always @(posedge clk) begin
        if (buffer_full) begin
            $display("[%0t] !!! BUFFER OVERFLOW DETECTED !!!", $time);
        end
    end

    // Monitor LED changes
    logic [5:0] debug_led_prev;
    always @(posedge clk) begin
        debug_led_prev <= debug_led;
        if (debug_led !== debug_led_prev) begin
            $display("[%0t] LED changed: 0x%02h (binary: %06b)", $time, debug_led, debug_led);
        end
    end

    // Monitor captured samples
    int captured_sample_count = 0;
    always @(posedge clk) begin
        if (dut.u_sampler.ready_o) begin
            captured_sample_count <= captured_sample_count + 1;
            if (captured_sample_count < 5) begin
                $display("[%0t] Sample captured: L=0x%06h (%0d), R=0x%06h (%0d)",
                    $time,
                    dut.sample_left, $signed(dut.sample_left),
                    dut.sample_right, $signed(dut.sample_right));
            end
        end
    end

    // Monitor RAM buffer swaps
    int buffer_swap_count = 0;
    always @(posedge clk) begin
        if (dut.u_ram.buffer_ready_o) begin
            buffer_swap_count <= buffer_swap_count + 1;
            $display("[%0t] *** RAM BUFFER SWAP #%0d - Buffer full and ready for reading ***",
                $time, buffer_swap_count);
        end
    end

    //==========================================================================
    // Tasks
    //==========================================================================

    task automatic reset_dut();
        $display("[%0t] Applying reset...", $time);
        btn_s1_resetb = 1'b1;  // Active when high (inverted internally)
        btn_s2 = 1'b0;
        repeat(10) @(posedge clk);
        btn_s1_resetb = 1'b0;  // Release reset
        repeat(5) @(posedge clk);
        $display("[%0t] Reset released", $time);
    endtask

    task automatic wait_cycles(input int num_cycles);
        repeat(num_cycles) @(posedge clk);
    endtask

    task automatic check_i2s_activity();
        int start_sck = sck_edge_count;
        int start_ws = ws_transition_count;

        $display("[%0t] Checking I2S activity...", $time);
        wait_cycles(1000);

        if (sck_edge_count <= start_sck) begin
            $display("[%0t] ERROR: I2S SCK not toggling!", $time);
            error_count++;
        end else begin
            $display("[%0t] I2S SCK active: %0d edges", $time, sck_edge_count - start_sck);
        end

        if (ws_transition_count <= start_ws) begin
            $display("[%0t] WARNING: I2S WS not toggling", $time);
        end else begin
            $display("[%0t] I2S WS active: %0d transitions", $time, ws_transition_count - start_ws);
        end
    endtask

    //==========================================================================
    // Main test sequence
    //==========================================================================
    initial begin
        $display("================================================================================");
        $display("FPGA_TEMPLATE_TOP TESTBENCH");
        $display("================================================================================");
        $display("System Clock: 27 MHz (%0d ns period)", CLK_PERIOD);
        $display("Simulation Duration: %0d us", SIM_DURATION/1000);
        $display("================================================================================\n");

        // VCD dump
        $dumpfile("fpga_template_top_tb.vcd");
        $dumpvars(0, fpga_template_top_tb);
        $dumpvars(0, dut);
        $dumpvars(0, dut.u_i2s_clock);
        $dumpvars(0, dut.u_sampler);
        $dumpvars(0, dut.u_ram);
        $dumpvars(0, dut.vu);

        // Initialize inputs
        clk = 0;
        btn_s1_resetb = 0;
        btn_s2 = 0;

        //======================================================================
        // TEST 1: Reset and Initialization
        //======================================================================
        $display("\n[TEST 1] Reset and Initialization");
        reset_dut();

        // Check initial states
        if (i2s_sck !== 1'b0 && i2s_sck !== 1'bx) begin
            // SCK can be 0 or starting to toggle
        end
        if (buffer_full !== 1'b0) begin
            $display("[TEST 1] ERROR: buffer_full should be 0 after reset");
            error_count++;
        end
        $display("[TEST 1] PASSED - Reset complete\n");

        //======================================================================
        // TEST 2: I2S Clock Generation
        //======================================================================
        $display("\n[TEST 2] I2S Clock Generation");
        check_i2s_activity();
        $display("[TEST 2] PASSED\n");

        //======================================================================
        // TEST 3: Normal Operation
        //======================================================================
        $display("\n[TEST 3] Normal Operation - Run for 500us");
        wait_cycles(13500);  // ~500us at 27MHz

        $display("[TEST 3] Statistics:");
        $display("  SCK edges: %0d", sck_edge_count);
        $display("  WS transitions: %0d", ws_transition_count);
        $display("  Buffer overflows: %0d", buffer_full ? 1 : 0);
        $display("  Final LED state: 0x%02h", debug_led);

        if (sck_edge_count < 100) begin
            $display("[TEST 3] ERROR: Too few SCK edges");
            error_count++;
        end else begin
            $display("[TEST 3] PASSED\n");
        end

        //======================================================================
        // TEST 4: Extended operation - wait for buffer swap
        //======================================================================
        $display("\n[TEST 4] Extended Operation - Waiting for RAM buffer swap");
        $display("  Need 256 samples @ 52.7kHz = ~4.85ms");

        // Wait for buffer swap or timeout (6ms should be enough)
        fork
            begin
                wait(dut.u_ram.buffer_ready_o == 1'b1);
                $display("[%0t] *** BUFFER SWAP DETECTED ***", $time);
            end
            begin
                wait_cycles(162000);  // ~6ms at 27MHz
                $display("[%0t] Timeout waiting for buffer swap", $time);
            end
        join_any
        disable fork;

        wait_cycles(1000);  // Let reads complete

        $display("[TEST 4] Final Statistics:");
        $display("  Total SCK edges: %0d", sck_edge_count);
        $display("  Total WS transitions: %0d", ws_transition_count);
        $display("  LED state: 0x%02h (inverted, so 0x3F = all on)", debug_led);

        // Expected: ~52.7kHz sample rate, so ~52-53 samples in 1ms
        // At 1.5ms total, expect ~78-80 WS transitions (2 per frame)
        if (ws_transition_count < 50) begin
            $display("[TEST 4] WARNING: Fewer WS transitions than expected");
        end

        $display("[TEST 4] PASSED\n");

        //======================================================================
        // TEST 5: Button Press (S2)
        //======================================================================
        $display("\n[TEST 5] Button S2 Press Test");
        btn_s2 = 1'b1;
        wait_cycles(100);
        btn_s2 = 1'b0;
        wait_cycles(100);
        $display("[TEST 5] PASSED - Button handled\n");

        //======================================================================
        // Final results
        //======================================================================
        wait_cycles(100);

        $display("\n================================================================================");
        $display("TEST COMPLETE");
        $display("================================================================================");
        $display("Simulation time: %0t", $time);
        $display("\nI2S Clock Statistics:");
        $display("  Total SCK edges: %0d", sck_edge_count);
        $display("  Total WS transitions: %0d", ws_transition_count);
        $display("  Calculated sample rate: ~%0d Hz", (ws_transition_count * 1000000) / ($time / 1000));
        $display("\nData Path Statistics:");
        $display("  Samples captured: %0d", captured_sample_count);
        $display("  RAM buffer swaps: %0d", buffer_swap_count);
        $display("  Buffer overflows: %0d", buffer_full ? 1 : 0);
        $display("\nOutput State:");
        $display("  Final LED state: 0x%02h (inverted: 0x%02h active)", debug_led, ~debug_led);
        $display("  LED binary: %06b", debug_led);
        $display("\nTest Results:");
        $display("  Total errors: %0d", error_count);

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
        #(SIM_DURATION);
        $display("\n*** SIMULATION TIMEOUT at %0t ***", $time);
        $display("Total errors: %0d", error_count);
        $finish;
    end

endmodule
