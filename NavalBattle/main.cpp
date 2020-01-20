#include "Game.h"
using namespace Sokolova;
int main(const int argc, const char** argv)
{
	std::tuple< std::string, int, std::vector<std::string>> arguments = parsingString(argc, argv);
	if (std::get<HELP_INDEX>(arguments) != EMPTY_STRING)
	{
			printHelp();
		    return 0;
	}
	int n = std::get<ROUND_NUMBER_INDEX>(arguments);
	std::vector<std::string> playerTypes = std::get<USER_TYPES_INDEX>(arguments);
	Game game(playerTypes, n);
	game.start();
	return 0;
}