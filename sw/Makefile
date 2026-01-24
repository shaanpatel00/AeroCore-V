CC=riscv64-unknown-elf-gcc
OBJCOPY=riscv64-unknown-elf-objcopy
CFLAGS=-march=rv32i -mabi=ilp32 -ffreestanding -nostdlib

all: kernel.hex

kernel.elf: kernel/pid.c
	$(CC) $(CFLAGS) -T kernel/linker.ld $^ -o $@

kernel.hex: kernel.elf
	$(OBJCOPY) -O verilog $< $@

clean:
	rm -f *.elf *.hex