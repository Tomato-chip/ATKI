// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfpga_template_top_tb__Syms.h"


void Vfpga_template_top_tb___024root__trace_chg_0_sub_0(Vfpga_template_top_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vfpga_template_top_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root__trace_chg_0\n"); );
    // Init
    Vfpga_template_top_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfpga_template_top_tb___024root*>(voidSelf);
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vfpga_template_top_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vfpga_template_top_tb___024root__trace_chg_0_sub_0(Vfpga_template_top_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__do_pipeline),32);
        bufp->chgIData(oldp+1,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__i),32);
        bufp->chgIData(oldp+2,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__do_pipeline),32);
        bufp->chgIData(oldp+3,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgCData(oldp+4,((0x3fU & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led)))),6);
        bufp->chgBit(oldp+5,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q));
        bufp->chgBit(oldp+6,(vlSelf->fpga_template_top_tb__DOT__buffer_full));
        bufp->chgIData(oldp+7,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left),24);
        bufp->chgIData(oldp+8,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_right),24);
        bufp->chgCData(oldp+9,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led),6);
        bufp->chgIData(oldp+10,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left),32);
        bufp->chgIData(oldp+11,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_right),32);
        bufp->chgBit(oldp+12,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w));
        bufp->chgIData(oldp+13,(((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid)
                                  ? vlSelf->__VdfgTmp_hb1fddee5__0
                                  : 0U)),32);
        bufp->chgBit(oldp+14,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w));
        bufp->chgBit(oldp+15,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__ram_ready_q));
        bufp->chgBit(oldp+16,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w));
        bufp->chgBit(oldp+17,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__frame_start_q));
        bufp->chgCData(oldp+18,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_ctr_q),3);
        bufp->chgBit(oldp+19,(((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q)) 
                               & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q))));
        bufp->chgBit(oldp+20,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q));
        bufp->chgCData(oldp+21,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q),6);
        bufp->chgIData(oldp+22,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_period_cycles),32);
        bufp->chgIData(oldp+23,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_last_toggle_time),32);
        bufp->chgBit(oldp+24,((0x10U > (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count))));
        bufp->chgCData(oldp+25,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count),6);
        bufp->chgCData(oldp+26,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count),6);
        bufp->chgCData(oldp+27,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address),5);
        bufp->chgCData(oldp+28,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address),5);
        bufp->chgBit(oldp+29,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel));
        bufp->chgBit(oldp+30,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_sel));
        bufp->chgBit(oldp+31,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid));
        bufp->chgBit(oldp+32,((0x10U <= (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count))));
        bufp->chgBit(oldp+33,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress));
        bufp->chgBit(oldp+34,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted));
        bufp->chgBit(oldp+35,(((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w) 
                               & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w))));
        bufp->chgSData(oldp+36,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address),14);
        bufp->chgSData(oldp+37,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address),14);
        bufp->chgBit(oldp+38,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_write_enable));
        bufp->chgBit(oldp+39,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_write_enable));
        bufp->chgSData(oldp+40,((0x1ffU & ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address) 
                                           >> 5U))),9);
        bufp->chgSData(oldp+41,((0x1ffU & ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address) 
                                           >> 5U))),9);
        bufp->chgBit(oldp+42,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_d));
        bufp->chgBit(oldp+43,(((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q)) 
                               & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q))));
        bufp->chgIData(oldp+44,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q),25);
        bufp->chgCData(oldp+45,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q),6);
        bufp->chgBit(oldp+46,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q));
        bufp->chgBit(oldp+47,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q));
        bufp->chgBit(oldp+48,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__channel_q));
        bufp->chgIData(oldp+49,(vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i),24);
        bufp->chgBit(oldp+50,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__sample_valid));
        bufp->chgBit(oldp+51,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q));
        bufp->chgIData(oldp+52,((0xffffffU & (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid) 
                                               & (vlSelf->__VdfgTmp_hb1fddee5__0 
                                                  >> 0x17U))
                                               ? ((IData)(1U) 
                                                  + 
                                                  (~ vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i))
                                               : vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i))),24);
        bufp->chgIData(oldp+53,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q),32);
        bufp->chgIData(oldp+54,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q),20);
        bufp->chgBit(oldp+55,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__tick));
        bufp->chgCData(oldp+56,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next),6);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+57,(vlSelf->fpga_template_top_tb__DOT__mic_sd_0));
        bufp->chgIData(oldp+58,(vlSelf->fpga_template_top_tb__DOT__bit_counter),32);
        bufp->chgIData(oldp+59,(vlSelf->fpga_template_top_tb__DOT__left_shift_reg),25);
        bufp->chgIData(oldp+60,(vlSelf->fpga_template_top_tb__DOT__right_shift_reg),25);
    }
    bufp->chgBit(oldp+61,(vlSelf->fpga_template_top_tb__DOT__clk));
    bufp->chgBit(oldp+62,(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb));
    bufp->chgBit(oldp+63,(vlSelf->fpga_template_top_tb__DOT__btn_s2));
    bufp->chgBit(oldp+64,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q));
    bufp->chgIData(oldp+65,(vlSelf->fpga_template_top_tb__DOT__sample_count),32);
    bufp->chgIData(oldp+66,(vlSelf->fpga_template_top_tb__DOT__buffer_swap_count),32);
    bufp->chgIData(oldp+67,(vlSelf->fpga_template_top_tb__DOT__handshake_count),32);
    bufp->chgIData(oldp+68,(vlSelf->fpga_template_top_tb__DOT__ready_low_cycles),32);
    bufp->chgBit(oldp+69,(vlSelf->fpga_template_top_tb__DOT__monitor_handshake));
    bufp->chgIData(oldp+70,(vlSelf->fpga_template_top_tb__DOT__left_sample),24);
    bufp->chgIData(oldp+71,(vlSelf->fpga_template_top_tb__DOT__right_sample),24);
    bufp->chgBit(oldp+72,(vlSelf->fpga_template_top_tb__DOT__prev_sample_valid));
    bufp->chgCData(oldp+73,(vlSelf->fpga_template_top_tb__DOT__prev_leds),6);
    bufp->chgIData(oldp+74,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_data_out),32);
    bufp->chgIData(oldp+75,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_data_out),32);
    bufp->chgBit(oldp+76,(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_edge));
}

void Vfpga_template_top_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root__trace_cleanup\n"); );
    // Init
    Vfpga_template_top_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfpga_template_top_tb___024root*>(voidSelf);
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
