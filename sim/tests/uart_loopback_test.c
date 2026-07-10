#include <stdint.h>
#include <stdbool.h>

// MMIO Addresses based on the SoC Architecture
#define UART_BASE       0x40000200
#define UART_TX_REG     (*(volatile uint32_t*)(UART_BASE + 0x00))
#define UART_RX_REG     (*(volatile uint32_t*)(UART_BASE + 0x04))
#define UART_STATUS_REG (*(volatile uint32_t*)(UART_BASE + 0x08))

#define TX_READY_BIT    0x1
#define RX_VALID_BIT    0x2

// Simple function to wait for TX ready and send a char
void uart_send(char c) {
    while (!(UART_STATUS_REG & TX_READY_BIT)); // Polling wait
    UART_TX_REG = c;
}

// Simple function to wait for RX and read a char
char uart_receive() {
    while (!(UART_STATUS_REG & RX_VALID_BIT)); // Polling wait
    return (char)UART_RX_REG;
}

int main() {
    const char test_string[] = "AeroCore-V UART Verification";
    int i = 0;
    bool test_passed = true;

    // Loopback testing
    while (test_string[i] != '\0') {
        uart_send(test_string[i]);
        char read_back = uart_receive();
        
        if (read_back != test_string[i]) {
            test_passed = false;
            break;
        }
        i++;
    }

    // Write a specific pass/fail code to a known memory location or UART
    // for the Verilator testbench to read and assert
    if (test_passed) {
        uart_send(0xFF); // 0xFF indicates PASS to the testbench
        return 0;
    } else {
        uart_send(0xEE); // 0xEE indicates FAIL
        return 1;
    }
}