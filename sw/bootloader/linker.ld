/* RISC-V Linker Script for Flight Controller SoC */
OUTPUT_ARCH( "riscv" )
ENTRY( _start )

/* Memory Layout based on soc_top.sv */
/* RAM size: 4096 words = 16KB */
MEMORY
{
  RAM (rwx) : ORIGIN = 0x00000000, LENGTH = 16K
}

SECTIONS
{
  /* 1. Text Section (Code) */
  .text :
  {
    *(.text.init)   /* Startup code first */
    *(.text)        /* All other code */
    *(.text.*)
    . = ALIGN(4);
  } > RAM

  /* 2. Read-Only Data (Strings, Consts) */
  .rodata :
  {
    *(.rodata)
    *(.rodata.*)
    . = ALIGN(4);
  } > RAM

  /* 3. Initialized Data */
  .data :
  {
    . = ALIGN(4);
    /* Global pointer optimization symbol */
    PROVIDE( __global_pointer$ = . + 0x800 );
    *(.sdata)
    *(.sdata.*)
    *(.data)
    *(.data.*)
    . = ALIGN(4);
  } > RAM

  /* 4. Uninitialized Data (BSS) */
  .bss :
  {
    . = ALIGN(4);
    _bss_start = .;
    *(.sbss)
    *(.sbss.*)
    *(.bss)
    *(.bss.*)
    *(COMMON)
    . = ALIGN(4);
    _bss_end = .;
  } > RAM

  /* 5. Stack Setup */
  /* Place stack at the very end of RAM */
  .stack (NOLOAD) :
  {
    . = ALIGN(16);
    . = ORIGIN(RAM) + LENGTH(RAM);
    PROVIDE( _stack_top = . );
  } > RAM
}