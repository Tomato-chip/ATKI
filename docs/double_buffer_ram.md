# Double-Buffer (Ping-Pong) RAM Controller

## Overview

The `double_buffer_ram` module implements a double-buffering scheme for continuous data sampling and processing. It uses two independent RAM buffers (A and B) that alternate roles between write (sampling) and read (processing).

**Key Features:**
- Continuous sampling without data loss
- Concurrent write to one buffer while reading from the other
- Automatic buffer switching when full
- Support for both Gowin DPB primitives and generic behavioral RAM
- Parameterizable data width and buffer depth
- Buffer-ready signaling for downstream synchronization

## Architecture

```
                    +------------------------+
  in_valid_i ------>|                        |
  in_data_i  ------>|   Write Controller     |
                    |   (write_addr counter) |
                    +------------------------+
                             |
                    +--------+--------+
                    |                 |
               +----v----+       +----v----+
               |         |       |         |
               | Buffer  |       | Buffer  |
               |    A    |       |    B    |
               | (256x16)|       | (256x16)|
               |         |       |         |
               +----+----+       +----+----+
                    |                 |
                    +--------+--------+
                             |
  rd_addr_i  --------------->| Read Mux        |-----> rd_data_o
  rd_en_i    --------------->| (inactive buf)  |-----> rd_data_valid_o
                             +------------------+

  active_buf_o       <--- Indicates which buffer is being written
  buf_ready_pulse_o  <--- Pulse when a buffer fills
  buf_ready_id_o     <--- ID of buffer that just filled
```

## Operation

### Buffer Switching

1. **Initial State**: Buffer A is active (being written), Buffer B is inactive (available for reading)
2. **Filling**: Incoming samples are written sequentially to Buffer A at addresses 0..255
3. **Buffer Full**: When 256 samples have been written:
   - `buf_ready_pulse_o` asserts for one clock cycle
   - `buf_ready_id_o` indicates which buffer just filled (0=A, 1=B)
   - `active_buf_o` toggles to point to Buffer B
4. **Role Swap**: Buffer A becomes inactive (readable), Buffer B becomes active (writable)
5. **Continuous Operation**: Process repeats indefinitely

### Write Timing

```
Cycle:      0    1    2    3    ...  255  256  257  258
in_valid_i: 1    1    1    1    ...  1    0    1    1
in_data_i:  D0   D1   D2   D3   ...  D255 X    D256 D257
write_addr: 0    1    2    3    ...  255  0    1    2
active_buf: A    A    A    A    ...  A    B    B    B
buf_ready:  0    0    0    0    ...  0    1    0    0
```

### Read Timing (1-cycle latency)

```
Cycle:       0    1    2    3    4
rd_addr_i:   0    1    2    3    4
rd_en_i:     1    1    1    1    1
rd_data_o:   X    D0   D1   D2   D3
rd_valid_o:  0    1    1    1    1
```

## Interface

### Parameters

| Parameter | Default | Description |
|-----------|---------|-------------|
| `DATA_WIDTH` | 16 | Width of each data sample in bits |
| `SAMPLES_PER_BUF` | 256 | Number of samples per buffer |
| `ADDR_WIDTH` | `$clog2(SAMPLES_PER_BUF)` | Address bus width (auto-calculated) |
| `SYNTH_USE_GOWIN_DPB` | 1 | 1=Use Gowin DPB primitives, 0=Use generic RAM |
| `DROP_WRITES_ON_TOGGLE` | 1 | (Reserved) Drop writes during buffer toggle cycle |

### Ports

#### Clock and Reset
- `clk_i` (input): System clock
- `rst_ni` (input): Active-low synchronous reset

#### Write Interface (Sampling)
- `in_valid_i` (input): Write enable - assert to write a sample
- `in_data_i[DATA_WIDTH-1:0]` (input): Sample data to write
- `in_ready_o` (output): Back-pressure signal (always 1 in current implementation)

