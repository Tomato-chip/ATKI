# SystemVerilog Agent - AI-Powered HDL Generator

An AI-powered tool that generates SystemVerilog modules and comprehensive testbenches from natural language descriptions, then automatically tests them using Verilator or iverilog.

## Quick Start

### 1. Prerequisites

**Required:**
- Python 3.6+
- Anthropic API key (get from https://console.anthropic.com/)
- At least one simulator:
  - Verilator (recommended): `sudo apt-get install verilator`
  - iverilog: `sudo apt-get install iverilog`

**Optional:**
- GTKWave for viewing waveforms: `sudo apt-get install gtkwave`

### 2. Setup

Set your API key:
```bash
export ANTHROPIC_API_KEY="your-api-key-here"
```

Add this to your `~/.bashrc` or `~/.zshrc` to make it permanent.

Check that simulators are available:
```bash
cd python_tools/sv_agent
./svgen --check
```

### 3. Generate Your First Module

```bash
cd python_tools/sv_agent

# Generate a simple counter
./svgen "Create an 8-bit up counter with enable"
```

That's it! The agent will:
1. Generate a SystemVerilog module
2. Create a self-checking testbench
3. Compile and run the simulation
4. Show you the results

## Usage

### Command Line Tool: `svgen`

The easiest way to use the agent:

```bash
./svgen "your module description"
```

**Examples:**

```bash
# Simple counter
./svgen "Create an 8-bit up/down counter with enable"

# PWM controller
./svgen "Create a PWM controller with 8-bit duty cycle input"

# FIFO buffer
./svgen "Create a synchronous FIFO with 16 entries and 8-bit data"

# Custom module name
./svgen -n my_counter "Create a simple counter"

# Use iverilog instead of verilator
./svgen -s iverilog "Create a shift register"

# Generate without testing
./svgen --no-test "Create an edge detector"
```

**Options:**
- `-s, --simulator`: Choose simulator (`verilator` or `iverilog`)
- `-n, --name`: Custom module name
- `--no-test`: Generate code without running simulation
- `--check`: Check available simulators
- `-v, --verbose`: Verbose output
- `--api-key`: Provide API key via command line

### Example Modules

Run pre-defined examples:

```bash
# List all examples
./examples.py list

# Run a specific example
./examples.py counter
./examples.py pwm
./examples.py fifo

# Run all examples
./examples.py --all
```

Available examples:
- **counter**: Up/down counter with overflow detection
- **pwm**: PWM controller
- **shift_register**: Parameterized shift register
- **fifo**: Synchronous FIFO buffer
- **debouncer**: Button debouncer
- **edge_detector**: Rising/falling edge detector
- **gray_counter**: Gray code counter

### Python API

Use the agent programmatically:

```python
from sv_agent import SystemVerilogAgent

# Initialize
agent = SystemVerilogAgent()

# Generate and test a module
result = agent.create_and_test(
    specification="""
    Create a PWM controller with:
    - 8-bit duty cycle input
    - Configurable counter width
    - Single PWM output
    """,
    simulator="verilator"
)

if result["success"]:
    print(f"Module created: {result['module_name']}")
    print(f"Files: {result['module_file']}, {result['tb_file']}")
```

**Advanced usage:**

```python
# Just generate module (no testbench)
module = agent.generate_module("Create a counter")
print(module["code"])

# Generate testbench for existing module
tb = agent.generate_testbench(module_code, module_name)

# Run simulation only
result = agent.run_simulation(
    module_file="generated/counter.sv",
    tb_file="generated/counter_tb.sv",
    simulator="verilator"
)
```

## Generated Files

All generated files are organized in:

```
digital/generated/      # SystemVerilog modules
sim/generated/          # Testbenches
sim/out/                # Simulation results and waveforms
```

Example output structure:
```
digital/generated/counter.sv          # Your module
sim/generated/counter_tb.sv           # Testbench
sim/out/counter_run/                  # Simulation directory
  ├── Vcounter_tb                     # Compiled simulator binary
  ├── counter_tb.vcd                  # Waveform file
  └── obj_dir/                        # Build artifacts
```

## Viewing Waveforms

After a successful simulation, view the waveform:

```bash
# The svgen tool tells you the path
gtkwave sim/out/counter_run/counter_tb.vcd
```

## Writing Good Specifications

The better your specification, the better the generated code:

**Good specification:**
```bash
./svgen "Create a UART transmitter with:
- 8-bit data input
- Configurable baud rate (parameter)
- Start and stop bits
- Busy flag output
- Active-low reset"
```

**Tips:**
- Be specific about bit widths
- Mention reset polarity (active-low/high)
- Specify synchronous vs asynchronous behavior
- List all inputs and outputs
- Mention any special features (overflow, underflow, etc.)
- Use bullet points for clarity

## Troubleshooting

### API Key Issues

```
Error: API key required!
```
**Solution:** Set `ANTHROPIC_API_KEY` environment variable

### Simulator Not Found

```
Error: verilator not found!
```
**Solution:** Install simulator:
```bash
sudo apt-get install verilator iverilog
```

### Compilation Errors

If the generated code doesn't compile:
1. Check the error messages in the output
2. Look at the generated files in `digital/generated/` and `sim/generated/`
3. Try regenerating with a more detailed specification
4. The agent learns from project style, so complex modules may need refinement

### Simulation Fails

If compilation works but simulation fails:
1. Check `sim/out/<module>_run/` for simulation output
2. View the waveform with gtkwave to debug
3. Look at the testbench in `sim/generated/`
4. The testbench is self-checking and will report specific failures

## Project Integration

The agent follows your project's coding conventions:
- Uses `logic` instead of `wire`/`reg`
- Active-low reset signals named `rst_ni`
- Input suffix `_i`, output suffix `_o`
- `always_ff` for sequential, `always_comb` for combinational
- Parameterized designs

Generated modules can be integrated into your FPGA builds:
1. Move the module from `digital/generated/` to appropriate directory
2. Add to your build system
3. Instantiate in your top-level design

## Advanced Features

### Adding Extra Source Files

If your module depends on other files:

```python
result = agent.create_and_test(
    specification="...",
    extra_files=["path/to/dependency.sv"]
)
```

### Custom Project Path

```python
agent = SystemVerilogAgent(project_root="/path/to/project")
```

### Using Different Claude Models

The agent uses Claude Sonnet 4.5 by default. You can modify the model in `sv_agent.py` if needed.

## How It Works

1. **Specification → Module**: The agent uses Claude to generate a SystemVerilog module based on your natural language description
2. **Module → Testbench**: It analyzes the module and creates a comprehensive self-checking testbench
3. **Compile → Simulate**: Runs Verilator or iverilog to compile and execute the test
4. **Report Results**: Shows test output, pass/fail status, and waveform location

## Examples Gallery

See `examples.py` for more examples:
- Counters (binary, Gray code)
- Communication (UART, SPI concepts)
- Memory (FIFO, shift registers)
- Signal processing (edge detectors, debouncers)
- PWM and timing circuits

## Tips for Best Results

1. **Start simple**: Begin with basic modules to understand the agent's output
2. **Iterate**: If the first result isn't perfect, refine your specification
3. **Review code**: Always review generated code before using in production
4. **Use waveforms**: GTKWave is invaluable for understanding behavior
5. **Learn from examples**: Run the example modules to see specification patterns

## Contributing

Ideas for extending the agent:
- Add formal verification support (using SymbiYosys)
- Generate UVM testbenches
- Support for additional simulators (Modelsim, Questa)
- Code coverage analysis
- Automatic documentation generation

## License

Part of the ATKI project. See main project README for license details.

## Support

For issues or questions:
1. Check this README
2. Look at examples in `examples.py`
3. Review generated code in `digital/generated/` and `sim/generated/`
4. Check the main CLAUDE.md in the project root

---

**Happy Hardware Design! 🚀**
