// Verilator C++ testbench wrapper
#include <verilated.h>
#include "Vi2s_clock_gen_tb.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vi2s_clock_gen_tb* tb = new Vi2s_clock_gen_tb;

    // Run simulation
    while (!Verilated::gotFinish()) {
        tb->eval();
    }

    delete tb;
    return 0;
}
