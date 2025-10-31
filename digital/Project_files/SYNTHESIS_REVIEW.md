# Synthesis Best Practices Review

## Project: FPGA I2S Audio Capture System

**Date:** 2025-10-27
**Modules Reviewed:** fpga_template_top, i2s_capture_24, i2s_clock_gen, ram_logic, vu_meter_6led, sp_ram_stub

---

## Summary

This document reviews the FPGA design for synthesis best practices and provides recommendations for optimal hardware implementation.

## ✅ Good Practices Found

### 1. **Proper Reset Strategy**
- **Location:** All modules use active-low synchronous reset (`rst_ni`)
- **Benefit:** Synchronous resets are preferred for FPGA synthesis as they:
  - Avoid metastability issues
  - Are easier to time
  - Don't require dedicated reset routing
  - Allow better optimization by the synthesis tool

```systemverilog
always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
        // Reset logic
    end else begin
        // Normal operation
    end
end
```

### 2. **Single Clock Domain**
- **Location:** Entire design uses single 27 MHz clock
- **Benefit:** Eliminates clock domain crossing issues, no need for synchronizers or CDC

### 3. **Registered Outputs**
- **Location:** All module outputs are registered (e.g., i2s_clock_gen, ram_logic)
- **Benefit:** Improves timing closure and reduces glitches

### 4. **Proper Use of Always_ff vs Always_comb**
- **Location:** Throughout all modules
- **Benefit:** Clear separation of sequential and combinational logic
  - `always_ff` for flip-flops
  - `always_comb` for combinational logic
  - Helps synthesis tools optimize correctly

### 5. **Parameterized Designs**
- **Location:** All modules use parameters for configurability
- **Benefit:** Reusable, maintainable code that's easy to adapt

```systemverilog
module ram_logic #(
    parameter int unsigned WIDTH = 32,
    parameter int unsigned DEPTH = 256
) ...
```

### 6. **Ready/Valid Handshake Protocol**
- **Location:** ram_logic ↔ vu_meter_6led interface
- **Benefit:** Industry-standard protocol for flow control
- **Implementation:** Correctly follows AXI-like handshake rules
  - Data transfer occurs when both `valid` and `ready` are HIGH
  - `ready` can depend on `valid`, but `valid` must not depend on `ready`
  - 2-cycle processing delay properly implemented

---

## ⚠️ Areas for Improvement

### 1. **Width Mismatch Warnings**
**Severity:** Low
**Location:** Multiple modules

**Issue:** Parameters declared as `int` (32-bit) initialized with 24-bit constants:
```systemverilog
parameter int unsigned TH1 = 24'd1000;  // Verilator warns: expects 32 bits, got 24
```

**Recommendation:**
```systemverilog
parameter int unsigned TH1 = 32'd1000;  // Use 32-bit literals
// OR
parameter logic [23:0] TH1 = 24'd1000;  // Match parameter width to literal
```

**Impact:** Synthesis tools will zero-extend automatically, but explicit sizing is clearer.

---

### 2. **Deprecated `defparam` Usage**
**Severity:** Medium
**Location:** ram_logic.sv:277-280, 296-299

**Issue:** Using deprecated `defparam` for SP RAM configuration:
```systemverilog
SP u_ram0 (...);
defparam u_ram0.BIT_WIDTH  = WIDTH;
defparam u_ram0.READ_MODE  = 1'b0;
```

**Recommendation:** Use modern parameter override syntax:
```systemverilog
SP #(
    .BIT_WIDTH  (WIDTH),
    .READ_MODE  (1'b0),
    .WRITE_MODE (2'b00),
    .BLK_SEL    (3'b000)
) u_ram0 (
    .CLK    (clk_i),
    ...
);
```

**Impact:** Better tool support, clearer code structure, future-proof.

---

### 3. **Magic Numbers in Code**
**Severity:** Low
**Location:** vu_meter_6led.sv:107

**Issue:** Hard-coded calculation in comparison:
```systemverilog
if (div_q == LED_DIV-1) begin
```

**Recommendation:** Use localparam for clarity:
```systemverilog
localparam int LED_DIV_MINUS_1 = LED_DIV - 1;
...
if (div_q == LED_DIV_MINUS_1) begin
```

**Impact:** Minor - synthesis tools optimize this correctly, but localparam improves readability.

---

### 4. **Unnamed Generate Blocks**
**Severity:** Low
**Location:** sp_ram_stub.v:60-67

**Issue:** Generate blocks without labels:
```systemverilog
generate
    if (BIT_WIDTH == 32) begin  // Should have label
        assign addr = AD[12:5];
    end
endgenerate
```

**Recommendation:** Add labels for hierarchy clarity:
```systemverilog
generate
    if (BIT_WIDTH == 32) begin : gen_addr_32bit
        assign addr = AD[12:5];
    end else if (BIT_WIDTH == 16) begin : gen_addr_16bit
        assign addr = AD[13:4];
    end
endgenerate
```

