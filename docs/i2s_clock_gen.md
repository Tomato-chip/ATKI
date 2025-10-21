# I2S Clock Generator

## Overview

The `i2s_clock_gen` module generates precise clock signals for I2S (Inter-IC Sound) audio interfaces. It produces two output clocks:
- **SCK** (Serial Clock / Bit Clock): The clock signal that synchronizes data transmission
- **WS** (Word Select / LRCLK): The frame sync signal that indicates left/right channel

Additionally, it provides an optional `frame_start` pulse that marks the beginning of a new audio frame.

## Default Configuration

With default parameters, the module generates the following frequencies from a 27 MHz system clock:

| Signal | Frequency | Period | Description |
|--------|-----------|--------|-------------|
| System Clock | 27 MHz | 37.037 ns | Input clock |
| SCK | 3.375 MHz | 296.3 ns | Serial clock (27 MHz / 8) |
| WS | 52.734 kHz | 18.96 μs | Word select (3.375 MHz / 64) |

## Module Interface

### Parameters

```systemverilog
parameter int unsigned SYS_CLK_HZ      = 27_000_000  // System clock frequency in Hz
parameter int unsigned SCK_DIV         = 8            // SCK divider (must be >= 2)
parameter int unsigned SCKS_PER_FRAME  = 64           // SCK cycles per full frame (L+R)
parameter bit          WS_POL          = 1'b0         // WS polarity (0=left-low, 1=left-high)
parameter bit          FRAME_PULSE_EN  = 1'b1         // Enable frame_start_o output
```

### Ports

```systemverilog
input  logic clk_i            // System clock
input  logic rst_ni           // Active-low synchronous reset
output logic sck_o            // Serial Clock (bit clock)
output logic ws_o             // Word Select (LRCLK)
output logic frame_start_o    // One-cycle pulse at left channel start
```

## Frequency Calculations

The output frequencies are derived using these formul human:

:

```
SCK_HZ = SYS_CLK_HZ / SCK_DIV
WS_HZ = SCK_HZ / SCKS_PER_FRAME
```

### Example Configurations

#### Configuration 1: 44.1 kHz Audio (typical CD quality)
```systemverilog
i2s_clock_gen #(
  .SYS_CLK_HZ(27_000_000),
  .SCK_DIV(10),              // 2.7 MHz SCK
  .SCKS_PER_FRAME(64)        // ~42.2 kHz WS
) u_i2s_clk (/*...*/);
```

#### Configuration 2: 48 kHz Audio (typical pro audio)
For 48 kHz, you would need a different system clock or adjust parameters accordingly:
```systemverilog
// With 24.576 MHz system clock:
i2s_clock_gen #(
  .SYS_CLK_HZ(24_576_000),
  .SCK_DIV(8),               // 3.072 MHz SCK
  .SCKS_PER_FRAME(64)        // 48 kHz WS
) u_i2s_clk (/*...*/);
```

#### Configuration 3: TDM Array with 7 Microphones
For a TDM (Time Division Multiplexed) array with 7 microphones, you might use:
```systemverilog
i2s_clock_gen #(
  .SYS_CLK_HZ(27_000_000),
  .SCK_DIV(8),               // 3.375 MHz SCK
  .SCKS_PER_FRAME(128)       // ~26.4 kHz WS (64 bits × 7 mics = 448 bits total)
) u_i2s_clk (/*...*/);
```

**Note:** For 7 microphones, additional data line handling is required. This module provides only the clock signals (SCK/WS); data lines (SDx) must be handled by separate logic.

## Timing Specifications

### SCK Generation
- **Duty Cycle:** 50% ±1 system clock cycle
- **Period Precision:** Exactly `SCK_DIV` system clock cycles
- **Jitter:** Minimal (deterministic, based on system clock)

### WS Generation
- **Transition Timing:** WS transitions occur only on SCK falling edges (standard I2S convention)
- **Period:** Exactly `SCKS_PER_FRAME * SCK_DIV * 2` system clock cycles (full L+R frame)
- **Polarity:** Configurable via `WS_POL` parameter
  - `WS_POL = 0`: WS low = left channel, WS high = right channel (standard)
  - `WS_POL = 1`: WS low = right channel, WS high = left channel

### Frame Start Pulse
- **Timing:** Single-cycle pulse at the beginning of the left channel
- **Enable/Disable:** Controlled by `FRAME_PULSE_EN` parameter
- **Use Case:** Synchronizing downstream audio processing blocks

## Design Features

### Synthesis-Friendly
- Single-clocked design (no derived clocks)
- No latches
- All state in flip-flops
- Fully synchronous reset

### Clock Domain
- Single clock domain (system clock)
- No CDC (Clock Domain Crossing) issues
- Safe for FPGA implementation

