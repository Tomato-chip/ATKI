# ============================================================================
# I2S Integration Test Makefile
# ============================================================================
# Builds and runs Verilator-based simulation of the complete I2S pipeline
# ============================================================================

# Directories
SIM_DIR := .
SRC_DIR := ../digital
OUT_DIR := out/i2s_integration_run

# Source files
TB_SRC := i2s_integration_tb.sv
CLK_GEN_SRC := $(SRC_DIR)/clk_generator/i2s_clock_gen.sv
CAPTURE_SRC := $(SRC_DIR)/sampler/i2s_capture_24.sv

ALL_SRC := $(TB_SRC) $(CLK_GEN_SRC) $(CAPTURE_SRC)

# Verilator flags
VFLAGS := --binary
VFLAGS += --trace
VFLAGS += --trace-structs
VFLAGS += --trace-max-array 1024
VFLAGS += -Wall
VFLAGS += -Wno-TIMESCALEMOD
VFLAGS += -Wno-WIDTHEXPAND
VFLAGS += -Wno-UNUSEDSIGNAL
VFLAGS += -Wno-UNUSEDPARAM
VFLAGS += --top-module i2s_integration_tb
VFLAGS += --timing
VFLAGS += -j 0
VFLAGS += -DSYNTHESIS  # Disable SVA assertions for Verilator compatibility

# Output binary
VTARGET := $(OUT_DIR)/Vi2s_integration_tb

# ============================================================================
# Targets
# ============================================================================

.PHONY: all sim clean help

all: sim

# Build and run simulation
sim: $(VTARGET)
	@echo "================================================================"
	@echo "Running I2S Integration Simulation"
	@echo "================================================================"
	@cd $(OUT_DIR) && ./Vi2s_integration_tb 2>&1 | tee simulation.log
	@echo ""
	@echo "Simulation complete. Results in $(OUT_DIR)/"
	@echo "  - simulation.log: Full simulation output"
	@echo "  - i2s_integration.vcd: Waveform file"
	@echo ""

# Build Verilator executable
$(VTARGET): $(ALL_SRC) | $(OUT_DIR)
	@echo "Building Verilator simulation..."
	@verilator $(VFLAGS) \
		-Mdir $(OUT_DIR)/obj_dir \
		$(ALL_SRC) 2>&1 | tee $(OUT_DIR)/build.log
	@mv $(OUT_DIR)/obj_dir/Vi2s_integration_tb $(OUT_DIR)/ 2>/dev/null || true
	@echo "Build complete."

# Create output directory
$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

# Clean build artifacts
clean:
	@echo "Cleaning simulation artifacts..."
	@rm -rf $(OUT_DIR)
	@echo "Clean complete."

# Help
help:
	@echo "I2S Integration Test Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  make sim    - Build and run simulation (default)"
	@echo "  make clean  - Remove all build artifacts"
	@echo "  make help   - Show this help message"
	@echo ""
	@echo "Output:"
	@echo "  $(OUT_DIR)/simulation.log   - Simulation output"
	@echo "  $(OUT_DIR)/i2s_integration.vcd - Waveform file"
	@echo ""
