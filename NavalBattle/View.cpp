#include "View.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <Windows.h>
namespace Sokolova {

	void View::addPlayers(std::vector<Player*> players)
	{
		this->userIndex_ = USER_DOESNT_PARTICIPATE;
		for (int i = 0; i < PLAYERS_NUMBER; i++)
		{
			if (players[i]->getPlayerType() == USER)
				this->userIndex_ = i;
			players_.push_back(players[i]);
		}
	}

	View::View()
	{
		userResultMessages.insert({ missed, "You missed! Now your enemy will shoot." });
		userResultMessages.insert({ injured, "Cool! You injured your enemy's ship. Shoot again." });
		userResultMessages.insert({ killed, "Great! You killed  your enemy's ship. Shoot again." });

		enemyResultMessages.insert({ missed, "Your enemy missed! Now you will shoot." });
		enemyResultMessages.insert({ injured, "Your enemy injured your ship. Now he will shoot again." });
		enemyResultMessages.insert({ killed, "Your enemy killed your ship. Now he will shoot again." });
	}

	void View::showPlayerField(const Player* player)
	{
		if (player->getPlayerType() == USER)
		{
			std::cout << USER_FIELD << std::endl;
		}
		int lineNumber = 0;
		std::cout << DELIMITER_STRING_DOUBLE_GAP;
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			std::cout << symbol(j) << DELIMITER_STRING_GAP;
		}
		std::cout << std::endl;
		for (int i = 0; i < FIELD_SIZE; i++)
		{
			std::cout << lineNumber << DELIMITER_STRING_GAP;
			for (int j = 0; j < FIELD_SIZE; j++)
			{
				std::cout << (char)player->myField_[i][j] << DELIMITER_STRING_GAP;
			}
			std::cout << std::endl;
			lineNumber++;
		}
	}

	void View::showPlayerEnemyField(const Player* player)
	{
		std::cout << USER_ENEMY_FIELD << std::endl;
		int lineNumber = 0;
		std::cout << DELIMITER_STRING_DOUBLE_GAP;
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			std::cout << symbol(j) << DELIMITER_STRING_GAP;
		}
		std::cout << std::endl;
		for (int i = 0; i < FIELD_SIZE; i++)
		{
			std::cout << lineNumber << DELIMITER_STRING_GAP;
			for (int j = 0; j < FIELD_SIZE; j++)
			{
				std::cout << (char)player->enemyField_[i][j] << DELIMITER_STRING_GAP;
			}
			std::cout << std::endl;
			lineNumber++;
		}
	}

	void View::showFields()
	{
		if (userIndex_ != USER_DOESNT_PARTICIPATE)
		{
			std::cout << USER_FIELD + LONG_DELIMITER + DELIMITER_STRING_GAP + USER_ENEMY_FIELD << std::endl;
		}
		else
		{
			std::cout << FIRST_FIELD + LONG_DELIMITER + DELIMITER_STRING_GAP + SECOND_FIELD << std::endl;
		}
		std::cout << std::endl;
		int lineNumber = 0;
		std::cout << DELIMITER_STRING_DOUBLE_GAP;
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			std::cout << symbol(j) << DELIMITER_STRING_GAP;
		}
		std::cout << LONG_DELIMITER + DELIMITER_STRING_GAP;
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			std::cout << symbol(j) << DELIMITER_STRING_GAP;
		}
		std::cout << std::endl;
		for (int i = 0; i < FIELD_SIZE; i++)
		{
			std::cout << lineNumber << DELIMITER_STRING_GAP;
			for (int j = 0; j < FIELD_SIZE; j++)
			{
				std::cout << (char)players_[FIRST]->myField_[i][j] << DELIMITER_STRING_GAP;
			}
			std::cout << LONG_DELIMITER;
			std::cout << lineNumber << DELIMITER_STRING_GAP;
			for (int j = 0; j < FIELD_SIZE; j++)
			{
				if (userIndex_ != USER_DOESNT_PARTICIPATE)
				{
					std::cout << (char)this->players_[userIndex_]->enemyField_[i][j] << DELIMITER_STRING_GAP;
				}
				else
				{
					std::cout << (char)this->players_[(FIRST + INDEX_SHIFT) % PLAYERS_NUMBER]->myField_[i][j] << DELIMITER_STRING_GAP;
				}

			}
			std::cout << std::endl;
			lineNumber++;
		}
		std::cout << std::endl;
	}

	void View::initPlayerField(const Player* player)
	{
		system("cls");
		if (player->remainedShipsNumber_ < SHIPS_NUMBER)
		{
			std::cout << SUGGESTION_TO_SET_SHIPS << std::endl;
		}
		this->showPlayerField(player);
	}

	void View::setAllUserShips()
	{
		int userIndex = this->userIndex_;
		Player* player = this->players_[userIndex];
		std::cout << SUGGESTION_TO_SET_SHIPS << std::endl;
		this->showPlayerField(player);
		std::cout << SUGGESTION_TO_SET_SHIPS_RANDOMLY << std::endl;

		std::vector <Point> position;
		int i = 0;
		int setShipsNumber = 0;
		while (setShipsNumber < SHIPS_NUMBER)
		{
			position = this->readPosition();

			if (position.size() == USER_DIDNT_ENTERED_ANYTHING)
			{
				continue;
			}

			if (position.size() == RANDOM_KEY_POINT_PARAMETERS)
			{
				if (position[FIRST].getI() == I_RANDOM && position[FIRST].getJ() == J_RANDOM)
				{
					std::cout << TO_SET_USER_SHIPS_RANDOMLY + GETCHAR << std::endl;
					getchar();
					player->setAllShipsRandomly();
					break;
				}
			}
			Ship ship;
			for (i = 0; i < SHIPS_NUMBER; i++)
			{
				if (player->myShips_[i].getShipSize() == position.size())
				{
					ship = player->myShips_[i];
					break;
				}
			}
			player->setShip(position);
			this->initPlayerField(player);
			player->initInfoPoins(position, &ship);
			setShipsNumber++;
		}
		player->remainedShipsNumber_ = SHIPS_NUMBER;
	}

	void View::initPlayers(int currentRoundNumber, int roundsNumber)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		system(BLUE_SCREEN_WHITE_TEXT.c_str());
		if (currentRoundNumber == FIRST_ROUND)
		{
			std::cout << " Hello! Let's play. Information about this game:\n" <<
				"first player: " << this->players_[FIRST]->getPlayerType() << END_LINE <<
				"second player: " << this->players_[(FIRST + INDEX_SHIFT) % PLAYERS_NUMBER]->getPlayerType() << END_LINE <<
				"number of rounds: " << roundsNumber << END_LINE <<
				GETCHAR + TO_START << std::endl;
			getchar();
			system("cls");
		}

		if (userIndex_ != USER_DOESNT_PARTICIPATE)
		{
			setAllUserShips();
			system("cls");
			showFields();
			int anotherPlayerIndex = (userIndex_ + INDEX_SHIFT) % PLAYERS_NUMBER;
			players_[anotherPlayerIndex]->setAllShipsRandomly();
			std::cout << ENEMY_IS_READY << std::endl;
		}
		else
		{
			for (int i = 0; i < PLAYERS_NUMBER; i++)
			{
				players_[i]->initMyField();
				players_[i]->initEnemyField();
				players_[i]->setAllShipsRandomly();
			}
			showFields();
		}
	}

	int View::chooseFirstPlayer()
	{
		std::cout << CHOOSE_FIRST_PLAYER;
		int first = choosePlayer();
		std::this_thread::sleep_for(std::chrono::microseconds(CHOOSING_PLAYER_SLEEP));
		std::cout << indexToString(first) << std::endl;
		std::cout << GETCHAR + TO_START;
		getchar();
		return first;
	}

	Point View::playerTurn(int playerIndex)
	{
		Player* player = this->players_[playerIndex];
		std::string type = player->getPlayerType();
		Point p = player->choosePoint();
		bool pointIsCorrect;
		bool pointIsNew = false;
		if (userIndex_ != USER_DOESNT_PARTICIPATE)
		{
			if (userIndex_ == playerIndex)
			{
				pointIsCorrect = isAccessibleForTurn(p);
				if (pointIsCorrect == true)
				{
					pointIsNew = players_[userIndex_]->enemyField_[p.getI()][p.getJ()] == unknown ? true : false;
				}
				while (pointIsNew == false)
				{
					pointIsCorrect = isAccessible(p);
					if (pointIsCorrect == false)
					{
						pointIsNew = false;
						std::cout << WRONG_CURRENT_POINT_OUT_OF_FIELD_RANGES << p.getOriginalInput() << DELIMITER_DOT << SUGGESTION_TO_TRY_AGAIN << DELIMITER_DOT << std::endl;
					}
					else
					{
						std::cout << WRONG_CURRENT_POINT_ALREADY_CHECKED << p.getOriginalInput() << DELIMITER_LINE << SUGGESTION_TO_TRY_AGAIN << DELIMITER_DOT << std::endl;
					}
					p = player->choosePoint();
					pointIsNew = players_[userIndex_]->enemyField_[p.getI()][p.getJ()] == unknown ? true : false;
					bool pointIsCorrect = isAccessible(p);
				}
			}
			else
			{
				std::cout << "Your enemy turn: " << p.getOriginalInput() << std::endl;
				std::cout << GETCHAR + TO_CHECK_POINT_AT_USER_FIELD;
				getchar();
			}
		}
		return p;
	}

	void View::updateFields(int playerIndex, ShotResult result)
	{
		system("cls");
		showFields();
		if (this->players_[playerIndex]->getPlayerType() == USER)
		{
			std::cout << this->userResultMessages[result] << std::endl;
		}
		else if (userIndex_ != USER_DOESNT_PARTICIPATE)
		{
			std::cout << this->enemyResultMessages[result] << std::endl;
		}

	}

	std::vector<Point> View::readPosition()
	{
		std::vector <Point> position;
		std::string line;
		getline(std::cin, line, DELIMITER_LINE);
		int lineSize = line.size();
		if (line.size() == RANDOM_KEY_POINT_PARAMETERS && (line[FIRST] == RANDOM_KEY_LOWERCASE || line[FIRST] == RANDOM_KEY_UPPERCASE))
		{
			position.push_back(Point(I_RANDOM, J_RANDOM));
			return position;
		}
		if (lineSize > MAX_INPUT_LINE_SIZE)
		{
			std::cout << UNKNOWN_WRONG_INPUT + SUGGESTION_TO_TRY_AGAIN << std::endl;
			return position;
		}
		std::vector <std::string> points = parsingString(line, DELIMITER_STRING_GAP);
		for (int i = 0; i < points.size(); i++)
		{
			Point p;
			p.getPoint(points[i]);
			if (points[i].size() != POINT_PARAMETERS || !isAccessible(p))
			{
				std::cout << WRONG_CURRENT_POINT_INPUT << points[i] << DELIMITER_DOT << SUGGESTION_TO_TRY_AGAIN << std::endl;
				return position;
			}
			if (this->players_[userIndex_]->myField_[p.getI()][p.getJ()] != blank)
			{
				std::cout << WRONG_CURRENT_POINT_ALREADY_USED << points[i] << DELIMITER_DOT << SUGGESTION_TO_TRY_AGAIN << std::endl;
				return position;
			}
			position.push_back(p);
		}
		return position;
	}

	void View::showWinner(int winnerIndex)
	{
		std::cout << "Winner: " << indexToString(winnerIndex) << std::endl;
		if (userIndex_ != USER_DOESNT_PARTICIPATE)
		{
			if (winnerIndex == userIndex_)
			{
				std::cout << USER_WON + SMILE << std::endl;
			}
			else
			{
				std::cout << USER_LOSE << std::endl;
			}

		}
		std::cout << GETCHAR + TO_CONTINUE << std::endl;
		getchar();
	}

	void View::showStatistic(int statistic[PLAYERS_NUMBER])
	{
		std::cout << "First player " <<
			DELIMITER_BRACKET_OPEN << this->players_[FIRST]->getPlayerType() << ")" <<
			" won " << statistic[FIRST] <<
			" times;" << std::endl;

		std::cout << "Second player " <<
			DELIMITER_BRACKET_OPEN << this->players_[(FIRST + INDEX_SHIFT) % PLAYERS_NUMBER]->getPlayerType() << DELIMITER_BRACKET_CLOSE <<
			" won " << statistic[(FIRST + INDEX_SHIFT) % PLAYERS_NUMBER] <<
			" times;" << std::endl;
		int firstPlayerVictories = statistic[FIRST];
		int secondPlayerVictories = statistic[(FIRST + INDEX_SHIFT) % PLAYERS_NUMBER];
		if (firstPlayerVictories == secondPlayerVictories)
		{
			std::cout << NOBODY_WON + SMILE << std::endl;
		}
		else
		{
			int winnerIndex = firstPlayerVictories > secondPlayerVictories ? FIRST : (FIRST + INDEX_SHIFT) % PLAYERS_NUMBER;
			std::string winner = indexToString(winnerIndex);
			std::string winnerType = this->players_[winnerIndex]->getPlayerType();
			std::cout << "Final winner: " << winner << DELIMITER_BRACKET_OPEN << winnerType << DELIMITER_BRACKET_CLOSE << std::endl;
		}

		std::cout << GETCHAR + TO_QUIT << std::endl;
		getchar();
	}
}
