#include "Functions.h"
#include <time.h>

Player * createPlayer(std::string playerType)
{
	if (playerType == RANDOM)
		return new RandomPlayer;
	if (playerType == OPTIMAL)
		return new OptimalPlayer;
	if (playerType == USER)
		return new UserPlayer;
}


bool isAccessible(const Point& point)
{
	int i = point.i_;
	int j = point.j_;
	if ((i >= -1) && (i <= FIELD_SIZE) && (j >= -1) && (j <= FIELD_SIZE))
	{
		return true;
	}
	return false;
}

int calcDif(int x, int y)
{
	int dif = y - x;
	if (dif < 0)
		return -1;
	if (dif == 0)
		return 0;
	if (dif > 0)
		return +1;
}
