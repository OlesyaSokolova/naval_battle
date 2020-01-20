#include <string>
#include "View.h"
namespace Sokolova {
	class Game
	{
	public:		
		Game(std::vector<std::string> playerTypes, int roundsNumber);
		void start();		
		int round(int currentRoundNumber);
		ShotResult shoot(int playerIndex, Point p);
		Game(Game const&) = delete;
		Game& operator= (Game const&) = delete;
	private:		
		View * view_;
		std::vector<Player*> players_;
		int roundsNumber_;
		int statistic_[PLAYERS_NUMBER];
	};
}
