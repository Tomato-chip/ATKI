// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfpga_template_top_tb__Syms.h"


VL_ATTR_COLD void Vfpga_template_top_tb___024root__trace_init_sub__TOP__0(Vfpga_template_top_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("fpga_template_top_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declDouble(c+76,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+78,0,"CLK_FREQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+80,0,"NUM_TEST_SAMPLES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+81,0,"RAM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+60,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"debug_led",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+61,0,"btn_s1_resetb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"btn_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"i2s_sck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"i2s_ws",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"mic_sd_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"buffer_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"sample_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+65,0,"buffer_swap_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+66,0,"handshake_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+67,0,"ready_low_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+68,0,"monitor_handshake",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+82,0,"test_audio_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+57,0,"bit_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+58,0,"left_shift_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+59,0,"right_shift_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+69,0,"left_sample",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+70,0,"right_sample",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+71,0,"prev_sample_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+72,0,"prev_leds",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+60,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"debug_led",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+61,0,"btn_s1_resetb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"btn_s2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"i2s_sck",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"i2s_ws",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"mic_sd_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"buffer_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"resetb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"sample_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+9,0,"sample_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+10,0,"debug_sample_led",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+11,0,"sampler_to_ram_32_data_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+12,0,"sampler_to_ram_write_request_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"ram_to_6led_32_data_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+14,0,"ram_to_6led_read_valid_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"ram_to_6led_read_ready_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"ram_to_6led_buffer_ready_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_i2s_clock", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+83,0,"SYS_CLK_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+84,0,"SCK_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+85,0,"SCKS_PER_FRAME",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+86,0,"WS_POL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+87,0,"FRAME_PULSE_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+60,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"sck_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"ws_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"frame_start_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+88,0,"SCK_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+89,0,"WS_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+90,0,"SCK_CTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+91,0,"WS_CTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+92,0,"SCK_HALF_HIGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+92,0,"SCK_HALF_LOW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+18,0,"sck_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+6,0,"sck_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"sck_tick",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"sck_falling_edge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"sck_prev_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"ws_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+63,0,"ws_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"frame_start_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+22,0,"sck_period_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+23,0,"sck_last_toggle_time",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_ram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+85,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+94,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+92,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+60,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"write_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+12,0,"write_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"write_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"read_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+15,0,"read_ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"read_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"buffer_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"buffer_overflow_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"write_count_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+26,0,"read_count_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+27,0,"write_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+28,0,"read_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+25,0,"write_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+26,0,"read_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+29,0,"write_buffer_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"read_buffer_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"read_buffer_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"write_buffer_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"read_in_progress",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"write_accepted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"read_accepted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"ram0_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+37,0,"ram1_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBit(c+38,0,"ram0_write_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"ram1_write_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+73,0,"ram0_data_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"ram1_data_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_ram0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+60,0,"CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"CE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"OCE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"RESET",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"WRE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"BLKSEL",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+36,0,"AD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+11,0,"DI",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"DO",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"BIT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"READ_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+100,0,"WRITE_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+97,0,"BLK_SEL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+101,0,"RESET_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+102,0,"INIT_RAM_00",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+110,0,"MEM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"do_pipeline",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+112,0,"data_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_ram1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+60,0,"CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"CE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"OCE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"RESET",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"WRE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"BLKSEL",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+37,0,"AD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+11,0,"DI",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"DO",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"BIT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"READ_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+100,0,"WRITE_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+97,0,"BLK_SEL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+101,0,"RESET_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+102,0,"INIT_RAM_00",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+110,0,"MEM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"do_pipeline",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+112,0,"data_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_sampler", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+60,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"sck_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"ws_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"sd_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"left_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+9,0,"right_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+12,0,"ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"sck_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"ws_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"sck_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"ws_edge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"shift25_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+45,0,"cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+46,0,"left_done_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"right_done_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"channel_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("vu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+87,0,"SELECT_LEFT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+113,0,"DECAY_SHIFT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+114,0,"SCALE_SHIFT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+115,0,"TH1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+116,0,"TH2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+117,0,"TH3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+118,0,"TH4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+119,0,"TH5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+120,0,"TH6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+121,0,"LED_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+60,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"ram_read_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+14,0,"ram_read_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"ram_read_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"ram_buffer_ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"leds_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+49,0,"sample",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+35,0,"sample_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"ram_read_accepted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"ram_ready_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"processing_delay_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"mag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+52,0,"level_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"div_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 19,0);
    tracep->declBit(c+54,0,"tick",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"leds_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vfpga_template_top_tb___024root__trace_init_top(Vfpga_template_top_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root__trace_init_top\n"); );
    // Body
    Vfpga_template_top_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vfpga_template_top_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vfpga_template_top_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfpga_template_top_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfpga_template_top_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vfpga_template_top_tb___024root__trace_register(Vfpga_template_top_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vfpga_template_top_tb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vfpga_template_top_tb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vfpga_template_top_tb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vfpga_template_top_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vfpga_template_top_tb___024root__trace_const_0_sub_0(Vfpga_template_top_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vfpga_template_top_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root__trace_const_0\n"); );
    // Init
    Vfpga_template_top_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfpga_template_top_tb___024root*>(voidSelf);
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vfpga_template_top_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<8>/*255:0*/ Vfpga_template_top_tb__ConstPool__CONST_h9e67c271_0;

VL_ATTR_COLD void Vfpga_template_top_tb___024root__trace_const_0_sub_0(Vfpga_template_top_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullDouble(oldp+76,(3.70369999999999990e+01));
    bufp->fullDouble(oldp+78,(2.70000000000000000e+07));
    bufp->fullIData(oldp+80,(0x50U),32);
    bufp->fullIData(oldp+81,(0x10U),32);
    bufp->fullIData(oldp+82,(vlSelf->fpga_template_top_tb__DOT__test_audio_value),24);
    bufp->fullIData(oldp+83,(0x19bfcc0U),32);
    bufp->fullIData(oldp+84,(8U),32);
    bufp->fullIData(oldp+85,(0x20U),32);
    bufp->fullBit(oldp+86,(0U));
    bufp->fullBit(oldp+87,(1U));
    bufp->fullIData(oldp+88,(0x337f98U),32);
    bufp->fullIData(oldp+89,(0x19bfcU),32);
    bufp->fullIData(oldp+90,(3U),32);
    bufp->fullIData(oldp+91,(6U),32);
    bufp->fullIData(oldp+92,(4U),32);
    bufp->fullBit(oldp+93,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_tick));
    bufp->fullIData(oldp+94,(0x10U),32);
    bufp->fullBit(oldp+95,(1U));
    bufp->fullBit(oldp+96,(0U));
    bufp->fullCData(oldp+97,(0U),3);
    bufp->fullIData(oldp+98,(0x20U),32);
    bufp->fullBit(oldp+99,(0U));
    bufp->fullCData(oldp+100,(0U),2);
    bufp->fullIData(oldp+101,(0x53594e43U),32);
    bufp->fullWData(oldp+102,(Vfpga_template_top_tb__ConstPool__CONST_h9e67c271_0),256);
    bufp->fullIData(oldp+110,(0x200U),32);
    bufp->fullIData(oldp+111,(9U),32);
    bufp->fullIData(oldp+112,(0xffffffffU),32);
    bufp->fullIData(oldp+113,(0xbU),32);
    bufp->fullIData(oldp+114,(0xcU),32);
    bufp->fullIData(oldp+115,(0x3e8U),32);
    bufp->fullIData(oldp+116,(0xbb8U),32);
    bufp->fullIData(oldp+117,(0x2328U),32);
    bufp->fullIData(oldp+118,(0x4e20U),32);
    bufp->fullIData(oldp+119,(0x9c40U),32);
    bufp->fullIData(oldp+120,(0x13880U),32);
    bufp->fullIData(oldp+121,(0x83d60U),32);
}

VL_ATTR_COLD void Vfpga_template_top_tb___024root__trace_full_0_sub_0(Vfpga_template_top_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vfpga_template_top_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root__trace_full_0\n"); );
    // Init
    Vfpga_template_top_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfpga_template_top_tb___024root*>(voidSelf);
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vfpga_template_top_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vfpga_template_top_tb___024root__trace_full_0_sub_0(Vfpga_template_top_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__do_pipeline),32);
    bufp->fullIData(oldp+2,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__i),32);
    bufp->fullIData(oldp+3,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__do_pipeline),32);
    bufp->fullIData(oldp+4,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__i),32);
    bufp->fullCData(oldp+5,((0x3fU & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led)))),6);
    bufp->fullBit(oldp+6,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q));
    bufp->fullBit(oldp+7,(vlSelf->fpga_template_top_tb__DOT__buffer_full));
    bufp->fullIData(oldp+8,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left),24);
    bufp->fullIData(oldp+9,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_right),24);
    bufp->fullCData(oldp+10,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led),6);
    bufp->fullIData(oldp+11,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left),32);
    bufp->fullBit(oldp+12,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w));
    bufp->fullIData(oldp+13,(((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid)
                               ? vlSelf->__VdfgTmp_hb1fddee5__0
                               : 0U)),32);
    bufp->fullBit(oldp+14,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w));
    bufp->fullBit(oldp+15,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__ram_ready_q));
    bufp->fullBit(oldp+16,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w));
    bufp->fullBit(oldp+17,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__frame_start_q));
    bufp->fullCData(oldp+18,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_ctr_q),3);
    bufp->fullBit(oldp+19,(((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q)) 
                            & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q))));
    bufp->fullBit(oldp+20,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q));
    bufp->fullCData(oldp+21,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q),6);
    bufp->fullIData(oldp+22,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_period_cycles),32);
    bufp->fullIData(oldp+23,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_last_toggle_time),32);
    bufp->fullBit(oldp+24,((0x10U > (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count))));
    bufp->fullCData(oldp+25,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count),5);
    bufp->fullCData(oldp+26,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count),5);
    bufp->fullCData(oldp+27,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address),4);
    bufp->fullCData(oldp+28,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address),4);
    bufp->fullBit(oldp+29,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel));
    bufp->fullBit(oldp+30,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_sel));
    bufp->fullBit(oldp+31,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid));
    bufp->fullBit(oldp+32,((0x10U <= (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count))));
    bufp->fullBit(oldp+33,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress));
    bufp->fullBit(oldp+34,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted));
    bufp->fullBit(oldp+35,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__sample_valid));
    bufp->fullSData(oldp+36,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address),14);
    bufp->fullSData(oldp+37,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address),14);
    bufp->fullBit(oldp+38,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_write_enable));
    bufp->fullBit(oldp+39,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_write_enable));
    bufp->fullSData(oldp+40,((0xffU & ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address) 
                                       >> 5U))),9);
    bufp->fullSData(oldp+41,((0xffU & ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address) 
                                       >> 5U))),9);
    bufp->fullBit(oldp+42,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_d));
    bufp->fullBit(oldp+43,(((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q)) 
                            & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q))));
    bufp->fullIData(oldp+44,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q),25);
    bufp->fullCData(oldp+45,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q),6);
    bufp->fullBit(oldp+46,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q));
    bufp->fullBit(oldp+47,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q));
    bufp->fullBit(oldp+48,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__channel_q));
    bufp->fullIData(oldp+49,(vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i),24);
    bufp->fullBit(oldp+50,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q));
    bufp->fullIData(oldp+51,((0xffffffU & (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid) 
                                            & (vlSelf->__VdfgTmp_hb1fddee5__0 
                                               >> 0x17U))
                                            ? ((IData)(1U) 
                                               + (~ vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i))
                                            : vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i))),24);
    bufp->fullIData(oldp+52,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q),32);
    bufp->fullIData(oldp+53,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q),20);
    bufp->fullBit(oldp+54,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__tick));
    bufp->fullCData(oldp+55,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next),6);
    bufp->fullBit(oldp+56,(vlSelf->fpga_template_top_tb__DOT__mic_sd_0));
    bufp->fullIData(oldp+57,(vlSelf->fpga_template_top_tb__DOT__bit_counter),32);
    bufp->fullIData(oldp+58,(vlSelf->fpga_template_top_tb__DOT__left_shift_reg),25);
    bufp->fullIData(oldp+59,(vlSelf->fpga_template_top_tb__DOT__right_shift_reg),25);
    bufp->fullBit(oldp+60,(vlSelf->fpga_template_top_tb__DOT__clk));
    bufp->fullBit(oldp+61,(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb));
    bufp->fullBit(oldp+62,(vlSelf->fpga_template_top_tb__DOT__btn_s2));
    bufp->fullBit(oldp+63,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q));
    bufp->fullIData(oldp+64,(vlSelf->fpga_template_top_tb__DOT__sample_count),32);
    bufp->fullIData(oldp+65,(vlSelf->fpga_template_top_tb__DOT__buffer_swap_count),32);
    bufp->fullIData(oldp+66,(vlSelf->fpga_template_top_tb__DOT__handshake_count),32);
    bufp->fullIData(oldp+67,(vlSelf->fpga_template_top_tb__DOT__ready_low_cycles),32);
    bufp->fullBit(oldp+68,(vlSelf->fpga_template_top_tb__DOT__monitor_handshake));
    bufp->fullIData(oldp+69,(vlSelf->fpga_template_top_tb__DOT__left_sample),24);
    bufp->fullIData(oldp+70,(vlSelf->fpga_template_top_tb__DOT__right_sample),24);
    bufp->fullBit(oldp+71,(vlSelf->fpga_template_top_tb__DOT__prev_sample_valid));
    bufp->fullCData(oldp+72,(vlSelf->fpga_template_top_tb__DOT__prev_leds),6);
    bufp->fullIData(oldp+73,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_data_out),32);
    bufp->fullIData(oldp+74,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_data_out),32);
    bufp->fullBit(oldp+75,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_edge));
}
