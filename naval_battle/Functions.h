#pragma once
#include "Players.h"
#include <time.h>

inline int indexToArrayIndex(int & i)
{
	return i - 1;
}
Player * createPlayer(std::string playerType);
inline int nextPlayer(int playerIndex, bool result)
{
	return (playerIndex + (int)!result) % PLAYERS_NUMBER;
}
inline int choosePlayer()
{
	srand(time(NULL));
	return rand() % PLAYERS_NUMBER;
}
bool isAccessible(const Point& point);
inline char symbol(int j)
{
	char c = (char)j + 'a';
	return c;
}
int calcDif(int x, int y);
std::vector<std::string> parsingString(std::string line, std::string delim);
