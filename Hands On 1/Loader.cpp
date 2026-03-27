#include "Loader.h"

void Loader::loadProgram(std::vector<std::string> program, Memory &mem) {
    mem.loadInstructions(program);
}