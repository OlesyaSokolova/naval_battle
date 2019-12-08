#include "Functions.h"

class View 
{
public:
	View() = default;
	View(Player* player1, Player* player2);
	virtual ~View() = default;
private:
	Player* player1_;
	Player* player2_;
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