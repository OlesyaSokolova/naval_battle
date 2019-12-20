#include "ProxyRandom.h"
Player::Player()
{
	initMyField();
	initEnemyField();
	initMyShips();
	this->remainedShipsNumber_ = 0;

}
void Player::initMyShips()
{//map с типами кораблей и их количествами
	for (int i = 0; i < BATTLESHIPS_NUMBER; i++)
	{
		Ship ship(BATTLESHIP_SIZE);
		myShips_.push_back(ship);
	}
	for (int i = 0; i < CRUISERS_NUMBER; i++)
	{
		Ship ship(CRUISER_SIZE);
		myShips_.push_back(ship);
	}
	for (int i = 0; i < DESTROYERS_NUMBER; i++)
	{
		Ship ship(DESTROYER_SIZE);
		myShips_.push_back(ship);
	}
	for (int i = 0; i < TORPEDO_BOATS_NUMBER; i++)
	{
		Ship ship(TORPEDO_BOAT_SIZE);
		myShips_.push_back(ship);
	}
}
void Player::setAllShips()
{
	std::vector <Point> position;
	int i = 0;
	int setShipsNumber = 0;
	while (setShipsNumber < SHIPS_NUMBER)
	{
		Ship ship = this->myShips_[i];
		int shipNumber = ship.getShipNumber();
		int shipSize = ship.getShipSize();
		for (int j = 0; j < shipNumber; j++)
		{
			position = generateRandomPosition(shipSize);
			this->setShip(position);
			initInfoPoins(position, &myShips_[i]);
			setShipsNumber++;
			i++;
		}
	}
	remainedShipsNumber_ = SHIPS_NUMBER;
}
void Player::initMyField()
{
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			this->myField_[i][j] = blank;
		}
	}
}
void Player::initEnemyField()
{
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			this->enemyField_[i][j] = blank;
		}
	}
}
bool Player::validatePosition(std::vector <Point>&position)
{
	return true;
}
void Player::setShip(std::vector <Point>& position)
{
	for (int i = 0; i < position.size(); i++)
	{
		Point p = position[i];
		myField_[p.getI()][p.getJ()] = injured;
	}
}

int Player::getRemainedShipsNumber() const
{
	return this->remainedShipsNumber_;
}
std::string Player::getPlayerType() const
{
	return this->playerType_;
}
PointCondition Player::askPoint(Point p) const
{
	if (p.getI() < 0 || p.getJ() < 0)
		return blank;
	return myField_[p.getI()][p.getJ()];
}

std::vector <Point> Player::generateRandomPosition(int shipSize)
{
	Point firstPoint, lastPoint;
	bool fixed = false;
	ProxyRandom r(shipSize);
	while (fixed != true)
	{
		firstPoint = r.generateRandomPoint();
		while (myField_[firstPoint.getI()][firstPoint.getJ()] != blank)
		{
			firstPoint = r.generateRandomPoint();
		}
		lastPoint = r.generateLastPoint(firstPoint, shipSize);
		fixed = r.fixLastPoint(this, firstPoint, lastPoint);
	}

	std::vector<Point> position = r.getPosition(firstPoint, lastPoint);
	return position;
}

void  Player::initInfoPoins(const std::vector<Point>& position, Ship* ship)
{
	int x, y;
	for (int i = 0; i < position.size(); i++)
	{
		x = position[i].getI();
		y = position[i].getJ();
		InfoPoint p(x, y, ship);
		this->infoPoints_.push_back(p);
	}
}