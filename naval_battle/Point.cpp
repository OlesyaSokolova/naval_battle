#include "Point.h"
Point::Point()
	:i_(0), j_(0), ship_(NULL) {}

Point::Point(int i, int j, Ship* ship)
	: i_(i), j_(j), ship_(ship) {}

Point::Point(int i, int j)
	: i_(i), j_(j), ship_(NULL) {}