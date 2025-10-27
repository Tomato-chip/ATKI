// ============================================================================
// fpga_template_top - FPGA I2S Audio Capture System
// ============================================================================
// Top-level module integrating:
//   - I2S clock generation and audio capture (24-bit samples)
//   - Ping-pong RAM buffering (256 samples per buffer)
//   - VU meter with 6-LED output
//
// Data Flow:
//   I2S Mic -> i2s_capture_24 -> RAM Ping-Pong Buffer -> VU Meter -> LEDs
//
// Reset: Tang Nano 20K button pulls HIGH when pressed (inverted to active-high)
// ============================================================================

// import fpga_template_pkg::*; 

module fpga_template_top (
    input   clk,
    //---I2C----------- (Disabled - pins used for UART monitors)
        //input   i2c_scl,
        //inout   i2c_sda,
    //---UART----------
        // input   uart_rx,    // Pin 70 - RX from USB/FTDI
        // output  uart_tx,    // Pin 69 - TX to USB/FTDI
        // output  uart_tx_mon,  // Pin 28 - Scope monitor
        // output  uart_rx_mon,  // Pin 27 - Scope monitor
    //---UART State Monitors---
        //output  [1:0] rx_state_mon,
        //output  [3:0] proto_state_mon,
        //output  [1:0] tx_state_mon,

    //---PWM-----------
        // output pwm_out,
    //---Debug---------
        output  [5:0] debug_led,
        input   btn_s1_resetb,     // Button 1 input
        input   btn_s2,            // Button 2 input
    //---I2S sampler outputs MIC---
        output logic       i2s_sck,
        output logic       i2s_ws,
        input  logic       mic_sd_0,      // Mikrofon 0 + 1

        output logic       buffer_full

        // input  logic mic_sd_1,       // Mikrofon 2 + 3
        // input  logic mic_sd_2,       // Mikrofon 4 + 5
        // input  logic mic_sd_3        // Mikrofon 6 +(7)
    );

//--------------------------------------------------------------------------------------------------------
//  Debug LED og registerbank 
//--------------------------------------------------------------------------------------------------------


    assign debug_led = ~debug_sample_led[5:0];


    wire [23:0] sample_left, sample_right;
    wire [5:0]  debug_sample_led;
//--------------------------------------------------------------------------------------------------------
//  Inter-module wiring
//--------------------------------------------------------------------------------------------------------
    // Sampler -> RAM path (write interface)
    logic [31:0] sampler_to_ram_32_data_w;      // 32-bit data: {8'b0, sample_left[23:0]}
    logic        sampler_to_ram_write_request_w; // Write valid from sampler

    // RAM -> VU Meter path (read interface)
    logic [31:0] ram_to_6led_32_data_w;         // 32-bit read data from RAM
    logic        ram_to_6led_read_valid_w;      // Read data valid
    logic        ram_to_6led_read_ready_w;      // VU meter ready to consume
    logic        ram_to_6led_buffer_ready_w;    // Buffer swap signal

    // Zero-pad 24-bit sample to 32-bit RAM word
    assign sampler_to_ram_32_data_w = {8'b00000000, sample_left};    // Pad to 32-bit
    // always_ff @(posedge clk_i) begin
    //     if (!rst_ni) begin
    //         sampler_to_ram_32_data_w <= '0;
    //         ram_to_6led_32_data_w    <= '0;      
    //     end
    // end
//--------------------------------------------------------------------------------------------------------

    i2s_capture_24 u_sampler (
        .clk_i     (clk),               // input
        .rst_ni    (resetb),            // input
        .sck_i     (i2s_sck),           // input
        .ws_i      (i2s_ws),            // input
        .sd_i      (mic_sd_0),          // input
        .left_o    (sample_left),  // output [23:0]
        .right_o   (sample_right),      // output [23:0]
        .ready_o   (sampler_to_ram_write_request_w)        // output
    );



    ram_logic #(
        .DEPTH(256)  // ✅ Circular buffer mode: Always readable, provides natural smoothing
    ) u_ram (
        .clk_i              (clk),
        .rst_ni             (resetb),       // Active-low synchronous reset
        .write_data_i       (sampler_to_ram_32_data_w),
        .write_valid_i      (sampler_to_ram_write_request_w),       // Write request
        .write_ready_o      (),             // Ready to accept write
        .read_data_o        (ram_to_6led_32_data_w),
        .read_ready_i       (ram_to_6led_read_ready_w),             // Reader ready for data
        .read_valid_o       (ram_to_6led_read_valid_w),             // Read data valid
        .buffer_ready_o     (ram_to_6led_buffer_ready_w),           // Pulse: full buffer ready for reading
        .buffer_overflow_o  (buffer_full),   // Error: write to full system (drives top-level output)
        .write_count_o      (),              // Current write buffer fill level
        .read_count_o       ()               // Current read buffer position
    );

    // VU-meter på KUN én kanal (vælg her: 1=venstre, 0=højre)
    vu_meter_6led #(
        .USE_RAM_IF(1'b1)  // ✅ RAM mode - use buffered data
    ) vu (
        .clk_i          (clk),
        .rst_ni         (resetb),
        .sample_valid_i (sampler_to_ram_write_request_w), // Not used in RAM mode
        .left_sample_i  (sample_left),                    // Not used in RAM mode
        .right_sample_i (sample_right),                   // Not used in RAM mode
        .leds_o         (debug_sample_led),        // forbind til dine 6 LED pins i .cst

        .ram_read_data_i     (ram_to_6led_32_data_w[23:0]),       // From ram_logic.read_data_o
        .ram_read_valid_i    (ram_to_6led_read_valid_w),          // From ram_logic.read_valid_o
        .ram_read_ready_o    (ram_to_6led_read_ready_w),          // To ram_logic.read_ready_i
        .ram_buffer_ready_i  (ram_to_6led_buffer_ready_w)         // From ram_logic.buffer_ready_o
    );

