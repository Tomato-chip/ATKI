// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram_vu_handshake_tb.h for the primary calling header

#include "Vram_vu_handshake_tb__pch.h"
#include "Vram_vu_handshake_tb___024root.h"

VL_ATTR_COLD void Vram_vu_handshake_tb___024root___eval_initial__TOP(Vram_vu_handshake_tb___024root* vlSelf);
VlCoroutine Vram_vu_handshake_tb___024root___eval_initial__TOP__Vtiming__0(Vram_vu_handshake_tb___024root* vlSelf);
VlCoroutine Vram_vu_handshake_tb___024root___eval_initial__TOP__Vtiming__1(Vram_vu_handshake_tb___024root* vlSelf);
VlCoroutine Vram_vu_handshake_tb___024root___eval_initial__TOP__Vtiming__2(Vram_vu_handshake_tb___024root* vlSelf);

void Vram_vu_handshake_tb___024root___eval_initial(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_initial\n"); );
    // Body
    Vram_vu_handshake_tb___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vram_vu_handshake_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vram_vu_handshake_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vram_vu_handshake_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__ram_vu_handshake_tb__DOT__clk__0 
        = vlSelf->ram_vu_handshake_tb__DOT__clk;
    vlSelf->__Vtrigprevexpr_hbeb878a1__0 = (1U & (VL_LTES_III(32, 0x100U, vlSelf->ram_vu_handshake_tb__DOT__read_count) 
                                                  | (~ (IData)(vlSelf->ram_vu_handshake_tb__DOT__read_enable))));
}

VL_INLINE_OPT VlCoroutine Vram_vu_handshake_tb___024root___eval_initial__TOP__Vtiming__0(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->ram_vu_handshake_tb__DOT__clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x4650ULL, 
                                           nullptr, 
                                           "ram_vu_handshake_tb.sv", 
                                           80);
        vlSelf->ram_vu_handshake_tb__DOT__clk = (1U 
                                                 & (~ (IData)(vlSelf->ram_vu_handshake_tb__DOT__clk)));
    }
}

VL_INLINE_OPT void Vram_vu_handshake_tb___024root___act_comb__TOP__0(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__buffer_full 
        = ((IData)(vlSelf->ram_vu_handshake_tb__DOT__sample_valid) 
           & (0xffU == (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_address)));
}

