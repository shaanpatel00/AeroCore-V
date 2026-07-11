#!/usr/bin/env python3
import sys
import struct

try:
    from elftools.elf.elffile import ELFFile
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
        
        with open(output_hex, 'w') as out:
            current_addr = 0
            
            # Extract Text, Read-Only Data, and Initialized Data
            for sec_name in ['.text', '.rodata', '.data', '.sdata']:
                sec = elf.get_section_by_name(sec_name)
                if not sec:
                    continue
                    
                data = sec.data()
                start_addr = sec['sh_addr']
                
                # Pad any gaps between memory sections with zeroes
                if start_addr > current_addr:
                    gap = start_addr - current_addr
                    out.write("00000000\n" * (gap // 4))
                    current_addr = start_addr
                
                # Pad the data block to a clean 4-byte boundary
                padded_data = data + b'\x00' * ((4 - len(data) % 4) % 4)
                
                # Write out as 32-bit hex words
                for i in range(0, len(padded_data), 4):
                    word = padded_data[i:i+4]
                    val = struct.unpack('<I', word)[0]
                    out.write(f"{val:08x}\n")
                    
                current_addr += len(padded_data)

    print("[elf2hex] Done.")

if __name__ == "__main__":
    main()