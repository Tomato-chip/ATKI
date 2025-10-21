# Microphone Sampler Module

## Overview

The `sampler` module is a parameterized microphone sampling interface that captures parallel microphone data and stores it in ping-pong (double-buffer) RAM. It provides a scalable architecture for multi-microphone systems while currently implementing single-microphone operation.

**Current Status:**
- 1 active microphone channel (channel 0)
- Channels 1-6 stubbed for future expansion
- Scalable to 7 microphones via generate block (template included)

**Key Features:**
- Parallel microphone sample bus
- Per-channel double-buffer RAM integration
- Automatic buffer switching
- Channel-aware buffer completion signaling
- Configurable data width and buffer depth
- Active-low synchronous reset

## Architecture

```
                        +------------------+
  mic_data_i[0..6] ---->|                  |
  mic_valid_i --------->|  Sampler Control |
                        |                  |
                        +------------------+
                                 |
                +----------------+----------------+
                |                |                |
           +----v----+      +----v----+      +----v----+
           | Channel | ...  | Channel | ...  | Channel |
           |    0    |      |    1    |      |    6    |
           | (Active)|      | (Stub)  |      | (Stub)  |
           +----+----+      +----+----+      +----+----+
                |                |                |
           +----v----+      +----v----+      +----v----+
           | Double  |      | Double  |      | Double  |
           | Buffer  |      | Buffer  |      | Buffer  |
           | RAM 0   |      | RAM 1   |      | RAM 6   |
           +---------+      +---------+      +---------+
                |                |                |
                +----------------+----------------+
                                 |
                        +--------v---------+
                        | OR-Reduction &   |
                        | Priority Encoder |
                        +------------------+
                                 |
                    +------------+------------+
                    |                         |
          buf_ready_pulse_o          buf_ready_ch_o
```

## Current Implementation (N_MICS=1)

### Signal Flow

1. **Microphone Input**: `mic_data_i[0]` sampled on `mic_valid_i` strobe
2. **Buffer Storage**: Samples written to active buffer (A or B) via `double_buffer_ram`
3. **Address Management**: Internal write address auto-increments (0 to SAMPLES_PER_BUF-1)
4. **Buffer Toggle**: At SAMPLES_PER_BUF samples, buffer toggles and `buf_ready_pulse_o` asserts for 1 cycle
5. **Status Output**: `buf_ready_ch_o` indicates channel 0 completed

### Timing Diagram

```
Clock:       __|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_
mic_valid:   ______|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|____________
mic_data[0]: ------< S0 >< S1 >< S2 >...< S255 >--------------
active_buf:  ______A_____________________________B____________
buf_ready:   ___________________________________|‾|____________
buf_ch:      -----------------------------------< 0 >----------
                                          ^ Buffer A complete
```

## Interface

### Parameters

| Parameter | Default | Description |
|-----------|---------|-------------|
| `N_MICS` | 1 | Number of microphone channels (1-7) |
| `DATA_WIDTH` | 16 | Sample width in bits (8-32) |
| `SAMPLES_PER_BUF` | 256 | Samples per buffer (≥2) |
| `ADDR_WIDTH` | `$clog2(SAMPLES_PER_BUF)` | Auto-calculated address width |
| `USE_GOWIN_DPB` | 1 | 1=Gowin DPB, 0=Generic RAM |

### Ports

#### Clock and Reset
- `clk_i` (input): System clock
- `rst_ni` (input): Active-low synchronous reset

#### Microphone Input
- `mic_data_i[N_MICS][DATA_WIDTH-1:0]` (input): Parallel sample bus (one per mic)
- `mic_valid_i` (input): Single strobe aligned for all microphones

#### Status and Control
- `buf_ready_pulse_o` (output): 1-cycle pulse when any channel's buffer completes
- `buf_ready_ch_o[log2(N_MICS)-1:0]` (output): Which channel triggered the pulse
- `active_buf_o` (output): Current write buffer (0=A, 1=B)

## Integration with double_buffer_ram

