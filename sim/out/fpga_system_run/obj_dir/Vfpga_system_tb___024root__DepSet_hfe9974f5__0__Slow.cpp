// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpga_system_tb.h for the primary calling header

#include "Vfpga_system_tb__pch.h"
#include "Vfpga_system_tb___024root.h"

VL_ATTR_COLD void Vfpga_system_tb___024root___eval_static__TOP(Vfpga_system_tb___024root* vlSelf);

VL_ATTR_COLD void Vfpga_system_tb___024root___eval_static(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_static\n"); );
    // Body
    Vfpga_system_tb___024root___eval_static__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vfpga_system_tb___024root___eval_static__TOP(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->fpga_system_tb__DOT__error_count = 0U;
    vlSelf->fpga_system_tb__DOT__buffer_count = 0U;
    vlSelf->fpga_system_tb__DOT__sample_count = 0U;
}

VL_ATTR_COLD void Vfpga_system_tb___024root___eval_initial__TOP(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->fpga_system_tb__DOT__mic_shift_reg = 0U;
    vlSelf->fpga_system_tb__DOT__bit_counter = 0U;
    vlSelf->fpga_system_tb__DOT__mic_sd = 0U;
    vlSelf->fpga_system_tb__DOT__sck_prev = 0U;
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__i = 0U;
    while (VL_GTS_III(32, 0x200U, vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__i)) {
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem[(0x1ffU 
                                                                   & vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__i)] = 0U;
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__i 
            = ((IData)(1U) + vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__i);
    }
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_data_out = 0U;
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__do_pipeline = 0U;
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x200U, vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__i)) {
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem[(0x1ffU 
                                                                   & vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__i)] = 0U;
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__i 
            = ((IData)(1U) + vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__i);
    }
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_data_out = 0U;
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__do_pipeline = 0U;
}

VL_ATTR_COLD void Vfpga_system_tb___024root___eval_final(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_system_tb___024root___dump_triggers__stl(Vfpga_system_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfpga_system_tb___024root___eval_phase__stl(Vfpga_system_tb___024root* vlSelf);

VL_ATTR_COLD void Vfpga_system_tb___024root___eval_settle(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_settle\n"); );
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
            Vfpga_system_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("fpga_system_tb.sv", 11, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfpga_system_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_system_tb___024root___dump_triggers__stl(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfpga_system_tb___024root___stl_sequent__TOP__0(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__leds_next 
        = ((0x38U & (IData)(vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__leds_next)) 
           | (((0x2328U < vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q) 
               << 2U) | (((0xbb8U < vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q) 
                          << 1U) | (0x3e8U < vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q))));
    vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__leds_next 
        = ((7U & (IData)(vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__leds_next)) 
           | (((0x13880U < vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q) 
               << 5U) | (((0x9c40U < vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q) 
                          << 4U) | ((0x4e20U < vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q) 
                                    << 3U))));
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_accepted 
        = vlSelf->fpga_system_tb__DOT__ram_read_valid;
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__ws_edge 
        = ((IData)(vlSelf->fpga_system_tb__DOT__u_sampler__DOT__ws_d) 
           != (IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q));
    vlSelf->__VdfgTmp_h10302c67__0 = ((IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_buffer_sel)
                                       ? vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_data_out
                                       : vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_data_out);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_accepted 
        = ((0x20U > (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_count)) 
           & (IData)(vlSelf->fpga_system_tb__DOT__sample_ready));
    if (vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_buffer_sel) {
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__4__addr 
            = vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_address;
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__4__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__4__addr) 
               << 5U);
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_address 
            = vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__4__Vfuncout;
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__5__addr 
            = vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_address;
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__5__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__5__addr) 
               << 5U);
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_address 
            = vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__5__Vfuncout;
    } else {
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__6__addr 
            = vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_address;
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__6__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__6__addr) 
               << 5U);
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_address 
            = vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__6__Vfuncout;
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__7__addr 
            = vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_address;
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__7__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__7__addr) 
               << 5U);
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_address 
            = vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__7__Vfuncout;
    }
    vlSelf->fpga_system_tb__DOT____Vcellinp__u_vu_meter__ram_read_data_i 
        = ((IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid)
            ? (0xffffffU & vlSelf->__VdfgTmp_h10302c67__0)
            : 0U);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_write_enable 
        = ((~ (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_buffer_sel)) 
           & (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_accepted));
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_write_enable 
        = ((IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_accepted) 
           & (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_buffer_sel));
}

VL_ATTR_COLD void Vfpga_system_tb___024root___eval_stl(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vfpga_system_tb___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vfpga_system_tb___024root___eval_triggers__stl(Vfpga_system_tb___024root* vlSelf);

VL_ATTR_COLD bool Vfpga_system_tb___024root___eval_phase__stl(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfpga_system_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vfpga_system_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_system_tb___024root___dump_triggers__act(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge fpga_system_tb.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_system_tb___024root___dump_triggers__nba(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge fpga_system_tb.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfpga_system_tb___024root___ctor_var_reset(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->fpga_system_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__mic_sd = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__leds = VL_RAND_RESET_I(6);
    vlSelf->fpga_system_tb__DOT__sample_left = VL_RAND_RESET_I(24);
    vlSelf->fpga_system_tb__DOT__sample_right = VL_RAND_RESET_I(24);
    vlSelf->fpga_system_tb__DOT__sample_ready = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__ram_read_valid = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__ram_buffer_ready = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__ram_overflow = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__error_count = 0;
    vlSelf->fpga_system_tb__DOT__buffer_count = 0;
    vlSelf->fpga_system_tb__DOT__sample_count = 0;
    vlSelf->fpga_system_tb__DOT____Vcellinp__u_vu_meter__ram_read_data_i = VL_RAND_RESET_I(24);
    vlSelf->fpga_system_tb__DOT__mic_shift_reg = VL_RAND_RESET_I(25);
    vlSelf->fpga_system_tb__DOT__bit_counter = VL_RAND_RESET_I(5);
    vlSelf->fpga_system_tb__DOT__sck_prev = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__leds_prev = VL_RAND_RESET_I(6);
    vlSelf->fpga_system_tb__DOT__unnamedblk1__DOT__start_buf_count = 0;
    vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_ctr_q = VL_RAND_RESET_I(3);
    vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_tick = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_prev_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_ctr_q = VL_RAND_RESET_I(6);
    vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__frame_start_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__sck_d = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__ws_d = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__ws_edge = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__shift25_q = VL_RAND_RESET_I(25);
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__cnt_q = VL_RAND_RESET_I(6);
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__left_done_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__right_done_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__channel_q = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_address = VL_RAND_RESET_I(5);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_address = VL_RAND_RESET_I(5);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_count = VL_RAND_RESET_I(6);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_count = VL_RAND_RESET_I(6);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_buffer_sel = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_buffer_sel = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_in_progress = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_accepted = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_accepted = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_address = VL_RAND_RESET_I(14);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_address = VL_RAND_RESET_I(14);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_write_enable = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_write_enable = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_data_out = VL_RAND_RESET_I(32);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_data_out = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__do_pipeline = VL_RAND_RESET_I(32);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__do_pipeline = VL_RAND_RESET_I(32);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q = VL_RAND_RESET_I(32);
    vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__div_q = VL_RAND_RESET_I(10);
    vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__tick = VL_RAND_RESET_I(1);
    vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__leds_next = VL_RAND_RESET_I(6);
    vlSelf->__VdfgTmp_h10302c67__0 = 0;
    vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__4__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__4__addr = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__5__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__5__addr = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__6__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__6__addr = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__7__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__7__addr = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigprevexpr___TOP__fpga_system_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
