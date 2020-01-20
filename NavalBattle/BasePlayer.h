#pragma once
#include "Point.h"
namespace Sokolova {
	class Player
	{
	public:
		Player();
		virtual ~Player() = default;

		void initMyField();
		void initEnemyField();
		void initMyShips();
		virtual void initPrivateData();
		virtual void setAllShipsRandomly();
		void initInfoPoins(const std::vector<Point>& position, Ship* ship);

		std::string getPlayerType() const;
		ShotResult askPoint(Point p);
		int getRemainedShipsNumber() const;

		PointCondition checkPoint(Point p) const;
		virtual Point choosePoint() = 0;
		virtual void setMyShotResult(Point p, ShotResult result);
		void setEnemyShotResult(Point p, ShotResult result);

	protected:
		virtual std::vector <Point> generateRandomPosition(int shipSize);
		virtual void setShip(std::vector <Point>& position);

		std::vector<Ship> myShips_;
		int remainedShipsNumber_;
		std::string playerType_;
		std::vector<InfoPoint> infoPoints_;
		PointCondition myField_[FIELD_SIZE][FIELD_SIZE];
		ShotResult enemyField_[FIELD_SIZE][FIELD_SIZE];

		friend class View;
	};
}