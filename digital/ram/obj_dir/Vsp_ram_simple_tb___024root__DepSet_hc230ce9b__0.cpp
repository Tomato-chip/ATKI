// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsp_ram_simple_tb.h for the primary calling header

#include "Vsp_ram_simple_tb__pch.h"
#include "Vsp_ram_simple_tb___024root.h"

VL_ATTR_COLD void Vsp_ram_simple_tb___024root___eval_initial__TOP(Vsp_ram_simple_tb___024root* vlSelf);
VlCoroutine Vsp_ram_simple_tb___024root___eval_initial__TOP__Vtiming__0(Vsp_ram_simple_tb___024root* vlSelf);
VlCoroutine Vsp_ram_simple_tb___024root___eval_initial__TOP__Vtiming__1(Vsp_ram_simple_tb___024root* vlSelf);
VlCoroutine Vsp_ram_simple_tb___024root___eval_initial__TOP__Vtiming__2(Vsp_ram_simple_tb___024root* vlSelf);

void Vsp_ram_simple_tb___024root___eval_initial(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_initial\n"); );
    // Body
    Vsp_ram_simple_tb___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vsp_ram_simple_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vsp_ram_simple_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vsp_ram_simple_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__sp_ram_simple_tb__DOT__clk__0 
        = vlSelf->sp_ram_simple_tb__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vsp_ram_simple_tb___024root___eval_initial__TOP__Vtiming__0(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->sp_ram_simple_tb__DOT__clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x4856ULL, 
                                           nullptr, 
                                           "sp_ram_simple_tb.sv", 
                                           27);
        vlSelf->sp_ram_simple_tb__DOT__clk = (1U & 
                                              (~ (IData)(vlSelf->sp_ram_simple_tb__DOT__clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vsp_ram_simple_tb___024root___eval_initial__TOP__Vtiming__2(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x2faf080ULL, 
                                       nullptr, "sp_ram_simple_tb.sv", 
                                       132);
    VL_WRITEF("ERROR: Simulation timeout!\n");
    VL_FINISH_MT("sp_ram_simple_tb.sv", 134, "");
}

VL_INLINE_OPT void Vsp_ram_simple_tb___024root___act_sequent__TOP__0(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___act_sequent__TOP__0\n"); );
    // Body
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__buffer_full 
        = ((IData)(vlSelf->sp_ram_simple_tb__DOT__sample_ready) 
           & (9U == (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_address)));
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_0 
        = ((~ (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel)) 
           & (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_ready));
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_1 
        = ((IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel) 
           & (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_ready));
}

void Vsp_ram_simple_tb___024root___eval_act(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_act\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        Vsp_ram_simple_tb___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vsp_ram_simple_tb___024root___nba_sequent__TOP__0(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__sp_ram_simple_tb__DOT__dut__DOT__rw_sel;
    __Vdly__sp_ram_simple_tb__DOT__dut__DOT__rw_sel = 0;
    SData/*13:0*/ __Vdlyvdim0__sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvdim0__sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 0;
    SData/*15:0*/ __Vdlyvval__sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvval__sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvset__sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 0;
    SData/*13:0*/ __Vdlyvdim0__sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvdim0__sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 0;
    SData/*15:0*/ __Vdlyvval__sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvval__sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvset__sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 0;
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->sp_ram_simple_tb__DOT__read_data) 
                      != (IData)(vlSelf->sp_ram_simple_tb__DOT__read_data_prev)) 
                     & (0U != (IData)(vlSelf->sp_ram_simple_tb__DOT__read_data))))) {
        VL_WRITEF("[%0t] read_data changed: %04x -> %04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data_prev),
                  16,vlSelf->sp_ram_simple_tb__DOT__read_data);
    }
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        VL_WRITEF("[%0t] buffer_ready pulse detected, read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    __Vdlyvset__sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 0U;
    __Vdlyvset__sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 0U;
    __Vdly__sp_ram_simple_tb__DOT__dut__DOT__rw_sel 
        = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel;
    if (vlSelf->sp_ram_simple_tb__DOT__rst_n) {
        if (vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_1) {
            __Vdlyvval__sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 
                = vlSelf->sp_ram_simple_tb__DOT__sample_in;
            __Vdlyvset__sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 1U;
            __Vdlyvdim0__sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 
                = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_1;
            vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_1 
                = vlSelf->sp_ram_simple_tb__DOT__sample_in;
        } else {
            vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_1 
                = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem
                [vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_1];
        }
        if (vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_0) {
            __Vdlyvval__sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 
                = vlSelf->sp_ram_simple_tb__DOT__sample_in;
            __Vdlyvset__sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 1U;
            __Vdlyvdim0__sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 
                = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_0;
            vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_0 
                = vlSelf->sp_ram_simple_tb__DOT__sample_in;
        } else {
            vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_0 
                = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem
                [vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_0];
        }
        if (vlSelf->sp_ram_simple_tb__DOT__sample_ready) {
            vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_address 
                = ((IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__buffer_full)
                    ? 0U : (0xffU & ((IData)(1U) + (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_address))));
        }
        if (((IData)(vlSelf->sp_ram_simple_tb__DOT__sample_ready) 
             & (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__valid_read_out))) {
            vlSelf->sp_ram_simple_tb__DOT__dut__DOT__read_address 
                = ((9U == (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__read_address))
                    ? 0U : (0xffU & ((IData)(1U) + (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__read_address))));
        }
        vlSelf->sp_ram_simple_tb__DOT__buffer_ready = 0U;
        if (vlSelf->sp_ram_simple_tb__DOT__dut__DOT__buffer_full) {
            vlSelf->sp_ram_simple_tb__DOT__dut__DOT__read_address = 0U;
            __Vdly__sp_ram_simple_tb__DOT__dut__DOT__rw_sel 
                = (1U & (~ (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel)));
            vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel_read 
                = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel;
            vlSelf->sp_ram_simple_tb__DOT__buffer_ready = 1U;
            vlSelf->sp_ram_simple_tb__DOT__dut__DOT__valid_read_out = 1U;
        }
    } else {
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_address = 0U;
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__read_address = 0U;
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_1 = 0U;
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_0 = 0U;
        __Vdly__sp_ram_simple_tb__DOT__dut__DOT__rw_sel = 0U;
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel_read = 1U;
        vlSelf->sp_ram_simple_tb__DOT__buffer_ready = 0U;
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__valid_read_out = 0U;
    }
    if ((1U & (~ (IData)(vlSelf->sp_ram_simple_tb__DOT__rst_n)))) {
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__data_out_reg = 0U;
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__data_out_reg = 0U;
    }
    vlSelf->sp_ram_simple_tb__DOT__read_data_prev = vlSelf->sp_ram_simple_tb__DOT__read_data;
    if (__Vdlyvset__sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0) {
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem[__Vdlyvdim0__sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0] 
            = __Vdlyvval__sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0;
    }
    if (__Vdlyvset__sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0) {
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem[__Vdlyvdim0__sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0] 
            = __Vdlyvval__sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0;
    }
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel 
        = __Vdly__sp_ram_simple_tb__DOT__dut__DOT__rw_sel;
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_0 
        = ((~ (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel)) 
           & (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_ready));
    if (vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel) {
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_1 
            = vlSelf->sp_ram_simple_tb__DOT__sample_ready;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__0__a8 
            = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__read_address;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__0__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__0__a8) 
               << 4U);
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_0 
            = vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__0__Vfuncout;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__1__a8 
            = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_address;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__1__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__1__a8) 
               << 4U);
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_1 
            = vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__1__Vfuncout;
    } else {
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_1 = 0U;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__2__a8 
            = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_address;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__2__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__2__a8) 
               << 4U);
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_0 
            = vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__2__Vfuncout;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__3__a8 
            = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__read_address;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__3__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__3__a8) 
               << 4U);
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_1 
            = vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__3__Vfuncout;
    }
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__buffer_full 
        = ((IData)(vlSelf->sp_ram_simple_tb__DOT__sample_ready) 
           & (9U == (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_address)));
    vlSelf->sp_ram_simple_tb__DOT__read_data = 0U;
    if (vlSelf->sp_ram_simple_tb__DOT__dut__DOT__valid_read_out) {
        vlSelf->sp_ram_simple_tb__DOT__read_data = 
            ((IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel_read)
              ? (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_1)
              : (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_0));
    }
}

