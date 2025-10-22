// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram_vu_handshake_tb.h for the primary calling header

#include "Vram_vu_handshake_tb__pch.h"
#include "Vram_vu_handshake_tb___024root.h"

VL_ATTR_COLD void Vram_vu_handshake_tb___024root___eval_static__TOP(Vram_vu_handshake_tb___024root* vlSelf);

VL_ATTR_COLD void Vram_vu_handshake_tb___024root___eval_static(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_static\n"); );
    // Body
    Vram_vu_handshake_tb___024root___eval_static__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vram_vu_handshake_tb___024root___eval_static__TOP(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->ram_vu_handshake_tb__DOT__errors = 0U;
    vlSelf->ram_vu_handshake_tb__DOT__warnings = 0U;
    vlSelf->ram_vu_handshake_tb__DOT__sample_count = 0U;
    vlSelf->ram_vu_handshake_tb__DOT__read_count = 0U;
}

VL_ATTR_COLD void Vram_vu_handshake_tb___024root___eval_final(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_vu_handshake_tb___024root___dump_triggers__stl(Vram_vu_handshake_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vram_vu_handshake_tb___024root___eval_phase__stl(Vram_vu_handshake_tb___024root* vlSelf);

VL_ATTR_COLD void Vram_vu_handshake_tb___024root___eval_settle(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_settle\n"); );
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
            Vram_vu_handshake_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("ram_vu_handshake_tb.sv", 16, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vram_vu_handshake_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_vu_handshake_tb___024root___dump_triggers__stl(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vram_vu_handshake_tb___024root___stl_sequent__TOP__0(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__leds_next 
        = ((0x38U & (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__leds_next)) 
           | (((0x384U < vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__level_q) 
               << 2U) | (((0x12cU < vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__level_q) 
                          << 1U) | (0x64U < vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__level_q))));
    vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__leds_next 
        = ((7U & (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__leds_next)) 
           | (((0x1f40U < vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__level_q) 
               << 5U) | (((0xfa0U < vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__level_q) 
                          << 4U) | ((0x7d0U < vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__level_q) 
                                    << 3U))));
    vlSelf->ram_vu_handshake_tb__DOT__read_enable = 
        ((~ (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_in_progress)) 
         & (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__valid_read_out));
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__buffer_full 
        = ((IData)(vlSelf->ram_vu_handshake_tb__DOT__sample_valid) 
           & (0xffU == (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_address)));
    vlSelf->ram_vu_handshake_tb__DOT__read_data = 0U;
    if (vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__valid_read_out) {
        vlSelf->ram_vu_handshake_tb__DOT__read_data 
            = (0xffffU & ((IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_buffer_sel)
                           ? vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__do_pipe
                           : vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__do_pipe));
    }
    if (vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_buffer_sel) {
        vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__0__a8 
            = vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_address;
        vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__0__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__0__a8) 
               << 4U);
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__address_RAM_0 
            = vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__0__Vfuncout;
        vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__1__a8 
            = vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_address;
        vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__1__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__1__a8) 
               << 4U);
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__address_RAM_1 
            = vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__1__Vfuncout;
    } else {
        vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__2__a8 
            = vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_address;
        vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__2__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__2__a8) 
               << 4U);
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__address_RAM_0 
            = vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__2__Vfuncout;
        vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__3__a8 
            = vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_address;
        vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__3__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__3__a8) 
               << 4U);
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__address_RAM_1 
            = vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__3__Vfuncout;
    }
}

VL_ATTR_COLD void Vram_vu_handshake_tb___024root___eval_stl(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vram_vu_handshake_tb___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vram_vu_handshake_tb___024root___eval_triggers__stl(Vram_vu_handshake_tb___024root* vlSelf);

VL_ATTR_COLD bool Vram_vu_handshake_tb___024root___eval_phase__stl(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vram_vu_handshake_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vram_vu_handshake_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_vu_handshake_tb___024root___dump_triggers__act(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge ram_vu_handshake_tb.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([changed] ((32'sh100 <= ram_vu_handshake_tb.read_count) | (~ ram_vu_handshake_tb.read_enable)))\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_vu_handshake_tb___024root___dump_triggers__nba(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge ram_vu_handshake_tb.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([changed] ((32'sh100 <= ram_vu_handshake_tb.read_count) | (~ ram_vu_handshake_tb.read_enable)))\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vram_vu_handshake_tb___024root___ctor_var_reset(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->ram_vu_handshake_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->ram_vu_handshake_tb__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->ram_vu_handshake_tb__DOT__sample_data = VL_RAND_RESET_I(16);
    vlSelf->ram_vu_handshake_tb__DOT__sample_valid = VL_RAND_RESET_I(1);
    vlSelf->ram_vu_handshake_tb__DOT__read_data = VL_RAND_RESET_I(16);
    vlSelf->ram_vu_handshake_tb__DOT__buffer_ready = VL_RAND_RESET_I(1);
    vlSelf->ram_vu_handshake_tb__DOT__read_enable = VL_RAND_RESET_I(1);
    vlSelf->ram_vu_handshake_tb__DOT__read_ack = VL_RAND_RESET_I(1);
    vlSelf->ram_vu_handshake_tb__DOT__leds = VL_RAND_RESET_I(6);
    vlSelf->ram_vu_handshake_tb__DOT__errors = 0;
    vlSelf->ram_vu_handshake_tb__DOT__warnings = 0;
    vlSelf->ram_vu_handshake_tb__DOT__sample_count = 0;
    vlSelf->ram_vu_handshake_tb__DOT__read_count = 0;
    vlSelf->ram_vu_handshake_tb__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->ram_vu_handshake_tb__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_address = VL_RAND_RESET_I(8);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_address = VL_RAND_RESET_I(8);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_count = VL_RAND_RESET_I(9);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_buffer_sel = VL_RAND_RESET_I(1);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_buffer_sel = VL_RAND_RESET_I(1);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__valid_read_out = VL_RAND_RESET_I(1);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_in_progress = VL_RAND_RESET_I(1);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__buffer_full = VL_RAND_RESET_I(1);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__address_RAM_0 = VL_RAND_RESET_I(14);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__address_RAM_1 = VL_RAND_RESET_I(14);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__do_reg = VL_RAND_RESET_I(32);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__do_pipe = VL_RAND_RESET_I(32);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__do_reg = VL_RAND_RESET_I(32);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__do_pipe = VL_RAND_RESET_I(32);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__read_state_q = VL_RAND_RESET_I(2);
    vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__read_req = VL_RAND_RESET_I(1);
    vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__level_q = VL_RAND_RESET_I(32);
    vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__div_q = VL_RAND_RESET_I(10);
    vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__tick = VL_RAND_RESET_I(1);
    vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__leds_next = VL_RAND_RESET_I(6);
    vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__0__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__0__a8 = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__1__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__1__a8 = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__2__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__2__a8 = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__3__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__3__a8 = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__ram_vu_handshake_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr_hbeb878a1__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
