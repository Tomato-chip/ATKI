# Makefile for i2s_capture_24 testbench simulation

# Paths
TB_NAME = i2s_capture_24_tb
DUT_PATH = ../../digital/sampler
TB_FILE = $(DUT_PATH)/$(TB_NAME).sv
DUT_FILE = $(DUT_PATH)/i2s_capture_24.sv

# Output files
SIM_DIR = .
VCD_FILE = $(SIM_DIR)/$(TB_NAME).vcd
OBJ_DIR = $(SIM_DIR)/obj_dir

# Verilator flags
VERILATOR = verilator
VFLAGS = --binary
VFLAGS += --trace
VFLAGS += --trace-structs
VFLAGS += -Wall
VFLAGS += -Wno-DECLFILENAME
VFLAGS += -Wno-WIDTHEXPAND
VFLAGS += -Wno-UNUSEDSIGNAL
VFLAGS += -Wno-REDEFMACRO
VFLAGS += --top-module $(TB_NAME)
VFLAGS += --timescale 1ns/1ps
VFLAGS += --Mdir $(OBJ_DIR)

# Build executable name
EXECUTABLE = $(OBJ_DIR)/V$(TB_NAME)

# Default target
.PHONY: all
all: sim

# Build the simulation
.PHONY: build
build: $(EXECUTABLE)

$(EXECUTABLE): $(TB_FILE) $(DUT_FILE)
	@echo "==> Building testbench with Verilator..."
	$(VERILATOR) $(VFLAGS) $(TB_FILE) $(DUT_FILE)
	@echo "==> Build complete: $@"

# Run the simulation
.PHONY: sim
sim: $(EXECUTABLE)
	@echo "==> Running simulation..."
	@echo ""
	cd $(SIM_DIR) && $(EXECUTABLE)
	@echo ""
	@echo "==> Simulation complete"
	@echo "==> Waveform: $(VCD_FILE)"

# View waveforms with GTKWave
.PHONY: wave
wave: $(VCD_FILE)
	@echo "==> Opening waveform viewer..."
	gtkwave $(VCD_FILE) &

# Clean build artifacts
.PHONY: clean
clean:
	@echo "==> Cleaning simulation artifacts..."
	rm -rf $(OBJ_DIR)
	rm -f $(VCD_FILE)
	rm -f *.log
	@echo "==> Clean complete"

# Help
.PHONY: help
help:
	@echo "i2s_capture_24 Testbench Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  all    - Build and run simulation (default)"
	@echo "  build  - Build testbench executable"
	@echo "  sim    - Run simulation"
	@echo "  wave   - View waveforms with GTKWave"
	@echo "  clean  - Remove build artifacts"
	@echo "  help   - Show this help message"
