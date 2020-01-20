#pragma once
#include "BasePlayer.h"
namespace Sokolova {
	class RandomPlayer : public Player
	{
	public:
		RandomPlayer();
		Point choosePoint() override;
		void initPrivateData() override;
	private:
		std::vector<Point> pointsToUse;
	};
}