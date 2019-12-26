#include "Ships.h"
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
	std::string getOriginalInput() const;
protected:
	int i_;
	int j_;
	friend class ProxyRandom;
	char i_j_[POINT_PARAMETERS + INDEX_SHIFT];
};

class InfoPoint : public Point
{
public:
	InfoPoint() = default;
	InfoPoint(int i, int j, Ship* ship);
	ShotResult decreaseShipCounter() const;
private:
	Ship* ship_;
};