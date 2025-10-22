TASK: 
1) Implement a simple read handshake between @digital/ram/sp_ram.sv and @digital/sampler/vu_meter_6led.sv , modify both modules accordingly, and verify the integration through simulation.
2) Detect syntax errors, logic bugs, timing/reset issues, CDC problems, and sim-vs-synth mismatches across all files.
3) Fix the issues directly in the files using SystemVerilog best practices while preserving comments and style.
4) Run a full simulation to verify that all modules work correctly together.


Goals:
1) @digital/sampler/vu_meter_6led.sv must sequentially read samples from @digital/ram/sp_ram.sv buffer addresses (0..N-1).
2) @digital/ram/sp_ram.sv must only advance to the next address when it receives an ACK from @digital/sampler/vu_meter_6led.sv.
3) @digital/ram/sp_ram.sv must expose a `read_enable` signal that stays HIGH while reading is allowed, and goes LOW when all addresses have been read. 
4) @digital/sampler/vu_meter_6led.sv must only start reading again when `buffer_full` pulse.
5) Test the that the files work together, and implemet them in @digital/fpga_template/fpga_template.sv

### implementation in @digital/fpga_template/fpga_template.sv
   i2s_capture_24 reads data from mic_sd_0, and sends debug_sample_l to a ram module
   when the buffer has resived 256 samples i shifts buffer and then the vu_meter_6led can read data from the ram module.

### If the test fails
- Identify the root cause, fix it, and re-run simulation (at least two iterations).
- Document every iteration (what changed, and results).

### Required Artifacts
- Updated source files: @digital/ram/sp_ram.sv, @digital/sampler/vu_meter_6led.sv  
- Testbench
- Markdown summary: @docs/ram_vu_handshake_summary.md


### Permissions
- You may modify files freely, including moving or renaming them if needed (update references).  
- Keep comments and coding style consistent but modernize to SystemVerilog best practices.  
- Attempt automatic fixes and verification until the test passes.
