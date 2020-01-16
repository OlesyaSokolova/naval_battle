
#include <string>

const int FIELD_SIZE = 10;
const int DIRECTIONS_NUMBER = 4;

const int BATTLESHIPS_NUMBER = 1;
const int CRUISERS_NUMBER = 2;
const int DESTROYERS_NUMBER = 3;
const int TORPEDO_BOATS_NUMBER = 4;

const int BATTLESHIP_ID = 0;
const int CRUISER_ID = 1;
const int DESTROYER_ID = 3;
const int TORPEDO_BOAT_ID = 4;

const int BATTLESHIP_SIZE = 4;
const int CRUISER_SIZE = 3;
const int DESTROYER_SIZE = 2;
const int TORPEDO_BOAT_SIZE = 1;
const int KILLED_SHIP_SIZE = 0;

const int SHIP_TYPES_NUMBER = 4;

const int SHIPS_NUMBER = BATTLESHIPS_NUMBER + CRUISERS_NUMBER + DESTROYERS_NUMBER + TORPEDO_BOATS_NUMBER;
const int PLAYERS_NUMBER = 2;
const int DIRECTIONS = 8;
const int POINT_PARAMETERS = 2;
const int POINTS_NUMBER_ON_LINE = 8;

enum PointCondition { blank = (int)' ', ship = (int)'x', enemyInjured = (int)'#', enemyMissed = (int)'o'};
enum ShotResult {unknown = (int)' ', missed = (int)'o', injured = (int)'#', killed};

const std::string DELIMITER_1 = " ";
const char DELIMITER_2 = '\n';
const std::string LONG_DELIMITER = "       ";
const std::string BATTLESHIP = "Battleship";
const std::string CRUISER = "Cruiser";
const std::string DESTROYER = "Destroyer";
const std::string TORPEDO_BOAT = "Torpedo-boat";

const std::string USER = "user";
const std::string RANDOM = "random";
const std::string OPTIMAL = "optimal";

const std::string GRAPHIC_VIEW = "graphic";
const std::string CONSOLE_VIEW = "console";

const std::string EMPTY_STRING = "";
const char END_STRING = '\0';

const char ADDENDUM_FOR_NUMBER = '0';
const char ADDENDUM_FOR_LETTER_UPPERCASE = 'A';
const char ADDENDUM_FOR_LETTER_LOWERCASE = 'a';

const char FIRST_NUMBER = '0';
const char LAST_NUMBER = '9';
const char FIRST_LETTER_UPPERCASE = 'A';
const char LAST_LETTER_UPPERCASE = 'J';
const char FIRST_LETTER_LOWERCASE = 'a';
const char LAST_LETTER_LOWERCASE = 'j';
const int INIT_STATISTIC = 0;
const int MAX_INPUT_LINE_SIZE = 11;
const int INDEX_SHIFT = 1;
const int INDEX_SHIFT_2 = 2;
const int SHIP_SIZE_SHIFT = 1;
const int K_VARIANTS_FOR_LINES = 2;
const int TIMES_TO_USE_POINT_OPTIMALLY = 2;
const int ENDS_NUMBER = 2;
const int END_GAME_SHIPS_NUMBER = 0;
const int FIRST_DIRECTION = 0;
const int MIN_I = 0;
const int MIN_J = 0;
const int USER_DOESNT_PARTICIPATE = -1;
const int pointAreaDi[DIRECTIONS_NUMBER] = { -1, 0, 1, 0 };
const int pointAreaDj[DIRECTIONS_NUMBER] = { 0, 1, 0, -1 };
const int shipFirstDi[DIRECTIONS] = { -1, 1, 1, 1, 1, -1, -1, -1 };
const int shipFirstDj[DIRECTIONS] = { 1, 1, 1, -1, -1, -1, -1, 1 };

const int shipLastDi[DIRECTIONS] = { 1, -1, -1, -1, -1, 1, 1, 1 };
const int shipLastDj[DIRECTIONS] = { -1, -1, -1, 1, 1, 1, 1, -1 };
const int kForLines[DIRECTIONS_NUMBER][K_VARIANTS_FOR_LINES] = { 0, 5,
7, 2,
4, 1,
6, 3,
};
const int RESULT_VARIANTS = 4;
const int FIRST = 0;
const enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Red = 4,
	DarkGray = 8,
	LightBlue = 9,
	White = 15
};