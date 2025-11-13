# Embedded C Agent - AI-Powered C Code Generator

An AI-powered tool that generates embedded C modules (.h/.c files) and comprehensive unit tests from natural language descriptions, then automatically compiles and tests them.

## Quick Start

### 1. Prerequisites

**Required:**
- Python 3.6+
- Anthropic API key (get from https://console.anthropic.com/)
- GCC compiler: `sudo apt-get install gcc`

**Optional:**
- Clang: `sudo apt-get install clang`
- ARM cross-compiler: `sudo apt-get install gcc-arm-none-eabi`
- AVR cross-compiler: `sudo apt-get install gcc-avr`

### 2. Setup

Set your API key:
```bash
export ANTHROPIC_API_KEY="your-api-key-here"
```

Add to `~/.bashrc` for persistence.

Check that compilers are available:
```bash
cd python_tools/c_agent
./cgen --check
```

### 3. Generate Your First Module

```bash
cd python_tools/c_agent

# Generate a ring buffer
./cgen "Create a ring buffer for uint8_t with 256 bytes"
```

The agent will:
1. Generate header (.h) and source (.c) files
2. Create comprehensive unit tests
3. Compile everything
4. Run the tests
5. Show you the results

## Usage

### Command Line Tool: `cgen`

```bash
./cgen "your module description"
```

**Examples:**

```bash
# Ring buffer
./cgen "Create a ring buffer for uint8_t data with 256 bytes"

# CRC calculation
./cgen "Create a CRC16 module with CCITT polynomial"

# Button debounce
./cgen "Create a debounce module for 8 buttons"

# For ARM Cortex-M
./cgen -t cortex-m "Create a GPIO driver for LED control"

# Custom name
./cgen -n my_buffer "Create a circular buffer"

# Generate without testing
./cgen --no-test "Create a UART buffer module"

# Use different compiler
./cgen -c clang "Create a state machine framework"
```

**Options:**
- `-t, --target`: Target platform (`generic`, `cortex-m`, `avr`)
- `-c, --compiler`: Compiler (`gcc`, `clang`, `arm-none-eabi-gcc`, `avr-gcc`)
- `-n, --name`: Custom module name
- `--no-test`: Generate without compiling/testing
- `--check`: Check available compilers
- `-v, --verbose`: Verbose output

### Example Modules

Run pre-defined examples:

```bash
# List all examples
./examples.py list

# Run a specific example
./examples.py ring_buffer
./examples.py crc16
./examples.py debounce

# Run all examples
./examples.py --all
```

**Available Examples:**
- **ring_buffer**: Circular buffer implementation
- **crc16**: CRC16 calculation with lookup table
- **debounce**: Button debounce with state machine
- **led_blink**: Non-blocking LED controller
- **uart_buffer**: UART TX/RX buffering (ISR-safe)
- **state_machine**: Generic state machine framework
- **pid_controller**: PID controller implementation
- **moving_average**: Moving average filter
- **event_queue**: Event queue system
- **bit_manipulation**: Bit manipulation utilities

### Python API

Use the agent programmatically:

```python
from c_agent import EmbeddedCAgent

# Initialize
agent = EmbeddedCAgent()

# Generate and test a module
result = agent.create_and_test(
    specification="""
    Create a ring buffer with:
    - 256 byte capacity
    - uint8_t data type
    - ISR-safe operations
    """,
    target="generic",
    compiler="gcc"
)

if result["success"]:
    print(f"Module: {result['module_name']}")
    print(f"Header: {result['header_file']}")
    print(f"Source: {result['source_file']}")
    print(f"Test:   {result['test_file']}")
```

**Advanced usage:**

```python
# Just generate module (no tests)
module = agent.generate_module(
    "Create a CRC16 module",
    target="cortex-m"
)
print(module["header"])
print(module["source"])

# Generate tests for existing module
test = agent.generate_test(header_code, source_code, module_name)

# Compile and test only
result = agent.compile_and_test(
    module_name="ring_buffer",
    compiler="gcc"
)
```

## Generated Files

Files are organized in:

```
embedded/generated/      # C modules (.h/.c)
embedded/tests/          # Unit tests
embedded/tests/out/      # Test binaries and results
```

Example structure:
```
embedded/generated/ring_buffer/
  ├── ring_buffer.h              # Header file
  └── ring_buffer.c              # Source file
embedded/tests/
  ├── test_ring_buffer.c         # Unit test
  └── out/ring_buffer/
      └── test_ring_buffer       # Test binary
```

## Writing Good Specifications

Be specific for best results:

**Good specification:**
```bash
./cgen "Create a ring buffer module with:
- Fixed size of 256 bytes
- uint8_t data type
- Functions: init, push, pop, is_empty, is_full, count
- ISR-safe operations using critical sections
- Return error codes on overflow/underflow
- Use modulo arithmetic for efficiency"
```

**Tips:**
- Specify data types and sizes
- List all required functions
- Mention thread/ISR safety requirements
- Include error handling approach
- Specify any performance requirements
- Use bullet points for clarity

## Target Platforms

### Generic (default)
```bash
./cgen "Create a CRC module"
```
- Standard C99 code
- No platform-specific dependencies
- Portable across architectures

### ARM Cortex-M
```bash
./cgen -t cortex-m "Create a GPIO driver"
```
- CMSIS conventions
- Interrupt-aware code
- Memory-mapped I/O patterns
- Use with: `gcc` or `arm-none-eabi-gcc`

### AVR (Arduino)
```bash
./cgen -t avr "Create a timer module"
```
- AVR-specific includes
- ISR macros
- 8-bit optimizations
- Use with: `gcc` or `avr-gcc`

## Compilers

### GCC (default)
```bash
./cgen "..."  # Uses gcc by default
```
- Compiles and runs tests on host
- Best for algorithm development and testing

### ARM Cross-Compiler
```bash
./cgen -c arm-none-eabi-gcc -t cortex-m "..."
```
- Compiles for ARM targets
- Doesn't run tests (cross-compiled)
- Validates code compiles for target

### AVR Cross-Compiler
```bash
./cgen -c avr-gcc -t avr "..."
```
- Compiles for AVR (Arduino)
- Doesn't run tests (cross-compiled)
- Validates code for embedded target

## Test Framework

Generated tests use a simple, dependency-free framework:

```c
#include "module.h"
#include <stdio.h>
#include <assert.h>

static int test_count = 0;
static int test_passed = 0;

#define TEST_ASSERT(condition, message) do {
    test_count++;
    if (condition) {
        test_passed++;
        printf("  [PASS] %s\n", message);
    } else {
        printf("  [FAIL] %s\n", message);
    }
} while(0)

static void test_function_name(void) {
    printf("\nTest: function_name\n");
    // Tests here
    TEST_ASSERT(result == expected, "description");
}

int main(void) {
    test_function_name();
    // More tests...

    printf("Passed: %d/%d\n", test_passed, test_count);
    return (test_passed == test_count) ? 0 : 1;
}
```

## Coding Conventions

Generated code follows embedded C best practices:

**Code Style:**
- stdint.h types (`uint8_t`, `uint16_t`, etc.)
- Include guards in headers
- Doxygen-style comments
- `const` for read-only parameters
- `static` for internal functions
- Defensive programming (parameter validation)

**Example:**
```c
// Header file
#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Initialize the ring buffer
 * @return 0 on success, -1 on error
 */
int ring_buffer_init(void);

/**
 * @brief Push data to buffer
 * @param data Data byte to push
 * @return 0 on success, -1 if full
 */
int ring_buffer_push(uint8_t data);

#endif // RING_BUFFER_H
```

## Integration with Projects

To use generated modules in your project:

1. **Copy files**:
   ```bash
   cp embedded/generated/ring_buffer/* your_project/src/
   ```

2. **Add to build system**:
   ```makefile
   SRCS += src/ring_buffer.c
   INCS += -Isrc
   ```

3. **Include in your code**:
   ```c
   #include "ring_buffer.h"
   ```

## Troubleshooting

### API Key Issues
```
Error: API key required!
```
**Solution:** Set `ANTHROPIC_API_KEY` environment variable

### Compiler Not Found
```
Error: gcc not found!
```
**Solution:**
```bash
sudo apt-get install gcc
```

### Compilation Errors
If generated code doesn't compile:
1. Check compiler output in the error message
2. Review generated files in `embedded/generated/`
3. Try with more detailed specification
4. Check for platform-specific requirements

### Test Failures
If tests fail:
1. Review test output for specific failures
2. Check test file in `embedded/tests/`
3. Run the test binary manually for detailed output
4. Refine specification to clarify requirements

## Common Use Cases

### 1. Data Structures
```bash
./cgen "Create a linked list for uint32_t with dynamic allocation"
./cgen "Create a hash table with string keys and int values"
```

### 2. Communication Protocols
```bash
./cgen "Create a simple packet protocol with CRC"
./cgen "Create a Modbus RTU frame parser"
```

### 3. Hardware Drivers
```bash
./cgen -t cortex-m "Create an I2C master driver"
./cgen -t avr "Create a PWM controller for motor speed"
```

### 4. Signal Processing
```bash
./cgen "Create a median filter with window size 5"
./cgen "Create a Kalman filter for sensor fusion"
```

### 5. Utilities
```bash
./cgen "Create string utilities for embedded systems"
./cgen "Create a printf-like formatter for fixed buffer"
```

## Advanced Features

### Multi-File Projects

If your module depends on other files:

```python
result = agent.create_and_test(
    specification="...",
    extra_files=["common/types.c", "common/utils.c"]
)
```

### Custom Compiler Flags

```python
result = agent.compile_and_test(
    module_name="my_module",
    compiler="gcc",
    cflags=["-Wall", "-O2", "-DDEBUG"]
)
```

### Cross-Platform Testing

Generate once, compile for multiple targets:

```bash
# Generate module
./cgen --no-test "Create a CRC module"

# Test on host
cd embedded/generated/crc
gcc -I.. ../crc/crc.c ../../tests/test_crc.c -o test_crc
./test_crc

# Cross-compile for ARM
arm-none-eabi-gcc -I.. ../crc/crc.c -c -o crc.o
```

## Examples Gallery

See `examples.py` for implementations of:
- **Data structures**: Ring buffers, queues, stacks
- **Algorithms**: CRC, filters, PID controllers
- **Hardware**: Debounce, LED control, UART buffering
- **Frameworks**: State machines, event systems
- **Utilities**: Bit manipulation, string handling

## Tips for Best Results

1. **Start simple**: Test with basic modules first
2. **Be specific**: Detail requirements clearly
3. **Review code**: Always review generated code
4. **Iterate**: Refine specifications as needed
5. **Test early**: Generate tests help catch issues
6. **Document**: Add comments to generated code you keep

## Future Enhancements

Ideas for extending the agent:
- Integration with CMake/Make build systems
- Support for additional test frameworks (Unity, CppUTest)
- Code coverage analysis (gcov)
- Static analysis integration (cppcheck, clang-tidy)
- MISRA C compliance checking
- Automatic documentation generation (Doxygen)

## License

Part of the ATKI project. See main project README for license details.

---

**Happy Embedded Programming! 🚀**