Each microphone channel instantiates one `double_buffer_ram` module:

```systemverilog
double_buffer_ram #(
    .DATA_WIDTH           (DATA_WIDTH),
    .SAMPLES_PER_BUF      (SAMPLES_PER_BUF),
    .ADDR_WIDTH           (ADDR_WIDTH),
    .SYNTH_USE_GOWIN_DPB  (USE_GOWIN_DPB),
    .DROP_WRITES_ON_TOGGLE(1'b1)
) channel_0_buffer (
    .clk_i              (clk_i),
    .rst_ni             (rst_ni),
    .in_valid_i         (mic_valid_i),      // Common strobe
    .in_data_i          (mic_data_i[0]),    // Channel 0 data
    .in_ready_o         (),                  // Not used
    .rd_addr_i          (rd_addr[0]),        // Future processor access
    .rd_en_i            (rd_en[0]),
    .rd_data_o          (rd_data[0]),
    .rd_data_valid_o    (rd_data_valid[0]),
    .active_buf_o       (ch_active_buf[0]),
    .buf_ready_pulse_o  (ch_buf_ready_pulse[0]),
    .buf_ready_id_o     ()                   // Not used (single buffer per ch)
);
```

### Key Connections

- **Common Strobe**: All channels share `mic_valid_i` for synchronous sampling
- **Per-Channel Data**: Each channel has dedicated `mic_data_i[ch]` input
- **Per-Channel Storage**: Independent double-buffer RAM per channel
- **Aggregated Status**: OR-reduction of all `buf_ready_pulse` signals

## Scaling to Multiple Microphones (7 Channels)

To enable all 7 microphone channels, uncomment the generate block in `rtl/sampler.sv`:

### Generate Block Template

```systemverilog
generate
    for (genvar ch = 1; ch < N_MICS; ch++) begin : gen_mic_channels
        double_buffer_ram #(
            .DATA_WIDTH           (DATA_WIDTH),
            .SAMPLES_PER_BUF      (SAMPLES_PER_BUF),
            .ADDR_WIDTH           (ADDR_WIDTH),
            .SYNTH_USE_GOWIN_DPB  (USE_GOWIN_DPB),
            .DROP_WRITES_ON_TOGGLE(1'b1)
        ) channel_buffer (
            .clk_i              (clk_i),
            .rst_ni             (rst_ni),
            .in_valid_i         (mic_valid_i),
            .in_data_i          (mic_data_i[ch]),
            .in_ready_o         (),
            .rd_addr_i          (rd_addr[ch]),
            .rd_en_i            (rd_en[ch]),
            .rd_data_o          (rd_data[ch]),
            .rd_data_valid_o    (rd_data_valid[ch]),
            .active_buf_o       (ch_active_buf[ch]),
            .buf_ready_pulse_o  (ch_buf_ready_pulse[ch]),
            .buf_ready_id_o     ()
        );

        assign rd_addr[ch] = '0;
        assign rd_en[ch]   = 1'b0;
    end
endgenerate
```

### Output Aggregation

**Buffer Ready Pulse (OR-Reduction):**
```systemverilog
always_comb begin
    buf_ready_pulse_o = 1'b0;
    for (int i = 0; i < N_MICS; i++) begin
        buf_ready_pulse_o |= ch_buf_ready_pulse[i];
    end
end
```

**Channel ID (Priority Encoder):**
```systemverilog
always_comb begin
    buf_ready_ch_o = '0;
    for (int i = 0; i < N_MICS; i++) begin
        if (ch_buf_ready_pulse[i]) begin
            buf_ready_ch_o = i[$clog2(N_MICS>1?N_MICS:2)-1:0];
            break;  // Lowest channel has priority
        end
    end
end
```

### Resource Scaling

For N_MICS=7, DATA_WIDTH=16, SAMPLES_PER_BUF=256:

| Resource | Per Channel | Total (7 channels) |
|----------|-------------|-------------------|
| DPB Blocks | 2 | 14 |
| Logic Cells | ~50 | ~350 + control |
| Registers | ~20 | ~140 + control |
| Memory | 8 Kbits | 56 Kbits |

