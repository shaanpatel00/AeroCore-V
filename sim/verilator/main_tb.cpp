#include <iostream>
#include <verilated.h>
#include "Vsoc_top.h" // Your Verilated top-level module

// Define the MMIO address for the UART Transmit Register based on your architecture
#define UART_TX_ADDR 0x40000200

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    // Instantiate the Verilated hardware
    Vsoc_top* top = new Vsoc_top;

    // Initialize inputs
    top->clk = 0;
    top->reset = 1;

    // Assert reset for 5 cycles
    for (int i = 0; i < 10; ++i) {
        top->clk = !top->clk;
        top->eval();
    }
    top->reset = 0;

    std::cout << "[VERILATOR] Starting AeroCore-V SoC Simulation..." << std::endl;

    int max_cycles = 50000;
    int cycle_count = 0;
    bool test_finished = false;

    // Main Simulation Loop
    while (!Verilated::gotFinish() && cycle_count < max_cycles && !test_finished) {
        // Toggle Clock
        top->clk = 1;
        top->eval();
        top->clk = 0;
        top->eval();

        // -------------------------------------------------------------
        // Verification Logic: Monitor the System Bus / UART
        // -------------------------------------------------------------
        // We are checking if the RISC-V core is writing to the UART_TX_REG
        // (You may need to adjust these signal names based on your exact soc_top.sv ports)
        
        if (top->io_write_en && (top->io_addr == UART_TX_ADDR)) {
            uint32_t uart_data = top->io_write_data;
            
            // Print characters to terminal just like a real UART console
            if (uart_data >= 0x20 && uart_data <= 0x7E) {
                std::cout << (char)uart_data;
            }

            // Check for our custom PASS/FAIL execution codes
            if (uart_data == 0xFF) {
                std::cout << "\n[VERIFICATION] RESULT: PASS (0xFF detected)" << std::endl;
                test_finished = true;
            } else if (uart_data == 0xEE) {
                std::cout << "\n[VERIFICATION] RESULT: FAIL (0xEE detected)" << std::endl;
                test_finished = true;
                // Exit with an error code so the GitHub Action turns red
                delete top;
                exit(1); 
            }
        }

        cycle_count++;
    }

    if (!test_finished) {
        std::cout << "\n[VERIFICATION] RESULT: TIMEOUT (Max cycles reached)" << std::endl;
        delete top;
        exit(1);
    }

    // Clean up
    delete top;
    return 0;
}