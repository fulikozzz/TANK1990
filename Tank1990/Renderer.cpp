#include "Renderer.h"

Renderer::Renderer(Map^ map) {
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
    this->player_up = Image::FromFile("textures\\ptank_up.png");
    this->player_left = Image::FromFile("textures\\ptank_left.png");
    this->player_right = Image::FromFile("textures\\ptank_right.png");
    this->player_down = Image::FromFile("textures\\ptank_down.png");
}

void Renderer::drawMap(Graphics^ g) {
    for (int y = 0; y < map->getHeight(); ++y) {
        for (int x = 0; x < map->getWidth(); ++x) {
            switch (map->getCell(y, x)) {
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

void Renderer::drawPlayer(Graphics^ g, Player_Tank^ player1) {
    if (player1 != nullptr) {

        Image^ sprite;
        switch (player1->getDirection())
        {
        case UP:
            sprite = player_up;
            break;
        case LEFT:
            sprite = player_left;
            break;
        case RIGHT:
            sprite = player_right;
            break;
        case DOWN:
            sprite = player_down;
            break;
        }

        g->DrawImage(sprite,
            player1->getPosition()->getX(),
            player1->getPosition()->getY(),
            cellSize, cellSize);
    }
}