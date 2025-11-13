#!/usr/bin/env python3
"""
Embedded C Agent - AI-powered embedded C code generator and tester

This agent can:
- Generate embedded C modules from natural language specifications
- Create comprehensive unit tests
- Compile and run tests for different targets
- Provide detailed test results
"""

import anthropic
import subprocess
import os
import re
from pathlib import Path
from typing import Dict, Optional, Tuple, List


class EmbeddedCAgent:
    """AI agent for generating and testing embedded C code"""

    def __init__(self, api_key: Optional[str] = None, project_root: Optional[Path] = None):
        """
        Initialize the Embedded C agent

        Args:
            api_key: Anthropic API key (defaults to ANTHROPIC_API_KEY env var)
            project_root: Project root directory (defaults to parent of python_tools)
        """
        self.api_key = api_key or os.getenv("ANTHROPIC_API_KEY")
        if not self.api_key:
            raise ValueError(
                "API key required. Set ANTHROPIC_API_KEY environment variable or "
                "pass api_key parameter"
            )

        self.client = anthropic.Anthropic(api_key=self.api_key)

        # Set up project paths
        if project_root is None:
            self.project_root = Path(__file__).parent.parent.parent
        else:
            self.project_root = Path(project_root)

        self.embedded_dir = self.project_root / "embedded"
        self.generated_dir = self.embedded_dir / "generated"
        self.tests_dir = self.embedded_dir / "tests"

        # Create directories if they don't exist
        self.generated_dir.mkdir(parents=True, exist_ok=True)
        self.tests_dir.mkdir(parents=True, exist_ok=True)

    def generate_module(
        self,
        specification: str,
        target: str = "generic",
        include_context: bool = True
    ) -> Dict[str, str]:
        """
        Generate an embedded C module from natural language specification

        Args:
            specification: Natural language description of the desired module
            target: Target platform (generic, cortex-m, avr)
            include_context: Include project-specific coding style context

        Returns:
            Dictionary with 'header', 'source', and 'module_name' keys
        """
        context = ""
        if include_context:
            context = """
Follow these embedded C best practices:
- Use stdint.h types (uint8_t, uint16_t, etc.)
- Add include guards in headers
- Document functions with Doxygen-style comments
- Use const for read-only parameters
- Implement defensive programming (parameter validation)
- Minimize global variables
- Use static for internal functions
- Keep functions focused and small
"""

        target_context = ""
        if target == "cortex-m":
            target_context = """
Target: ARM Cortex-M
- Use CMSIS conventions where applicable
- Consider interrupt safety
- Use volatile for hardware registers
- Memory-mapped I/O access patterns
"""
        elif target == "avr":
            target_context = """
Target: AVR (Arduino-compatible)
- Include <avr/io.h> for register definitions
- Use ISR() macro for interrupts
- Consider 8-bit architecture limitations
"""

        prompt = f"""Generate an embedded C module based on this specification:

{specification}

{context}
{target_context}

Generate both a header file (.h) and source file (.c).

Header file should include:
- Include guards
- Function prototypes
- Type definitions and structs
- Doxygen-style documentation
- Constants and macros

Source file should include:
- The header file
- Function implementations
- Static helper functions if needed
- Clear comments

Example structure:

**Header (module_name.h):**
```c
#ifndef MODULE_NAME_H
#define MODULE_NAME_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Brief description
 * @param param1 Description
 * @return Return value description
 */
void module_function(uint8_t param1);

#endif // MODULE_NAME_H
```

**Source (module_name.c):**
```c
#include "module_name.h"

void module_function(uint8_t param1) {
    // Implementation
}
```

Return the header and source code in this format:
HEADER_START
[header code here]
HEADER_END
SOURCE_START
[source code here]
SOURCE_END"""

        response = self.client.messages.create(
            model="claude-sonnet-4-5-20250929",
            max_tokens=6000,
            messages=[{"role": "user", "content": prompt}]
        )

        code = response.content[0].text
        header, source = self._parse_header_source(code)
        module_name = self._extract_module_name(header or source)

        return {
            "header": header,
            "source": source,
            "module_name": module_name
        }

    def generate_test(
        self,
        header_code: str,
        source_code: str,
        module_name: str
    ) -> str:
        """
        Generate unit tests for the C module

        Args:
            header_code: Header file content
            source_code: Source file content
            module_name: Name of the module

        Returns:
            Test file code
        """
        prompt = f"""Generate comprehensive unit tests for this C module:

**Header ({module_name}.h):**
```c
{header_code}
```

**Source ({module_name}.c):**
```c
{source_code}
```

Requirements:
1. Use a simple test framework (minimal dependencies)
2. Test all public functions
3. Include edge cases and boundary conditions
4. Use descriptive test names
5. Print clear pass/fail messages
6. Return 0 on success, non-zero on failure

Use this test framework structure:

```c
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "{module_name}.h"

// Test utilities
static int test_count = 0;
static int test_passed = 0;

#define TEST_ASSERT(condition, message) do {{ \\
    test_count++; \\
    if (condition) {{ \\
        test_passed++; \\
        printf("  [PASS] %s\\n", message); \\
    }} else {{ \\
        printf("  [FAIL] %s\\n", message); \\
    }} \\
}} while(0)

// Test functions
static void test_function_name(void) {{
    printf("\\nTest: function_name\\n");
    // Test implementation
    TEST_ASSERT(result == expected, "description");
}}

int main(void) {{
    printf("================================================================================\\n");
    printf("Testing {module_name.upper()}\\n");
    printf("================================================================================\\n");

    // Run tests
    test_function_name();
    // ... more tests

    // Results
    printf("\\n================================================================================\\n");
    printf("TEST RESULTS\\n");
    printf("================================================================================\\n");
    printf("Passed: %d/%d tests\\n", test_passed, test_count);

    if (test_passed == test_count) {{
        printf("{module_name.upper()}: PASS\\n");
        return 0;
    }} else {{
        printf("{module_name.upper()}: FAIL\\n");
        return 1;
    }}
}}
```

Return ONLY the test code."""

        response = self.client.messages.create(
            model="claude-sonnet-4-5-20250929",
            max_tokens=8000,
            messages=[{"role": "user", "content": prompt}]
        )

        code = response.content[0].text
        return self._clean_code_block(code)

    def compile_and_test(
        self,
        module_name: str,
        compiler: str = "gcc",
        extra_files: Optional[List[str]] = None,
        cflags: Optional[List[str]] = None
    ) -> Dict:
        """
        Compile and run tests

        Args:
            module_name: Name of the module to test
            compiler: Compiler to use (gcc, arm-none-eabi-gcc, avr-gcc)
            extra_files: Additional source files needed
            cflags: Additional compiler flags

        Returns:
            Dictionary with test results
        """
        module_path = self.generated_dir / module_name
        test_file = self.tests_dir / f"test_{module_name}.c"
        source_file = module_path / f"{module_name}.c"
        header_file = module_path / f"{module_name}.h"

        # Verify files exist
        if not source_file.exists():
            return {
                "success": False,
                "stage": "validation",
                "error": f"Source file not found: {source_file}"
            }

        if not test_file.exists():
            return {
                "success": False,
                "stage": "validation",
                "error": f"Test file not found: {test_file}"
            }

        # Set up output directory
        out_dir = self.tests_dir / f"out/{module_name}"
        out_dir.mkdir(parents=True, exist_ok=True)

        # Build file list
        files = [str(source_file), str(test_file)]
        if extra_files:
            files.extend([str(self.generated_dir / f) for f in extra_files])

        # Build compiler flags
        flags = ["-I", str(module_path.parent)]
        if cflags:
            flags.extend(cflags)
        else:
            # Default flags for testing
            flags.extend(["-Wall", "-Wextra", "-std=c99", "-O2"])

        binary = out_dir / f"test_{module_name}"

        # Compile
        cmd = [compiler] + files + flags + ["-o", str(binary)]

        print(f"Compiling with {compiler}...")
        print(f"Command: {' '.join(cmd)}")

        result = subprocess.run(cmd, capture_output=True, text=True)

        if result.returncode != 0:
            return {
                "success": False,
                "stage": "compilation",
                "stdout": result.stdout,
                "stderr": result.stderr
            }

        print("✓ Compilation successful")

        # Run tests (only for native compilation)
        if compiler in ["gcc", "clang"]:
            print(f"Running tests...")
            result = subprocess.run(
                [str(binary)],
                capture_output=True,
                text=True,
                timeout=10
            )

            return {
                "success": result.returncode == 0,
                "stage": "testing",
                "stdout": result.stdout,
                "stderr": result.stderr,
                "binary": binary
            }
        else:
            # Cross-compilation - can't run directly
            return {
                "success": True,
                "stage": "compilation",
                "stdout": "Cross-compiled successfully (not run)",
                "stderr": result.stderr,
                "binary": binary,
                "note": "Binary compiled for cross-platform, not executed"
            }

    def create_and_test(
        self,
        specification: str,
        module_name: Optional[str] = None,
        target: str = "generic",
        compiler: str = "gcc",
        extra_files: Optional[List[str]] = None
    ) -> Dict:
        """
        Complete workflow: generate module, tests, compile and run

        Args:
            specification: Natural language description
            module_name: Optional custom module name
            target: Target platform (generic, cortex-m, avr)
            compiler: Compiler to use (gcc, arm-none-eabi-gcc, avr-gcc)
            extra_files: Additional source files needed

        Returns:
            Dictionary with all results and file paths
        """
        print(f"\n{'='*70}")
        print(f"Embedded C Agent - Create and Test")
        print(f"{'='*70}\n")

        # Step 1: Generate module
        print("Step 1: Generating C module...")
        try:
            module_result = self.generate_module(specification, target)
            header_code = module_result["header"]
            source_code = module_result["source"]
            detected_name = module_result["module_name"]

            # Use custom name if provided
            if module_name:
                header_code = header_code.replace(detected_name, module_name)
                header_code = header_code.replace(detected_name.upper(), module_name.upper())
                source_code = source_code.replace(detected_name, module_name)
                detected_name = module_name

            print(f"✓ Generated module: {detected_name}")
        except Exception as e:
            return {
                "success": False,
                "stage": "generation",
                "error": str(e)
            }

        # Step 2: Save module files
        module_dir = self.generated_dir / detected_name
        module_dir.mkdir(exist_ok=True)

        header_file = module_dir / f"{detected_name}.h"
        source_file = module_dir / f"{detected_name}.c"

        header_file.write_text(header_code)
        source_file.write_text(source_code)

        print(f"✓ Saved header: {header_file}")
        print(f"✓ Saved source: {source_file}")

        # Step 3: Generate tests
        print("\nStep 2: Generating unit tests...")
        try:
            test_code = self.generate_test(header_code, source_code, detected_name)
            print(f"✓ Generated tests")
        except Exception as e:
            return {
                "success": False,
                "stage": "test_generation",
                "error": str(e),
                "header_file": header_file,
                "source_file": source_file
            }

        # Step 4: Save test file
        test_file = self.tests_dir / f"test_{detected_name}.c"
        test_file.write_text(test_code)
        print(f"✓ Saved test: {test_file}")

        # Step 5: Compile and test
        print(f"\nStep 3: Compiling and testing with {compiler}...")
        test_result = self.compile_and_test(
            detected_name,
            compiler,
            extra_files
        )

        # Step 6: Report results
        print(f"\n{'='*70}")
        print("TEST RESULTS")
        print(f"{'='*70}\n")

        if test_result["success"]:
            print("✓ PASSED - All tests passed!")
        else:
            print(f"✗ FAILED - Error in {test_result['stage']}")

        if "stdout" in test_result and test_result["stdout"]:
            print("\n--- Test Output ---")
            print(test_result["stdout"])

        if "stderr" in test_result and test_result["stderr"]:
            print("\n--- Compiler Warnings/Errors ---")
            print(test_result["stderr"])

        if "note" in test_result:
            print(f"\n📝 Note: {test_result['note']}")

        print(f"\n{'='*70}\n")

        return {
            "success": test_result["success"],
            "module_name": detected_name,
            "header_file": header_file,
            "source_file": source_file,
            "test_file": test_file,
            "test_result": test_result
        }

    def _parse_header_source(self, code: str) -> Tuple[str, str]:
        """Parse header and source from formatted output"""
        # Clean markdown blocks first
        code = self._clean_code_block(code)

        # Look for HEADER_START/END and SOURCE_START/END markers
        header_match = re.search(r'HEADER_START\s*\n(.*?)\nHEADER_END', code, re.DOTALL)
        source_match = re.search(r'SOURCE_START\s*\n(.*?)\nSOURCE_END', code, re.DOTALL)

        if header_match and source_match:
            return header_match.group(1).strip(), source_match.group(1).strip()

        # Fallback: try to split by common patterns
        # Look for .h and .c file markers
        parts = re.split(r'\*\*.*?\.h.*?\*\*|\*\*.*?\.c.*?\*\*', code)
        if len(parts) >= 3:
            header = self._clean_code_block(parts[1])
            source = self._clean_code_block(parts[2])
            return header, source

        # Last resort: return as is
        return code, code

    def _clean_code_block(self, code: str) -> str:
        """Remove markdown code block formatting if present"""
        # Remove ```c or ``` blocks
        code = re.sub(r'^```c?\s*\n', '', code, flags=re.MULTILINE)
        code = re.sub(r'\n```\s*$', '', code, flags=re.MULTILINE)
        return code.strip()

    def _extract_module_name(self, code: str) -> str:
        """Extract module name from C code"""
        # Try to find in include guard
        match = re.search(r'#ifndef\s+(\w+)_H', code)
        if match:
            return match.group(1).lower()

        # Try to find .h include
        match = re.search(r'#include\s+"(\w+)\.h"', code)
        if match:
            return match.group(1)

        return "module"


def check_compiler_available(compiler: str) -> Tuple[bool, str]:
    """Check if a compiler is available on the system"""
    try:
        result = subprocess.run(
            [compiler, "--version"],
            capture_output=True,
            text=True
        )
        if result.returncode == 0:
            version = result.stdout.split('\n')[0]
            return True, version
    except FileNotFoundError:
        pass

    return False, ""


if __name__ == "__main__":
    # Quick test
    print("Embedded C Agent initialized")
    print(f"Checking for compilers...")

    for compiler in ["gcc", "clang", "arm-none-eabi-gcc", "avr-gcc"]:
        available, version = check_compiler_available(compiler)
        status = f"✓ {version}" if available else "✗ Not found"
        print(f"  {compiler}: {status}")
