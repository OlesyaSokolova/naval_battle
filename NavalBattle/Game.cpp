#include "Game.h"
#include <iostream>
Game::Game(std::vector<std::string> playerTypes, std::string viewType, int roundsNumber = 1)
	:roundsNumber_(roundsNumber), statistic_{ 0 }
{
	for (int i = 0; i < PLAYERS_NUMBER; i++)
	{
		Player* player = createPlayer(playerTypes[i]);
		this->players_.push_back(player);
	}
	this->view_ = createView(viewType);
	this->view_->addPlayers(this->players_);
}
void Game::start()
{
	int winnerIndex = 0;
	for (int i = 0; i < this->roundsNumber_; i++)
	{
		winnerIndex = this->round();
		this->statistic_[winnerIndex]++;
	}
	std::cout << "Winner: " << winnerIndex << " (" << this->players_[winnerIndex]->getPlayerType() << ")" << std::endl;
	getchar();
}
ShotResult Game::shoot(int playerIndex, Point p)
{
	int enemyIndex = (playerIndex + INDEX_SHIFT) % PLAYERS_NUMBER;
	ShotResult res = this->players_[enemyIndex]->askPoint(p);
	this->players_[playerIndex]->setMyShotResult(p, res);
	this->players_[enemyIndex]->setEnemyShotResult(p, res);
	return res;
}
int Game::round()
{
	this->view_->initPlayers();
	int firstPlayer = this->view_->chooseFirstPlayer();
	int playerIndex = firstPlayer;
	ShotResult result;
	int shipsNumberFirst = players_[0]->getRemainedShipsNumber();
	int shipsNumberSecond = players_[1]->getRemainedShipsNumber();
	int k = 0;
	while (shipsNumberFirst > 0 && shipsNumberSecond > 0)
	{
		Point p = view_->playerTurn(playerIndex);
		result = shoot(playerIndex, p);
		view_->updateFields(playerIndex, result);
		playerIndex = nextPlayer(playerIndex, result);
		shipsNumberFirst = players_[0]->getRemainedShipsNumber();
		shipsNumberSecond = players_[1]->getRemainedShipsNumber();
	}
	return playerIndex;
}