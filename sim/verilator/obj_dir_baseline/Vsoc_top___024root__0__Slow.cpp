// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc_top.h for the primary calling header

#include "Vsoc_top__pch.h"

VL_ATTR_COLD void Vsoc_top___024root___eval_static(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_static\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ext_sensor_data__0 
        = vlSelfRef.ext_sensor_data;
    vlSelfRef.__Vtrigprevexpr___TOP__spi_miso__0 = vlSelfRef.spi_miso;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__1 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vsoc_top___024root___eval_initial(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_initial\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        VL_READMEM_N(true, 32, 4096, 0, "../../sw/kernel.hex"s
                     ,  &(vlSelfRef.soc_top__DOT__ram)
                     , 0, ~0ULL);
    }
}

VL_ATTR_COLD void Vsoc_top___024root___eval_final(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_final\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsoc_top___024root___eval_phase__stl(Vsoc_top___024root* vlSelf);

VL_ATTR_COLD void Vsoc_top___024root___eval_settle(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_settle\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vsoc_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("../../rtl/core/../../rtl/soc_top.sv", 1, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vsoc_top___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vsoc_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vsoc_top___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vsoc_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___trigger_anySet__stl\n"); );
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

void Vsoc_top___024root___nba_comb__TOP__0(Vsoc_top___024root* vlSelf);

VL_ATTR_COLD bool Vsoc_top___024root___eval_phase__stl(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_phase__stl\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsoc_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vsoc_top___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vsoc_top___024root___nba_comb__TOP__0(vlSelf);
                {
                    // Inlined CFunc: __Vm_traceActivitySetAll
                    vlSelfRef.__Vm_traceActivity[0U] = 1U;
                    vlSelfRef.__Vm_traceActivity[1U] = 1U;
                    vlSelfRef.__Vm_traceActivity[2U] = 1U;
                }
            }
        }
    }
    return (__VstlExecute);
}

bool Vsoc_top___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vsoc_top___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( ext_sensor_data)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( spi_miso)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vsoc_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vsoc_top___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsoc_top___024root___ctor_var_reset(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___ctor_var_reset\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->ext_sensor_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5236005040747592559ull);
    vlSelf->spi_miso = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12140560756394917646ull);
    vlSelf->spi_mosi = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 852284730959930751ull);
    vlSelf->spi_sclk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11093002469780296933ull);
    vlSelf->motor_pwm = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13729791733360175450ull);
    vlSelf->soc_top__DOT__dcache_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10040644742239883211ull);
    vlSelf->soc_top__DOT__dcache_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14684409796164047920ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->soc_top__DOT__ram[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17383027778387336553ull);
    }
    vlSelf->soc_top__DOT__io_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14541006962711705259ull);
    vlSelf->soc_top__DOT__uart_mock_rx_buffer = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13510867039817887957ull);
    vlSelf->soc_top__DOT__l1_mem_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10237282189756866466ull);
    vlSelf->soc_top__DOT__mem_delay_cnt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1930001486232317457ull);
    vlSelf->soc_top__DOT__mem_pending = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18346072485235213503ull);
    vlSelf->soc_top__DOT__u_core__DOT__dcache_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10715599094997775097ull);
    vlSelf->soc_top__DOT__u_core__DOT__id_alu_op = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 7760352982591441134ull);
    vlSelf->soc_top__DOT__u_core__DOT__id_op_a_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14827806355841756009ull);
    vlSelf->soc_top__DOT__u_core__DOT__id_op_b_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17924182778416197314ull);
    vlSelf->soc_top__DOT__u_core__DOT__id_pid_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13213856796916914398ull);
    vlSelf->soc_top__DOT__u_core__DOT__id_wb_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15172088622063352459ull);
    vlSelf->soc_top__DOT__u_core__DOT__id_wb_mux = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10238377544024298737ull);
    vlSelf->soc_top__DOT__u_core__DOT__pid_integ = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3659192609212747502ull);
    vlSelf->soc_top__DOT__u_core__DOT__pid_integ_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4975170707353217184ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16168006642748946275ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_execute__DOT__std_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6602597061516843433ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_execute__DOT__pid_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13288626510370742353ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7269507588786745699ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18303752950921784879ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__p_term = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2625522816542316451ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__i_term = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2175334909756617347ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__d_term = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10490268842152909013ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__integral_accum = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 18418097999434734837ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error_diff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8353649152947007415ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_decode__DOT__imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1366829323497798590ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9773356384630148012ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11228954394245551491ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12565996015046620314ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8454943715302893802ull);
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_fetch__DOT__stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11302155380995297394ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_fetch__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 632590389596197667ull);
    vlSelf->soc_top__DOT__u_core__DOT__u_fetch__DOT__next_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16623355072662580583ull);
    vlSelf->__VdfgRegularize_hebeb780c_0_0 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_1 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_2 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_3 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_4 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_5 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_12 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_20 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ext_sensor_data__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__spi_miso__0 = 0;
    vlSelf->__VicoDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__1 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
