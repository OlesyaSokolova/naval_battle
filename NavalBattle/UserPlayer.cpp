#include "Functions.h"
#include <iostream>

UserPlayer::UserPlayer()
	: Player()
{
	this->playerType_ = USER;
}

Point UserPlayer::choosePoint()
{
	std::cout << "Enter a point to shoot:";
	InfoPoint p;
	p.readPoint();
	return p;
}