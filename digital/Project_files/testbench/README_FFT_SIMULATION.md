# FFT System Simulation Guide

## Overview

This directory contains testbenches for verifying the complete audio capture and FFT system.

## Test Files

### Full System Testbench
- **fpga_template_top_fft_tb.sv** - Complete system testbench with I2S audio input simulation and FFT verification
  - Tests single-frequency sine wave (Bin 16)
  - Tests DC signal (Bin 0)
  - Tests two-tone signal (Bins 16 and 32)
  - Verifies FFT output correctness

### Individual Module Testbenches
- **fft_256_tb.sv** - Standalone FFT module testbench
- **ram_logic_tb.sv** - RAM ping-pong buffer testbench
- **test_ram_logic.py** - Cocotb-based RAM testbench

## Required Source Files

To run the full system testbench, you need:

1. **FFT Modules**:
   - `fft_256.sv` - 256-point FFT module
   - `fft_twiddle_256.sv` - Twiddle factor ROM

2. **System Modules**:
   - `../fpga_template/fpga_template.sv` - Top-level module with FFT integrated
   - `ram_logic_test.sv` - Ping-pong RAM buffer (DEPTH=256)
   - `i2s_clock_gen_test.sv` - I2S clock generator
   - `i2s_capture_24_test.sv` - I2S capture module

3. **Testbench Infrastructure**:
   - `testbench/gowin_sp_ram_model.sv` - RAM behavioral model
   - `testbench/fpga_template_top_fft_tb.sv` - Main testbench

## Running the Simulation

### Option 1: Using Icarus Verilog (iverilog)

```bash
cd /home/tomato-chip/ATKI/digital/Project_files

# Compile all source files
iverilog -g2012 -o sim_fft_system \
  fft_256.sv \
  fft_twiddle_256.sv \
  ../fpga_template/fpga_template.sv \
  ram_logic_test.sv \
  i2s_clock_gen_test.sv \
  i2s_capture_24_test.sv \
  testbench/gowin_sp_ram_model.sv \
  testbench/fpga_template_top_fft_tb.sv

# Run simulation
vvp sim_fft_system

# View waveforms (optional)
gtkwave fpga_template_top_fft_tb.vcd
```

### Option 2: Using Verilator

```bash
cd /home/tomato-chip/ATKI/digital/Project_files

# Verilator requires a C++ testbench wrapper
# Note: The SystemVerilog testbench needs to be adapted for Verilator
verilator --binary -j 0 -Wall \
  --top-module fpga_template_top_fft_tb \
  fft_256.sv \
  fft_twiddle_256.sv \
  ../fpga_template/fpga_template.sv \
  ram_logic_test.sv \
  i2s_clock_gen_test.sv \
  i2s_capture_24_test.sv \
  testbench/gowin_sp_ram_model.sv \
  testbench/fpga_template_top_fft_tb.sv

./obj_dir/Vfpga_template_top_fft_tb
```

### Option 3: Using Cocotb (Python-based)

If you have cocotb installed:

```bash
# Install cocotb (if not already installed)
pip3 install cocotb cocotb-bus

# Create a Makefile for cocotb
# (Refer to test_ram_logic.py for examples)
```

## Expected Results

The verification script `verify_fft_system.py` calculates the expected FFT outputs:

```bash
python3 verify_fft_system.py
```

### Test 1: Single Frequency (Bin 16)
- **Input**: Sine wave at bin 16 (frequency = 16/256 of sample rate)
- **Expected Output**: Peak at FFT bin 16 with magnitude ~64
- **Verification**: Check that `peak_bin` in simulation matches bin 16

### Test 2: DC Signal
- **Input**: Constant value (DC)
- **Expected Output**: Peak at FFT bin 0 with magnitude ~64
- **Verification**: Bin 0 should have highest magnitude

### Test 3: Two-Tone Signal
- **Input**: Sum of two sine waves at bins 16 and 32
- **Expected Output**: Two peaks at bins 16 and 32, each with magnitude ~32
- **Verification**: Both bins should show significant magnitude

## Verification Criteria

1. **Peak Detection**: FFT output should show peak at expected bin (±1 bin tolerance)
2. **Magnitude**: Peak magnitude should be proportional to input amplitude
3. **Timing**: FFT should complete within ~512 clock cycles
4. **Data Flow**: Signals `fft_busy` and `fft_output_valid` should assert correctly

## Debugging Tips

1. **View Waveforms**: Use GTKWave to inspect signals
   ```bash
   gtkwave fpga_template_top_fft_tb.vcd
   ```

2. **Check Key Signals**:
   - `i2s_ws` - I2S word select (frame timing)
   - `buffer_ready` - RAM buffer swap signal
   - `fft_busy` - FFT computation in progress
   - `fft_output_valid` - FFT output valid
   - `peak_bin` - Detected peak frequency bin

3. **Monitor FFT Outputs**:
   - `dut.fft_data_real_o` - Real component output
   - `dut.fft_data_imag_o` - Imaginary component output

## Module Configuration

### RAM Buffer
- **DEPTH**: 256 samples (changed from 16 to match FFT size)
- **WIDTH**: 32 bits (24-bit audio + padding)

### FFT Module
- **Size**: 256 points
- **Stages**: 8 (log2(256))
- **Data Width**: 24 bits (Q1.23 fixed-point)
- **Processing Time**: ~512 clock cycles

### I2S Configuration
- **Sample Rate**: Determined by I2S clock generator
- **Bit Depth**: 24 bits
- **Channels**: Left channel only (mono)

## Troubleshooting

### Simulation doesn't compile
- Ensure all source files are present
- Check for syntax errors in modified files
- Verify simulator supports SystemVerilog 2012

### FFT output incorrect
- Check input signal generation in testbench
- Verify RAM buffer correctly feeds FFT
- Check twiddle factor ROM values
- Inspect bit-reversal logic

### Simulation timeout
- Increase timeout in testbench (currently 100ms)
- Check for stuck FSM states
- Verify handshaking signals (valid/ready)

## File Organization

```
Project_files/
├── fft_256.sv                          # FFT main module
├── fft_twiddle_256.sv                  # Twiddle factors
├── ram_logic_test.sv                   # RAM buffer (DEPTH=256)
├── i2s_clock_gen_test.sv              # I2S clock
├── i2s_capture_24_test.sv             # I2S capture
├── verify_fft_system.py               # Expected output calculator
├── testbench/
│   ├── fpga_template_top_fft_tb.sv   # Full system testbench
│   ├── fft_256_tb.sv                  # FFT standalone test
│   ├── ram_logic_tb.sv                # RAM standalone test
│   ├── gowin_sp_ram_model.sv         # RAM behavioral model
│   └── README_FFT_SIMULATION.md       # This file
└── ../fpga_template/
    └── fpga_template.sv                # Top module with FFT
```

## Next Steps

1. Install simulation tools (iverilog recommended for quick start)
2. Run `verify_fft_system.py` to see expected results
3. Compile and run the full system testbench
4. View waveforms to verify operation
5. Adjust parameters if needed for your application

## References

- FFT Implementation: Radix-2 Decimation-In-Time (DIT)
- Fixed-Point Format: Q1.23 (1 sign bit, 23 fractional bits)
- Twiddle Factors: Precomputed W_N^k = e^(-j*2π*k/N)
