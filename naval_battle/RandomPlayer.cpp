#include "Functions.h"
#include <time.h>

RandomPlayer::RandomPlayer()
	:Player()
{
	this->playerType_ = RANDOM;
}

std::vector <Point> RandomPlayer::generateRandomPosition(int shipSize)
{
	srand(time(NULL));

	int fi = rand() % FIELD_SIZE;
	int fj = rand() % FIELD_SIZE;

	int direction = rand() % DIRECTIONS_NUMBER;

	bool verticalDirection = (direction % 2 == 0) ? true : false;
	bool horizontalDirection = !verticalDirection;

	int li = (int)horizontalDirection * (shipSize - 1) + fi;
	int lj = (int)verticalDirection * (shipSize - 1) + fj;

	Point firstPoint(fi, fj);
	Point lastPoint(li, lj);

	std::vector <Point> position;
	position.push_back(firstPoint);
	int i, j;
	for (int k = 1; k < shipSize - 1; k++)
	{
		i = (int)horizontalDirection * k + fi;
		j = (int)verticalDirection * k + fj;
		position.push_back(Point(i, j));
	}
	position.push_back(lastPoint);
	return position;
}

void RandomPlayer::setAllShips()
{
	std::vector <Point> position;
	int i = 0;
	while (setShipsNumber_ < SHIPS_NUMBER)
	{		
		Ship * ship = yourShips_.getShip(i);
		int shipNumber = ship->getShipNumber();
		int shipSize = ship->getShipSize();
		for (int j = 0; j < shipNumber; j++)
		{
			position = generateRandomPosition(shipSize);
			bool success = false;
			while (success != true)
			{
				success = setShip(position);
			}
			setShipsNumber_++;
		}
		i++;
	}
}