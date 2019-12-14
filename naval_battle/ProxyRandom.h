#pragma once
#include "Functions.h"
class ProxyRandom
{
public:
	ProxyRandom(int shipSize);
	Point generateRandomPoint();
	bool areaIsBlank(const RandomPlayer* player, const Point& firstPoint, const Point& lastPoint);
	bool fixLastPoint(const RandomPlayer* player, const Point& firstPoint, Point& lastPoint);
	Point generateLastPoint(const Point& firstPoint, int shipSize);
	std::vector<Point> getPosition(const Point& firstPoint, const Point& lastPoint);
private:
	int dif_;
	int di[DIRECTIONS];
	int dj[DIRECTIONS];
	int direction_;
	int shipFirstDi[DIRECTIONS];
	int shipFirstDj[DIRECTIONS];

	int shipLastDi[DIRECTIONS];
	int shipLastDj[DIRECTIONS];
};