//--------------------------------------------------------------------------------------------------------
// Clock Generator
//--------------------------------------------------------------------------------------------------------

    // Generate I2S clock
    i2s_clock_gen u_i2s_clock (
        .clk_i        ( clk),
        .rst_ni       ( resetb),
        .sck_o         ( i2s_sck),
        .ws_o          ( i2s_ws),
        .frame_start_o ( )
    );

//--------------------------------------------------------------------------------------------------------
//  assign uart_rx
//--------------------------------------------------------------------------------------------------------
    // UART monitor assignments for scope debugging
    // assign uart_rx_mon = uart_rx;
    // wire debug_rx_data_valid;

    // // Clock divider to verify clock is running
    // reg [20:0] clk_div_counter;
    // always @(posedge clk) begin
    //     if (!resetb)
    //         clk_div_counter <= 0;
    //     else
    //         clk_div_counter <= clk_div_counter + 1;
    // end

    // // TX monitor shows divided clock (~25.8 Hz at 27MHz)
    // assign uart_tx_mon = clk_div_counter[20]; 

    // assign debug_led = ~sys_cfg.debug_led; // Inverted for Tang Nano 20K active-LOW LEDs

//--------------------------------------------------------------------------------------------------------
// Clock and reset
//--------------------------------------------------------------------------------------------------------

    // Reset button behavior differs between boards:
    // Tang Nano 9K:  Button pulls LOW when pressed  (active LOW)
    // Tang Nano 20K: Button pulls HIGH when pressed (active HIGH)
    wire resetb;
        assign resetb = ~btn_s1_resetb;   // 20K: button HIGH when pressed

    // `ifdef TANGNANO20K
    //     assign resetb = ~btn_s1_resetb;   // 20K: button HIGH when pressed
    // `elsif TANGNANO9K
    //     assign resetb = btn_s1_resetb;    // 9K: button LOW when pressed, invert to get active high reset
    // `else
    //     assign resetb = ~btn_s1_resetb;   // Default to 20K behavior
    // `endif 

    // Direct clock insert PLL here when needed

//--------------------------------------------------------------------------------------------------------
// Register bank structs  
//--------------------------------------------------------------------------------------------------------
    // rb_sys_cfg_wire_t sys_cfg;
    // assign sys_cfg.monitor_flag = 1'b0;

    // rb_dsp_cfg_wire_t dsp_cfg;

//--------------------------------------------------------------------------------------------------------
// Interface signals (shared between I2C and UART)
//--------------------------------------------------------------------------------------------------------
    // wire [7:0] rb_address;
    // wire [7:0] rb_data_write_to_reg;
    // wire [7:0] rb_data_read_from_reg;
    // wire rb_reg_en;
    // wire rb_write_en;
    // wire [1:0] rb_streamSt_mon;

    // // I2C interface signals
    // wire [7:0] i2c_address;
    // wire [7:0] i2c_data_write_to_reg;
    // wire i2c_reg_en;
    // wire i2c_write_en;
    // wire [1:0] i2c_streamSt_mon;

    // // UART interface signals
    // wire [7:0] uart_address;
    // wire [7:0] uart_data_write_to_reg;
    // wire uart_reg_en;
    // wire uart_write_en;
    // wire [1:0] uart_streamSt_mon;
    // wire [7:0] uart_debug_out;
    // wire [1:0] uart_tx_state_mon;  // Keep TX state from being optimized away

    // // Debug UART signals
    // assign debug_uart_send = debug_send;
    // assign debug_uart_data = debug_byte;

