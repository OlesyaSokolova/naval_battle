#include "Functions.h"
RandomPlayer::RandomPlayer()
	:Player()
{
	this->playerType_ = RANDOM;
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			this->pointsToUse.push_back(Point(i, j));
		}
	}
}

Point RandomPlayer::choosePoint()
{
	int vectorSize = this->pointsToUse.size();
	int index = rand() % vectorSize;
	Point point = this->pointsToUse[index];
	this->pointsToUse.erase(pointsToUse.begin()+index);
	return point;
}

