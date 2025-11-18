
import fpga_template_pkg::*; 

module fpga_template_top (
        input   clk,
    //---I2C----------- (Disabled - pins used for UART monitors)
        //input   i2c_scl,
        //inout   i2c_sda,
    //---UART----------
        input   uart_rx,    // Pin 70 - RX from USB/FTDI
        output  uart_tx,    // Pin 69 - TX to USB/FTDI
        output  uart_tx_mon,  // Pin 28 - Scope monitor
        output  uart_rx_mon,  // Pin 27 - Scope monitor
    //---UART State Monitors---
        //output  [1:0] rx_state_mon,
        //output  [3:0] proto_state_mon,
        //output  [1:0] tx_state_mon,
    //---Debug---------
        output  [5:0] debug_led,
        input   btn_s1_resetb,     // Button 1 input
        input   btn_s2,            // Button 2 input
    //---I2S sampler outputs MIC---
        output logic       i2s_sck,
        output logic       i2s_ws,
        output logic       buffer_full,
        input  logic       mic_sd_0       // Mikrofon 0 + 1
    );

//--------------------------------------------------------------------------------------------------------
//  Debug LED og registerbank 
//--------------------------------------------------------------------------------------------------------
    // assign debug_led = ~debug_sample_led[5:0];
//--------------------------------------------------------------------------------------------------------
// Debug assign kommandoer
//--------------------------------------------------------------------------------------------------------
    // assign debug_led = sys_cfg.debug_led;
    assign debug_led = sys_cfg.debug_led[5:0];
    // assign debug_led_pin = {5'b11111,btn_s1_reset};
    // assign debug_led_pin = ram_out[0][5:0];
    // assign sys_cfg.debug_led[5:0] = ram_out[0][5:0];
    // assign sampler_cfg.chanel0_lsb = ram_out[0][7:0];
    // assign sampler_cfg.chanel1_lsb = ram_out[0][15:8];
    // assign sampler_cfg.chanel2_lsb = ram_out[0][23:16];
    // assign sampler_cfg.chanel3_lsb = ram_out[0][31:24];
    // assign sampler_cfg.chanel0_lsb = ram_out[0][7:0];
    // assign sampler_cfg.chanel6_lsb = mic_samples[0][7:0];
    // assign sampler_cfg.chanel4_lsb = mic_samples[0][7:0];

//--------------------------------------------------------------------------------------------------------
//  Sampler
//--------------------------------------------------------------------------------------------------------
    wire [23:0] debug_sample_l, debug_sample_r;
    wire [5:0] debug_sample_led;

    i2s_capture_24 u_sampler (
        .clk_i     (clk),                        
        .rst_ni    (resetb),                     
        .sck_i     (i2s_sck),                    
        .ws_i      (i2s_ws),                     
        .sd_i      (mic_sd_0),              
        .left_o    (debug_sample_l),  
        .right_o   (debug_sample_r),    
        .ready_o   (buffer_full)        
    );

    vu_meter_6led vu (
        .clk_i          (clk),
        .rst_ni         (resetb),
        .sample_stb_i   (buffer_full), 
        .left_sample_i  (debug_sample_l),
        .right_sample_i (debug_sample_r),
        .leds_o         (debug_sample_led) 
    );

//--------------------------------------------------------------------------------------------------------
// Clock Generator
//--------------------------------------------------------------------------------------------------------

    // Generate I2S clock
    i2s_clock_gen u_i2s_clock (
        .clk_i         (clk),
        .rst_ni        (resetb),
        .sck_o         (i2s_sck),
        .ws_o          (i2s_ws),
        .frame_start_o ( )
    );

//--------------------------------------------------------------------------------------------------------
// Communication subsystem (UART, register bank, debug)
//--------------------------------------------------------------------------------------------------------
    rb_sys_cfg_wire_t sys_cfg;
    rb_dsp_cfg_wire_t dsp_cfg;
    rb_sampler_cfg_wire_t sampler_cfg;
    wire resetb = ~btn_s1_resetb;

    fpga_template_comm u_comm (
        .clk            (clk),
        .btn_s1_resetb  (btn_s1_resetb),
        .btn_s2         (btn_s2),
        .uart_rx        (uart_rx),
        .uart_tx        (uart_tx),
        .uart_tx_mon    (uart_tx_mon),
        .uart_rx_mon    (uart_rx_mon),
        .sys_cfg        (sys_cfg),
        .sampler_cfg    (sampler_cfg),
        .dsp_cfg        (dsp_cfg)
    );
//--------------------------------------------------------------------------------------------------------

endmodule