//--------------------------------------------------------------------------------------------------------
// I2C interface - DISABLED (pins used for UART monitors)
//--------------------------------------------------------------------------------------------------------
    /*i2c_if i2c_inst (
        .clk                (clk),
        .resetb             (resetb),
        .sda                (i2c_sda),
        .scl                (i2c_scl),
        .address            (i2c_address),
        .data_write_to_reg  (i2c_data_write_to_reg),
        .data_read_from_reg (rb_data_read_from_reg),
        .reg_en             (i2c_reg_en),
        .write_en           (i2c_write_en),
        .streamSt_mon       (i2c_streamSt_mon)
    );*/

//--------------------------------------------------------------------------------------------------------
// UART interface
//--------------------------------------------------------------------------------------------------------
    // uart_if uart_inst (
    //     .clk                (clk),
    //     .resetb             (resetb),
    //     .uart_rx            (uart_rx),
    //     .uart_tx            (uart_tx),

    //     .address            (uart_address),
    //     .data_write_to_reg  (uart_data_write_to_reg),
    //     .data_read_from_reg (rb_data_read_from_reg),
    //     .reg_en             (uart_reg_en),
    //     .write_en           (uart_write_en),
    //     .streamSt_mon       (uart_streamSt_mon),
    //     // Debug interface
    //     .debug_send         (debug_uart_send),
    //     .debug_data         (debug_uart_data),
    //     .debug_out          (uart_debug_out),
    //     .debug_rx_data_valid (debug_rx_data_valid),
    //     .rx_state_mon       (),
    //     .proto_state_mon    (),
    //     .tx_state_mon       (uart_tx_state_mon)  // Critical: prevents TX optimization
    // );

//--------------------------------------------------------------------------------------------------------
// Interface arbitration (OR together since only one active at a time)
//--------------------------------------------------------------------------------------------------------
    //assign rb_address = i2c_address | uart_address;
    //assign rb_data_write_to_reg = i2c_data_write_to_reg | uart_data_write_to_reg;
    //assign rb_reg_en = i2c_reg_en | uart_reg_en;
    //assign rb_write_en = i2c_write_en | uart_write_en;

    // assign rb_address           = uart_address;
    // assign rb_data_write_to_reg = uart_data_write_to_reg;
    // assign rb_reg_en            = uart_reg_en;
    // assign rb_write_en          = uart_write_en;
    // assign rb_streamSt_mon      = uart_streamSt_mon; 
//--------------------------------------------------------------------------------------------------------
// Register bank        
//-------------------------------------------------------------------------------------------------------- 
    // rb_fpga_template rb_fpga_template_inst (
    //     .clk                (clk),
    //     .resetb             (resetb),
    //     .address            (rb_address),
    //     .data_write_in      (rb_data_write_to_reg),
    //     .data_read_out      (rb_data_read_from_reg),
    //     .reg_en             (rb_reg_en),
    //     .write_en           (rb_write_en),
    //     .sys_cfg            (sys_cfg),
    //     .dsp_cfg            (dsp_cfg)
    //     ); 

//-------------------------------------------------------------------------------------------------------- 
// pwm            
//-------------------------------------------------------------------------------------------------------- 
    // pwm pwm_inst (
    //     .clock_in(clk),
    //     .reset(!resetb),
    //     .duty_cycle(sys_cfg.pwm_duty),  // 0x80 -> 50% 
    //     .pwm_out(pwm_out)
    // ); 
         
