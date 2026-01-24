# AeroCore-V: RISC-V Flight Control SoC

**AeroCore-V** is a specialized SystemVerilog System-on-Chip (SoC) designed for low-latency UAV flight control. It is targeted for the **Terasic DE10-Standard** (Cyclone V FPGA) and features a custom RISC-V core with hardware-accelerated PID control, a two-level cache hierarchy, and an MMU-protected kernel.

The project includes a **"Digital Twin"** simulation environment that couples the Verilated RTL with a C++ physics engine and OpenGL visualization to validate flight stability before synthesis.

## Key Features

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
```

## Architecture
Data Flow
* Sensors: IMU data enters via SPI Wrapper (GPIO inputs).

* Core: The RISC-V CPU reads sensors from 0x4000_0000.

* Calculate: The Custom ALU executes PID_STEP (Opcode 0x0B) in 1 cycle.

* Actuate: CPU writes result to Motor PWM Register 0x4000_0100.

* Physics: In simulation, physics_engine.cpp reads this register to update velocity.

```mermaid
graph TD
    subgraph "FPGA / SoC (DE10-Standard)"
        subgraph "Core Complex"
            RV32[RISC-V Core<br/>RV32I]
            ALU[Standard ALU]
            PID_ALU[<b>Custom PID ALU</b><br/>Opcode: 0x0B<br/>Single-Cycle Calc]
            MMU[MMU<br/>TLB + PTW]
            
            RV32 <--> ALU
            RV32 <--> PID_ALU
            RV32 <--> MMU
        end

        subgraph "Memory Hierarchy"
            L1_Cache[L1 Cache<br/>Split I/D, Direct-Mapped]
            L2_Cache[L2 Cache<br/>Unified, 4-Way LRU]
            BRAM[Block RAM / DDR3<br/>Main Memory<br/>0x0000_0000]
            
            MMU <--> L1_Cache
            L1_Cache <--> L2_Cache
            L2_Cache <--> BRAM
        end

        subgraph "Peripheral Interconnect (MMIO 0x4000_XXXX)"
            Bus[System Interconnect]
            
            SPI_Wrap[SPI Wrapper<br/>0x4000_0000]
            I2C_Wrap[I2C Wrapper<br/>0x4000_0004]
            UART_Wrap[UART<br/>0x4000_0200]
            PWM_Ctrl[PWM Controller<br/>0x4000_0100]

            L2_Cache <--> Bus
            Bus <--> SPI_Wrap
            Bus <--> I2C_Wrap
            Bus <--> UART_Wrap
            Bus <--> PWM_Ctrl
        end
    end

    subgraph "External Hardware / Digital Twin"
        IMU[IMU Sensor<br/>(Gyro/Accel)]
        GPS[GPS Module]
        Telemetry[Telemetry Station<br/>(PC)]
        Motors[BLDC Motors<br/>(ESCs)]

        SPI_Wrap <==>|SPI| IMU
        I2C_Wrap <==>|I2C| GPS
        UART_Wrap <==>|TX/RX| Telemetry
        PWM_Ctrl ==>|PWM| Motors
    end

    %% Styles
    style PID_ALU fill:#f96,stroke:#333,stroke-width:2px
    style L2_Cache fill:#69f,stroke:#333,stroke-width:2px
```

# System Architecture & Logic

## 1. Hardware Architecture (RTL)
The hardware is a custom System-on-Chip (SoC) centered around a modified RISC-V core.

### Top-Level Integration (`soc_top.sv`)
This module ties everything together. It instantiates the RISC-V core, memory, and peripherals. It maps memory addresses to specific hardware:
* **RAM**: `0x0000_0000` (Main Memory)
* **IO**: `0x4000_0000` (Peripherals) where bit 30 determines if an access is IO or RAM.
* **Motors**: Writes to `0x40000100` directly update the `motor_pwm` output signals.

### Custom PID Acceleration (`alu_pid.sv` & Pipeline)
Instead of calculating flight stability in software (slow), the core has a dedicated hardware unit.
* **Decode (`decode.sv`)**: Recognizes a custom opcode `OPCODE_CUSTOM0` (`0x0B`). When found, it asserts `pid_en` to enable the custom ALU.
* **ALU (`alu_pid.sv`)**: This unit performs the Proportional-Integral-Derivative (PID) math in parallel. It takes `error` and `prev_error`, applies fixed-point coefficients (`coeff_kp`, `coeff_ki`, `coeff_kd`), and outputs the control signal in a single clock cycle.
* **Execute (`execute.sv`)**: Muxes the standard ALU result with the PID result based on the `pid_en` signal.

### Memory System
* **MMU (`tlb.sv`)**: A Translation Lookaside Buffer translates virtual addresses to physical ones. It enforces permissions, ensuring User mode code (telemetry) cannot write to Supervisor pages (kernel).
* **L2 Cache (`l2_controller.sv`)**: Implements a 4-Way Set Associative cache with a True LRU (Least Recently Used) policy. It maintains an "LRU Matrix" (`lru_matrix`) to track access history and intelligently evict old data to keep the sensor stream smooth.

## 2. Software Stack (Kernel)
The software is a bare-metal kernel that relies on the hardware features described above.

### Flight Loop (`pid.c`)
This is the critical task. It reads sensor data from the SPI memory-mapped address `0x40000000` (defined as `SPI_DATA_REG`).
* It calculates the error and then calls `custom_pid_op()`.
* This C function uses inline assembly (`.insn r 0x0B...`) to invoke the hardware PID unit directly.
* The result is immediately written to the motor register `MOTOR_PWM_REG`.

### Scheduler (`sched.c`)
A simple cooperative scheduler runs in `main()`. It prioritizes the `pid_task()` (flight control) to ensure the drone stays stable, and runs `telemetry_task()` less frequently (every 100 ticks) to report status.

### Telemetry (`telemetry_task.c`)
Reads the system state and formats it into human-readable text using Q16.16 fixed-point conversion. It transmits this data via UART for debugging.

## 3. Digital Twin Simulation
The project validates the hardware/software logic by coupling it with a C++ physics engine.

### Bridge (`bridge.cpp`)
This C++ program instantiates the Verilated hardware model (`Vsoc_top`).
1.  **Run Hardware**: It steps the hardware clock for 10,000 cycles.
2.  **Read Motor**: It "peeks" into the simulated FPGA memory (`top->motor_pwm`) to see what thrust the RISC-V core is requesting.
3.  **Update Physics**: It passes this thrust to `physics->update()`, which calculates the new altitude based on gravity, drag, and mass.
4.  **Feedback Loop**: The new altitude is converted back to sensor data and fed into the simulation inputs, closing the control loop.