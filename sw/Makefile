CC = riscv64-elf-gcc
OBJCOPY = riscv64-elf-objcopy
CFLAGS=-march=rv32i -mabi=ilp32 -ffreestanding -nostdlib

all: kernel.hex

kernel.elf: bootloader/start.S kernel/sched.c kernel/pid.c
	$(CC) $(CFLAGS) -T bootloader/linker.ld $^ -o $@

kernel.hex: kernel.elf
	python3 tools/elf2hex.py $< $@

clean:
	rm -f *.elf *.hex