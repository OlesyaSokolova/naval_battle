
#include <vector>
#include "Consts.h"
class Ship
{
public:
	Ship() = default;
	Ship(int size);
	int getShipSize() const;
	std::string getShipName() const;
	int getShipNumber() const;
	void decreaseSize();
	~Ship() = default;
private:
	std::string shipName_;
	int number_;
	int shipSize_;
	int size_;
};