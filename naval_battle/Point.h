#pragma once
#include "Ships.h"
#include <iostream>
#include "Consts.h"
class Point
{
public:
	Point();
	Point(int i, int j);
	int getI() const;
	int getJ() const;
	//operator=!!!!!!
	int letterToIndex(const char c);
	virtual void readPoint();
	void getPoint(std::string);
	virtual ~Point() = default;
protected:
	int i_;
	int j_; 
	friend class ProxyRandom;
 };

class InfoPoint : public Point
{
public:
	InfoPoint() = default;
	InfoPoint(int i, int j, Ship* ship);	
private:
	Ship* ship_;
};