#include "Ships.h"
namespace Sokolova {
	class Point
	{
	public:
		Point();
		Point(int i, int j);	
		int getI() const;
		int getJ() const;
		std::string getOriginalInput() const;
		int getUsedTimes() const;
		void getPoint(std::string);
		void increaseTimesToUse();
		int letterToIndex(const char c);
		virtual void readPoint();
		virtual ~Point() = default;
		
	protected:
		int i_;
		int j_;
		friend class ProxyRandom;
		char i_j_[POINT_PARAMETERS + INDEX_SHIFT];
	private:
		int usedTimes_;
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
}