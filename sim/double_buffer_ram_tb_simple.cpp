// =============================================================================
// double_buffer_ram_tb_simple.cpp
// Simplified C++ testbench for Verilator simulation
// =============================================================================

#include <verilated.h>
#include "Vdouble_buffer_ram.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    const int DATA_WIDTH = 16;
    const int SAMPLES_PER_BUF = 256;

    Verilated::commandArgs(argc, argv);
    Vdouble_buffer_ram* dut = new Vdouble_buffer_ram;

    int error_count = 0;
    std::vector<uint16_t> buffer_a(SAMPLES_PER_BUF);
    std::vector<uint16_t> buffer_b(SAMPLES_PER_BUF);

    auto tick = [&]() {
        dut->clk_i = 0;
        dut->eval();
        dut->clk_i = 1;
        dut->eval();
    };

    std::cout << "========================================" << std::endl;
    std::cout << "DOUBLE_BUFFER_RAM SIMPLE TEST" << std::endl;
    std::cout << "========================================" << std::endl;

    // Reset
    dut->rst_ni = 0;
    dut->in_valid_i = 0;
    dut->rd_en_i = 0;
    for (int i = 0; i < 10; i++) tick();
    dut->rst_ni = 1;
    tick();

    // Test 1: Write 256 samples to buffer A
    std::cout << "\nTest 1: Writing 256 samples to buffer A..." << std::endl;
    for (int i = 0; i < SAMPLES_PER_BUF; i++) {
        dut->in_valid_i = 1;
        dut->in_data_i = 0x1000 + i;
        buffer_a[i] = 0x1000 + i;
        tick();
    }
    dut->in_valid_i = 0;
    tick();

    // Check that buffer toggle occurred
    if (dut->active_buf_o != 1) {
        std::cerr << "ERROR: Should be writing to buffer B now!" << std::endl;
        error_count++;
    }

    // Test 2: Write 256 samples to buffer B while reading buffer A
    std::cout << "Test 2: Writing to buffer B, reading from buffer A..." << std::endl;
    int read_errors = 0;
    for (int i = 0; i < SAMPLES_PER_BUF + 2; i++) {
        // Write
        if (i < SAMPLES_PER_BUF) {
            dut->in_valid_i = 1;
            dut->in_data_i = 0x2000 + i;
            buffer_b[i] = 0x2000 + i;
        } else {
            dut->in_valid_i = 0;
        }

        // Read
        if (i < SAMPLES_PER_BUF) {
            dut->rd_addr_i = i;
            dut->rd_en_i = 1;
        } else {
            dut->rd_en_i = 0;
        }

        tick();

        // Check read data (with 1-cycle latency)
        if (i >= 1 && i <= SAMPLES_PER_BUF && dut->rd_data_valid_o) {
            uint16_t expected = buffer_a[i-1];
            if (dut->rd_data_o != expected) {
                if (read_errors < 5) {  // Only print first 5 errors
                    std::cerr << "ERROR: Read A[" << (i-1) << "]: expected=0x"
                              << std::hex << expected << ", got=0x" << dut->rd_data_o
                              << std::dec << std::endl;
                }
                read_errors++;
            }
        }
    }

    if (read_errors == 0) {
        std::cout << "  Buffer A readback: PASS" << std::endl;
    } else {
        std::cout << "  Buffer A readback: FAIL (" << read_errors << " errors)" << std::endl;
        error_count += read_errors;
    }

    // Check buffer toggle
    if (dut->active_buf_o != 0) {
        std::cerr << "ERROR: Should be writing to buffer A now!" << std::endl;
        error_count++;
    }

    // Test 3: Read buffer B
    std::cout << "Test 3: Reading from buffer B..." << std::endl;
    read_errors = 0;
    for (int i = 0; i < SAMPLES_PER_BUF + 1; i++) {
        if (i < SAMPLES_PER_BUF) {
            dut->rd_addr_i = i;
            dut->rd_en_i = 1;
        } else {
            dut->rd_en_i = 0;
        }

        tick();

        if (i >= 1 && dut->rd_data_valid_o) {
            uint16_t expected = buffer_b[i-1];
            if (dut->rd_data_o != expected) {
                if (read_errors < 5) {
                    std::cerr << "ERROR: Read B[" << (i-1) << "]: expected=0x"
                              << std::hex << expected << ", got=0x" << dut->rd_data_o
                              << std::dec << std::endl;
                }
                read_errors++;
            }
        }
    }

    if (read_errors == 0) {
        std::cout << "  Buffer B readback: PASS" << std::endl;
    } else {
        std::cout << "  Buffer B readback: FAIL (" << read_errors << " errors)" << std::endl;
        error_count += read_errors;
    }

    // Results
    std::cout << "\n========================================" << std::endl;
    if (error_count == 0) {
        std::cout << "DOUBLE_BUFFER_RAM: PASS" << std::endl;
    } else {
        std::cout << "DOUBLE_BUFFER_RAM: FAIL (" << error_count << " errors)" << std::endl;
    }
    std::cout << "========================================" << std::endl;

    dut->final();
    delete dut;
    return (error_count == 0) ? 0 : 1;
}
