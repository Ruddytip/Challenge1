#include "keyboard.hpp"

keyboard::keyboard(): key(0){

}

keyboard::~keyboard(){

}

void keyboard::checkPress(){
    key = (kbhit()? getch() : 0);
}

bool keyboard::keyPress(unsigned int symbol){
    return (key == symbol);
}