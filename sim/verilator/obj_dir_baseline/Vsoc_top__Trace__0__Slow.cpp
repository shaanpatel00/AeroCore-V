// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vsoc_top__Syms.h"


VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__RISCV_PKG__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsoc_top___024root__trace_init_dtype____0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_sub__TOP__0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "$rootio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+74,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+76,0,"ext_sensor_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+77,0,"spi_miso",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+78,0,"spi_mosi",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+79,0,"spi_sclk",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+80,0,"motor_pwm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "RISCV_PKG", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vsoc_top___024root__trace_init_sub__TOP__RISCV_PKG__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "soc_top", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+74,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+76,0,"ext_sensor_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+77,0,"spi_miso",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+78,0,"spi_mosi",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+79,0,"spi_sclk",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+80,0,"motor_pwm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"icache_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"icache_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"dcache_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"dcache_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+39,0,"dcache_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+40,0,"dcache_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+81,0,"icache_ram_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+82,0,"dcache_ram_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+83,0,"io_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+84,0,"uart_mock_rx_buffer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"l1_mem_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"l1_mem_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+85,0,"l1_mem_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+40,0,"l1_mem_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+39,0,"l1_mem_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"l1_mem_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+85,0,"core_dcache_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"core_dcache_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+93,0,"MEM_LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"mem_delay_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"mem_pending",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_core", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+74,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"icache_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"icache_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+81,0,"icache_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+94,0,"icache_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"dcache_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"dcache_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+39,0,"dcache_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+40,0,"dcache_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+85,0,"dcache_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"dcache_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"if_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+81,0,"if_instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"if_pc_plus_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+41,0,"id_alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+42,0,"id_op_a_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+43,0,"id_op_b_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+44,0,"id_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"id_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+45,0,"id_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"id_op_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"id_op_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+48,0,"id_pid_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"id_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+50,0,"id_wb_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+51,0,"id_wb_mux",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+95,0,"csr_kp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+96,0,"csr_ki",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+97,0,"csr_kd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+86,0,"pid_integ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"ex_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+52,0,"pid_integ_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+53,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+54,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+55,0,"is_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+56,0,"is_jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+57,0,"is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+87,0,"branch_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+88,0,"core_pc_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+89,0,"core_pc_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+58,0,"core_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+59,0,"id_wb_en_gated",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+90,0,"mem_read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+91,0,"core_wb_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_decode", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+74,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+81,0,"instr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+59,0,"wb_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"wb_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+91,0,"wb_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+41,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+42,0,"op_a_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+43,0,"op_b_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+45,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+39,0,"mem_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+40,0,"mem_re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+50,0,"wb_en_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+51,0,"wb_mux",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+48,0,"pid_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+44,0,"rs1_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"rs2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+60,0,"rs1_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+61,0,"rs2_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"rd_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+53,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+54,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+62,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_regfile", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+74,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+60,0,"raddr_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+44,0,"rdata_a",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+61,0,"raddr_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"rdata_b",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+91,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+59,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);

    Vsoc_top___024root__trace_init_dtype____0(vlSelf, tracep, "regs", 0, c+5, VerilatedTraceSigDirection::NONE);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_execute", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+74,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+41,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BIT(tracep,c+48,0,"pid_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"op_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"op_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+95,0,"pid_kp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+96,0,"pid_ki",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+97,0,"pid_kd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+52,0,"pid_integ_wb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+63,0,"std_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+64,0,"pid_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_pid_alu", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+74,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"error",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"prev_error",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+95,0,"coeff_kp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+96,0,"coeff_ki",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+97,0,"coeff_kd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+98,0,"dt_fixed",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+64,0,"control_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+52,0,"integ_update",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+99,0,"MAX_OUT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+100,0,"MIN_OUT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_QUAD(tracep,c+65,0,"p_term",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+67,0,"i_term",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+69,0,"d_term",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+71,0,"integral_accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+73,0,"error_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_fetch", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+74,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+58,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+88,0,"pc_load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+89,0,"pc_target",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"icache_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"icache_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+94,0,"icache_gnt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"pc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"pc_plus_4_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+92,0,"next_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_init_dtype_sub____0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vsoc_top___024root__trace_init_dtype____0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_dtype____0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsoc_top___024root__trace_init_dtype_sub____0(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_init_dtype_sub____0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_dtype_sub____0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 31);
    for (int i = 0; i < 32; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__RISCV_PKG__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_sub__TOP__RISCV_PKG__0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+101,0,"OPCODE_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+102,0,"OPCODE_OPIMM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+103,0,"OPCODE_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+104,0,"OPCODE_STORE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+105,0,"OPCODE_BRANCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+106,0,"OPCODE_JAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+107,0,"OPCODE_JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+108,0,"OPCODE_LUI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+109,0,"OPCODE_AUIPC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+110,0,"OPCODE_CUSTOM0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_init_top(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_top\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsoc_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vsoc_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsoc_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsoc_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsoc_top___024root__trace_register(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_register\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vsoc_top___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vsoc_top___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vsoc_top___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vsoc_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_const_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsoc_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_const_0\n"); );
    // Body
    Vsoc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc_top___024root*>(voidSelf);
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vsoc_top___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_const_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_const_0_sub_0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+93,(8U),32);
    bufp->fullBit(oldp+94,(1U));
    bufp->fullIData(oldp+95,(0x00050000U),32);
    bufp->fullIData(oldp+96,(0x00004cccU),32);
    bufp->fullIData(oldp+97,(0x00028000U),32);
    bufp->fullIData(oldp+98,(0x00010000U),32);
    bufp->fullIData(oldp+99,(0x00320000U),32);
    bufp->fullIData(oldp+100,(0xffce0000U),32);
    bufp->fullCData(oldp+101,(0x33U),7);
    bufp->fullCData(oldp+102,(0x13U),7);
    bufp->fullCData(oldp+103,(3U),7);
    bufp->fullCData(oldp+104,(0x23U),7);
    bufp->fullCData(oldp+105,(0x63U),7);
    bufp->fullCData(oldp+106,(0x6fU),7);
    bufp->fullCData(oldp+107,(0x67U),7);
    bufp->fullCData(oldp+108,(0x37U),7);
    bufp->fullCData(oldp+109,(0x17U),7);
    bufp->fullCData(oldp+110,(0x0bU),7);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_full_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsoc_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_full_0\n"); );
    // Body
    Vsoc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc_top___024root*>(voidSelf);
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vsoc_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_full_dtype____0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

VL_ATTR_COLD void Vsoc_top___024root__trace_full_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_full_0_sub_0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+0,(vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc),32);
    bufp->fullBit(oldp+1,(vlSelfRef.soc_top__DOT__l1_mem_valid));
    bufp->fullCData(oldp+2,(vlSelfRef.soc_top__DOT__mem_delay_cnt),4);
    bufp->fullBit(oldp+3,(vlSelfRef.soc_top__DOT__mem_pending));
    bufp->fullIData(oldp+4,(((IData)(4U) + vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc)),32);
    Vsoc_top___024root__trace_full_dtype____0(vlSelf, bufp, 5, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs);
    bufp->fullIData(oldp+37,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result),32);
    bufp->fullIData(oldp+38,(vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b),32);
    bufp->fullBit(oldp+39,(vlSelfRef.soc_top__DOT__dcache_we));
    bufp->fullBit(oldp+40,(vlSelfRef.soc_top__DOT__dcache_req));
    bufp->fullCData(oldp+41,(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op),7);
    bufp->fullCData(oldp+42,(vlSelfRef.soc_top__DOT__u_core__DOT__id_op_a_sel),2);
    bufp->fullCData(oldp+43,(vlSelfRef.soc_top__DOT__u_core__DOT__id_op_b_sel),2);
    bufp->fullIData(oldp+44,(vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a),32);
    bufp->fullIData(oldp+45,(vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm),32);
    bufp->fullIData(oldp+46,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error),32);
    bufp->fullIData(oldp+47,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error),32);
    bufp->fullBit(oldp+48,(vlSelfRef.soc_top__DOT__u_core__DOT__id_pid_en));
    bufp->fullCData(oldp+49,(vlSelfRef.__VdfgRegularize_hebeb780c_0_2),5);
    bufp->fullBit(oldp+50,(vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_en));
    bufp->fullCData(oldp+51,(vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_mux),2);
    bufp->fullIData(oldp+52,(vlSelfRef.soc_top__DOT__u_core__DOT__pid_integ_next),32);
    bufp->fullCData(oldp+53,(vlSelfRef.__VdfgRegularize_hebeb780c_0_0),7);
    bufp->fullCData(oldp+54,(vlSelfRef.__VdfgRegularize_hebeb780c_0_1),3);
    bufp->fullBit(oldp+55,((0x63U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))));
    bufp->fullBit(oldp+56,((0x6fU == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))));
    bufp->fullBit(oldp+57,((0x67U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))));
    bufp->fullBit(oldp+58,(vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__stall));
    bufp->fullBit(oldp+59,(((~ (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__stall)) 
                            & (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_en))));
    bufp->fullCData(oldp+60,(vlSelfRef.__VdfgRegularize_hebeb780c_0_4),5);
    bufp->fullCData(oldp+61,(vlSelfRef.__VdfgRegularize_hebeb780c_0_5),5);
    bufp->fullCData(oldp+62,(vlSelfRef.__VdfgRegularize_hebeb780c_0_3),7);
    bufp->fullIData(oldp+63,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__std_result),32);
    bufp->fullIData(oldp+64,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__pid_result),32);
    bufp->fullQData(oldp+65,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__p_term),64);
    bufp->fullQData(oldp+67,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__i_term),64);
    bufp->fullQData(oldp+69,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__d_term),64);
    bufp->fullQData(oldp+71,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__integral_accum),64);
    bufp->fullIData(oldp+73,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error_diff),32);
    bufp->fullBit(oldp+74,(vlSelfRef.clk));
    bufp->fullBit(oldp+75,(vlSelfRef.rst_n));
    bufp->fullIData(oldp+76,(vlSelfRef.ext_sensor_data),32);
    bufp->fullBit(oldp+77,(vlSelfRef.spi_miso));
    bufp->fullBit(oldp+78,(vlSelfRef.spi_mosi));
    bufp->fullBit(oldp+79,(vlSelfRef.spi_sclk));
    bufp->fullCData(oldp+80,(vlSelfRef.motor_pwm),4);
    bufp->fullIData(oldp+81,(vlSelfRef.soc_top__DOT__ram
                             [(0x00000fffU & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                              >> 2U))]),32);
    bufp->fullIData(oldp+82,(vlSelfRef.soc_top__DOT__ram
                             [(0x00000fffU & (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result 
                                              >> 2U))]),32);
    bufp->fullIData(oldp+83,(vlSelfRef.soc_top__DOT__io_rdata),32);
    bufp->fullCData(oldp+84,(vlSelfRef.soc_top__DOT__uart_mock_rx_buffer),8);
    bufp->fullIData(oldp+85,(vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata),32);
    bufp->fullIData(oldp+86,(vlSelfRef.soc_top__DOT__u_core__DOT__pid_integ),32);
    bufp->fullBit(oldp+87,(((0x63U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                            & ((0x00004000U & vlSelfRef.soc_top__DOT__ram
                                [(0x00000fffU & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                 >> 2U))])
                                ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)
                                    ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                        ? (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a 
                                           >= vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)
                                        : (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a 
                                           < vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b))
                                    : ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                        ? VL_GTES_III(32, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)
                                        : VL_LTS_III(32, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)))
                                : ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)) 
                                   & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                       ? (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b 
                                          != vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a)
                                       : (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b 
                                          == vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a)))))));
    bufp->fullBit(oldp+88,(((0x6fU == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                            | ((0x67U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                               | ((0x63U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                                  & ((0x00004000U & vlSelfRef.soc_top__DOT__ram
                                      [(0x00000fffU 
                                        & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                           >> 2U))])
                                      ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)
                                          ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                              ? (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a 
                                                 >= vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)
                                              : (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a 
                                                 < vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b))
                                          : ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                              ? VL_GTES_III(32, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)
                                              : VL_LTS_III(32, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)))
                                      : ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)) 
                                         & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                             ? (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b 
                                                != vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a)
                                             : (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b 
                                                == vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a)))))))));
    bufp->fullIData(oldp+89,(((0x67U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))
                               ? (0xfffffffeU & (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm 
                                                 + vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a))
                               : (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                  + vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm))),32);
    bufp->fullIData(oldp+90,(((3U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))
                               ? ((0U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                   ? ((2U & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                       ? ((1U & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                           ? (((- (IData)(
                                                          (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                           >> 0x0000001fU))) 
                                               << 8U) 
                                              | (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                 >> 0x00000018U))
                                           : (((- (IData)(
                                                          (1U 
                                                           & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                              >> 0x00000017U)))) 
                                               << 8U) 
                                              | (0x000000ffU 
                                                 & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                    >> 0x00000010U))))
                                       : ((1U & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                           ? (((- (IData)(
                                                          (1U 
                                                           & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                              >> 0x0000000fU)))) 
                                               << 8U) 
                                              | (0x000000ffU 
                                                 & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                    >> 8U)))
                                           : (((- (IData)(
                                                          (1U 
                                                           & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                              >> 7U)))) 
                                               << 8U) 
                                              | (0x000000ffU 
                                                 & vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata))))
                                   : ((4U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                       ? (0x000000ffU 
                                          & ((2U & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                              ? ((1U 
                                                  & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                                  ? 
                                                 (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                  >> 0x00000018U)
                                                  : 
                                                 (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                  >> 0x00000010U))
                                              : ((1U 
                                                  & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                                  ? 
                                                 (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                  >> 8U)
                                                  : vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata)))
                                       : vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata))
                               : vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata)),32);
    bufp->fullIData(oldp+91,(vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__wdata),32);
    bufp->fullIData(oldp+92,((((0x6fU == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                               | ((0x67U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                                  | ((0x63U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                                     & ((0x00004000U 
                                         & vlSelfRef.soc_top__DOT__ram
                                         [(0x00000fffU 
                                           & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                              >> 2U))])
                                         ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)
                                             ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                                 ? 
                                                (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a 
                                                 >= vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)
                                                 : 
                                                (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a 
                                                 < vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b))
                                             : ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                                 ? 
                                                VL_GTES_III(32, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)
                                                 : 
                                                VL_LTS_III(32, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)))
                                         : ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)) 
                                            & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                                ? (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b 
                                                   != vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a)
                                                : (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b 
                                                   == vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a)))))))
                               ? ((0x67U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))
                                   ? (0xfffffffeU & 
                                      (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm 
                                       + vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a))
                                   : (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                      + vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm))
                               : ((IData)(4U) + vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc))),32);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_full_dtype____0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_full_dtype____0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->fullIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->fullIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->fullIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->fullIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->fullIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->fullIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->fullIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->fullIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->fullIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->fullIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->fullIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->fullIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->fullIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->fullIData(oldp+15,(__VdtypeVar[15]),32);
    bufp->fullIData(oldp+16,(__VdtypeVar[16]),32);
    bufp->fullIData(oldp+17,(__VdtypeVar[17]),32);
    bufp->fullIData(oldp+18,(__VdtypeVar[18]),32);
    bufp->fullIData(oldp+19,(__VdtypeVar[19]),32);
    bufp->fullIData(oldp+20,(__VdtypeVar[20]),32);
    bufp->fullIData(oldp+21,(__VdtypeVar[21]),32);
    bufp->fullIData(oldp+22,(__VdtypeVar[22]),32);
    bufp->fullIData(oldp+23,(__VdtypeVar[23]),32);
    bufp->fullIData(oldp+24,(__VdtypeVar[24]),32);
    bufp->fullIData(oldp+25,(__VdtypeVar[25]),32);
    bufp->fullIData(oldp+26,(__VdtypeVar[26]),32);
    bufp->fullIData(oldp+27,(__VdtypeVar[27]),32);
    bufp->fullIData(oldp+28,(__VdtypeVar[28]),32);
    bufp->fullIData(oldp+29,(__VdtypeVar[29]),32);
    bufp->fullIData(oldp+30,(__VdtypeVar[30]),32);
    bufp->fullIData(oldp+31,(__VdtypeVar[31]),32);
}
