#include "View.h"
#include <iostream>
#include <chrono>
#include <thread>
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
View::View()
{
	userResultMessages.insert({missed, "You missed! Now your enemy will shoot." });
	userResultMessages.insert({injured, "Cool! You injured your enemy's ship. Shoot again." });
	userResultMessages.insert({killed, "Great! You killed  your enemy's ship. Shoot again." });

	enemyResultMessages.insert({ missed, "Your enemy missed! Now you will shoot." });
	enemyResultMessages.insert({ injured, "Your enemy injured your ship. Now he will shoot again." });
	enemyResultMessages.insert({ killed, "Your enemy killed your ship. Now he will shoot again." });
}
void View::showPlayerField(const Player* player)
{
	if (player->getPlayerType() == USER)
	{
		std::cout << "This is your field:" << std::endl;
	}	
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
	std::cout << "This is your enemy's field:" << std::endl;
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
void View::updatePlayerEnemyField(const Player* player)
{
	system("cls");
	this->showPlayerField(player);
	this->showPlayerEnemyField(player);
}
void View::initPlayerField(const Player* player)
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
				player->setAllShipsRandomly();
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
		this->initPlayerField(player);
		player->initInfoPoins(position, &ship);
		setShipsNumber++;
	}
	player->remainedShipsNumber_ = SHIPS_NUMBER;
}
void View::initPlayers()
{	
	if (userIndex_ != -1)
	{
		setAllUserShips();
		system("cls");
		this->showPlayerField(players_[userIndex_]);
		this->showPlayerEnemyField(players_[userIndex_]);
		int anotherPlayerIndex = (userIndex_ + INDEX_SHIFT) % PLAYERS_NUMBER;
		players_[anotherPlayerIndex]->setAllShipsRandomly();
		std::cout << "Your enemy is ready!" << std::endl;
	}
	else 
		for (int i = 0; i < PLAYERS_NUMBER; i++)
		{
			players_[i]->initMyField();
			players_[i]->initEnemyField();
			players_[i]->setAllShipsRandomly();
			std::cout << "Player #" << i << " is ready!" << std::endl;
			this->showPlayerField(players_[i]);
		}
}	

int View::chooseFirstPlayer()
{
	std::cout << "Well ok now let's choose the player who will start: ";
	int first = choosePlayer();
	std::cout << players_[first]->getPlayerType() << std::endl;
	std::cout << "If you are ready, press ENTER";
	getchar();
	std::this_thread::sleep_for(std::chrono::microseconds(500000));
	return first; 
}
Point View::playerTurn(int playerIndex)
{
	Player* player = this->players_[playerIndex];
	std::string type = player->getPlayerType();
	Point p = player->choosePoint();
	bool pointIsCorrect;
	bool pointIsNew = false;
	if (userIndex_ != -1)
	{
		if (userIndex_ == playerIndex)
		{
			pointIsCorrect = isAccessibleForTurn(p);
			if (pointIsCorrect == true)
			{
				pointIsNew = players_[userIndex_]->enemyField_[p.getI()][p.getJ()] == unknown ? true : false;
			}
			while(pointIsNew == false)
			{	
				pointIsCorrect = isAccessible(p);
				if(pointIsCorrect == false )
				{
					pointIsNew = false;
					std::cout << "This point is out of field ranges: " << p.getOriginalInput() << ". Please, try again." << std::endl;
				}
				else
				{
					std::cout << "You have already checked this point: " << p.getOriginalInput() << std::endl << "Please, try again." << std::endl;
				}
				p = player->choosePoint();
				pointIsNew = players_[userIndex_]->enemyField_[p.getI()][p.getJ()] == unknown ? true : false;
				bool pointIsCorrect = isAccessible(p);
			}
		}
		else
		{
			std::cout << "Your enemy turn: " << p.getOriginalInput() << std::endl;
			std::cout << "Please, press ENTER to check this point at your field.";
			getchar();
		}
		
	}
	return p;
}
void View::updateFields(int playerIndex, ShotResult result)
{
	std::this_thread::sleep_for(std::chrono::microseconds(700000));
	if (this->players_[playerIndex]->getPlayerType() == USER)
	{	
		this->updatePlayerEnemyField(this->players_[playerIndex]);
		std::cout << this->userResultMessages[result] << std::endl;
		getchar();
	}
	else
	{
		if (userIndex_ != -1)
		{		
				this->updatePlayerEnemyField(this->players_[userIndex_]);
				std::cout << this->enemyResultMessages[result] << std::endl;		
		}
		else
		{
			system("cls");
			std::cout << "first player " << "(" << this->players_[0]->getPlayerType() << ")" << ":" << std::endl;
			this->showPlayerField(this->players_[0]);
			std::cout << "second player " << "(" << this->players_[1]->getPlayerType() << ")" << ":" << std::endl;
			this->showPlayerField(this->players_[1]);
		}
		
	}
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
			std::cout << "Wrong input point: " << points[i] << ". Please, Try again." << std::endl;
			return position;
		}
		p.getPoint(points[i]);
		if (!isAccessible(p))
		{
			std::cout << "Wrong input point: " << points[i] << ". Please, Try again." << std::endl;
		}
		position.push_back(p);
	}
	return position;
}