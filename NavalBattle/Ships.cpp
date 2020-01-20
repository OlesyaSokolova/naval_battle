#include "Ships.h"
namespace Sokolova {

	Ship::Ship(int size)
		: shipSize_(size)
	{
		if (size == BATTLESHIP_SIZE)
		{
			shipName_ = BATTLESHIP;
			number_ = BATTLESHIPS_NUMBER;
		}
		else if (size == CRUISER_SIZE)
		{
			shipName_ = CRUISER;
			number_ = CRUISERS_NUMBER;
		}
		else if (size == DESTROYER_SIZE)
		{
			shipName_ = DESTROYER;
			number_ = DESTROYERS_NUMBER;
		}
		else if (size == TORPEDO_BOAT_SIZE)
		{
			number_ = TORPEDO_BOATS_NUMBER;
			shipName_ = TORPEDO_BOAT;
		}
	}

	int Ship::getShipSize() const
	{
		return this->shipSize_;
	}

	std::string Ship::getShipName() const
	{
		return this->shipName_;
	}

	int Ship::getShipNumber() const
	{
		return this->number_;
	}

	void Ship::decreaseSize()
	{
		this->shipSize_--;
	}
}