### Resource Usage
Minimal resource utilization:
- Two small counters (`$clog2(SCK_DIV)` and `$clog2(SCKS_PER_FRAME)` bits)
- A few flip-flops for state
- Simple combinational logic

## Verification

The module includes comprehensive testbenches:

### 1. Full-Featured Testbench (`i2s_clock_gen_tb.sv`)
- SystemVerilog Assertions (SVA) for timing verification
- Functional coverage bins
- Period and duty cycle measurements
- Self-checking with PASS/FAIL reporting

### 2. Verilator-Compatible Testbench (`i2s_clock_gen_tb_verilator.sv`)
- Compatible with Verilator open-source simulator
- Blocking assignment version for synthesis tool compatibility
- Full measurement and verification

### 3. Simple Testbench (`i2s_clock_gen_tb_simple.sv`)
- Quick verification of basic functionality
- Minimal code for fast simulation

### Running the Testbench

With Verilator:
```bash
verilator --binary --timing \
  -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND -Wno-TIMESCALEMOD \
  --top-module i2s_clock_gen_tb_simple \
  -Irtl rtl/i2s_clock_gen_verilator.sv sim/i2s_clock_gen_tb_simple.sv
./obj_dir/Vi2s_clock_gen_tb_simple
```

Expected output: **TEST PASS** with timing measurements

## Integration Example

### Basic Instantiation

```systemverilog
module audio_system (
  input  logic       clk_27mhz,
  input  logic       rst_n,
  // I2S outputs to codec
  output logic       i2s_sck,
  output logic       i2s_ws,
  input logic       i2s_sd
);

  logic frame_start;

  // Generate I2S clocks
  i2s_clock_gen #(
    .SYS_CLK_HZ(27_000_000),
    .SCK_DIV(8),
    .SCKS_PER_FRAME(64)
  ) u_i2s_clocks (
    .clk_i         ( clk_27mhz   ),
    .rst_ni        ( rst_n       ),
    .sck_o         ( i2s_sck     ),
    .ws_o          ( i2s_ws      ),
    .frame_start_o ( frame_start )
  );

  // Your audio data handling logic here
  // Use frame_start to synchronize data

endmodule
```

### Multi-Microphone Array Example

```systemverilog
module mic_array_7ch (
  input  logic       clk_27mhz,
  input  logic       rst_n,
  input  logic [6:0] mic_data_in,   // 7 microphone data lines
  output logic       i2s_sck,
  output logic       i2s_ws,
  output logic       processed_valid
);

  logic frame_start;

  // Generate clocks for 7-channel TDM
  i2s_clock_gen #(
    .SYS_CLK_HZ(27_000_000),
    .SCK_DIV(8),
    .SCKS_PER_FRAME(64),           // Adjust based on bit depth
    .FRAME_PULSE_EN(1'b1)
  ) u_i2s_clocks (
    .clk_i         ( clk_27mhz   ),
    .rst_ni        ( rst_n       ),
    .sck_o         ( i2s_sck     ),
    .ws_o          ( i2s_ws      ),
    .frame_start_o ( frame_start )
  );

  // Use frame_start to trigger data capture/processing
  always_ff @(posedge clk_27mhz) begin
    if (frame_start) begin
      // Start capturing data from all 7 microphones
      processed_valid <= 1'b1;
    end
  end

  // TDM data handling for 7 channels would go here

endmodule
```

## Constraints and Limitations

1. **Minimum Divider:** `SCK_DIV` must be ≥ 2
2. **Minimum Frame Size:** `SCKS_PER_FRAME` must be ≥ 2
3. **Integer Division:** Frequencies must divide evenly for exact timing
4. **Clock Quality:** Output clock quality depends on input system clock quality
5. **No PLL:** This module does not include a PLL; use external clock generation if exact audio frequencies are required

## Files

- `rtl/i2s_clock_gen.sv` - Main RTL with SVA assertions (for simulation)
- `rtl/i2s_clock_gen_verilator.sv` - Verilator-compatible version (for open-source tools)
- `sim/i2s_clock_gen_tb.sv` - Full testbench with assertions and coverage
- `sim/i2s_clock_gen_tb_verilator.sv` - Verilator-compatible testbench
- `sim/i2s_clock_gen_tb_simple.sv` - Simple functional testbench
- `docs/i2s_clock_gen.md` - This document

## References

- I2S Specification: [Philips I2S Bus Specification](https://www.sparkfun.com/datasheets/BreakoutBoards/I2SBUS.pdf)
- TDM: Time Division Multiplexing for multi-channel audio
- Standard audio sample rates: 8 kHz, 16 kHz, 32 kHz, 44.1 kHz, 48 kHz, 96 kHz, 192 kHz

## License

This module is provided as part of the ATKI FPGA project.

## Revision History

| Version | Date | Description |
|---------|------|-------------|
| 1.0 | 2025-10-14 | Initial release with full verification |
