#include "Instruction.h"
#include <sstream>

Instruction::Instruction(std::string line) {
    std::stringstream ss(line);
    ss >> name;

    std::string arg;
    while (ss >> arg) {
        if (arg.back() == ',') arg.pop_back();
        args.push_back(arg);
    }
}

std::string Instruction::getName() {
    return name;
}

std::vector<std::string> Instruction::getArgs() {
    return args;
}