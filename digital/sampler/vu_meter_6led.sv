// ===============================================================
// vu_meter_6led.sv
// Enkel 6-LED VU-meter med RAM-buffer handshake interface
// Læser samples fra pingpong_sp_ram via read handshake
// ===============================================================
module vu_meter_6led #(
  parameter int SAMPLE_WIDTH   = 16,         // Bredde af RAM samples
  parameter int DECAY_SHIFT    = 11,         // større = langsommere fald (12..13 = mere træg)
  parameter int SCALE_SHIFT    = 2,          // større = mindre følsom; justér 0..4 for 16-bit
  // faste tærskler — justeret for 16-bit samples
  parameter int unsigned TH1   = 16'd100,
  parameter int unsigned TH2   = 16'd300,
  parameter int unsigned TH3   = 16'd900,
  parameter int unsigned TH4   = 16'd2000,
  parameter int unsigned TH5   = 16'd4000,
  parameter int unsigned TH6   = 16'd8000,
  // LED-opdatering ~50 Hz ved 27 MHz: 27e6 / 540000 ≈ 50
  parameter int LED_DIV        = 540000
)(
  input  logic                      clk_i,          // 27 MHz
  input  logic                      rst_ni,

  // RAM handshake interface
  input  logic                      buffer_ready_i,  // puls når ny buffer er klar
  input  logic                      read_enable_i,   // HIGH = data tilgængelig
  input  logic [SAMPLE_WIDTH-1:0]   ram_sample_i,    // sample data fra RAM
  output logic                      read_ack_o,      // puls for at læse næste sample

  output logic [5:0]                leds_o
);
  // RAM read control state machine
  typedef enum logic [1:0] {
    IDLE,       // Venter på buffer_ready_i
    READING,    // Læser samples fra RAM
    DONE        // Færdig med at læse buffer
  } read_state_t;

  read_state_t read_state_q;
  logic read_req;  // Intern anmodning om at læse næste sample

  // Sample processing
  logic signed [SAMPLE_WIDTH-1:0] sample;
  assign sample = ram_sample_i;

  // Absolutværdi (unsigned) - håndterer både 16-bit og 24-bit
  logic [SAMPLE_WIDTH-1:0] mag;
  always_comb begin
    mag = sample[SAMPLE_WIDTH-1] ? (~sample + 1'b1) : sample;
  end

  // RAM read state machine
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      read_state_q <= IDLE;
      read_ack_o   <= 1'b0;
    end else begin
      read_ack_o <= 1'b0;  // Default: ingen ACK

      case (read_state_q)
        IDLE: begin
          // Vent på at buffer er klar
          if (buffer_ready_i) begin
            read_state_q <= READING;
            read_ack_o   <= 1'b1;  // Start med at læse første sample
          end
        end

        READING: begin
          if (!read_enable_i) begin
            // Buffer er færdiglæst
            read_state_q <= DONE;
          end else begin
            // Læs næste sample (throttle: læs hvert 16. clock for ikke at overbelaste)
            // For fuld hastighed, fjern tælleren og læs hver clock
            read_ack_o <= 1'b1;
          end
        end

        DONE: begin
          // Vent på næste buffer_ready_i
          if (buffer_ready_i) begin
            read_state_q <= READING;
            read_ack_o   <= 1'b1;
          end
        end

        default: read_state_q <= IDLE;
      endcase
    end
  end

  // Leaky integrator (glidende middel)
  // Opdateres ved hver læst sample
  logic [31:0] level_q;
  logic sample_valid;
  assign sample_valid = (read_state_q == READING) && read_enable_i;

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      level_q <= 32'd0;
    end else if (sample_valid && read_ack_o) begin
      // level = level - (level >> DECAY) + (mag >> SCALE)
      level_q <= level_q - (level_q >> DECAY_SHIFT)
                          + (mag >> SCALE_SHIFT);
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
