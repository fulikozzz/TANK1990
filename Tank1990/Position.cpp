#include "Position.h"

Position::Position(int x, int y) {
	this->x = x;
	this->y = y;
}

int Position::getX() { return x; }

int Position::getY() { return y; }
void Position::setX(int value) { x = value; }
void Position::setY(int value) { y = value; }
void Position::setPosition(int newX, int newY) { x = newX;	y = newY; }