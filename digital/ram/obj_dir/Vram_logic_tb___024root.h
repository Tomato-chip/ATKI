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
    CData/*0:0*/ ram_logic_tb__DOT__unnamedblk5__DOT__saw_buffer_ready;
    CData/*3:0*/ ram_logic_tb__DOT__dut__DOT__write_address;
    CData/*3:0*/ ram_logic_tb__DOT__dut__DOT__read_address;
    CData/*4:0*/ ram_logic_tb__DOT__dut__DOT__write_count;
    CData/*4:0*/ ram_logic_tb__DOT__dut__DOT__read_count;
    CData/*0:0*/ ram_logic_tb__DOT__dut__DOT__write_buffer_sel;
    CData/*0:0*/ ram_logic_tb__DOT__dut__DOT__read_buffer_sel;
    CData/*0:0*/ ram_logic_tb__DOT__dut__DOT__read_buffer_valid;
    CData/*0:0*/ ram_logic_tb__DOT__dut__DOT__read_in_progress;
    CData/*0:0*/ ram_logic_tb__DOT__dut__DOT__write_accepted;
    CData/*0:0*/ ram_logic_tb__DOT__dut__DOT__read_accepted;
    CData/*0:0*/ ram_logic_tb__DOT__dut__DOT__ram0_write_enable;
    CData/*0:0*/ ram_logic_tb__DOT__dut__DOT__ram1_write_enable;
    CData/*3:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__12__addr;
    CData/*3:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__13__addr;
    CData/*3:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__14__addr;
    CData/*3:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__15__addr;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__ram_logic_tb__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ ram_logic_tb__DOT__write_data;
    SData/*13:0*/ ram_logic_tb__DOT__dut__DOT__ram0_address;
    SData/*13:0*/ ram_logic_tb__DOT__dut__DOT__ram1_address;
    SData/*13:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__12__Vfuncout;
    SData/*13:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__13__Vfuncout;
    SData/*13:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__14__Vfuncout;
    SData/*13:0*/ __Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__15__Vfuncout;
    IData/*31:0*/ ram_logic_tb__DOT__error_count;
    IData/*31:0*/ ram_logic_tb__DOT__test_num;
    IData/*31:0*/ ram_logic_tb__DOT__buffer_number;
    IData/*31:0*/ ram_logic_tb__DOT__unnamedblk6__DOT__i;
    IData/*31:0*/ ram_logic_tb__DOT__unnamedblk7__DOT__buf_idx;
    IData/*31:0*/ ram_logic_tb__DOT__unnamedblk8__DOT__buf_idx;
    IData/*31:0*/ ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO;
    IData/*31:0*/ ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO;
    IData/*31:0*/ ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__do_pipeline;
    IData/*31:0*/ ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__i;
    IData/*31:0*/ ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__do_pipeline;
    IData/*31:0*/ ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 16> ram_logic_tb__DOT__expected_buffer;
    VlUnpacked<IData/*31:0*/, 1024> ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem;
    VlUnpacked<IData/*31:0*/, 1024> ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem;
    VlUnpacked<CData/*0:0*/, 9> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h108cd1ff__0;
    VlForkSync __Vfork_1__sync;
    VlForkSync __Vfork_2__sync;
    VlForkSync __Vfork_3__sync;
    VlForkSync __Vfork_4__sync;
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
