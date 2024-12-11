#include "Map.h"

Map::Map(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    grid = gcnew array<array<wchar_t>^>(rows);
    for (int i = 0; i < rows; i++) {
        grid[i] = gcnew array<wchar_t>(cols);
    }
}
void Map::LoadFromFile(System::String^ filePath) {
    System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(filePath);
    for (int i = 0; i < rows; ++i) {
        System::String^ line = reader->ReadLine();
        grid[i] = line->ToCharArray();
    }
    reader->Close();
}

wchar_t Map::GetCell(int row, int col) {
    return grid[row][col];
}

int Map::GetRows() { return rows; }
int Map::GetCols() { return cols; }