void Vram_vu_handshake_tb___024root___eval_act(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_act\n"); );
    // Body
    if ((5ULL & vlSelf->__VactTriggered.word(0U))) {
        Vram_vu_handshake_tb___024root___act_comb__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*0:0*/, 32> Vram_vu_handshake_tb__ConstPool__TABLE_hd0027ab9_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vram_vu_handshake_tb__ConstPool__TABLE_hb67b6cb0_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vram_vu_handshake_tb__ConstPool__TABLE_he2571a9e_0;

VL_INLINE_OPT void Vram_vu_handshake_tb___024root___nba_sequent__TOP__0(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*8:0*/ __Vdly__ram_vu_handshake_tb__DOT__u_ram__DOT__read_count;
    __Vdly__ram_vu_handshake_tb__DOT__u_ram__DOT__read_count = 0;
    SData/*9:0*/ __Vdlyvdim0__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvdim0__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvval__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvset__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvdim0__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvval__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvset__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 0;
    SData/*9:0*/ __Vdly__ram_vu_handshake_tb__DOT__u_vu__DOT__div_q;
    __Vdly__ram_vu_handshake_tb__DOT__u_vu__DOT__div_q = 0;
    // Body
    __Vdly__ram_vu_handshake_tb__DOT__u_vu__DOT__div_q 
        = vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__div_q;
    __Vdlyvset__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 0U;
    __Vdlyvset__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 0U;
    __Vdly__ram_vu_handshake_tb__DOT__u_ram__DOT__read_count 
        = vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_count;
    if (((IData)(vlSelf->ram_vu_handshake_tb__DOT__read_ack) 
         & (IData)(vlSelf->ram_vu_handshake_tb__DOT__read_enable))) {
        vlSelf->ram_vu_handshake_tb__DOT__read_count 
            = ((IData)(1U) + vlSelf->ram_vu_handshake_tb__DOT__read_count);
        if (VL_UNLIKELY((VL_GTES_III(32, 5U, vlSelf->ram_vu_handshake_tb__DOT__read_count) 
                         | VL_LTES_III(32, 0xfdU, vlSelf->ram_vu_handshake_tb__DOT__read_count)))) {
            VL_WRITEF("  [%0t] Read ACK #%0d: data=0x%04x, LEDs=%06b\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      32,vlSelf->ram_vu_handshake_tb__DOT__read_count,
                      16,(IData)(vlSelf->ram_vu_handshake_tb__DOT__read_data),
                      6,vlSelf->ram_vu_handshake_tb__DOT__leds);
        }
    }
    if (((IData)(vlSelf->ram_vu_handshake_tb__DOT__sample_valid) 
         & (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_buffer_sel))) {
        __Vdlyvval__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 
            = vlSelf->ram_vu_handshake_tb__DOT__sample_data;
        __Vdlyvset__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 1U;
        __Vdlyvdim0__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 
            = (0x3ffU & ((IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__address_RAM_1) 
                         >> 4U));
    }
    if (((~ (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_buffer_sel)) 
         & (IData)(vlSelf->ram_vu_handshake_tb__DOT__sample_valid))) {
        __Vdlyvval__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 
            = vlSelf->ram_vu_handshake_tb__DOT__sample_data;
        __Vdlyvset__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 1U;
        __Vdlyvdim0__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 
            = (0x3ffU & ((IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__address_RAM_0) 
                         >> 4U));
    }
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__do_pipe 
        = (0xffffU & vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem
           [(0x3ffU & ((IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__address_RAM_1) 
                       >> 4U))]);
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__do_pipe 
        = (0xffffU & vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem
           [(0x3ffU & ((IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__address_RAM_0) 
                       >> 4U))]);
    if (vlSelf->ram_vu_handshake_tb__DOT__rst_n) {
        if (vlSelf->ram_vu_handshake_tb__DOT__sample_valid) {
            vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_address 
                = ((IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__buffer_full)
                    ? 0U : (0xffU & ((IData)(1U) + (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_address))));
        }
        if ((((1U == (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__read_state_q)) 
              & (IData)(vlSelf->ram_vu_handshake_tb__DOT__read_enable)) 
             & (IData)(vlSelf->ram_vu_handshake_tb__DOT__read_ack))) {
            vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__level_q 
                = ((vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__level_q 
                    - VL_SHIFTR_III(32,32,32, vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__level_q, 0xbU)) 
                   + VL_SHIFTR_III(32,32,32, (0xffffU 
                                              & ((0x8000U 
                                                  & (IData)(vlSelf->ram_vu_handshake_tb__DOT__read_data))
                                                  ? 
                                                 ((IData)(1U) 
                                                  + 
                                                  (~ (IData)(vlSelf->ram_vu_handshake_tb__DOT__read_data)))
                                                  : (IData)(vlSelf->ram_vu_handshake_tb__DOT__read_data))), 2U));
        }
        if ((((IData)(vlSelf->ram_vu_handshake_tb__DOT__read_ack) 
              & (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__valid_read_out)) 
             & (~ (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_in_progress)))) {
            __Vdly__ram_vu_handshake_tb__DOT__u_ram__DOT__read_count 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_count)));
            vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_address 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_address)));
            if ((0x100U == ((IData)(1U) + (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_count)))) {
                vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_in_progress = 1U;
            }
        }
        if (vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__buffer_full) {
            vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_address = 0U;
            __Vdly__ram_vu_handshake_tb__DOT__u_ram__DOT__read_count = 0U;
            vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_in_progress = 0U;
        }
    } else {
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_address = 0U;
        vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__level_q = 0U;
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_address = 0U;
        __Vdly__ram_vu_handshake_tb__DOT__u_ram__DOT__read_count = 0U;
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_in_progress = 0U;
    }
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_count 
        = __Vdly__ram_vu_handshake_tb__DOT__u_ram__DOT__read_count;
    if (__Vdlyvset__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0) {
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem[__Vdlyvdim0__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0] 
            = __Vdlyvval__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0;
    }
    if (__Vdlyvset__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0) {
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem[__Vdlyvdim0__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0] 
            = __Vdlyvval__ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0;
    }
    __Vtableidx1 = (((IData)(vlSelf->ram_vu_handshake_tb__DOT__read_enable) 
                     << 4U) | (((IData)(vlSelf->ram_vu_handshake_tb__DOT__buffer_ready) 
                                << 3U) | (((IData)(vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__read_state_q) 
                                           << 1U) | (IData)(vlSelf->ram_vu_handshake_tb__DOT__rst_n))));
    if (vlSelf->ram_vu_handshake_tb__DOT__rst_n) {
        if (vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__tick) {
            vlSelf->ram_vu_handshake_tb__DOT__leds 
                = vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__leds_next;
        }
        if ((0x3e7U == (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__div_q))) {
            __Vdly__ram_vu_handshake_tb__DOT__u_vu__DOT__div_q = 0U;
            vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__tick = 1U;
        } else {
            __Vdly__ram_vu_handshake_tb__DOT__u_vu__DOT__div_q 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__div_q)));
            vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__tick = 0U;
        }
        vlSelf->ram_vu_handshake_tb__DOT__buffer_ready = 0U;
        if (vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__buffer_full) {
            vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_buffer_sel 
                = vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_buffer_sel;
            vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_buffer_sel 
                = (1U & (~ (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_buffer_sel)));
            vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__valid_read_out = 1U;
            vlSelf->ram_vu_handshake_tb__DOT__buffer_ready = 1U;
        }
    } else {
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__write_buffer_sel = 0U;
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_buffer_sel = 1U;
        vlSelf->ram_vu_handshake_tb__DOT__leds = 0U;
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__valid_read_out = 0U;
        __Vdly__ram_vu_handshake_tb__DOT__u_vu__DOT__div_q = 0U;
        vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__tick = 0U;
        vlSelf->ram_vu_handshake_tb__DOT__buffer_ready = 0U;
    }
    vlSelf->ram_vu_handshake_tb__DOT__read_ack = Vram_vu_handshake_tb__ConstPool__TABLE_hd0027ab9_0
        [__Vtableidx1];
    if ((2U & Vram_vu_handshake_tb__ConstPool__TABLE_hb67b6cb0_0
         [__Vtableidx1])) {
        vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__read_state_q 
            = Vram_vu_handshake_tb__ConstPool__TABLE_he2571a9e_0
            [__Vtableidx1];
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
    if (vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__valid_read_out) {
        vlSelf->ram_vu_handshake_tb__DOT__read_enable 
            = (1U & (~ (IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_in_progress)));
        vlSelf->ram_vu_handshake_tb__DOT__read_data = 0U;
        vlSelf->ram_vu_handshake_tb__DOT__read_data 
            = (0xffffU & ((IData)(vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__read_buffer_sel)
                           ? vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__do_pipe
                           : vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__do_pipe));
    } else {
        vlSelf->ram_vu_handshake_tb__DOT__read_enable = 0U;
        vlSelf->ram_vu_handshake_tb__DOT__read_data = 0U;
    }
    vlSelf->ram_vu_handshake_tb__DOT__u_vu__DOT__div_q 
        = __Vdly__ram_vu_handshake_tb__DOT__u_vu__DOT__div_q;
}

