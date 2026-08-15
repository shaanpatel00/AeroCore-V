#include "riscv_asm.h"

// --- Reserved Physical Pages for MMU Page Tables ---
// The linker reserves the top 8KB of RAM exclusively for these two pages
// (see bootloader/linker.ld's .stack section) - the stack is bounded to
// grow only up to 0x2000, so it can never collide with this region.
#define PT_ROOT_ADDR   0x3000   // Root (Level 1) page table - 1 page
#define PT_L0_RAM_ADDR 0x2000   // Level 0 page table for RAM's identity map

#define CSR_SATP 0x180

// Sv32 PTE permission bits
#define PTE_V  0x001
#define PTE_R  0x002
#define PTE_W  0x004
#define PTE_X  0x008

#define PTE_LEAF_RWX (PTE_V | PTE_R | PTE_W | PTE_X)
#define PTE_LEAF_RW  (PTE_V | PTE_R | PTE_W)
#define PTE_POINTER  (PTE_V)

#define MAKE_PTE(ppn, flags) (((uint32_t)(ppn) << 10) | (flags))

/**
 * @brief Sets up a minimal identity-mapped Sv32 page table and enables
 * paging.
 *
 * Identity-maps:
 *  - All 4 physical RAM pages (0x0000-0x3FFF), including the page tables
 *    themselves, via a 2-level walk (root -> L0 -> RAM page).
 *  - The MMIO peripheral region (0x40000000's page: SPI/motor/UART) via a
 *    single megapage leaf directly at the root level. This SoC only ever
 *    touches addresses within that one 4KB page, and the TLB's own refill
 *    logic keys on the full VPN (not just vpn1), so a true multi-page
 *    megapage isn't needed here - this works because we never touch a
 *    different vpn0 under vpn1=256. Also sidesteps a real collision: MMIO's
 *    vpn0=0 would otherwise collide with RAM page 0's vpn0=0 if they had to
 *    share an L0 table.
 *
 * Must run before anything else in the boot sequence, since once satp is
 * written every subsequent load/store goes through translation.
 */
void mmu_init(void) {
    volatile uint32_t *root   = (volatile uint32_t *)PT_ROOT_ADDR;
    volatile uint32_t *l0_ram = (volatile uint32_t *)PT_L0_RAM_ADDR;

    // --- L0 table: identity-map all 4 RAM pages ---
    l0_ram[0] = MAKE_PTE(0, PTE_LEAF_RWX); // 0x0000-0x0FFF: code/data/bss
    l0_ram[1] = MAKE_PTE(1, PTE_LEAF_RWX); // 0x1000-0x1FFF: spare/stack headroom
    l0_ram[2] = MAKE_PTE(2, PTE_LEAF_RWX); // 0x2000-0x2FFF: this L0 table itself
    l0_ram[3] = MAKE_PTE(3, PTE_LEAF_RWX); // 0x3000-0x3FFF: the root table itself

    // --- Root table ---
    root[0]   = MAKE_PTE(PT_L0_RAM_ADDR >> 12, PTE_POINTER); // vpn1=0   -> L0 table above
    root[256] = MAKE_PTE(0x40000000 >> 12, PTE_LEAF_RW);     // vpn1=256 -> MMIO megapage

    // --- Enable paging: MODE=1 (Sv32), PPN = PT_ROOT_ADDR >> 12 ---
    uint32_t satp_val = 0x80000000u | (PT_ROOT_ADDR >> 12);
    csrw(CSR_SATP, satp_val);
}