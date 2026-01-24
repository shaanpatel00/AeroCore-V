# fpga/scripts/build.tcl
# Usage: quartus_sh -t build.tcl

load_package flow

# Configuration
set project_dir "../de10_standard"
set project_name "de10"
set revision_name "de10"

# Navigate to project directory
set script_path [file dirname [file normalize [info script]]]
cd "$script_path/$project_dir"

puts "--- Opening Project: $project_name ---"

if {[project_exists $project_name]} {
    project_open -revision $revision_name $project_name
} else {
    puts "Error: Project $project_name not found in $project_dir."
    puts "Please ensure de10.qpf and de10.qsf exist."
    exit 1
}

# Run Full Compilation
puts "--- Starting Compilation Flow ---"
if {[catch {execute_flow -compile} result]} {
    puts "\nError during compilation: $result"
    project_close
    exit 1
} else {
    puts "\n--- Compilation Successful ---"
}

project_close