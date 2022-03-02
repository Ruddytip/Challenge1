#pragma once
#include <windows.h>
#include <iostream>

class screen{
private:
    HANDLE handle;
    unsigned int width, height;
    std::string* buff;
public:
    screen(int size_x, int size_y);
    ~screen();
    int get_width();
    int get_height();
    std::string* get_buff();
    void show();
    void clear();
    void setup();
};