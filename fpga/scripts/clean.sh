#!/bin/bash
# fpga/scripts/clean.sh

echo "Cleaning Quartus build artifacts..."

cd "$(dirname "$0")/../de10_standard"

# Remove generated directories
rm -rf db
rm -rf incremental_db
rm -rf output_files
rm -rf simulation
rm -rf greybox_tmp
rm -rf hc_output

# Remove generated files
rm -f *.qws
rm -f *.sof
rm -f *.pof
rm -f *.smsg
rm -f *.summary
rm -f *.done

echo "Clean complete."