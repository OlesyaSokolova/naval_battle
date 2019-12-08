#include "Functions.h"

Ship::~Ship() {}

Ship::Ship(std::vector<Point>& position)
	: position_(position), number_(0) {}

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
Ship_4::Ship_4()
{
	this->shipName_ = BATTLESHIP;
	this->number_ = BATTLESHIPS_NUMBER;
	this->shipSize_ = BATTLESHIP_SIZE;
}

Ship_4::Ship_4(std::vector<Point>& position)
	: Ship (position)
    { 
		this->shipName_ = BATTLESHIP;
		this->number_ = BATTLESHIPS_NUMBER;
		this->shipSize_ = BATTLESHIP_SIZE;
	}

Ship_3::Ship_3()
{
	this->shipName_ = CRUISER;
	this->number_ = CRUISERS_NUMBER;
	this->shipSize_ = CRUISER_SIZE;
}

Ship_3::Ship_3(std::vector<Point>& position)
	: Ship(position)
	{
		this->shipName_ = CRUISER;
		this->number_ = CRUISERS_NUMBER;
		this->shipSize_ = CRUISER_SIZE;
	}

Ship_2::Ship_2()
{
	this->shipName_ = DESTROYER;
	this->number_ = DESTROYERS_NUMBER;
	this->shipSize_ = DESTROYER_SIZE;
}

Ship_2::Ship_2(std::vector<Point>& position) 
	: Ship (position)
    { 
		this->shipName_ = DESTROYER;
		this->number_ = DESTROYERS_NUMBER;
		this->shipSize_ = DESTROYER_SIZE;
	}

Ship_1::Ship_1()
{
	this->shipName_ = TORPEDO_BOAT;
	this->number_ = TORPEDO_BOATS_NUMBER;
	this->shipSize_ = TORPEDO_BOAT_SIZE;
}

Ship_1::Ship_1(std::vector<Point>& position)
	: Ship(position)
	{
		this->shipName_ = TORPEDO_BOAT;
		this->number_ = TORPEDO_BOATS_NUMBER;
		this->shipSize_ = TORPEDO_BOAT_SIZE;
	}
Ship* Ships::getShip(int id)
{
	switch (id)
	{
	case(BATTLESHIP_ID):
		return &battleship;	
	case(CRUISER_ID):
		return &cruiser;
	case(2):
		return &destroyer;
	case(3):
		return &torpedo_boat;	
	}	
}