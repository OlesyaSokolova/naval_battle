#include <vector>
#include "Consts.h"
namespace Sokolova {
	class Ship
	{
	public:
		Ship() = default;
		Ship(int size);
		~Ship() = default;	
		int getShipSize() const;
		std::string getShipName() const;
		int getShipNumber() const;
		void decreaseSize();		
	private:
		std::string shipName_;
		int number_;
		int shipSize_;
		int size_;
	};
}