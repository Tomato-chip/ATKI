// =============================================================================
// pcm_rom.v
// I²S Microphone Emulator (MSM261S4030H0-compatible)
// Serializes 24-bit PCM data from ROM as I²S stream (MSB-first, 25 bits/channel)
// =============================================================================

module pcm_rom #(
    parameter WIDTH      = 24,
    parameter ADDR_WIDTH = 8    // 2^8 = 256 adresser
)(
    input  wire        clk_i,
    input  wire        rst_ni,
    input  wire        sck_i,    // I²S bit clock
    input  wire        ws_i,     // Word select: 0=left, 1=right
    output reg         sd_o      // Serial data output
);

    reg [WIDTH-1:0] mem_left  [(1<<ADDR_WIDTH)-1:0];
    reg [WIDTH-1:0] mem_right [(1<<ADDR_WIDTH)-1:0];

    initial begin
        $readmemh("/home/tomato-chip/ATKI/tools/pcm_data_sine.hex", mem_left);
        $readmemh("/home/tomato-chip/ATKI/tools/pcm_data_cosine.hex", mem_right);
    end

    // Edge detection for SCK and WS
    reg sck_d, ws_d;
    always @(posedge clk_i) begin
        if (!rst_ni) begin
            sck_d <= 1'b0;
            ws_d  <= 1'b0;
        end else begin
            sck_d <= sck_i;
            ws_d  <= ws_i;
        end
    end

    wire sck_fall = sck_d & ~sck_i;
    wire ws_edge  = (ws_d != ws_i);

    // State registers
    reg [24:0] shift_reg;           // 1 dummy + 24 data bits
    reg [4:0]  bit_cnt;             // 0..24 (25 bits total)
    reg [ADDR_WIDTH-1:0] addr_cnt;  // ROM address counter
    reg        channel;             // 0=left, 1=right

    always @(posedge clk_i) begin
        if (!rst_ni) begin
            shift_reg <= 25'h0;
            bit_cnt   <= 5'd0;
            addr_cnt  <= {ADDR_WIDTH{1'b0}};
            sd_o      <= 1'b0;
            channel   <= 1'b0;
        end else begin
            // WS edge: load new data for channel
            if (ws_edge) begin
                bit_cnt <= 5'd0;
                channel <= ws_i;
                // Load data: {1'b0 dummy, mem_left/right[addr_cnt]}
                if (ws_i == 1'b0) begin
                    shift_reg <= {1'b0, mem_left[addr_cnt]};
                end else begin
                    shift_reg <= {1'b0, mem_right[addr_cnt]};
                end

                // Increment address after right channel completes
                if (ws_i == 1'b0 && channel == 1'b1) begin
                    addr_cnt <= addr_cnt + 1'b1;
                end
            end
            // SCK falling edge: shift out next bit
            else if (sck_fall && bit_cnt < 5'd25) begin
                sd_o      <= shift_reg[24];           // Output MSB
                shift_reg <= {shift_reg[23:0], 1'b0}; // Shift left
                bit_cnt   <= bit_cnt + 5'd1;
            end
        end
    end

endmodule
