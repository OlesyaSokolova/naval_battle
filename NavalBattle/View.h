#include "Functions.h"
#include <algorithm>
#include <unordered_map>
class View
{
public:
	View();
	virtual ~View() = default;
	void initPlayers();
	int chooseFirstPlayer();
	Point playerTurn(int playerIndex);
	void showPlayerField(const Player* player);
	void initPlayerField(const Player* player);
	void updateFields(int playerIndex, shotResult result);
	std::vector<Point> readPosition();
	void setAllUserShips();
	void showPlayerEnemyField(const Player* player);
	void updatePlayerEnemyField(const Player* player);
	void addPlayers(std::vector<Player*> players);
private:
	std::vector<Player*> players_;
	int userIndex_;
	std::unordered_map <shotResult, std::string, std::hash<int>> userResultMessages;
	std::unordered_map <shotResult, std::string, std::hash<int>> enemyResultMessages;
};

class GraphicView : public View
{
public:

private:
};

class ConsoleView : public View
{
public:

private:
};
View * createView(std::string viewType);