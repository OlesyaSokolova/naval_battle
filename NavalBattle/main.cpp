#include <iostream>
#include "Game.h"

int main()
{
	std::vector<std::string> playerTypes = { OPTIMAL, USER };
	std::string viewType = CONSOLE_VIEW;
	int n = 1;
	Game game(playerTypes, viewType, n);
	game.start();
	getchar();
	return 0;
}