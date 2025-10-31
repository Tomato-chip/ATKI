// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpga_template_top_tb.h for the primary calling header

#include "Vfpga_template_top_tb__pch.h"
#include "Vfpga_template_top_tb___024root.h"

VL_ATTR_COLD void Vfpga_template_top_tb___024root___eval_static(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vfpga_template_top_tb___024root___eval_final(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_template_top_tb___024root___dump_triggers__stl(Vfpga_template_top_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfpga_template_top_tb___024root___eval_phase__stl(Vfpga_template_top_tb___024root* vlSelf);

VL_ATTR_COLD void Vfpga_template_top_tb___024root___eval_settle(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vfpga_template_top_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("fpga_template_top_tb.sv", 17, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfpga_template_top_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_template_top_tb___024root___dump_triggers__stl(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfpga_template_top_tb___024root___stl_sequent__TOP__0(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next 
        = ((0x38U & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next)) 
           | (((0x2328U < vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q) 
               << 2U) | (((0xbb8U < vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q) 
                          << 1U) | (0x3e8U < vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q))));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next 
        = ((7U & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next)) 
           | (((0x13880U < vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q) 
               << 5U) | (((0x9c40U < vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q) 
                          << 4U) | ((0x4e20U < vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q) 
                                    << 3U))));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_edge 
        = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_d) 
           != (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__sample_valid 
        = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w) 
           & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__ram_ready_q));
    vlSelf->__VdfgTmp_hb1fddee5__0 = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_sel)
                                       ? vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_data_out
                                       : vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_data_out);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted 
        = ((0x10U > (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count)) 
           & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w));
    if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel) {
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__0__addr 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__0__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__0__addr) 
               << 5U);
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address 
            = vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__0__Vfuncout;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__1__addr 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__1__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__1__addr) 
               << 5U);
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address 
            = vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__1__Vfuncout;
    } else {
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__2__addr 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__2__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__2__addr) 
               << 5U);
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address 
            = vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__2__Vfuncout;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__3__addr 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__3__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__3__addr) 
               << 5U);
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address 
            = vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__3__Vfuncout;
    }
    vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i 
        = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid)
            ? (0xffffffU & vlSelf->__VdfgTmp_hb1fddee5__0)
            : 0U);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_write_enable 
        = ((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel)) 
           & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_write_enable 
        = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted) 
           & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel));
}

VL_ATTR_COLD void Vfpga_template_top_tb___024root___eval_stl(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vfpga_template_top_tb___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vfpga_template_top_tb___024root___eval_triggers__stl(Vfpga_template_top_tb___024root* vlSelf);

VL_ATTR_COLD bool Vfpga_template_top_tb___024root___eval_phase__stl(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfpga_template_top_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vfpga_template_top_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_template_top_tb___024root___dump_triggers__act(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(negedge fpga_template_top_tb.btn_s1_resetb or posedge fpga_template_top_tb.dut.u_i2s_clock.sck_q)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge fpga_template_top_tb.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([changed] fpga_template_top_tb.btn_s1_resetb)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(negedge fpga_template_top_tb.dut.u_i2s_clock.ws_q)\n");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @(posedge fpga_template_top_tb.dut.sampler_to_ram_write_request_w)\n");
    }
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @(posedge fpga_template_top_tb.dut.ram_to_6led_buffer_ready_w)\n");
    }
    if ((0x80ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @(posedge fpga_template_top_tb.buffer_full)\n");
    }
    if ((0x100ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @([changed] (32'sh50 <= fpga_template_top_tb.sample_count))\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_template_top_tb___024root___dump_triggers__nba(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(negedge fpga_template_top_tb.btn_s1_resetb or posedge fpga_template_top_tb.dut.u_i2s_clock.sck_q)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge fpga_template_top_tb.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([changed] fpga_template_top_tb.btn_s1_resetb)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(negedge fpga_template_top_tb.dut.u_i2s_clock.ws_q)\n");
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @(posedge fpga_template_top_tb.dut.sampler_to_ram_write_request_w)\n");
    }
    if ((0x40ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @(posedge fpga_template_top_tb.dut.ram_to_6led_buffer_ready_w)\n");
    }
    if ((0x80ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @(posedge fpga_template_top_tb.buffer_full)\n");
    }
    if ((0x100ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @([changed] (32'sh50 <= fpga_template_top_tb.sample_count))\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfpga_template_top_tb___024root___ctor_var_reset(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->fpga_template_top_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__btn_s2 = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__mic_sd_0 = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__buffer_full = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__sample_count = 0;
    vlSelf->fpga_template_top_tb__DOT__buffer_swap_count = 0;
    vlSelf->fpga_template_top_tb__DOT__handshake_count = 0;
    vlSelf->fpga_template_top_tb__DOT__ready_low_cycles = 0;
    vlSelf->fpga_template_top_tb__DOT__monitor_handshake = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__test_audio_value = VL_RAND_RESET_I(24);
    vlSelf->fpga_template_top_tb__DOT__bit_counter = 0;
    vlSelf->fpga_template_top_tb__DOT__left_shift_reg = VL_RAND_RESET_I(25);
    vlSelf->fpga_template_top_tb__DOT__right_shift_reg = VL_RAND_RESET_I(25);
    vlSelf->fpga_template_top_tb__DOT__left_sample = VL_RAND_RESET_I(24);
    vlSelf->fpga_template_top_tb__DOT__right_sample = VL_RAND_RESET_I(24);
    vlSelf->fpga_template_top_tb__DOT__prev_sample_valid = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__prev_leds = VL_RAND_RESET_I(6);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left = VL_RAND_RESET_I(24);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_right = VL_RAND_RESET_I(24);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led = VL_RAND_RESET_I(6);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i = VL_RAND_RESET_I(24);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_d = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_edge = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q = VL_RAND_RESET_I(25);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q = VL_RAND_RESET_I(6);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__channel_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address = VL_RAND_RESET_I(4);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address = VL_RAND_RESET_I(4);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count = VL_RAND_RESET_I(5);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count = VL_RAND_RESET_I(5);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_sel = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address = VL_RAND_RESET_I(14);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address = VL_RAND_RESET_I(14);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_write_enable = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_write_enable = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_data_out = VL_RAND_RESET_I(32);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_data_out = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__do_pipeline = VL_RAND_RESET_I(32);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__do_pipeline = VL_RAND_RESET_I(32);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__sample_valid = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__ram_ready_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q = VL_RAND_RESET_I(32);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q = VL_RAND_RESET_I(20);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__tick = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next = VL_RAND_RESET_I(6);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_ctr_q = VL_RAND_RESET_I(3);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_tick = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q = VL_RAND_RESET_I(6);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__frame_start_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_period_cycles = 0;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_last_toggle_time = 0;
    vlSelf->__VdfgTmp_hb1fddee5__0 = 0;
    vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__0__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__0__addr = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__1__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__1__addr = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__2__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__2__addr = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__3__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__3__addr = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__btn_s1_resetb__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__buffer_full__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr_he4466ec5__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
