#pragma once
#include <conio.h> // Необходима для kbhit() и getch()

// Список доступных клавиш
namespace KEY{
    const unsigned int W = 119;
    const unsigned int A = 97;
    const unsigned int S = 115;
    const unsigned int D = 100;
    const unsigned int Escape = 27;
    const unsigned int Space = 32;
    const unsigned int Enter = 13;
    unsigned int ID_KEY = 0;
    void checkPress(){
        ID_KEY = (kbhit() ? getch() : 0);
    }
    bool keyPress(unsigned int symbol){
        return (ID_KEY == symbol);
    }
};