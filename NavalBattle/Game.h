
#include <string>
#include "View.h"

class Game
{
public:
	Game(std::vector<std::string> playerTypes, std::string viewType, int roundsNumber);
	~Game() = default;
	void start();
	int round();
	bool shoot(int playerIndex, Point p);
private:
	View * view_;
	std::vector<Player*> players_;
	int roundsNumber_;
	int statistic_[PLAYERS_NUMBER];
};
