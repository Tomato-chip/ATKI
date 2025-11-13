# Embedded C Code

This directory contains embedded C code for the ATKI project.

## Structure

- `generated/` - Auto-generated C modules (from C Agent)
- `tests/` - Auto-generated unit tests (from C Agent)

## C Agent

The C Agent is an AI-powered tool for generating embedded C code:

```bash
cd python_tools/c_agent
./cgen "Create a ring buffer for uint8_t with 256 bytes"
```

See:
- `python_tools/c_agent/README.md` - Full documentation
- `C_AGENT_GUIDE.md` - Quick start guide

## Future Directories

As the project grows, you might add:
- `drivers/` - Hardware drivers
- `protocols/` - Communication protocols
- `utils/` - Utility libraries
- `hal/` - Hardware abstraction layer
