#include <iostream>
#include <verilated.h>
#include "Vsoc_top.h"
#include "Vsoc_top___024root.h"
#include "verilated_vcd_c.h"

vluint64_t main_time = 0;

// --- MUST BE IN GLOBAL SCOPE ---
// Verilator requires this function to track simulation time
double sc_time_stamp() {
    return main_time;
}
// -------------------------------

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Vsoc_top* top = new Vsoc_top;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("trace.vcd");

    // Initialize inputs
    top->clk = 0;
    top->rst_n = 0;

    // Assert reset for 5 cycles
    for (int i = 0; i < 10; ++i) {
        top->clk = !top->clk;
        top->eval();
        tfp->dump(main_time++);
    }
    top->rst_n = 1; // Release reset

    std::cout << "[VERILATOR] Starting AeroCore-V SoC Simulation..." << std::endl;

    //TEMP REPLACEMENT
    int max_cycles = 100000000;
    int cycle_count = 0;
    long stall_cycles = 0;
    long total_requests = 0;
    bool prev_req = false;

    while (!Verilated::gotFinish() && cycle_count < max_cycles) {
        top->clk = 1; top->eval(); tfp->dump(main_time++);
        top->clk = 0; top->eval(); tfp->dump(main_time++);
        cycle_count++;
        bool req_now = top->rootp->soc_top__DOT__dcache_req;
        if (req_now && !prev_req) total_requests++;
        prev_req = req_now;

        if (cycle_count % 500000 == 0) {
            std::cout << "cyc=" << cycle_count
                       << " pc=0x" << std::hex << top->rootp->soc_top__DOT__u_core__DOT__u_fetch__DOT__pc
                       << " tick_count=" << std::dec << top->rootp->soc_top__DOT__ram[443]
                       << std::endl;
        }

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
    tfp->close();
    delete tfp;
    delete top;
    return 0;
}