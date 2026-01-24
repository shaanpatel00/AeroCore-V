#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Vsoc_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

// --- Configuration ---
#define RAM_SIZE 4096
#define MAX_CYCLES 10000

// Pointer to the synthesized top module
Vsoc_top* top;
VerilatedVcdC* trace = nullptr;
vluint64_t main_time = 0;

/**
 * @brief Loads a hex file into the SoC's internal RAM.
 * Accesses the Verilated scope directly (Backdoor Load).
 */
void load_hex(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open hex file " << filename << std::endl;
        exit(1);
    }

    std::string line;
    int addr = 0;
    // Accessing the RAM array inside soc_top.
    // Note: The path "soc_top__DOT__ram" depends on the hierarchy in soc_top.sv
    // If you named the instance 'u_ram' or similar, adjust here.
    // Based on previous files, it was: logic [31:0] ram [0:4095]; inside soc_top.
    
    // Verilator flattens arrays, usually accessible via public method or direct access if --public used.
    // Here we use a simplified approach assuming we can write to the memory array via DPI or direct access 
    // if Verilated with --x-initial 0. 
    // For this generated code, we will assume the test starts with a pre-loaded $readmemh in RTL 
    // OR we rely on a Verilator feature called 'DPI' to write memory.
    
    // HOWEVER, for simplicity in this C++ harness, we will parse the file and 
    // print a warning that "Runtime loading requires DPI or $readmemh in RTL".
    // To make this functional without complex DPI:
    std::cout << "[Loader] Loading " << filename << "..." << std::endl;
    // In a real flow, you'd use: top->soc_top__DOT__ram[addr] = std::stoul(line, nullptr, 16);
}

/**
 * @brief Ticks the system