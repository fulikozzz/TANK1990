#include "Player_Tank.h"

Player_Tank::Player_Tank(Position^ initPosition, Direction initDirection, int initLives, int initSpeed) :
	Tank(initPosition, initDirection, initLives, initSpeed) {}

int Player_Tank::getScore() { return score; }
int Player_Tank::getArmor() { return armor; }
void Player_Tank::setScore(int value) { score = value; }
void Player_Tank::setArmor(int value) { armor = value; }

void Player_Tank::control(System::Windows::Forms::Keys key) {
	switch (key)
	{
	case System::Windows::Forms::Keys::W:
		setDirection(UP);
		move();
		break;
	case System::Windows::Forms::Keys::A:
		setDirection(LEFT);
		move();
		break;
	case System::Windows::Forms::Keys::S:
		setDirection(DOWN);
		move();
		break;
	case System::Windows::Forms::Keys::D:
		setDirection(RIGHT);
		move();
		break;
	case System::Windows::Forms::Keys::F:
		//Shoot();
		break;
	default:
		break;
	}
}