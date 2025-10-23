// ============================================================================
// pingpong_sp_ram.sv
// - Two Gowin single-port BSRAM primitives (SP) used in ping-pong.
// - 16-bit samples, 256 per buffer (8-bit counters).
// - READ_MODE = BYPASS, WRITE_MODE = NORMAL, RESET_MODE = SYNC.
// - Single clock domain; synchronous active-low top reset (rst_ni).
// - Optional sample gating: sample_ready_i/frame_start_i.
// - Ready/valid handshakes on write and read sides.
// - Buffer-level handshake: buf_ready_o (pulse), buf_id_o (0/1), buf_take_i.
// - Sticky error flags: overrun_o, underrun_o.
// ============================================================================

`timescale 1ns/1ps

module pingpong_sp_ram #(
  parameter int unsigned SAMPLE_W = 16,
  parameter int unsigned BUF_LEN  = 256
) (
  // Clock / reset
  input  logic                  clk_i,
  input  logic                  rst_ni,          // active-low, synchronous

  // Write side (producer)
  input  logic [SAMPLE_W-1:0]  wr_data_i,
  input  logic                  wr_valid_i,
  output logic                  wr_ready_o,
  input  logic                  sample_ready_i,  // 1-clk strobe when a new sample arrives (tie high if unused)
  input  logic                  frame_start_i,   // optional frame boundary (not required by core)

  // Read side (consumer)
  output logic [SAMPLE_W-1:0]  rd_data_o,
  output logic                  rd_valid_o,
  input  logic                  rd_ready_i,
  output logic                  rd_last_o,

  // Buffer/signaling
  output logic                  buf_ready_o,     // 1-clk pulse when a 256-sample block is ready
  output logic                  buf_id_o,        // which RAM (0/1) became ready
  input  logic                  buf_take_i,      // consumer ack: start reading that buffer
  output logic                  buf_empty_o,     // no filled buffers available

  // Error/status
  output logic                  overrun_o,       // both buffers full while producer had data
  output logic                  underrun_o       // consumer requested data while none available
);

  // ------------------------
  // Local parameters / checks
  // ------------------------
  localparam int unsigned ADDR_W = 8;   // 256 deep
  localparam bit          BYPASS  = 1'b0;
  localparam logic [1:0]  WMODE   = 2'b00;

  // Synthesis-time sanity
  initial begin
    if (SAMPLE_W != 16) $error("This variant fixes SAMPLE_W=16 for clean SP mapping.");
    if (BUF_LEN  != 256) $error("This variant fixes BUF_LEN=256 (8-bit counters).");
  end

  // ------------------------
  // Address packing helper: SP uses AD[13:4] for 16-bit words.
  // For 256-depth we zero-pad {MSBs, addr[7:0], 4'b0000}.
  // ------------------------
  function automatic logic [13:0] pack_ad(input logic [ADDR_W-1:0] a);
    return {2'b00, a, 4'b0000};
  endfunction

  // ------------------------
  // State
  // ------------------------
  logic [ADDR_W-1:0] wr_addr, rd_addr;
  logic              wr_sel_q;         // 0 -> write RAM0, 1 -> write RAM1
  logic              rd_sel_q;         // 0 -> read  RAM0, 1 -> read  RAM1
  logic              reading_q;        // currently streaming a buffer
  logic [1:0]        filled_q;         // bit per buffer: block complete & not yet taken
  logic              last_filled_q;    // remembers which buffer was filled last

  // Pulses/flags
  logic buf_ready_d, buf_ready_q;      // 1-clk pulse generation
  logic buf_id_d,    buf_id_q;

  // Producer sample-beat (gated by ready)
  wire  do_write   = wr_valid_i && wr_ready_o && sample_ready_i;

  // Both buffers full?
  wire  both_full  = &filled_q;

  // ------------------------
  // Write path
  // ------------------------
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      wr_addr        <= '0;
      wr_sel_q       <= 1'b0;    // start writing RAM0
      filled_q       <= 2'b00;
      last_filled_q  <= 1'b0;
      buf_ready_q    <= 1'b0;
      buf_id_q       <= 1'b0;
      overrun_o      <= 1'b0;
    end else begin
      // Default: no buffer-ready pulse this cycle
      buf_ready_q <= 1'b0;

      // Stall detection (producer tried while we were not ready)
      if (wr_valid_i && !wr_ready_o && sample_ready_i)
        overrun_o <= 1'b1;

      if (do_write) begin
        // Increment write address
        if (wr_addr == (BUF_LEN-1)) begin
          // Completed a block on wr_sel_q
          filled_q[wr_sel_q] <= 1'b1;
          last_filled_q      <= wr_sel_q;
          buf_ready_q        <= 1'b1;
          buf_id_q           <= wr_sel_q;

          // Switch to the other buffer and reset address
          wr_sel_q           <= ~wr_sel_q;
          wr_addr            <= '0;
        end else begin
          wr_addr <= wr_addr + 1'b1;
        end
      end

      // Clear filled flag when consumer starts reading it (handled in read path)
      // (No action here; done below when reading starts.)
    end
  end

  // Producer backpressure: not ready when both filled
  assign wr_ready_o = !both_full;

  // 1-clk pulse outputs
  assign buf_ready_o = buf_ready_q;
  assign buf_id_o    = buf_id_q;

  // ------------------------
  // Read path
  // ------------------------
  // Choose which buffer to read on buf_take_i when idle:
  // - If both are filled, prefer the one that is NOT last_filled_q (older first)
  // - Else take whichever is filled.
  wire have_buf0    = filled_q[0];
  wire have_buf1    = filled_q[1];
  wire any_filled   = have_buf0 | have_buf1;
  assign buf_empty_o = ~any_filled;

  logic        take_now;
  logic        next_rd_sel;
  always_comb begin
    take_now   = (!reading_q) && buf_take_i && any_filled;
    // Select older if both filled; else whichever is set
    if (have_buf0 && have_buf1)
      next_rd_sel = ~last_filled_q;    // read the older one first
    else if (have_buf0)
      next_rd_sel = 1'b0;
    else
      next_rd_sel = 1'b1;              // must be buf1
  end

  // Read state machine
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      reading_q   <= 1'b0;
      rd_sel_q    <= 1'b1; // start idle with opposite to writer (doesn't matter)
      rd_addr     <= '0;
      rd_last_o   <= 1'b0;
      underrun_o  <= 1'b0;
    end else begin
      rd_last_o <= 1'b0;

      // Underrun: consumer asked while no data valid
      if (rd_ready_i && !rd_valid_o)
        underrun_o <= 1'b1;

      if (take_now) begin
        // Lock chosen buffer for reading; free it from "filled"
        rd_sel_q              <= next_rd_sel;
        reading_q             <= 1'b1;
        rd_addr               <= '0;
        filled_q[next_rd_sel] <= 1'b0;   // now reserved for reading (unblocks writer)
      end else if (reading_q) begin
        // Stream with ready/valid handshaking
        if (rd_valid_o && rd_ready_i) begin
          if (rd_addr == (BUF_LEN-1)) begin
            rd_last_o  <= 1'b1;
            reading_q  <= 1'b0;
            rd_addr    <= '0;
          end else begin
            rd_addr    <= rd_addr + 1'b1;
          end
        end
      end
    end
  end

  // In BYPASS read mode, DO reflects the addressed word without an extra pipeline stage.
  // We assert valid while "reading_q" and hold the address until the handshake occurs.
  assign rd_valid_o = reading_q;

  // ------------------------
  // SP primitive wiring
  //   - RAM0: write when wr_sel_q==0 && do_write; read when rd_sel_q==0 && reading_q.
  //   - RAM1: same pattern with sel==1.
  // Only one operation (R or W) is performed on a given SP at a time.
  // ------------------------

  // RAM0 control
  wire        ram0_we   = (wr_sel_q == 1'b0) && do_write;
  wire        ram0_re   = (rd_sel_q == 1'b0) && reading_q;
  wire [13:0] ram0_ad   = ram0_we ? pack_ad(wr_addr) :
                          ram0_re ? pack_ad(rd_addr) : pack_ad(wr_addr);
  wire [15:0] ram0_di   = wr_data_i;
  wire [15:0] ram0_do;

  // RAM1 control
  wire        ram1_we   = (wr_sel_q == 1'b1) && do_write;
  wire        ram1_re   = (rd_sel_q == 1'b1) && reading_q;
  wire [13:0] ram1_ad   = ram1_we ? pack_ad(wr_addr) :
                          ram1_re ? pack_ad(rd_addr) : pack_ad(wr_addr);
  wire [15:0] ram1_di   = wr_data_i;
  wire [15:0] ram1_do;

  // Output mux
  assign rd_data_o = (rd_sel_q == 1'b0) ? ram0_do : ram1_do;

  // ------------------------
  // Gowin BSRAM primitives (SP)
  // ------------------------

  // RAM0
  SP u_sp0 (
    .DO     ({ /* upper unused */ , ram0_do }),
    .CLK    (clk_i),
    .CE     (1'b1),
    .OCE    (1'b0),       // BYPASS read
    .RESET  (~rst_ni),    // active-high inside primitive
    .WRE    (ram0_we),    // 1=write, 0=read
    .AD     (ram0_ad),
    .BLKSEL (3'b000),
    .DI     ({ /* upper unused */ , ram0_di })
  );
  // Parameters
  defparam u_sp0.READ_MODE  = 1'b0;        // BYPASS
  defparam u_sp0.WRITE_MODE = 2'b00;       // NORMAL
  defparam u_sp0.BIT_WIDTH  = 16;
  defparam u_sp0.RESET_MODE = "SYNC";
  defparam u_sp0.BLK_SEL    = 3'b000;

  // RAM1
  SP u_sp1 (
    .DO     ({ /* upper unused */ , ram1_do }),
    .CLK    (clk_i),
    .CE     (1'b1),
    .OCE    (1'b0),
    .RESET  (~rst_ni),
    .WRE    (ram1_we),
    .AD     (ram1_ad),
    .BLKSEL (3'b000),
    .DI     ({ /* upper unused */ , ram1_di })
  );
  // Parameters
  defparam u_sp1.READ_MODE  = 1'b0;        // BYPASS
  defparam u_sp1.WRITE_MODE = 2'b00;       // NORMAL
  defparam u_sp1.BIT_WIDTH  = 16;
  defparam u_sp1.RESET_MODE = "SYNC";
  defparam u_sp1.BLK_SEL    = 3'b000;

endmodule