//--------------------------------------------------------------------------------------------------------
// Debug functionality - Button S2 triggers UART debug sequence
//--------------------------------------------------------------------------------------------------------

    // Button debouncing and edge detection for btn_s2
    // reg [2:0] btn_s2_sync;
    // reg btn_s2_prev;
    // wire btn_s2_edge;

    // always @(posedge clk) begin
    //     if (!resetb) begin
    //         btn_s2_sync <= 3'b000;
    //         btn_s2_prev <= 1'b0;
    //     end else begin
    //         btn_s2_sync <= {btn_s2_sync[1:0], btn_s2};
    //         btn_s2_prev <= btn_s2_sync[2];
    //     end
    // end

    // assign btn_s2_edge = btn_s2_sync[2] & ~btn_s2_prev;  // Rising edge

    // // Debug sequence generator
    // reg [3:0] debug_state;
    // reg [15:0] debug_counter;
    // reg [7:0] debug_byte;
    // reg debug_send;
    // reg debug_active;

    // localparam DEBUG_IDLE = 4'h0;
    // localparam DEBUG_START = 4'h1;
    // localparam DEBUG_SEND = 4'h2;
    // localparam DEBUG_WAIT = 4'h3;

    // // Debug sequence: "DBG:" followed by incrementing numbers 0x00 to 0x0F
    // always @(posedge clk) begin
    //     if (!resetb) begin
    //         //debug_led <= 6'b111111;
    //         debug_state <= DEBUG_IDLE;
    //         debug_counter <= 16'h0000;
    //         debug_byte <= 8'h00;
    //         debug_send <= 1'b0;
    //         debug_active <= 1'b0;
    //     end else begin
    //         debug_send <= 1'b0;  // Default

    //         case (debug_state)
    //             DEBUG_IDLE: begin
    //                 if (!btn_s2_edge) begin
    //                     //debug_led <= 6'b000000;
    //                     debug_state <= DEBUG_START;
    //                     debug_counter <= 16'h0000;
    //                     debug_active <= 1'b1;
    //                 end
    //             end

    //             DEBUG_START: begin
    //                 if (debug_counter < 16'h1000) begin  // Prevent timeout
    //                     debug_counter <= debug_counter + 1;

    //                     // Send debug sequence with delays between bytes
    //                     if (debug_counter[15:8] == 8'h00) begin  // First part - send bytes
    //                         case (debug_counter[7:0])
    //                             8'h10: begin debug_byte <= 8'h44; debug_send <= 1'b1; end  // 'D'
    //                             8'h20: begin debug_byte <= 8'h42; debug_send <= 1'b1; end  // 'B'
    //                             8'h30: begin debug_byte <= 8'h47; debug_send <= 1'b1; end  // 'G'
    //                             8'h40: begin debug_byte <= 8'h3A; debug_send <= 1'b1; end  // ':'
    //                             8'h50: begin debug_byte <= 8'h20; debug_send <= 1'b1; end  // ' '
    //                             8'h60: begin debug_byte <= 8'h00; debug_send <= 1'b1; end  // 0x00
    //                             8'h70: begin debug_byte <= 8'h01; debug_send <= 1'b1; end  // 0x01
    //                             8'h80: begin debug_byte <= 8'h02; debug_send <= 1'b1; end  // 0x02
    //                             8'h90: begin debug_byte <= 8'h03; debug_send <= 1'b1; end  // 0x03
    //                             8'hA0: begin debug_byte <= 8'h04; debug_send <= 1'b1; end  // 0x04
    //                             8'hB0: begin debug_byte <= 8'h05; debug_send <= 1'b1; end  // 0x05
    //                             8'hC0: begin debug_byte <= 8'h06; debug_send <= 1'b1; end  // 0x06
    //                             8'hD0: begin debug_byte <= 8'h07; debug_send <= 1'b1; end  // 0x07
    //                             8'hE0: begin debug_byte <= 8'h08; debug_send <= 1'b1; end  // 0x08
    //                             8'hF0: begin debug_byte <= 8'h09; debug_send <= 1'b1; end  // 0x09
    //                             default: begin
    //                                 // Do nothing, just count
    //                             end
    //                         endcase
    //                     end else if (debug_counter[15:8] == 8'h01) begin  // Second part
    //                         case (debug_counter[7:0])
    //                             8'h00: begin debug_byte <= 8'h0A; debug_send <= 1'b1; end  // 0x0A
    //                             8'h10: begin debug_byte <= 8'h0B; debug_send <= 1'b1; end  // 0x0B
    //                             8'h20: begin debug_byte <= 8'h0C; debug_send <= 1'b1; end  // 0x0C
    //                             8'h30: begin debug_byte <= 8'h0D; debug_send <= 1'b1; end  // 0x0D
    //                             8'h40: begin debug_byte <= 8'h0E; debug_send <= 1'b1; end  // 0x0E
    //                             8'h50: begin debug_byte <= 8'h0F; debug_send <= 1'b1; end  // 0x0F
    //                             8'h60: begin debug_byte <= 8'h0D; debug_send <= 1'b1; end  // '\r'
    //                             8'h70: begin debug_byte <= 8'h0A; debug_send <= 1'b1; end  // '\n'
    //                             8'h80: begin
    //                                 debug_state <= DEBUG_IDLE;
    //                                 debug_active <= 1'b0;
    //                             end
    //                             default: begin
    //                                 // Do nothing, just count
    //                             end
    //                         endcase
    //                     end else begin
    //                         // Finished
    //                         debug_state <= DEBUG_IDLE;
    //                         debug_active <= 1'b0;
    //                     end
    //                 end else begin
    //                     // Timeout
    //                     debug_state <= DEBUG_IDLE;
    //                     debug_active <= 1'b0;
    //                 end
    //             end
    //         endcase
    //     end
    // end

//--------------------------------------------------------------------------------------------------------

endmodule
