#include "Game.h"
int main(const int argc, const char** argv)
{

	std::tuple< std::string, int, std::vector<std::string>> arguments = parsingString(argv);
	if (std::get<0>(arguments) != EMPTY_STRING)
	{

			printHelp();
		    return 0;
	}
	std::vector<std::string> playerTypes = std::get<2>(arguments);
	int n = std::get<1>(arguments);
	Game game(playerTypes, n);
	game.start();
	return 0;
}