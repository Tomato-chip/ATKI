# RAM Logic User Manual

## Overview

The `ram_logic.sv` module implements a ping-pong buffer RAM controller with dual-buffer architecture. It allows simultaneous write and read operations by alternating between two independent RAM buffers.

## Key Features

- **Dual-buffer architecture**: Write to one buffer while reading from another
- **Configurable parameters**: Data width and buffer depth
- **Independent interfaces**: Separate read and write handshaking
- **Automatic buffer swapping**: Buffers swap when write buffer fills
- **Overflow protection**: Detects and signals write attempts to full buffers
- **Ready/valid protocol**: Standard handshaking for both read and write

## Module Parameters

```systemverilog
module ram_logic #(
    parameter int unsigned WIDTH = 32,      // Data width in bits (8, 16, or 32 recommended)
    parameter int unsigned DEPTH = 256,     // Samples per buffer
    parameter int unsigned ADDR_WIDTH = $clog2(DEPTH)  // Auto-calculated
)
```

| Parameter | Description | Default | Notes |
|-----------|-------------|---------|-------|
| `WIDTH` | Data width in bits | 32 | Optimal values: 8, 16, 32 for Gowin SP RAM |
| `DEPTH` | Buffer depth (samples) | 256 | Total storage = 2 × DEPTH × WIDTH bits |
| `ADDR_WIDTH` | Address width | Auto | Calculated as ceil(log2(DEPTH)) |

## Interface Signals

### Clock and Reset
- `clk_i` - System clock (input)
- `rst_ni` - Active-low synchronous reset (input)

### Write Interface (Producer)
| Signal | Direction | Description |
|--------|-----------|-------------|
| `write_data_i[WIDTH-1:0]` | Input | Data to write |
| `write_valid_i` | Input | Write request (data valid) |
| `write_ready_o` | Output | Ready to accept write |

**Write Handshake**: Data is written when `write_valid_i && write_ready_o` are both high.

### Read Interface (Consumer)
| Signal | Direction | Description |
|--------|-----------|-------------|
| `read_data_o[WIDTH-1:0]` | Output | Read data |
| `read_ready_i` | Input | Reader ready for data |
| `read_valid_o` | Output | Read data is valid |

**Read Handshake**: Data is consumed when `read_ready_i && read_valid_o` are both high.

### Status and Control
| Signal | Direction | Description |
|--------|-----------|-------------|
| `buffer_ready_o` | Output | **Pulse**: Full buffer ready for reading |
| `buffer_overflow_o` | Output | **Pulse**: Error - write to full system |
| `write_count_o[ADDR_WIDTH:0]` | Output | Current write buffer fill level (0 to DEPTH) |
| `read_count_o[ADDR_WIDTH:0]` | Output | Current read buffer position (0 to DEPTH-1) |

## Operation

### Normal Operation Flow

1. **Initial State**
   - Write buffer (RAM0) is empty and ready to accept writes
   - Read buffer (RAM1) is empty and invalid
   - `write_ready_o = 1`, `read_valid_o = 0`

2. **Write Phase**
   - Producer writes data using valid/ready handshake
   - `write_count_o` increments with each accepted write
   - Continues until DEPTH samples are written

3. **Buffer Swap**
   - When `write_count == DEPTH`, buffers automatically swap
   - `buffer_ready_o` pulses high for one cycle
   - Write buffer switches to the other RAM
   - Read buffer becomes the just-filled RAM
   - Counters reset to zero

4. **Read Phase**
   - `read_valid_o` goes high, indicating data available
   - Consumer reads data using ready/valid handshake
   - `read_count_o` increments with each accepted read
   - Continues until DEPTH samples are read

5. **Continuous Operation**
   - Write and read operations are independent after first swap
   - Producer can fill the next buffer while consumer reads current buffer
   - Buffers alternate continuously

### Timing Diagram Example

```
Cycle:  0    1    2    3    4    5    ...  255  256  257  258
        |    |    |    |    |    |         |    |    |    |
write_valid: ___/‾‾‾‾\___/‾‾‾‾\___/‾‾‾‾\___/‾‾‾‾\___/‾‾‾‾\___/‾‾‾‾
write_ready: ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
write_count: 0    1    1    2    2    3              254  255  0    1
buffer_ready:____________________________________________________/‾\_____
read_valid:  _____________________________________________________/‾‾‾‾‾
```

## Usage Examples

### Example 1: Basic Integration

```systemverilog
// Instantiate with default parameters (32-bit, 256 depth)
ram_logic #(
    .WIDTH(32),
    .DEPTH(256)
) u_ram_buffer (
    .clk_i(clk),
    .rst_ni(rst_n),

    // Connect to data producer
    .write_data_i(producer_data),
    .write_valid_i(producer_valid),
    .write_ready_o(producer_ready),

    // Connect to data consumer
    .read_data_o(consumer_data),
    .read_ready_i(consumer_ready),
    .read_valid_o(consumer_valid),

    // Monitor status
    .buffer_ready_o(new_buffer_ready),
    .buffer_overflow_o(overflow_error),
    .write_count_o(write_fill_level),
    .read_count_o(read_position)
);
```

