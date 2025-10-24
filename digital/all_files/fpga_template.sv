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
    assign buffer_full = ram_buffer_ready_w;

//--------------------------------------------------------------------------------------------------------
    

    wire [23:0] debug_sample_l, debug_sample_r;
    wire [5:0]  debug_sample_led;
    wire [15:0] ram_data_w;
    wire        ram_buffer_ready_w;
    wire        ram_read_enable_w;
    wire        ram_read_ack_w;
    wire        sample_ready_w;

    i2s_capture_24 u_sampler (
        .clk_i     (clk),               // input         
        .rst_ni    (resetb),            // input         
        .sck_i     (i2s_sck),           // input         
        .ws_i      (i2s_ws),            // input         
        .sd_i      (mic_sd_0),          // input    
        .left_o    (debug_sample_l),  // output [23:0]   
        .right_o   (debug_sample_r),      // output [23:0]   
        .ready_o   (sample_ready_w)        // output          
    );

    pingpong_sp_ram u_ram (
        .clk_i          (clk),
        .rst_ni         (resetb),
        .sample_i       (debug_sample_l[15:0]),  // Brug øverste 16 bit af venstre kanal
        .sample_ready_i (sample_ready_w),
        .read_data_o    (ram_data_w),
        .buffer_ready_o (ram_buffer_ready_w),
        .read_enable_o  (ram_read_enable_w),
        .read_ack_i     (ram_read_ack_w)
    );


//--------------------------------------------------------------------------------------------------------

    // VU-meter på KUN én kanal (vælg her: 1=venstre, 0=højre)
    vu_meter_6led vu (
        .clk_i          (clk),
        .rst_ni         (resetb),
        .sample_stb_i   (sample_ready_w), // fra cap.ready_o
        .left_sample_i  (debug_sample_l[15:0]),  // Use upper 16 bits of 24-bit sample
        .right_sample_i (debug_sample_r[15:0]),  // Use upper 16 bits of 24-bit sample
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