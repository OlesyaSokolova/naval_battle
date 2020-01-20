#pragma once
#include "BasePlayer.h"
#include "OptimalPlayer.h"
namespace Sokolova {

	class OptimalPlayer : public Player
	{
	public:
		OptimalPlayer();

		void initPrivateData() override;
		Point choosePoint()override;
		std::vector <Point>generateRandomPositionOptimally(int shipSize);
		void setAllShipsRandomly() override;
		void setMyShotResult(Point p, ShotResult result) override;

	private:
		Point chooseRandomPoint();
		Point randPointNearPoint(Point p);
		Point chooseRightPoint();
		bool canBeUsed(Point p);

		std::vector<Point> successfulPoints;
		std::vector<Point> pointsOnLines[DIRECTIONS_NUMBER];
		Point pointsToUse[FIELD_SIZE][FIELD_SIZE];
		int dir_;
	};
}