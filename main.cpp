#include "engine.hpp"

void engine::setup(){
    std::string* buff = scr.get_buff();
    int dx = scr.get_width();
    int dy = scr.get_height();
    for(int x = 0; x < dx; ++x)
        for(int y = 0; y < dy; ++y){
            if(x == 0 || y == 0 || x == dx - 1 || y == dy - 1) buff[y][x] = '#';
    }
}

void engine::game_logic(){
    // _sleep(20);
}

void engine::screen_logic(){
    // system("cls");
    std::cout << "FPS: "<< FPS << std::endl;
    scr.show();
}

void engine::board_logic(){
    brd.checkPress();
    if(brd.keyPress(key::W)) std::cout << "W\n";
    if(brd.keyPress(key::A)) std::cout << "A\n";
    if(brd.keyPress(key::S)) std::cout << "S\n";
    if(brd.keyPress(key::D)) std::cout << "D\n";
    if(brd.keyPress(key::Space)) std::cout << "Space\n";
    if(brd.keyPress(key::Enter)) std::cout << "Enter\n";
    if(brd.keyPress(key::Escape)) close();
}

int main(){
    engine app(20, 10);
    app.run();
    return 0;
}