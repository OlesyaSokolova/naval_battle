#pragma once
#include <vector>
#include "Consts.h"

class Ship
{
public:
	Ship() = default;

	Ship(int size);
	int getShipSize() const;
	std::string getShipName() const;
	int getShipNumber() const;
	~Ship() = default;
protected:
	std::string shipName_;
	int number_;
	int shipSize_;
};
	
