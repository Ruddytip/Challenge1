#pragma once
#include <iostream>

enum ESymbols{
    Empty = ' ',
    Wall = '#',
    Body = '!',
    Ball = '*',
    Error = '~'
};

namespace COLORS{
    const std::string RED = "\x1B[31m";
    const std::string GREEN = "\x1B[32m";
    const std::string YELLOW = "\x1B[33m";
    const std::string BLUE = "\x1B[34m";
    const std::string PURPULE = "\x1B[35m";
    const std::string WHITE = "\x1B[37m";
    const std::string DEFAULT = "\x1B[0m";
};

struct SPixel{
    char Symbol;
    std::string Color;
};

class CScreen{
private:
    uint8_t Width, Height;
    std::string* ScreenBuffer;
public:
    CScreen(int size_x, int size_y);
    ~CScreen();
    uint8_t get_width();
    uint8_t get_height();
    std::string* get_buff();
    void printBuffer();
    void clearBuffer();
    void setSymbol(int x, int y, char symbol);
    char getSymbol(int x, int y);
    void refreshScreen();
    void setColor(std::string color);
};