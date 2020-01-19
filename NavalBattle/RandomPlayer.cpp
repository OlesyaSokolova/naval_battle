#include "Functions.h"
void RandomPlayer::initPrivateData()
{
	initMyField();
	initEnemyField();
	initMyShips();
	this->remainedShipsNumber_ = POINT_WAS_NOT_USED;
	infoPoints_.clear();
	this->playerType_ = RANDOM;
	pointsToUse.clear();
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			this->pointsToUse.push_back(Point(i, j));
		}
	}
}
RandomPlayer::RandomPlayer()
	:Player()
{
	this->initPrivateData();
}

Point RandomPlayer::choosePoint()
{
	int vectorSize = this->pointsToUse.size();
	int index = rand() % vectorSize;
	Point point = this->pointsToUse[index];
	this->pointsToUse.erase(pointsToUse.begin()+index);
	return point;
}

