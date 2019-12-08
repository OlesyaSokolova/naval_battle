#include "Game.h"

Game::Game(std::vector<std::string> playerTypes, std::string viewType, int roundsNumber  = 1)
	:roundsNumber_(roundsNumber), statistic_(0, 0) 
{
	for (int i = 0; i < PLAYERS_NUMBER; i++)
	{
		players_[i] = createPlayer(playerTypes[i]);
	}
	view_ = createView(viewType);
}
void Game::start()
{
	int winnerIndex = 0;
	for (int i = 0; i < this->roundsNumber_; i++)
	{
		winnerIndex = this->round();
		this->statistic_[winnerIndex]++;
	}
		
}
int Game::round()
{
	return 1;
}