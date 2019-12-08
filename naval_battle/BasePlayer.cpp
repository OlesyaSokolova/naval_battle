#include "Functions.h"
Player::~Player() {}
Player::Player()
{
	initMyField();
	initEnemyField();
	this->setShipsNumber_ = 0;
	this->remainedShipsNumber_ = SHIPS_NUMBER;
}
void Player::initMyField()
{
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			this->yourField_[i][j] = blank;
		}
	}
}
void Player::initEnemyField()
{
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			this->enemyField_[i][j] = unknown;
		}
	}
}
bool Player::validatePosition(std::vector <Point>&position)
{
	return true;
}
bool Player::setShip(std::vector <Point>& position)
{
	return true;
}