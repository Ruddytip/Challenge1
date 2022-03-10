#include <iostream>
#include <vector>
#include "screen.hpp" // Подключение класса экрана

class CObject{
private:
    uint8_t x, y;
    char symbol;
    std::string color;
public:
    CObject(uint8_t _x, uint8_t _y, char _symbol, std::string _color);
    ~CObject();
    void setPos(uint8_t _x, uint8_t _y);
    void setSymbol(char _symbol);
    void setColor(std::string _color);
    uint8_t getX();
    uint8_t getY();
    char getSymbol();
    std::string getColor();
};

enum EMove{
    Up = '^',
    Left = '<',
    Down = 'V',
    Right = '>'
};

class CSnake{
private:
    std::vector<CObject> body;
    char direction;
public:
    CSnake(uint8_t _x, uint8_t _y, char _dir);
    ~CSnake();
    void setDirection(char _dir);
    char getDirection();
    int getLength();
    CObject getHead();
    CObject getSegment(int _index);
    void push(CObject _segment);
    void pop();
    char checkCollision(CScreen* scr);
    void print(CScreen* scr);
    void move();
    void eatApple(CObject* _app);
};