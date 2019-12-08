#include "Functions.h"
int letterToIndex(const char & c)
{
	if (c >= 'A' && c <= 'J')
		return c - 'A';
	else if (c >= 'a' && c <= 'j')
		return c - 'a';
}
int indexToArrayIndex(int & i)
{
	return i - 1;
}

Player * createPlayer(std::string playerType)
{
	if (playerType == RANDOM)
		return new RandomPlayer;
	if (playerType == OPTIMAL)
		return new OptimalPlayer;
	if (playerType == USER)
		return new UserPlayer;
}

View * createView(std::string viewType)
{
	if (viewType == CONSOLE_VIEW)
		return new ConsoleView;
	if (viewType == GRAPHIC_VIEW)
		return new GraphicView;
}