void Vsp_ram_simple_tb___024root___eval_nba(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsp_ram_simple_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

void Vsp_ram_simple_tb___024root___timing_resume(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h73fcac0b__0.resume("@(posedge sp_ram_simple_tb.clk)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vsp_ram_simple_tb___024root___timing_commit(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h73fcac0b__0.commit("@(posedge sp_ram_simple_tb.clk)");
    }
}

void Vsp_ram_simple_tb___024root___eval_triggers__act(Vsp_ram_simple_tb___024root* vlSelf);

bool Vsp_ram_simple_tb___024root___eval_phase__act(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsp_ram_simple_tb___024root___eval_triggers__act(vlSelf);
    Vsp_ram_simple_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vsp_ram_simple_tb___024root___timing_resume(vlSelf);
        Vsp_ram_simple_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsp_ram_simple_tb___024root___eval_phase__nba(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsp_ram_simple_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsp_ram_simple_tb___024root___dump_triggers__nba(Vsp_ram_simple_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsp_ram_simple_tb___024root___dump_triggers__act(Vsp_ram_simple_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsp_ram_simple_tb___024root___eval(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsp_ram_simple_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("sp_ram_simple_tb.sv", 8, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vsp_ram_simple_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("sp_ram_simple_tb.sv", 8, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vsp_ram_simple_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vsp_ram_simple_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsp_ram_simple_tb___024root___eval_debug_assertions(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
