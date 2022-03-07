#include "screen.hpp" // Подключение класса экрана
#include "keyboard.hpp" // Для работы клавиатуры
#include <ctime> // Для нахождения времени кадра
#include <vector> 

enum EMove{
    Up = '^',
    Left = '<',
    Down = 'V',
    Right = '>'
};

struct Segment{
    uint8_t x, y;
    char body;
};

int main(){
    CScreen scr(80, 20);

    // Построение стен по периметру экрана==========================================
    uint8_t dx(scr.get_width()), dy(scr.get_height());
    for(int j = 0; j < dy; ++j){
        for(int i = 0; i < dx; ++i){
            if(i == 0 || j == 0 || j == 2) {scr.setPixel(i, j, Wall, COLORS::BLUE);}
            if(i == dx - 1 || j == dy - 1) {scr.setPixel(i, j, Wall, COLORS::BLUE);}
        }
    }

    // =============================================================================
    unsigned int FPS(0), start(0), end(0);
    int tickrate = 100;
    int tick = 0;

    uint8_t x(dx / 2), y(dy / 2);
    char direction(Left);
    std::vector<Segment> snake;
    snake.push_back(Segment{x, y, direction});

    while(true){
        start = clock();

        KEY::checkPress();
        if(KEY::keyPress(KEY::W)) if(direction != Down) direction = Up;
        if(KEY::keyPress(KEY::A)) if(direction != Right) direction = Left;
        if(KEY::keyPress(KEY::S)) if(direction != Up) direction = Down;
        if(KEY::keyPress(KEY::D)) if(direction != Left) direction = Right;
        if(KEY::keyPress(KEY::Escape)) break;

        scr.setText(1, 1, std::string(78, Empty), COLORS::DEFAULT);
        scr.setText(1, 1, "FPS: " + std::to_string(1000 / (FPS + 1)), COLORS::PURPULE);
        scr.setText(15, 1, "Snake length: " + std::to_string(snake.size()), COLORS::YELLOW);

        for(int i = 0; i < snake.size(); ++i){
            scr.setPixel(snake[i].x, snake[i].y, snake[i].body, COLORS::GREEN);
        }

        scr.refreshScreen();
        ++tick;   
        end = clock();
        if(tick >= tickrate){
            switch (direction){
                case Up: --y; break;
                case Left: --x; break;
                case Down: ++y; break;
                case Right: ++x; break;
            }
            snake[0].x = x;
            snake[0].y = y;
            snake[0].body = direction;
            FPS = end - start;   
            tick = 0;
            if(scr.getSymbol(x, y) != Empty){
                break;
            }
        }     
    }
    
    return 0;
}

// =============================================================================