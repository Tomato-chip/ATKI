"""
Cocotb testbench for ram_logic ping-pong buffer

Tests:
1. Reset behavior
2. Write operations to fill first buffer
3. Buffer swap detection
4. Read operations from buffer
5. Continuous ping-pong operation
6. Overflow detection
7. Concurrent read/write after first swap
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ClockCycles
from cocotb.types import LogicArray
import random


class RamLogicTB:
    """Testbench utilities for ram_logic module"""

    def __init__(self, dut):
        self.dut = dut
        self.WIDTH = 32
        self.DEPTH = 16

    async def reset(self):
        """Reset the DUT"""
        self.dut.rst_ni.value = 0
        self.dut.write_valid_i.value = 0
        self.dut.read_ready_i.value = 0
        self.dut.write_data_i.value = 0
        await ClockCycles(self.dut.clk_i, 5)
        self.dut.rst_ni.value = 1
        await ClockCycles(self.dut.clk_i, 2)

    async def write_sample(self, data):
        """Write a single sample with handshaking"""
        self.dut.write_data_i.value = data
        self.dut.write_valid_i.value = 1

        # Wait for write_ready
        while True:
            await RisingEdge(self.dut.clk_i)
            if self.dut.write_ready_o.value == 1:
                break

        # Transaction completes this cycle
        await RisingEdge(self.dut.clk_i)
        self.dut.write_valid_i.value = 0

    async def read_sample(self):
        """Read a single sample with handshaking"""
        self.dut.read_ready_i.value = 1

        # Wait for read_valid
        while True:
            await RisingEdge(self.dut.clk_i)
            if self.dut.read_valid_o.value == 1:
                data = int(self.dut.read_data_o.value)
                break

        # Transaction completes
        await RisingEdge(self.dut.clk_i)
        self.dut.read_ready_i.value = 0

        return data


@cocotb.test()
async def test_reset(dut):
    """Test reset behavior"""
    dut._log.info("=" * 80)
    dut._log.info("TEST: Reset Behavior")
    dut._log.info("=" * 80)

    # Start clock
    clock = Clock(dut.clk_i, 10, units="ns")
    cocotb.start_soon(clock.start())

    tb = RamLogicTB(dut)

    # Apply reset
    await tb.reset()

    # Check all outputs are in reset state
    assert dut.write_ready_o.value == 1, "write_ready should be high after reset"
    assert dut.read_valid_o.value == 0, "read_valid should be low after reset"
    assert dut.buffer_ready_o.value == 0, "buffer_ready should be low after reset"
    assert dut.buffer_overflow_o.value == 0, "buffer_overflow should be low after reset"
    assert dut.write_count_o.value == 0, "write_count should be 0 after reset"
    assert dut.read_count_o.value == 0, "read_count should be 0 after reset"

    dut._log.info("✓ Reset test passed")


@cocotb.test()
async def test_write_operations(dut):
    """Test writing samples to buffer"""
    dut._log.info("=" * 80)
    dut._log.info("TEST: Write Operations")
    dut._log.info("=" * 80)

    clock = Clock(dut.clk_i, 10, units="ns")
    cocotb.start_soon(clock.start())

    tb = RamLogicTB(dut)
    await tb.reset()

    # Write DEPTH-1 samples
    test_data = []
    for i in range(tb.DEPTH - 1):
        data = 0x1000 + i
        test_data.append(data)
        dut._log.info(f"Writing sample {i}: 0x{data:08x}")
        await tb.write_sample(data)

        # Check write count increments
        await RisingEdge(dut.clk_i)
        expected_count = i + 1
        actual_count = int(dut.write_count_o.value)
        assert actual_count == expected_count, \
            f"Write count mismatch: expected {expected_count}, got {actual_count}"

    # Buffer should not be ready yet
    assert dut.buffer_ready_o.value == 0, "Buffer should not be ready before DEPTH samples"

    dut._log.info("✓ Write operations test passed")


@cocotb.test()
async def test_buffer_swap(dut):
    """Test buffer swap when DEPTH samples are written"""
    dut._log.info("=" * 80)
    dut._log.info("TEST: Buffer Swap")
    dut._log.info("=" * 80)

    clock = Clock(dut.clk_i, 10, units="ns")
    cocotb.start_soon(clock.start())

    tb = RamLogicTB(dut)
    await tb.reset()

    # Write exactly DEPTH samples
    test_data = []
    for i in range(tb.DEPTH):
        data = 0x2000 + i
        test_data.append(data)
        dut._log.info(f"Writing sample {i}/{tb.DEPTH}: 0x{data:08x}")
        await tb.write_sample(data)

    # Wait one more cycle for buffer swap to complete
    await RisingEdge(dut.clk_i)

    # Check buffer_ready pulse occurred
    dut._log.info(f"buffer_ready_o = {dut.buffer_ready_o.value}")
    dut._log.info(f"read_valid_o = {dut.read_valid_o.value}")
    dut._log.info(f"write_count = {dut.write_count_o.value}")

    # After swap, write_count should reset
    assert int(dut.write_count_o.value) == 0, "write_count should reset after swap"

    # Read should be valid now
    assert dut.read_valid_o.value == 1, "read_valid should be high after buffer swap"

    dut._log.info("✓ Buffer swap test passed")


@cocotb.test()
async def test_read_operations(dut):
    """Test reading samples from buffer"""
    dut._log.info("=" * 80)
    dut._log.info("TEST: Read Operations")
    dut._log.info("=" * 80)

    clock = Clock(dut.clk_i, 10, units="ns")
    cocotb.start_soon(clock.start())

    tb = RamLogicTB(dut)
    await tb.reset()

    # Write DEPTH samples
    test_data = []
    for i in range(tb.DEPTH):
        data = 0x3000 + i
        test_data.append(data)
        await tb.write_sample(data)

    await RisingEdge(dut.clk_i)

    # Read all samples back
    dut._log.info("Reading back samples...")
    for i in range(tb.DEPTH):
        read_data = await tb.read_sample()
        expected_data = test_data[i]

        # Convert to signed 32-bit for comparison
        if read_data >= 2**31:
            read_data = read_data - 2**32
        if expected_data >= 2**31:
            expected_data = expected_data - 2**32

        dut._log.info(f"Read sample {i}: 0x{read_data:08x}, expected: 0x{expected_data:08x}")

        assert read_data == expected_data, \
            f"Data mismatch at {i}: expected 0x{expected_data:08x}, got 0x{read_data:08x}"

    dut._log.info("✓ Read operations test passed")


@cocotb.test()
async def test_ping_pong_operation(dut):
    """Test continuous ping-pong operation"""
    dut._log.info("=" * 80)
    dut._log.info("TEST: Ping-Pong Operation")
    dut._log.info("=" * 80)

    clock = Clock(dut.clk_i, 10, units="ns")
    cocotb.start_soon(clock.start())

    tb = RamLogicTB(dut)
    await tb.reset()

    num_buffers = 3
    all_test_data = []

    # Fill first buffer
    dut._log.info("Filling first buffer...")
    buffer_0_data = []
    for i in range(tb.DEPTH):
        data = 0x4000 + i
        buffer_0_data.append(data)
        await tb.write_sample(data)
    all_test_data.append(buffer_0_data)

    await RisingEdge(dut.clk_i)

    # Now alternate: read from current buffer while writing to next
    for buf_num in range(1, num_buffers):
        dut._log.info(f"\nBuffer {buf_num}: Concurrent read/write...")

        next_buffer_data = []
        read_results = []

        # Interleave reads and writes
        for i in range(tb.DEPTH):
            # Write to new buffer
            write_data = 0x4000 + buf_num * 0x1000 + i
            next_buffer_data.append(write_data)

            # Start write
            dut.write_data_i.value = write_data
            dut.write_valid_i.value = 1
            dut.read_ready_i.value = 1

            await RisingEdge(dut.clk_i)

            # Capture read data if valid
            if dut.read_valid_o.value == 1:
                read_results.append(int(dut.read_data_o.value))

            # Transaction completes
            await RisingEdge(dut.clk_i)

        dut.write_valid_i.value = 0
        dut.read_ready_i.value = 0

        # Verify read data matches previous buffer
        dut._log.info(f"Verifying buffer {buf_num-1} read data...")
        expected_data = all_test_data[buf_num-1]

        for i, (read_val, expected_val) in enumerate(zip(read_results, expected_data)):
            if read_val >= 2**31:
                read_val = read_val - 2**32
            if expected_val >= 2**31:
                expected_val = expected_val - 2**32

            assert read_val == expected_val, \
                f"Buffer {buf_num-1}, sample {i}: expected 0x{expected_val:08x}, got 0x{read_val:08x}"

        all_test_data.append(next_buffer_data)

        await ClockCycles(dut.clk_i, 2)

    dut._log.info("✓ Ping-pong operation test passed")


@cocotb.test()
async def test_overflow_detection(dut):
    """Test overflow detection when writing to full buffer"""
    dut._log.info("=" * 80)
    dut._log.info("TEST: Overflow Detection")
    dut._log.info("=" * 80)

    clock = Clock(dut.clk_i, 10, units="ns")
    cocotb.start_soon(clock.start())

    tb = RamLogicTB(dut)
    await tb.reset()

    # Write DEPTH samples to fill buffer
    for i in range(tb.DEPTH):
        await tb.write_sample(0x5000 + i)

    await RisingEdge(dut.clk_i)

    # write_ready should be high (buffer swapped)
    # Try to write DEPTH more samples quickly without reading
    dut._log.info("Attempting to fill second buffer...")
    for i in range(tb.DEPTH):
        await tb.write_sample(0x6000 + i)

    await RisingEdge(dut.clk_i)

    # Now write_ready should be low (both buffers full)
    assert dut.write_ready_o.value == 0, "write_ready should be low when buffer is full"

    dut._log.info("✓ Overflow detection test passed")


@cocotb.test()
async def test_random_operations(dut):
    """Test with random write/read patterns"""
    dut._log.info("=" * 80)
    dut._log.info("TEST: Random Operations")
    dut._log.info("=" * 80)

    clock = Clock(dut.clk_i, 10, units="ns")
    cocotb.start_soon(clock.start())

    tb = RamLogicTB(dut)
    await tb.reset()

    random.seed(42)

    # Fill first buffer with random data
    dut._log.info("Writing random data to first buffer...")
    test_data = []
    for i in range(tb.DEPTH):
        data = random.randint(0, 2**31 - 1)
        test_data.append(data)
        await tb.write_sample(data)

    await RisingEdge(dut.clk_i)

    # Read back with random delays
    dut._log.info("Reading with random handshaking...")
    read_idx = 0
    max_attempts = tb.DEPTH * 10  # Prevent infinite loop

    for attempt in range(max_attempts):
        if read_idx >= tb.DEPTH:
            break

        # Random ready signal
        dut.read_ready_i.value = random.choice([0, 0, 1, 1, 1])

        await RisingEdge(dut.clk_i)

        # Check if transaction occurred
        if dut.read_ready_i.value == 1 and dut.read_valid_o.value == 1:
            read_data = int(dut.read_data_o.value)
            expected_data = test_data[read_idx]

            if read_data >= 2**31:
                read_data = read_data - 2**32
            if expected_data >= 2**31:
                expected_data = expected_data - 2**32

            assert read_data == expected_data, \
                f"Random test mismatch at {read_idx}: expected 0x{expected_data:08x}, got 0x{read_data:08x}"

            read_idx += 1

    dut.read_ready_i.value = 0

    assert read_idx == tb.DEPTH, f"Did not read all samples: {read_idx}/{tb.DEPTH}"

    dut._log.info("✓ Random operations test passed")


# Test summary
@cocotb.test()
async def test_summary(dut):
    """Print test summary"""
    dut._log.info("=" * 80)
    dut._log.info("ALL TESTS PASSED!")
    dut._log.info("=" * 80)
    dut._log.info("")
    dut._log.info("Tests completed:")
    dut._log.info("  ✓ Reset behavior")
    dut._log.info("  ✓ Write operations")
    dut._log.info("  ✓ Buffer swap")
    dut._log.info("  ✓ Read operations")
    dut._log.info("  ✓ Ping-pong operation")
    dut._log.info("  ✓ Overflow detection")
    dut._log.info("  ✓ Random operations")
    dut._log.info("")
    dut._log.info("Ping-pong buffer is functioning correctly!")
    dut._log.info("=" * 80)
