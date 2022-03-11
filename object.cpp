#include "object.hpp"

CObject::CObject(uint8_t _x, uint8_t _y, char _symbol, std::string _color):
x(_x), y(_y), symbol(_symbol), color(_color){}

CObject::~CObject(){}

void CObject::setPos(uint8_t _x, uint8_t _y){x = _x; y = _y;}

void CObject::setSymbol(char _symbol){symbol = _symbol;}

void CObject::setColor(std::string _color){color = _color;}

uint8_t CObject::getX(){return x;}

uint8_t CObject::getY(){return y;}

char CObject::getSymbol(){return symbol;}

std::string CObject::getColor(){return color;}



CSnake::CSnake(uint8_t _x, uint8_t _y, char _dir):direction(_dir){
    CObject head(_x, _x, _dir, COLORS::GREEN);
    push(head);
}

CSnake::~CSnake(){

}

void CSnake::setDirection(char _dir){direction = _dir;}

char CSnake::getDirection(){return direction;}

int CSnake::getLength(){return body.size();}

CObject CSnake::getHead(){return body[0];}

CObject CSnake::getSegment(int _index){return body[_index];}

void CSnake::push(CObject _segment){body.push_back(_segment);}

void CSnake::pop(){body.pop_back();}

char CSnake::checkCollision(CScreen* _scr){
    uint8_t x = getHead().getX();
    uint8_t y = getHead().getY();
    switch (direction){
    case Up:    --y; break;
    case Left:  --x; break;
    case Down:  ++y; break;
    case Right: ++x; break;
    }

    char symbol = _scr->getSymbol(x, y);
    switch (symbol){
    case Empty: return Empty; break;
    case Wall: return Wall; break;
    case Body: return Body; break;
    case Apple: return Apple; break;
    default: return Error; break;
    }
}

void CSnake::print(CScreen* _scr){
    for(auto i = body.begin(); i <= body.end(); ++i){
        _scr->setPixel(i->getX(), i->getY(), i->getSymbol(), i->getColor());
    }
}

void CSnake::move(){
    for(int i = getLength() - 1; i > 0; --i){
        body[i] = body[i - 1];
    }
    uint8_t x = getHead().getX();
    uint8_t y = getHead().getY();
    switch (direction){
    case Up:    --y; break;
    case Left:  --x; break;
    case Down:  ++y; break;
    case Right: ++x; break;
    }
    body[0].setPos(x, y);
}

void CSnake::eatApple(CObject* _app){
    CObject tail = body[getLength() - 1];
    move();
    push(tail);
    _app->setPos(rand()%50 + 10, rand()%30 + 10);
}