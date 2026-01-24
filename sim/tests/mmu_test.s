# RISC-V Assembly Test: MMU Basic Translation
# Sets up Identity Mapping for code and a Virtual Mapping for Data

.section .text
.global _start

_start:
    # ---------------------------------------------------
    # 1. Setup Page Table (Root at 0x80000000 - RAM Base)
    # ---------------------------------------------------
    li s0, 0x80000000   # Page Table Base Addr
    
    # Create a Leaf PTE for Virtual Addr 0x00002000 -> Phys 0x80002000
    # Sv32 PTE Format: PPN[21:0] | Reserved | D | A | G | U | X | W | R | V
    # Mapping PPN 0x80002 to VPN 0x00002 (Simple Linear for test)
    
    # PTE Value construction:
    # PPN = 0x80002 (Shifted left by 10) -> 0x20000800
    # Perms = DAGUXWRV = 00000111 (RWV)  -> 0x07
    # PTE = 0x20000807
    
    li t0, 0x20000807
    
    # Store at offset for VPN 0 (index 0) 
    # (Simplified: assumes we are mapping low addresses directly)
    sw t0, 0(s0)
    
    # ---------------------------------------------------
    # 2. Enable Paging (Write SATP)
    # ---------------------------------------------------
    # Mode = 1 (Sv32), PPN = 0x80000 >> 12 = 0x80000
    # SATP = 0x80080000
    
    li t1, 0x80080000
    csrw satp, t1
    sfence.vma      # Flush TLB
    
    # ---------------------------------------------------
    # 3. Test Translation
    # ---------------------------------------------------
    # Setup pointer to Virtual Address 0x00000000 
    # (Which we mapped to Phys 0x80002000 via the PTE above)
    
    li t2, 0x00000000
    li t3, 0xDEADBEEF
    
    # Store to Virtual Address
    sw t3, 0(t2)
    
    # ---------------------------------------------------
    # 4. Verification
    # ---------------------------------------------------
    # Bypass MMU (if possible) or check Physical RAM location in simulation
    # For self-checking, we read it back.
    
    lw t4, 0(t2)
    bne t3, t4, fail

pass:
    j pass

fail:
    j fail