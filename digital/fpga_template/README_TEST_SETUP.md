# RAM Test Setup with Analog Discovery 2

## Overview
This test setup generates an internal 1 kHz sine wave, feeds it through the I2S capture and RAM buffer system, and provides parallel readout for verification with the Analog Discovery 2.

## Files Created

1. **`i2s_sine_generator.sv`** - Generates I2S-compatible PCM sine wave
   - 1 kHz test tone at 48 kHz sample rate
   - 24-bit signed PCM output
   - Produces SCK, WS, and SD signals

2. **`fpga_test_sine_readout.sv`** - Top-level test wrapper
   - Integrates sine generator with I2S capture and RAM buffer
   - Provides parallel readout interface
   - Keeps VU meter for visual feedback

3. **`tangnano20k_test_readout.cst`** - Pin constraints for test design
   - Maps RAM readout signals to Tang Nano 20K GPIO pins
   - Optimized for Analog Discovery 2 connection

## Quick Start

### 1. Build the Design

Use the Gowin IDE to synthesize and program the FPGA:
```bash
# Use fpga_test_sine_readout as the top module
# Use tangnano20k_test_readout.cst as constraints
```

### 2. Connect Analog Discovery 2

**Priority Connection (Minimum 8 channels):**
```
DIO 0  → Pin 26  : ram_buffer_ready (TRIGGER ON THIS!)
DIO 1  → Pin 25  : ram_read_valid
DIO 2  → Pin 52  : ram_data_out[0]  (LSB)
DIO 3  → Pin 53  : ram_data_out[1]
DIO 4  → Pin 54  : ram_data_out[2]
DIO 5  → Pin 56  : ram_data_out[3]
DIO 6  → Pin 57  : ram_data_out[4]
DIO 7  → Pin 68  : ram_data_out[5]
GND    → GND     : Common ground
```

**Extended Connection (All 16 channels):**
```
DIO 0  → Pin 26  : ram_buffer_ready
DIO 1  → Pin 25  : ram_read_valid
DIO 2  → Pin 52  : ram_data_out[0]
DIO 3  → Pin 53  : ram_data_out[1]
DIO 4  → Pin 54  : ram_data_out[2]
DIO 5  → Pin 56  : ram_data_out[3]
DIO 6  → Pin 57  : ram_data_out[4]
DIO 7  → Pin 68  : ram_data_out[5]
DIO 8  → Pin 69  : ram_data_out[6]
DIO 9  → Pin 70  : ram_data_out[7]
DIO 10 → Pin 71  : ram_data_out[8]
DIO 11 → Pin 72  : ram_data_out[9]
DIO 12 → Pin 73  : ram_data_out[10]
DIO 13 → Pin 74  : ram_data_out[11]
DIO 14 → Pin 79  : ram_data_out[12]
DIO 15 → Pin 80  : ram_data_out[13]
```

**Alternative: Monitor System Status**
```
DIO 0  → Pin 26  : ram_buffer_ready (trigger)
DIO 1  → Pin 25  : ram_read_valid
DIO 2  → Pin 27  : ram_write_count[0]
DIO 3  → Pin 28  : ram_write_count[1]
DIO 4  → Pin 29  : ram_write_count[2]
DIO 5  → Pin 30  : ram_write_count[3]
DIO 6  → Pin 31  : ram_write_count[4]
DIO 7  → Pin 32  : ram_write_count[5]
DIO 8  → Pin 33  : ram_write_count[6]
DIO 9  → Pin 34  : ram_write_count[7]
DIO 10 → Pin 35  : ram_write_count[8]
```

### 3. WaveForms Configuration

#### Logic Analyzer Setup
1. Open **Digilent WaveForms**
2. Select **Logic** tool
3. Configure channels:
   - **DIO 0**: Label "buffer_ready", **USE AS TRIGGER**
   - **DIO 1**: Label "read_valid"
   - **DIO 2-9**: Group as "data[7:0]" (or extend to data[15:0])

#### Trigger Settings
```
Trigger Type: Simple
Trigger Channel: DIO 0 (buffer_ready)
Condition: Rising Edge
Pre-trigger: 10% (capture mostly after trigger)
```

#### Sampling Settings
```
Sample Rate: 100 MS/s (captures 27 MHz clock accurately)
Buffer Size: Maximum (100M samples if available)
```

#### Data Export
After capture:
1. Go to **View → Protocol → UART/SPI/I2C** (or custom)
2. Select channels DIO 2-9 as data bus
3. Export as CSV: **File → Export → Data**

### 4. What to Expect

