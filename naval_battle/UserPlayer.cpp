#include "Functions.h"
#include "ProxyRandom.h"
#include <iostream>

UserPlayer::UserPlayer()
	: Player()
{
	this->playerType_ = USER;
}
std::vector <Point> UserPlayer::generateRandomPosition(int shipSize)
{
	Point firstPoint, lastPoint;
	bool fixed = false;
	ProxyRandom r(shipSize);
	while (fixed != true)
	{
		firstPoint = r.generateRandomPoint();
		while (myField_[firstPoint.getI()][firstPoint.getJ()] != blank)
		{
			firstPoint = r.generateRandomPoint();
		}
		lastPoint = r.generateLastPoint(firstPoint, shipSize);
		fixed = r.fixLastPoint(this, firstPoint, lastPoint);
	}

	std::vector<Point> position = r.getPosition(firstPoint, lastPoint);
	return position;
}
std::vector<Point> UserPlayer::readPosition()
{
	std::vector <Point> position;
	std::string line;
	getline(std::cin, line, DELIMITER_2);
	int lineSize = line.size();
	if (lineSize > MAX_INPUT_LINE_SIZE)
	{
		std::cout << "Wrong Input!Please, Try again." << std::endl;
		return position;
	}
	
	std::vector <std::string> points = parsingString(line, DELIMITER_1);
	for(int i = 0; i < points.size(); i++)
	{
		Point p;
		if (points[i].size() > 2)
		{
		std::cout << "wrong input point: " << points[i] << ". Please, Try again." << std::endl;
			return position;
		}
		p.getPoint(points[i]);
		position.push_back(p);
	}
	return position;
}
void UserPlayer::updateMyField()
{
	system("cls");
	std::cout << "Set your ships:" << std::endl;
}
void UserPlayer::setAllShips()
{
	remainedShipsNumber_ = SHIPS_NUMBER;
	std::vector <Point> position;
	int i = 0;
	int setShipsNumber = 0;
	while (setShipsNumber < SHIPS_NUMBER)
	{
		//setShip()//view_:friend show setting
		position = this->readPosition();
		if (position.size() == 0)
			continue;
		Ship ship;
		for (i = 0; i < myShips_.size(); i++)
		{
			if (myShips_[i].getShipSize() == position.size())
			{
				ship = myShips_[i];
				break;
			}
		}
		this->setShip(position);
		this->updateMyField();
		this->showMyField();
		initInfoPoins(position, &ship);
		setShipsNumber++;
	}
	remainedShipsNumber_ = SHIPS_NUMBER;
}
Point UserPlayer::choosePoint()
{
	//view_:friend show choosing
	std::cout << "Enter a point to shoot:";
	InfoPoint p;
	p.readPoint();
	return p;
}