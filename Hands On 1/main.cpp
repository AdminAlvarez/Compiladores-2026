#include <iostream>
#include "CPU.h"
#include "Memory.h"
#include "Instruction.h"
#include "ControlUnit.h"
#include "Loader.h"

using namespace std;

int main() {
    CPU cpu;
    Memory memory(256);
    ControlUnit cu;
    Loader loader;

    vector<string> program = {
        "start",
        "move AL 10",
        "move BL 20",
        "add AL BL",
        "sto 100",
        "stop"
    };

    loader.loadProgram(program, memory);

    while (cpu.isRunning()) {

        // FETCH
        cpu.setIR(memory.getInstruction(cpu.getPC()));
        cpu.printState("FETCH");

        // DECODE
        Instruction instr(cpu.getIR());
        cpu.printState("DECODE");

        // EXECUTE
        cu.execute(instr, cpu, memory);
        cpu.printState("EXECUTE");

        cpu.incrementPC();
    }

    cout << "\nResultado en memoria[100]: " << memory.readData(100) << endl;

    return 0;
}