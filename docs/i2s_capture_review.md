# I2S Capture System Code Review Report

**Date**: 2025-10-21
**Reviewer**: Claude Code
**Scope**: I2S audio capture and VU meter subsystem

## Summary

This review covers four SystemVerilog modules that implement I2S audio capture, clock generation, VU metering, and top-level integration:

- `digital/sampler/i2s_capture_24.sv` - 24-bit I2S data capture
- `digital/clk_generator/i2s_clock_gen.sv` - I2S clock generation (SCK/WS)
- `digital/sampler/vu_meter_6led.sv` - 6-LED VU meter display
- `digital/fpga_template/fpga_template.sv` - Top-level integration

**Overall Assessment**: Two **CRITICAL** bugs found that will prevent correct operation:
1. I2S data sampling timing error - captures wrong bit values
2. Debug button logic inversion - feature completely broken

Additional medium and low-priority issues identified for timing, documentation, and code clarity.

---

## Syntax or Structural Issues

### 1. Missing Signal Synchronization (i2s_capture_24.sv:60)
**Severity**: CRITICAL
**Location**: `digital/sampler/i2s_capture_24.sv:60`

**Issue**:
Data signal `sd_i` is sampled directly without proper synchronization, and is sampled **after** the SCK rising edge has been detected. According to I2S specification, data is valid on the rising edge of SCK, but the current implementation detects the edge first, then samples on the **next** clock cycle.

**Current Code**:
```systemverilog
logic sck_d, ws_d;
always_ff @(posedge clk_i) begin
  if (!rst_ni) begin
    sck_d <= 1'b0;
    ws_d  <= 1'b0;
  end else begin
    sck_d <= sck_i;  // Synchronize SCK
    ws_d  <= ws_i;   // Synchronize WS
    // sd_i NOT synchronized!
  end
end
wire sck_rise = ~sck_d & sck_i;  // Line 34

// Later...
if (sck_rise) begin
  shift25_q <= {shift25_q[23:0], sd_i}; // Line 60: Samples sd_i one cycle late!
```

**Impact**:
All captured audio data will be shifted by one bit, resulting in completely corrupted samples.

**Fix**:
```systemverilog
logic sck_d, ws_d, sd_d;  // Add sd_d synchronizer
always_ff @(posedge clk_i) begin
  if (!rst_ni) begin
    sck_d <= 1'b0;
    ws_d  <= 1'b0;
    sd_d  <= 1'b0;
  end else begin
    sck_d <= sck_i;
    ws_d  <= ws_i;
    sd_d  <= sd_i;  // Capture sd on same clock edge as sck
  end
end
wire sck_rise = ~sck_d & sck_i;

// Use synchronized sd_d:
if (sck_rise) begin
  shift25_q <= {shift25_q[23:0], sd_d};  // Use sd_d, not sd_i
```

---

### 2. Parameter Bit Width Redundancy (vu_meter_6led.sv:11-16)
**Severity**: LOW
**Location**: `digital/sampler/vu_meter_6led.sv:11-16`

**Issue**:
Threshold parameters declared as `int unsigned` (32-bit) but initialized with `24'd` sized literals. The sizing is redundant since `int` is already 32 bits.

**Current Code**:
```systemverilog
parameter int unsigned TH1   = 24'd1000,  // int is 32-bit, 24'd is redundant
parameter int unsigned TH2   = 24'd3000,
// ...
```

**Fix** (choose one approach):
```systemverilog
// Option 1: Remove redundant sizing
parameter int unsigned TH1 = 1000,
parameter int unsigned TH2 = 3000,

// Option 2: Use explicit bit vectors
parameter [31:0] TH1 = 32'd1000,
parameter [31:0] TH2 = 32'd3000,
```

---

### 3. Output Signal Type Not Explicit (i2s_capture_24.sv:18-19)
**Severity**: LOW
**Location**: `digital/sampler/i2s_capture_24.sv:18-19`

**Issue**:
Output signals `left_o` and `right_o` represent signed PCM audio data but are not declared as `signed`. This could cause sign-extension issues when used in signed arithmetic (like the VU meter).

**Current Code**:
```systemverilog
output logic [23:0] left_o,   // Unsigned by default
output logic [23:0] right_o,
```

**Fix**:
```systemverilog
output logic signed [23:0] left_o,   // Explicitly signed for PCM audio
output logic signed [23:0] right_o,
```

---

## Logic or Functional Issues

