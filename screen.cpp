#include "screen.hpp"

/*В программе используются Escape-код
Перемещение курсора вверх на N строк: \033[NA
Перемещение курсора вниз на N строк: \033[NB
Перемещение курсора вперед на N столбцов: \033[NC
Перемещение курсора назад на N столбцов: \033[ND
Стереть до конца строки: \033[K*/

CScreen::CScreen(int size_x, int size_y):
Width(size_x), Height(size_y){
    ScreenBuffer = new std::string[Height];
    clearBuffer();
    printBuffer();
}

CScreen::~CScreen(){
    delete[] ScreenBuffer;
}

uint8_t CScreen::get_width(){
    return Width;
}

uint8_t CScreen::get_height(){
    return Height;
}

std::string* CScreen::get_buff(){
    return ScreenBuffer;
}

void CScreen::printBuffer(){
    for(int i = 0; i < Height; ++i)
        std::cout << ScreenBuffer[i] << std::endl;
}

void CScreen::clearBuffer(){
    for(int i = 0; i < Height; ++i)
        ScreenBuffer[i] = std::string(Width, Empty);
}

void CScreen::setSymbol(int x, int y, char symbol){
    if(x < 0 || y < 0) return;
    if(x >= Width || y >= Height) return;
    ScreenBuffer[y][x] = symbol;
}

char CScreen::getSymbol(int x, int y){
    if(x < 0 || y < 0) return Error;
    if(x >= Width || y >= Height) return Error;
    return ScreenBuffer[y][x];
}

void CScreen::refreshScreen(){
    for(int i = 0; i < Height; ++i) std::cout << "\033[1A";
    printBuffer();
}

void CScreen::setColor(std::string color){
    std::cout << color;
}