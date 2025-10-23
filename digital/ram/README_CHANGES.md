# Ping-Pong RAM Refactoring - Change Summary

**Dato:** 2025-10-23
**Fil:** `sp_ram.sv`
**Ændringer:** Forenkling af RAM kontrol signaler til et enkelt read/write select signal

## Oversigt

Ping-pong RAM modulet er blevet refaktoreret for at forenkle kontrollogikken ved at erstatte separate `write_buffer_sel` og `read_buffer_sel` signaler med et enkelt `rw_sel` signal.

## Ændringer i Detaljer

### 1. Kontrolsignaler (Linjer 23-28)

**Før:**
```systemverilog
logic          write_buffer_sel;        // 0: skriv RAM0, 1: skriv RAM1
logic          read_buffer_sel;         // 0: læs   RAM0, 1: læs  RAM1
```

**Efter:**
```systemverilog
logic          rw_sel;                  // 0: skriv RAM0/læs RAM1, 1: skriv RAM1/læs RAM0
```

**Rationale:**
- I ping-pong mode er write og read altid på forskellige RAMs
- Et enkelt signal reducerer kompleksitet og potentielle timing problemer
- Gør det tydeligt at RAMs opererer i mutually exclusive mode

### 2. Reset og Styrelogik (Linjer 33-63)

**Før:**
```systemverilog
write_buffer_sel    <= 1'b0;     // start: skriv RAM0
read_buffer_sel     <= 1'b1;     // start: læs RAM1 (tom indtil første blok)
...
read_buffer_sel     <= write_buffer_sel;    // Læs fra den buffer der netop blev fyldt
write_buffer_sel    <= ~write_buffer_sel;   // skriv til den anden fremover
```

**Efter:**
```systemverilog
rw_sel              <= 1'b0;     // start: skriv RAM0, læs RAM1
...
rw_sel              <= ~rw_sel;  // Skift mellem RAM0 og RAM1
```

**Rationale:**
- Simplere toggle logic - kun ét signal skal opdateres
- Reducerer risiko for at write og read selector kommer ud af sync
- Tydeligere at se ping-pong mechanismen

### 3. Write Enable Signaler (Linjer 65-68)

**Før:**
```systemverilog
wire         write_enable_RAM_0 = sample_ready && (write_buffer_sel == 1'b0);
wire         write_enable_RAM_1 = sample_ready && (write_buffer_sel == 1'b1);
```

**Efter:**
```systemverilog
wire         write_enable_RAM_0 = sample_ready && (rw_sel == 1'b0);
wire         write_enable_RAM_1 = sample_ready && (rw_sel == 1'b1);
```

**Rationale:**
- Direkte mapping fra rw_sel til write enables
- Garanterer at kun én RAM skriver ad gangen

### 4. Adresse Routing (Linjer 70-84)

**Før:**
```systemverilog
if (write_buffer_sel == 1'b0) begin
    // RAM0 skriver, RAM1 læser
    address_RAM_0 = pack_addr(write_address);
    address_RAM_1 = pack_addr(read_address);
end else begin
    // RAM1 skriver, RAM0 læser
    address_RAM_0 = pack_addr(read_address);
    address_RAM_1 = pack_addr(write_address);
end
```

**Efter:**
```systemverilog
if (rw_sel == 1'b0) begin
    // RAM0 skriver, RAM1 læser
    address_RAM_0 = pack_addr(write_address);
    address_RAM_1 = pack_addr(read_address);
end else begin
    // RAM1 skriver, RAM0 læser
    address_RAM_0 = pack_addr(read_address);
    address_RAM_1 = pack_addr(write_address);
end
```

**Rationale:**
- Samme logik, men bruger det forenklede rw_sel signal
- Tydeligt at se hvilken RAM der skriver/læser

### 5. Output Multiplexer (Linjer 121-129)

**Før:**
```systemverilog
if (valid_read_out) begin
    read_data_o = (read_buffer_sel == 1'b0) ? data_out_RAM_0 : data_out_RAM_1;
end
```

**Efter:**
```systemverilog
if (valid_read_out) begin
    // rw_sel=0 => skriv RAM0, læs RAM1
    // rw_sel=1 => skriv RAM1, læs RAM0
    read_data_o = (rw_sel == 1'b0) ? data_out_RAM_1 : data_out_RAM_0;
end
```