### Example 2: Producer Logic

```systemverilog
// Simple producer that writes data when available
always_ff @(posedge clk) begin
    if (have_data && ram_write_ready) begin
        ram_write_data <= next_sample;
        ram_write_valid <= 1'b1;
    end else begin
        ram_write_valid <= 1'b0;
    end
end
```

### Example 3: Consumer Logic

```systemverilog
// Simple consumer that processes one sample per cycle
always_ff @(posedge clk) begin
    if (ram_read_valid && processing_ready) begin
        process_sample(ram_read_data);
        ram_read_ready <= 1'b1;
    end else begin
        ram_read_ready <= 1'b0;
    end
end
```

### Example 4: Monitoring Buffer Ready

```systemverilog
// Detect new buffer availability
always_ff @(posedge clk) begin
    if (!rst_n) begin
        buffer_count <= 0;
    end else if (buffer_ready) begin
        buffer_count <= buffer_count + 1;
        $display("Buffer %0d ready at time %0t", buffer_count, $time);
    end
end
```

## Important Notes

### Buffer Swap Conditions
- Buffer swap occurs when `write_count == DEPTH` **AND** `!read_in_progress`
- If a read is in progress, swap waits until read completes
- This ensures data integrity during the transition

### Overflow Handling
- `buffer_overflow_o` pulses when writes occur to a full buffer
- This indicates the system cannot keep up with the data rate
- Consider:
  - Increasing buffer DEPTH
  - Slowing down the producer
  - Speeding up the consumer

### Read Valid Timing
- `read_valid_o` goes high after the first buffer swap
- Remains high during active read operations
- Goes low between buffer swaps and during reset

### Latency
- **Write latency**: 1 cycle (write appears in RAM next cycle)
- **Read latency**: 1 cycle in BYPASS mode (combinatorial output from RAM)
- **Buffer swap**: Occurs in 1 cycle

## Gowin SP RAM Integration

The module uses Gowin SP (Single Port) RAM primitives with specific configuration:

- **READ_MODE**: `1'b0` (BYPASS mode for low latency)
- **WRITE_MODE**: `2'b00` (NORMAL write mode)
- **Address packing**: Addresses are packed into 14-bit format with appropriate padding based on WIDTH

### Address Format
The `pack_address()` function formats addresses for Gowin RAM:
- **32-bit data**: `{1'b0, addr, 5'b00000}` - Uses 32-bit word mode
- **16-bit data**: `{2'b00, addr, 4'b0000}` - Uses 16-bit word mode
- **8-bit data**: `{1'b0, addr, 5'b00000}` - Uses 8-bit byte mode

## Reset Behavior

On `rst_ni` assertion (active low):
- All counters reset to zero
- Write buffer selects RAM0
- Read buffer selects RAM1 (initially invalid)
- `read_valid_o` = 0 (no data available)
- `buffer_ready_o` = 0
- `read_in_progress` = 0

## Assertions and Debug

The module includes synthesis-ignored assertions for debugging:
- Detects writes to full buffers
- Validates DEPTH > 0
- Warns if WIDTH is not optimal (recommends 8, 16, or 32)

These assertions are only active during simulation and are removed during synthesis.

## Performance

### Throughput
- **Write**: Up to 1 sample per clock cycle (when `write_ready_o` is high)
- **Read**: Up to 1 sample per clock cycle (when `read_valid_o` is high)
- **Continuous**: Can sustain simultaneous 1 sample/cycle write and read after initial fill

### Storage
- **Total capacity**: 2 × DEPTH × WIDTH bits
- **Effective capacity**: DEPTH samples (one buffer is always reserved)

### Typical Configuration Examples
| WIDTH | DEPTH | Total Storage | Use Case |
|-------|-------|---------------|----------|
| 32 | 256 | 16 Kbits | Audio samples, DSP buffers |
| 16 | 512 | 16 Kbits | Sensor data streaming |
| 8 | 1024 | 16 Kbits | UART/serial buffers |

## Troubleshooting

### Problem: `buffer_overflow_o` pulsing
- **Cause**: Producer writing faster than consumer reading
- **Solutions**:
  - Increase DEPTH parameter
  - Add backpressure to producer (respect `write_ready_o`)
  - Speed up consumer processing

### Problem: `read_valid_o` never goes high
- **Cause**: First buffer hasn't filled yet
- **Solution**: Wait for first `buffer_ready_o` pulse (requires DEPTH writes)

### Problem: Data appears corrupted
- **Cause**: Reading while buffer is being written
- **Solution**: Module handles this automatically - verify buffer selection logic

### Problem: Read/write handshake issues
- **Check**: Verify valid/ready signals follow proper handshake protocol
- **Remember**: Transaction occurs only when both valid and ready are high

## Version and Compatibility

- **Language**: SystemVerilog (IEEE 1800-2017)
- **Target**: Gowin FPGAs with SP RAM primitives
- **Simulation**: Compatible with Verilator, Icarus Verilog, and commercial simulators
- **Synthesis**: Tested with Yosys (requires sv2v conversion)
