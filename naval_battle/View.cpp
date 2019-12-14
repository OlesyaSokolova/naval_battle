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
	}	
	//fill your field::
}
int View::chooseFirstPlayer()
{
	//print message
	return choosePlayer();
}
void printInitMessage(std::string playerType)
{
	return;
}
Point View::playerTurn(int playerIndex)
{
	Player* player = this->players_[playerIndex];
	std::string type = player->getPlayerType();
	//return player->choosePoint();
	Point p(8, 9, NULL);
	return p;
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