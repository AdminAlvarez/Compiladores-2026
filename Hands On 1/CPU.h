#ifndef CPU_H
#define CPU_H

#include <string>

class CPU {
private:
    int PC, MAR, MBR, ACC;
    int AL, AH, BL, BH;
    std::string IR;
    bool running;

public:
    CPU();

    int& getRegister(std::string reg);

    void setIR(std::string instr);
    std::string getIR();

    int getPC();
    void incrementPC();

    void stop();
    bool isRunning();

    void printState(std::string stage);

    void setMAR(int val);
    void setMBR(int val);
    int getACC();
    void setACC(int val);
};

#endif