// =============================================================================
// double_buffer_ram_tb_verilator.cpp
// C++ testbench wrapper for Verilator simulation
// =============================================================================

#include <verilated.h>
#include "Vdouble_buffer_ram.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

// Helper class for clock management
class ClockDriver {
public:
    Vdouble_buffer_ram* dut;
    vluint64_t sim_time;

    ClockDriver(Vdouble_buffer_ram* d) : dut(d), sim_time(0) {
        dut->clk_i = 0;
    }

    void tick() {
        dut->clk_i = 0;
        dut->eval();
        sim_time++;

        dut->clk_i = 1;
        dut->eval();
        sim_time++;
    }
};

int main(int argc, char** argv) {
    const int DATA_WIDTH = 16;
    const int SAMPLES_PER_BUF = 256;
    const int ADDR_WIDTH = 8;

    Verilated::commandArgs(argc, argv);
    Vdouble_buffer_ram* dut = new Vdouble_buffer_ram;
    ClockDriver clk(dut);

    int error_count = 0;
    std::vector<uint16_t> golden_buffer_a(SAMPLES_PER_BUF, 0);
    std::vector<uint16_t> golden_buffer_b(SAMPLES_PER_BUF, 0);
    bool buffer_a_valid = false;
    bool buffer_b_valid = false;
    int write_count = 0;
    uint16_t current_write_value = 0x1000;

    std::cout << "================================================================================" << std::endl;
    std::cout << "DOUBLE_BUFFER_RAM TESTBENCH (Verilator)" << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << "Parameters: DATA_WIDTH=" << DATA_WIDTH
              << ", SAMPLES_PER_BUF=" << SAMPLES_PER_BUF
              << ", ADDR_WIDTH=" << ADDR_WIDTH << std::endl;
    std::cout << "================================================================================" << std::endl;

    // Initialize random seed
    srand(time(NULL));

    // =========================================================================
    // Test 1: Reset
    // =========================================================================
    std::cout << "\n[TEST 1] Reset and initialization" << std::endl;
    dut->rst_ni = 0;
    dut->in_valid_i = 0;
    dut->in_data_i = 0;
    dut->rd_addr_i = 0;
    dut->rd_en_i = 0;

    for (int i = 0; i < 10; i++) {
        clk.tick();
    }

    dut->rst_ni = 1;
    clk.tick();
    clk.tick();

    if (dut->active_buf_o != 0) {
        std::cerr << "ERROR: Initial active_buf should be 0" << std::endl;
        error_count++;
    }

    std::cout << "Reset complete" << std::endl;

    // =========================================================================
    // Test 2: Fill buffer A
    // =========================================================================
    std::cout << "\n[TEST 2] Filling buffer A with " << SAMPLES_PER_BUF << " samples" << std::endl;

    for (int i = 0; i < SAMPLES_PER_BUF; i++) {
        dut->in_valid_i = 1;
        dut->in_data_i = current_write_value;

        if (dut->active_buf_o == 0) {
            golden_buffer_a[write_count % SAMPLES_PER_BUF] = current_write_value;
        } else {
            golden_buffer_b[write_count % SAMPLES_PER_BUF] = current_write_value;
        }

        current_write_value++;
        write_count++;

        clk.tick();

        // Check for buffer ready pulse
        if (dut->buf_ready_pulse_o) {
            std::cout << "Buffer ready pulse: buffer "
                      << (dut->buf_ready_id_o ? "B" : "A")
                      << " filled (ID=" << (int)dut->buf_ready_id_o << ")" << std::endl;

            if (dut->buf_ready_id_o == 0) {
                buffer_a_valid = true;
            } else {
                buffer_b_valid = true;
            }
        }
    }

    dut->in_valid_i = 0;
    for (int i = 0; i < 5; i++) clk.tick();

    if (!buffer_a_valid) {
        std::cerr << "ERROR: Buffer A should be marked valid" << std::endl;
        error_count++;
    }

    if (dut->active_buf_o != 1) {
        std::cerr << "ERROR: After filling buffer A, active_buf should be 1" << std::endl;
        error_count++;
    }

    // =========================================================================
    // Test 3: Fill buffer B while reading buffer A
    // =========================================================================
    std::cout << "\n[TEST 3] Filling buffer B while reading buffer A" << std::endl;

    int read_errors = 0;
    for (int i = 0; i < SAMPLES_PER_BUF; i++) {
        // Write to buffer B
        dut->in_valid_i = 1;
        dut->in_data_i = current_write_value;

        if (dut->active_buf_o == 0) {
            golden_buffer_a[write_count % SAMPLES_PER_BUF] = current_write_value;
        } else {
            golden_buffer_b[write_count % SAMPLES_PER_BUF] = current_write_value;
        }

        current_write_value++;
        write_count++;

        // Read from buffer A (if i > 2 to account for latency)
        if (i < SAMPLES_PER_BUF - 3) {
            dut->rd_addr_i = i;
            dut->rd_en_i = 1;
        }

        clk.tick();

        // Check read data (with 1-cycle latency)
        if (i >= 2 && i < SAMPLES_PER_BUF - 1 && dut->rd_data_valid_o) {
            uint16_t expected = golden_buffer_a[i - 1];
            if (dut->rd_data_o != expected) {
                std::cerr << "ERROR: Readback mismatch at addr=" << (i-1)
                          << ": expected=0x" << std::hex << expected
                          << ", got=0x" << dut->rd_data_o << std::dec << std::endl;
                read_errors++;
            }
        }

        // Check for buffer ready pulse
        if (dut->buf_ready_pulse_o) {
            std::cout << "Buffer ready pulse: buffer "
                      << (dut->buf_ready_id_o ? "B" : "A")
                      << " filled" << std::endl;

            if (dut->buf_ready_id_o == 1) {
                buffer_b_valid = true;
            }
        }
    }

    dut->in_valid_i = 0;
    dut->rd_en_i = 0;
    for (int i = 0; i < 5; i++) clk.tick();

    if (read_errors == 0) {
        std::cout << "Buffer A verification PASSED" << std::endl;
    } else {
        std::cout << "Buffer A verification FAILED with " << read_errors << " errors" << std::endl;
        error_count += read_errors;
    }

    if (!buffer_b_valid) {
        std::cerr << "ERROR: Buffer B should be marked valid" << std::endl;
        error_count++;
    }

    // =========================================================================
    // Test 4: Fill buffer A while reading buffer B
    // =========================================================================
    std::cout << "\n[TEST 4] Filling buffer A while reading buffer B" << std::endl;

    read_errors = 0;
    for (int i = 0; i < SAMPLES_PER_BUF; i++) {
        // Write to buffer A
        dut->in_valid_i = 1;
        dut->in_data_i = current_write_value;

        if (dut->active_buf_o == 0) {
            golden_buffer_a[write_count % SAMPLES_PER_BUF] = current_write_value;
        } else {
            golden_buffer_b[write_count % SAMPLES_PER_BUF] = current_write_value;
        }

        current_write_value++;
        write_count++;

        // Read from buffer B
        if (i < SAMPLES_PER_BUF - 3) {
            dut->rd_addr_i = i;
            dut->rd_en_i = 1;
        }

        clk.tick();

        // Check read data
        if (i >= 2 && i < SAMPLES_PER_BUF - 1 && dut->rd_data_valid_o) {
            uint16_t expected = golden_buffer_b[i - 1];
            if (dut->rd_data_o != expected) {
                std::cerr << "ERROR: Readback mismatch at addr=" << (i-1)
                          << ": expected=0x" << std::hex << expected
                          << ", got=0x" << dut->rd_data_o << std::dec << std::endl;
                read_errors++;
            }
        }

        if (dut->buf_ready_pulse_o) {
            std::cout << "Buffer ready pulse: buffer "
                      << (dut->buf_ready_id_o ? "B" : "A")
                      << " filled" << std::endl;
        }
    }

    dut->in_valid_i = 0;
    dut->rd_en_i = 0;
    for (int i = 0; i < 5; i++) clk.tick();

    if (read_errors == 0) {
        std::cout << "Buffer B verification PASSED" << std::endl;
    } else {
        std::cout << "Buffer B verification FAILED with " << read_errors << " errors" << std::endl;
        error_count += read_errors;
    }

    // =========================================================================
    // Test 5: Verify buf_ready_pulse is 1-cycle wide
    // =========================================================================
    std::cout << "\n[TEST 5] Verifying buf_ready_pulse timing" << std::endl;

    int pulse_count = 0;
    bool last_pulse = false;

    for (int i = 0; i < SAMPLES_PER_BUF + 10; i++) {
        dut->in_valid_i = (i < SAMPLES_PER_BUF) ? 1 : 0;
        dut->in_data_i = current_write_value++;

        clk.tick();

        if (dut->buf_ready_pulse_o) {
            pulse_count++;
            if (last_pulse) {
                std::cerr << "ERROR: buf_ready_pulse_o not 1-cycle wide!" << std::endl;
                error_count++;
            }
            last_pulse = true;
        } else {
            last_pulse = false;
        }
    }

    if (pulse_count != 1) {
        std::cerr << "ERROR: Expected 1 pulse, got " << pulse_count << std::endl;
        error_count++;
    } else {
        std::cout << "Pulse timing verification PASSED" << std::endl;
    }

    // =========================================================================
    // Final results
    // =========================================================================
    std::cout << "\n================================================================================" << std::endl;
    std::cout << "TEST COMPLETE" << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << "Total errors: " << error_count << std::endl;

    if (error_count == 0) {
        std::cout << "DOUBLE_BUFFER_RAM: PASS" << std::endl;
        std::cout << "All tests passed successfully!" << std::endl;
    } else {
        std::cout << "DOUBLE_BUFFER_RAM: FAIL" << std::endl;
        std::cerr << "Test failed with " << error_count << " errors" << std::endl;
    }

    std::cout << "================================================================================" << std::endl;

    // Cleanup
    dut->final();
    delete dut;

    return (error_count == 0) ? 0 : 1;
}
