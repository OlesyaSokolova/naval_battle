#include "Point.h"
class Player
{
public:
	Player();
	virtual ~Player() = default;
	void initMyField();
	void initEnemyField();
	void initMyShips();
	virtual void setAllShips();
	int getRemainedShipsNumber() const;
	std::string getPlayerType() const;
	PointCondition askPoint(Point p) const;
	void initInfoPoins(const std::vector<Point>& position, Ship* ship);
	virtual Point choosePoint() = 0;
protected:
	virtual std::vector <Point> generateRandomPosition(int shipSize);
	virtual void setShip(std::vector <Point>& position);
	bool validatePosition(std::vector <Point>&position);
	std::vector<Ship> myShips_;
	int remainedShipsNumber_;
	std::string playerType_;
	std::vector<InfoPoint> infoPoints_;
	PointCondition myField_[FIELD_SIZE][FIELD_SIZE];
	PointCondition enemyField_[FIELD_SIZE][FIELD_SIZE];

	friend class View;
};

class UserPlayer : public Player
{
public:
	UserPlayer();
	Point choosePoint() override;
};
class RandomPlayer : public Player
{
public:
	RandomPlayer();
	Point choosePoint() override;
};
class OptimalPlayer : public Player
{
public:
	OptimalPlayer();
	std::vector <Point>generateRandomPositionOptimally(int shipSize);
	void setAllShips() override;
	Point choosePoint()override;
	std::vector<Point> successfulPoints;
	std::vector<Point> pointsOnLines[DIRECTIONS_NUMBER];
};