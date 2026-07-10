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
    # Expected Result Calculation:
    # Kp = 5.0, Kd = 2.5 (Default inside hardware mock)
    # Output = (5.0 * 1.0) + (2.5 * 0.5) = 5.0 + 1.25 = 6.25
    # 6.25 in Q16.16 = 6.25 * 65536 = 409600 = 0x00064000
    li a2, 0x00064000

    # ---------------------------------------------------
    # 3. Execute Custom Instruction & Verify
    # ---------------------------------------------------
    # custom_pid a3, a0, a1
    .insn r 0x0B, 0, 0, a3, a0, a1

    # Compare result to expected
    beq a3, a2, pass

fail:
    j fail

pass:
    j pass