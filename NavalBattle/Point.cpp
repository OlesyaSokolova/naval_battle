#include "Point.h"
#include <iostream>
namespace Sokolova {

	Point::Point()
		:i_(0), j_(0), i_j_{ END_STRING }, usedTimes_(POINT_WAS_NOT_USED) {}

	Point::Point(int i, int j)
		: i_(i), j_(j), i_j_{ (char)i + ADDENDUM_FOR_NUMBER, (char)j + ADDENDUM_FOR_LETTER_LOWERCASE, END_STRING }, usedTimes_(POINT_WAS_NOT_USED) {}

	int Point::getI() const
	{
		return this->i_;
	}
	int Point::getJ() const
	{
		return this->j_;
	}

	std::string Point::getOriginalInput() const
	{
		char res[POINT_PARAMETERS + INDEX_SHIFT];
		strcpy_s(res, i_j_);
		std::swap(res[FIRST], res[(FIRST + INDEX_SHIFT) % POINT_PARAMETERS]);
		std::string result = (std::string)res;
		return result;
	}

	int Point::letterToIndex(const char c)
	{
		if (c >= FIRST_LETTER_UPPERCASE && c <= LAST_LETTER_UPPERCASE)
			return c - ADDENDUM_FOR_LETTER_UPPERCASE;
		else if (c >= FIRST_LETTER_LOWERCASE && c <= LAST_LETTER_LOWERCASE)
			return c - ADDENDUM_FOR_LETTER_LOWERCASE;
	}

	void Point::getPoint(std::string i_j)
	{
		for (int k = 0; k < POINT_PARAMETERS; k++)
		{
			if (FIRST_NUMBER <= i_j[k] && i_j[k] <= LAST_NUMBER)
			{
				this->i_ = i_j[k] - ADDENDUM_FOR_NUMBER;
			}
			else
			{
				this->j_ = letterToIndex(i_j[k]);
			}
		}
	}

	void Point::readPoint()
	{
		for (int k = 0; k < POINT_PARAMETERS; k++)
		{
			std::cin >> i_j_[k];
			if (FIRST_NUMBER <= i_j_[k] && i_j_[k] <= LAST_NUMBER)
			{
				this->i_ = i_j_[k] - ADDENDUM_FOR_NUMBER;
			}
			else
			{
				this->j_ = letterToIndex(i_j_[k]);
			}
		}

	}

	int Point::getUsedTimes() const
	{
		return this->usedTimes_;
	}

	void Point::increaseTimesToUse()
	{
		this->usedTimes_++;
	}

	InfoPoint::InfoPoint(int i, int j, Ship* ship)
		:Point(i, j), ship_(ship) {}

	ShotResult InfoPoint::decreaseShipCounter() const
	{
		this->ship_->decreaseSize();
		if (ship_->getShipSize() == KILLED_SHIP_SIZE)
		{
			return killed;
		}
		return injured;
	}

}