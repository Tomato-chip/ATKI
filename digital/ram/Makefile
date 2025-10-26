# ============================================================================
# RAM Logic Simulation Makefile
# ============================================================================
# Builds and runs Verilator-based simulation of the ram_logic module
# ============================================================================

# Directories
RAM_DIR := .
OUT_DIR := obj_dir

# Source files
TB_SRC := ram_logic_tb.sv
DUT_SRC := ram_logic.sv
RAM_STUB := sp_ram_stub.v

ALL_SRC := $(TB_SRC) $(DUT_SRC) $(RAM_STUB)

# Verilator flags
VFLAGS := --binary
VFLAGS += --trace
VFLAGS += --trace-structs
VFLAGS += --trace-max-array 2048
VFLAGS += -Wall
VFLAGS += -Wno-TIMESCALEMOD
VFLAGS += -Wno-WIDTHEXPAND
VFLAGS += -Wno-WIDTHTRUNC
VFLAGS += -Wno-UNUSEDSIGNAL
VFLAGS += -Wno-UNUSEDPARAM
VFLAGS += -Wno-UNDRIVEN
VFLAGS += -Wno-CASEINCOMPLETE
VFLAGS += -Wno-DECLFILENAME
VFLAGS += -Wno-GENUNNAMED
VFLAGS += -Wno-DEFPARAM
VFLAGS += --top-module ram_logic_tb
VFLAGS += --timing
VFLAGS += -j 0

# Output binary
VTARGET := $(OUT_DIR)/Vram_logic_tb

# VCD output file
VCD_FILE := ram_logic_tb.vcd

# ============================================================================
# Targets
# ============================================================================

.PHONY: all sim clean help view

all: sim

# Build and run simulation
sim: $(VTARGET)
	@echo "================================================================"
	@echo "Running RAM Logic Simulation"
	@echo "================================================================"
	@./$(VTARGET) 2>&1 | tee simulation.log
	@echo ""
	@echo "================================================================"
	@echo "Simulation complete!"
	@echo "================================================================"
	@echo "Results:"
	@echo "  - simulation.log: Full simulation output"
	@echo "  - $(VCD_FILE): Waveform file"
	@echo ""
	@echo "To view waveforms:"
	@echo "  make view    (requires GTKWave)"
	@echo "================================================================"

# Build Verilator executable
$(VTARGET): $(ALL_SRC) | $(OUT_DIR)
	@echo "================================================================"
	@echo "Building Verilator simulation..."
	@echo "================================================================"
	@echo "Source files:"
	@for src in $(ALL_SRC); do echo "  - $$src"; done
	@echo ""
	@verilator $(VFLAGS) \
		-Mdir $(OUT_DIR) \
		$(ALL_SRC) 2>&1 | tee build.log
	@echo "Build complete."
	@echo ""

# Create output directory
$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

# View waveforms with GTKWave
view: $(VCD_FILE)
	@if command -v gtkwave >/dev/null 2>&1; then \
		echo "Opening waveforms in GTKWave..."; \
		gtkwave $(VCD_FILE) &; \
	else \
		echo "ERROR: GTKWave not found. Install with: sudo apt install gtkwave"; \
		exit 1; \
	fi

# Clean build artifacts
clean:
	@echo "Cleaning simulation artifacts..."
	@rm -rf $(OUT_DIR)
	@rm -f simulation.log build.log $(VCD_FILE)
	@echo "Clean complete."

# Help
help:
	@echo "RAM Logic Simulation Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  make sim    - Build and run simulation (default)"
	@echo "  make view   - Open waveforms in GTKWave"
	@echo "  make clean  - Remove all build artifacts"
	@echo "  make help   - Show this help message"
	@echo ""
	@echo "Files:"
	@echo "  $(TB_SRC)  - Testbench"
	@echo "  $(DUT_SRC)  - Design under test"
	@echo "  $(RAM_STUB)  - RAM primitive stub for simulation"
	@echo ""
	@echo "Output:"
	@echo "  simulation.log      - Simulation output"
	@echo "  $(VCD_FILE)  - Waveform file"
	@echo ""
