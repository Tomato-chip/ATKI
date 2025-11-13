# Embedded C Agent - Quick Start Guide

Generate embedded C code from natural language using AI!

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

3. **Install Compiler** (if not already installed):
   ```bash
   sudo apt-get install gcc
   ```

4. **Check Installation**:
   ```bash
   cd python_tools/c_agent
   ./cgen --check
   ```

## Usage

### Quick Generation

```bash
cd python_tools/c_agent

# Generate any module by describing it
./cgen "Create a ring buffer for uint8_t with 256 bytes"
```

### More Examples

```bash
# CRC module
./cgen "Create a CRC16 calculation module with CCITT polynomial"

# Button debounce
./cgen "Create a debounce module for 8 buttons with 50ms debounce time"

# State machine
./cgen "Create a generic state machine framework"

# For ARM Cortex-M
./cgen -t cortex-m "Create a GPIO driver for LED control"

# Custom name
./cgen -n my_buffer "Create a circular buffer"

# Just generate code (don't compile)
./cgen --no-test "Create a UART buffer module"
```

### Run Example Modules

```bash
# See all examples
./examples.py list

# Run an example
./examples.py ring_buffer
./examples.py crc16
./examples.py debounce
./examples.py pid_controller
```

## Writing Specifications

Be specific for best results:

```bash
./cgen "Create a ring buffer module with:
- Fixed size of 256 bytes
- uint8_t data type
- Functions: init, push, pop, is_empty, is_full, count
- ISR-safe operations
- Return error codes on overflow/underflow"
```

## Output Files

Generated files go to:
- **Modules**: `embedded/generated/module_name/module_name.h` and `.c`
- **Tests**: `embedded/tests/test_module_name.c`
- **Binaries**: `embedded/tests/out/module_name/test_module_name`

Run tests manually:
```bash
cd embedded/tests/out/ring_buffer
./test_ring_buffer
```

## Common Commands

```bash
# Check compilers
./cgen --check

# Use different compiler
./cgen -c clang "your spec"

# For ARM Cortex-M
./cgen -t cortex-m -c arm-none-eabi-gcc "your spec"

# For AVR (Arduino)
./cgen -t avr -c avr-gcc "your spec"

# See help
./cgen --help

# Run all examples
./examples.py --all
```

## Target Platforms

- **generic** (default): Standard C99, runs on host
- **cortex-m**: ARM Cortex-M with CMSIS
- **avr**: AVR (Arduino-compatible)

## Example Use Cases

**Data Structures:**
```bash
./cgen "Create a linked list for uint32_t values"
./cgen "Create a hash table with string keys"
```

**Communication:**
```bash
./cgen "Create a packet protocol with header, CRC, and payload"
./cgen "Create a simple command parser for UART"
```

**Hardware Drivers:**
```bash
./cgen -t cortex-m "Create an I2C master driver"
./cgen -t avr "Create a PWM controller for servos"
```

**Algorithms:**
```bash
./cgen "Create a PID controller with anti-windup"
./cgen "Create a moving average filter with window size 16"
```

**Utilities:**
```bash
./cgen "Create bit manipulation utilities"
./cgen "Create a circular buffer statistics module"
```

## Tips

1. **Start simple**: Try basic modules first (ring buffer, CRC)
2. **Be specific**: Include data types, sizes, function names
3. **Use examples**: Run `./examples.py list` to see patterns
4. **Review output**: Check generated code in `embedded/generated/`
5. **Iterate**: Regenerate with refined specs if needed
6. **Test thoroughly**: Generated tests are starting points

## Full Documentation

See `python_tools/c_agent/README.md` for complete documentation.

---

**Quick Example Session:**

```bash
cd python_tools/c_agent

# Generate a ring buffer
./cgen "Create a ring buffer for uint8_t with 256 bytes"

# View the generated files
ls ../../embedded/generated/ring_buffer/
cat ../../embedded/generated/ring_buffer/ring_buffer.h
cat ../../embedded/generated/ring_buffer/ring_buffer.c

# View the test
cat ../../embedded/tests/test_ring_buffer.c

# Run the test
../../embedded/tests/out/ring_buffer/test_ring_buffer
```

## Integration with Your Project

To use generated modules in your embedded project:

```bash
# Copy the module
cp embedded/generated/ring_buffer/* your_project/src/

# Add to your Makefile
# SRCS += src/ring_buffer.c

# Use in your code
#include "ring_buffer.h"
```

That's it! Happy embedded programming! 🚀
