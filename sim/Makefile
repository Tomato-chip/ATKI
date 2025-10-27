# ============================================================================
# I2S Integration Test Makefile
# ============================================================================
# Builds and runs Verilator-based simulation of the complete I2S pipeline
# ============================================================================

# Directories
SIM_DIR := .
SRC_DIR := ../digital
OUT_DIR := out/i2s_integration_run
SYSTEM_OUT_DIR := out/fpga_system_run

# Source files - I2S integration
TB_SRC := i2s_integration_tb.sv
CLK_GEN_SRC := $(SRC_DIR)/clk_generator/i2s_clock_gen.sv
CAPTURE_SRC := $(SRC_DIR)/sampler/i2s_capture_24.sv

ALL_SRC := $(TB_SRC) $(CLK_GEN_SRC) $(CAPTURE_SRC)

# Source files - Full system integration
SYSTEM_TB_SRC := fpga_system_tb.sv
RAM_SRC := $(SRC_DIR)/ram/ram_logic.sv
VU_SRC := $(SRC_DIR)/sampler/vu_meter_6led.sv
RAM_STUB := $(SRC_DIR)/ram/sp_ram_stub.v

SYSTEM_ALL_SRC := $(SYSTEM_TB_SRC) $(CLK_GEN_SRC) $(CAPTURE_SRC) $(RAM_SRC) $(VU_SRC) $(RAM_STUB)

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
VFLAGS += -Wno-DEFPARAM
VFLAGS += -Wno-BLKANDNBLK
VFLAGS += -Wno-WIDTHTRUNC
VFLAGS += -Wno-UNDRIVEN
VFLAGS += -Wno-CASEINCOMPLETE
VFLAGS += -Wno-DECLFILENAME
VFLAGS += -Wno-GENUNNAMED
VFLAGS += --timing
VFLAGS += -j 0
VFLAGS += -DSYNTHESIS  # Disable SVA assertions for Verilator compatibility

# Output binaries
VTARGET := $(OUT_DIR)/Vi2s_integration_tb
SYSTEM_VTARGET := $(SYSTEM_OUT_DIR)/Vfpga_system_tb

# ============================================================================
# Targets
# ============================================================================

.PHONY: all sim system clean clean-all help list

all: system

# Build and run I2S integration simulation
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

# Build and run full system simulation
system: $(SYSTEM_VTARGET)
	@echo "================================================================"
	@echo "Running FPGA System Integration Simulation"
	@echo "================================================================"
	@cd $(SYSTEM_OUT_DIR) && ./Vfpga_system_tb 2>&1 | tee simulation.log
	@echo ""
	@echo "================================================================"
	@echo "Simulation complete!"
	@echo "================================================================"
	@echo "Results in $(SYSTEM_OUT_DIR)/"
	@echo "  - simulation.log: Full simulation output"
	@echo "  - fpga_system_tb.vcd: Waveform file"
	@echo ""
	@if [ -f $(SYSTEM_OUT_DIR)/fpga_system_tb.vcd ]; then \
		ls -lh $(SYSTEM_OUT_DIR)/fpga_system_tb.vcd; \
	fi
	@echo "================================================================"

# Build I2S Verilator executable
$(VTARGET): $(ALL_SRC) | $(OUT_DIR)
	@echo "Building I2S Verilator simulation..."
	@verilator $(VFLAGS) --top-module i2s_integration_tb \
		-Mdir $(OUT_DIR)/obj_dir \
		$(ALL_SRC) 2>&1 | tee $(OUT_DIR)/build.log
	@mv $(OUT_DIR)/obj_dir/Vi2s_integration_tb $(OUT_DIR)/ 2>/dev/null || true
	@echo "Build complete."

# Build System Verilator executable
$(SYSTEM_VTARGET): $(SYSTEM_ALL_SRC) | $(SYSTEM_OUT_DIR)
	@echo "================================================================"
	@echo "Building FPGA System Verilator simulation..."
	@echo "================================================================"
	@echo "Source files:"
	@for src in $(SYSTEM_ALL_SRC); do echo "  - $$src"; done
	@echo ""
	@verilator $(VFLAGS) --top-module fpga_system_tb \
		-Mdir $(SYSTEM_OUT_DIR)/obj_dir \
		$(SYSTEM_ALL_SRC) 2>&1 | tee $(SYSTEM_OUT_DIR)/build.log
	@mv $(SYSTEM_OUT_DIR)/obj_dir/Vfpga_system_tb $(SYSTEM_OUT_DIR)/ 2>/dev/null || true
	@echo "Build complete."

# Create output directories
$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

$(SYSTEM_OUT_DIR):
	@mkdir -p $(SYSTEM_OUT_DIR)

# List source files
list:
	@echo "I2S Integration Test Sources:"
	@for src in $(ALL_SRC); do echo "  $$src"; done
	@echo ""
	@echo "Full System Integration Sources:"
	@for src in $(SYSTEM_ALL_SRC); do echo "  $$src"; done

# Clean I2S build artifacts
clean:
	@echo "Cleaning I2S simulation artifacts..."
	@rm -rf $(OUT_DIR)
	@echo "Clean complete."

# Clean all build artifacts
clean-all:
	@echo "Cleaning all simulation artifacts..."
	@rm -rf $(OUT_DIR) $(SYSTEM_OUT_DIR)
	@echo "Clean complete."

# Help
help:
	@echo "FPGA Simulation Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  make system    - Build and run full system simulation (default)"
	@echo "  make sim       - Build and run I2S integration only"
	@echo "  make list      - List all source files"
	@echo "  make clean     - Remove I2S build artifacts"
	@echo "  make clean-all - Remove all build artifacts"
	@echo "  make help      - Show this help message"
	@echo ""
	@echo "System Components (Full System):"
	@echo "  - i2s_clock_gen   : I2S clock generator"
	@echo "  - i2s_capture_24  : I2S sampler"
	@echo "  - ram_logic       : Ping-pong RAM"
	@echo "  - vu_meter_6led   : VU meter consumer"
	@echo ""
	@echo "Output:"
	@echo "  $(SYSTEM_OUT_DIR)/simulation.log        - System simulation output"
	@echo "  $(SYSTEM_OUT_DIR)/fpga_system_tb.vcd    - System waveform file"
	@echo "  $(OUT_DIR)/simulation.log               - I2S simulation output"
	@echo "  $(OUT_DIR)/i2s_integration.vcd          - I2S waveform file"
	@echo ""
