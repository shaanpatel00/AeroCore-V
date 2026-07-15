#include <iostream>
#include <verilated.h>
#include "Vsoc_top.h"
#include "Vsoc_top___024root.h"

// --- MUST BE IN GLOBAL SCOPE ---
// Verilator requires this function to track simulation time
double sc_time_stamp() {
    return 0;
}
// -------------------------------

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vsoc_top* top = new Vsoc_top;

    // Initialize inputs
    top->clk = 0;
    top->rst_n = 0;

    // Assert reset for 5 cycles
    for (int i = 0; i < 10; ++i) {
        top->clk = !top->clk;
        top->eval();
    }
    top->rst_n = 1; // Release reset

    std::cout << "[VERILATOR] Starting AeroCore-V SoC Simulation..." << std::endl;

    int max_cycles = 200000;
    int cycle_count = 0;
    long stall_cycles = 0;
    long total_requests = 0;
    bool prev_req = false;

    while (!Verilated::gotFinish() && cycle_count < max_cycles) {
        top->clk = 1; top->eval();
        top->clk = 0; top->eval();
        cycle_count++;
        bool req_now = top->rootp->soc_top__DOT__dcache_req;
        if (req_now && !prev_req) total_requests++;
        prev_req = req_now;

        #ifdef BYPASS_L1
        if (req_now && !top->rootp->soc_top__DOT__l1_mem_valid) {
            stall_cycles++;
        }
        #else
        if (req_now && !top->rootp->soc_top__DOT__core_dcache_valid) {
            stall_cycles++;
        }
        #endif
    }

    std::cout << "[BENCH] total_cycles=" << cycle_count
               << " total_requests=" << total_requests
               << " stall_cycles=" << stall_cycles
               << " stall_pct=" << (100.0 * stall_cycles / cycle_count) << "%"
               << std::endl;

    // If the loop finished but $finish wasn't called, it means we timed out
    if (!Verilated::gotFinish()) {
        std::cout << "\n[VERIFICATION] RESULT: TIMEOUT (Max cycles reached)" << std::endl;
        delete top;
        exit(1); // Return error code for CI
    }

    // Clean up
    delete top;
    return 0;
}