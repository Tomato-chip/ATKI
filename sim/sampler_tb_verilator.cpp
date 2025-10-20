// =============================================================================
// sampler_tb_verilator.cpp
// C++ testbench wrapper for Verilator simulation of sampler module
// =============================================================================

#include <verilated.h>
#include "Vsampler.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    const int DATA_WIDTH = 16;
    const int SAMPLES_PER_BUF = 256;

    Verilated::commandArgs(argc, argv);
    Vsampler* dut = new Vsampler;

    int error_count = 0;
    std::vector<uint16_t> golden_buffer_a(SAMPLES_PER_BUF);
    std::vector<uint16_t> golden_buffer_b(SAMPLES_PER_BUF);
    bool buffer_a_valid = false;
    bool buffer_b_valid = false;
    int sample_count = 0;
    uint16_t current_sample_value = 0x5000;

    auto tick = [&]() {
        dut->clk_i = 0;
        dut->eval();
        dut->clk_i = 1;
        dut->eval();
    };

    std::cout << "========================================" << std::endl;
    std::cout << "SAMPLER TESTBENCH (Verilator)" << std::endl;
    std::cout << "========================================" << std::endl;

    // Reset
    dut->rst_ni = 0;
    dut->mic_valid_i = 0;
    dut->mic_data_i[0] = 0;
    for (int i = 0; i < 10; i++) tick();
    dut->rst_ni = 1;
    tick();

    std::cout << "\nTest 1: Reset and initialization - ";
    if (dut->active_buf_o != 0) {
        std::cerr << "FAIL (active_buf_o should be 0)" << std::endl;
        error_count++;
    } else {
        std::cout << "PASS" << std::endl;
    }

    // Test 2: Fill buffer A with 256 samples
    std::cout << "Test 2: Filling buffer A with " << SAMPLES_PER_BUF << " samples - ";
    for (int i = 0; i < SAMPLES_PER_BUF; i++) {
        dut->mic_valid_i = 1;
        dut->mic_data_i[0] = current_sample_value;

        if (dut->active_buf_o == 0) {
            golden_buffer_a[sample_count % SAMPLES_PER_BUF] = current_sample_value;
        } else {
            golden_buffer_b[sample_count % SAMPLES_PER_BUF] = current_sample_value;
        }

        current_sample_value++;
        sample_count++;
        tick();

        if (dut->buf_ready_pulse_o) {
            buffer_a_valid = true;
            std::cout << "\n  Buffer A ready pulse detected at sample " << i << std::endl;
        }
    }

    dut->mic_valid_i = 0;
    for (int i = 0; i < 5; i++) tick();

    if (!buffer_a_valid) {
        std::cerr << "FAIL (Buffer A not marked valid)" << std::endl;
        error_count++;
    } else if (dut->active_buf_o != 1) {
        std::cerr << "FAIL (active_buf_o should be 1)" << std::endl;
        error_count++;
    } else {
        std::cout << "  PASS" << std::endl;
    }

    // Test 3: Fill buffer B
    std::cout << "Test 3: Filling buffer B with " << SAMPLES_PER_BUF << " samples - ";
    for (int i = 0; i < SAMPLES_PER_BUF; i++) {
        dut->mic_valid_i = 1;
        dut->mic_data_i[0] = current_sample_value;

        if (dut->active_buf_o == 0) {
            golden_buffer_a[sample_count % SAMPLES_PER_BUF] = current_sample_value;
        } else {
            golden_buffer_b[sample_count % SAMPLES_PER_BUF] = current_sample_value;
        }

        current_sample_value++;
        sample_count++;
        tick();

        if (dut->buf_ready_pulse_o) {
            buffer_b_valid = true;
            std::cout << "\n  Buffer B ready pulse detected at sample " << i << std::endl;
        }
    }

    dut->mic_valid_i = 0;
    for (int i = 0; i < 5; i++) tick();

    if (!buffer_b_valid) {
        std::cerr << "FAIL (Buffer B not marked valid)" << std::endl;
        error_count++;
    } else if (dut->active_buf_o != 0) {
        std::cerr << "FAIL (active_buf_o should be 0)" << std::endl;
        error_count++;
    } else {
        std::cout << "  PASS" << std::endl;
    }

    // Test 4: Verify pulse is single-cycle
    std::cout << "Test 4: Verifying single-cycle pulse - ";
    int pulse_count = 0;
    bool last_pulse = false;
    bool multi_cycle_error = false;

    for (int i = 0; i < SAMPLES_PER_BUF + 10; i++) {
        if (i < SAMPLES_PER_BUF) {
            dut->mic_valid_i = 1;
            dut->mic_data_i[0] = current_sample_value++;
        } else {
            dut->mic_valid_i = 0;
        }

        tick();

        if (dut->buf_ready_pulse_o) {
            pulse_count++;
            if (last_pulse) {
                multi_cycle_error = true;
            }
            last_pulse = true;
        } else {
            last_pulse = false;
        }
    }

    if (pulse_count != 1) {
        std::cerr << "FAIL (Expected 1 pulse, got " << pulse_count << ")" << std::endl;
        error_count++;
    } else if (multi_cycle_error) {
        std::cerr << "FAIL (Pulse not single-cycle)" << std::endl;
        error_count++;
    } else {
        std::cout << "PASS" << std::endl;
    }

    // Test 5: Verify channel ID
    std::cout << "Test 5: Verifying channel ID - ";
    if (dut->buf_ready_ch_o != 0) {
        std::cerr << "FAIL (buf_ready_ch_o should be 0, got " << (int)dut->buf_ready_ch_o << ")" << std::endl;
        error_count++;
    } else {
        std::cout << "PASS" << std::endl;
    }

    // Results
    std::cout << "\n========================================" << std::endl;
    if (error_count == 0) {
        std::cout << "SAMPLER: PASS" << std::endl;
        std::cout << "All tests passed successfully!" << std::endl;
    } else {
        std::cout << "SAMPLER: FAIL (" << error_count << " errors)" << std::endl;
    }
    std::cout << "========================================" << std::endl;

    dut->final();
    delete dut;
    return (error_count == 0) ? 0 : 1;
}