## Operation

### Normal Operation

1. **Reset**: Assert `rst_ni=0` for at least 5 cycles
   - All write addresses reset to 0
   - Active buffer set to A (active_buf_o=0)
   - Buffer ready flags cleared

2. **Sampling**: For each microphone sample:
   - Present data on `mic_data_i[0..N_MICS-1]`
   - Assert `mic_valid_i` for 1 clock cycle
   - Sample written to current address in active buffer
   - Write address auto-increments

3. **Buffer Completion**: After SAMPLES_PER_BUF samples:
   - Active buffer toggles (A→B or B→A)
   - `buf_ready_pulse_o` asserts for exactly 1 cycle
   - `buf_ready_ch_o` indicates which channel completed
   - Write address resets to 0
   - Completed buffer available for read via processor

4. **Continuous Operation**: Sampling continues in new buffer
   - Processor can read completed buffer concurrently
   - No sample loss during buffer switch

### Synchronous Reset Behavior

Active-low synchronous reset (`rst_ni=0`):
- Write addresses → 0
- Active buffer → A
- Buffer ready pulses → 0
- Internal state cleared on clock edge

**Important**: Hold `rst_ni=0` for minimum 5 clock cycles for proper initialization.

## Read Access (Future Processor Interface)

Each channel exposes read signals for processor access:

```systemverilog
logic [ADDR_WIDTH-1:0]  rd_addr [N_MICS];   // Read address per channel
logic [N_MICS-1:0]      rd_en;              // Read enable per channel
logic [DATA_WIDTH-1:0]  rd_data [N_MICS];   // Read data per channel
logic [N_MICS-1:0]      rd_data_valid;      // Read valid per channel
```

**Read Latency**: 1 clock cycle (Gowin DPB synchronous read)

**Concurrent Access**: Read from inactive buffer while writing to active buffer

## Timing Considerations

### Setup and Hold
- `mic_data_i` must be stable before rising edge of `clk_i` when `mic_valid_i=1`
- `mic_valid_i` acts as a synchronous write enable

### Buffer Switch Timing
- Toggle occurs synchronously at clock edge when sample 255 is written
- No dead cycles - next sample (0) can be written immediately

### Critical Paths
- Priority encoder for `buf_ready_ch_o` (combinational)
- OR-reduction for `buf_ready_pulse_o` (combinational)
- Write address increment (sequential)

## Usage Example

### Single Microphone System

```systemverilog
sampler #(
    .N_MICS          (1),
    .DATA_WIDTH      (16),
    .SAMPLES_PER_BUF (256),
    .USE_GOWIN_DPB   (1'b1)  // Use Gowin primitives
) mic_sampler (
    .clk_i              (clk_27mhz),
    .rst_ni             (rst_n),

    // Microphone interface
    .mic_data_i         ('{pdm_data}),      // Array literal for single mic
    .mic_valid_i        (pdm_valid),

    // Status
    .buf_ready_pulse_o  (buffer_full),
    .buf_ready_ch_o     (),                  // Not needed for single channel
    .active_buf_o       (current_buffer)
);

// Processor triggered by buffer completion
always_ff @(posedge clk_27mhz) begin
    if (buffer_full) begin
        start_fft <= 1'b1;
        // Process completed buffer while next buffer fills
    end
end
```

### Multi-Microphone System (Future)

```systemverilog
logic [15:0] mic_samples [7];  // 7 microphones

sampler #(
    .N_MICS          (7),
    .DATA_WIDTH      (16),
    .SAMPLES_PER_BUF (256),
    .USE_GOWIN_DPB   (1'b1)
) mic_array_sampler (
    .clk_i              (clk_27mhz),
    .rst_ni             (rst_n),
    .mic_data_i         (mic_samples),
    .mic_valid_i        (all_mics_ready),
    .buf_ready_pulse_o  (any_buffer_full),
    .buf_ready_ch_o     (completed_channel),
    .active_buf_o       (current_buffer)
);

// Handle channel-specific completion
always_ff @(posedge clk_27mhz) begin
    if (any_buffer_full) begin
        case (completed_channel)
            3'd0: process_mic_0();
            3'd1: process_mic_1();
            // ... etc
        endcase
    end
end
```

