#!/bin/bash
# fpga/scripts/program.sh

# 1. Configuration
PROJECT_DIR="../de10_standard"
OUTPUT_DIR="output_files"
SOF_FILE="de10.sof"
CABLE_NAME="DE-SoC [USB-1]" # Standard name for DE10 onboard blaster

# 2. Check for Bitstream
if [ ! -f "$PROJECT_DIR/$OUTPUT_DIR/$SOF_FILE" ]; then
    echo "Error: Bitstream not found at $PROJECT_DIR/$OUTPUT_DIR/$SOF_FILE"
    echo "Run the build script first."
    exit 1
fi

# 3. Program the FPGA
# -m jtag: Mode JTAG
# -c: Cable name (auto-detects if index 1)
# -o "p;...": Operation "Program" file ...
echo "--- Programming FPGA with $SOF_FILE ---"

# Note: You might need to add quartus/bin to your PATH
quartus_pgm -m jtag -c 1 -o "p;$PROJECT_DIR/$OUTPUT_DIR/$SOF_FILE"

if [ $? -eq 0 ]; then
    echo "--- Programming Successful ---"
else
    echo "--- Programming Failed ---"
    # Tip for WSL/Linux users
    echo "Tip: Ensure jtagd is running and you have permissions (udev rules)."
fi