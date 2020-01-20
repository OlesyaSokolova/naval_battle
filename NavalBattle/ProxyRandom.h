#pragma once
#include "Functions.h"
namespace Sokolova {
	class ProxyRandom
	{
	public:
		ProxyRandom(int shipSize);
		~ProxyRandom() = default;
		Point generateRandomPoint();
		bool areaIsBlank(const Player* player, const Point& firstPoint, const Point& lastPoint);
		bool fixLastPoint(const Player* player, const Point& firstPoint, Point& lastPoint);
		bool fixLastPoint(const Player* player, const Point& firstPoint, Point& lastPoint, int line);
		Point generateLastPoint(const Point& firstPoint, int shipSize);
		Point generateLastPoint(const Point& firstPoint, int shipSize, int line);
		std::vector<Point> getPosition(const Point& firstPoint, const Point& lastPoint);
	private:
		int dif_;
		int di[DIRECTIONS];
		int dj[DIRECTIONS];
		int direction_;
		std::vector<Point> pointsToUse;
	};
}