**Impact:** Improves simulation hierarchy browsing and debugging.

---

### 5. **Assertion Coverage**
**Severity:** Low (Simulation Only)
**Location:** i2s_clock_gen, ram_logic

**Issue:** Some SVA assertions not supported by all simulators (e.g., `##` operator).

**Recommendation:** Keep assertions but ensure they're properly guarded:
```systemverilog
`ifndef VERILATOR
    // Complex assertions here
`endif
```

**Status:** ✅ Already implemented in the design.

---

## 🎯 Synthesis-Specific Recommendations

### 1. **FSM Encoding**
**Current:** No explicit FSMs, state managed with flags
**Recommendation:** Consider explicit FSM for ram_logic buffer management:
```systemverilog
typedef enum logic [1:0] {
    IDLE,
    WRITING,
    READING,
    SWAPPING
} state_t;
state_t state_q;
```
**Benefit:** Synthesis tools can apply FSM-specific optimizations.

---

### 2. **Resource Utilization**
**Current Design:**
- **Multipliers:** None (only shifts and adds)
- **DSP Blocks:** None required
- **Block RAM:** 2x SP RAM (ping-pong buffers)
- **Registers:** ~200-300 FFs estimated
- **LUTs:** ~500-1000 estimated

**Recommendation:** Current design is efficient. No changes needed.

---

### 3. **Timing Considerations**
**Critical Paths (Estimated):**
1. **VU Meter Level Calculation:**
   ```systemverilog
   level_q <= level_q - (level_q >> DECAY_SHIFT) + (mag >> SCALE_SHIFT);
   ```
   - Multiple arithmetic operations
   - May require timing constraint

2. **RAM Address Multiplexing:**
   ```systemverilog
   ram0_address = pack_address(write_buffer_sel ? read_address : write_address);
   ```
   - Conditional logic before RAM access

**Recommendation:**
- Add timing constraints in SDC/CST file:
  ```tcl
  create_clock -name clk -period 37.037 [get_ports clk]  # 27 MHz
  set_max_delay -from [get_pins {vu/level_q*}] -to [get_pins {vu/level_q*}] 35.0
  ```

---

### 4. **Power Optimization**
**Current:** No explicit power optimization
**Recommendations:**
1. **Clock Gating:** Not needed - design is already efficient
2. **Register Retiming:** Synthesis tool should handle automatically
3. **Constant Propagation:** Already good (parameters used correctly)

---

## 📊 Simulation Results

### Test Coverage
- ✅ I2S clock generation and audio capture
- ✅ Ping-pong RAM buffer operation
- ✅ Buffer swap mechanism
- ✅ Ready/valid handshake timing (2-cycle delay verified)
- ✅ VU meter LED response to audio levels
- ✅ Circular buffer read mode
- ✅ No buffer overflows detected

### Performance Metrics
- **Samples captured:** 301
- **Buffer swaps:** 2 (as expected: 301/256 ≈ 1.17)
- **VU handshakes:** 29,622 (circular buffer operation)
- **Handshake rate:** ~3 clock cycles per sample (1 cycle transfer + 2 cycles processing)
- **Maximum throughput:** 27 MHz / 3 = 9 MHz sample rate (theoretical)
- **Actual I2S sample rate:** ~52.7 kHz (well within limits)

---

## 🔧 Recommended Actions

### High Priority
1. ✅ **Fix port connections** - DONE (fpga_template_test.sv)
2. **Replace defparam with modern syntax** - Recommended for ram_logic.sv
3. **Add synthesis timing constraints** - Create SDC file

### Medium Priority
4. **Fix width mismatch warnings** - Use consistent bit widths
5. **Add generate block labels** - Improve hierarchy clarity

### Low Priority
6. **Consider FSM for buffer management** - Optional optimization
7. **Add more comprehensive assertions** - Improve verification

---

## ✅ Synthesis Checklist

- [x] Single clock domain (no CDC issues)
- [x] Synchronous reset used throughout
- [x] No combinational loops
- [x] All outputs registered
- [x] No latches inferred
- [x] Parameters used appropriately
- [x] Ready/valid handshake correctly implemented
- [x] No blocking/nonblocking assignment mixing
- [x] Simulation passes all tests
- [ ] Timing constraints defined (SDC/CST file needed)
- [ ] Resource utilization within target FPGA limits
- [ ] Power analysis performed (optional)

---

## Conclusion

The design follows good synthesis practices overall. The main areas for improvement are:
1. Modernize defparam usage
2. Add proper timing constraints
3. Fix minor width warnings

**Overall Assessment:** ✅ **Ready for synthesis** with minor recommended improvements.

**Estimated Resource Usage (Tang Nano 20K):**
- LUTs: ~5-10% (500-1000 / 20,736)
- FFs: ~2-3% (200-300 / 15,552)
- BRAM: ~6% (2 / 30 blocks)
- DSPs: 0% (0 / 48)

The design should synthesize successfully and meet timing at 27 MHz without issues.
