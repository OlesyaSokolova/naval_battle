#pragma once
#include "Consts.h"
#include "Players.h"
#include "View.h"

int letterToIndex(const char & c);
int indexToArrayIndex(int & i);
Player * createPlayer(std::string playerType);
View * createView(std::string viewType);