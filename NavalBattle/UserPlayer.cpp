#include "Functions.h"
#include <iostream>

UserPlayer::UserPlayer()
	: Player()
{
	this->playerType_ = USER;
}

Point UserPlayer::choosePoint()
{
	//view_:friend show choosing
	std::cout << "Enter a point to shoot:";
	InfoPoint p;
	p.readPoint();
	return p;
}