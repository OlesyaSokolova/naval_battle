#include "Functions.h"

class View
{
public:
	View();
	virtual ~View() = default;
	void initPlayers(int currentRoundNumber, int roundsNumber);
	int chooseFirstPlayer();
	Point playerTurn(int playerIndex);
	void showPlayerField(const Player* player);
	void initPlayerField(const Player* player);
	void updateFields(int playerIndex, ShotResult result);
	std::vector<Point> readPosition();
	void setAllUserShips();
	void showPlayerEnemyField(const Player* player);
	void addPlayers(std::vector<Player*> players);
	void showWinner(int winnerIndex);
	void showStatistic(int statistic[PLAYERS_NUMBER]);
	void showFieldsWithUser();
	void showFields();
private:
	std::vector<Player*> players_;
	int userIndex_;
	std::unordered_map <ShotResult, std::string, std::hash<int>> userResultMessages;
	std::unordered_map <ShotResult, std::string, std::hash<int>> enemyResultMessages;
};

//class GraphicView : public View
//{
//public:
//
//private:
//};

//class ConsoleView : public View
//{
//public:
//
//private:
//};
//View * createView(std::string viewType);