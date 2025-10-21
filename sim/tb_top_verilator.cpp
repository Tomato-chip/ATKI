// Verilator C++ testbench wrapper
#include <verilated.h>
#include "Vi2s_clock_gen_tb_verilator.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vi2s_clock_gen_tb_verilator* tb = new Vi2s_clock_gen_tb_verilator;

    // Run simulation
    while (!Verilated::gotFinish()) {
        tb->eval();
    }

    delete tb;
    return 0;
}
