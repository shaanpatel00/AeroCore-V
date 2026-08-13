.section .text
.global _start
_start:
    # 1. Build a 2-level Sv32 page table (untranslated - satp still disabled)
    # Root table @ phys 0x3000, L0 table @ phys 0x2000, data page @ phys 0x1000

    # Root PTE idx0 -> points to L0 table (PPN=2, pointer: V=1,R=W=X=0)
    li   t0, 0x3000
    li   t1, 0x00000801
    sw   t1, 0(t0)

    # Root PTE idx256 -> same L0 table (covers UART's vpn1=256)
    li   t0, 0x3400
    sw   t1, 0(t0)

    # L0 slot0 (vpn0=0) -> identity-maps UART's page (PPN=0x40000, R+W, U=0)
    li   t0, 0x2000
    li   t1, 0x10000007
    sw   t1, 0(t0)

    # L0 slot2 (vpn0=2) -> maps VA 0x2000's page to phys page 1 (PPN=1, R+W, U=0)
    li   t0, 0x2008
    li   t1, 0x00000407
    sw   t1, 0(t0)

    # 2. Enable paging: satp = MODE(1) | PPN(root=0x3000>>12=3)
    li   t1, 0x80000003
    csrw satp, t1

    # 3. Translated store + load round-trip through the new TLB-miss -> PTW -> refill path
    li   t0, 0x00002000      # virtual data address (page offset 0)
    li   t2, 0x1234ABCD      # test pattern
    sw   t2, 0(t0)
    lw   t3, 0(t0)

    # 4. Report result over UART (also translated, via the identity-mapped UART page)
    li   t4, 0x40000200      # UART_TX (virtual)
    li   t5, 0x40000208      # UART_STATUS (virtual)

wait_tx:
    lw   t6, 0(t5)
    andi t6, t6, 1
    beqz t6, wait_tx

    bne  t2, t3, fail

pass:
    li   a0, 0xFF
    sw   a0, 0(t4)
    j    done

fail:
    li   a0, 0xEE
    sw   a0, 0(t4)

done:
    j done
