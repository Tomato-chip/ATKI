# I2S Capture 24-bit Testbench

Verilator-based testbench for the `i2s_capture_24.sv` module.

## Quick Start

```bash
# Build and run simulation
make sim

# Clean build artifacts
make clean

# View waveforms (after VCD fix)
make wave
```

## Files

- `Makefile` - Build and simulation control
- `../../digital/sampler/i2s_capture_24_tb.sv` - Testbench source
- `obj_dir/` - Verilator build directory (auto-generated)
- `simulation.log` - Simulation output (auto-generated)
- `i2s_capture_24_tb.vcd` - Waveform dump (when working)

## Test Results

**Status**: ❌ FAILED

The simulation identified a critical bug in `i2s_capture_24.sv` line 65:
- Counter logic checks `cnt_q == 24` before 25th bit is shifted
- Results in `ready_o` never asserting
- See `/home/tomato-chip/ATKI/docs/i2s_capture_24_test_report.md` for full analysis

## Requirements

- Verilator 5.0+
- GNU Make
- g++ compiler

## Test Coverage

The testbench validates:
1. ✅ Reset behavior
2. ❌ Frame capture (blocked by DUT bug)
3. ❌ Edge case patterns (blocked by DUT bug)
4. ❌ Alternating bit patterns (blocked by DUT bug)
5. ❌ Signed value handling (blocked by DUT bug)
6. ❌ Ready pulse timing (blocked by DUT bug)

## Simulation Parameters

- System Clock: 27 MHz
- SCK: 3.375 MHz (÷8)
- Frame Rate: ~52.7 kHz
- Frame Structure: 64 SCK cycles (32 per channel)

## Next Steps

1. Fix `i2s_capture_24.sv` counter logic (see test report)
2. Re-run: `make clean && make sim`
3. Verify all test phases pass
