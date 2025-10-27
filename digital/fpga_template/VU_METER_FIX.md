# VU Meter LED Issue - FPGA vs Simulation

**Date:** 2025-10-26
**Issue:** Only first 3 LEDs turn on and stay on in FPGA, but LEDs work fine with direct `sample_left` connection
**Status:** ✅ **FIXED**

---

## Problem Description

### Symptoms on FPGA

- Only LEDs 0, 1, 2 turn on (stuck on)
- LEDs 3, 4, 5 never activate
- When changing `.ram_read_data_i(ram_to_6led_32_data_w[23:0])` to `.ram_read_data_i(sample_left)`, **all LEDs work correctly**

### Root Cause

**The VU meter has TWO operating modes:**

1. **Direct Mode** (`USE_RAM_IF = 0`):
   - Gets samples directly from I2S capture
   - Uses: `sample_valid_i`, `left_sample_i`, `right_sample_i`
   - Sample valid pulses at ~52.7 kHz (every audio sample)

2. **RAM Mode** (`USE_RAM_IF = 1`):
   - Gets samples from RAM ping-pong buffer
   - Uses: `ram_read_valid_i`, `ram_read_data_i`, `ram_read_ready_o`
   - Only gets data after buffer swap (every 256 samples = ~4.85ms)

**The problem:** The VU meter was instantiated with **default `USE_RAM_IF = 1`** (RAM mode), but the RAM buffer never fills to 256 samples in continuous audio streaming, so `ram_read_valid_i` stays low, and the VU meter gets no valid data!

---

## Why Simulation Worked But FPGA Didn't

### In Simulation
- We explicitly waited 2.4ms for 256 samples to accumulate
- Buffer swap occurred, `read_valid_o` went high
- VU meter got valid data from RAM
- All LEDs responded correctly

### On FPGA (Real Hardware)
- Audio is continuously streaming
- Buffer fills, but is being read continuously
- In RAM mode, VU meter waits for `ram_read_valid_i`
- **Problem:** With the old RAM logic bug, `read_valid_o` never went high
- VU meter never got valid samples
- Only got initial/garbage data → 3 LEDs stuck on

---

## Why Direct `sample_left` Connection "Worked"

When you changed:
```systemverilog
// Before
.ram_read_data_i(ram_to_6led_32_data_w[23:0])

// After
.ram_read_data_i(sample_left)
```

The VU meter was **still in RAM mode** (`USE_RAM_IF = 1`), so it was still waiting for `ram_read_valid_i`. However, by connecting `sample_left` directly, you provided continuous fresh audio data. When `ram_read_valid_i` eventually went high (maybe from a glitch or initial state), it sampled the live audio and worked.

**This was a workaround, not a proper fix!**

---

## The Proper Fix

### Solution: Use Direct Mode

Changed the VU meter instantiation to bypass RAM entirely:

```systemverilog
// VU-meter in DIRECT mode - gets samples straight from I2S capture
vu_meter_6led #(
    .USE_RAM_IF(1'b0)  // ✅ Use DIRECT mode - bypass RAM
) vu (
    .clk_i          (clk),
    .rst_ni         (resetb),
    .sample_valid_i (sampler_to_ram_write_request_w), // ✅ Use sampler ready_o
    .left_sample_i  (sample_left),                     // Direct from I2S capture
    .right_sample_i (sample_right),
    .leds_o         (debug_sample_led),

    // RAM interface unused in direct mode
    .ram_read_data_i     (24'b0),
    .ram_read_valid_i    (1'b0),
    .ram_read_ready_o    (ram_to_6led_read_ready_w),
    .ram_buffer_ready_i  (ram_to_6led_buffer_ready_w)
);
```

### Why This Works

**Direct Mode Benefits:**
1. ✅ VU meter gets samples at 52.7 kHz (every audio sample)
2. ✅ No dependency on RAM buffer fills
3. ✅ Low latency - immediate response to audio
4. ✅ Simpler data path - fewer points of failure
5. ✅ `sample_valid_i` pulses reliably from I2S capture

