// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram_logic_tb.h for the primary calling header

#include "Vram_logic_tb__pch.h"
#include "Vram_logic_tb___024root.h"

VL_ATTR_COLD void Vram_logic_tb___024root___eval_initial__TOP(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__0(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__2(Vram_logic_tb___024root* vlSelf);

void Vram_logic_tb___024root___eval_initial(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial\n"); );
    // Body
    Vram_logic_tb___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__ram_logic_tb__DOT__clk__0 
        = vlSelf->ram_logic_tb__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__0(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->ram_logic_tb__DOT__clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "ram_logic_tb.sv", 
                                           62);
        vlSelf->ram_logic_tb__DOT__clk = (1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_4__1(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_4__1\n"); );
    // Init
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val = 0;
    SData/*15:0*/ __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data = 0;
    // Body
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val = 0xd00U;
    VL_WRITEF("[%0t] Writing buffer %0d with values %0d to %0d\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->ram_logic_tb__DOT__buffer_number,
              32,__Vtask_ram_logic_tb__DOT__write_buffer__10__start_val,
              32,((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val);
    vlSelf->ram_logic_tb__DOT__expected_buffer[0U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(1U) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[1U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(2U) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[2U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(3U) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[3U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(4U) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[4U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(5U) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[5U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(6U) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[6U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(7U) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[7U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(8U) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[8U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(9U) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[9U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xaU) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xaU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xbU) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xbU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xcU) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xcU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xdU) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xdU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xeU) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xeU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__10__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xfU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__10__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__buffer_number = ((IData)(1U) 
                                                + vlSelf->ram_logic_tb__DOT__buffer_number);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       144);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vfork_4__sync.done("ram_logic_tb.sv", 
                                 377);
    vlSelf->__Vm_traceActivity[4U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_4__0(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_4__0\n"); );
    // Init
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer;
    __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer = 0;
    // Body
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       373);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       373);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       373);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       373);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       373);
    __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer = 0U;
    VL_WRITEF("[%0t] Reading and verifying buffer...\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__buffer_ready)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           154);
    }
    VL_WRITEF("[%0t] Buffer ready signal detected\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 0 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[0]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [1U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 1 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [1U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[1]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [2U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 2 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [2U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[2]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [3U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 3 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [3U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[3]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [4U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 4 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [4U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[4]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [5U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 5 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [5U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[5]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [6U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 6 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [6U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[6]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [7U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 7 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [7U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[7]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [8U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 8 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [8U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[8]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [9U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 9 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [9U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[9]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xaU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 10 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xaU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[10]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xbU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 11 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xbU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[11]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xcU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 12 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xcU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[12]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xdU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 13 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xdU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[13]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xeU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 14 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xeU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[14]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xfU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 15 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xfU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[15]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    if ((0U == __Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer)) {
        VL_WRITEF("[%0t] Buffer verification PASSED - all 16 samples correct\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
    } else {
        VL_WRITEF("[%0t] Buffer verification FAILED - %0d errors\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,__Vtask_ram_logic_tb__DOT__read_verify_buffer__9__errors_this_buffer);
    }
    vlSelf->__Vfork_4__sync.done("ram_logic_tb.sv", 
                                 372);
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_3__1(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_3__1\n"); );
    // Init
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__read_buffer_slow__5__unnamedblk4__DOT__i;
    __Vtask_ram_logic_tb__DOT__read_buffer_slow__5__unnamedblk4__DOT__i = 0;
    // Body
    VL_WRITEF("[%0t] Reading buffer with variable ready...\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__buffer_ready)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           189);
    }
    __Vtask_ram_logic_tb__DOT__read_buffer_slow__5__unnamedblk4__DOT__i = 0U;
    while (VL_GTS_III(32, 0x10U, __Vtask_ram_logic_tb__DOT__read_buffer_slow__5__unnamedblk4__DOT__i)) {
        vlSelf->ram_logic_tb__DOT__read_ready = (0U 
                                                 != 
                                                 VL_MODDIV_III(32, (IData)(
                                                                           VL_RANDOM_I()), (IData)(3U)));
        if (VL_UNLIKELY(((IData)(vlSelf->ram_logic_tb__DOT__read_ready) 
                         & (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
            VL_WRITEF("[%0t] Read[%0d]: 0x%04x\n",64,
                      VL_TIME_UNITED_Q(1000),-9,32,
                      __Vtask_ram_logic_tb__DOT__read_buffer_slow__5__unnamedblk4__DOT__i,
                      16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                           : 0U));
            co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge ram_logic_tb.clk)", 
                                                               "ram_logic_tb.sv", 
                                                               197);
        } else {
            co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge ram_logic_tb.clk)", 
                                                               "ram_logic_tb.sv", 
                                                               199);
            __Vtask_ram_logic_tb__DOT__read_buffer_slow__5__unnamedblk4__DOT__i 
                = (__Vtask_ram_logic_tb__DOT__read_buffer_slow__5__unnamedblk4__DOT__i 
                   - (IData)(1U));
        }
        __Vtask_ram_logic_tb__DOT__read_buffer_slow__5__unnamedblk4__DOT__i 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_buffer_slow__5__unnamedblk4__DOT__i);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->__Vfork_3__sync.done("ram_logic_tb.sv", 
                                 329);
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_3__0(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_3__0\n"); );
    // Init
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val = 0;
    SData/*15:0*/ __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data = 0;
    // Body
    __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val = 0xa00U;
    VL_WRITEF("[%0t] Writing buffer %0d with values %0d to %0d\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->ram_logic_tb__DOT__buffer_number,
              32,__Vtask_ram_logic_tb__DOT__write_buffer__4__start_val,
              32,((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val);
    vlSelf->ram_logic_tb__DOT__expected_buffer[0U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(1U) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[1U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(2U) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[2U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(3U) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[3U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(4U) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[4U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(5U) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[5U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(6U) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[6U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(7U) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[7U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(8U) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[8U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(9U) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[9U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xaU) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xaU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xbU) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xbU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xcU) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xcU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xdU) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xdU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xeU) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xeU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__4__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xfU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__4__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__buffer_number = ((IData)(1U) 
                                                + vlSelf->ram_logic_tb__DOT__buffer_number);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       144);
    vlSelf->__Vm_traceActivity[5U] = 1U;
    vlSelf->__Vfork_3__sync.done("ram_logic_tb.sv", 
                                 325);
    vlSelf->__Vm_traceActivity[5U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_2__1(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_2__1\n"); );
    // Init
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer;
    __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer = 0;
    // Body
    __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer = 0U;
    VL_WRITEF("[%0t] Reading and verifying buffer...\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__buffer_ready)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           154);
    }
    VL_WRITEF("[%0t] Buffer ready signal detected\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 0 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[0]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [1U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 1 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [1U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[1]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [2U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 2 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [2U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[2]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [3U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 3 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [3U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[3]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [4U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 4 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [4U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[4]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [5U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 5 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [5U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[5]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [6U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 6 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [6U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[6]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [7U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 7 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [7U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[7]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [8U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 8 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [8U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[8]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [9U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 9 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [9U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[9]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xaU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 10 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xaU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[10]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xbU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 11 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xbU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[11]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xcU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 12 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xcU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[12]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xdU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 13 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xdU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[13]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xeU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 14 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xeU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[14]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xfU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 15 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xfU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[15]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    if ((0U == __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer)) {
        VL_WRITEF("[%0t] Buffer verification PASSED - all 16 samples correct\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
    } else {
        VL_WRITEF("[%0t] Buffer verification FAILED - %0d errors\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,__Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    vlSelf->ram_logic_tb__DOT__unnamedblk8__DOT__buf_idx = 1U;
    __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer = 0U;
    VL_WRITEF("[%0t] Reading and verifying buffer...\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__buffer_ready)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           154);
    }
    VL_WRITEF("[%0t] Buffer ready signal detected\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 0 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[0]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [1U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 1 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [1U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[1]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [2U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 2 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [2U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[2]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [3U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 3 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [3U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[3]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [4U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 4 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [4U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[4]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [5U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 5 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [5U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[5]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [6U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 6 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [6U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[6]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [7U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 7 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [7U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[7]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [8U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 8 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [8U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[8]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [9U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 9 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [9U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[9]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xaU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 10 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xaU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[10]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xbU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 11 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xbU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[11]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xcU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 12 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xcU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[12]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xdU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 13 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xdU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[13]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xeU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 14 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xeU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[14]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xfU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 15 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xfU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[15]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    if ((0U == __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer)) {
        VL_WRITEF("[%0t] Buffer verification PASSED - all 16 samples correct\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
    } else {
        VL_WRITEF("[%0t] Buffer verification FAILED - %0d errors\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,__Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    vlSelf->ram_logic_tb__DOT__unnamedblk8__DOT__buf_idx = 2U;
    __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer = 0U;
    VL_WRITEF("[%0t] Reading and verifying buffer...\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__buffer_ready)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           154);
    }
    VL_WRITEF("[%0t] Buffer ready signal detected\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 0 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[0]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [1U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 1 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [1U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[1]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [2U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 2 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [2U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[2]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [3U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 3 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [3U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[3]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [4U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 4 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [4U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[4]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [5U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 5 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [5U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[5]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [6U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 6 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [6U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[6]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [7U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 7 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [7U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[7]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [8U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 8 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [8U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[8]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [9U])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 9 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [9U],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                            ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                           ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                           : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                            : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[9]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xaU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 10 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xaU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[10]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xbU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 11 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xbU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[11]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xcU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 12 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xcU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[12]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xdU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 13 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xdU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[13]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xeU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 14 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xeU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[14]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
    }
    if ((((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
           ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                          ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                          : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
           : 0U) != vlSelf->ram_logic_tb__DOT__expected_buffer
         [0xfU])) {
        VL_WRITEF("[%0t] ERROR: Read mismatch at index 15 - Expected: 0x%04x, Got: 0x%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,vlSelf->ram_logic_tb__DOT__expected_buffer
                  [0xfU],16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                              ? (0xffffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                             ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                             : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                              : 0U));
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    } else {
        VL_WRITEF("[%0t] Read[15]: 0x%04x (correct)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,16,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                                        ? vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO
                                                        : vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO))
                                                    : 0U));
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       173);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    if ((0U == __Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer)) {
        VL_WRITEF("[%0t] Buffer verification PASSED - all 16 samples correct\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
    } else {
        VL_WRITEF("[%0t] Buffer verification FAILED - %0d errors\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,__Vtask_ram_logic_tb__DOT__read_verify_buffer__3__errors_this_buffer);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       313);
    vlSelf->ram_logic_tb__DOT__unnamedblk8__DOT__buf_idx = 3U;
    vlSelf->__Vfork_2__sync.done("ram_logic_tb.sv", 
                                 310);
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_2__0(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_2__0\n"); );
    // Init
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val = 0;
    SData/*15:0*/ __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data = 0;
    // Body
    __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val = 0x200U;
    VL_WRITEF("[%0t] Writing buffer %0d with values %0d to %0d\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->ram_logic_tb__DOT__buffer_number,
              32,__Vtask_ram_logic_tb__DOT__write_buffer__2__start_val,
              32,((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val);
    vlSelf->ram_logic_tb__DOT__expected_buffer[0U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(1U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[1U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(2U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[2U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(3U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[3U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(4U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[4U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(5U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[5U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(6U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[6U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(7U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[7U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(8U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[8U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(9U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[9U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xaU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xaU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xbU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xbU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xcU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xcU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xdU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xdU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xeU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xeU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xfU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__buffer_number = ((IData)(1U) 
                                                + vlSelf->ram_logic_tb__DOT__buffer_number);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       144);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk7__DOT__buf_idx = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val = 0x300U;
    VL_WRITEF("[%0t] Writing buffer %0d with values %0d to %0d\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->ram_logic_tb__DOT__buffer_number,
              32,__Vtask_ram_logic_tb__DOT__write_buffer__2__start_val,
              32,((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val);
    vlSelf->ram_logic_tb__DOT__expected_buffer[0U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(1U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[1U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(2U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[2U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(3U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[3U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(4U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[4U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(5U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[5U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(6U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[6U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(7U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[7U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(8U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[8U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(9U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[9U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xaU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xaU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xbU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xbU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xcU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xcU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xdU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xdU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xeU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xeU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xfU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__buffer_number = ((IData)(1U) 
                                                + vlSelf->ram_logic_tb__DOT__buffer_number);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       144);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk7__DOT__buf_idx = 2U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val = 0x400U;
    VL_WRITEF("[%0t] Writing buffer %0d with values %0d to %0d\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->ram_logic_tb__DOT__buffer_number,
              32,__Vtask_ram_logic_tb__DOT__write_buffer__2__start_val,
              32,((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val);
    vlSelf->ram_logic_tb__DOT__expected_buffer[0U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(1U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[1U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(2U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[2U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(3U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[3U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(4U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[4U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(5U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[5U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(6U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[6U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(7U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[7U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(8U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[8U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(9U) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[9U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xaU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xaU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xbU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xbU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xcU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xcU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xdU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xdU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xeU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xeU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__2__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xfU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__2__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__buffer_number = ((IData)(1U) 
                                                + vlSelf->ram_logic_tb__DOT__buffer_number);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       144);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       305);
    vlSelf->__Vm_traceActivity[6U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk7__DOT__buf_idx = 3U;
    vlSelf->__Vfork_2__sync.done("ram_logic_tb.sv", 
                                 302);
    vlSelf->__Vm_traceActivity[6U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__1(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__1\n"); );
    // Body
    vlSelf->ram_logic_tb__DOT__unnamedblk5__DOT__saw_buffer_ready = 0U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__unnamedblk5__DOT__saw_buffer_ready)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           257);
        if (vlSelf->ram_logic_tb__DOT__buffer_ready) {
            vlSelf->ram_logic_tb__DOT__unnamedblk5__DOT__saw_buffer_ready = 1U;
        }
    }
    VL_WRITEF("[TEST %0d] PASSED - Buffer ready pulse detected\n",
              32,vlSelf->ram_logic_tb__DOT__test_num);
    vlSelf->__Vfork_1__sync.done("ram_logic_tb.sv", 
                                 254);
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__0(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__0\n"); );
    // Init
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val = 0;
    SData/*15:0*/ __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data = 0;
    // Body
    __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val = 0x100U;
    VL_WRITEF("[%0t] Writing buffer %0d with values %0d to %0d\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->ram_logic_tb__DOT__buffer_number,
              32,__Vtask_ram_logic_tb__DOT__write_buffer__1__start_val,
              32,((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val);
    vlSelf->ram_logic_tb__DOT__expected_buffer[0U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(1U) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[1U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(2U) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[2U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(3U) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[3U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(4U) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[4U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(5U) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[5U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(6U) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[6U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(7U) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[7U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(8U) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[8U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(9U) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[9U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xaU) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xaU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xbU) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xbU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xcU) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xcU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xdU) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xdU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xeU) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xeU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__1__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xfU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__1__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__buffer_number = ((IData)(1U) 
                                                + vlSelf->ram_logic_tb__DOT__buffer_number);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       144);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    vlSelf->__Vfork_1__sync.done("ram_logic_tb.sv", 
                                 249);
    vlSelf->__Vm_traceActivity[7U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__2(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x2faf080ULL, 
                                       nullptr, "ram_logic_tb.sv", 
                                       411);
    VL_WRITEF("\n*** TIMEOUT - Simulation ran too long ***\n");
    VL_FINISH_MT("ram_logic_tb.sv", 413, "");
}

VL_INLINE_OPT void Vram_logic_tb___024root___act_sequent__TOP__0(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___act_sequent__TOP__0\n"); );
    // Body
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_accepted 
        = ((IData)(vlSelf->ram_logic_tb__DOT__read_ready) 
           & (IData)(vlSelf->ram_logic_tb__DOT__read_valid));
    vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted 
        = ((0x10U > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
           & (IData)(vlSelf->ram_logic_tb__DOT__write_valid));
    vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_write_enable 
        = ((~ (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel)) 
           & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted));
    vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_write_enable 
        = ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted) 
           & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel));
}

void Vram_logic_tb___024root___eval_act(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_act\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        Vram_logic_tb___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vram_logic_tb___024root___nba_sequent__TOP__0(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__ram_logic_tb__DOT__dut__DOT__read_buffer_valid;
    __Vdly__ram_logic_tb__DOT__dut__DOT__read_buffer_valid = 0;
    CData/*0:0*/ __Vdly__ram_logic_tb__DOT__dut__DOT__read_in_progress;
    __Vdly__ram_logic_tb__DOT__dut__DOT__read_in_progress = 0;
    CData/*3:0*/ __Vdly__ram_logic_tb__DOT__dut__DOT__write_address;
    __Vdly__ram_logic_tb__DOT__dut__DOT__write_address = 0;
    CData/*4:0*/ __Vdly__ram_logic_tb__DOT__dut__DOT__write_count;
    __Vdly__ram_logic_tb__DOT__dut__DOT__write_count = 0;
    CData/*3:0*/ __Vdly__ram_logic_tb__DOT__dut__DOT__read_address;
    __Vdly__ram_logic_tb__DOT__dut__DOT__read_address = 0;
    CData/*4:0*/ __Vdly__ram_logic_tb__DOT__dut__DOT__read_count;
    __Vdly__ram_logic_tb__DOT__dut__DOT__read_count = 0;
    SData/*9:0*/ __Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvval__ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvset__ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvval__ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvset__ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 0;
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->ram_logic_tb__DOT__rst_n) 
                      & (IData)(vlSelf->ram_logic_tb__DOT__write_valid)) 
                     & (0x10U > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count))))) {
        VL_WRITEF("[%0t] WRITE: addr=%0#, data=0x%04x, count=%0#\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count) 
                                                   - (IData)(1U)),
                  16,(IData)(vlSelf->ram_logic_tb__DOT__write_data),
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count);
    }
    __Vdlyvset__ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 0U;
    __Vdlyvset__ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 0U;
    __Vdly__ram_logic_tb__DOT__dut__DOT__read_count 
        = vlSelf->ram_logic_tb__DOT__dut__DOT__read_count;
    __Vdly__ram_logic_tb__DOT__dut__DOT__read_in_progress 
        = vlSelf->ram_logic_tb__DOT__dut__DOT__read_in_progress;
    __Vdly__ram_logic_tb__DOT__dut__DOT__read_buffer_valid 
        = vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid;
    __Vdly__ram_logic_tb__DOT__dut__DOT__write_count 
        = vlSelf->ram_logic_tb__DOT__dut__DOT__write_count;
    if (VL_UNLIKELY(((IData)(vlSelf->ram_logic_tb__DOT__rst_n) 
                     & (IData)(vlSelf->ram_logic_tb__DOT__buffer_ready)))) {
        VL_WRITEF("[%0t] *** BUFFER SWAP - Buffer ready for reading ***\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->ram_logic_tb__DOT__rst_n) 
                     & (IData)(vlSelf->ram_logic_tb__DOT__buffer_overflow)))) {
        VL_WRITEF("[%0t] !!! OVERFLOW DETECTED !!!\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
    }
    __Vdly__ram_logic_tb__DOT__dut__DOT__read_address 
        = vlSelf->ram_logic_tb__DOT__dut__DOT__read_address;
    __Vdly__ram_logic_tb__DOT__dut__DOT__write_address 
        = vlSelf->ram_logic_tb__DOT__dut__DOT__write_address;
    if (vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_write_enable) {
        __Vdlyvval__ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 
            = (0xffffU & (IData)(vlSelf->ram_logic_tb__DOT__write_data));
        __Vdlyvset__ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 1U;
        __Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0 
            = (0x3ffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_address) 
                         >> 4U));
    }
    if (vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_write_enable) {
        __Vdlyvval__ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 
            = (0xffffU & (IData)(vlSelf->ram_logic_tb__DOT__write_data));
        __Vdlyvset__ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 1U;
        __Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0 
            = (0x3ffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_address) 
                         >> 4U));
    }
    if ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_write_enable)))) {
        vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem
            [(0x3ffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_address) 
                        >> 4U))];
    }
    if ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_write_enable)))) {
        vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem
            [(0x3ffU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_address) 
                        >> 4U))];
    }
    if (vlSelf->ram_logic_tb__DOT__rst_n) {
        vlSelf->ram_logic_tb__DOT__buffer_ready = 0U;
        vlSelf->ram_logic_tb__DOT__buffer_overflow = 0U;
        if (((0x10U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
             & (~ (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_in_progress)))) {
            vlSelf->ram_logic_tb__DOT__buffer_ready = 1U;
            __Vdly__ram_logic_tb__DOT__dut__DOT__read_buffer_valid = 1U;
            __Vdly__ram_logic_tb__DOT__dut__DOT__read_in_progress = 1U;
            vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel 
                = vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel;
            __Vdly__ram_logic_tb__DOT__dut__DOT__write_address = 0U;
            __Vdly__ram_logic_tb__DOT__dut__DOT__write_count = 0U;
            __Vdly__ram_logic_tb__DOT__dut__DOT__read_address = 0U;
            __Vdly__ram_logic_tb__DOT__dut__DOT__read_count = 0U;
            vlSelf->ram_logic_tb__DOT__read_valid = 0U;
            vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel 
                = (1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel)));
        } else {
            if (((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_accepted) 
                 & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid))) {
                if ((0xfU > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_count))) {
                    __Vdly__ram_logic_tb__DOT__dut__DOT__read_address 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_address)));
                    __Vdly__ram_logic_tb__DOT__dut__DOT__read_count 
                        = (0x1fU & ((IData)(1U) + (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_count)));
                } else {
                    __Vdly__ram_logic_tb__DOT__dut__DOT__read_in_progress = 0U;
                    __Vdly__ram_logic_tb__DOT__dut__DOT__read_count = 0U;
                    __Vdly__ram_logic_tb__DOT__dut__DOT__read_address = 0U;
                }
            }
            if (vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted) {
                if ((0x10U > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count))) {
                    __Vdly__ram_logic_tb__DOT__dut__DOT__write_address 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_address)));
                    __Vdly__ram_logic_tb__DOT__dut__DOT__write_count 
                        = (0x1fU & ((IData)(1U) + (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)));
                } else {
                    vlSelf->ram_logic_tb__DOT__buffer_overflow = 1U;
                }
            }
            vlSelf->ram_logic_tb__DOT__read_valid = 
                ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid) 
                 & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_in_progress));
        }
    } else {
        vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel = 0U;
        __Vdly__ram_logic_tb__DOT__dut__DOT__write_address = 0U;
        __Vdly__ram_logic_tb__DOT__dut__DOT__read_address = 0U;
        __Vdly__ram_logic_tb__DOT__dut__DOT__write_count = 0U;
        __Vdly__ram_logic_tb__DOT__dut__DOT__read_count = 0U;
        vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel = 1U;
        __Vdly__ram_logic_tb__DOT__dut__DOT__read_buffer_valid = 0U;
        __Vdly__ram_logic_tb__DOT__dut__DOT__read_in_progress = 0U;
        vlSelf->ram_logic_tb__DOT__buffer_ready = 0U;
        vlSelf->ram_logic_tb__DOT__buffer_overflow = 0U;
        vlSelf->ram_logic_tb__DOT__read_valid = 0U;
    }
    if (__Vdlyvset__ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0) {
        vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem[__Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0] 
            = __Vdlyvval__ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem__v0;
    }
    if (__Vdlyvset__ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0) {
        vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem[__Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0] 
            = __Vdlyvval__ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem__v0;
    }
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid 
        = __Vdly__ram_logic_tb__DOT__dut__DOT__read_buffer_valid;
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_in_progress 
        = __Vdly__ram_logic_tb__DOT__dut__DOT__read_in_progress;
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_count 
        = __Vdly__ram_logic_tb__DOT__dut__DOT__read_count;
    vlSelf->ram_logic_tb__DOT__dut__DOT__write_count 
        = __Vdly__ram_logic_tb__DOT__dut__DOT__write_count;
    vlSelf->ram_logic_tb__DOT__dut__DOT__write_address 
        = __Vdly__ram_logic_tb__DOT__dut__DOT__write_address;
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_address 
        = __Vdly__ram_logic_tb__DOT__dut__DOT__read_address;
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_accepted 
        = ((IData)(vlSelf->ram_logic_tb__DOT__read_ready) 
           & (IData)(vlSelf->ram_logic_tb__DOT__read_valid));
    vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted 
        = ((0x10U > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
           & (IData)(vlSelf->ram_logic_tb__DOT__write_valid));
    if (vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel) {
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__12__addr 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__read_address;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__12__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__12__addr) 
               << 4U);
        vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_address 
            = vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__12__Vfuncout;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__13__addr 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__write_address;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__13__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__13__addr) 
               << 4U);
        vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_address 
            = vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__13__Vfuncout;
    } else {
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__14__addr 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__write_address;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__14__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__14__addr) 
               << 4U);
        vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_address 
            = vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__14__Vfuncout;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__15__addr 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__read_address;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__15__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__15__addr) 
               << 4U);
        vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_address 
            = vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__15__Vfuncout;
    }
    vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_write_enable 
        = ((~ (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel)) 
           & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted));
    vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_write_enable 
        = ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted) 
           & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel));
}

void Vram_logic_tb___024root___eval_nba(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vram_logic_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[8U] = 1U;
    }
}

void Vram_logic_tb___024root___timing_resume(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h108cd1ff__0.resume("@(posedge ram_logic_tb.clk)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vram_logic_tb___024root___timing_commit(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h108cd1ff__0.commit("@(posedge ram_logic_tb.clk)");
    }
}

void Vram_logic_tb___024root___eval_triggers__act(Vram_logic_tb___024root* vlSelf);

bool Vram_logic_tb___024root___eval_phase__act(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vram_logic_tb___024root___eval_triggers__act(vlSelf);
    Vram_logic_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vram_logic_tb___024root___timing_resume(vlSelf);
        Vram_logic_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vram_logic_tb___024root___eval_phase__nba(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vram_logic_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_logic_tb___024root___dump_triggers__nba(Vram_logic_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_logic_tb___024root___dump_triggers__act(Vram_logic_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vram_logic_tb___024root___eval(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vram_logic_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("ram_logic_tb.sv", 18, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vram_logic_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("ram_logic_tb.sv", 18, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vram_logic_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vram_logic_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vram_logic_tb___024root___eval_debug_assertions(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
