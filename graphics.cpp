#include "graphics.hpp"

/*В программе используются Escape-код
Перемещение курсора вверх на N строк: \033[NA
Перемещение курсора вниз на N строк: \033[NB
Перемещение курсора вперед на N столбцов: \033[NC
Перемещение курсора назад на N столбцов: \033[ND
Стереть до конца строки: \033[K*/

screen::screen(int size_x, int size_y):
width(size_x), height(size_y){
    buff = new std::string[height];
    for(int i = 0; i < height; ++i)
        buff[i] = std::string(width, ' ');
    setup();
}

screen::~screen(){
    delete[] buff;
}

int screen::get_width(){
    return width;
}

int screen::get_height(){
    return height;
}

std::string* screen::get_buff(){
    return buff;
}

void screen::show(){
    // system("cls");
    // for(int i = 0; i < (*buff).length(); ++i){
    //     if(!(i % width)) std::cout << std::endl;
    //     std::cout << (*buff)[i];
    // }
    for(int i = 0; i < height; ++i)
        std::cout << buff[i] << std::endl;
    // for(int i = 0; i < height; ++i) std::cout << "\033[1A";
}

void screen::clear(){

}

void screen::setup(){

}