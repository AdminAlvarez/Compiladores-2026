#include "Memory.h"

Memory::Memory(int size) {
    data.resize(size, 0);
}

void Memory::loadInstructions(std::vector<std::string> program) {
    instructions = program;
}

std::string Memory::getInstruction(int index) {
    return instructions[index];
}

void Memory::writeData(int addr, int value) {
    data[addr] = value;
}

int Memory::readData(int addr) {
    return data[addr];
}