**On FPGA:**
- LEDs will show VU meter activity (default)
- Press **btn_s2** to switch to RAM debug LEDs
- **buffer_full** signal pulses every 256 samples (~5.3 ms at 48 kHz)

**On Logic Analyzer:**
- **ram_buffer_ready** pulses once every 256 samples (buffer swap)
- **ram_read_valid** stays high while reading buffer (256 reads)
- **ram_data_out** shows 18-bit audio samples changing on each read
- Data should show a smooth sine wave pattern

**Expected Data Pattern:**
- 1 kHz sine at 48 kHz sample rate = 48 samples per cycle
- Each buffer (256 samples) contains ~5.3 cycles of sine wave
- 18-bit values range from 0x00000 to 0x3FFFF (signed)
- Should see smooth progression: 0 → +max → 0 → -max → 0

## Verification Steps

### Test 1: Basic Operation
1. Trigger on `ram_buffer_ready` rising edge
2. Verify `ram_read_valid` goes high after trigger
3. Count 256 transitions on `ram_data_out`
4. Verify `ram_read_valid` goes low after 256 reads

### Test 2: Data Integrity
1. Capture one complete buffer (256 samples)
2. Export data to CSV
3. Plot in spreadsheet or Python
4. Verify sine wave shape at 1 kHz

### Test 3: Continuous Operation
1. Set long capture (1 second = ~94 buffer swaps)
2. Verify regular `ram_buffer_ready` pulses
3. Check for any overflow or error conditions
4. Verify continuous data flow

## Python Analysis Script

```python
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Load CSV from WaveForms export
data = pd.read_csv('logic_capture.csv')

# Extract data bus (assuming columns 'DIO2' through 'DIO9')
samples = []
for i, row in data.iterrows():
    if row['DIO1'] == 1:  # read_valid high
        value = sum(row[f'DIO{j}'] << (j-2) for j in range(2, 10))
        # Convert to signed 18-bit
        if value >= 2**17:
            value -= 2**18
        samples.append(value)

# Plot
plt.figure(figsize=(12, 6))
plt.plot(samples[:256])  # One buffer
plt.title('RAM Data Output - 1 kHz Sine Wave')
plt.xlabel('Sample Number')
plt.ylabel('Amplitude (18-bit)')
plt.grid(True)
plt.show()

# FFT Analysis
fft = np.fft.fft(samples[:256])
freqs = np.fft.fftfreq(256, 1/48000)
plt.figure(figsize=(12, 6))
plt.plot(freqs[:128], np.abs(fft[:128]))
plt.title('FFT - Should show peak at 1 kHz')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude')
plt.grid(True)
plt.show()
```

## Troubleshooting

### No data on Analog Discovery
- Check ground connection
- Verify FPGA is programmed and running
- Check that btn_s1 is not pressed (not in reset)
- Measure voltage on data pins (should toggle 0-3.3V)

### Buffer ready never pulses
- Check that sine generator is running
- Verify I2S capture is receiving data
- Check debug LEDs for activity

### Data looks random
- Increase sample rate to 100 MS/s
- Verify trigger is set correctly
- Check that you're capturing `ram_data_out`, not other signals

### Sine wave has wrong frequency
- Verify 64 samples per cycle (should be ~48 samples at 1 kHz)
- Check that sample rate is 48 kHz (measure time between buffer_ready pulses)
- If needed, adjust SINE_FREQ parameter in i2s_sine_generator.sv

## Pin Reference

### Tang Nano 20K GPIO Header Pinout
Refer to Tang Nano 20K schematic for physical pin locations.

**Key pins used:**
- **Pins 25-26**: Control signals (easy access on header)
- **Pins 27-35**: Counter outputs (grouped together)
- **Pins 52-84**: Data outputs (spread across available GPIO)

## Next Steps

After successful capture:
1. **Modify sine frequency**: Change `SINE_FREQ` parameter in sine generator
2. **Capture both channels**: Expand readout to include bits [17:0] and [35:18]
3. **Test with different waveforms**: Modify sine generator to output square/triangle waves
4. **Verify data integrity**: Compare captured data against expected values
5. **Test overflow conditions**: Artificially slow down read_ready to trigger overflow

## Additional Files Needed

You still need these existing files from your project:
- `i2s_capture_24_test.sv` (I2S capture module)
- `ram_logic_test.sv` (RAM ping-pong buffer)
- `vu_meter_6led_test.sv` (VU meter)
- `i2s_clock_gen.sv` (if using external I2S clock gen)

Make sure all dependencies are in the project.
