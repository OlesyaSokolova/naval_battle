#include "ProxyRandom.h"
#include <time.h>
#include <algorithm>
namespace Sokolova {

	ProxyRandom::ProxyRandom(int shipSize)
		: dif_(shipSize + SHIP_SIZE_SHIFT),
		di{ -INDEX_SHIFT_2, INDEX_SHIFT_2, dif_, dif_, INDEX_SHIFT_2, -INDEX_SHIFT_2, -dif_, -dif_ },
		dj{ dif_, dif_, INDEX_SHIFT_2, -INDEX_SHIFT_2, -dif_, -dif_, -INDEX_SHIFT_2, +INDEX_SHIFT_2 },
		direction_(FIRST_DIRECTION)
	{
		for (int i = 0; i < FIELD_SIZE; i++)
		{
			for (int j = 0; j < FIELD_SIZE; j++)
			{
				this->pointsToUse.push_back(Point(i, j));
			}
		}
	}

	Point ProxyRandom::generateRandomPoint()
	{
		int vectorSize = this->pointsToUse.size();
		int index = rand() % vectorSize;
		Point point = this->pointsToUse[index];
		std::swap(this->pointsToUse[index], this->pointsToUse[vectorSize - INDEX_SHIFT]);
		this->pointsToUse.pop_back();
		return point;
	}

	bool ProxyRandom::areaIsBlank(const Player* player, const Point& firstPoint, const Point& lastPoint)
	{
		int areaRange_i_min = std::max(MIN_I, std::min(firstPoint.i_, lastPoint.i_));
		int areaRange_i_max = std::max(firstPoint.i_, lastPoint.i_);
		int areaRange_j_min = std::max(MIN_J, std::min(firstPoint.j_, lastPoint.j_));
		int areaRange_j_max = std::max(firstPoint.j_, lastPoint.j_);
		for (int i = areaRange_i_min; i <= areaRange_i_max && i < FIELD_SIZE; i++)
		{
			for (int j = areaRange_j_min; j <= areaRange_j_max && j < FIELD_SIZE; j++)
			{
				Point p(i, j);
				if (player->checkPoint(p) != blank)
					return false;
			}
		}
		return true;
	}

	bool ProxyRandom::fixLastPoint(const Player* player, const Point& firstPoint, Point& lastPoint)
	{
		int i = firstPoint.i_;
		int j = firstPoint.j_;
		int dir = this->direction_;
		bool isBlank = this->areaIsBlank(player, firstPoint, lastPoint);
		bool isGood = isAccessible(lastPoint);
		int counter = 0;
		while (isBlank == false || isGood == false)
		{
			dir = (dir + INDEX_SHIFT) % DIRECTIONS;
			if (counter == DIRECTIONS - INDEX_SHIFT)
				return false;
			lastPoint.i_ = i + di[dir];
			lastPoint.j_ = j + dj[dir];
			isBlank = this->areaIsBlank(player, firstPoint, lastPoint);
			isGood = isAccessible(lastPoint);
			counter++;
		}
		this->direction_ = dir;
		return true;
	}

	bool ProxyRandom::fixLastPoint(const Player* player, const Point& firstPoint, Point& lastPoint, int line)
	{
		int i = firstPoint.i_;
		int j = firstPoint.j_;
		int dir = this->direction_;
		bool isBlank = this->areaIsBlank(player, firstPoint, lastPoint);
		bool isGood = isAccessible(lastPoint);
		int counter = 0;
		while (isBlank == false || isGood == false)
		{
			dir = kForLines[line][(counter + INDEX_SHIFT) % K_VARIANTS_FOR_LINES];
			if (counter == K_VARIANTS_FOR_LINES)
				return false;
			lastPoint.i_ = i + di[dir];
			lastPoint.j_ = j + dj[dir];
			isBlank = this->areaIsBlank(player, firstPoint, lastPoint);
			isGood = isAccessible(lastPoint);
			counter++;
		}
		this->direction_ = dir;
		return true;
	}

	Point ProxyRandom::generateLastPoint(const Point& firstPoint, int shipSize)
	{
		int direction = rand() % DIRECTIONS;
		int li = firstPoint.i_ + this->di[direction];
		int lj = firstPoint.j_ + this->dj[direction];
		Point lastPoint(li, lj);
		this->direction_ = direction;
		return lastPoint;
	}

	Point ProxyRandom::generateLastPoint(const Point& firstPoint, int shipSize, int line)
	{
		int direction = kForLines[line][rand() % K_VARIANTS_FOR_LINES];
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
		if (shipSize != TORPEDO_BOAT_SIZE)
			result.push_back(pl);
		return result;
	}
}
