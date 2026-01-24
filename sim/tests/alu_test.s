# RISC-V Assembly Test: Custom PID ALU
# Tests the 'custom-0' instruction (opcode 0x0B)
# Logic: Output = (Kp*Error) + (Ki*Integral) + (Kd*Delta)

.section .text
.global _start

_start:
    # ---------------------------------------------------
    # 1. Setup Test Values (Q16.16 Fixed Point)
    # ---------------------------------------------------
    # Error = 1.0 (0x00010000)
    li a0, 0x00010000
    
    # Prev Error = 0.5 (0x00008000)
    li a1, 0x00008000
    
    # ---------------------------------------------------
    # 2. Setup CSRs (Mocked via GPRs for this test)
    # ---------------------------------------------------
    # In the actual hardware logic (alu_pid.sv), these are hardwired 
    # or memory-mapped. For this unit test, we assume the hardware 
    # has default gains:
    # Kp = 5.0 (0x00050000)
    # Ki = 0.3 (0x00004CCC)
    # Kd = 2.5 (0x00028000)