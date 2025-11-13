# SystemVerilog Agent - Quick Start Guide

Generate SystemVerilog modules from natural language using AI!

## Setup (One-Time)

1. **Get API Key**: Sign up at https://console.anthropic.com/ and get your API key

2. **Set API Key**:
   ```bash
   export ANTHROPIC_API_KEY="your-api-key-here"
   ```

   Add to `~/.bashrc` to make permanent:
   ```bash
   echo 'export ANTHROPIC_API_KEY="your-api-key-here"' >> ~/.bashrc
   ```

3. **Install Simulator** (if not already installed):
   ```bash
   sudo apt-get install verilator
   ```

4. **Check Installation**:
   ```bash
   cd python_tools/sv_agent
   ./svgen --check
   ```

## Usage

### Quick Generation

```bash
cd python_tools/sv_agent

# Generate any module by describing it
./svgen "Create an 8-bit counter with enable"
```

### More Examples

```bash
# PWM controller
./svgen "Create a PWM controller with 8-bit duty cycle"

# FIFO buffer
./svgen "Create a 16-entry FIFO with 8-bit data width"

# Custom name
./svgen -n my_module "Create a shift register"

# Just generate code (don't test)
./svgen --no-test "Create an edge detector"
```

### Run Example Modules

```bash
# See all examples
./examples.py list

# Run an example
./examples.py counter
./examples.py pwm
./examples.py fifo
```

## Writing Specifications

Be specific for best results:

```bash
./svgen "Create a UART transmitter with:
- 8-bit data input
- Configurable baud rate (parameter)
- Start and stop bits
- Busy flag output
- Active-low reset"
```

## Output Files

Generated files go to:
- **Modules**: `digital/generated/your_module.sv`
- **Testbenches**: `sim/generated/your_module_tb.sv`
- **Waveforms**: `sim/out/your_module_run/your_module_tb.vcd`

View waveforms:
```bash
gtkwave sim/out/counter_run/counter_tb.vcd
```

## Common Commands

```bash
# Check simulators
./svgen --check

# Use iverilog instead of verilator
./svgen -s iverilog "your spec"

# See help
./svgen --help

# Run all examples
./examples.py --all
```

## Tips

1. **Start simple**: Try basic modules first (counters, shift registers)
2. **Be specific**: Include bit widths, reset type, special features
3. **Use examples**: Run `./examples.py list` to see patterns
4. **Review output**: Always check generated code before using
5. **Iterate**: Regenerate with refined specs if needed

## Full Documentation

See `python_tools/sv_agent/README.md` for complete documentation.

---

**Quick Example Session:**

```bash
cd python_tools/sv_agent

# Generate a counter
./svgen "Create an 8-bit up/down counter with overflow flag"

# View the generated code
cat ../../digital/generated/counter.sv

# View the testbench
cat ../../sim/generated/counter_tb.sv

# View the waveform
gtkwave ../../sim/out/counter_run/counter_tb.vcd
```

That's it! Happy hardware design! 🚀
