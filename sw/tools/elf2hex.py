#!/usr/bin/env python3
import sys
import struct

# You may need to install pyelftools: pip install pyelftools
try:
    from elftools.elf.elffile import ELFFile
    from elftools.elf.sections import SymbolTableSection
except ImportError:
    print("Error: 'pyelftools' not found. Please run: pip install pyelftools")
    sys.exit(1)

def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input.elf> <output.hex>")
        sys.exit(1)

    input_elf = sys.argv[1]
    output_hex = sys.argv[2]

    print(f"[elf2hex] Converting {input_elf} -> {output_hex}")

    with open(input_elf, 'rb') as f:
        elf = ELFFile(f)
        
        # Open output file
        with open(output_hex, 'w') as out:
            # We iterate through loadable segments (usually .text and .data)
            # For a simple bare-metal RISC-V core, we usually flatten everything 
            # into a single continuous memory block starting at 0x00000000.
            
            # Note: This script assumes the linker script placed code at 0x0.
            # If there are gaps between sections, we might need to fill with zeros 
            # if the Verilog loader expects linear addresses.
            
            current_addr = 0
            
            # Find the .text section to start
            section = elf.get_section_by_name('.text')
            if not section:
                print("Error: No .text section found.")
                sys.exit(1)
                
            data = section.data()
            start_addr = section['sh_addr']
            
            # Simple padding if text doesn't start at 0 (unlikely for this bootloader)
            if start_addr > 0:
                print(f"Warning: Text starts at {hex(start_addr)}, padding with zeros.")
                for _ in range(start_addr // 4):
                    out.write("00000000\n")
            
            # Process Code (.text)
            # Write 32-bit words in Little Endian reversed for Verilog (Big Endian hex string)
            # or keep logical order depending on how $readmemh reads it.
            # Usually $readmemh reads "AABBCCDD" as [31:0] = 0xAABBCCDD.
            # RISC-V instructions are Little Endian in memory. 
            # Byte 0 (LSB) at Addr 0.
            # If we want 32-bit word at addr 0 to be 0x12345678:
            # Memory bytes: 78 56 34 12.
            # Python 'data' gives bytes.
            
            def write_chunk(chunk_data):
                # Padding to multiple of 4 bytes
                while len(chunk_data) % 4 != 0:
                    chunk_data += b'\x00'
                    
                for i in range(0, len(chunk_data), 4):
                    word = chunk_data[i:i+4]
                    # Convert to 32-bit int to format as hex
                    # struct.unpack('<I') reads Little Endian bytes -> Integer
                    val = struct.unpack('<I', word)[0]
                    # Write as 8-char hex string
                    out.write(f"{val:08x}\n")

            write_chunk(data)
            
            # Check for .data section
            data_sec = elf.get_section_by_name('.data')
            if data_sec:
                # Handle gap between text and data if any
                text_end = start_addr + len(data)
                data_addr = data_sec['sh_addr']
                gap = data_addr - text_end
                
                if gap > 0:
                    for _ in range(gap // 4):
                        out.write("00000000\n")
                
                write_chunk(data_sec.data())

    print("[elf2hex] Done.")

if __name__ == "__main__":
    main()