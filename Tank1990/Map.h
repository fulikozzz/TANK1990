#pragma once

#include "Wall.h"

#include <string>
#include <vector>

ref class Map
{
private:
    int width;          // 20
    int height;         // 20
    array<Wall^, 2>^ grid;

public:

    Map();

    void loadFromFile(System::String^ filePath);
    int getWidth();
    int getHeight();
    Wall^ getCell(int x, int y);

};