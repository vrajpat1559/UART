// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_tx.h for the primary calling header

#include "Vtb_uart_tx__pch.h"

void Vtb_uart_tx___024root___timing_ready(Vtb_uart_tx___024root* vlSelf);

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_static(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_static\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        vlSelfRef.tb_uart_tx__DOT__errors = 0U;
        vlSelfRef.tb_uart_tx__DOT__tests_run = 0U;
    }
    vlSelfRef.__Vtrigprevexpr___TOP__tb_uart_tx__DOT__clk__0 
        = vlSelfRef.tb_uart_tx__DOT__clk;
    Vtb_uart_tx___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_uart_tx___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

VL_ATTR_COLD bool Vtb_uart_tx___024root___eval_stl(Vtb_uart_tx___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_stl\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_uart_tx___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_uart_tx___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                {
                    // Inlined CFunc: _act_sequent__TOP__0
                    vlSelfRef.tb_uart_tx__DOT__dut__DOT__state_next 
                        = (3U & ((2U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state))
                                  ? ((1U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state))
                                      ? ((IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state) 
                                         & (- (IData)(
                                                      (0x009fU 
                                                       != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__cycle_cnt)))))
                                      : ((IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state) 
                                         | (- (IData)(
                                                      ((0x009fU 
                                                        == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__cycle_cnt)) 
                                                       & (7U 
                                                          == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_idx)))))))
                                  : ((1U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state))
                                      ? ((0x009fU == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__cycle_cnt))
                                          ? 2U : (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state))
                                      : ((IData)(vlSelfRef.tb_uart_tx__DOT__tx_start)
                                          ? 1U : (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__state)))));
                }
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_dump_triggers__stl(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_dump_triggers__stl\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_uart_tx___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_dump_triggers__ico(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_dump_triggers__ico\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_uart_tx___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_dump_triggers__act(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_dump_triggers__act\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_uart_tx___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_dump_triggers__nba(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_dump_triggers__nba\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_uart_tx___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_dump_triggers__obs(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_dump_triggers__obs\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_dump_triggers__react(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_dump_triggers__react\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_final(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_final\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_uart_tx___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_uart_tx___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

bool Vtb_uart_tx___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_uart_tx___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtb_uart_tx___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_uart_tx___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_uart_tx.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_uart_tx___024root___ctor_var_reset(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___ctor_var_reset\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_uart_tx__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4909121462720714774ull);
    vlSelf->tb_uart_tx__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14155515402027574779ull);
    vlSelf->tb_uart_tx__DOT__tx_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1242294580363250427ull);
    vlSelf->tb_uart_tx__DOT__tx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12702062035842614992ull);
    vlSelf->tb_uart_tx__DOT__tx_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14772283692851637980ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10964300233926577061ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__state_next = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13812546068401785099ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__cycle_cnt = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 3390864566377365244ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__bit_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13381771076961777091ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__data_shift = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5653068381679520949ull);
    vlSelf->__VdlyVal__tb_uart_tx__DOT__tx_data__v0 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_data__v0 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_start__v0 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_start__v1 = 0;
    vlSelf->__VdlyVal__tb_uart_tx__DOT__tx_data__v1 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_data__v1 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_start__v2 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_start__v3 = 0;
    vlSelf->__VdlyVal__tb_uart_tx__DOT__tx_data__v2 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_data__v2 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_start__v4 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_start__v5 = 0;
    vlSelf->__VdlyVal__tb_uart_tx__DOT__tx_data__v3 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_data__v3 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_start__v6 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_start__v7 = 0;
    vlSelf->__VdlyVal__tb_uart_tx__DOT__tx_data__v4 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_data__v4 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_start__v8 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_start__v9 = 0;
    vlSelf->__VdlyVal__tb_uart_tx__DOT__tx_data__v5 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_data__v5 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_start__v10 = 0;
    vlSelf->__VdlySet__tb_uart_tx__DOT__tx_start__v11 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_tx__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