### 4. Off-By-One Counter Check (i2s_capture_24.sv:65)
**Severity**: HIGH
**Location**: `digital/sampler/i2s_capture_24.sv:65`

**Issue**:
The code latches output data when `cnt_q == 6'd24`, but this check happens **before** the 25th bit is shifted in. The counter is incremented from 24 to 25 in the same `if` block, meaning the data latch uses the shift register state when only 24 bits have been captured.

**Current Code**:
```systemverilog
if (cnt_q < 6'd25) begin
  shift25_q <= {shift25_q[23:0], sd_i};
  cnt_q     <= cnt_q + 6'd1;

  // This check happens when cnt_q is STILL 24, before increment completes
  if (cnt_q == 6'd24) begin
    if (ws_i == 1'b0) begin
      left_o      <= shift25_q[23:0];  // Only 24 bits shifted at this point!
      left_done_q <= 1'b1;
    end else begin
      right_o      <= shift25_q[23:0];
      right_done_q <= 1'b1;
    end
  end
end
```

**Impact**:
The captured data will be missing the 25th bit, or will capture one bit from the previous frame.

**Fix**:
```systemverilog
if (cnt_q < 6'd25) begin
  shift25_q <= {shift25_q[23:0], sd_d};
  cnt_q     <= cnt_q + 6'd1;
end

// Separate check after counter update (on next cycle when cnt_q == 25)
if (cnt_q == 6'd25) begin
  if (ws_i == 1'b0) begin
    left_o      <= shift25_q[23:0];
    left_done_q <= 1'b1;
  end else begin
    right_o      <= shift25_q[23:0];
    right_done_q <= 1'b1;
  end
end
```

---

### 5. Inverted Debug Button Logic (fpga_template.sv:328)
**Severity**: CRITICAL
**Location**: `digital/fpga_template/fpga_template.sv:328`

**Issue**:
The debug state machine checks `if (!btn_s2_edge)` which is inverted logic. Since `btn_s2_edge` is a single-cycle pulse on button press, `!btn_s2_edge` will be **true** for all other clock cycles, causing the debug sequence to start continuously when the button is **not** pressed.

**Current Code**:
```systemverilog
DEBUG_IDLE: begin
  if (!btn_s2_edge) begin  // WRONG: true when button NOT pressed!
    debug_state <= DEBUG_START;
    debug_counter <= 16'h0000;
    debug_active <= 1'b1;
  end
end
```

**Impact**:
Debug sequence triggers continuously, making the feature completely unusable.

**Fix**:
```systemverilog
DEBUG_IDLE: begin
  if (btn_s2_edge) begin  // Correct: trigger on button press
    debug_state <= DEBUG_START;
    debug_counter <= 16'h0000;
    debug_active <= 1'b1;
  end
end
```

---

### 6. Frame Size Parameter vs. Documentation Mismatch (i2s_clock_gen.sv:17)
**Severity**: MEDIUM
**Location**: `digital/clk_generator/i2s_clock_gen.sv:17`

**Issue**:
Module header comment states "Frame: 64 SCK cycles (32 bits per channel, 2 channels)" but the default parameter is `SCKS_PER_FRAME = 32`.

**Current Code**:
```systemverilog
// Line 11: Comment says 64 SCK cycles per frame
//   - Frame: 64 SCK cycles (32 bits per channel, 2 channels)

// Line 17: Parameter defaults to 32
parameter int unsigned SCKS_PER_FRAME  = 32,  // SCKs per full frame (L+R)
```

**Impact**:
Confusion about actual frame structure. With `SCKS_PER_FRAME = 32`, each channel gets only 16 SCK cycles, which doesn't match "32 bits per channel" unless using DDR sampling.

**Fix** (choose one):
```systemverilog
// Option 1: Update parameter to match comment
parameter int unsigned SCKS_PER_FRAME = 64,  // 32 bits per channel × 2 channels

// Option 2: Update comment to match parameter
//   - Frame: 32 SCK cycles (16 bits per channel, 2 channels)
```

**Note**: Based on i2s_capture_24.sv behavior (25 bits per channel), the parameter should likely be `64` to provide 32 SCK cycles per channel.

---

### 7. Non-Standard Edge Detection (i2s_capture_24.sv:35)
**Severity**: LOW
**Location**: `digital/sampler/i2s_capture_24.sv:35`

**Issue**:
Using XOR (`^`) for edge detection is non-standard and less clear than explicit comparison.

