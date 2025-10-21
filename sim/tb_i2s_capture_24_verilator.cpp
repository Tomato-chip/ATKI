// =============================================================================
// tb_i2s_capture_24_verilator.cpp
// Verilator C++ testbench for i2s_capture_24 module
// =============================================================================

#include <verilated.h>
#include "Vtb_i2s_top.h"
#include <iostream>
#include <iomanip>

#define LEFT_PATTERN  0xABCDEF
#define RIGHT_PATTERN 0x123456

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vtb_i2s_top* dut = new Vtb_i2s_top;

    bool test_passed = true;
    int valid_count = 0;
    uint32_t captured_data = 0;

    // Initialize
    dut->clk = 0;
    dut->rst_n = 0;
    dut->sck = 0;
    dut->ws = 0;
    dut->sd = 0;

    std::cout << "=== I²S Capture 24-bit Test ===" << std::endl;
    std::cout << "Left pattern:  0x" << std::hex << std::setfill('0')
              << std::setw(6) << LEFT_PATTERN << std::endl;
    std::cout << "Right pattern: 0x" << std::setw(6) << RIGHT_PATTERN << std::endl;

    // Reset sequence
    for (int i = 0; i < 20; i++) {
        dut->clk = !dut->clk;
        dut->eval();
    }
    dut->rst_n = 1;
    for (int i = 0; i < 20; i++) {
        dut->clk = !dut->clk;
        dut->eval();
    }

    // Helper: run clock cycles
    auto clk_cycles = [&](int n) {
        for (int i = 0; i < n; i++) {
            dut->clk = 0;
            dut->eval();
            dut->clk = 1;
            dut->eval();
            // Check for valid on positive edge
            if (dut->valid) {
                valid_count++;
                captured_data = dut->data24;
            }
        }
    };

    // Helper: toggle sck
    auto sck_cycle = [&]() {
        // Run enough clk cycles for sck edge detection
        clk_cycles(16);
        dut->sck = 1;
        clk_cycles(16);
        dut->sck = 0;
    };

    // Helper: send half frame (32 SCK cycles)
    auto send_half_frame = [&](uint32_t pattern) {
        // Skip 1 SCK (I²S MSB delay)
        sck_cycle();

        // Send 24 bits MSB-first
        for (int i = 23; i >= 0; i--) {
            dut->sd = (pattern >> i) & 1;
            sck_cycle();
        }

        // Send 8 dummy bits (fill 32-bit slot)
        for (int i = 0; i < 8; i++) {
            dut->sd = 0;
            sck_cycle();
        }
    };

    // LEFT channel (ws=0)
    dut->ws = 0;
    clk_cycles(20);

    send_half_frame(LEFT_PATTERN);

    // Allow time for valid pulse
    clk_cycles(50);

    // Check left channel capture
    if (captured_data == LEFT_PATTERN) {
        std::cout << "[PASS] Left channel captured: 0x"
                  << std::setw(6) << captured_data << std::endl;
    } else {
        std::cout << "[FAIL] Left channel mismatch: expected 0x"
                  << std::setw(6) << LEFT_PATTERN
                  << ", got 0x" << std::setw(6) << captured_data << std::endl;
        test_passed = false;
    }

    // RIGHT channel (ws=1) - should be ignored
    dut->ws = 1;
    clk_cycles(20);

    int before_right = valid_count;
    send_half_frame(RIGHT_PATTERN);

    // Allow time to check for unwanted valid pulse
    clk_cycles(50);

    if (valid_count == before_right) {
        std::cout << "[PASS] Right channel correctly ignored" << std::endl;
    } else {
        std::cout << "[FAIL] Right channel should not trigger valid" << std::endl;
        test_passed = false;
    }

    // Verify valid count
    if (valid_count == 1) {
        std::cout << "[PASS] Only left channel triggered valid (count="
                  << std::dec << valid_count << ")" << std::endl;
    } else {
        std::cout << "[FAIL] Unexpected valid count: " << std::dec << valid_count
                  << " (expected 1)" << std::endl;
        test_passed = false;
    }

    // Final result
    std::cout << std::endl;
    if (test_passed) {
        std::cout << "*** ALL TESTS PASSED ***" << std::endl;
    } else {
        std::cout << "*** TEST FAILED ***" << std::endl;
    }

    delete dut;
    return test_passed ? 0 : 1;
}
