#!/usr/bin/env python3
"""
Embedded C Agent - Example Usage

This file contains example specifications and demonstrates how to use
the embedded C agent programmatically.
"""

import os
import sys
from pathlib import Path

# Add current directory to path
sys.path.insert(0, str(Path(__file__).parent))

from c_agent import EmbeddedCAgent


# Example specifications
EXAMPLES = {
    "ring_buffer": """
Create a ring buffer (circular buffer) module with:
- Fixed size of 256 bytes
- Support for uint8_t data
- Thread-safe operations (optional ISR safety)
- Functions: init, push, pop, is_empty, is_full, get_count
- Return error codes on overflow/underflow
- Use modulo arithmetic for wrap-around
""",

    "crc16": """
Create a CRC16 calculation module with:
- CRC-CCITT polynomial (0x1021)
- Function to calculate CRC for a byte array
- Function to calculate CRC byte-by-byte (for streaming)
- Optional lookup table for speed
- Include test vectors in comments
""",

    "debounce": """
Create a button debounce module with:
- Support for multiple buttons (up to 8)
- Configurable debounce time (in milliseconds)
- State machine based approach
- Functions: init, update (call periodically), get_state
- Detect button press and release events
- Return rising/falling edge detection
""",

    "led_blink": """
Create an LED blink controller with:
- Support for multiple LEDs
- Non-blocking operation
- Configurable on/off times per LED
- Functions: init, set_pattern, update (call in main loop)
- Support for one-shot and continuous patterns
- Use timing based on millisecond counter
""",

    "uart_buffer": """
Create a UART buffering module with:
- Separate TX and RX ring buffers
- Configurable buffer sizes (compile-time)
- ISR-safe functions for buffer access
- Functions: tx_push, tx_pop, rx_push, rx_pop
- Buffer status queries (full, empty, count)
- Overflow handling
""",

    "state_machine": """
Create a generic state machine framework with:
- State structure with entry, execute, and exit callbacks
- Event-driven transitions
- Maximum 16 states
- Functions: init, add_state, add_transition, process_event
- Current state tracking
- Guards for conditional transitions
""",

    "pid_controller": """
Create a PID controller implementation with:
- Proportional, Integral, and Derivative terms
- Configurable gains (Kp, Ki, Kd)
- Anti-windup for integral term
- Output limiting/clamping
- Functions: init, set_gains, update, reset
- Use fixed-point or float arithmetic
- Include setpoint and process variable inputs
""",

    "moving_average": """
Create a moving average filter with:
- Configurable window size (power of 2)
- Efficient implementation using ring buffer
- Support for int16_t and int32_t data
- Functions: init, add_sample, get_average
- Optional: weighted moving average
""",

    "event_queue": """
Create an event queue system with:
- Fixed-size queue for events
- Event structure with ID and optional data
- Functions: init, push_event, pop_event, is_empty
- Priority support (optional)
- ISR-safe operations
- Timestamp for events (optional)
""",

    "bit_manipulation": """
Create a bit manipulation utility module with:
- Set, clear, toggle, and test individual bits
- Extract and insert bit fields
- Count leading/trailing zeros
- Reverse bits in a word
- Parity calculation
- Portable implementation with macros
- Type-safe inline functions
""",
}


def run_example(example_name: str, compiler: str = "gcc", target: str = "generic"):
    """Run a specific example"""

    if example_name not in EXAMPLES:
        print(f"Unknown example: {example_name}")
        print(f"Available examples: {', '.join(EXAMPLES.keys())}")
        return False

    # Check for API key
    api_key = os.getenv("ANTHROPIC_API_KEY")
    if not api_key:
        print("Error: ANTHROPIC_API_KEY environment variable not set")
        print("Get your API key from: https://console.anthropic.com/")
        return False

    # Initialize agent
    agent = EmbeddedCAgent(api_key=api_key)

    # Run the example
    print(f"\n{'='*70}")
    print(f"Running example: {example_name}")
    print(f"{'='*70}\n")
    print(f"Specification:")
    print(EXAMPLES[example_name])
    print()

    try:
        result = agent.create_and_test(
            specification=EXAMPLES[example_name],
            module_name=example_name,
            target=target,
            compiler=compiler
        )

        if result["success"]:
            print(f"\n✓ Example '{example_name}' completed successfully!")
            return True
        else:
            print(f"\n✗ Example '{example_name}' failed")
            return False

    except Exception as e:
        print(f"\n✗ Error running example: {e}")
        import traceback
        traceback.print_exc()
        return False


def list_examples():
    """List all available examples"""
    print("Available Examples:")
    print("=" * 70)
    print()

    for name, spec in EXAMPLES.items():
        print(f"{name}:")
        # Print first line of spec
        first_line = spec.strip().split('\n')[0]
        print(f"  {first_line}")
        print()


def main():
    """Main entry point"""
    import argparse

    parser = argparse.ArgumentParser(
        description="Run Embedded C Agent examples",
        formatter_class=argparse.RawDescriptionHelpFormatter
    )

    parser.add_argument(
        "example",
        nargs="?",
        choices=list(EXAMPLES.keys()) + ["list"],
        help="Example to run (use 'list' to see all examples)"
    )

    parser.add_argument(
        "-c", "--compiler",
        choices=["gcc", "clang", "arm-none-eabi-gcc", "avr-gcc"],
        default="gcc",
        help="Compiler to use (default: gcc)"
    )

    parser.add_argument(
        "-t", "--target",
        choices=["generic", "cortex-m", "avr"],
        default="generic",
        help="Target platform (default: generic)"
    )

    parser.add_argument(
        "--all",
        action="store_true",
        help="Run all examples"
    )

    args = parser.parse_args()

    if args.example == "list" or (not args.example and not args.all):
        list_examples()
        return 0

    if args.all:
        # Run all examples
        results = {}
        for name in EXAMPLES.keys():
            success = run_example(name, args.compiler, args.target)
            results[name] = success

        # Summary
        print(f"\n{'='*70}")
        print("SUMMARY")
        print(f"{'='*70}\n")
        for name, success in results.items():
            status = "✓ PASS" if success else "✗ FAIL"
            print(f"{status} - {name}")
        print()

        all_passed = all(results.values())
        return 0 if all_passed else 1

    else:
        # Run single example
        success = run_example(args.example, args.compiler, args.target)
        return 0 if success else 1


if __name__ == "__main__":
    sys.exit(main())
