# Verificering af valid_read_out Signal

## Analyse af sp_ram.sv

### Signal Definition (linje 26)
```systemverilog
logic valid_read_out;
```

### Signal Brug

#### 1. Initialization (linje 38)
```systemverilog
if (!rst_ni) begin
    valid_read_out <= 1'b0;
```
**Status:** ✅ Reset til 0

#### 2. Set Condition (linje 58)
```systemverilog
if (buffer_full) begin
    buffer_ready_o  <= 1'b1;
    valid_read_out  <= 1'b1;      // <-- SÆTTES TIL 1
    read_address    <= '0;
    rw_sel          <= ~rw_sel;
end
```
**Status:** ✅ Sættes til 1 når første buffer er fyldt

#### 3. Clear Condition
**PROBLEM:** ❌ **INGEN KODE** der clearer `valid_read_out` tilbage til 0!

#### 4. Usage in Read Address Logic (linje 50-53)
```systemverilog
if (sample_ready && valid_read_out) begin
    if (read_address == DEPTH-1) read_address <= '0;
    else                         read_address <= read_address + 1'b1;
end
```
**Effekt:** Read address incrementer kun når `valid_read_out == 1`

#### 5. Usage in Output Mux (linje 124-128)
```systemverilog
always_comb begin
    read_data_o = '0;
    if (valid_read_out) begin
        read_data_o = (rw_sel == 1'b0) ? data_out_RAM_1 : data_out_RAM_0;
    end
end
```
**Effekt:** Output er kun valid når `valid_read_out == 1`, ellers 0

---

## Behavior Analyse

### State Transition Diagram for valid_read_out

```
        Reset
          |
          v
    ┌────────────┐
    │ valid = 0  │  <-- Initial state
    │ output = 0 │
    └────────────┘
          |
          | buffer_full (første gang)
          v
    ┌────────────┐
    │ valid = 1  │  <-- Terminal state
    │ output ≠ 0 │
    └────────────┘
          |
          | (forbliver 1 for evigt)
          v
        ...
```

### Timing Diagram

```
Cycle:        0    1    2  ...  9   10   11   12  ...  19   20   21   22
              ├────┼────┼───────┼────┼────┼────┼───────┼────┼────┼────┤
sample_ready: ─┬──┬┬──┬┬──┬┬──┬┬──┬┬──┬┬──┬┬──┬┬──┬┬──┬┬──┬┬──┬┬──┬┬──┬
              ─┘  └┘  └┘  └┘  └┘  └┘  └┘  └┘  └┘  └┘  └┘  └┘  └┘  └┘  └

write_addr:    0    1    2  ...  8    9    0    1  ...  8    9    0    1

buffer_full:  ─────────────────────┬────┐─────────────────┬────┐────────
                                   └────┘                 └────┘

valid_read    ─────────────────────┬─────────────────────────────────────
  _out:                            └─────────────────────────────────────
                                   ^
                                   | Sættes til 1, forbliver 1

read_addr:    x    x    x  ...  x    0    1    2  ...  8    9    0    1
                                   ^
                                   | Starter increment

read_data_o:  0    0    0  ...  0  [D0] [D1] [D2] ... [D8] [D9] [D0] [D1]
                                   ^
                                   | Starter output af data
```

---

## Er Dette et Problem?

### Scenario 1: Kontinuerlig Streaming (Current Design Intent)
**Brugscase:** Data kommer kontinuerligt fra sampler, consumer læser kontinuerligt

**Behavior:**
1. ✅ System starter: `valid_read_out = 0`, ingen output
2. ✅ Første buffer fyldes (10 samples)
3. ✅ `valid_read_out` → 1, read starter
4. ✅ Ping-pong fortsætter kontinuerligt
5. ✅ Output er altid valid efter første buffer

**Konklusion:** ✅ **KORREKT BEHAVIOR** for streaming use-case

### Scenario 2: Start/Stop med Pause (Potentielt Problem)
**Brugscase:** FFT consumer der ønsker at pause mellem blokke

**Behavior:**
1. ✅ Første buffer færdig → `valid_read_out = 1`
2. ❌ FFT consumer færdig med processing
3. ❌ **PROBLEM:** Ingen måde at pause/stop read output
4. ❌ `valid_read_out` forbliver 1, data fortsætter

**Konklusion:** ❌ **MANGLER HANDSHAKING** hvis pause er nødvendigt

---

## Sammenligning med pingpong_buffer_sp.sv

