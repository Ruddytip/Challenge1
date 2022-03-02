#include <ctime>
#include "engine.hpp"

engine::engine(int size_x, int size_y):
scr(size_x, size_y), running(true), FPS(0){
    setup();
}

engine::~engine(){
    scr.~screen();
}

void engine::run(){
    while(running){
        unsigned int start_time =  clock();
        board_logic();
        game_logic();
        screen_logic();
        unsigned int end_time = clock();
        FPS = 1000 / (end_time - start_time + 1);
    }
}

void engine::close(){
    running = false;
    scr.~screen();
}