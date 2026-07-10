#include <stdint.h>

#define I2C_BASE        0x40000004
#define I2C_CTRL_REG    (*(volatile uint32_t*)(I2C_BASE + 0x00))
#define I2C_ADDR_REG    (*(volatile uint32_t*)(I2C_BASE + 0x04))
#define I2C_DATA_REG    (*(volatile uint32_t*)(I2C_BASE + 0x08))
#define I2C_STATUS_REG  (*(volatile uint32_t*)(I2C_BASE + 0x0C))

#define I2C_START       0x01
#define I2C_STOP        0x02
#define I2C_READ        0x04
#define I2C_BUSY        0x01

#define MOCK_GPS_ADDR   0x42
#define EXPECTED_BYTE   0xAA

int main() {
    // 1. Set the target device address
    I2C_ADDR_REG = MOCK_GPS_ADDR;

    // 2. Issue Start and Read commands
    I2C_CTRL_REG = (I2C_START | I2C_READ);

    // 3. Wait for transaction to complete
    while (I2C_STATUS_REG & I2C_BUSY);

    // 4. Issue Stop command
    I2C_CTRL_REG = I2C_STOP;

    // 5. Read data and verify
    uint32_t sensor_data = I2C_DATA_REG;

    // Assert condition for testbench
    if (sensor_data == EXPECTED_BYTE) {
        return 0; // PASS
    } else {
        return 1; // FAIL
    }
}