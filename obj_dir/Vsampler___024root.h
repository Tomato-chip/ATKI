// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsampler.h for the primary calling header

#ifndef VERILATED_VSAMPLER___024ROOT_H_
#define VERILATED_VSAMPLER___024ROOT_H_  // guard

#include "verilated.h"


class Vsampler__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsampler___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(mic_valid_i,0,0);
    VL_OUT8(buf_ready_pulse_o,0,0);
    VL_OUT8(buf_ready_ch_o,0,0);
    VL_OUT8(active_buf_o,0,0);
    CData/*0:0*/ sampler__DOT__ch_buf_ready_pulse;
    CData/*0:0*/ sampler__DOT__ch_active_buf;
    CData/*7:0*/ sampler__DOT__channel_0_buffer__DOT__write_addr;
    CData/*0:0*/ sampler__DOT__channel_0_buffer__DOT__buffer_full;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk_i__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VL_IN16(mic_data_i[1],15,0);
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsampler__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsampler___024root(Vsampler__Syms* symsp, const char* v__name);
    ~Vsampler___024root();
    VL_UNCOPYABLE(Vsampler___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
