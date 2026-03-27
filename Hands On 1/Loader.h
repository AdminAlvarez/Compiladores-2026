#ifndef LOADER_H
#define LOADER_H

#include "Memory.h"
#include <vector>
#include <string>

class Loader {
public:
    void loadProgram(std::vector<std::string> program, Memory &mem);
};

#endif