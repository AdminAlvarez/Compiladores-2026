#include "ControlUnit.h"
#include <iostream>

void ControlUnit::execute(Instruction instr, CPU &cpu, Memory &mem) {
    std::string op = instr.getName();
    auto args = instr.getArgs();

    if (op == "start") {
        std::cout << "Inicio\n";
    }
    else if (op == "stop") {
        cpu.stop();
    }
    else if (op == "move") {
        int value = stoi(args[1]);
        cpu.getRegister(args[0]) = value;
    }
    else if (op == "add") {
        int &r1 = cpu.getRegister(args[0]);
        int &r2 = cpu.getRegister(args[1]);

        int result = r1 + r2;
        cpu.setACC(result);
        r1 = result;
    }
    else if (op == "sto") {
        int addr = stoi(args[0]);

        cpu.setMAR(addr);
        cpu.setMBR(cpu.getACC());

        mem.writeData(addr, cpu.getACC());
    }
}