// =============================================================================
// sampler.sv
// Parameterized microphone sampler with double-buffer integration
// =============================================================================
// Accepts parallel microphone samples and stores them in ping-pong buffers.
// Currently supports 1 active microphone, scalable to 7 via parameter.
// Each microphone channel has its own double-buffer RAM instance.
// =============================================================================

module sampler #(
    parameter int unsigned N_MICS          = 1,     // Number of microphones (1-7)
    parameter int unsigned DATA_WIDTH      = 16,    // Sample width in bits
    parameter int unsigned SAMPLES_PER_BUF = 256,   // Samples per buffer
    parameter int unsigned ADDR_WIDTH      = $clog2(SAMPLES_PER_BUF),
    parameter bit          USE_GOWIN_DPB   = 1'b1   // Use Gowin DPB (1) or generic RAM (0)
)(
    input  logic                     clk_i,
    input  logic                     rst_ni,        // Active-low synchronous reset

    // Microphone parallel sample bus
    input  logic [DATA_WIDTH-1:0]    mic_data_i [N_MICS],
    input  logic                     mic_valid_i,   // One-sample strobe for all mics

    // Status and handshakes
    output logic                     buf_ready_pulse_o,  // 1-cycle pulse when buffer completes
    output logic [$clog2(N_MICS>1?N_MICS:2)-1:0] buf_ready_ch_o,  // Channel that completed
    output logic                     active_buf_o        // Current write buffer (0=A, 1=B)

    // Optional future enhancements (commented out for now)
    // output logic                     in_ready_o,        // Back-pressure
    // output logic [N_MICS-1:0]        buf_ready_level_o, // Sticky flags per channel
    // input  logic [N_MICS-1:0]        buf_release_i      // Clear sticky flags
);

    // =========================================================================
    // Parameter validation
    // =========================================================================
    initial begin
        if (N_MICS < 1 || N_MICS > 7) begin
            $fatal(1, "N_MICS must be between 1 and 7, got %0d", N_MICS);
        end
        if (DATA_WIDTH < 8 || DATA_WIDTH > 32) begin
            $fatal(1, "DATA_WIDTH must be between 8 and 32, got %0d", DATA_WIDTH);
        end
        if (SAMPLES_PER_BUF < 2) begin
            $fatal(1, "SAMPLES_PER_BUF must be >= 2, got %0d", SAMPLES_PER_BUF);
        end
    end

    // =========================================================================
    // Internal signals for each channel
    // =========================================================================
    logic [N_MICS-1:0]               ch_buf_ready_pulse;
    logic [N_MICS-1:0]               ch_active_buf;

    // Read interface signals (per channel) - for future use
    logic [ADDR_WIDTH-1:0]           rd_addr [N_MICS];
    logic [N_MICS-1:0]               rd_en;
    logic [DATA_WIDTH-1:0]           rd_data [N_MICS];
    logic [N_MICS-1:0]               rd_data_valid;

    // =========================================================================
    // Channel 0: Active microphone
    // =========================================================================
    double_buffer_ram #(
        .DATA_WIDTH           (DATA_WIDTH),
        .SAMPLES_PER_BUF      (SAMPLES_PER_BUF),
        .ADDR_WIDTH           (ADDR_WIDTH),
        .SYNTH_USE_GOWIN_DPB  (USE_GOWIN_DPB),     // Configurable via parameter
        .DROP_WRITES_ON_TOGGLE(1'b1)
    ) channel_0_buffer (
        .clk_i              (clk_i),
        .rst_ni             (rst_ni),

        // Write interface from microphone
        .in_valid_i         (mic_valid_i),
        .in_data_i          (mic_data_i[0]),
        .in_ready_o         (),                    // Not used currently

        // Read interface (for future processor access)
        .rd_addr_i          (rd_addr[0]),
        .rd_en_i            (rd_en[0]),
        .rd_data_o          (rd_data[0]),
        .rd_data_valid_o    (rd_data_valid[0]),

        // Status
        .active_buf_o       (ch_active_buf[0]),
        .buf_ready_pulse_o  (ch_buf_ready_pulse[0]),
        .buf_ready_id_o     ()                     // Not used for single buffer per channel
    );

    // Default read interface values for channel 0
    assign rd_addr[0] = '0;
    assign rd_en[0]   = 1'b0;

    // =========================================================================
    // Channels 1 to N_MICS-1: Stubbed for future expansion
    // =========================================================================
    // Template for scaling to multiple microphones:
    //
    // generate
    //     for (genvar ch = 1; ch < N_MICS; ch++) begin : gen_mic_channels
    //         double_buffer_ram #(
    //             .DATA_WIDTH           (DATA_WIDTH),
    //             .SAMPLES_PER_BUF      (SAMPLES_PER_BUF),
    //             .ADDR_WIDTH           (ADDR_WIDTH),
    //             .SYNTH_USE_GOWIN_DPB  (1'b1),
    //             .DROP_WRITES_ON_TOGGLE(1'b1)
    //         ) channel_buffer (
    //             .clk_i              (clk_i),
    //             .rst_ni             (rst_ni),
    //
    //             // Write interface
    //             .in_valid_i         (mic_valid_i),
    //             .in_data_i          (mic_data_i[ch]),
    //             .in_ready_o         (),
    //
    //             // Read interface
    //             .rd_addr_i          (rd_addr[ch]),
    //             .rd_en_i            (rd_en[ch]),
    //             .rd_data_o          (rd_data[ch]),
    //             .rd_data_valid_o    (rd_data_valid[ch]),
    //
    //             // Status
    //             .active_buf_o       (ch_active_buf[ch]),
    //             .buf_ready_pulse_o  (ch_buf_ready_pulse[ch]),
    //             .buf_ready_id_o     ()
    //         );
    //
    //         // Default read interface values
    //         assign rd_addr[ch] = '0;
    //         assign rd_en[ch]   = 1'b0;
    //     end
    // endgenerate

    // Stub unused channels
    generate
        for (genvar ch = 1; ch < N_MICS; ch++) begin : gen_stub_channels
            assign ch_buf_ready_pulse[ch] = 1'b0;
            assign ch_active_buf[ch]      = 1'b0;
            assign rd_data[ch]            = '0;
            assign rd_data_valid[ch]      = 1'b0;
        end
    endgenerate

    // =========================================================================
    // Output aggregation
    // =========================================================================

    // OR all buffer ready pulses (any channel completing triggers pulse)
    always_comb begin
        buf_ready_pulse_o = 1'b0;
        for (int i = 0; i < N_MICS; i++) begin
            buf_ready_pulse_o |= ch_buf_ready_pulse[i];
        end
    end

    // Priority encoder: find which channel triggered the pulse
    // (lowest index has priority if multiple channels complete simultaneously)
    always_comb begin
        buf_ready_ch_o = '0;
        for (int i = 0; i < N_MICS; i++) begin
            if (ch_buf_ready_pulse[i]) begin
                buf_ready_ch_o = i[$clog2(N_MICS>1?N_MICS:2)-1:0];
                break;  // Take first match (lowest priority)
            end
        end
    end

    // Expose channel 0's active buffer status
    // (In multi-channel mode, all channels should be synchronized)
    assign active_buf_o = ch_active_buf[0];

    // =========================================================================
    // Optional: Sticky buffer ready flags (future enhancement)
    // =========================================================================
    // logic [N_MICS-1:0] buf_ready_level_q;
    //
    // always_ff @(posedge clk_i) begin
    //     if (!rst_ni) begin
    //         buf_ready_level_q <= '0;
    //     end else begin
    //         for (int i = 0; i < N_MICS; i++) begin
    //             if (buf_release_i[i]) begin
    //                 buf_ready_level_q[i] <= 1'b0;
    //             end else if (ch_buf_ready_pulse[i]) begin
    //                 buf_ready_level_q[i] <= 1'b1;
    //             end
    //         end
    //     end
    // end
    //
    // assign buf_ready_level_o = buf_ready_level_q;

    // =========================================================================
    // Assertions (simulation only)
    // =========================================================================
    `ifndef SYNTHESIS
        // Buffer ready pulse should be exactly 1 cycle
        assert property (@(posedge clk_i) disable iff (!rst_ni)
            buf_ready_pulse_o |=> !buf_ready_pulse_o)
        else $error("buf_ready_pulse_o not single-cycle");

        // Valid channel ID
        assert property (@(posedge clk_i) disable iff (!rst_ni)
            buf_ready_pulse_o |-> (buf_ready_ch_o < N_MICS))
        else $error("buf_ready_ch_o out of range: %0d", buf_ready_ch_o);

        // Mic valid should not cause X/Z propagation
        assert property (@(posedge clk_i) disable iff (!rst_ni)
            mic_valid_i |-> !$isunknown(mic_data_i[0]))
        else $warning("mic_data_i[0] contains X or Z during valid");
    `endif

endmodule
