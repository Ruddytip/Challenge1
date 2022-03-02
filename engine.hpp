#pragma once
#include "keyboard.hpp"
#include "graphics.hpp"


class engine{
private:
    screen scr;
    keyboard brd;
    bool running;
    unsigned int FPS;
public:
    engine(int size_x, int size_y);
    ~engine();
    void run();
    void game_logic();
    void screen_logic();
    void board_logic();
    void close();
    void setup();
};