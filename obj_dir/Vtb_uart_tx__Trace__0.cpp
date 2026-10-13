// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_uart_tx__Syms.h"


void Vtb_uart_tx___024root__trace_chg_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_uart_tx___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_chg_0\n"); );
    // Body
    Vtb_uart_tx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_tx___024root*>(voidSelf);
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_uart_tx___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_uart_tx___024root__trace_chg_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_chg_0_sub_0\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgBit(oldp+0,((1U & ((2U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state))
                                     ? ((1U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state)) 
                                        || (1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__data_shift) 
                                                  >> (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_idx))))
                                     : (~ (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state))))));
        bufp->chgBit(oldp+1,((0U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state))));
        bufp->chgBit(oldp+2,(vlSelfRef.tb_uart_tx__DOT__tx_done));
        bufp->chgCData(oldp+3,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state),2);
        bufp->chgSData(oldp+4,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__cycle_cnt),9);
        bufp->chgCData(oldp+5,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_idx),3);
        bufp->chgCData(oldp+6,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__data_shift),8);
    }
    bufp->chgBit(oldp+7,(vlSelfRef.tb_uart_tx__DOT__clk));
    bufp->chgBit(oldp+8,(vlSelfRef.tb_uart_tx__DOT__rst_n));
    bufp->chgBit(oldp+9,(vlSelfRef.tb_uart_tx__DOT__tx_start));
    bufp->chgCData(oldp+10,(vlSelfRef.tb_uart_tx__DOT__tx_data),8);
    bufp->chgIData(oldp+11,(vlSelfRef.tb_uart_tx__DOT__errors),32);
    bufp->chgIData(oldp+12,(vlSelfRef.tb_uart_tx__DOT__tests_run),32);
    bufp->chgCData(oldp+13,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state_next),2);
}

void Vtb_uart_tx___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_cleanup\n"); );
    // Body
    Vtb_uart_tx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_tx___024root*>(voidSelf);
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
