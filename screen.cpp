#include "screen.hpp"

/*В программе используются Escape-код
Перемещение курсора вверх на N строк: \033[NA
Перемещение курсора вниз на N строк: \033[NB
Перемещение курсора вперед на N столбцов: \033[NC
Перемещение курсора назад на N столбцов: \033[ND
Стереть до конца строки: \033[K*/

CScreen::CScreen(uint8_t size_x, uint8_t size_y):
Width(size_x), Height(size_y){
    pBuffer = new SPixel*[Height];
    for(int j = 0; j < Height; ++j){
        pBuffer[j] = new SPixel[Width];
        for(int i = 0; i < Width; ++i){
            pBuffer[j][i] = SPixel{Empty, COLORS::DEFAULT};
        }
    }
    sScreenBuffer = new std::string[Height];
    clearBuffer();
    printBuffer();
}

CScreen::~CScreen(){
    for(int i = 0; i < Height; ++i) delete[] pBuffer[i];
    delete[] pBuffer;
    delete[] sScreenBuffer;
}

uint8_t CScreen::get_width(){
    return Width;
}

uint8_t CScreen::get_height(){
    return Height;
}

char CScreen::getSymbol(uint8_t x, uint8_t y){
    if(x < 0 || x >= Width) return Error;
    if(y < 0 || y >= Height) return Error;
    return pBuffer[y][x].Symbol;
}

std::string CScreen::getColor(uint8_t x, uint8_t y){
    if(x < 0 || x >= Width) return COLORS::DEFAULT;
    if(y < 0 || y >= Height) return COLORS::DEFAULT;
    return pBuffer[y][x].Color;
}

void CScreen::printBuffer(){
    for(int i = 0; i < Height; ++i)
        std::cout << sScreenBuffer[i] << std::endl;
}

void CScreen::clearBuffer(){
    for(int i = 0; i < Height; ++i)
        sScreenBuffer[i].clear();
}

void CScreen::setPixel(uint8_t x, uint8_t y, char symbol, std::string color){
    if(x < 0 || y < 0) return;
    if(x >= Width || y >= Height) return;
    pBuffer[y][x].Symbol = symbol;
    pBuffer[y][x].Color = color;
}

void CScreen::refreshScreen(){
    for(int i = 0; i < Height; ++i) std::cout << "\033[1A";
    convetrBuffers();
    printBuffer();
    clearBuffer();
}

void CScreen::setText(uint8_t x, uint8_t y, std::string text, std::string color){
    for(int i = 0; i < text.length(); ++i){
        if((x + i < 0) || (x + i >= Width)) continue;
        if((y < 0) || (y >= Height)) continue;
        pBuffer[y][x + i].Symbol = text[i];
        pBuffer[y][x + i].Color = color;
    }
}

void CScreen::setUnicodeText(uint8_t x, uint8_t y, std::string text, std::string color){
    // if(x < 0 || x >= Width) return;
    // if(y < 0 || y >= Height) return;
    // std::cout << color;
    // for(int i = 0; i < y; ++i) std::cout << "\033[1B";
    // for(int i = 0; i < x; ++i) std::cout << "\033[1C";
    // std::cout << text;
    // for(int i = 0; i < y; ++i) std::cout << "\033[1A";
    // std::cout << COLORS::DEFAULT;
}

void CScreen::convetrBuffers(){
    for(int j = 0; j < Height; ++j){
        for(int i = 0; i < Width; ++i){
            sScreenBuffer[j]+= pBuffer[j][i].Color;
            sScreenBuffer[j]+= pBuffer[j][i].Symbol;
            sScreenBuffer[j]+= COLORS::DEFAULT;
        }
    }
}
