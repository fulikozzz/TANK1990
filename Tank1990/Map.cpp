#include "Map.h"
#include <stdexcept>

Map::Map() {
    width = 20;
    height = 20;
    grid = gcnew array<wchar_t, 2>(height, width);
}

void Map::loadFromFile(System::String^ filePath) {
    System::IO::StreamReader^ reader = nullptr;

    try {
        reader = gcnew System::IO::StreamReader(filePath);

        for (int y = 0; y < height; ++y) {
            System::String^ line = reader->ReadLine();

            if (line == nullptr || line->Length != width) {
                throw gcnew System::Exception("Файл карты не соответствует формату!");
            }

            for (int x = 0; x < width; ++x) {
                grid[y, x] = line[x];
            }
        }
    }
    catch (System::Exception^ e) {
        throw gcnew System::Exception("Ошибка загрузки карты: " + e->Message);
    }
    finally {
        if (reader != nullptr) {
            reader->Close();
        }
    }
}

int Map::getHeight() { return height; }

int Map::getWidth() { return width; }

char Map::getCell(int x, int y) {
    if (x > width || x < 0 || y > height || y < 0) {
        throw std::out_of_range("Координаты за пределами карты.");
    }
    else return grid[x, y];
}