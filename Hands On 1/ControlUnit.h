#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include "Instruction.h"
#include "CPU.h"
#include "Memory.h"

class ControlUnit {
public:
    void execute(Instruction instr, CPU &cpu, Memory &mem);
};

#endif