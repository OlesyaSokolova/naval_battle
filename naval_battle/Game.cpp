#include "Game.h"

Game::Game(std::vector<std::string> playerTypes, std::string viewType, int roundsNumber  = 1)
	:roundsNumber_(roundsNumber), statistic_{0}
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
bool Game::shoot(int playerIndex, Point p)
{
	int enemyIndex = (playerIndex + 1) % 2;
	PointCondition res = this->players_[enemyIndex]->askPoint(p); 
	bool result = (res > 0) ? 1 : 0;
	return result;
}
int Game::round()
{
	this->view_->initPlayers(players_);
	int firstPlayer = this->view_->chooseFirstPlayer();
	int playerIndex = firstPlayer;
	bool result;
	while (players_[0]->getRemainedShipsNumber() > 0 && players_[1]->getRemainedShipsNumber() > 0)
	{
		Point p = view_->playerTurn(playerIndex);
		result = shoot(playerIndex, p);
		//view_->updateFields(playerIndex, result);
		playerIndex = nextPlayer(playerIndex, result);
	}
	return playerIndex;
}