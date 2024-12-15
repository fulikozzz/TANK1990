#include "Map.h"
#include <stdexcept>

Map::Map() {
    width = 20;
    height = 20;
    grid = gcnew array<Wall^, 2>(height, width);
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
                WallType type;
                switch (line[x])
                {
                case '1': type = IronWall; break;
                case '2': type = WoodenWall; break;
                case '3': type = BrickWallHigh; break;
                case '4': type = BrickWallHalf; break;
                case '5': type = BrickWallLow; break;
                case '6': type = Tree; break;
                case '7': type = Ice; break;
                case '8': type = Water; break;
                case 'p': type = Player_Base; break;
                case 'e': type = Enemy_Base; break;
                default: type = Empty; break;
                }
                grid[y, x] = gcnew Wall(gcnew Position(x, y), type);
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

Wall^ Map::getCell(int x, int y) {
    if (x > width || x < 0 || y > height || y < 0) {
        throw std::out_of_range("Координаты за пределами карты.");
    }
    else return grid[x, y];
}