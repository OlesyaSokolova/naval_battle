#include "Functions.h"
class View 
{
public:
	View() = default;
	View(std::vector<Player*> players);
	virtual ~View() = default;
	void initPlayers(std::vector<Player*> players);
	friend void printInitMessage(std::string playerType);
	int chooseFirstPlayer();
    Point playerTurn(int playerIndex);
	void updateFields(int playerIndex, int result);
private:
	std::vector<Player*> players_;
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