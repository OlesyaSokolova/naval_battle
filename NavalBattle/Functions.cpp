#include "Functions.h"

Player * createPlayer(std::string playerType)
{
	if (playerType == RANDOM)
		return new RandomPlayer;
	if (playerType == OPTIMAL)
		return new OptimalPlayer;
	if (playerType == USER)
		return new UserPlayer;
}


bool isAccessible(const Point& point)
{
	int i = point.getI();
	int j = point.getJ();
	if ((i >= -1) && (i <= FIELD_SIZE) && (j >= -1) && (j <= FIELD_SIZE))
	{
		return true;
	}
	return false;
}

int calcDif(int x, int y)
{
	int dif = y - x;
	if (dif < 0)
		return -1;
	if (dif == 0)
		return 0;
	if (dif > 0)
		return +1;
}

std::vector<std::string> parsingString(std::string line, std::string delim)
{
	std::vector<std::string> result;
	int pos = line.find(delim);
	while (pos != std::string::npos)
	{
		if (pos == line.size())
			return result;
		result.push_back(line.substr(0, pos));
		line.erase(0, pos + delim.length());
		pos = line.find(delim);
	}
	if (line.substr(0, pos) != EMPTY_STRING)
	{
		result.push_back(line.substr(0, pos));
	}

	return result;
}
Point randomPointOnLine(int line)
{
	srand(time(NULL));
	int i = 1, j = 1;
	if (line == 0)
	{
		i = 1;
		j = rand() % 8 + 1;
	}
	if (line == 1)
	{
		i = rand() % 8 + 1;
		j = 8;
	}
	if (line == 2)
	{
		i = 8;
		j = rand() % 8 + 1;
	}
	else if (line == 3)
	{
		i = rand() % 8 + 1;
		j = 1;
	}
	return Point(i, j);
}
