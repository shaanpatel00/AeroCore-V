# --- Configuration ---
MODULE := Vsoc_top
RTL_DIR := ../../rtl
TWIN_DIR := ../digital_twin

# Source Files
RTL_SRCS := $(RTL_DIR)/core/riscv_pkg.sv \
            $(RTL_DIR)/core/alu_pid.sv \
            $(RTL_DIR)/core/regfile.sv \
            $(RTL_DIR)/core/fetch.sv \
            $(RTL_DIR)/core/decode.sv \
            $(RTL_DIR)/core/execute.sv \
            $(RTL_DIR)/core/riscv_core.sv \
            $(RTL_DIR)/cache/cache_mem.sv \
            $(RTL_DIR)/cache/l1_controller.sv \
            $(RTL_DIR)/cache/l2_controller.sv \
            $(RTL_DIR)/mmu/tlb.sv \
            $(RTL_DIR)/mmu/ptw.sv \
            $(RTL_DIR)/peripherals/spi_wrappers.sv \
            $(RTL_DIR)/peripherals/uart.sv \
            $(RTL_DIR)/soc_top.sv

# Tools
VERILATOR := verilator
CXX := g++
CFLAGS := -std=c++11 -Wall -O2

# OpenGL Libs (For Digital Twin)
GL_LIBS := -lGL -lGLU -lglut

# --- Targets ---

.PHONY: all clean test twin

all: test twin

# 1. Headless Testbench (Compiles main_tb.cpp)
test: obj_dir/$(MODULE)__ALL.a
	@echo "--- Building Headless Sim ---"
	$(CXX) $(CFLAGS) -Iobj_dir -I$(VERILATOR_ROOT)/include \
		$(VERILATOR_ROOT)/include/verilated.cpp \
		$(VERILATOR_ROOT)/include/verilated_vcd_c.cpp \
		main_tb.cpp obj_dir/*.o \
		-o run_test
	@echo "Build Complete: ./run_test <hex_file>"

# 2. Digital Twin (Compiles bridge.cpp + physics + viz)
twin: obj_dir/$(MODULE)__ALL.a
	@echo "--- Building Digital Twin ---"
	$(CXX) $(CFLAGS) -Iobj_dir -I$(VERILATOR_ROOT)/include \
		-I$(TWIN_DIR) \
		$(VERILATOR_ROOT)/include/verilated.cpp \
		$(TWIN_DIR)/physics_engine.cpp \
		$(TWIN_DIR)/visualizer.cpp \
		$(TWIN_DIR)/bridge.cpp \
		obj_dir/*.o \
		$(GL_LIBS) \
		-o digital_twin
	@echo "Build Complete: ./digital_twin"

# 3. Verilate the RTL (Common Step)
obj_dir/$(MODULE)__ALL.a: $(RTL_SRCS)
	@echo "--- Verilating RTL ---"
	$(VERILATOR) --cc --exe --trace \
		-I$(RTL_DIR)/core -I$(RTL_DIR)/cache \
		-I$(RTL_DIR)/mmu -I$(RTL_DIR)/peripherals \
		--top-module soc_top \
		$(RTL_SRCS)
	make -C obj_dir -f Vsoc_top.mk

clean:
	rm -rf obj_dir run_test digital_twin trace.vcd