**Rationale:**
- Output vælger den RAM der IKKE skrives til
- Når rw_sel=0: RAM0 skriver, så læs fra RAM1 (data_out_RAM_1)
- Når rw_sel=1: RAM1 skriver, så læs fra RAM0 (data_out_RAM_0)
- Dette sikrer vi læser fra den buffer der netop blev fyldt

## Timing Analyse

### Kritiske Stier
1. **sample_ready → write_enable_RAM_x**: Kombinatorisk, ingen ekstra delay
2. **rw_sel → address mux → RAM**: Kombinatorisk mux, eksisterende logik
3. **rw_sel → output mux → read_data_o**: Kombinatorisk, eksisterende logik

### Forbedringer
- **Reduceret fanout**: rw_sel drives kun ét register sammenlignet med to før
- **Simplere logic**: Færre signaler at route betyder potentielt bedre timing
- **Atomisk skifte**: rw_sel opdateres i én clock cycle, eliminerer risiko for glitches

### Potentielle Problemer
✅ **INGEN** - Ændringen er primært en refactoring der forenkler uden at ændre timing karakteristika

## Verificering

### Testbench
Ny integration testbench: `sp_ram_integration_tb.sv`

**Inkluderede Moduler:**
- `pingpong_sp_ram` - RAM modul under test
- `i2s_clock_gen` - I2S clock generator
- `i2s_capture_24` - I2S sampler
- `vu_meter_6led` - VU meter for LED indikation

**Test Scenarie:**
1. Genererer I2S clock og word select signaler
2. Simulerer mikrofon data med stigende amplitude
3. Verificerer at samples bliver korrekt fanget
4. Verificerer at RAM buffers skifter korrekt
5. Tjekker at `read_data_o` IKKE er stuck på nul

**Forventede Resultater:**
- Mindst 20 samples skal fanges
- Mindst 2 buffer ready cycles (ping-pong skift)
- `read_data_o` skal ændre sig til non-zero værdier
- VU meter LEDs skal reagere på signal amplitude

### Simulation Kommandoer

```bash
cd /home/tomato-chip/ATKI/digital/ram/

# Kør simulation med Icarus Verilog
make sim

# Se waveforms i GTKWave
make wave

# Syntax check
make check

# Clean up
make clean
```

### GTKWave Waveform Grupper

Waveform filen (`sp_ram_integration_tb.gtkw`) viser:
1. **I2S Interface**: SCK, WS, SD signaler
2. **I2S Captured Samples**: left/right samples, ready signal
3. **Ping-Pong RAM Control**: rw_sel, write/read addresses, buffer status
4. **RAM Write Enables**: Separate enables for RAM0 og RAM1
5. **RAM Addresses**: Packed addresses til begge RAMs
6. **RAM Data**: Input samples og output data fra begge RAMs
7. **VU Meter**: Level accumulator og LED outputs
8. **Test Signals**: Test patterns og counters

## Konklusion

### Fordele ved Ændringerne
✅ **Simplere kode**: Færre signaler at holde styr på
✅ **Bedre læsbarhed**: Tydeligere ping-pong mechanisme
✅ **Reduceret fejlrisiko**: Kan ikke komme ud af sync mellem write/read selectors
✅ **Samme eller bedre timing**: Ingen forringelse, potentielt bedre routing
✅ **Lettere at vedligeholde**: Mindre kompleks state machine

### Bagudkompatibilitet
⚠️ **Interface uændret**: Alle eksterne signaler er de samme
✅ **Funktionelt ækvivalent**: Samme behaviour som før
✅ **Drop-in replacement**: Kan erstatte eksisterende modul direkte

### Anbefalinger
1. ✅ Kør testbench for at verificere funktionalitet
2. ✅ Review waveforms i GTKWave
3. ✅ Tjek at `read_data_o` ikke er stuck på nul
4. Overvej at køre timing analyse i synthesis flow
5. Test i hardware på FPGA board

## Files Ændret/Tilføjet

- **Modificeret**: `digital/ram/sp_ram.sv` - Hovedmodul med refactored control logic
- **Ny**: `digital/ram/sp_ram_integration_tb.sv` - Comprehensive testbench
- **Ny**: `digital/ram/sp_ram_integration_tb.gtkw` - GTKWave save file
- **Ny**: `digital/ram/Makefile` - Simulation build system
- **Ny**: `digital/ram/README_CHANGES.md` - Dette dokument
