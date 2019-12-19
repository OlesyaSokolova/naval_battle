#pragma once
#include "Functions.h"
class View
{
public:
	View() = default;
	virtual ~View() = default;
	void initPlayers();
	friend void printInitMessage(std::string playerType);
	int chooseFirstPlayer();
	Point playerTurn(int playerIndex);
	void showPlayerField(const Player* player);
	void updatePlayerField(const Player* player);
	void updateFields(int playerIndex, int result);
	std::vector<Point> readPosition();
	void setAllUserShips();
	void addPlayers(std::vector<Player*> players);
private:
	std::vector<Player*> players_;
	int userIndex_;
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