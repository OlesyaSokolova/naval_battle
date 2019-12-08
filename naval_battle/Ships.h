#include <vector>
#include "Point.h"
class Ship 
{
public:
	Ship() = default;
	Ship(std::vector <Point>& position);
	int getShipSize() const;
	std::string getShipName() const;
	int getShipNumber() const;
	virtual ~Ship() = 0;
protected:
	std::string shipName_;
	std::vector <Point> position_;
	int number_;
	int shipSize_;
};
class Ship_4 : public Ship
{
public:
	Ship_4();
	Ship_4(std::vector<Point>& position);
};
class Ship_3 : public Ship
{
public:
	Ship_3();
	Ship_3(std::vector<Point>& position);
};
class Ship_2 : public Ship
{
public:
	Ship_2();
	Ship_2(std::vector<Point>& position);
};
class Ship_1 : public Ship
{
public:
	Ship_1();
	Ship_1(std::vector<Point>& position);
};
class Ships 
{
public:
	Ships() = default;
	~Ships()= default;
	Ship* getShip(int id);
private:
	Ship_4 battleship;
	Ship_3 cruiser;
	Ship_2 destroyer;
	Ship_1 torpedo_boat;
};