**Current Code**:
```systemverilog
wire ws_edge = ws_d ^ ws_i;  // XOR for edge detection
```

**Fix**:
```systemverilog
wire ws_edge = (ws_d != ws_i);  // More explicit and conventional
```

---

## Timing / Reset Domain Risks

### 8. Reset Polarity Documentation Inconsistency (fpga_template.sv:154-160)
**Severity**: MEDIUM
**Location**: `digital/fpga_template/fpga_template.sv:154-160`

**Issue**:
Comments and code logic appear contradictory regarding reset polarity for Tang Nano 9K.

**Current Code and Comments**:
```systemverilog
// Reset button behavior differs between boards:
// Tang Nano 9K:  Button pulls LOW when pressed  (active LOW)
// Tang Nano 20K: Button pulls HIGH when pressed (active HIGH)
wire resetb;
`ifdef TANGNANO20K
    assign resetb = ~btn_s1_resetb;   // 20K: button HIGH when pressed
`elsif TANGNANO9K
    assign resetb = btn_s1_resetb;    // 9K: button LOW when pressed, invert to get active high reset
`else
    assign resetb = ~btn_s1_resetb;   // Default to 20K behavior
`endif
```

**Analysis**:
- Comment says "9K: button LOW when pressed"
- Comment also says "invert to get active high reset"
- But code does **NOT** invert: `resetb = btn_s1_resetb`
- If button is LOW when pressed, then `resetb` will be LOW (active-low reset)
- This contradicts CLAUDE.md which states "9K: used directly as active high resetb"

**Contradiction**:
The comment "invert to get active high reset" and the actual code `assign resetb = btn_s1_resetb` are opposite actions.

**Impact**:
If the reset polarity is wrong, the FPGA will either be held in permanent reset or never reset properly on Tang Nano 9K boards.

**Requires Clarification**:
Need to verify actual hardware behavior on Tang Nano 9K:

```systemverilog
// If btn_s1_resetb is LOW when pressed on 9K, AND we want resetb HIGH during reset:
`elsif TANGNANO9K
    assign resetb = ~btn_s1_resetb;   // Invert: button LOW → resetb HIGH

// If btn_s1_resetb is HIGH when NOT pressed on 9K, AND we want resetb HIGH during reset:
`elsif TANGNANO9K
    assign resetb = btn_s1_resetb;    // Direct: button released → resetb HIGH
```

**Recommendation**: Test on actual Tang Nano 9K hardware or consult board schematic.

---

### 9. Potential Metastability in WS Edge Detection
**Severity**: LOW
**Location**: `digital/sampler/i2s_capture_24.sv:35`

**Issue**:
Edge detection using combinatorial XOR on synchronized signals is acceptable, but the edge signal is used in the same clock cycle. If `ws_i` transitions very close to `clk_i` edge, metastability could cause glitches.

**Current Code**:
```systemverilog
always_ff @(posedge clk_i) begin
  ws_d <= ws_i;  // Single-stage synchronizer
end
wire ws_edge = ws_d ^ ws_i;  // Combinatorial edge detect
```

**Mitigation**:
Since `ws_i` comes from `i2s_clock_gen` which is synchronous to `clk_i`, this should not cause issues **if both modules use the same clock**. However, best practice would be to use a two-stage synchronizer for signals crossing domains.

**Current Status**: ACCEPTABLE (same clock domain assumed)

---

### 10. Clock Domain Crossing Assumptions
**Severity**: LOW
**Location**: `digital/fpga_template/fpga_template.sv:84-93, 117-123`

**Issue**:
The I2S clock generator (`i2s_clock_gen`) and I2S capture module (`i2s_capture_24`) are connected directly, with the assumption that both use the same `clk` (27 MHz system clock).

**Current Architecture**:
```systemverilog
// Clock generator (synchronous to clk)
i2s_clock_gen u_i2s_clock (
  .clk_i   (clk),
  .sck_o   (i2s_sck),  // Generated from clk
  .ws_o    (i2s_ws)    // Generated from clk
);

// Capture module (synchronous to clk)
i2s_capture_24 u_sampler (
  .clk_i   (clk),      // Same clock
  .sck_i   (i2s_sck),  // Treated as data signal
  .ws_i    (i2s_ws),   // Treated as data signal
  .sd_i    (mic_sd_0)  // External async signal
);
```

**Analysis**:
This is a valid design pattern where SCK and WS are generated **from** the system clock, then treated as data signals by the capture module. The synchronizers in i2s_capture_24 provide edge detection, not CDC synchronization.

