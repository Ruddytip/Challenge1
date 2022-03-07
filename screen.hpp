#pragma once
#include <iostream>

// Список символов для отображения
enum ESymbols{
    Empty = ' ',
    Wall = '#',
    Body = 'S',
    Ball = '*',
    Error = '~'
};

// Список цветов
namespace COLORS{
    const std::string RED = "\x1B[31m";
    const std::string GREEN = "\x1B[32m";
    const std::string YELLOW = "\x1B[33m";
    const std::string BLUE = "\x1B[34m";
    const std::string PURPULE = "\x1B[35m";
    const std::string WHITE = "\x1B[37m";
    const std::string DEFAULT = "\x1B[0m";
};

// Класс окна в консоли
class CScreen{
private:
    uint8_t Width, Height; // Ширина и высота отображаемой области    
    std::string* sScreenBuffer; // Буфер эерана для отображения
    struct SPixel{ // Буфер виртуальных пикселей
        char Symbol; // Символ пикселя
        std::string Color; // Цвет пикселя
    }** pBuffer;
    SPixel getPixel(uint8_t x, uint8_t y); // Возвращает виртуальный пиксель
public:
    CScreen(uint8_t size_x, uint8_t size_y); // Конструктор экрана, задаёт ширину и высоту
    ~CScreen();
    uint8_t get_width(); // Возвращает ширину экрана
    uint8_t get_height(); // Возвращает высоту экрана
    char getSymbol(uint8_t x, uint8_t y); // Возвращает символ в указанных координатах
    std::string getColor(uint8_t x, uint8_t y); // возвращает цвет в указанных координатах
    void printBuffer(); // Выводит на экран содержимое буфера экрана
    void clearBuffer(); // Очищает буфер экрана
    // Устанавливает в указанных координатах символ и его цвет
    void setPixel(uint8_t x, uint8_t y, char symbol, std::string color);
    void refreshScreen(); // Обновляет содержимое экрана
    // Устанавливает в указанных координатах строку text с цветом color
    void setText(uint8_t x, uint8_t y, std::string text, std::string color);
    // Устанавливает в указанных координатах строку юникода text с цветом color
    void setUnicodeText(uint8_t x, uint8_t y, std::string text, std::string color);
    void convetrBuffers(); // Конвертирует буфер виртуальных пикселей в буфер экрана
};