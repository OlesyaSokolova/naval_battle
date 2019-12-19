#include "Functions.h"
RandomPlayer::RandomPlayer()
	:Player()
{
	this->playerType_ = RANDOM;
}

Point RandomPlayer::choosePoint()
{
	srand(time(NULL));
	int i = rand() % FIELD_SIZE;
	int j = rand() % FIELD_SIZE;
	Point point(i, j);
	return point;
}
