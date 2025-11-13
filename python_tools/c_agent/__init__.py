"""
Embedded C Agent - AI-powered embedded C code generator and tester

This package provides tools for generating embedded C modules and unit tests
from natural language descriptions using Claude AI.
"""

from .c_agent import EmbeddedCAgent, check_compiler_available

__version__ = "1.0.0"
__all__ = ["EmbeddedCAgent", "check_compiler_available"]
