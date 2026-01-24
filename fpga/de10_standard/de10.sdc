# Create Clock Constraint for 50MHz Oscillator
create_clock -name CLOCK_50 -period 20.000 [get_ports {CLOCK_50}]

# Derive PLL clocks (if you add a PLL later)
derive_pll_clocks

# Handle Clock Uncertainty (Jitter)
derive_clock_uncertainty

# Input/Output Delays (Simplified for hobbyist projects)
# We assume minimal delay for GPIOs, but define them to silence warnings
set_false_path -from [get_ports {KEY[*]}] -to [get_clocks {CLOCK_50}]
set_false_path -from [get_ports {SW[*]}]  -to [get_clocks {CLOCK_50}]
set_false_path -from [get_ports {GPIO[*]}] -to [get_clocks {CLOCK_50}]
set_false_path -from [get_clocks {CLOCK_50}] -to [get_ports {GPIO[*]}]
set_false_path -from [get_clocks {CLOCK_50}] -to [get_ports {LEDR[*]}]