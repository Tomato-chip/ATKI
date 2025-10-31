# GTKWave Signal Viewing Guide

## Quick Start

Open the waveform:
```bash
cd /home/tomato-chip/ATKI/digital/Project_files
gtkwave fpga_template_top_tb.vcd &
```

---

## Recommended Signal Groups

### 📌 **Group 1: Top-Level System Signals**

Add these signals from `TOP.fpga_template_top_tb.dut`:

| Signal | Description | What to Look For |
|--------|-------------|------------------|
| `clk` | System clock (27 MHz) | Main timing reference |
| `resetb` | Active-high reset | Should go HIGH after ~370ns |
| `debug_led[5:0]` | VU meter LED output | Binary display, changes ~50Hz |
| `buffer_full` | Overflow indicator | Should stay LOW (no errors) |

**Display Format:**
- `clk` → Digital
- `debug_led[5:0]` → Binary or Hex
- `buffer_full` → Digital (Highlight RED if HIGH)

---

### 📌 **Group 2: I2S Interface (Clock & Data)**

Add from `TOP.fpga_template_top_tb.dut.u_i2s_clock`:

| Signal | Description | What to Look For |
|--------|-------------|------------------|
| `sck_o` | I2S serial clock | ~3.375 MHz, toggles every 8 system clocks |
| `ws_o` | Word select (L/R) | Toggles every 32 SCK cycles |

Add from `TOP.fpga_template_top_tb.dut`:

| Signal | Description | What to Look For |
|--------|-------------|------------------|
| `mic_sd_0` | I2S data from mic | Serial bit stream, changes on SCK rising |

**Display Format:** All Digital

**Key Timing:**
- SCK period: ~296ns (8 × 37ns)
- WS period: ~18.96µs (32 × SCK period)
- Sample rate: ~52.7 kHz

---

### 📌 **Group 3: I2S Capture Module**

Add from `TOP.fpga_template_top_tb.dut.u_sampler`:

| Signal | Description | What to Look For |
|--------|-------------|------------------|
| `left_o[23:0]` | Captured left channel | 24-bit signed audio sample |
| `right_o[23:0]` | Captured right channel | 24-bit signed audio sample |
| `ready_o` | Sample ready pulse | 1-cycle pulse when L+R ready |
| `cnt_q[5:0]` | Bit counter | Counts 0→25 during capture |
| `shift25_q[24:0]` | Shift register | Watch bits shift in MSB-first |

**Display Format:**
- `left_o`, `right_o` → Hex or Signed Decimal
- `ready_o` → Digital (Highlight YELLOW on HIGH)
- `cnt_q` → Decimal
- `shift25_q` → Hex

**What to Observe:**
- `cnt_q` counts 0→25 during each half-frame
- `ready_o` pulses once per complete L+R frame (~19µs apart)
- Left/right samples update on `ready_o` pulse

---

### 📌 **Group 4: RAM Logic - Write Path**

Add from `TOP.fpga_template_top_tb.dut.u_ram`:

| Signal | Description | What to Look For |
|--------|-------------|------------------|
| `write_data_i[31:0]` | Data to write | {8'b0, left_sample[23:0]} |
| `write_valid_i` | Write request | Pulses from I2S ready_o |
| `write_ready_o` | Ready to accept | Should always be HIGH |
| `write_accepted` | Handshake success | valid && ready |
| `write_count[8:0]` | Buffer fill level | Counts 0→16 (DEPTH=16) |
| `write_address[3:0]` | Write pointer | Increments 0→15, wraps |
| `write_buffer_sel` | Active write buffer | 0=RAM0, 1=RAM1 |

**Display Format:**
- `write_data_i` → Hex
- `write_count` → Decimal (Analog view helpful)
- `write_address` → Decimal
- Other signals → Digital

**What to Observe:**
- `write_count` increments to 16, then resets to 0
- `write_buffer_sel` toggles when count reaches 16
- **Buffer swap happens when `write_count == 16`**

---

### 📌 **Group 5: RAM Logic - Read Path**

Add from `TOP.fpga_template_top_tb.dut.u_ram`:

| Signal | Description | What to Look For |
|--------|-------------|------------------|
| `read_data_o[31:0]` | Data from RAM | Audio samples |
| `read_valid_o` | Data valid | HIGH in circular mode |
| `read_ready_i` | Consumer ready | From VU meter |
| `read_accepted` | Read handshake | valid && ready |
| `read_count[8:0]` | Read position | 0→15, wraps in circular mode |
| `read_address[3:0]` | Read pointer | Wraps at 15→0 |
| `read_buffer_sel` | Active read buffer | 0=RAM0, 1=RAM1 |

**Display Format:**
- `read_data_o` → Hex
- `read_count` → Decimal (Analog view helpful)
- `read_address` → Decimal

**What to Observe:**
- After first buffer swap, `read_valid_o` goes HIGH and stays HIGH
- `read_count` wraps 0→15→0 continuously (circular buffer)
- `read_buffer_sel` lags `write_buffer_sel` by one swap

---

### 📌 **Group 6: RAM Logic - Control Signals**

Add from `TOP.fpga_template_top_tb.dut.u_ram`:

| Signal | Description | What to Look For |
|--------|-------------|------------------|
| `buffer_ready_o` | Buffer swap pulse | 1-cycle pulse at swap |
| `buffer_overflow_o` | Error flag | Should stay LOW |
| `read_buffer_valid` | Read buffer has data | Goes HIGH after first swap |
| `read_in_progress` | Read phase active | Goes HIGH after first swap |
| `write_buffer_full` | Write buffer full | HIGH when count==16 |

**Display Format:** All Digital
- `buffer_ready_o` → Highlight GREEN on HIGH
- `buffer_overflow_o` → Highlight RED on HIGH

**What to Observe:**
- `buffer_ready_o` pulses exactly when `write_count` reaches 16
- Should see 2 pulses for 16-sample test (at samples 8 and 16)

---

### 📌 **Group 7: VU Meter - Handshake Timing** ⭐ **CRITICAL FOR DEBUGGING**

Add from `TOP.fpga_template_top_tb.dut.vu`:

| Signal | Description | What to Look For |
|--------|-------------|------------------|
| `ram_read_data_i[23:0]` | Sample from RAM | Audio data input |
| `ram_read_valid_i` | RAM has data | From ram_logic |
| `ram_read_ready_o` | VU ready to accept | Should be LOW for 2 cycles after handshake |
| `ram_ready_q` | Internal ready reg | State machine tracking |
| `sample_valid` | Handshake occurred | valid && ready |
| `processing_delay_q` | Delay state flag | THE FIX - should be HIGH for 1 cycle |

**Display Format:**
- `ram_read_data_i` → Hex or Signed Decimal

**⭐ CRITICAL TIMING TO VERIFY:**

**Expected Handshake Pattern:**
```
Cycle N:   sample_valid=1, ram_ready_q=1, processing_delay_q=0  ← Handshake
Cycle N+1: sample_valid=0, ram_ready_q=0, processing_delay_q=1  ← Processing 1
Cycle N+2: sample_valid=0, ram_ready_q=0, processing_delay_q=0  ← Processing 2
Cycle N+3: sample_valid=0, ram_ready_q=1, processing_delay_q=0  ← Ready again
```

**What to Verify:**
- `ram_ready_q` stays LOW for exactly 2 cycles after `sample_valid` HIGH
- `processing_delay_q` is HIGH for exactly 1 cycle
- Handshakes occur every 3 clock cycles (~111ns apart)

---

### 📌 **Group 8: VU Meter - Level Computation**

Add from `TOP.fpga_template_top_tb.dut.vu`:

| Signal | Description | What to Look For |
|--------|-------------|------------------|
| `sample[23:0]` | Input sample | From RAM via mux |
| `mag[23:0]` | Absolute value | Unsigned magnitude |
| `level_q[31:0]` | Computed level | Leaky integrator output |
| `leds_o[5:0]` | LED output | VU meter display |

**Display Format:**
- `level_q` → Analog (great for visualization!)
- `leds_o` → Binary

**What to Observe:**
- `level_q` gradually increases as samples arrive
- `leds_o` updates at ~50 Hz (every 540,000 clocks)
- Higher audio values → higher `level_q` → more LEDs

---

### 📌 **Group 9: RAM Physical Access**

Add from `TOP.fpga_template_top_tb.dut.u_ram`:

| Signal | Description | What to Look For |
|--------|-------------|------------------|
| `ram0_address[13:0]` | RAM0 address bus | Packed address format |
| `ram1_address[13:0]` | RAM1 address bus | Packed address format |
| `ram0_write_enable` | RAM0 write strobe | Active when writing to RAM0 |
| `ram1_write_enable` | RAM1 write strobe | Active when writing to RAM1 |

**What to Observe:**
- Only one RAM has write_enable active at a time
- Address multiplexing: write uses one RAM, read uses the other

---

## 🎯 Zoom Levels for Different Views

### 1. **Overview - Full Simulation**
- **Zoom:** Fit entire waveform (View → Zoom → Zoom Fit)
- **Focus:**
  - `buffer_ready_o` pulses (should see 2)
  - `write_count` ramping 0→16 twice
  - `debug_led` slow changes

### 2. **Buffer Swap Event** ⭐ **RECOMMENDED VIEW**
- **Zoom:** ±5µs around `buffer_ready_o` pulse
- **Focus:**
  - `write_count` reaching 16
  - `write_buffer_sel` and `read_buffer_sel` toggling
  - `read_valid_o` going HIGH
  - State transitions

**How to find:** Search for `buffer_ready_o` rising edge (Edit → Search Signal → Rising Edge)

### 3. **VU Meter Handshake Detail** ⭐ **CRITICAL**
- **Zoom:** 3-5 clock cycles (~111-185ns)
- **Focus:**
  - `sample_valid` pulse
  - `ram_ready_q` LOW for 2 cycles
  - `processing_delay_q` HIGH for 1 cycle

**How to find:** Search for `sample_valid` rising edge after first buffer swap

### 4. **I2S Frame Capture**
- **Zoom:** 20µs (one complete I2S frame)
- **Focus:**
  - `ws_o` full cycle
  - `cnt_q` counting 0→25 twice (left + right)
  - `ready_o` pulse at frame end

### 5. **Single Clock Cycle**
- **Zoom:** 100ns (~3 clock cycles)
- **Focus:** Sequential logic updates, register changes

---

## 📝 GTKWave Tips

### Loading Signals Quickly
1. In left panel, expand: `TOP` → `fpga_template_top_tb` → `dut`
2. **Select multiple signals:** Hold Ctrl and click
3. **Add to waveform:** Right-click → "Insert" or press Insert key

### Formatting
- **Change radix:** Right-click signal → Data Format → (Hex/Dec/Binary/Analog)
- **Group signals:** Edit → Create Group
- **Analog view:** Great for counters and level_q
- **Highlight transitions:** Edit → Highlight → All Transitions

### Navigation
- **Zoom to fit:** View → Zoom → Zoom Fit
- **Center on time:** Click time, press 'C'
- **Marker:** Click waveform, press 'T'
- **Measure time:** Place primary marker (T), then secondary marker (T again), see ΔTime in bottom

### Searching
- **Find edge:** Edit → Search Signal → Rising/Falling Edge
- **Jump to time:** Edit → Jump to Time → Enter time

---

## 🔍 What to Look for (Verification Checklist)

### ✅ I2S Timing
- [ ] SCK toggles every 8 system clocks (296ns period)
- [ ] WS toggles every 32 SCK cycles (~18.96µs)
- [ ] `ready_o` pulses once per WS cycle

### ✅ RAM Write Path
- [ ] `write_count` increments 0→16 cleanly
- [ ] `write_buffer_sel` toggles at count==16
- [ ] No glitches on `write_address`

### ✅ Buffer Swap
- [ ] `buffer_ready_o` pulses exactly when `write_count==16`
- [ ] 2 swaps occur for 16-sample test (at samples 8 and 16)
- [ ] `read_buffer_sel` updated at swap
- [ ] `read_valid_o` goes HIGH and stays HIGH

### ✅ RAM Read Path
- [ ] After first swap, `read_valid_o` stays HIGH
- [ ] `read_count` wraps 0→15→0 continuously
- [ ] `read_address` increments without gaps

### ✅ VU Meter Handshake **⭐ MOST IMPORTANT**
- [ ] `ram_ready_q` LOW for exactly 2 cycles after handshake
- [ ] `processing_delay_q` HIGH for exactly 1 cycle
- [ ] No back-to-back handshakes (min 3 cycle spacing)
- [ ] Handshake rate matches expectation (~3 clocks/sample)

### ✅ VU Meter Level
- [ ] `level_q` increases as samples arrive
- [ ] No overflow or underflow
- [ ] `leds_o` updates at 50 Hz rate

---

## 🐛 Common Issues to Debug

### Issue: Buffer Overflow
**Symptoms:** `buffer_overflow_o` goes HIGH
**Check:**
- `write_count` vs `write_accepted`
- Is RAM write path stalled?

### Issue: No Buffer Swap
**Symptoms:** `buffer_ready_o` never pulses
**Check:**
- Is `write_count` reaching 16?
- Is `write_valid_i` pulsing regularly?

### Issue: VU Meter Not Consuming Data
**Symptoms:** Few handshakes, `read_count` not incrementing
**Check:**
- `ram_read_ready_o` timing
- `processing_delay_q` behavior
- Is `read_valid_o` HIGH?

### Issue: Incorrect Handshake Timing
**Symptoms:** VU meter accepts samples too quickly/slowly
**Check:**
- Count cycles between `sample_valid` pulses
- Should be 3 cycles minimum
- `ram_ready_q` should be LOW for 2 cycles after handshake

---

## 📊 Expected Simulation Results (16 samples)

- **Total samples captured:** ~17 (slightly more due to timing)
- **Buffer swaps:** 2 (at samples 8 and 16)
- **VU handshakes:** Many (~thousands in circular mode)
- **Handshake rate:** Every 3 clock cycles = 9 MHz max throughput
- **Actual sample rate:** ~52.7 kHz (well below max)
- **No errors:** `buffer_overflow_o` stays LOW

---

## 🚀 Quick View Template

Copy this signal list for quick viewing:

```
# Group: System
TOP.fpga_template_top_tb.dut.clk
TOP.fpga_template_top_tb.dut.resetb

# Group: I2S
TOP.fpga_template_top_tb.dut.u_i2s_clock.sck_o
TOP.fpga_template_top_tb.dut.u_i2s_clock.ws_o
TOP.fpga_template_top_tb.dut.u_sampler.ready_o
TOP.fpga_template_top_tb.dut.u_sampler.left_o[23:0]

# Group: RAM Write
TOP.fpga_template_top_tb.dut.u_ram.write_count[8:0]
TOP.fpga_template_top_tb.dut.u_ram.write_buffer_sel
TOP.fpga_template_top_tb.dut.u_ram.buffer_ready_o

# Group: RAM Read
TOP.fpga_template_top_tb.dut.u_ram.read_count[8:0]
TOP.fpga_template_top_tb.dut.u_ram.read_buffer_sel
TOP.fpga_template_top_tb.dut.u_ram.read_valid_o

# Group: VU Handshake (CRITICAL)
TOP.fpga_template_top_tb.dut.vu.ram_read_valid_i
TOP.fpga_template_top_tb.dut.vu.ram_read_ready_o
TOP.fpga_template_top_tb.dut.vu.ram_ready_q
TOP.fpga_template_top_tb.dut.vu.processing_delay_q
TOP.fpga_template_top_tb.dut.vu.sample_valid

# Group: VU Level
TOP.fpga_template_top_tb.dut.vu.level_q[31:0]
TOP.fpga_template_top_tb.dut.vu.leds_o[5:0]
```

---

**Tip:** Save your signal configuration: File → Write Save File