**Status**: CORRECT DESIGN PATTERN

**External Signal Risk**:
The `mic_sd_0` signal comes from an external microphone and is truly asynchronous. However, it's only sampled when `sck_rise` is detected, and since SCK is generated synchronously, the sampling window is well-defined. This is acceptable for I2S interfaces.

---

## Recommendations

### Immediate Action Required (Critical Bugs)

1. **Fix i2s_capture_24.sv data sampling** (Issue #1)
   - Add `sd_d` synchronizer register
   - Use `sd_d` instead of `sd_i` in shift register
   - **Priority**: CRITICAL - Current code captures wrong data

2. **Fix fpga_template.sv button logic** (Issue #5)
   - Change `if (!btn_s2_edge)` to `if (btn_s2_edge)`
   - **Priority**: CRITICAL - Debug feature completely broken

### High Priority Fixes

3. **Fix i2s_capture_24.sv counter logic** (Issue #4)
   - Move data latch check outside counter increment block
   - Check `cnt_q == 6'd25` instead of `cnt_q == 6'd24`
   - **Priority**: HIGH - May cause data corruption

4. **Verify and fix reset polarity** (Issue #8)
   - Test on Tang Nano 9K hardware
   - Update code or comments to match actual behavior
   - **Priority**: MEDIUM-HIGH - Could prevent board from working

### Medium Priority Improvements

5. **Resolve i2s_clock_gen parameter mismatch** (Issue #6)
   - Verify intended frame size (32 or 64 SCK cycles)
   - Update either parameter default or documentation
   - **Priority**: MEDIUM - Affects system timing

6. **Add explicit signedness** (Issue #3)
   - Declare `left_o` and `right_o` as `signed` in i2s_capture_24
   - **Priority**: LOW-MEDIUM - Prevents potential arithmetic issues

### Code Quality Improvements

7. **Clean up vu_meter_6led.sv parameters** (Issue #2)
   - Remove redundant `24'd` sizing from `int unsigned` parameters
   - **Priority**: LOW - Code clarity only

8. **Update edge detection style** (Issue #7)
   - Change `ws_d ^ ws_i` to `(ws_d != ws_i)`
   - **Priority**: LOW - Readability only

### Testing Recommendations

After implementing fixes:

1. **Unit Test**: Run individual module testbenches with waveform verification
2. **Integration Test**: Verify I2S clock generation with scope or logic analyzer
3. **Functional Test**: Capture real audio from microphone and verify data integrity
4. **Button Test**: Verify debug sequence triggers correctly on S2 button press
5. **Reset Test**: Verify both Tang Nano 9K and 20K reset behavior
6. **VU Meter Test**: Verify LED response to audio input levels

### Design Documentation

Consider adding:
- Timing diagrams showing SCK, WS, and SD relationships
- State machine diagrams for debug sequence
- Block diagram showing clock domain relationships
- Register map documentation for sampler configuration

---

## Code Quality Assessment

### i2s_clock_gen.sv
- **Quality**: GOOD
- Well-structured with clear separation of SCK and WS generation
- Excellent use of SystemVerilog assertions for verification
- Good parameter validation
- Only minor documentation issue

### vu_meter_6led.sv
- **Quality**: GOOD
- Clean leaky integrator implementation
- Proper use of tick-based LED updates to prevent flicker
- Good parameterization for tuning
- Minor parameter style issue only

### i2s_capture_24.sv
- **Quality**: NEEDS WORK
- Good synchronization structure but critical sampling bug
- Off-by-one error in counter logic
- Needs explicit signal types for audio data
- Clear comments but logic issues undermine functionality

### fpga_template.sv
- **Quality**: FAIR
- Good modular structure and clear section organization
- Critical button logic bug
- Reset polarity inconsistency
- Extensive debug infrastructure (when fixed)

---

## Conclusion

The I2S capture system has a solid architectural foundation but contains **two critical bugs** that will prevent correct operation:

1. **I2S data capture timing error** - will corrupt all audio samples
2. **Debug button logic inversion** - feature completely non-functional

Additionally, the **reset polarity** issue for Tang Nano 9K needs immediate verification to ensure the design works on target hardware.

After addressing these critical issues, the design should function correctly. The medium and low-priority items are code quality improvements that should be addressed during the next revision cycle.

**Estimated effort to fix critical issues**: 1-2 hours
**Recommended test time after fixes**: 4-6 hours (including hardware validation)

---

**End of Report**
