# sim/tests/Makefile
CC = riscv64-elf-gcc
OBJCOPY = riscv64-elf-objcopy
PYTHON = python3

# Architecture and ABI for AeroCore-V
CFLAGS = -march=rv32i -mabi=ilp32 -mcmodel=medany -ffreestanding -nostdlib -O0 -Wall

# Paths to existing bootloader and tools
BOOT_DIR = ../../sw/bootloader
TOOLS_DIR = ../../sw/tools
START_ASM = $(BOOT_DIR)/start.S
LINKER_SCRIPT = $(BOOT_DIR)/linker.ld
ELF2HEX = $(TOOLS_DIR)/elf2hex.py

# Find all C test files in this directory
TEST_SRCS = $(wildcard *.c)
TEST_ELFS = $(TEST_SRCS:.c=.elf)
TEST_HEXS = $(TEST_SRCS:.c=.hex)

.PHONY: all clean

all: $(TEST_HEXS)

# Rule to build hex files
%.hex: %.elf
	$(PYTHON) $(ELF2HEX) $< $@

# Rule to build elf files (links the specific test with start.S)
%.elf: %.c $(START_ASM) $(LINKER_SCRIPT)
	$(CC) $(CFLAGS) -T $(LINKER_SCRIPT) $(START_ASM) $< -o $@

clean:
	rm -f *.o *.elf *.hex