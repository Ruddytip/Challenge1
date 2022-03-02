#pragma once
#include <conio.h>
#include <string>

namespace key{
    const unsigned int W = 119;
    const unsigned int A = 97;
    const unsigned int S = 115;
    const unsigned int D = 100;
    const unsigned int Escape = 27;
    const unsigned int Space = 32;
    const unsigned int Enter = 13;
};

class keyboard{
private:
    unsigned int key;
public:
    keyboard();
    ~keyboard();
    void checkPress();
    bool keyPress(unsigned int symbol);
};