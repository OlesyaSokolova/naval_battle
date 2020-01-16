#include "Players.h"
#include <time.h>

inline int indexToArrayIndex(int & i)
{
	return i - 1;
}
Player * createPlayer(std::string playerType);
inline int nextPlayer(int playerIndex, ShotResult result)
{
	bool res = result == missed ? 0 : 1;
	int next = (playerIndex + (int)!res) % PLAYERS_NUMBER;
	return next;
}
inline int choosePlayer()
{
	srand(time(NULL));
	return rand() % PLAYERS_NUMBER;
}
bool isAccessible(const Point& point);
inline char symbol(int j)
{
	char c = (char)j + ADDENDUM_FOR_LETTER_LOWERCASE;
	return c;
}
int calcDif(int x, int y);
std::vector<std::string> parsingString(std::string line, std::string delim);
Point randomPointOnLine(int line);
void shufflePoints(std::vector<Point>& vec);
int calcLastPoint(int dir, std::vector<Point> points);
bool isAccessibleForTurn(const Point& point);
inline std::string indexToString(int i)
{
	if (i == FIRST)
	{
		return "first player";
	}
	else
	{
		return "second player";
	}
}
