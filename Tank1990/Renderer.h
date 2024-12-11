#pragma once
#include "Map.h"

using namespace System::Drawing;

ref class Renderer {
private:
    Map^ map;
    Image^ iron_wall;
    Image^ wooden_wall;
    Image^ brick_wall_high;
    Image^ brick_wall_half;
    Image^ brick_wall_low;
    Image^ tree;
    Image^ ice;
    Image^ water;
    Image^ player_base;
    Image^ enemy_base;
    int cellSize = 54;

public:
    Renderer(Map^ map, int cellSize) {
        this->map = map;
        this->cellSize = cellSize;
        this->iron_wall = Image::FromFile("textures\\iron_wall.png");
        this->wooden_wall = Image::FromFile("textures\\wooden_wall.png");
        this->brick_wall_high = Image::FromFile("textures\\birck_wall_high.png");
        this->brick_wall_half = Image::FromFile("textures\\brick_wall_half.png");
        this->brick_wall_low = Image::FromFile("textures\\brick_wall_low.png");
        this->tree = Image::FromFile("textures\\tree.png");
        this->ice = Image::FromFile("textures\\ice.png");
        this->water = Image::FromFile("textures\\water.png");
        this->player_base = Image::FromFile("textures\\player_base.png");
        this->enemy_base = Image::FromFile("textures\\enemy_base.png");
    }

    void Draw(Graphics^ g) {
        for (int y = 0; y < map->GetRows(); ++y) {
            for (int x = 0; x < map->GetCols(); ++x) {
                switch (map->GetCell(y, x)) {
                case '1':
                    g->DrawImage(iron_wall, x * cellSize, y * cellSize, cellSize, cellSize);
                    break;
                case '2':
                    g->DrawImage(wooden_wall, x * cellSize, y * cellSize, cellSize, cellSize);
                    break;

                case '3':
                    g->DrawImage(brick_wall_high, x * cellSize, y * cellSize, cellSize, cellSize);
                    break;

                case '4':
                    g->DrawImage(brick_wall_half, x * cellSize, y * cellSize, cellSize, cellSize);
                    break;

                case '5':
                    g->DrawImage(brick_wall_low, x * cellSize, y * cellSize, cellSize, cellSize);
                    break;

                case '6':
                    g->DrawImage(tree, x * cellSize, y * cellSize, cellSize, cellSize);
                    break;

                case '7':
                    g->DrawImage(ice, x * cellSize, y * cellSize, cellSize, cellSize);
                    break;

                case '8':
                    g->DrawImage(water, x * cellSize, y * cellSize, cellSize, cellSize);
                    break;

                case 'p':
                    g->DrawImage(player_base, x * cellSize, y * cellSize, cellSize, cellSize);
                    break;

                case 'e':
                    g->DrawImage(enemy_base, x * cellSize, y * cellSize, cellSize, cellSize);
                    break;

                default:
                    break;
                }
            }
        }
    }
};
