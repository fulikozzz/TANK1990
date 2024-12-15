#pragma once

#include <string>
#include <vector>

ref class Map
{
private:
    int width;          // 20
    int height;         // 20
    array<wchar_t, 2>^ grid;

public:

    Map();

    void loadFromFile(System::String^ filePath);
    int getWidth();
    int getHeight();
    char getCell(int x, int y);

};