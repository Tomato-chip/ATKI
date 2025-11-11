// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vram_logic_tb.h for the primary calling header

#ifndef VERILATED_VRAM_LOGIC_TB___024ROOT_H_
#define VERILATED_VRAM_LOGIC_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vram_logic_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vram_logic_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ ram_logic_tb__DOT__clk;
    CData/*0:0*/ ram_logic_tb__DOT__rst_n;
    CData/*0:0*/ ram_logic_tb__DOT__write_valid;
    CData/*0:0*/ ram_logic_tb__DOT__read_ready;
    CData/*0:0*/ ram_logic_tb__DOT__read_valid;
    CData/*0:0*/ ram_logic_tb__DOT__buffer_ready;
    CData/*0:0*/ ram_logic_tb__DOT__buffer_overflow;
    CData/*1:0*/ ram_logic_tb__DOT__dut__DOT__state_q;
    CData/*1:0*/ ram_logic_tb__DOT__dut__DOT__state_d;
    CData/*3:0*/ ram_logic_tb__DOT__dut__DOT__write_addr_q;
    CData/*3:0*/ ram_logic_tb__DOT__dut__DOT__read_addr_q;
    CData/*4:0*/ ram_logic_tb__DOT__dut__DOT__write_count_q;
    CData/*4:0*/ ram_logic_tb__DOT__dut__DOT__read_count_q;
    CData/*0:0*/ ram_logic_tb__DOT__dut__DOT__write_buf_sel_q;
    CData/*0:0*/ ram_logic_tb__DOT__dut__DOT__read_buf_sel_q;
    CData/*0:0*/ ram_logic_tb__DOT__dut__DOT__write_accepted;
    CData/*0:0*/ ram_logic_tb__DOT__dut__DOT__read_accepted;
    CData/*3:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__21__addr;
    CData/*3:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__22__addr;
    CData/*3:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__23__addr;
    CData/*3:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__24__addr;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__ram_logic_tb__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*13:0*/ ram_logic_tb__DOT__dut__DOT__ram0_addr;
    SData/*13:0*/ ram_logic_tb__DOT__dut__DOT__ram1_addr;
    SData/*13:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__21__Vfuncout;
    SData/*13:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__22__Vfuncout;
    SData/*13:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__23__Vfuncout;
    SData/*13:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__24__Vfuncout;
    IData/*31:0*/ ram_logic_tb__DOT__write_data;
    IData/*31:0*/ ram_logic_tb__DOT__test_errors;
    IData/*31:0*/ ram_logic_tb__DOT__test_passed;
    IData/*31:0*/ ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 16> ram_logic_tb__DOT__test_data;
    VlUnpacked<IData/*31:0*/, 16> ram_logic_tb__DOT__read_back;
    VlUnpacked<IData/*31:0*/, 512> ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem;
    VlUnpacked<IData/*31:0*/, 512> ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h108cd1ff__0;
    VlForkSync __Vfork_1__sync;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vram_logic_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vram_logic_tb___024root(Vram_logic_tb__Syms* symsp, const char* v__name);
    ~Vram_logic_tb___024root();
    VL_UNCOPYABLE(Vram_logic_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
