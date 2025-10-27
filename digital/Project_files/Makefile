# ============================================================================
# Makefile for fpga_template_top Verilator Simulation
# ============================================================================

# Source files
TB_SRC := fpga_template_top_tb.sv
DUT_SRCS := fpga_template.sv i2s_clock_gen.sv i2s_capture_24.sv ram_logic.sv vu_meter_6led.sv
RAM_STUB := sp_ram_stub.v

ALL_SRC := $(TB_SRC) $(DUT_SRCS) $(RAM_STUB)

# Output directory
OUT_DIR := obj_dir

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
VFLAGS += -Wno-BLKANDNBLK
VFLAGS += -Wno-PINCONNECTEMPTY
VFLAGS += --top-module fpga_template_top_tb
VFLAGS += --timing
VFLAGS += -j 0
VFLAGS += -DSYNTHESIS

# Output binary
VTARGET := $(OUT_DIR)/Vfpga_template_top_tb

# VCD file
VCD_FILE := fpga_template_top_tb.vcd

# ============================================================================
# Targets
# ============================================================================

.PHONY: all sim clean help list

all: sim

# Build and run simulation
sim: $(VTARGET)
	@echo "================================================================"
	@echo "Running FPGA Template Top Simulation"
	@echo "================================================================"
	@./$(VTARGET) 2>&1 | tee simulation.log
	@echo ""
	@echo "================================================================"
	@echo "Simulation complete!"
	@echo "================================================================"
	@if [ -f $(VCD_FILE) ]; then \
		echo "VCD file generated:"; \
		ls -lh $(VCD_FILE); \
	else \
		echo "WARNING: VCD file not found!"; \
	fi
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

# List source files
list:
	@echo "Source files:"
	@for src in $(ALL_SRC); do echo "  $$src"; done

# Clean build artifacts
clean:
	@echo "Cleaning simulation artifacts..."
	@rm -rf $(OUT_DIR)
	@rm -f simulation.log build.log $(VCD_FILE)
	@echo "Clean complete."

# Help
help:
	@echo "FPGA Template Top Simulation Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  make sim    - Build and run simulation (default)"
	@echo "  make list   - List all source files"
	@echo "  make clean  - Remove all build artifacts"
	@echo "  make help   - Show this help message"
	@echo ""
	@echo "Output:"
	@echo "  simulation.log          - Full simulation output"
	@echo "  $(VCD_FILE)  - Waveform file"
	@echo "  build.log               - Verilator build log"
	@echo ""
