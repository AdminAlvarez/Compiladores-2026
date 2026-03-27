#include "CPU.h"
#include <iostream>

CPU::CPU() {
    PC = MAR = MBR = ACC = 0;
    AL = AH = BL = BH = 0;
    IR = "";
    running = true;
}

int& CPU::getRegister(std::string reg) {
    if (reg == "AL") return AL;
    if (reg == "AH") return AH;
    if (reg == "BL") return BL;
    if (reg == "BH") return BH;

    throw std::runtime_error("Registro inválido");
}

void CPU::setIR(std::string instr) { IR = instr; }
std::string CPU::getIR() { return IR; }

int CPU::getPC() { return PC; }
void CPU::incrementPC() { PC++; }

void CPU::stop() { running = false; }
bool CPU::isRunning() { return running; }

void CPU::setMAR(int val) { MAR = val; }
void CPU::setMBR(int val) { MBR = val; }
int CPU::getACC() { return ACC; }
void CPU::setACC(int val) { ACC = val; }

void CPU::printState(std::string stage) {
    std::cout << "\n=== " << stage << " ===\n";
    std::cout << "PC: " << PC << "\nIR: " << IR << "\nACC: " << ACC << std::endl;
    std::cout << "MAR: " << MAR << " MBR: " << MBR << std::endl;
    std::cout << "AL: " << AL << " AH: " << AH << std::endl;
    std::cout << "BL: " << BL << " BH: " << BH << std::endl;
}