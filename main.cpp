#include "screen.hpp" // Подключение класса экрана
#include "keyboard.hpp" // Для работы клавиатуры
#include "object.hpp" // Класс змейки
#include <ctime> // Для нахождения времени кадра

int main(){
    const uint8_t SIZE_X = 80;
    const uint8_t SIZE_Y = 40;
    CScreen scr(SIZE_X, SIZE_Y);
    CSnake snake(SIZE_X / 2, SIZE_Y / 2, Left);
    CObject apple(SIZE_X / 4, SIZE_Y / 4, Apple, COLORS::RED);

    // Построение стен по периметру экрана==========================================
    for(int j = 0; j < SIZE_Y; ++j){
        for(int i = 0; i < SIZE_X; ++i){
            if(i == 0 || j == 0 || j == 2) {scr.setPixel(i, j, Wall, COLORS::BLUE);}
            if(i == SIZE_X - 1 || j == SIZE_Y - 1) {scr.setPixel(i, j, Wall, COLORS::BLUE);}
        }
    }

    // =============================================================================
    unsigned int FPS(0), start(0), end(0), tickrate(100), tick(0);

    bool gameRun = true;
    while(gameRun){
        start = clock();

        KEY::checkPress();
        if(KEY::keyPress(KEY::W)) if(snake.getDirection() != Down)  snake.setDirection(Up);
        if(KEY::keyPress(KEY::A)) if(snake.getDirection() != Right) snake.setDirection(Left);
        if(KEY::keyPress(KEY::S)) if(snake.getDirection() != Up)    snake.setDirection(Down);
        if(KEY::keyPress(KEY::D)) if(snake.getDirection() != Left)  snake.setDirection(Right);
        if(KEY::keyPress(KEY::Escape)) break;

        scr.setText(1, 1, std::string(78, Empty), COLORS::DEFAULT);
        scr.setText(1, 1, "FPS: " + std::to_string(1000 / (FPS + 1)), COLORS::PURPULE);
        scr.setText(15, 1, "Snake length: " + std::to_string(snake.getLength()), COLORS::YELLOW);
        snake.print(&scr);
        scr.refreshScreen();

        if(++tick >= tickrate){
            switch (snake.checkCollision(&scr)){
                case Empty: snake.move(); break;
                case Apple: snake.eatApple(&apple); break;
                case Body: gameRun = false; break;
                case Wall: gameRun = false; break;
            }
            tick = 0;
            end = clock();
            FPS = end - start;   
        }       
    }

    return 0;
}