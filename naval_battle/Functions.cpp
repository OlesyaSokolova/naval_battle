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
		result.push_back(line.substr(0, pos));
		line.erase(0, pos + delim.length());
		pos = line.find(delim);
	}
	result.push_back(line.substr(0, pos));
	return result;
}