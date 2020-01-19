#include "Game.h"
#include <iostream>
#include <chrono>
#include <thread>
Game::Game(std::vector<std::string> playerTypes, int roundsNumber = 1)
	:roundsNumber_(roundsNumber), statistic_{ 0 }
{
	for (int i = 0; i < PLAYERS_NUMBER; i++)
	{
		Player* player = createPlayer(playerTypes[i]);
		this->players_.push_back(player);
	}
	this->view_ = new View;
	this->view_->addPlayers(this->players_);
}
void Game::start()
{
	int winnerIndex = 0;
	for (int i = 0; i < this->roundsNumber_; i++)
	{
		system("cls");
		for (int i = 0; i < PLAYERS_NUMBER; i++)
		{
			players_[i]->initPrivateData();
		}
		winnerIndex = this->round();
		if (roundsNumber_ > 1)
		{
			this->view_->showWinner(winnerIndex);
		}
		
		this->statistic_[winnerIndex]++;
	}
	this->view_->showStatistic(this->statistic_);
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
	srand(time(NULL));
	this->view_->initPlayers();
	int firstPlayer = this->view_->chooseFirstPlayer();
	int playerIndex = firstPlayer;
	ShotResult result;
	int shipsNumberFirst = players_[FIRST]->getRemainedShipsNumber();
	int shipsNumberSecond = players_[(FIRST + INDEX_SHIFT) % PLAYERS_NUMBER]->getRemainedShipsNumber();
	while (shipsNumberFirst > 0 && shipsNumberSecond > 0)
	{
		Point p = view_->playerTurn(playerIndex);
		result = shoot(playerIndex, p);
		//if (players_[FIRST]->getPlayerType() != USER && players_[(FIRST + INDEX_SHIFT) % PLAYERS_NUMBER]->getPlayerType() != USER)
		//{
		//	std::cout << indexToString(playerIndex) << ": " << p.getOriginalInput() << std::endl;	
		//	std::this_thread::sleep_for(std::chrono::microseconds(2500000));
		//}
		
		view_->updateFields(playerIndex, result);
		playerIndex = nextPlayer(playerIndex, result);
		shipsNumberFirst = players_[FIRST]->getRemainedShipsNumber();
		shipsNumberSecond = players_[(FIRST + INDEX_SHIFT) % PLAYERS_NUMBER]->getRemainedShipsNumber();
	}
	return playerIndex;
}