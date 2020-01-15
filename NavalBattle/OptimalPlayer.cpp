#include "ProxyRandom.h"
#include <iostream>
#include <time.h>


void OptimalPlayer::initPrivateFields()
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

	for (int i = 0; i < DIRECTIONS_NUMBER; i++)
	{
		shufflePoints(pointsOnLines[i]);
	}
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			this->pointsToUse[i][j] = Point(i, j);
		}
	}
}
OptimalPlayer::OptimalPlayer()
	:Player()
{	
	this->initPrivateFields();
}
Point OptimalPlayer::chooseRandomPoint()
{
	int i = rand() % FIELD_SIZE;
	int j = rand() % FIELD_SIZE;
	Point point;
	point = this->pointsToUse[i][j];
	bool pointCanBeUsed = canBeUsed(point);
	int k = 0;
	while (pointCanBeUsed == false)
	{
		k++;
		if (k == FIELD_SIZE - INDEX_SHIFT)
		{
			i = (i + INDEX_SHIFT) % FIELD_SIZE;
			k = 0;
		}
		j = (j + INDEX_SHIFT) % FIELD_SIZE;
		point = this->pointsToUse[i][j];
		pointCanBeUsed = canBeUsed(point);
	}
	
	return point;
}
bool OptimalPlayer::canBeUsed(Point p)
{
	if (this->pointsToUse[p.getI()][p.getJ()].getUsedTimes() == 0)
	{	
			return true;
	}
	return false;
}

void OptimalPlayer::setMyShotResult(Point p, ShotResult result)
{
	if (result != missed)
	{	
		if (result == killed)
		{
			result = injured;
			this->successfulPoints.clear();
		}
		else
		{
			this->successfulPoints.push_back(p);
		}	
	}
	else if (this->successfulPoints.size() == 1)
	{
		this->dir_ = (this->dir_ + INDEX_SHIFT) % DIRECTIONS_NUMBER;
	}
	else if(this->successfulPoints.size() > 1)
	{
		this->dir_ = (this->dir_ + INDEX_SHIFT + INDEX_SHIFT) % DIRECTIONS_NUMBER;
	}
	this->enemyField_[p.getI()][p.getJ()] = result;
}
Point OptimalPlayer::chooseRightPoint()
{
	Point p;
	if (this->successfulPoints.size() == 1)
	{
		p = this->randPointNearPoint(successfulPoints[0]);
	}
	else
	{
		bool pointIsCorrect = false;
		bool pointCanBeUsed = false;
		std::cout << "2";
		while (pointIsCorrect == false || pointCanBeUsed == false)
		{
			int lastPointIndex = calcLastPoint(this->dir_, this->successfulPoints);
			int di = pointAreaDi[this->dir_];
			int dj = pointAreaDj[this->dir_];
			int i = di * INDEX_SHIFT + successfulPoints[lastPointIndex].getI();
			int j = dj * INDEX_SHIFT + successfulPoints[lastPointIndex].getJ();
			p = Point(i, j);
			pointIsCorrect = isAccessibleForTurn(p);
			pointCanBeUsed = canBeUsed(p);
			this->dir_ = (this->dir_ + INDEX_SHIFT+ INDEX_SHIFT) % DIRECTIONS_NUMBER;
		}
	}
	return p;
}
Point OptimalPlayer::randPointNearPoint(Point p)
{
	srand(time(NULL));
	int di = pointAreaDi[this->dir_];
	int dj = pointAreaDj[this->dir_];
	Point res(p.getI() + di, p.getJ() + dj);
	bool pointIsCorrect = isAccessible(res);
	bool pointCanBeUsed = canBeUsed(res);
	while (pointIsCorrect == false || pointCanBeUsed == false)
	{
		this->dir_ = (this->dir_ + INDEX_SHIFT) % DIRECTIONS_NUMBER;
		di = pointAreaDi[this->dir_];
		dj = pointAreaDj[this->dir_];
		res = Point(p.getI() + di, p.getJ() + dj);
		pointIsCorrect = isAccessibleForTurn(res);
		pointCanBeUsed = canBeUsed(res);
	}
	return res;
}
Point OptimalPlayer::choosePoint()
{
	Point p;
	if (successfulPoints.size() == 0)
	{
		p = this->chooseRandomPoint();
	}
	else
	{
		p = this->chooseRightPoint();
	}
	int i = p.getI();
	int j = p.getJ();
	this->pointsToUse[i][j].increaseTimesToUse();
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