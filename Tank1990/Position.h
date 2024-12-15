#pragma once
ref class Position
{
private:
	int x;
	int y;
	
public:
	Position(int x, int y);
	int getX();
	int getY();
	void setX(int value);
	void setY(int value);
	void setPosition(int newX, int newY);
};

