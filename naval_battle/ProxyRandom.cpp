#include "ProxyRandom.h"
#include <time.h>
#include <algorithm>
Point ProxyRandom::generateRandomPoint()
{
	srand(time(NULL));
	int i = rand() % FIELD_SIZE;
	int j = rand() % FIELD_SIZE;
	Point point(i, j);
	return point;		
}
ProxyRandom::ProxyRandom( int shipSize)
	: dif_(shipSize+SHIP_SIZE_SHIFT),
	di{ -2, 2, dif_, dif_, 2, -2, -dif_, -dif_ },
	dj{ dif_, dif_, 2, -2, -dif_, -dif_, -2, +2 },

	shipFirstDi{ -1, 1, 1, 1, 1, -1, -1, -1 },
	shipFirstDj{ 1, 1, 1, -1, -1, -1, -1, 1 },

	shipLastDi{ 1, -1, -1, -1, -1, 1, 1, 1 },
	shipLastDj{ -1, -1, -1, 1, 1, 1, 1, -1 },

	direction_(0)
	{}

bool ProxyRandom::areaIsBlank(const RandomPlayer* player, const Point& firstPoint, const Point& lastPoint)
{
	int areaRange_i_min = std::min(firstPoint.i_, lastPoint.i_);
	int areaRange_i_max = std::max(firstPoint.i_, lastPoint.i_);
	int areaRange_j_min = std::min(firstPoint.j_, lastPoint.j_);
	int areaRange_j_max = std::max(firstPoint.j_, lastPoint.j_);
	for (int i = areaRange_i_min; i <= areaRange_i_max && i < FIELD_SIZE; i++)
	{
		for (int j = areaRange_j_min; j <= areaRange_j_max && j < FIELD_SIZE; j++)
		{
			Point p(i, j, NULL);
			if (player->askPoint(p) != blank)
				return false;
		}
	}
	return true;
}
bool ProxyRandom::fixLastPoint(const RandomPlayer* player, const Point& firstPoint, Point& lastPoint)
{
	int i = firstPoint.i_;
	int j = firstPoint.j_;
	int dir = this->direction_;
	bool isBlank = this->areaIsBlank(player, firstPoint, lastPoint);
	bool isGood = isAccessible(lastPoint);
	while (isBlank == false || isGood == false)
	{	
		dir = (dir + INDEX_SHIFT) % DIRECTIONS_NUMBER;
		if (dir == DIRECTIONS_NUMBER - INDEX_SHIFT)
			return false;
		lastPoint.i_ = i + di[dir];
		lastPoint.j_ = j + dj[dir];
		isBlank = this->areaIsBlank(player, firstPoint, lastPoint);	
		isGood = isAccessible(lastPoint);
	}
	this->direction_ = dir;
	return true;
}
Point ProxyRandom::generateLastPoint(const Point& firstPoint, int shipSize)
{
	srand(time(NULL));
	int direction = rand() % DIRECTIONS_NUMBER;
	int li = firstPoint.i_ + this->di[direction];
	int lj = firstPoint.j_ + this->dj[direction];
	Point lastPoint(li, lj);
	this->direction_ = direction;
	return lastPoint;
}
std::vector<Point> ProxyRandom::getPosition(const Point& firstPoint, const Point& lastPoint)
{
	int shipSize = dif_ - SHIP_SIZE_SHIFT;
	Point pf, pl;
	pf.i_ = firstPoint.i_ + shipFirstDi[direction_];
	pf.j_ = firstPoint.j_ + shipFirstDj[direction_];

	pl.i_ = lastPoint.i_ + shipLastDi[direction_];
	pl.j_ = lastPoint.j_ + shipLastDj[direction_];
	std::vector<Point> result;

	int dif_i = calcDif(pf.i_, pl.i_);
	int dif_j = calcDif(pf.j_, pl.j_);

	result.push_back(pf);
	int i, j;
	for (int k = 1; k < shipSize - SHIP_SIZE_SHIFT; k++)
	{
		i = dif_i * k + pf.i_;
		j = dif_j * k + pf.j_;
		result.push_back(Point(i, j));
	}
	if(shipSize!=1)
		result.push_back(pl);
	return result;
}
