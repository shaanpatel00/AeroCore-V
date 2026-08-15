CC ?= riscv64-elf-gcc
OBJCOPY = riscv64-elf-objcopy
CFLAGS=-march=rv32i_zicsr -mabi=ilp32 -ffreestanding -nostdlib

all: kernel.hex

kernel.elf: bootloader/start.S kernel/mmu_init.c kernel/sched.c kernel/pid.c user/telemetry_task.c
	$(CC) $(CFLAGS) -T bootloader/linker.ld $^ -o $@ -lgcc

kernel.hex: kernel.elf
	python3 tools/elf2hex.py $< $@

clean:
	rm -f *.elf *.hex