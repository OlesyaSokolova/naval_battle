#include "View.h"
#include <iostream>
void View::addPlayers(std::vector<Player*> players)
{
	this->userIndex_ = -1;
	for (int i = 0; i < PLAYERS_NUMBER; i++)
	{
		if (players[i]->getPlayerType() == USER)
			this->userIndex_ = i;
		players_.push_back(players[i]);
	}

}
void View::showPlayerField(const Player* player)
{
	int lineNumber = 0;
	std::cout << "  ";
	for (int j = 0; j < FIELD_SIZE; j++)
	{
		std::cout << symbol(j) << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		std::cout << lineNumber << " ";
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			std::cout << (char)player->myField_[i][j] << " ";
		}
		std::cout << std::endl;
		lineNumber++;
	}
}
void View::showPlayerEnemyField(const Player* player)
{
	int lineNumber = 0;
	std::cout << "  ";
	for (int j = 0; j < FIELD_SIZE; j++)
	{
		std::cout << symbol(j) << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		std::cout << lineNumber << " ";
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			std::cout << (char)player->enemyField_[i][j] << " ";
		}
		std::cout << std::endl;
		lineNumber++;
	}
}
void View::updatePlayerField(const Player* player)
{
	system("cls");
	if (player->remainedShipsNumber_ < SHIPS_NUMBER)
	{
		std::cout << "Set your ships:" << std::endl;
	}
	this->showPlayerField(player);
}
void View::setAllUserShips()
{
	int userIndex = this->userIndex_;
	Player* player = this->players_[userIndex];
	std::cout << "Set your ships." << std::endl;
	this->showPlayerField(player);
	std::cout << "If you are lazy, bot can do it for you randomly, just type \"r\":" << std::endl;

	std::vector <Point> position;
	int i = 0;
	int setShipsNumber = 0;
	while (setShipsNumber < SHIPS_NUMBER)
	{
		position = this->readPosition();

		if (position.size() == 0)
		{
			continue;
		}

		if (position.size() == 1)
		{
			int i_ = position[0].getI();
			int j_ = position[0].getJ();
			if (i_ == -1 && j_ == -1)
			{
				std::cout << "Ok! Your ships will be set randomly." << std::endl;
				player->setAllShips();
				break;
			}
		}
		Ship ship;
		for (i = 0; i < SHIPS_NUMBER; i++)
		{
			if (player->myShips_[i].getShipSize() == position.size())
			{
				ship = player->myShips_[i];
				break;
			}
		}
		player->setShip(position);
		this->updatePlayerField(player);
		player->initInfoPoins(position, &ship);
		setShipsNumber++;
	}
	player->remainedShipsNumber_ = SHIPS_NUMBER;
}
void View::initPlayers()
{
	for (int i = 0; i < PLAYERS_NUMBER; i++)
	{
		players_[i]->initMyField();
		players_[i]->initEnemyField();
		if (players_[i]->getPlayerType() == USER)
		{
			setAllUserShips();
			system("cls");
			std::cout << "This is your field:" << std::endl;
			this->showPlayerField(players_[i]);
			std::cout << "and this is your enemy's field:" << std::endl;
			this->showPlayerEnemyField(players_[i]);
		}
		if (players_[i]->getPlayerType() == RANDOM)
		{
			players_[i]->setAllShips();
			std::cout << "Player #" << i << " is ready!" << std::endl;
		}
		if (players_[i]->getPlayerType() == OPTIMAL)
		{
			players_[i]->setAllShips();
			std::cout << "Player #" << i << " is ready!" << std::endl;
		}
	}
}
int View::chooseFirstPlayer()
{
	std::cout << "Well ok now let's choose the player who will start: ";
	int first = choosePlayer();
	std::cout << players_[first]->getPlayerType() << std::endl;
	return first;
}
void printInitMessage(std::string playerType)
{
	return;
}
Point View::playerTurn(int playerIndex)
{
	Player* player = this->players_[playerIndex];
	std::string type = player->getPlayerType();
	return player->choosePoint();
}
void View::updateFields(int playerIndex, int result)
{
	return;
}
View * createView(std::string viewType)
{
	if (viewType == CONSOLE_VIEW)
		return new ConsoleView;
	if (viewType == GRAPHIC_VIEW)
		return new GraphicView;
}
std::vector<Point> View::readPosition()
{
	std::vector <Point> position;
	std::string line;
	getline(std::cin, line, DELIMITER_2);
	int lineSize = line.size();
	if (line.size() == 1 && (line[0] == 'r' || line[0] == 'R'))
	{
		position.push_back(Point(-1, -1));
		return position;
	}
	if (lineSize > MAX_INPUT_LINE_SIZE)
	{
		std::cout << "Wrong Input!Please, Try again." << std::endl;
		return position;
	}
#
	std::vector <std::string> points = parsingString(line, DELIMITER_1);
	for (int i = 0; i < points.size(); i++)
	{
		Point p;
		if (points[i].size() > 2)
		{
			std::cout << "wrong input point: " << points[i] << ". Please, Try again." << std::endl;
			return position;
		}
		p.getPoint(points[i]);
		if (!isAccessible(p))
		{
			std::cout << "wrong input point: " << points[i] << ". Please, Try again." << std::endl;
		}
		position.push_back(p);
	}
	return position;
}