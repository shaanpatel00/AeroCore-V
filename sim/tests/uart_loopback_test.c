#include <stdint.h>

// MMIO Addresses based on the SoC Architecture
#define UART_BASE       0x40000200
#define UART_TX_REG     (*(volatile uint32_t*)(UART_BASE + 0x00))
#define UART_RX_REG     (*(volatile uint32_t*)(UART_BASE + 0x04))
#define UART_STATUS_REG (*(volatile uint32_t*)(UART_BASE + 0x08))
#define TX_READY_BIT    0x1
#define RX_VALID_BIT    0x2

// Use uint32_t for everything to force the GCC compiler to use 'SW' (Store Word).
void uart_send(uint32_t c) {
    while (!(UART_STATUS_REG & TX_READY_BIT)); 
    UART_TX_REG = c;
}

uint32_t uart_receive() {
    while (!(UART_STATUS_REG & RX_VALID_BIT)); 
    return UART_RX_REG;
}

int main() {
    const char *test_string = "AeroCore-V UART Verification";
    uint32_t i = 0;
    uint32_t test_passed = 1;
    
    // Loopback testing
    while (test_string[i] != '\0') {
        uart_send((uint32_t)test_string[i]);
        uint32_t read_back = uart_receive();
        
        if (read_back != (uint32_t)test_string[i]) {
            test_passed = 0;
            break;
        }
        i++;
    }
    
    if (test_passed) {
        uart_send(0xFF); 
        return 0;
    } else {
        uart_send(0xEE); 
        return 1;
    }
}