// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_uart_tx__Syms.h"


VL_ATTR_COLD void Vtb_uart_tx___024root__trace_init_sub__TOP__0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_init_sub__TOP__0\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "tb_uart_tx", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+14,0,"CLK_FREQ_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"BAUD_RATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"CYCLES_PER_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+17,0,"CLK_PERIOD_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+8,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+9,0,"tx_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+10,0,"tx_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"tx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"tx_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"tx_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+11,0,"errors",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+12,0,"tests_run",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "dut", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+14,0,"CLK_FREQ_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"BAUD_RATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+8,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+9,0,"tx_start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+10,0,"tx_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"tx_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"tx_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"CYCLES_PER_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+13,0,"state_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"cycle_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 8,0);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"bit_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"data_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_init_top(Vtb_uart_tx___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_init_top\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_uart_tx___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_uart_tx___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_uart_tx___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_uart_tx___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_register(Vtb_uart_tx___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_register\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb_uart_tx___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtb_uart_tx___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtb_uart_tx___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtb_uart_tx___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_const_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_const_0\n"); );
    // Body
    Vtb_uart_tx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_tx___024root*>(voidSelf);
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_uart_tx___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_const_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_const_0_sub_0\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+14,(0x000f4240U),32);
    bufp->fullIData(oldp+15,(0x0000186aU),32);
    bufp->fullIData(oldp+16,(0x000000a0U),32);
    bufp->fullIData(oldp+17,(0x000003e8U),32);
}

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_full_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_full_0\n"); );
    // Body
    Vtb_uart_tx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_tx___024root*>(voidSelf);
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_uart_tx___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_full_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_full_0_sub_0\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,((1U & ((2U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state))
                                  ? ((1U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state)) 
                                     || (1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__data_shift) 
                                               >> (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_idx))))
                                  : (~ (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state))))));
    bufp->fullBit(oldp+1,((0U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state))));
    bufp->fullBit(oldp+2,(vlSelfRef.tb_uart_tx__DOT__tx_done));
    bufp->fullCData(oldp+3,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state),2);
    bufp->fullSData(oldp+4,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__cycle_cnt),9);
    bufp->fullCData(oldp+5,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_idx),3);
    bufp->fullCData(oldp+6,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__data_shift),8);
    bufp->fullBit(oldp+7,(vlSelfRef.tb_uart_tx__DOT__clk));
    bufp->fullBit(oldp+8,(vlSelfRef.tb_uart_tx__DOT__rst_n));
    bufp->fullBit(oldp+9,(vlSelfRef.tb_uart_tx__DOT__tx_start));
    bufp->fullCData(oldp+10,(vlSelfRef.tb_uart_tx__DOT__tx_data),8);
    bufp->fullIData(oldp+11,(vlSelfRef.tb_uart_tx__DOT__errors),32);
    bufp->fullIData(oldp+12,(vlSelfRef.tb_uart_tx__DOT__tests_run),32);
    bufp->fullCData(oldp+13,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state_next),2);
}
