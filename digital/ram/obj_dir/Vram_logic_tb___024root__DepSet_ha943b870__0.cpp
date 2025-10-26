// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram_logic_tb.h for the primary calling header

#include "Vram_logic_tb__pch.h"
#include "Vram_logic_tb__Syms.h"
#include "Vram_logic_tb___024root.h"

VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__0(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__1(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_2__0(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_2__1(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_3__0(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_3__1(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_4__0(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_4__1(Vram_logic_tb___024root* vlSelf);

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Init
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val = 0;
    SData/*15:0*/ __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data = 0;
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val = 0;
    SData/*15:0*/ __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data = 0;
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer;
    __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    VL_WRITEF("================================================================================\nRAM Logic Testbench Start\nParameters: WIDTH=16, DEPTH=16\n================================================================================\n");
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x635f7462U;
    __Vtemp_1[2U] = 0x6c6f6769U;
    __Vtemp_1[3U] = 0x72616d5fU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->ram_logic_tb__DOT__clk = 0U;
    vlSelf->ram_logic_tb__DOT__test_num = ((IData)(1U) 
                                           + vlSelf->ram_logic_tb__DOT__test_num);
    VL_WRITEF("\n[TEST %0d] Basic Reset Test\n",32,
              vlSelf->ram_logic_tb__DOT__test_num);
    VL_WRITEF("[%0t] Applying reset...\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    vlSelf->ram_logic_tb__DOT__rst_n = 0U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__write_data = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       105);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       105);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       105);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       105);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       105);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       107);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       107);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("[%0t] Reset complete\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    if ((((0x10U > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
          & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid))) 
         & (~ (IData)(vlSelf->ram_logic_tb__DOT__buffer_ready)))) {
        VL_WRITEF("[TEST %0d] PASSED - Initial state correct\n",
                  32,vlSelf->ram_logic_tb__DOT__test_num);
    } else {
        VL_WRITEF("[TEST %0d] FAILED - Initial state incorrect\n",
                  32,vlSelf->ram_logic_tb__DOT__test_num);
        vlSelf->ram_logic_tb__DOT__error_count = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__error_count);
    }
    vlSelf->ram_logic_tb__DOT__test_num = ((IData)(1U) 
                                           + vlSelf->ram_logic_tb__DOT__test_num);
    VL_WRITEF("\n[TEST %0d] Write First Buffer\n",32,
              vlSelf->ram_logic_tb__DOT__test_num);
    vlSelf->__Vfork_1__sync.init(2U, nullptr);
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__0(vlSelf);
    vlSelf->__Vm_traceActivity[3U] = 1U;
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__1(vlSelf);
    co_await vlSelf->__Vfork_1__sync.join(nullptr, 
                                          "ram_logic_tb.sv", 
                                          247);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       264);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       264);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       264);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       264);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       264);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__test_num = ((IData)(1U) 
                                           + vlSelf->ram_logic_tb__DOT__test_num);
    VL_WRITEF("\n[TEST %0d] Read and Verify First Buffer\n",
              32,vlSelf->ram_logic_tb__DOT__test_num);
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 2U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 3U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 4U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 5U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 6U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 7U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 8U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 9U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 0xaU;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 0xbU;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 0xcU;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 0xdU;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 0xeU;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 0xfU;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           277);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
                                                       288);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 0x10U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    VL_WRITEF("[TEST %0d] PASSED - Buffer read complete\n",
              32,vlSelf->ram_logic_tb__DOT__test_num);
    vlSelf->ram_logic_tb__DOT__test_num = ((IData)(1U) 
                                           + vlSelf->ram_logic_tb__DOT__test_num);
    VL_WRITEF("\n[TEST %0d] Continuous Ping-Pong Operation (3 buffers)\n",
              32,vlSelf->ram_logic_tb__DOT__test_num);
    vlSelf->__Vfork_2__sync.init(2U, nullptr);
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_2__0(vlSelf);
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_2__1(vlSelf);
    co_await vlSelf->__Vfork_2__sync.join(nullptr, 
                                          "ram_logic_tb.sv", 
                                          300);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__test_num = ((IData)(1U) 
                                           + vlSelf->ram_logic_tb__DOT__test_num);
    VL_WRITEF("\n[TEST %0d] Write Buffer with Slow Reader\n",
              32,vlSelf->ram_logic_tb__DOT__test_num);
    vlSelf->__Vfork_3__sync.init(2U, nullptr);
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_3__0(vlSelf);
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_3__1(vlSelf);
    co_await vlSelf->__Vfork_3__sync.join(nullptr, 
                                          "ram_logic_tb.sv", 
                                          324);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       334);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       334);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       334);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       334);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       334);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       334);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       334);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       334);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       334);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       334);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__test_num = ((IData)(1U) 
                                           + vlSelf->ram_logic_tb__DOT__test_num);
    VL_WRITEF("\n[TEST %0d] Overflow Detection Test\n",
              32,vlSelf->ram_logic_tb__DOT__test_num);
    VL_WRITEF("[%0t] Applying reset...\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    vlSelf->ram_logic_tb__DOT__rst_n = 0U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__write_data = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       105);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       105);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       105);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       105);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       105);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       107);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       107);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("[%0t] Reset complete\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val = 0xb00U;
    VL_WRITEF("[%0t] Writing buffer %0d with values %0d to %0d\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->ram_logic_tb__DOT__buffer_number,
              32,__Vtask_ram_logic_tb__DOT__write_buffer__7__start_val,
              32,((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val);
    vlSelf->ram_logic_tb__DOT__expected_buffer[0U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(1U) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[1U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(2U) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[2U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(3U) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[3U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(4U) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[4U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(5U) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[5U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(6U) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[6U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(7U) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[7U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(8U) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[8U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(9U) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[9U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xaU) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xaU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xbU) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xbU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xcU) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xcU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xdU) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xdU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xeU) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xeU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__7__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xfU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__7__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__buffer_number = ((IData)(1U) 
                                                + vlSelf->ram_logic_tb__DOT__buffer_number);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       144);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       347);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_data = 0xdeadU;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       350);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->ram_logic_tb__DOT__buffer_overflow) {
        VL_WRITEF("[TEST %0d] PASSED - Overflow detected\n",
                  32,vlSelf->ram_logic_tb__DOT__test_num);
    } else {
        VL_WRITEF("[TEST %0d] INFO - Overflow not detected (may be expected)\n",
                  32,vlSelf->ram_logic_tb__DOT__test_num);
    }
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       359);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       359);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       359);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       359);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       359);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__test_num = ((IData)(1U) 
                                           + vlSelf->ram_logic_tb__DOT__test_num);
    VL_WRITEF("\n[TEST %0d] Interleaved Read/Write Operations\n",
              32,vlSelf->ram_logic_tb__DOT__test_num);
    __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val = 0xc00U;
    VL_WRITEF("[%0t] Writing buffer %0d with values %0d to %0d\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->ram_logic_tb__DOT__buffer_number,
              32,__Vtask_ram_logic_tb__DOT__write_buffer__8__start_val,
              32,((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val);
    vlSelf->ram_logic_tb__DOT__expected_buffer[0U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(1U) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[1U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(2U) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[2U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(3U) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[3U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(4U) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[4U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(5U) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[5U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(6U) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[6U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(7U) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[7U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(8U) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[8U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(9U) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[9U] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xaU) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xaU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xbU) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xbU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xcU) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xcU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xdU) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xdU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xeU) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xeU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data 
        = (0xffffU & ((IData)(0xfU) + __Vtask_ram_logic_tb__DOT__write_buffer__8__start_val));
    vlSelf->ram_logic_tb__DOT__expected_buffer[0xfU] 
        = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_buffer__8__unnamedblk1__DOT__unnamedblk2__DOT__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
                  | (~ (IData)(vlSelf->ram_logic_tb__DOT__write_valid))))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           135);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__buffer_number = ((IData)(1U) 
                                                + vlSelf->ram_logic_tb__DOT__buffer_number);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       144);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vfork_4__sync.init(2U, nullptr);
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_4__0(vlSelf);
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_4__1(vlSelf);
    co_await vlSelf->__Vfork_4__sync.join(nullptr, 
                                          "ram_logic_tb.sv", 
                                          371);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer = 0U;
    VL_WRITEF("[%0t] Reading and verifying buffer...\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__buffer_ready)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           154);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           161);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
        __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer 
            = ((IData)(1U) + __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    if ((0U == __Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer)) {
        VL_WRITEF("[%0t] Buffer verification PASSED - all 16 samples correct\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
    } else {
        VL_WRITEF("[%0t] Buffer verification FAILED - %0d errors\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,__Vtask_ram_logic_tb__DOT__read_verify_buffer__11__errors_this_buffer);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       389);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("\n================================================================================\nTestbench Complete\n================================================================================\nTotal tests run: %0d\nTotal errors: %0d\n",
              32,vlSelf->ram_logic_tb__DOT__test_num,
              32,vlSelf->ram_logic_tb__DOT__error_count);
    if ((0U == vlSelf->ram_logic_tb__DOT__error_count)) {
        VL_WRITEF("*** ALL TESTS PASSED ***\n");
    } else {
        VL_WRITEF("*** TESTS FAILED - %0d errors ***\n",
                  32,vlSelf->ram_logic_tb__DOT__error_count);
    }
    VL_WRITEF("================================================================================\n");
    VL_FINISH_MT("ram_logic_tb.sv", 404, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_logic_tb___024root___dump_triggers__act(Vram_logic_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vram_logic_tb___024root___eval_triggers__act(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->ram_logic_tb__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__ram_logic_tb__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__ram_logic_tb__DOT__clk__0 
        = vlSelf->ram_logic_tb__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vram_logic_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
