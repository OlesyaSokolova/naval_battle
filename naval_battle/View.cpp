#include "View.h"

View::View(std::vector<Player*> players)
{
	for (int i = 0; i < PLAYERS_NUMBER; i++)
	{
		players_[i] = players[i];
	}
}

void View::initPlayers(std::vector<Player*> players)
{
	for (int i = 0; i < PLAYERS_NUMBER; i++)
	{		
		players[i]->initMyField();
		players[i]->initEnemyField();
		if (players[i]->getPlayerType() == USER)
		{
			std::cout << "Set your ships:" << std::endl;
			players[i]->showMyField();
			players[i]->setAllShips();		
			std::cout << "and this is your enemy'  s field:\n" << std::endl;
			players[i]->showEnemyField();
		}		
	}	
	//fill your field::
}
int View::chooseFirstPlayer(const std::vector<Player*> players)
{
	std::cout << "Well ok now let's choose the player who will start: ";
	int first = choosePlayer();
	std::cout << players[first]->getPlayerType() << std::endl;
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