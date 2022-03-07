#pragma once
#include <iostream>

enum ESymbols{
    Empty = ' ',
    Wall = '#',
    Body = 'S',
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

class CScreen{
private:
    uint8_t Width, Height;
    std::string* sScreenBuffer;
    struct SPixel{
        char Symbol;
        std::string Color;
    }** pBuffer;
    SPixel getPixel(uint8_t x, uint8_t y);
public:
    CScreen(uint8_t size_x, uint8_t size_y);
    ~CScreen();
    uint8_t get_width();
    uint8_t get_height();
    std::string* getScreenBuff();
    char getSymbol(uint8_t x, uint8_t y);
    std::string getColor(uint8_t x, uint8_t y);
    void printBuffer();
    void clearBuffer();
    void setPixel(uint8_t x, uint8_t y, char symbol, std::string color);
    void refreshScreen();
    void setText(uint8_t x, uint8_t y, std::string text, std::string color);
    void setUnicodeText(uint8_t x, uint8_t y, std::string text, std::string color);
    void convetrBuffers();
};