#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <string>

class Memory {
private:
    std::vector<std::string> instructions;
    std::vector<int> data;

public:
    Memory(int size);

    void loadInstructions(std::vector<std::string> program);
    std::string getInstruction(int index);

    void writeData(int addr, int value);
    int readData(int addr);
};

#endif