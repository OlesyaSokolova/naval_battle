#pragma once
#include "Ships.h"
struct Point
{
	Point();
	Point(int i, int j);
	Point(int i, int j, Ship* ship);
	//operator=!!!!!!
	int i_;
	int j_;
	Ship* ship_;
 };