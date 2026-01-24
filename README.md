# AeroCore-V: RISC-V Flight Control SoC

**AeroCore-V** is a specialized SystemVerilog System-on-Chip (SoC) designed for low-latency UAV flight control. It is targeted for the **Terasic DE10-Standard** (Cyclone V FPGA) and features a custom RISC-V core with hardware-accelerated PID control, a two-level cache hierarchy, and an MMU-protected kernel.

The project includes a **"Digital Twin"** simulation environment that couples the Verilated RTL with a C++ physics engine and OpenGL visualization to validate flight stability before synthesis.

## 🚀 Key Features

### Hardware (RTL)
* **Custom PID Extension**: Single-cycle `PID` instruction (Opcode `0x0B`) for ultra-low latency control loops.
* **Memory Hierarchy**:
    * **L1 Cache**: Split I/D, Direct-Mapped.
    * **L2 Cache**: Unified, 4-Way Set Associative with **True LRU** replacement to handle high-frequency sensor streams.
* **Memory Management**: Sv32-compliant **MMU** (TLB + Hardware Page Table Walker) for kernel/user isolation.
* **Peripherals**: Memory-mapped SPI (IMU), I2C (GPS), UART (Telemetry), and PWM Motor Controllers.

### Software
* **Bare-Metal Kernel**: A cooperative scheduler managing flight control (100Hz) and telemetry tasks.
* **Telemetry**: Real-time status reporting via UART using Q16.16 fixed-point formatting.

### Simulation
* **Digital Twin**: A Verilator-based simulation where the RTL drives a C++ physics engine.
* **3D Visualization**: OpenGL visualization of the drone's response to hardware signals in real-time.

---

## 📂 Directory Structure

```text
aerocore-v/
├── fpga/                   # Quartus Prime Project Files
│   ├── de10_standard/      # Board-specific pin mappings (QSF) & constraints (SDC)
│   └── scripts/            # Tcl/Shell scripts for headless build & programming
├── rtl/                    # SystemVerilog Source Code
│   ├── cache/              # L1/L2 Controller & Cache Memory
│   ├── core/               # RISC-V Core (ALU, Decode, RegFile, Pipeline)
│   ├── mmu/                # TLB & Page Table Walker
│   └── peripherals/        # SPI, I2C, UART, & SoC Top-Level
├── sim/                    # Simulation Environment
│   ├── digital_twin/       # C++ Physics Engine & Visualizer
│   ├── tests/              # Assembly Unit Tests (ALU, MMU)
│   └── verilator/          # Verilator Testbench & Makefile
└── sw/                     # Embedded Software Stack
    ├── bootloader/         # Startup Assembly & Linker Script
    ├── kernel/             # PID Loop, Scheduler, Trap Handlers
    ├── tools/              # elf2hex converter
    └── user/               # Telemetry & User Tasks

## Architecture
Data Flow
* Sensors: IMU data enters via SPI Wrapper (GPIO inputs).

* Core: The RISC-V CPU reads sensors from 0x4000_0000.

* Calculate: The Custom ALU executes PID_STEP (Opcode 0x0B) in 1 cycle.

* Actuate: CPU writes result to Motor PWM Register 0x4000_0100.

* Physics: In simulation, physics_engine.cpp reads this register to update velocity.

