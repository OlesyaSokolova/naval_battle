#pragma once
#include <string>
#include "Functions.h"

class Game 
{
public:
	Game() = default;
	Game(std::vector<std::string> playerTypes, std::string viewType, int roundsNumber);
	~Game() = default;
	void start();
	int round();
private:
	View * view_;
	std::vector<Player*> players_;
	int roundsNumber_;
	int statistic_[PLAYERS_NUMBER];
};
