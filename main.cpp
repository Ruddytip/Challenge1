#include "screen.hpp" // Подключение класса экрана
#include "keyboard.hpp" // Подключение класа клавиатуры
#include <unistd.h> // Задержка

int main(){
    CScreen scr(80, 20);

    uint8_t x(1), y(5);
    uint8_t dx(scr.get_width()), dy(scr.get_height());
    
    for(int j = 0; j < dy; ++j){
        for(int i = 0; i < dx; ++i){
            if(i == 0 || j == 0) {scr.setPixel(i, j, Wall, COLORS::BLUE);}
            if(i == dx - 1 || j == dy - 1) {scr.setPixel(i, j, Wall, COLORS::BLUE);}
        }
    }



    while(true){
        KEY::checkPress();
        scr.setPixel(x, y, Empty, COLORS::DEFAULT);

        if(KEY::keyPress(KEY::W)) y-=1;
        if(KEY::keyPress(KEY::A)) x-=1;
        if(KEY::keyPress(KEY::S)) y+=1;
        if(KEY::keyPress(KEY::D)) x+=1;
        if(KEY::keyPress(KEY::Escape)) break;

        scr.setPixel(x, y, Ball, COLORS::GREEN);

        scr.refreshScreen();
        // usleep(50000); // Задержка в 50 милисекунд
    }
    
    return 0;
}