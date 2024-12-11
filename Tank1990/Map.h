#pragma once
#include <string>
#include <vector>

ref class Map
{
private:
    array<array<wchar_t>^>^ grid; 
    int rows;
    int cols;

public:
    Map(int rows, int cols);
    void LoadFromFile(System::String^ filePath);

    wchar_t GetCell(int row, int col);

    int GetRows();
    int GetCols();
};

