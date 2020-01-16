#include "Functions.h"
#include <iostream>

void UserPlayer::initPrivateData()
{
	initMyField();
	initEnemyField();
	initMyShips();
	infoPoints_.clear();
	this->remainedShipsNumber_ = END_GAME_SHIPS_NUMBER;
	this->playerType_ = USER;
}
UserPlayer::UserPlayer()
	: Player()
{
	this->initPrivateData();
}

Point UserPlayer::choosePoint()
{
	std::cout << "Enter a point to shoot:";
	InfoPoint p;
	p.readPoint();
	return p;
}