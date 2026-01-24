# RISC-V Bootloader (start.S)
# Target: RV32I SoC (Flight Controller)

.section .text
.global _start

_start:
    # ----------------------------------------------------------------
    # 1. Initialize Global Pointer (gp)
    # ----------------------------------------------------------------
    # The linker script defines __global_pointer$ to point to the 
    # middle of the small data section for optimization.
    .option push
    .option norelax
    la gp, __global_pointer$
    .option pop

    # ----------------------------------------------------------------
    # 2. Initialize Stack Pointer (sp)
    # ----------------------------------------------------------------
    # The linker script defines _stack_top at the end of RAM.
    la sp, _stack_top

    # ----------------------------------------------------------------
    # 3. Clear BSS Section (Zero-Initialize Global Variables)
    # ----------------------------------------------------------------
    la t0, _bss_start
    la t1, _bss_end
    bge t0, t1, bss_clear_done

bss_clear_loop:
    sw zero, 0(t0)
    addi t0, t0, 4
    blt t0, t1, bss_clear_loop

bss_clear_done:

    # ----------------------------------------------------------------
    # 4. Jump to Main Kernel
    # ----------------------------------------------------------------
    # Call the C entry point
    call main

    # ----------------------------------------------------------------
    # 5. Trap / Hang
    # ----------------------------------------------------------------
    # If main returns, just loop forever.
hang:
    j hang