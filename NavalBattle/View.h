#include "Functions.h"
namespace Sokolova {
	class View
	{
	public:
		View();
		virtual ~View() = default;
		void addPlayers(std::vector<Player*> players);
		void initPlayers(int currentRoundNumber, int roundsNumber);
		void initPlayerField(const Player* player);
		int chooseFirstPlayer();	
		void setAllUserShips();
		void showPlayerField(const Player* player);
		void showPlayerEnemyField(const Player* player);		
		void showWinner(int winnerIndex);
		void showStatistic(int statistic[PLAYERS_NUMBER]);
		void showFields();
		void updateFields(int playerIndex, ShotResult result);
		Point playerTurn(int playerIndex);		
		std::vector<Point> readPosition();
	private:
		std::vector<Player*> players_;
		int userIndex_;
		std::unordered_map <ShotResult, std::string, std::hash<int>> userResultMessages;
		std::unordered_map <ShotResult, std::string, std::hash<int>> enemyResultMessages;
	};
}