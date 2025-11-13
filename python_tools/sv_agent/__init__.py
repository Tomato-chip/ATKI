"""
SystemVerilog Agent - AI-powered SystemVerilog generator and tester

This package provides tools for generating SystemVerilog modules and testbenches
from natural language descriptions using Claude AI.
"""

from .sv_agent import SystemVerilogAgent, check_simulator_available

__version__ = "1.0.0"
__all__ = ["SystemVerilogAgent", "check_simulator_available"]
