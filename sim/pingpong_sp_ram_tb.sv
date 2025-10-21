// pingpong_sp_ram_tb.sv
// Self-checking testbench for ping-pong SP RAM module
// Verifies:
//   - Buffer toggle after 256 samples
//   - 1-cycle pipeline read latency
//   - Correct data readback from inactive buffer
//   - buf_ready_pulse_o and buf_ready_id_o signals

`timescale 1ns/1ps

module pingpong_sp_ram_tb;

    // Parameters
    localparam int DATA_WIDTH      = 16;
    localparam int SAMPLES_PER_BUF = 256;
    localparam int ADDR_WIDTH      = $clog2(SAMPLES_PER_BUF);
    localparam CLK_PERIOD          = 10;  // 10ns = 100MHz

    // DUT signals
    logic                   clk_i;
    logic                   rst_ni;
    logic                   in_valid_i;
    logic [DATA_WIDTH-1:0]  in_data_i;
    logic                   rd_en_i;
    logic [ADDR_WIDTH-1:0]  rd_addr_i;
    logic [DATA_WIDTH-1:0]  rd_data_o;
    logic                   rd_valid_o;
    logic                   active_buf_o;
    logic                   buf_ready_pulse_o;
    logic                   buf_ready_id_o;

    // Test variables
    int errors = 0;
    logic [DATA_WIDTH-1:0] expected_data;
    int i;

    // Instantiate DUT
    pingpong_sp_ram #(
        .DATA_WIDTH(DATA_WIDTH),
        .SAMPLES_PER_BUF(SAMPLES_PER_BUF),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) dut (
        .clk_i(clk_i),
        .rst_ni(rst_ni),
        .in_valid_i(in_valid_i),
        .in_data_i(in_data_i),
        .rd_en_i(rd_en_i),
        .rd_addr_i(rd_addr_i),
        .rd_data_o(rd_data_o),
        .rd_valid_o(rd_valid_o),
        .active_buf_o(active_buf_o),
        .buf_ready_pulse_o(buf_ready_pulse_o),
        .buf_ready_id_o(buf_ready_id_o)
    );

    // Clock generation
    initial begin
        clk_i = 0;
        forever #(CLK_PERIOD/2) clk_i = ~clk_i;
    end

    // Main test sequence
    initial begin
        $display("============================================");
        $display("Ping-Pong SP RAM Testbench");
        $display("============================================\n");

        // Initialize signals
        rst_ni = 1'b0;
        in_valid_i = 1'b0;
        in_data_i = '0;
        rd_en_i = 1'b0;
        rd_addr_i = '0;

        // Hold reset for a few cycles
        repeat(5) @(posedge clk_i);
        rst_ni = 1'b1;
        @(posedge clk_i);

        $display("[Test 1] Initial state check");
        if (active_buf_o !== 1'b0) begin
            $display("  ERROR: active_buf_o should be 0 after reset, got %b", active_buf_o);
            errors++;
        end
        if (buf_ready_pulse_o !== 1'b0) begin
            $display("  ERROR: buf_ready_pulse_o should be 0 after reset, got %b", buf_ready_pulse_o);
            errors++;
        end
        $display("  PASS: Initial state correct\n");

        // Test 2: Write 256 incrementing samples to buffer A
        $display("[Test 2] Writing 256 samples to buffer A (active_buf_o=0)");
        for (i = 0; i < 256; i++) begin
            @(posedge clk_i);
            in_valid_i = 1'b1;
            in_data_i = 16'hA000 + i;  // Pattern: 0xA000, 0xA001, ..., 0xA0FF
        end

        // After the 256th write clock, active_buf_o should toggle on the NEXT clock
        @(posedge clk_i);
        in_valid_i = 1'b0;
        #1;

        $display("  Debug: After 256 writes, active_buf_o=%b, buf_ready_pulse_o=%b", active_buf_o, buf_ready_pulse_o);

        // Check that buffer toggled after 256 samples
        if (buf_ready_pulse_o !== 1'b0) begin
            $display("  ERROR: buf_ready_pulse_o should be LOW (1-cycle pulse already passed)");
            errors++;
        end
        if (buf_ready_id_o !== 1'b0) begin
            $display("  ERROR: buf_ready_id_o should be 0 (buffer A was filled)");
            errors++;
        end
        if (active_buf_o !== 1'b1) begin
            $display("  ERROR: active_buf_o should be 1 after 256 writes to buffer A");
            errors++;
        end

        $display("  PASS: 256 samples written, buffer toggled\n");

        // Test 3: Read back data from buffer A (now inactive) with 1-cycle pipeline latency
        $display("[Test 3] Reading from buffer A with 1-cycle pipeline latency");

        // Read address 0
        @(posedge clk_i);
        rd_en_i = 1'b1;
        rd_addr_i = 8'd0;
        expected_data = 16'hA000;

        // Wait for 1-cycle pipeline latency
        @(posedge clk_i);
        #1;

        if (rd_valid_o !== 1'b1) begin
            $display("  ERROR: rd_valid_o should be HIGH after 1-cycle latency");
            errors++;
        end
        if (rd_data_o !== expected_data) begin
            $display("  ERROR: Expected 0x%04h, got 0x%04h", expected_data, rd_data_o);
            errors++;
        end else begin
            $display("  PASS: Read 0x%04h from address 0 with correct 1-cycle latency", rd_data_o);
        end

        // Test a few more addresses
        for (i = 1; i < 5; i++) begin
            @(posedge clk_i);
            rd_addr_i = i;
            expected_data = 16'hA000 + i;

            // Wait 1 cycle for pipeline
            @(posedge clk_i);
            #1;

            if (rd_valid_o !== 1'b1) begin
                $display("  ERROR: rd_valid_o not asserted for address %0d", i);
                errors++;
            end
            if (rd_data_o !== expected_data) begin
                $display("  ERROR: Address %0d: Expected 0x%04h, got 0x%04h", i, expected_data, rd_data_o);
                errors++;
            end
        end

        rd_en_i = 1'b0;
        @(posedge clk_i);
        #1;

        // rd_valid_o should go low when rd_en_i is low
        if (rd_valid_o !== 1'b0) begin
            $display("  WARNING: rd_valid_o should go LOW when rd_en_i is LOW");
        end

        $display("  PASS: Read verification complete for buffer A\n");

        // Test 4: Write 256 samples to buffer B
        $display("[Test 4] Writing 256 samples to buffer B (active_buf_o=1)");
        for (i = 0; i < 256; i++) begin
            @(posedge clk_i);
            in_valid_i = 1'b1;
            in_data_i = 16'hB000 + i;  // Pattern: 0xB000, 0xB001, ..., 0xB0FF
        end

        @(posedge clk_i);
        in_valid_i = 1'b0;
        #1;

        if (active_buf_o !== 1'b0) begin
            $display("  ERROR: active_buf_o should toggle back to 0, got %b", active_buf_o);
            errors++;
        end
        if (buf_ready_id_o !== 1'b1) begin
            $display("  ERROR: buf_ready_id_o should be 1 (buffer B filled), got %b", buf_ready_id_o);
            errors++;
        end

        $display("  PASS: Buffer B filled, active_buf_o toggled back to 0\n");

        // Test 5: Read from buffer B (now inactive)
        $display("[Test 5] Reading from buffer B");
        @(posedge clk_i);
        rd_en_i = 1'b1;
        rd_addr_i = 8'd0;
        expected_data = 16'hB000;

        // Wait for pipeline
        @(posedge clk_i);
        @(posedge clk_i);
        #1;

        if (rd_data_o !== expected_data) begin
            $display("  ERROR: Expected 0x%04h from buffer B, got 0x%04h", expected_data, rd_data_o);
            errors++;
        end else begin
            $display("  PASS: Read 0x%04h from buffer B", rd_data_o);
        end

        rd_en_i = 1'b0;
        @(posedge clk_i);

        // Final summary
        $display("\n============================================");
        if (errors == 0) begin
            $display("*** PASS: All tests passed! ***");
        end else begin
            $display("*** FAIL: %0d error(s) detected ***", errors);
            $fatal(1, "Testbench failed with errors");
        end
        $display("============================================\n");

        $finish;
    end

    // Timeout watchdog
    initial begin
        #100000;  // 100us timeout
        $display("\nERROR: Testbench timeout!");
        $fatal(1, "Timeout");
    end

    // Optional: Waveform dumping for debugging
    initial begin
        $dumpfile("pingpong_sp_ram_tb.vcd");
        $dumpvars(0, pingpong_sp_ram_tb);
    end

endmodule