void Vram_vu_handshake_tb___024root___eval_nba(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vram_vu_handshake_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((5ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vram_vu_handshake_tb___024root___act_comb__TOP__0(vlSelf);
    }
}

void Vram_vu_handshake_tb___024root___timing_resume(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h62688261__0.resume("@(posedge ram_vu_handshake_tb.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h267faeff__0.resume("@([changed] ((32'sh100 <= ram_vu_handshake_tb.read_count) | (~ ram_vu_handshake_tb.read_enable)))");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vram_vu_handshake_tb___024root___timing_commit(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h62688261__0.commit("@(posedge ram_vu_handshake_tb.clk)");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h267faeff__0.commit("@([changed] ((32'sh100 <= ram_vu_handshake_tb.read_count) | (~ ram_vu_handshake_tb.read_enable)))");
    }
}

void Vram_vu_handshake_tb___024root___eval_triggers__act(Vram_vu_handshake_tb___024root* vlSelf);

bool Vram_vu_handshake_tb___024root___eval_phase__act(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vram_vu_handshake_tb___024root___eval_triggers__act(vlSelf);
    Vram_vu_handshake_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vram_vu_handshake_tb___024root___timing_resume(vlSelf);
        Vram_vu_handshake_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vram_vu_handshake_tb___024root___eval_phase__nba(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vram_vu_handshake_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_vu_handshake_tb___024root___dump_triggers__nba(Vram_vu_handshake_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_vu_handshake_tb___024root___dump_triggers__act(Vram_vu_handshake_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vram_vu_handshake_tb___024root___eval(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vram_vu_handshake_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("ram_vu_handshake_tb.sv", 16, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vram_vu_handshake_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("ram_vu_handshake_tb.sv", 16, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vram_vu_handshake_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vram_vu_handshake_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vram_vu_handshake_tb___024root___eval_debug_assertions(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
