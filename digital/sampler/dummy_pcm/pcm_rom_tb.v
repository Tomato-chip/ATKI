// =============================================================================
// pcm_rom_tb.v
// Testbench for pcm_rom I²S microphone emulator with i2s_capture_24
// =============================================================================

`timescale 1ns/1ps

module pcm_rom_tb;

    // Clock and reset
    reg clk_27m;
    reg rst_n;

    // I²S signals
    wire sck;
    wire ws;
    wire sd;

    // Capture outputs
    wire signed [23:0] left_data;
    wire signed [23:0] right_data;
    wire ready;

    // 27 MHz clock generation
    initial clk_27m = 0;
    always #18.518 clk_27m = ~clk_27m;  // ~27 MHz (18.518ns period)

    // Reset sequence
    initial begin
        rst_n = 0;
        #200;
        rst_n = 1;
    end

    // I²S Clock Generator
    i2s_clock_gen #(
        .SYS_CLK_HZ(27_000_000),
        .SCK_DIV(8),
        .SCKS_PER_FRAME(32)
    ) clk_gen (
        .clk_i(clk_27m),
        .rst_ni(rst_n),
        .sck_o(sck),
        .ws_o(ws),
        .frame_start_o()
    );

    // PCM ROM (I²S microphone emulator)
    pcm_rom #(
        .WIDTH(24),
        .ADDR_WIDTH(8)
    ) mic (
        .clk_i(clk_27m),
        .rst_ni(rst_n),
        .sck_i(sck),
        .ws_i(ws),
        .sd_o(sd)
    );

    // I²S Capture
    i2s_capture_24 capture (
        .clk_i(clk_27m),
        .rst_ni(rst_n),
        .sck_i(sck),
        .ws_i(ws),
        .sd_i(sd),
        .left_o(left_data),
        .right_o(right_data),
        .ready_o(ready)
    );

    // Monitor
    integer frame_count;
    initial frame_count = 0;

    always @(posedge clk_27m) begin
        if (ready) begin
            frame_count = frame_count + 1;
            $display("Frame %0d: L=%06h (%0d), R=%06h (%0d)",
                     frame_count, left_data, left_data, right_data, right_data);

            // Stop after capturing 10 frames
            if (frame_count >= 10) begin
                $display("\n=== Test Complete ===");
                $display("Successfully captured %0d stereo frames from I²S microphone emulator", frame_count);
                $finish;
            end
        end
    end

    // Timeout
    initial begin
        #50_000_000;  // 50ms timeout
        $display("\n=== ERROR: Timeout ===");
        $display("Did not capture 10 frames within timeout period");
        $finish;
    end

    // VCD dump for waveform analysis
    initial begin
        $dumpfile("pcm_rom_tb.vcd");
        $dumpvars(0, pcm_rom_tb);
    end

endmodule
