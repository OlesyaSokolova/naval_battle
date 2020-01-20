#pragma once
#include "BasePlayer.h"
namespace Sokolova{
	class UserPlayer : public Player
	{
	public:
		UserPlayer();
		Point choosePoint() override;
		void initPrivateData() override;
	};
}