### Fuld Version (pingpong_buffer_sp.sv)
- ✅ State machine med `RD_IDLE` og `RD_ACTIVE` states
- ✅ `buf_take_i` signal for handshaking
- ✅ `rd_valid_o` styres af state machine
- ✅ Kan pause mellem buffers

### Simpel Version (sp_ram.sv)
- ⚠️ Ingen state machine
- ⚠️ Ingen handshaking
- ⚠️ `valid_read_out` er sticky (én gang sat, aldrig cleared)
- ⚠️ Antager kontinuerlig streaming

---

## Potentielle Problemer

### Problem 1: Første Buffer Read
**Timing:**
- Cycle 10: `buffer_full = 1`, `valid_read_out` → 1, `read_address` → 0
- Cycle 11: `read_address` incrementer (hvis `sample_ready`)

**Spørgsmål:** Bliver første sample i buffer korrekt læst?

**Analyse:**
```systemverilog
// Cycle 10: buffer_full triggers
buffer_ready_o  <= 1'b1;          // Pulser
valid_read_out  <= 1'b1;          // Sættes
read_address    <= '0;            // Reset til 0
rw_sel          <= ~rw_sel;       // Skift buffer (0→1)

// Output mux (kombinatorisk)
if (valid_read_out) begin
    read_data_o = (rw_sel == 1'b0) ? data_out_RAM_1 : data_out_RAM_0;
end
```

**Problem:** ⚠️ **RACE CONDITION**
- `valid_read_out` og `rw_sel` opdateres samtidigt
- Output mux læser potentielt fra forkert RAM i én cycle

**Fix:** Se nedenfor

### Problem 2: Read Address Increment Timing
**Kode:**
```systemverilog
if (sample_ready && valid_read_out) begin
    if (read_address == DEPTH-1) read_address <= '0;
    else                         read_address <= read_address + 1'b1;
end
```

**Behavior:** Read address incrementer i takt med `sample_ready`
- ✅ Godt: Synkroniseret med write rate
- ⚠️ Potentielt problem: Læser samtidigt med at næste sample skrives
- ⚠️ Hvis write og read er synkrone, risiko for read-before-write i samme clock

---

## Løsningsforslag

### Option 1: Lad det være (For Streaming Use-Case)
Hvis modulet KUN bruges til kontinuerlig streaming:
- ✅ Behavior er korrekt
- ✅ `valid_read_out` forbliver 1 efter første buffer (intended)
- ⚠️ Men fix race condition ved buffer swap

### Option 2: Fix Race Condition ved Buffer Swap

**Problem:** `valid_read_out` og `rw_sel` opdateres samtidigt

**Løsning:** Brug registered version af `rw_sel` til output mux

```systemverilog
// Add registered read buffer selector
logic rw_sel_read;

always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
        rw_sel_read <= 1'b1;  // Start: read from RAM1
    end else if (buffer_full) begin
        rw_sel_read <= ~rw_sel;  // Update AFTER swap
    end
end

// Output mux uses rw_sel_read (one cycle delayed)
always_comb begin
    read_data_o = '0;
    if (valid_read_out) begin
        read_data_o = (rw_sel_read == 1'b0) ? data_out_RAM_1 : data_out_RAM_0;
    end
end
```

**Effekt:** Output mux peker på korrekt (fyldt) buffer uden race condition

### Option 3: Add Handshaking (For FFT Use-Case)

Hvis FFT eller anden consumer har brug for pause capability:

```systemverilog
// Add input
input logic read_enable_i;  // Consumer ready to read

// Modify read address increment
if (sample_ready && valid_read_out && read_enable_i) begin
    ...
end

// Modify output
if (valid_read_out && read_enable_i) begin
    read_data_o = ...
end
```

---

## Anbefaling

### Umiddelbar Fix (Højeste Prioritet)
✅ **FIX RACE CONDITION** mellem `valid_read_out` og `rw_sel` ved buffer swap

Dette er en **timing hazard** der kan forårsage forkert data output i én cycle.

### Langsigtet (Afhænger af Use-Case)
1. Hvis consumer er FFT med burst reads → Tilføj handshaking
2. Hvis consumer er kontinuerlig streaming → Behold simpel design

### Test Cases
1. ✅ Verificer at første sample i hver buffer læses korrekt
2. ✅ Verificer at `read_data_o` ikke glitcher ved buffer swap
3. ✅ Verificer at ping-pong virker over multiple cycles
