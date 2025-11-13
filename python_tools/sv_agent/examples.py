#!/usr/bin/env python3
"""
SystemVerilog Agent - Example Usage

This file contains example specifications and demonstrates how to use
the SystemVerilog agent programmatically.
"""

import os
import sys
from pathlib import Path

# Add current directory to path
sys.path.insert(0, str(Path(__file__).parent))

from sv_agent import SystemVerilogAgent


# Example specifications
EXAMPLES = {
    "counter": """
Create an 8-bit up/down counter with:
- Clock and active-low reset
- Enable signal
- Up/down control (1=up, 0=down)
- 8-bit count output
- Overflow flag (when counting up past 255)
- Underflow flag (when counting down past 0)
""",

    "pwm": """
Create a PWM (Pulse Width Modulation) controller with:
- Configurable counter width (default 8 bits)
- 8-bit duty cycle input (0-255 for 0-100%)
- Single PWM output signal
- Synchronous design with active-low reset
- Counter should wrap around to create PWM waveform
""",

    "shift_register": """
Create a parameterized shift register with:
- Configurable width (default 8 bits)
- Serial input and serial output
- Parallel data output
- Load enable (to load parallel data)
- Shift enable
- Left/right shift control
- Active-low synchronous reset
""",

    "fifo": """
Create a synchronous FIFO buffer with:
- Configurable depth (default 16) and width (default 8 bits)
- Write interface: write enable, write data
- Read interface: read enable, read data
- Status signals: full flag, empty flag, data count
- Single clock domain
- Active-low synchronous reset
""",

    "debouncer": """
Create a button debouncer with:
- Configurable debounce time (default 10ms at 27MHz clock)
- Raw button input
- Debounced output (single pulse on press)
- Use a counter-based approach
- Active-low reset
""",

    "edge_detector": """
Create an edge detector that:
- Detects rising and falling edges on an input signal
- Outputs single-cycle pulses for rising and falling edges
- Has separate outputs for rising_edge and falling_edge
- Works synchronously with clock
- Active-low reset
""",

    "gray_counter": """
Create a Gray code counter:
- Configurable width (default 4 bits)
- Counts in Gray code sequence
- Enable input
- Gray code output
- Also provide binary output for verification
- Active-low synchronous reset
""",
}


def run_example(example_name: str, simulator: str = "verilator"):
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
    agent = SystemVerilogAgent(api_key=api_key)

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
            simulator=simulator
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
        description="Run SystemVerilog Agent examples",
        formatter_class=argparse.RawDescriptionHelpFormatter
    )

    parser.add_argument(
        "example",
        nargs="?",
        choices=list(EXAMPLES.keys()) + ["list"],
        help="Example to run (use 'list' to see all examples)"
    )

    parser.add_argument(
        "-s", "--simulator",
        choices=["verilator", "iverilog"],
        default="verilator",
        help="Simulator to use (default: verilator)"
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
            success = run_example(name, args.simulator)
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
        success = run_example(args.example, args.simulator)
        return 0 if success else 1


if __name__ == "__main__":
    sys.exit(main())