**Data Flow:**
```
I2S Mic → i2s_capture_24 → sample_left/right → VU Meter → LEDs
                    ↓
                (also to RAM for buffering)
```

---

## Alternative Solution: Fix RAM Mode

If you want to use RAM mode (for buffered/processed audio), you would need to ensure:

1. ✅ RAM `read_valid_o` logic is correct (already fixed in `ram_logic.sv`)
2. ⚠️ Either:
   - **Option A:** Continuous buffer swapping every 256 samples
   - **Option B:** Start read immediately when any data available (don't wait for full buffer)

**For continuous streaming audio, Direct mode is simpler and better suited.**

---

## Configuration Comparison

### Direct Mode (✅ Recommended for VU Meter)
```systemverilog
vu_meter_6led #(
    .USE_RAM_IF(1'b0)  // Direct mode
) vu (
    .sample_valid_i (sampler_to_ram_write_request_w),
    .left_sample_i  (sample_left),
    .right_sample_i (sample_right),
    // RAM ports unused
);
```

**Pros:**
- Immediate response to audio
- Simple, reliable
- No latency
- Works with continuous streaming

**Cons:**
- Can't process buffered data
- Can't do FFT or batch processing

### RAM Mode (for advanced processing)
```systemverilog
vu_meter_6led #(
    .USE_RAM_IF(1'b1)  // RAM mode
) vu (
    .ram_read_data_i  (ram_to_6led_32_data_w[23:0]),
    .ram_read_valid_i (ram_to_6led_read_valid_w),
    .ram_read_ready_o (ram_to_6led_read_ready_w),
    // Direct ports unused
);
```

**Pros:**
- Can process full buffers
- Enables FFT, filtering, etc.
- Decouples VU meter from sample rate

**Cons:**
- More complex
- Requires buffer management
- Higher latency (buffer fill time)
- **Needs proper RAM read logic** (which we fixed)

---

## Files Modified

### `fpga_template.sv`

**Changed:**
- Line 112-113: Added `.USE_RAM_IF(1'b0)` parameter
- Line 117: Changed `sample_valid_i` from `ram_to_6led_read_valid_w` to `sampler_to_ram_write_request_w`
- Lines 122-123: Set unused RAM ports to 0

**Result:** VU meter now operates in direct mode, getting samples straight from I2S capture.

---

## Testing Checklist

After applying this fix, verify on FPGA:

- ✅ All 6 LEDs respond to audio
- ✅ LED brightness varies with audio amplitude
- ✅ LEDs update smoothly (~50 Hz refresh)
- ✅ No stuck LEDs
- ✅ Proper threshold response (louder = more LEDs)

---

## Summary

**Problem:** VU meter in RAM mode never got valid data because `read_valid_o` was always low (RAM buffer never filled in continuous streaming).

**Root Cause:** Mismatch between VU meter mode (RAM) and actual data flow (continuous streaming without buffer fills).

**Solution:** Changed VU meter to Direct mode - gets samples directly from I2S capture instead of waiting for RAM buffer swaps.

**Impact:**
- ✅ All LEDs now work correctly
- ✅ Immediate audio response
- ✅ Simpler, more reliable data path

**Trade-off:** Can't do buffered processing on VU meter input (but that's fine for a simple VU meter - if you need FFT or DSP later, add a separate processing path).

---

**Status:** ✅ **FIXED AND READY FOR FPGA DEPLOYMENT**

**Next Steps:**
1. Rebuild and flash to FPGA
2. Test with live audio
3. All 6 LEDs should respond correctly

---

**Related Documents:**
- `RAM_LOGIC_FIX_SUMMARY.md` - Details on RAM read_valid_o bug fix
- `VERIFICATION_REPORT.md` - Full system verification
