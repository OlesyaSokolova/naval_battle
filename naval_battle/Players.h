#include <vector>
#include "Point.h"
#include "Ships.h"
class Player
{
public:
	Player();
	virtual ~Player() = 0;
	virtual void setAllShips() = 0;
	//virtual ShotDescription shoot(Point target);
protected:
	virtual bool setShip(std::vector <Point>& position);
	void initMyField();
	void initEnemyField();
	bool validatePosition(std::vector <Point>&position);

	Ships yourShips_;
	int setShipsNumber_;
	int remainedShipsNumber_;
	std::string playerType_;
	PointCondition yourField_[FIELD_SIZE][FIELD_SIZE];
	ShotDescription enemyField_[FIELD_SIZE][FIELD_SIZE];
};

class UserPlayer : public Player
{
public:
	UserPlayer();
	void setAllShips() override;
};
class RandomPlayer : public Player
{
public:
	RandomPlayer();
	std::vector <Point> generateRandomPosition(int shipSize);
	void setAllShips() override;
};
class OptimalPlayer : public Player
{
public:
	OptimalPlayer();
	void setAllShips() override;
};