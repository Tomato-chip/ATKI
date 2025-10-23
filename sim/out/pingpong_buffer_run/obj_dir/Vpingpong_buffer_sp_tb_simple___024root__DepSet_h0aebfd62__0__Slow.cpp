// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpingpong_buffer_sp_tb_simple.h for the primary calling header

#include "Vpingpong_buffer_sp_tb_simple__pch.h"
#include "Vpingpong_buffer_sp_tb_simple___024root.h"

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___eval_static__TOP(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___eval_static(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_static\n"); );
    // Body
    Vpingpong_buffer_sp_tb_simple___024root___eval_static__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___eval_static__TOP(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors = 0U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__words_written = 0U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__words_read = 0U;
}

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__i = 0U;
    while ((0x400U > vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__i)) {
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem[(0x3ffU 
                                                                               & vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__i)] = 0U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__i 
            = ((IData)(1U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__i);
    }
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO = 0U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__read_data = 0U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__i = 0U;
    while ((0x400U > vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__i)) {
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem[(0x3ffU 
                                                                               & vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__i)] = 0U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__i 
            = ((IData)(1U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__i);
    }
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO = 0U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__read_data = 0U;
}

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___eval_final(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__stl(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vpingpong_buffer_sp_tb_simple___024root___eval_phase__stl(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___eval_settle(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_settle\n"); );
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
            Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("pingpong_buffer_sp_tb_simple.sv", 6, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vpingpong_buffer_sp_tb_simple___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__stl(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
    if ((2ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] pingpong_buffer_sp_tb_simple.dut.__Vcellout__u_ram0__DO)\n");
    }
    if ((4ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 2 is active: @([hybrid] pingpong_buffer_sp_tb_simple.dut.__Vcellout__u_ram1__DO)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___stl_sequent__TOP__2(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___stl_sequent__TOP__2\n"); );
    // Body
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__read_data;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__read_data;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_has_data 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_sel)
            ? ((2U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state)) 
               | (3U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state)))
            : ((2U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state)) 
               | (3U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state))));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_beat 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_ready) 
           & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_valid));
    if (vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel) {
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__0__addr 
            = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr;
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__0__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__0__addr) 
               << 4U);
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram0 
            = vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__0__Vfuncout;
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__1__addr 
            = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_addr;
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__1__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__1__addr) 
               << 4U);
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram1 
            = vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__1__Vfuncout;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_ready 
            = ((0U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state)) 
               | (1U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state)));
    } else {
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__2__addr 
            = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_addr;
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__2__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__2__addr) 
               << 4U);
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram0 
            = vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__2__Vfuncout;
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__3__addr 
            = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr;
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__3__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__3__addr) 
               << 4U);
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram1 
            = vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__3__Vfuncout;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_ready 
            = ((0U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state)) 
               | (1U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state)));
    }
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_complete 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_beat) 
           & (0xffU == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr)));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_valid) 
           & ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_ready) 
              & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__sample_ready)));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wre_ram0 
        = ((1U & (~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel))) 
           && (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wre_ram1 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel) 
           && (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_complete 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat) 
           & (0xffU == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_addr)));
}

void Vpingpong_buffer_sp_tb_simple___024root___act_sequent__TOP__0(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);
void Vpingpong_buffer_sp_tb_simple___024root___act_sequent__TOP__1(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___eval_stl(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_stl\n"); );
    // Body
    if ((2ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vpingpong_buffer_sp_tb_simple___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((4ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vpingpong_buffer_sp_tb_simple___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vpingpong_buffer_sp_tb_simple___024root___stl_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___eval_triggers__stl(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);

VL_ATTR_COLD bool Vpingpong_buffer_sp_tb_simple___024root___eval_phase__stl(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vpingpong_buffer_sp_tb_simple___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vpingpong_buffer_sp_tb_simple___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__act(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] pingpong_buffer_sp_tb_simple.dut.__Vcellout__u_ram0__DO)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([hybrid] pingpong_buffer_sp_tb_simple.dut.__Vcellout__u_ram1__DO)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge pingpong_buffer_sp_tb_simple.clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__nba(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] pingpong_buffer_sp_tb_simple.dut.__Vcellout__u_ram0__DO)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([hybrid] pingpong_buffer_sp_tb_simple.dut.__Vcellout__u_ram1__DO)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge pingpong_buffer_sp_tb_simple.clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___ctor_var_reset(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_data = VL_RAND_RESET_I(16);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_valid = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_ready = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__sample_ready = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__frame_start = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_valid = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_ready = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_ready = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_id = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_take = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_empty = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__overrun = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__underrun = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors = 0;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__words_written = 0;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__words_read = 0;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__expected_data = VL_RAND_RESET_I(16);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_sel = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_addr = VL_RAND_RESET_I(8);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr = VL_RAND_RESET_I(8);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state = VL_RAND_RESET_I(2);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state = VL_RAND_RESET_I(2);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_complete = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state = VL_RAND_RESET_I(2);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_beat = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_complete = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_has_data = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram0 = VL_RAND_RESET_I(14);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram1 = VL_RAND_RESET_I(14);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wre_ram0 = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wre_ram1 = VL_RAND_RESET_I(1);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO = VL_RAND_RESET_I(32);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__read_data = VL_RAND_RESET_I(32);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__read_data = VL_RAND_RESET_I(32);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__0__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__0__addr = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__1__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__1__addr = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__2__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__2__addr = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__3__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__3__addr = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO__0 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO__0 = VL_RAND_RESET_I(32);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO__1 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO__1 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
