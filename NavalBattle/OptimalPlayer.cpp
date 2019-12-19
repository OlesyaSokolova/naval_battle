#include "ProxyRandom.h"

OptimalPlayer::OptimalPlayer()
	:Player()
{
	this->playerType_ = OPTIMAL;
}
Point OptimalPlayer::choosePoint()
{
	Point p;
	return p;
}
std::vector <Point>  OptimalPlayer::generateRandomPosition(int shipSize)
{
	Point firstPoint, lastPoint;
	bool fixed = false;
	ProxyRandom r(shipSize);
	while (fixed != true)
	{
		srand(time(NULL));
		int line = rand() % DIRECTIONS_NUMBER;
		firstPoint = randomPointOnLine(line);
		while (myField_[firstPoint.getI()][firstPoint.getJ()] != blank)
		{
			line = rand() % DIRECTIONS_NUMBER;
			firstPoint = randomPointOnLine(line);
		}
		lastPoint = r.generateLastPoint(firstPoint, shipSize, line);
		fixed = r.fixLastPoint(this, firstPoint, lastPoint);
	}

	std::vector<Point> position = r.getPosition(firstPoint, lastPoint);
	return position;
}