#include "Point.h"
#include <iostream>

Point::Point()
	:i_(0), j_(0) {}

Point::Point(int i, int j)
	: i_(i), j_(j) {}

int Point::getI() const
{
	return this->i_;
}
int Point::getJ() const
{
	return this->j_;
}
InfoPoint::InfoPoint(int i, int j, Ship* ship)
	:Point(i, j), ship_(ship) {}

int Point::letterToIndex(const char c)
{
	if (c >= 'A' && c <= 'J')
		return c - 'A';
	else if (c >= 'a' && c <= 'j')
		return c - 'a';
}
void Point::getPoint(std::string i_j)
{
	for (int k = 0; k < POINT_PARAMETERS; k++)
	{
		if ('0' <= i_j[k] && i_j[k] <= '9')
		{
			this->i_ = i_j[k] - '0';
		}
		else
		{
			this->j_ = letterToIndex(i_j[k]);
		}
	}
}
void Point::readPoint()
{
	char i_j[POINT_PARAMETERS];

	for (int k = 0; k < POINT_PARAMETERS; k++)
	{
		std::cin >> i_j[k];
		if ('0' <= i_j[k] && i_j[k] <= '9')
		{
			this->i_ = i_j[k] - '0';
		}
		else
		{
			this->j_ = letterToIndex(i_j[k]);
		}
	}
}
shotResult InfoPoint::decreaseShipCounter() const
{
	this->ship_->decreaseSize();
	if (ship_->getShipSize() == 0)
	{
		return killed;
	}
	return injured;
}