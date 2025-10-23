# Makefile for sp_ram integration testbench
# Supports both Icarus Verilog and Verilator

TB_TOP = sp_ram_integration_tb
VCD_FILE = $(TB_TOP).vcd

# Source files
SOURCES = sp_ram.sv \
          ../sampler/i2s_capture_24.sv \
          ../sampler/vu_meter_6led.sv \
          ../clk_generator/i2s_clock_gen.sv \
          $(TB_TOP).sv

# Icarus Verilog settings
IVERILOG = iverilog
VVP = vvp
IVERILOG_FLAGS = -g2012 -Wall -Winfloop

# Verilator settings
VERILATOR = verilator
VERILATOR_FLAGS = --binary --timing --trace-fst --trace-structs -Wall -Wno-fatal
VERILATOR_TOP = $(TB_TOP)

# GTKWave settings
GTKWAVE = gtkwave
GTKWAVE_SAVE = $(TB_TOP).gtkw

# Default target
.PHONY: all
all: sim

# Compile and run with Icarus Verilog (default)
.PHONY: sim
sim: clean
	@echo "=== Compiling with Icarus Verilog ==="
	$(IVERILOG) $(IVERILOG_FLAGS) -o $(TB_TOP).vvp $(SOURCES)
	@echo ""
	@echo "=== Running simulation ==="
	$(VVP) $(TB_TOP).vvp
	@echo ""
	@echo "=== Simulation complete ==="
	@echo "VCD file: $(VCD_FILE)"
	@echo "To view waveforms: make wave"

# Compile and run with Verilator
.PHONY: verilator
verilator: clean
	@echo "=== Compiling with Verilator ==="
	$(VERILATOR) $(VERILATOR_FLAGS) --top $(VERILATOR_TOP) $(SOURCES)
	@echo ""
	@echo "=== Running Verilator simulation ==="
	./obj_dir/V$(TB_TOP)
	@echo ""
	@echo "=== Simulation complete ==="

# Open waveforms in GTKWave
.PHONY: wave
wave: $(VCD_FILE)
	@if [ -f $(GTKWAVE_SAVE) ]; then \
		echo "Opening GTKWave with saved settings..."; \
		$(GTKWAVE) $(VCD_FILE) $(GTKWAVE_SAVE) & \
	else \
		echo "Opening GTKWave (no save file found)..."; \
		$(GTKWAVE) $(VCD_FILE) & \
	fi

# Quick check - compile only
.PHONY: check
check:
	@echo "=== Syntax check with Icarus Verilog ==="
	$(IVERILOG) $(IVERILOG_FLAGS) -o /dev/null $(SOURCES)
	@echo "=== Syntax check passed ==="

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf *.vvp *.vcd *.fst obj_dir

# Help
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  make sim       - Compile and run with Icarus Verilog (default)"
	@echo "  make verilator - Compile and run with Verilator"
	@echo "  make wave      - Open waveforms in GTKWave"
	@echo "  make check     - Syntax check only"
	@echo "  make clean     - Remove build artifacts"
	@echo "  make help      - Show this help"
