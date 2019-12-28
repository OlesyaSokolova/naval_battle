#include <iostream>
#include "Game.h"

int main()
{
	std::vector<std::string> playerTypes = { OPTIMAL, RANDOM };
	std::string viewType = CONSOLE_VIEW;
	int n = 1;
	Game game(playerTypes, viewType, n);
	game.start();
	return 0;
}