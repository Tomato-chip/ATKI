// ===============================================================
// vu_meter_6led.sv
// 6-LED VU-meter for 24-bit PCM audio samples
// Consumes samples from ram_logic via ready/valid handshake
// ===============================================================
module vu_meter_6led #(
  // Buffer size (must match ram_logic DEPTH parameter)
  parameter int BUFFER_DEPTH   = 16,        // Number of samples per buffer

  // Leaky integrator parameters
  parameter int DECAY_SHIFT    = 14,        // Decay rate: higher = slower decay (12-16 recommended)
  parameter int SCALE_SHIFT    = 2,         // Sensitivity: higher = less sensitive (0-4 recommended)

  // LED threshold levels (32-bit to match level_q width)
  parameter int unsigned TH1   = 32'd500,   // LED 1 threshold
  parameter int unsigned TH2   = 32'd2000,  // LED 2 threshold
  parameter int unsigned TH3   = 32'd6000,  // LED 3 threshold
  parameter int unsigned TH4   = 32'd15000, // LED 4 threshold
  parameter int unsigned TH5   = 32'd35000, // LED 5 threshold
  parameter int unsigned TH6   = 32'd70000, // LED 6 threshold

  // LED refresh rate: ~50 Hz at 27 MHz clock
  parameter int LED_DIV        = 540000     // 27e6 / 540000 = 50 Hz
)(
  input  logic               clk_i,             // System clock (27 MHz)
  input  logic               rst_ni,            // Active-low reset

  // RAM consumer interface (ready/valid handshake)
  input  logic signed [23:0] ram_read_data_i,   // Sample data from RAM
  input  logic               ram_read_valid_i,  // Valid signal from RAM
  output logic               ram_read_ready_o,  // Ready signal to RAM
  input  logic               ram_buffer_ready_i, // Buffer ready indicator (optional monitoring)
  // LED outputs
  output logic [5:0]         leds_o,            // LED control signals

  // Analog output for oscilloscope (PWM)
  output logic               analog_out_o,      // PWM output representing audio level

  // Debug outputs
  output logic [5:0]         debug_o            // Debug signals
);

  //==========================================================================
  // Internal signals
  //==========================================================================

  // Processing state machine
  typedef enum logic [1:0] {
    WAIT_BUFFER, // Wait for ram_buffer_ready_i pulse
    READING,     // Reading all samples from buffer and finding peak
    COMPUTE,     // Update leaky integrator with peak value
    SETTLE       // Allowing computation to settle
  } state_t;

  state_t state_q, state_d;

  // Buffer reading
  logic [$clog2(BUFFER_DEPTH):0] sample_count_q, sample_count_d; // Count samples read
  logic               sample_accepted;   // Handshake occurred

  // Peak detection
  logic        [23:0] magnitude;         // Absolute value of current sample
  logic        [23:0] peak_magnitude_q, peak_magnitude_d; // Maximum magnitude in buffer

  // Level tracking
  logic        [31:0] level_q, level_d;  // Leaky integrator output

  // LED update control
  logic [$clog2(LED_DIV)-1:0] refresh_counter_q;
  logic                        led_update_tick;

  //==========================================================================
  // Ready/valid handshake
  //==========================================================================
  assign sample_accepted = ram_read_valid_i && ram_read_ready_o;
  // Always ready to read - let RAM control flow with read_valid
  // This ensures we never miss samples due to state machine timing
  assign ram_read_ready_o = 1'b1;

  //==========================================================================
  // Magnitude calculation (absolute value)
  //==========================================================================
  always_comb begin
    magnitude = ram_read_data_i[23] ? (~ram_read_data_i + 24'b1) : ram_read_data_i;
  end

  //==========================================================================
  // State machine for buffer reading and peak detection
  //==========================================================================
  always_comb begin
    // Default: maintain state
    state_d = state_q;
    level_d = level_q;
    sample_count_d = sample_count_q;
    peak_magnitude_d = peak_magnitude_q;

    case (state_q)
      WAIT_BUFFER: begin
        // Wait for buffer_ready pulse indicating new buffer is available
        if (ram_buffer_ready_i) begin
          // New buffer starting, reset counters and peak
          state_d = READING;
          sample_count_d = '0;
          peak_magnitude_d = '0;
        end
      end

      READING: begin
        // Read exactly BUFFER_DEPTH samples and track peak magnitude
        if (sample_accepted) begin
          // Always update peak - use ternary to select max
          peak_magnitude_d = (magnitude > peak_magnitude_q) ? magnitude : peak_magnitude_q;

          // Increment sample counter
          sample_count_d = sample_count_q + 1'b1;

          // After reading exactly BUFFER_DEPTH samples, compute VU level
          if (sample_count_q >= BUFFER_DEPTH - 1) begin
            state_d = COMPUTE;
          end
        end
      end

      COMPUTE: begin
        // Update leaky integrator with peak magnitude from buffer
        level_d = level_q - (level_q >> DECAY_SHIFT) + (peak_magnitude_q >> SCALE_SHIFT);
        state_d = SETTLE;
      end

      SETTLE: begin
        // Allow computation to settle, then wait for next buffer
        state_d = WAIT_BUFFER;
      end

      default: state_d = WAIT_BUFFER;
    endcase
  end

  // State and level registers
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      state_q          <= WAIT_BUFFER;
      level_q          <= 32'd0;
      sample_count_q   <= '0;
      peak_magnitude_q <= '0;
    end else begin
      state_q          <= state_d;
      level_q          <= level_d;
      sample_count_q   <= sample_count_d;
      peak_magnitude_q <= peak_magnitude_d;
    end
  end

  //==========================================================================
  // LED refresh rate divider (~50 Hz to prevent flicker)
  //==========================================================================
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      refresh_counter_q <= '0;
      led_update_tick   <= 1'b0;
    end else begin
      if (refresh_counter_q == LED_DIV - 1) begin
        refresh_counter_q <= '0;
        led_update_tick   <= 1'b1;
      end else begin
        refresh_counter_q <= refresh_counter_q + 1'b1;
        led_update_tick   <= 1'b0;
      end
    end
  end

  //==========================================================================
  // LED threshold comparison and output
  //==========================================================================
  logic [5:0] leds_d;

  always_comb begin
    leds_d[0] = (level_q >= TH1);
    leds_d[1] = (level_q >= TH2);
    leds_d[2] = (level_q >= TH3);
    leds_d[3] = (level_q >= TH4);
    leds_d[4] = (level_q >= TH5);
    leds_d[5] = (level_q >= TH6);
  end

  // Update LED outputs only on refresh tick to reduce flicker
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      leds_o <= 6'b0;
    end else if (led_update_tick) begin
      leds_o <= leds_d;
    end
  end

  //==========================================================================
  // PWM Analog Output for Oscilloscope
  //==========================================================================
  // PWM Parameters:
  // - PWM frequency: 27 MHz / 1024 = ~26.4 kHz (above audio range)
  // - Resolution: 10 bits (1024 steps)
  // - Output range maps level_q (0-100000) to duty cycle (0-100%)
  //
  // The oscilloscope will show:
  // - Low audio levels: low average voltage (e.g., 0.5V at 3.3V logic)
  // - High audio levels: high average voltage (e.g., 3.0V at 3.3V logic)
  // - Set scope to AC coupling and add averaging/filtering for best viewing
  //==========================================================================

  localparam int PWM_BITS = 10;                    // 10-bit PWM resolution
  localparam int PWM_MAX = (1 << PWM_BITS) - 1;    // 1023
  localparam int LEVEL_MAX = 100000;                // Maximum expected level value

  logic [PWM_BITS-1:0] pwm_counter_q;              // PWM counter (0-1023)
  logic [PWM_BITS-1:0] pwm_duty_cycle;             // Scaled duty cycle value

  // Scale level_q (0-100000) down to PWM range (0-1023)
  // duty_cycle = (level_q * 1024) / 100000
  // Simplified: duty_cycle = level_q >> 6  (approx divide by 64, gives ~1562 max)
  // Better scaling: Clamp to LEVEL_MAX then scale
  logic [31:0] level_clamped;
  assign level_clamped = (level_q > LEVEL_MAX) ? LEVEL_MAX : level_q;

  // Scale: multiply by 1024, then divide by 100000
  // To avoid overflow: (level_clamped * 1024) / 100000 ≈ level_clamped / 98
  // More accurate: use shift and add: level * 1024 / 100000 ≈ level * 10 / 1000 ≈ level / 100
  always_comb begin
    // Simple scaling: divide level by ~100 to get 0-1023 range
    // level_clamped / 100 ≈ level_clamped >> 7 (divide by 128, close enough)
    pwm_duty_cycle = level_clamped[PWM_BITS+6:7];  // Take bits [16:7] for 10-bit result
  end

  // PWM counter and comparator
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      pwm_counter_q <= '0;
      analog_out_o  <= 1'b0;
    end else begin
      // Increment PWM counter
      pwm_counter_q <= pwm_counter_q + 1'b1;

      // Generate PWM output: high when counter < duty_cycle
      analog_out_o <= (pwm_counter_q < pwm_duty_cycle);
    end
  end

  //==========================================================================
  // Debug Output
  //==========================================================================
  // LED[5:4]: state_q[1:0] (00=WAIT, 01=READING, 10=COMPUTE, 11=SETTLE)
  // LED[3]: ram_buffer_ready_i
  // LED[2]: sample_accepted
  // LED[1:0]: sample_count_q[1:0] (low bits)
  assign debug_o = {
    state_q[1:0],
    ram_buffer_ready_i,
    sample_accepted,
    sample_count_q[1:0]
  };

endmodule
