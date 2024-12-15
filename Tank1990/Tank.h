#pragma once
#include "Position.h"
#include "Direction.h"

ref class Tank
{
private:
	Position^ position;
	Direction direction;
	int lives;
	int speed;

public:
	Tank(Position^ initPosition, Direction initDirection, int initLives, int initSpeed);

	Position^ getPosition();
	Direction getDirection();
	int getLives();
	int getSpeed();
	void setPosition(Position^ newPosition);
	void setDirection(Direction newDirection);
	void setLives(int value);
	void setSpeed(int value);

	void move();
};

