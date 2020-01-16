#include <iostream>
#include "Game.h"

int main()
{
	std::vector<std::string> playerTypes = {USER, RANDOM };
	std::string viewType = CONSOLE_VIEW;
	int n = 2;
	Game game(playerTypes, viewType, n);
	game.start();
	return 0;
}