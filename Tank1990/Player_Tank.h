#pragma once
#include "Tank.h"

ref class Player_Tank : public Tank
{
private:
	int score;
	int armor;

public:
	Player_Tank(Position^ initPosition, Direction initDirection, int initLives, int initSpeed);

	int getScore();
	int getArmor();
	void setScore(int value);
	void setArmor(int value);

	void control(System::Windows::Forms::Keys key);
};