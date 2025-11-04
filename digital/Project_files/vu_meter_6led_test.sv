// ===============================================================
// vu_meter_6led.sv
// Enkel 6-LED VU-meter for én I2S-kanal (24-bit PCM)
// Bruges sammen med i2s_capture_24 (clk_i = 27 MHz, strobe = ready_o)
// Eller med ram_logic via ready/valid handshake
// ===============================================================
module vu_meter_6led #(
  parameter bit SELECT_LEFT    = 1'b1,   // 1=venstre, 0=højre
  parameter int DECAY_SHIFT    = 14,     // større = langsommere fald (12..13 = mere træg)
  parameter int SCALE_SHIFT    = 2,      // større = mindre følsom; justér 8..12 (REDUCED from 10 for more sensitivity)
  // faste tærskler — hæv/sænk hvis for mange/få LED'er tænder
  parameter int unsigned TH1   = 24'd500,    // Lowered from 1000
  parameter int unsigned TH2   = 24'd2000,   // Lowered from 3000
  parameter int unsigned TH3   = 24'd6000,   // Lowered from 9000
  parameter int unsigned TH4   = 24'd15000,  // Lowered from 20000
  parameter int unsigned TH5   = 24'd35000,  // Lowered from 40000
  parameter int unsigned TH6   = 24'd70000,  // Lowered from 80000
  // LED-opdatering ~50 Hz ved 27 MHz: 27e6 / 540000 ≈ 50
  parameter int LED_DIV        = 2700000
  // RAM consumer mode enable (always true - direct mode removed)
  // parameter bit USE_RAM_IF     = 1'b1    // 1=use RAM handshake, 0=use direct sample_valid
)(
  input  logic               clk_i,          // 27 MHz (samme som i2s_capture_24.clk_i)
  input  logic               rst_ni,
  input  logic signed [23:0] ram_read_data_i,  // From ram_logic.read_data_o
  input  logic               ram_read_valid_i, // From ram_logic.read_valid_o
  output logic               ram_read_ready_o, // To ram_logic.read_ready_i
  input  logic               ram_buffer_ready_i, // From ram_logic.buffer_ready_o (optional)
  output logic [5:0]         leds_o
);

  //==========================================================================
  // Sample source selection and handshaking
  //==========================================================================
  logic signed [23:0] sample;
  logic               sample_valid;
  logic               ram_read_accepted;
  logic               ram_ready_q;         // Registered ready signal
  logic               processing_delay_q;  // Ensures 2-cycle processing time

  // generate
  //   if (USE_RAM_IF) begin : gen_ram_mode
      // RAM consumer mode: use ready/valid handshake with flow control
      // Ready signal indicates we can accept a new sample
      assign ram_read_ready_o = ram_ready_q;
      assign ram_read_accepted = ram_read_valid_i && ram_read_ready_o;

      // In RAM mode, interpret ram_read_data_i as a single channel sample
      // (Assumes ram_logic stores either left or right channel, selected externally)
      assign sample = ram_read_data_i;
      assign sample_valid = ram_read_accepted;

  //   end else begin : gen_direct_mode
  //     // Direct sample mode: use original interface
  //     assign ram_read_ready_o = 1'b0;  // Not using RAM interface
  //     assign sample = (SELECT_LEFT ? left_sample_i : right_sample_i);
  //     assign sample_valid = sample_valid_i;
  //   end
  // endgenerate

  // Absolutværdi (unsigned)
  logic [23:0] mag;
  always_comb mag = sample[23] ? (~sample + 1'b1) : sample;

  // Leaky integrator (glidende middel)
  logic [31:0] level_q;

  // Ready/valid flow control for RAM mode
  // We need 2 cycles to compute and settle the level update
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      level_q <= 32'd0;
      ram_ready_q <= 1'b1;           // Start ready
      processing_delay_q <= 1'b0;
    end else begin
      if (sample_valid) begin
        // Accept sample: start computation, enter processing state
        level_q <= level_q - (level_q >> DECAY_SHIFT)
                            + (mag >> SCALE_SHIFT);
        ram_ready_q <= 1'b0;
        processing_delay_q <= 1'b1;   // Mark as processing
      end else if (processing_delay_q) begin
        // Still processing: wait one more cycle for computation to settle
        ram_ready_q <= 1'b0;
        processing_delay_q <= 1'b0;   // Clear delay next cycle
      end else begin
        // Done processing: ready for next sample
        ram_ready_q <= 1'b1;
      end
    end
  end

  // ~50 Hz LED-opdatering (for at undgå flimren)
  logic [$clog2(LED_DIV)-1:0] div_q;
  logic tick;
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      div_q <= '0; tick <= 1'b0;
    end else if (div_q == LED_DIV-1) begin
      div_q <= '0; tick <= 1'b1;
    end else begin
      div_q <= div_q + 1'b1; tick <= 1'b0;
    end
  end

  // Sammenlign mod tærskler kun ved tick
  logic [5:0] leds_next;
  always_comb begin
    leds_next[0] = (level_q > TH1);
    leds_next[1] = (level_q > TH2);
    leds_next[2] = (level_q > TH3);
    leds_next[3] = (level_q > TH4);
    leds_next[4] = (level_q > TH5);
    leds_next[5] = (level_q > TH6);
  end

  always_ff @(posedge clk_i) begin
    if (!rst_ni)        leds_o <= 6'b0;
    else if (tick)      leds_o <= leds_next;
  end
endmodule
