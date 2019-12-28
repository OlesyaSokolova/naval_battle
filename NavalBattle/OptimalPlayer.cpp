#include "ProxyRandom.h"
#include <iostream>
#include <ctime>

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
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			this->pointsToUse.push_back(Point(i, j));
		}
	}
	for (int i = 0; i < DIRECTIONS_NUMBER; i++)
	{
		shufflePoints(pointsOnLines[i]);
	}
}
Point OptimalPlayer::chooseRandomPoint()
{
	srand(time(NULL));
	int vectorSize = this->pointsToUse.size();
	int index = rand() % vectorSize;
	Point point = this->pointsToUse[index];
	pointsToUse.erase(pointsToUse.begin() + index);
	return point;
}
void OptimalPlayer::setMyShotResult(Point p, ShotResult result)
{
	if (result != missed)
	{
		this->successfulPoints.push_back(p);
		result = injured;
	}
	else if(this->successfulPoints.size() == 1)
	{
		this->dir_ = (this->dir_ + INDEX_SHIFT) % DIRECTIONS_NUMBER;
	}
	this->enemyField_[p.getI()][p.getJ()] = result;
}
Point OptimalPlayer::chooseRightPoint()
{
	Point p;
	if (this->successfulPoints.size() == 1)
	{
		if (this->dir_ == -1)
		{
			return this->randPointNearPoint(successfulPoints[0]);
		}
		else
		{
			
		}
		
	}
	
	return p;
}
Point OptimalPlayer::randPointNearPoint(Point p)
{
	srand(time(NULL));
	int di = rand() % POINT_AREA_SHIFTS;
	int dj = rand() % POINT_AREA_SHIFTS;
	bool pointIsCorrect = false;
	Point res(p.getI() + di, p.getJ() + dj);
	while (pointIsCorrect == false)
	{
		di = rand() % POINT_AREA_SHIFTS;
		dj = rand() % POINT_AREA_SHIFTS;
		res = Point(p.getI() + di, p.getJ() + dj);
		pointIsCorrect = isAccessible(res);
	}
	return res;
}
Point OptimalPlayer::choosePoint()
{
/*	Point p;
	if (successfulPoints.size() == 0)
	{
		return this->chooseRandomPoint();
	}
	else
	{
		return this->chooseRightPoint();
	}*/
	srand(time(NULL));
	int vectorSize = this->pointsToUse.size();
	int index = rand() % vectorSize;
	Point point = this->pointsToUse[index];
	pointsToUse.erase(pointsToUse.begin() + index);
	return point;
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
	while (lineSize == 0)
	{
		line = (line + INDEX_SHIFT) % DIRECTIONS_NUMBER;
		lineSize = this->pointsOnLines[line].size();
	}	
	int index = 0;
	firstPoint = this->pointsOnLines[line][index];
	while (fixed != true)
	{
		lastPoint = r.generateLastPoint(firstPoint, shipSize, line);
		fixed = r.fixLastPoint(this, firstPoint, lastPoint, line);
		if (fixed == false)
		{
			lineSize = this->pointsOnLines[line].size();;
			if (lineSize == 0 || index == lineSize-1)
			{
				index = 0;
				line = (line + INDEX_SHIFT) % DIRECTIONS_NUMBER;
				while (this->pointsOnLines[line].size() == 0)
				{
					line = (line + INDEX_SHIFT) % DIRECTIONS_NUMBER;
				}			
			}				
			else
			{
				index = (index+INDEX_SHIFT)%lineSize;
			}
			firstPoint = this->pointsOnLines[line][index];
		}
	}
	this->pointsOnLines[line][index].increaseTimesToUse();
	if (this->pointsOnLines[line][index].getUsedTimes() == TIMES_TO_USE_POINT_OPTIMALLY)
	{
		pointsOnLines[line].erase(pointsOnLines[line].begin() + index);
	}
	position = r.getPosition(firstPoint, lastPoint);
	return position;
}
void OptimalPlayer::setAllShipsRandomly()
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