#!/usr/bin/env python3
"""
SystemVerilog Agent - AI-powered SystemVerilog module generator and tester

This agent can:
- Generate SystemVerilog modules from natural language specifications
- Create comprehensive self-checking testbenches
- Run simulations with Verilator or iverilog
- Provide detailed test results and waveforms
"""

import anthropic
import subprocess
import os
import re
from pathlib import Path
from typing import Dict, Optional, Tuple


class SystemVerilogAgent:
    """AI agent for generating and testing SystemVerilog code"""

    def __init__(self, api_key: Optional[str] = None, project_root: Optional[Path] = None):
        """
        Initialize the SystemVerilog agent

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

        self.sim_dir = self.project_root / "sim"
        self.digital_dir = self.project_root / "digital"
        self.generated_dir = self.digital_dir / "generated"
        self.sim_generated_dir = self.sim_dir / "generated"

        # Create directories if they don't exist
        self.generated_dir.mkdir(parents=True, exist_ok=True)
        self.sim_generated_dir.mkdir(parents=True, exist_ok=True)

    def generate_module(self, specification: str, include_context: bool = True) -> Dict[str, str]:
        """
        Generate a SystemVerilog module from natural language specification

        Args:
            specification: Natural language description of the desired module
            include_context: Include project-specific coding style context

        Returns:
            Dictionary with 'code' and 'module_name' keys
        """
        context = ""
        if include_context:
            context = """
Follow these coding conventions from the ATKI project:
- Use logic instead of wire/reg
- Use active-low reset signals named rst_ni
- Use _i suffix for inputs, _o suffix for outputs
- Use always_ff for sequential logic, always_comb for combinational
- Add clear comments explaining functionality
- Use parameterized designs where appropriate
"""

        prompt = f"""Generate a SystemVerilog module based on this specification:

{specification}

{context}

Example module structure:
```systemverilog
module example #(
    parameter int unsigned DATA_WIDTH = 16
) (
    input  logic                  clk_i,
    input  logic                  rst_ni,  // Active low reset
    input  logic [DATA_WIDTH-1:0] data_i,
    output logic [DATA_WIDTH-1:0] data_o
);

    // Sequential logic
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            // Reset state
        end else begin
            // Normal operation
        end
    end

endmodule
```

Return ONLY the SystemVerilog code with no additional explanations or markdown formatting."""

        response = self.client.messages.create(
            model="claude-sonnet-4-5-20250929",
            max_tokens=4000,
            messages=[{"role": "user", "content": prompt}]
        )

        code = response.content[0].text
        # Clean up markdown code blocks if present
        code = self._clean_code_block(code)
        module_name = self._extract_module_name(code)

        return {"code": code, "module_name": module_name}

    def generate_testbench(self, module_code: str, module_name: str) -> str:
        """
        Generate a comprehensive self-checking testbench for a module

        Args:
            module_code: SystemVerilog module code
            module_name: Name of the module

        Returns:
            Complete testbench code
        """
        prompt = f"""Generate a comprehensive self-checking testbench for this SystemVerilog module:

```systemverilog
{module_code}
```

Requirements:
1. Use `timescale 1ns/1ps
2. Create clock generation (use ~27 MHz / 37ns period)
3. Implement reset sequence task
4. Write test tasks for operations
5. Add self-checking with error_count variable
6. Generate VCD waveform dump as {module_name}_tb.vcd
7. Include timeout watchdog (100k cycles)
8. Print clear test results (PASS/FAIL)
9. Use $display for progress, $error for failures
10. Call $finish at end, $fatal on failure

Follow this testbench template structure:

```systemverilog
`timescale 1ns/1ps

module {module_name}_tb;
    // Parameters
    localparam CLK_PERIOD = 37;  // ~27 MHz clock

    // Signals matching DUT
    logic clk_i;
    logic rst_ni;
    // ... other signals

    int error_count = 0;

    // Clock generation
    initial begin
        clk_i = 0;
        forever #(CLK_PERIOD/2) clk_i = ~clk_i;
    end

    // DUT instantiation
    {module_name} dut (
        .clk_i(clk_i),
        .rst_ni(rst_ni)
        // ... other ports
    );

    // Tasks
    task automatic reset_dut();
        rst_ni = 0;
        // Initialize other inputs
        repeat(10) @(posedge clk_i);
        rst_ni = 1;
        repeat(2) @(posedge clk_i);
        $display("[%0t] Reset complete", $time);
    endtask

    // Main test sequence
    initial begin
        $display("================================================================================");
        $display("{module_name.upper()} TESTBENCH");
        $display("================================================================================");

        // Test 1: Reset
        $display("\\n[TEST 1] Reset and initialization");
        reset_dut();
        $display("[TEST 1] PASSED");

        // Add more test cases here

        // Final results
        repeat(20) @(posedge clk_i);
        $display("\\n================================================================================");
        $display("TEST COMPLETE");
        $display("================================================================================");
        $display("Total errors: %0d", error_count);

        if (error_count == 0) begin
            $display("{module_name.upper()}: PASS");
        end else begin
            $fatal(1, "Test failed with %0d errors", error_count);
        end
        $finish;
    end

    // Timeout watchdog
    initial begin
        #(CLK_PERIOD * 100000);
        $fatal(1, "TIMEOUT: Test did not complete in time");
    end

    // Waveform dump
    initial begin
        $dumpfile("{module_name}_tb.vcd");
        $dumpvars(0, {module_name}_tb);
    end

endmodule
```

