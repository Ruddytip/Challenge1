// #include "engine.hpp"

// void engine::setup(){
//     std::string* buff = scr.get_buff();
//     int dx = scr.get_width();
//     int dy = scr.get_height();
//     for(int x = 0; x < dx; ++x)
//         for(int y = 0; y < dy; ++y){
//             if(x == 0 || y == 0 || x == dx - 1 || y == dy - 1) buff[y][x] = '#';
//     }
//     CObject player1(Vec2d(2, 2), Vec2d(1, 4)), player2(Vec2d(dx - 2, 2), Vec2d(1, 4));
//     CObject ball(Vec2d(dx / 2, dy / 2), Vec2d(1, 1));

//     objects.push_back(player1);objects.push_back(player2);
//     objects.push_back(ball);
// }

// void engine::game_logic(){
//     // _sleep(20);
// }

// void engine::screen_logic(){
//     std::cout << "FPS: "<< FPS << std::endl;

//     for(auto iterator = objects.begin(); iterator < objects.end(); ++iterator) {
//             // =======================================================================================================================================================================
//     }

//     scr.show();
// }

// void engine::board_logic(){
//     brd.checkPress();
//     // if(brd.keyPress(key::W)) std::cout << "W\n";
//     // if(brd.keyPress(key::A)) std::cout << "A\n";
//     // if(brd.keyPress(key::S)) std::cout << "S\n";
//     // if(brd.keyPress(key::D)) std::cout << "D\n";
//     // if(brd.keyPress(key::Space)) std::cout << "Space\n";
//     // if(brd.keyPress(key::Enter)) std::cout << "Enter\n";
//     if(brd.keyPress(key::Escape)) close();
// }

#include "screen.hpp"
#include <unistd.h>

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
    bool flag = true;
    int n = 0;
    while(n < 2){
        scr.setPixel(x, y, Empty, COLORS::DEFAULT);
        x = flag ? x + 1 : x - 1;
        if(x == dx - 2 || x == 1) {flag = !flag; ++n;}
        scr.setText(1, 5, std::string("0123456789 Test label!!! Test label!!! Test label!!! Test label!!!"), COLORS::YELLOW);
        scr.setPixel(x, y, Ball, COLORS::GREEN);
        scr.refreshScreen();
        usleep(50000); // Задержка в 50 милисекунд
    }

    return 0;
}