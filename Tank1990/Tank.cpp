#include "Tank.h"

Tank::Tank(Position^ initPosition, Direction initDirection, int initLives, int initSpeed) :
	position(initPosition), direction(initDirection), lives(initLives), speed(initSpeed) {}

Position^ Tank::getPosition() { return position; }
Direction Tank::getDirection() { return direction; }
int Tank::getLives() { return lives; }
int Tank::getSpeed() { return speed; }
void Tank::setPosition(Position^ newPosition) { position = newPosition; }
void Tank::setDirection(Direction newDirection) { direction = newDirection; }
void Tank::setLives(int value) { lives = value; }
void Tank::setSpeed(int value) { speed = value; }

void Tank::move() {
	if (!checkCollision(position->getX(), position->getY(), direction)) {
		switch (direction)
		{
		case UP:
			position->setY(position->getY() - speed);
			break;
		case RIGHT:
			position->setX(position->getX() + speed);
			break;
		case DOWN:
			position->setY(position->getY() + speed);
			break;
		case LEFT:
			position->setX(position->getX() - speed);
			break;
		default:
			break;
		}
	}
}

bool Tank::checkCollision(int currentX, int currentY, Direction currentDirection) {
	Position^ newPosition = gcnew Position(currentX, currentY);
	switch (currentDirection)
	{
	case UP:
		newPosition->setY(currentY - speed);
		break;
	case RIGHT:
		newPosition->setX(currentX + speed);
		break;
	case DOWN:
		newPosition->setY(currentY + speed);
		break;
	case LEFT:
		newPosition->setX(currentX - speed);
		break;
	}
	
	if (newPosition->getX() < 0 || newPosition->getX() > 1080 || newPosition->getY() < 0 || newPosition->getY() > 1080)
		return true;
	else return false;
}