#### Read Interface (Processing)
- `rd_addr_i[ADDR_WIDTH-1:0]` (input): Read address for inactive buffer
- `rd_en_i` (input): Read enable
- `rd_data_o[DATA_WIDTH-1:0]` (output): Read data from inactive buffer (1-cycle latency)
- `rd_data_valid_o` (output): Read data valid flag (pipelined rd_en_i)

#### Status and Control
- `active_buf_o` (output): Currently active buffer (0=A writing, 1=B writing)
- `buf_ready_pulse_o` (output): One-cycle pulse when a buffer becomes full
- `buf_ready_id_o` (output): ID of buffer that just filled (0=A, 1=B)

## Usage Example

### Continuous Sampling System

```systemverilog
// Instantiate double-buffer RAM
double_buffer_ram #(
    .DATA_WIDTH      (16),
    .SAMPLES_PER_BUF (256),
    .SYNTH_USE_GOWIN_DPB (1'b1)
) sample_buffer (
    .clk_i              (clk),
    .rst_ni             (rst_n),

    // Connect to ADC or data source
    .in_valid_i         (adc_valid),
    .in_data_i          (adc_data),
    .in_ready_o         (adc_ready),

    // Connect to processing block
    .rd_addr_i          (proc_addr),
    .rd_en_i            (proc_en),
    .rd_data_o          (proc_data),
    .rd_data_valid_o    (proc_valid),

    // Status
    .active_buf_o       (current_buf),
    .buf_ready_pulse_o  (buffer_full),
    .buf_ready_id_o     (full_buf_id)
);

// Processor triggered by buffer_full
always_ff @(posedge clk) begin
    if (buffer_full) begin
        // Start processing the completed buffer
        start_processing <= 1'b1;
        processing_buffer_id <= full_buf_id;
    end
end
```

### Integration Notes

1. **Write Side**: Connect `in_valid_i` and `in_data_i` to your data source (ADC, FIFO, etc.)
   - Samples are written whenever `in_valid_i` is high
   - No need to manage addresses - controller handles it automatically

2. **Read Side**: Connect `rd_addr_i` and `rd_en_i` to your processing logic
   - You control which addresses to read and when
   - Read data appears with 1-cycle latency
   - Always reads from the INACTIVE buffer (safe from write conflicts)

3. **Synchronization**: Use `buf_ready_pulse_o` to trigger processing
   - This pulse indicates a complete buffer of data is ready
   - `buf_ready_id_o` tells you which buffer (A or B) to process
   - Processing can proceed while the other buffer fills

## Gowin DPB Implementation Notes

When `SYNTH_USE_GOWIN_DPB=1`, the module instantiates Gowin `DPB` primitives for on-chip block RAM.

### Address Mapping

Gowin DPB requires 14-bit addresses. The module automatically zero-pads:
```systemverilog
dpb_addr = {{(14-ADDR_WIDTH){1'b0}}, ram_addr};
```

For SAMPLES_PER_BUF=256, ADDR_WIDTH=8, so addresses become `{6'b0, addr[7:0]}`.

### Reset Configuration

- `RESET_MODE = "SYNC"`: Synchronous reset
- Reset polarity: Active-HIGH (`RESETA(!rst_ni)`)
- Both ports reset independently

### Port Configuration

- **Port A (Write)**:
  - `WREA` driven by write enable
  - `DOA` unused (write-only port)

- **Port B (Read)**:
  - `WREB` tied to 0 (read-only port)
  - `DOB` provides read data with 1-cycle latency

### Data Width Support

The DPB `BIT_WIDTH_0` and `BIT_WIDTH_1` parameters are set to `DATA_WIDTH`. Gowin DPB supports:
- 1, 2, 4, 8, 9, 16, 18, 32, 36 bits per port

## Generic RAM Fallback

When `SYNTH_USE_GOWIN_DPB=0`, the module uses `generic_dpram` for simulation or FPGA-agnostic synthesis.

**Features**:
- Behavioral dual-port RAM
- Synchronous read/write
- 1-cycle read latency (matches DPB behavior)
- Portable across vendors and simulators

**Location**: `rtl/gen/generic_dpram.sv`

## Timing Considerations

