#include "Functions.h"
#include "ProxyRandom.h"
RandomPlayer::RandomPlayer()
	:Player()
{
	this->playerType_ = RANDOM;
}

std::vector <Point> RandomPlayer::generateRandomPosition(int shipSize)
{
	Point firstPoint, lastPoint;
	bool fixed = false;
	ProxyRandom r(shipSize);
	while (fixed != true)
	{
		firstPoint = r.generateRandomPoint();
		while (myField_[firstPoint.i_][firstPoint.j_] != blank)
		{
			firstPoint = r.generateRandomPoint();
		}
	    lastPoint = r.generateLastPoint(firstPoint, shipSize);
	    fixed = r.fixLastPoint(this, firstPoint, lastPoint);
	}

    std::vector<Point> position= r.getPosition(firstPoint, lastPoint);
	return position;
}

void RandomPlayer::setAllShips()
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
			setShipsNumber++;
			i++;
		}
		
	}
	remainedShipsNumber_ = SHIPS_NUMBER;
}
