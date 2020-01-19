#include "Functions.h"
#include <iostream>


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
bool isAccessibleForTurn(const Point& point)
{
	int i = point.getI();
	int j = point.getJ();
	if ((i >= 0) && (i < FIELD_SIZE) && (j >= 0) && (j < FIELD_SIZE))
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
void shufflePoints(std::vector<Point>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::swap(vec[i], vec[rand()%vec.size()]);
	}
}
int zeroDirection_calcLastPoint(std::vector<Point> points)
{
	int minParam = FIELD_SIZE;
	int result = 0;
	for (int i = 0; i < points.size(); i++)
	{
		if (points[i].getI() < minParam)
		{
			minParam = points[i].getI();
			result = i;
		}
	}
	return result;
}
int firstDirection_calcLastPoint(std::vector<Point> points)
{
	int maxParam = 0;
	int result = 0;
	for (int i = 0; i < points.size(); i++)
	{
		if (points[i].getJ() > maxParam)
		{
			maxParam = points[i].getJ();
			result = i;
		}
	}
	return result;
}
int secondDirection_calcLastPoint(std::vector<Point> points)
{
	int maxParam = 0;
	int result = 0;
	for (int i = 0; i < points.size(); i++)
	{
		if (points[i].getI() > maxParam)
		{
			maxParam = points[i].getI();
			result = i;
		}
	}
	return result;
}

int thirdDirection_calcLastPoint(std::vector<Point> points)
{
	int minParam = FIELD_SIZE;
	int result = 0;
	for (int i = 0; i < points.size(); i++)
	{
		if (points[i].getJ() < minParam)
		{
			minParam = points[i].getJ();
			result = i;
		}
	}
	return result;
}
std::unordered_map<int, calcFunc> initLastPointsMap()
{
	std::unordered_map<int, calcFunc> result{ { 0, zeroDirection_calcLastPoint },
											  { 1, firstDirection_calcLastPoint},
											  {2, secondDirection_calcLastPoint},
											  {3, thirdDirection_calcLastPoint }};
	return result;

}
std::tuple < std::string, int, std::vector<std::string>> parsingString(const int argumentsNumber, const char ** argv)
{
	int rounds_number = DEFAULT_ROUNDS_NUMBER;
	std::vector<std::string> playersTypes;
	std::string firstPlayerType = DEFAULT_PLAYER_TYPE;
	std::string secondPlayerType = DEFAULT_PLAYER_TYPE;
	std::string help = EMPTY_STRING;

	std::unordered_map <std::string, const std::string, std::hash<std::string>> PLAYERS_TYPES{ {"r", RANDOM },
																						 { "o", OPTIMAL },
																						 { "u", USER } };
	for (int i = FIRST_ARGUMENT_NUMBER; i < argumentsNumber; i++)
	{
		if (argv[i] == SHOW_HELP_KEY_SHORT || argv[i] == SHOW_HELP_KEY_LONG)
		{
			help = argv[i];
			break;
		}
		if (argv[i] == ROUNDS_NUMBER_KEY_SHORT || argv[i] == ROUNDS_NUMBER_KEY_LONG)
		{
			rounds_number = atoi(argv[i + DELIMITER_STRING_GAP.length()]);
		}
		if (argv[i] == FIRST_PLAYER_TYPE_KEY_SHORT || argv[i] == FIRST_PLAYER_TYPE_KEY_LONG)
		{
			std::string type = argv[i + DELIMITER_STRING_GAP.length()];
			firstPlayerType = PLAYERS_TYPES[type];
			
		}
		if (argv[i] == SECOND_PLAYER_TYPE_KEY_SHORT || argv[i] == SECOND_PLAYER_TYPE_KEY_LONG)
		{
			std::string type = argv[i + DELIMITER_STRING_GAP.length()];
			secondPlayerType = PLAYERS_TYPES[type];
		}
	}
	playersTypes.push_back(firstPlayerType);
	playersTypes.push_back(secondPlayerType);
	return std::make_tuple(help, rounds_number, playersTypes);
}
void printHelp()
{
	for (int i = 0; i < HELP.size(); i++)
	{
		std::cout << HELP[i];
	}
	getchar();
}
