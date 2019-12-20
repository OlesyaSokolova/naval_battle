#include "ProxyRandom.h"

OptimalPlayer::OptimalPlayer()
	:Player()
{
	this->playerType_ = OPTIMAL;
	for (int i = 1; i <= 8; i++)
	{
		pointsOnLines[0].push_back(Point(1, i));
	}

	for (int i = 1; i <= 8; i++)
	{
		pointsOnLines[1].push_back(Point(i, 8));
	}

	for (int i = 1; i <= 8; i++)
	{
		pointsOnLines[2].push_back(Point(8, i));
	}

	for (int i = 1; i <= 8; i++)
	{
		pointsOnLines[3].push_back(Point(i, 1));
	}
}
Point OptimalPlayer::choosePoint()
{
	Point p;
	return p;
}
std::vector <Point>  OptimalPlayer::generateRandomPositionOptimally(int shipSize)
{
	Point firstPoint, lastPoint;
	bool fixed = false;
	ProxyRandom r(shipSize);
	srand(time(NULL));
	int counter = 0;
	int line = rand() % DIRECTIONS_NUMBER;
	int lineSize = this->pointsOnLines[line].size();
	std::vector<Point> position;
	int index;
	if (lineSize > 0)
		index = rand() % lineSize;
	else while (this->pointsOnLines[line].size() == 0)
	{
		line = (line + 1) % DIRECTIONS_NUMBER;
	}
	lineSize = this->pointsOnLines[line].size();
	index = rand() % lineSize;
	firstPoint = this->pointsOnLines[line][index];
	while (fixed != true)
	{	
		lastPoint = r.generateLastPoint(firstPoint, shipSize, line);
		fixed = r.fixLastPoint(this, firstPoint, lastPoint, line);
		if (fixed == false)
		{
			lineSize = this->pointsOnLines[line].size();
			std::swap(this->pointsOnLines[line][index], this->pointsOnLines[line][lineSize - 1]);
			this->pointsOnLines[line].pop_back();
			lineSize--;
			if(lineSize>0)
				index = rand() % lineSize;
			else while(this->pointsOnLines[line].size()==0)
			{
				line = (line + 1) % DIRECTIONS_NUMBER;
			}
			firstPoint = this->pointsOnLines[line][index];
		}
		
	}

	position = r.getPosition(firstPoint, lastPoint);
	return position;
}
void OptimalPlayer::setAllShips()
{
	std::vector <Point> position;
	int i = 0;
	int setShipsNumber = 0;
	while (setShipsNumber < SHIPS_NUMBER - TORPEDO_BOATS_NUMBER)
	{
		Ship ship = this->myShips_[i];
		int shipNumber = ship.getShipNumber();
		int shipSize = ship.getShipSize();
		for (int j = 0; j < shipNumber; j++)
		{	
			position = generateRandomPositionOptimally(shipSize);
			this->setShip(position);
			initInfoPoins(position, &myShips_[i]);
			setShipsNumber++;
			i++;
		}
	}
	while (setShipsNumber < SHIPS_NUMBER)
	{
		Ship ship = this->myShips_[setShipsNumber];
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