### Write Path
- **Setup**: `in_valid_i` and `in_data_i` must be stable before clock edge
- **Hold**: Data written at rising clock edge
- **Address Update**: `write_addr` increments synchronously

### Read Path
- **Latency**: 1 clock cycle from `rd_addr_i` to `rd_data_o`
- **Enable**: `rd_en_i` gates the output valid signal
- **Address Change**: Can change `rd_addr_i` every cycle for streaming reads

### Buffer Toggle
- **Trigger**: Occurs when writing the 256th sample (address 255)
- **Timing**: Toggle happens synchronously at the next clock edge
- **Duration**: Instantaneous (no dead cycles)

## Performance

| Metric | Value |
|--------|-------|
| Maximum Sample Rate | = System Clock Frequency |
| Buffer Switch Overhead | 0 cycles (concurrent operation) |
| Read Latency | 1 clock cycle |
| Write Latency | 0 cycles (flow-through) |

## Assertions (Simulation Only)

The module includes SystemVerilog assertions for verification:

1. **Address Bounds**: `write_addr < SAMPLES_PER_BUF`
2. **Pulse Width**: `buf_ready_pulse_o` is exactly 1 cycle wide
3. **Write Exclusivity**: Only one buffer has write enable at a time
4. **Toggle Condition**: `active_buf_o` only toggles when buffer is full

Assertions are disabled for synthesis (`ifndef SYNTHESIS`).

## Resource Utilization (Gowin GW1NR-9)

For default configuration (256 samples × 16 bits):

| Resource | Usage | Notes |
|----------|-------|-------|
| DPB Blocks | 2 | One per buffer (A and B) |
| Logic Cells | ~50 | Control logic and muxing |
| Registers | ~20 | Address counters and status |

## Limitations and Future Enhancements

### Current Limitations
1. No overflow protection - writes continue even if downstream isn't reading
2. Fixed buffer size (no dynamic resizing)
3. No partial buffer readout before full

### Potential Enhancements
1. **Overflow Protection**: Add `DROP_WRITES_ON_TOGGLE` functional implementation
2. **Level Signals**: Add `buf_ready_level_o[1:0]` sticky flags
3. **Handshake**: Add `buf_release_i` for explicit downstream acknowledgment
4. **Configurable Threshold**: Trigger `buf_ready_pulse` before buffer is completely full

## Testing

### Testbenches Provided

1. **SystemVerilog Testbench** (`sim/double_buffer_ram_tb.sv`):
   - Self-checking comprehensive tests
   - Random write gaps
   - Concurrent read/write verification
   - Requires Icarus Verilog or compatible simulator

2. **Verilator C++ Testbench** (`sim/double_buffer_ram_tb_verilator.cpp`, `sim/double_buffer_ram_tb_simple.cpp`):
   - Fast compilation and execution
   - Detailed error reporting
   - Suitable for CI/CD integration

### Running Tests

```bash
# With Icarus Verilog
iverilog -g2012 -o sim_out \\
    rtl/gen/generic_dpram.sv \\
    rtl/double_buffer_ram.sv \\
    sim/double_buffer_ram_tb.sv
vvp sim_out

# With Verilator
verilator --cc --exe --build -Wall \\
    -GSYNTH_USE_GOWIN_DPB=0 \\
    rtl/gen/generic_dpram.sv \\
    rtl/double_buffer_ram.sv \\
    sim/double_buffer_ram_tb_verilator.cpp \\
    -o double_buffer_ram_tb
./obj_dir/double_buffer_ram_tb
```

## Revision History

| Version | Date | Description |
|---------|------|-------------|
| 1.0 | 2025-10 | Initial release with Gowin DPB support |

## References

- Gowin Semiconductor DPB (Dual-Port Block RAM) Documentation
- "Embedded Memory User Guide" - Gowin FPGA Design Resources

## Support

For issues, questions, or contributions, please refer to the project repository.

---

**Note**: This module is designed for continuous sampling applications such as software-defined radio (SDR), data acquisition systems, and real-time signal processing pipelines.
