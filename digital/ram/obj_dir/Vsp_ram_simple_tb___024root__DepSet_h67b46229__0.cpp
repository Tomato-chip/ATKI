// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsp_ram_simple_tb.h for the primary calling header

#include "Vsp_ram_simple_tb__pch.h"
#include "Vsp_ram_simple_tb__Syms.h"
#include "Vsp_ram_simple_tb___024root.h"

VL_INLINE_OPT VlCoroutine Vsp_ram_simple_tb___024root___eval_initial__TOP__Vtiming__1(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x655f7462U;
    __Vtemp_1[2U] = 0x696d706cU;
    __Vtemp_1[3U] = 0x616d5f73U;
    __Vtemp_1[4U] = 0x73705f72U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(5, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->sp_ram_simple_tb__DOT__rst_n = 0U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 0U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = 0U;
    vlSelf->sp_ram_simple_tb__DOT__cycle_count = 0U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       57);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       57);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       57);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       57);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       57);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__rst_n = 1U;
    VL_WRITEF("[%0t] Reset released\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       62);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       62);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       62);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("[%0t] Starting buffer 0\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa000U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa001U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 2U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa002U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 3U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa003U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 4U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa004U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 5U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa005U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 6U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa006U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 7U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa007U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 8U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa008U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 9U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa009U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0xaU;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       82);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 0U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       86);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       86);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__buffer = 1U;
    VL_WRITEF("[%0t] Starting buffer 1\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa100U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa101U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 2U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa102U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 3U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa103U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 4U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa104U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 5U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa105U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 6U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa106U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 7U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa107U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 8U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa108U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 9U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa109U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0xaU;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       82);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 0U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       86);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       86);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__buffer = 2U;
    VL_WRITEF("[%0t] Starting buffer 2\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa200U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa201U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 2U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa202U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 3U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa203U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 4U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa204U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 5U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa205U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 6U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa206U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 7U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa207U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 8U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa208U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 9U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = 0xa209U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_count = ((IData)(1U) 
                                                   + vlSelf->sp_ram_simple_tb__DOT__sample_count);
    if (VL_UNLIKELY(vlSelf->sp_ram_simple_tb__DOT__buffer_ready)) {
        vlSelf->sp_ram_simple_tb__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__cycle_count);
        VL_WRITEF("[%0t] === BUFFER %0d READY === read_data=%04x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
                  16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    }
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0xaU;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       82);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 0U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       86);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       86);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__buffer = 3U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = 1U;
    vlSelf->sp_ram_simple_tb__DOT__sample_in = (0xffffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_in)));
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       97);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       97);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       97);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       97);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h73fcac0b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge sp_ram_simple_tb.clk)", 
                                                       "sp_ram_simple_tb.sv", 
                                                       97);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("\n=== Test Complete ===\nTotal samples: %0d\nBuffer ready count: %0d\nFinal read_data: %04x\n",
              32,vlSelf->sp_ram_simple_tb__DOT__sample_count,
              32,vlSelf->sp_ram_simple_tb__DOT__cycle_count,
              16,(IData)(vlSelf->sp_ram_simple_tb__DOT__read_data));
    if ((VL_LTES_III(32, 2U, vlSelf->sp_ram_simple_tb__DOT__cycle_count) 
         & (0U != (IData)(vlSelf->sp_ram_simple_tb__DOT__read_data)))) {
        VL_WRITEF("=== TEST PASSED ===\n");
    } else {
        VL_WRITEF("=== TEST FAILED ===\n");
    }
    VL_FINISH_MT("sp_ram_simple_tb.sv", 109, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsp_ram_simple_tb___024root___dump_triggers__act(Vsp_ram_simple_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsp_ram_simple_tb___024root___eval_triggers__act(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->sp_ram_simple_tb__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__sp_ram_simple_tb__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__sp_ram_simple_tb__DOT__clk__0 
        = vlSelf->sp_ram_simple_tb__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsp_ram_simple_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
