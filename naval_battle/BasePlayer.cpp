#include "Functions.h"
Player::~Player() {}
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
		myField_[p.i_][p.j_] = injured;
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
	return myField_[p.i_][p.j_];
}
void Player::showMyField() const
{
	int lineNumber = 0;
	std::cout << "  ";
	for (int j = 0; j < FIELD_SIZE; j++)
	{
		std::cout << symbol(j) << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		std::cout << lineNumber << " ";
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			std::cout << (char)this->myField_[i][j] << " ";
		}
		std::cout << std::endl;
		lineNumber++;
	}
}