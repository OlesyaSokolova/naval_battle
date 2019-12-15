#include <vector>
#include "Point.h"
class Player
{
public:
	Player();
	virtual ~Player() = 0;
	virtual void setAllShips() = 0;
	void initMyField();
	void initEnemyField();
	void initMyShips();
	int getRemainedShipsNumber() const;
	std::string getPlayerType() const;
	PointCondition askPoint(Point p) const;
	void showMyField() const;
	void showEnemyField() const;
	void initInfoPoins(const std::vector<Point>& position, Ship* ship);
	virtual Point choosePoint() = 0;
protected:
	virtual void setShip(std::vector <Point>& position);
	bool validatePosition(std::vector <Point>&position);
	std::vector<Ship> myShips_;
	int remainedShipsNumber_;
	std::string playerType_;
	std::vector<InfoPoint> infoPoints_;
	PointCondition myField_[FIELD_SIZE][FIELD_SIZE];
	PointCondition enemyField_[FIELD_SIZE][FIELD_SIZE];
};

class UserPlayer : public Player
{
public:
	UserPlayer();
	std::vector <Point> generateRandomPosition(int shipSize);
	void setAllShips();
	void updateMyField();
	std::vector<Point> readPosition();
	Point choosePoint();
};
class RandomPlayer : public Player
{
public:
	RandomPlayer();
	std::vector <Point> generateRandomPosition(int shipSize);
	void setAllShips();
	Point choosePoint();
};
class OptimalPlayer : public Player
{
public:
	OptimalPlayer();
	void setAllShips()override;
	Point choosePoint()override;
};