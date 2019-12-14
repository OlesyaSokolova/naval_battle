#pragma once
#include "Consts.h"
#include "Players.h"
#include "Fields.h"
#include <iostream>

inline int letterToIndex(const char & c)
{
	if (c >= 'A' && c <= 'J')
		return c - 'A';
	else if (c >= 'a' && c <= 'j')
		return c - 'a';
}
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