## Testing

### Testbenches Provided

1. **SystemVerilog Testbench** (`sim/sampler_tb.sv`):
   - Comprehensive self-checking tests
   - Golden buffer verification
   - Concurrent read/write testing
   - Buffer completion verification
   - Requires forcing internal signals for read access

2. **Verilator C++ Testbench** (`sim/sampler_tb_verilator.cpp`):
   - Fast compilation and execution
   - 5 independent test phases
   - Single-cycle pulse verification
   - Channel ID verification
   - PASS/FAIL reporting

### Running Tests

```bash
# With Verilator (recommended)
verilator --cc --exe --build -Wall \\
    -GUSE_GOWIN_DPB=0 \\
    --top-module sampler \\
    rtl/gen/generic_dpram.sv \\
    rtl/double_buffer_ram.sv \\
    rtl/sampler.sv \\
    sim/sampler_tb_verilator.cpp \\
    -o sampler_tb
./obj_dir/sampler_tb

# Expected output:
# SAMPLER: PASS
# All tests passed successfully!
```

### Test Coverage

- ✓ Reset and initialization
- ✓ Buffer A filling (256 samples)
- ✓ Buffer B filling (256 samples)
- ✓ Single-cycle pulse width
- ✓ Channel ID correctness
- ✓ Buffer toggle timing
- ✓ Active buffer tracking

## Assertions

The module includes SystemVerilog assertions for simulation verification:

1. **Single-Cycle Pulse**: `buf_ready_pulse_o` must be exactly 1 cycle wide
2. **Valid Channel ID**: `buf_ready_ch_o` must be < N_MICS
3. **Data Integrity**: No X/Z propagation during `mic_valid_i`

Assertions are disabled for synthesis (`ifndef SYNTHESIS`).

## Future Enhancements

### Planned Features

1. **Multi-Microphone Support**: Uncomment generate block for channels 1-6
2. **Sticky Buffer Flags**: `buf_ready_level_o[N_MICS]` with `buf_release_i[N_MICS]` handshake
3. **Back-Pressure**: `in_ready_o` output for flow control
4. **Configurable Priority**: Modify priority encoder for round-robin arbitration
5. **Overflow Protection**: Detect and flag buffer overrun conditions

### Scalability Considerations

- **Synchronization**: Ensure all microphones sample simultaneously via common `mic_valid_i`
- **Timing Closure**: Priority encoder may need pipelining for N_MICS>4
- **Memory Bandwidth**: Gowin DPB has limited instances; consider external SDRAM for >7 channels

## Performance

| Metric | Value |
|--------|-------|
| Maximum Sample Rate | = System Clock Frequency |
| Buffer Switch Latency | 0 cycles (concurrent operation) |
| Channel Identification Latency | 0 cycles (combinational) |
| Read Latency | 1 cycle (synchronous DPB) |

## Limitations

1. **Current Implementation**: Only channel 0 is active; channels 1-6 are stubbed
2. **Synchronous Sampling**: All channels must sample simultaneously (common strobe)
3. **Fixed Buffer Size**: No runtime buffer size adjustment
4. **No FIFO**: Direct connection to double-buffer; upstream must respect timing

## Related Documentation

- [double_buffer_ram.md](double_buffer_ram.md) - Double-buffer RAM controller details
- Gowin Semiconductor DPB (Dual-Port Block RAM) User Guide
- Application Note: Multi-Microphone Array Processing

## Revision History

| Version | Date | Description |
|---------|------|-------------|
| 1.0 | 2025-10 | Initial release with single-mic support |

---

**Note**: This module is designed for beamforming microphone arrays, acoustic localization systems, and multi-channel audio capture applications.
