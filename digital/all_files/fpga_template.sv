// Boiler plate for a midsize fpga project 
// 

import fpga_template_pkg::*; 

module fpga_template_top (
        input   clk,
    //---Debug---------
        output  [5:0] debug_led,
        input   btn_s1_resetb,     // Button 1 input
        input   btn_s2,            // Button 2 input
    //---I2S sampler outputs MIC---
        output logic       i2s_sck,
        output logic       i2s_ws,
        output logic       buffer_full,

        input  logic        mic_sd_0       // Mikrofon 0 + 1
    );

    assign debug_led = ~debug_sample_led[5:0];

//--------------------------------------------------------------------------------------------------------
pingpong_sp_ram u_ram(
    .clk_i              (clk), 
    .rst_ni             (resetb),   
    .sample_i           (debug_sample_l),
    .sample_ready_i     (),
    .read_data_o        (),
    .buffer_ready_o     ()
);  


    
//--------------------------------------------------------------------------------------------------------

    wire [23:0] debug_sample_l, debug_sample_r;
    wire [5:0] debug_sample_led;


    i2s_capture_24 u_sampler (
        .clk_i     (clk),               // input         
        .rst_ni    (resetb),            // input         
        .sck_i     (i2s_sck),           // input         
        .ws_i      (i2s_ws),            // input         
        .sd_i      (mic_sd_0),          // input    
        .left_o    (debug_sample_l),  // output [23:0]   
        .right_o   (debug_sample_r),      // output [23:0]   
        .ready_o   (buffer_full)        // output          
    );
//--------------------------------------------------------------------------------------------------------

    // VU-meter på KUN én kanal (vælg her: 1=venstre, 0=højre)
    vu_meter_6led vu (
        .clk_i          (clk),
        .rst_ni         (resetb),
        .sample_stb_i   (buffer_full), // fra cap.ready_o
        .left_sample_i  (debug_sample_l),
        .right_sample_i (debug_sample_r),
        .leds_o         (debug_sample_led)        // forbind til dine 6 LED pins i .cst
    );
//--------------------------------------------------------------------------------------------------------


    // Generate I2S clock
    i2s_clock_gen u_i2s_clock (
        .clk_i        ( clk   ),
        .rst_ni       ( resetb       ),
        .sck_o         ( i2s_sck     ),
        .ws_o          ( i2s_ws      ),
        .frame_start_o ( )
    );
//--------------------------------------------------------------------------------------------------------

    wire resetb;
    assign resetb = ~btn_s1_resetb;   // 20K: button HIGH when pressed


endmodule