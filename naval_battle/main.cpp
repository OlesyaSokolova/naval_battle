#include <iostream>
#include "Game.h"
#include "optionparser.h"

int main()
{
	RandomPlayer player1;
	player1.setAllShips();
	player1.showMyField();
	getchar();
	return 0;
}