#include "Functions.h"
#include <iostream>

UserPlayer::UserPlayer()
	: Player()
{
	this->playerType_ = USER;
}
void UserPlayer::setAllShips()
{
	int setShipsNumber = 0;
	while (setShipsNumber < SHIPS_NUMBER)
	{
		//setShip()//view_:friend show setting
		setShipsNumber++;
	}
	remainedShipsNumber_ = SHIPS_NUMBER;
}
Point UserPlayer::choosePoint()
{
	//view_:friend show choosing
	std::cout << "Enter a point:";
	Point p;
	std::cin >> p.i_, p.j_;
	p.i_ -= INDEX_SHIFT;
	p.j_ -= INDEX_SHIFT;
	return p;
}