Return ONLY the testbench code with no additional explanations or markdown formatting."""

        response = self.client.messages.create(
            model="claude-sonnet-4-5-20250929",
            max_tokens=6000,
            messages=[{"role": "user", "content": prompt}]
        )

        code = response.content[0].text
        return self._clean_code_block(code)

    def run_simulation(
        self,
        module_file: str,
        tb_file: str,
        simulator: str = "verilator",
        extra_files: Optional[list] = None
    ) -> Dict:
        """
        Compile and run simulation

        Args:
            module_file: Path to module file (relative to digital/)
            tb_file: Path to testbench file (relative to sim/)
            simulator: Simulator to use ('verilator' or 'iverilog')
            extra_files: Additional source files needed

        Returns:
            Dictionary with simulation results
        """
        module_path = self.digital_dir / module_file
        tb_path = self.sim_dir / tb_file

        if not module_path.exists():
            return {
                "success": False,
                "stage": "validation",
                "error": f"Module file not found: {module_path}"
            }

        if not tb_path.exists():
            return {
                "success": False,
                "stage": "validation",
                "error": f"Testbench file not found: {tb_path}"
            }

        module_name = module_path.stem
        out_dir = self.sim_dir / f"out/{module_name}_run"
        out_dir.mkdir(parents=True, exist_ok=True)

        if simulator == "verilator":
            return self._run_verilator(module_path, tb_path, out_dir, extra_files)
        elif simulator == "iverilog":
            return self._run_iverilog(module_path, tb_path, out_dir, extra_files)
        else:
            return {
                "success": False,
                "stage": "validation",
                "error": f"Unknown simulator: {simulator}"
            }

    def _run_verilator(self, module_path: Path, tb_path: Path, out_dir: Path,
                       extra_files: Optional[list]) -> Dict:
        """Run Verilator simulation"""
        tb_name = tb_path.stem
        binary = out_dir / f"V{tb_name}"

        # Build file list
        files = [str(tb_path), str(module_path)]
        if extra_files:
            files.extend([str(self.digital_dir / f) for f in extra_files])

        # Compile command
        cmd = [
            "verilator",
            "--binary",
            "--trace",
            "-Wall",
            "-Wno-TIMESCALEMOD",
            "-Wno-WIDTHEXPAND",
            "-Wno-UNUSEDSIGNAL",
            "-Wno-UNUSEDPARAM",
            f"--top-module", tb_name,
            "--timing",
            "-j", "0",
            "-Mdir", str(out_dir / "obj_dir"),
        ] + files

        print(f"Compiling with Verilator...")
        result = subprocess.run(cmd, capture_output=True, text=True)

        if result.returncode != 0:
            return {
                "success": False,
                "stage": "compilation",
                "stdout": result.stdout,
                "stderr": result.stderr
            }

        # Move binary
        obj_binary = out_dir / "obj_dir" / f"V{tb_name}"
        if obj_binary.exists():
            obj_binary.rename(binary)

        # Run simulation
        print(f"Running simulation...")
        result = subprocess.run(
            [str(binary)],
            capture_output=True,
            text=True,
            cwd=out_dir,
            timeout=60  # 60 second timeout
        )

        vcd_file = out_dir / f"{tb_name.replace('_tb', '')}_tb.vcd"

        return {
            "success": result.returncode == 0,
            "stage": "simulation",
            "stdout": result.stdout,
            "stderr": result.stderr,
            "vcd_file": vcd_file if vcd_file.exists() else None,
            "output_dir": out_dir
        }

    def _run_iverilog(self, module_path: Path, tb_path: Path, out_dir: Path,
                      extra_files: Optional[list]) -> Dict:
        """Run iverilog simulation"""
        tb_name = tb_path.stem
        vvp_file = out_dir / f"{tb_name}.vvp"

        # Build file list
        files = [str(tb_path), str(module_path)]
        if extra_files:
            files.extend([str(self.digital_dir / f) for f in extra_files])

        # Compile command
        cmd = [
            "iverilog",
            "-g2012",  # SystemVerilog 2012
            "-o", str(vvp_file),
        ] + files

        print(f"Compiling with iverilog...")
        result = subprocess.run(cmd, capture_output=True, text=True)

        if result.returncode != 0:
            return {
                "success": False,
                "stage": "compilation",
                "stdout": result.stdout,
                "stderr": result.stderr
            }

        # Run simulation
        print(f"Running simulation with vvp...")
        result = subprocess.run(
            ["vvp", str(vvp_file)],
            capture_output=True,
            text=True,
            cwd=out_dir,
            timeout=60
        )

        vcd_file = out_dir / f"{tb_name.replace('_tb', '')}_tb.vcd"

        return {
            "success": result.returncode == 0,
            "stage": "simulation",
            "stdout": result.stdout,
            "stderr": result.stderr,
            "vcd_file": vcd_file if vcd_file.exists() else None,
            "output_dir": out_dir
        }

    def create_and_test(
        self,
        specification: str,
        module_name: Optional[str] = None,
        simulator: str = "verilator",
        extra_files: Optional[list] = None
    ) -> Dict:
        """
        Complete workflow: generate module, testbench, and run simulation

        Args:
            specification: Natural language description of desired module
            module_name: Optional custom module name
            simulator: Simulator to use ('verilator' or 'iverilog')
            extra_files: Additional source files needed for simulation

        Returns:
            Dictionary with all results and file paths
        """
        print(f"\n{'='*70}")
        print(f"SystemVerilog Agent - Create and Test")
        print(f"{'='*70}\n")

        # Step 1: Generate module
        print("Step 1: Generating module...")
        try:
            module_result = self.generate_module(specification)
            module_code = module_result["code"]
            detected_name = module_result["module_name"]

            # Use custom name if provided
            if module_name:
                module_code = module_code.replace(
                    f"module {detected_name}",
                    f"module {module_name}",
                    1
                )
                detected_name = module_name

            print(f"✓ Generated module: {detected_name}")
        except Exception as e:
            return {
                "success": False,
                "stage": "generation",
                "error": str(e)
            }

        # Step 2: Save module
        module_file = f"{detected_name}.sv"
        module_path = self.generated_dir / module_file
        module_path.write_text(module_code)
        print(f"✓ Saved to: {module_path}")

        # Step 3: Generate testbench
        print("\nStep 2: Generating testbench...")
        try:
            tb_code = self.generate_testbench(module_code, detected_name)
            print(f"✓ Generated testbench")
        except Exception as e:
            return {
                "success": False,
                "stage": "testbench_generation",
                "error": str(e),
                "module_file": module_path
            }

        # Step 4: Save testbench
        tb_file = f"{detected_name}_tb.sv"
        tb_path = self.sim_generated_dir / tb_file
        tb_path.write_text(tb_code)
        print(f"✓ Saved to: {tb_path}")

        # Step 5: Run simulation
        print(f"\nStep 3: Running simulation with {simulator}...")
        sim_result = self.run_simulation(
            f"generated/{module_file}",
            f"generated/{tb_file}",
            simulator,
            extra_files
        )

        # Step 6: Report results
        print(f"\n{'='*70}")
        print("SIMULATION RESULTS")
        print(f"{'='*70}\n")

        if sim_result["success"]:
            print("✓ PASSED - All tests passed!")
        else:
            print(f"✗ FAILED - Error in {sim_result['stage']}")

        if "stdout" in sim_result and sim_result["stdout"]:
            print("\n--- Simulation Output ---")
            print(sim_result["stdout"])

        if "stderr" in sim_result and sim_result["stderr"]:
            print("\n--- Warnings/Errors ---")
            print(sim_result["stderr"])

        if sim_result.get("vcd_file"):
            print(f"\n📊 Waveform: {sim_result['vcd_file']}")
            print(f"   View with: gtkwave {sim_result['vcd_file']}")

        print(f"\n{'='*70}\n")

        return {
            "success": sim_result["success"],
            "module_name": detected_name,
            "module_file": module_path,
            "tb_file": tb_path,
            "simulation": sim_result
        }

    def _clean_code_block(self, code: str) -> str:
        """Remove markdown code block formatting if present"""
        # Remove ```systemverilog or ```verilog or ``` blocks
        code = re.sub(r'^```(?:systemverilog|verilog)?\s*\n', '', code, flags=re.MULTILINE)
        code = re.sub(r'\n```\s*$', '', code, flags=re.MULTILINE)
        return code.strip()

    def _extract_module_name(self, code: str) -> str:
        """Extract module name from SystemVerilog code"""
        match = re.search(r'module\s+(\w+)', code)
        return match.group(1) if match else "unknown_module"


def check_simulator_available(simulator: str) -> Tuple[bool, str]:
    """Check if a simulator is available on the system"""
    try:
        if simulator == "verilator":
            result = subprocess.run(
                ["verilator", "--version"],
                capture_output=True,
                text=True
            )
            if result.returncode == 0:
                version = result.stdout.split('\n')[0]
                return True, version
        elif simulator == "iverilog":
            result = subprocess.run(
                ["iverilog", "-V"],
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
    print("SystemVerilog Agent initialized")
    print(f"Checking for simulators...")

    for sim in ["verilator", "iverilog"]:
        available, version = check_simulator_available(sim)
        status = f"✓ {version}" if available else "✗ Not found"
        print(f"  {sim}: {status}")
