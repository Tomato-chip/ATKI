// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpingpong_buffer_sp_tb_simple.h for the primary calling header

#include "Vpingpong_buffer_sp_tb_simple__pch.h"
#include "Vpingpong_buffer_sp_tb_simple__Syms.h"
#include "Vpingpong_buffer_sp_tb_simple___024root.h"

extern const VlWide<8>/*255:0*/ Vpingpong_buffer_sp_tb_simple__ConstPool__CONST_h9971be63_0;

VL_INLINE_OPT VlCoroutine Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP__Vtiming__1(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(8, Vpingpong_buffer_sp_tb_simple__ConstPool__CONST_h9971be63_0));
    vlSymsp->_traceDumpOpen();
    VL_WRITEF("===================================\nPing-Pong Buffer Simple Test\n===================================\n\n");
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__rst_n = 0U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_valid = 0U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_data = 0U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__sample_ready = 1U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__frame_start = 0U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_ready = 0U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_take = 0U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       91);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("[%0t] Reset complete\n\n[%0t] Writing 256 samples...\n",
              64,VL_TIME_UNITED_Q(1000),-9,64,VL_TIME_UNITED_Q(1000),
              -9);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x100U, vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk1__DOT__i)) {
        co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                           "pingpong_buffer_sp_tb_simple.sv", 
                                                           98);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_valid = 1U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_data 
            = (0xffffU & ((IData)(0x1000U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk1__DOT__i));
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_ready))))) {
            VL_WRITEF("ERROR: wr_ready low during write!\n");
            vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors 
                = ((IData)(1U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors);
        }
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__words_written 
            = ((IData)(1U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__words_written);
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk1__DOT__i);
    }
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_valid = 0U;
    VL_WRITEF("[%0t] Write complete: %0d words\n\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->pingpong_buffer_sp_tb_simple__DOT__words_written);
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       111);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_ready) {
        VL_WRITEF("[%0t] buf_ready asserted, buf_id=%0#\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,1,(IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_id));
    } else {
        VL_WRITEF("ERROR: buf_ready not asserted after 256 writes!\n");
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors 
            = ((IData)(1U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors);
    }
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       120);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_take = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       122);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_take = 0U;
    VL_WRITEF("[%0t] Buffer taken\n\n[%0t] Reading 256 samples...\n",
              64,VL_TIME_UNITED_Q(1000),-9,64,VL_TIME_UNITED_Q(1000),
              -9);
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_ready = 1U;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk2__DOT__i = 0U;
    while (VL_GTS_III(32, 0x100U, vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk2__DOT__i)) {
        co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                           "pingpong_buffer_sp_tb_simple.sv", 
                                                           130);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_valid))))) {
            VL_WRITEF("ERROR: rd_valid not asserted for word %0d!\n",
                      32,vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk2__DOT__i);
            vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors 
                = ((IData)(1U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors);
            while ((1U & (~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_valid)))) {
                co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                                   nullptr, 
                                                                   "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                                   "pingpong_buffer_sp_tb_simple.sv", 
                                                                   137);
                vlSelf->__Vm_traceActivity[2U] = 1U;
            }
        }
        if ((0xffU == vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk2__DOT__i)) {
            if (((1U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state)) 
                 & (0xffU == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr)))) {
                VL_WRITEF("[%0t] rd_last asserted correctly on word %0d\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk2__DOT__i);
            } else {
                VL_WRITEF("ERROR: rd_last not asserted on final word!\n");
                vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors 
                    = ((IData)(1U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors);
            }
        }
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__expected_data 
            = (0xffffU & ((IData)(0x1000U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk2__DOT__i));
        if (VL_UNLIKELY(((0xffffU & ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_sel)
                                      ? vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__read_data
                                      : vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__read_data)) 
                         != (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__expected_data)))) {
            VL_WRITEF("ERROR: Word %0d mismatch! Expected 0x%04x, got 0x%04x\n",
                      32,vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk2__DOT__i,
                      16,(IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__expected_data),
                      16,(0xffffU & ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_sel)
                                      ? vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__read_data
                                      : vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__read_data)));
            vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors 
                = ((IData)(1U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors);
        }
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__words_read 
            = ((IData)(1U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__words_read);
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk2__DOT__i 
            = ((IData)(1U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__unnamedblk2__DOT__i);
    }
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_ready = 0U;
    VL_WRITEF("[%0t] Read complete: %0d words\n\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->pingpong_buffer_sp_tb_simple__DOT__words_read);
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       164);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_valid)) {
        VL_WRITEF("ERROR: rd_valid still high after read complete!\n");
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors 
            = ((IData)(1U) + vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors);
    }
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       171);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       171);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       171);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       171);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       171);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       171);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       171);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       171);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       171);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h28b425f1__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_buffer_sp_tb_simple.clk)", 
                                                       "pingpong_buffer_sp_tb_simple.sv", 
                                                       171);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("\n===================================\nTest Summary\n===================================\nWords written: %0d\nWords read:    %0d\nErrors:        %0d\n",
              32,vlSelf->pingpong_buffer_sp_tb_simple__DOT__words_written,
              32,vlSelf->pingpong_buffer_sp_tb_simple__DOT__words_read,
              32,vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors);
    if ((0U == vlSelf->pingpong_buffer_sp_tb_simple__DOT__errors)) {
        VL_WRITEF("\n*** ALL TESTS PASSED ***\n\n");
    } else {
        VL_WRITEF("\n*** TESTS FAILED ***\n\n");
    }
    VL_FINISH_MT("pingpong_buffer_sp_tb_simple.sv", 185, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__act(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);
#endif  // VL_DEBUG

void Vpingpong_buffer_sp_tb_simple___024root___eval_triggers__act(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO 
                                     != vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO__1));
    vlSelf->__VactTriggered.set(1U, (vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO 
                                     != vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO__1));
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__clk__0))));
    vlSelf->__VactTriggered.set(3U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO__1 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO;
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO__1 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO;
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__clk__0 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__clk;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(0U, 1U);
        vlSelf->__VactTriggered.set(1U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__act(vlSelf);
    }
#endif
}
