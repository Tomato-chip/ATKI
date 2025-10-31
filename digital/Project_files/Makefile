#==============================================================================
# Makefile for FPGA I2S Audio Capture System Simulation
#==============================================================================

# Verilator settings
VERILATOR = verilator
VERILATOR_FLAGS = --binary --trace --timing -Wall -Wno-fatal
VERILATOR_FLAGS += --top-module fpga_template_top_tb

# Source files
TB_TOP = fpga_template_top_tb.sv
DUT_TOP = fpga_template_test.sv

SRC_FILES = \
	$(TB_TOP) \
	$(DUT_TOP) \
	i2s_capture_24_test.sv \
	i2s_clock_gen_test.sv \
	ram_logic_test.sv \
	vu_meter_6led_test.sv \
	sp_ram_stub.v

# Output directory
OBJ_DIR = obj_dir
VCD_FILE = fpga_template_top_tb.vcd

# Targets
.PHONY: all sim clean help

all: sim

# Build and run simulation
sim: $(OBJ_DIR)/V$(basename $(TB_TOP))
	@echo "==================================================================="
	@echo "Running simulation..."
	@echo "==================================================================="
	./$(OBJ_DIR)/V$(basename $(TB_TOP))
	@echo ""
	@echo "Simulation complete. Waveform saved to $(VCD_FILE)"
	@echo "View with: gtkwave $(VCD_FILE)"

# Verilator build
$(OBJ_DIR)/V$(basename $(TB_TOP)): $(SRC_FILES)
	@echo "==================================================================="
	@echo "Building with Verilator..."
	@echo "==================================================================="
	$(VERILATOR) $(VERILATOR_FLAGS) $(SRC_FILES)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR)
	rm -f $(VCD_FILE)
	@echo "Clean complete"

# View waveform
wave: $(VCD_FILE)
	gtkwave $(VCD_FILE) &

# Help
help:
	@echo "FPGA I2S Audio Capture System - Simulation Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  make          - Build and run simulation (default)"
	@echo "  make sim      - Build and run simulation"
	@echo "  make clean    - Remove build artifacts and waveforms"
	@echo "  make wave     - Open waveform viewer (GTKWave)"
	@echo "  make help     - Show this help message"
	@echo ""
	@echo "Output:"
	@echo "  Executable:   $(OBJ_DIR)/V$(basename $(TB_TOP))"
	@echo "  Waveform:     $(VCD_FILE)"
