#pragma once
#include "Map.h"
#include "Player_Tank.h"

using namespace System::Drawing; 

ref class Renderer
{
private:
    Map^ map;

    int cellSize = 54;

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
    Image^ player_up;
    Image^ player_left;
    Image^ player_right;
    Image^ player_down;

public:

    Renderer(Map^ map);

    void drawMap(Graphics^ g);
    void drawPlayer(Graphics^ g, Player_Tank^ player1);
};