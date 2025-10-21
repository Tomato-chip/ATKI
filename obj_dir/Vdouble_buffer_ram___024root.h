// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdouble_buffer_ram.h for the primary calling header

#ifndef VERILATED_VDOUBLE_BUFFER_RAM___024ROOT_H_
#define VERILATED_VDOUBLE_BUFFER_RAM___024ROOT_H_  // guard

#include "verilated.h"


class Vdouble_buffer_ram__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdouble_buffer_ram___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(in_valid_i,0,0);
    VL_OUT8(in_ready_o,0,0);
    VL_IN8(rd_addr_i,7,0);
    VL_IN8(rd_en_i,0,0);
    VL_OUT8(rd_data_valid_o,0,0);
    VL_OUT8(active_buf_o,0,0);
    VL_OUT8(buf_ready_pulse_o,0,0);
    VL_OUT8(buf_ready_id_o,0,0);
    CData/*7:0*/ double_buffer_ram__DOT__write_addr;
    CData/*0:0*/ double_buffer_ram__DOT__buffer_full;
    CData/*0:0*/ double_buffer_ram__DOT__rd_en_q;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk_i__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(in_data_i,15,0);
    VL_OUT16(rd_data_o,15,0);
    SData/*15:0*/ double_buffer_ram__DOT__ram_a_rdata;
    SData/*15:0*/ double_buffer_ram__DOT__ram_b_rdata;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 256> double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_a__DOT__mem;
    VlUnpacked<SData/*15:0*/, 256> double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_b__DOT__mem;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdouble_buffer_ram__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdouble_buffer_ram___024root(Vdouble_buffer_ram__Syms* symsp, const char* v__name);
    ~Vdouble_buffer_ram___024root();
    VL_UNCOPYABLE(Vdouble_buffer_ram___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
