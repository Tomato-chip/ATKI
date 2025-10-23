# Ping-Pong Buffer with Gowin SP RAMs

## Overview

This directory contains a ping-pong buffer implementation using two Gowin SP (Single-Port) BSRAMs with full handshaking support.

## Files

- **`pingpong_buffer_sp.sv`** - Main ping-pong buffer module with dual SP RAMs
- **`../sim/pingpong_buffer_sp_tb.sv`** - Comprehensive testbench
- **`../sim/pingpong_buffer_sp_tb_simple.sv`** - Simplified testbench
- **`../sim/gowin_sp_sim.v`** - Behavioral simulation model for Gowin SP primitive

## Module: pingpong_buffer_sp

### Parameters
- `SAMPLE_W` (default 16) - Sample width in bits
- `BUF_LEN` (default 256) - Buffer length in samples

### Interface

#### Clock & Reset
- `clk_i` - System clock
- `rst_ni` - Active-low synchronous reset

#### Write Side (Producer)
- `wr_data_i[SAMPLE_W-1:0]` - Write data
- `wr_valid_i` - Producer has data
- `wr_ready_o` - Buffer ready to accept data (backpressure)
- `sample_ready_i` - Optional: 1-clk strobe per sample (tie to 1'b1 if unused)
- `frame_start_i` - Optional: frame boundary marker

#### Read Side (Consumer)
- `rd_data_o[SAMPLE_W-1:0]` - Read data
- `rd_valid_o` - Buffer has data for consumer
- `rd_ready_i` - Consumer ready to accept
- `rd_last_o` - Asserted on last word (256th) of block

#### Buffer Control
- `buf_ready_o` - 1-clk pulse when 256-sample block is filled
- `buf_id_o` - Which RAM is ready (0 or 1)
- `buf_take_i` - Consumer acknowledges and starts reading buffer
- `buf_empty_o` - No filled buffers available
- `overrun_o` - Writer stalled (both buffers occupied)
- `underrun_o` - Consumer requested data but none available

### Operation

1. **Write Phase**: Producer writes samples with `wr_valid_i=1` while `wr_ready_o=1`. After 256 samples, `buf_ready_o` pulses.

2. **Buffer Handoff**: Consumer asserts `buf_take_i` for one cycle to start reading the filled buffer.

3. **Read Phase**: Consumer reads with `rd_ready_i=1` while `rd_valid_o=1`. After 256 samples, `rd_last_o` pulses.

4. **Ping-Pong**: Writer and reader automatically swap RAMs after each block.

### SP RAM Configuration
- **BIT_WIDTH**: 16
- **READ_MODE**: 1'b1 (BYPASS - zero-latency output)
- **WRITE_MODE**: 2'b00 (NORMAL - synchronous write)
- **RESET_MODE**: "SYNC"
- **Address Mapping**: AD = {2'b00, addr[7:0], 4'b0000}

## Simulation

### Build and Run
```bash
cd sim
make -f Makefile.pingpong_buffer clean
make -f Makefile.pingpong_buffer sim
```

### Waveforms
Output VCD file: `sim/out/pingpong_buffer_run/pingpong_buffer_sp_tb_simple.vcd`

## Status

**Implementation Status**: ⚠️ In Development

The module has been implemented according to the specification with:
- ✅ Dual SP RAM instantiation with correct parameters
- ✅ Full handshaking on write and read sides
- ✅ Buffer state tracking and management
- ✅ Overrun/underrun detection
- ✅ Comprehensive testbenches
- ✅ Makefile for simulation

**Known Issues**: The simulation currently has bugs that need debugging:
- buf_ready signal generation needs verification
- Data path through SP RAMs needs checking
- State machine transitions need review

**Next Steps**:
1. Debug write state machine and buf_ready generation
2. Verify SP RAM model and data path
3. Test with waveform viewer (GTKWave)
4. Add assertions for protocol checking

## Integration Example

```systemverilog
pingpong_buffer_sp #(
    .SAMPLE_W(16),
    .BUF_LEN(256)
) u_pingpong (
    .clk_i          (clk),
    .rst_ni         (rst_n),
    .wr_data_i      (sample_data),
    .wr_valid_i     (sample_valid),
    .wr_ready_o     (sample_ready),
    .sample_ready_i (1'b1),           // Continuous operation
    .frame_start_i  (1'b0),           // Unused
    .rd_data_o      (fft_data),
    .rd_valid_o     (fft_valid),
    .rd_ready_i     (fft_ready),
    .rd_last_o      (fft_last),
    .buf_ready_o    (block_ready),
    .buf_id_o       (block_id),
    .buf_take_i     (block_take),
    .buf_empty_o    (no_data),
    .overrun_o      (write_stall),
    .underrun_o     (read_stall)
);
```

## References

- **Gowin SP BSRAM Primitive**: Single-port block RAM with configurable width and modes
- **AXI-Stream Protocol**: Similar handshaking semantics for TVALID/TREADY/TLAST
