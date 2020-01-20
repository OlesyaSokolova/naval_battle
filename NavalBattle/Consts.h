#include <string>
#include <unordered_map>
#include <algorithm>


const int NUMBER_OF_ARGUMENTS = 6;
const int FIRST_ARGUMENT_NUMBER = 1;
const std::string ROUNDS_NUMBER_KEY_SHORT = "-c";
const std::string ROUNDS_NUMBER_KEY_LONG = "--count";
const std::string FIRST_PLAYER_TYPE_KEY_SHORT = "-f";
const std::string FIRST_PLAYER_TYPE_KEY_LONG = "--first";
const std::string SECOND_PLAYER_TYPE_KEY_SHORT = "-s";
const std::string SECOND_PLAYER_TYPE_KEY_LONG = "--second";
const std::string SHOW_HELP_KEY_SHORT = "-h";
const std::string SHOW_HELP_KEY_LONG = "--help";

const int FIELD_SIZE = 10;
const int DIRECTIONS_NUMBER = 4;

const int BATTLESHIPS_NUMBER = 1;
const int CRUISERS_NUMBER = 2;
const int DESTROYERS_NUMBER = 3;
const int TORPEDO_BOATS_NUMBER = 4;

const int BATTLESHIP_SIZE = 4;
const int CRUISER_SIZE = 3;
const int DESTROYER_SIZE = 2;
const int TORPEDO_BOAT_SIZE = 1;
const int KILLED_SHIP_SIZE = 0;
const int NO_SHIPS = 0;
const int SHIP_TYPES_NUMBER = 4;

const int SHIPS_NUMBER = BATTLESHIPS_NUMBER + CRUISERS_NUMBER + DESTROYERS_NUMBER + TORPEDO_BOATS_NUMBER;
const int PLAYERS_NUMBER = 2;
const int DIRECTIONS = 8;

const int FIRST_DIRECTION = 0;
const int SECOND_DIRECTION = 1;
const int THIRD_DIRECTION = 2;
const int FOURS_DIRECTION = 3;

const int FIRST_DIRECTION_I = 1;
const int SECOND_DIRECTION_J = 8;
const int THIRD_DIRECTION_I = 8;
const int FOURS_DIRECTION_J = 1;

const int LINE_SIZE = 8;

const int POINT_PARAMETERS = 2;
const int POINTS_NUMBER_ON_LINE = 8;

enum PointCondition { blank = (int)' ', ship = (int)'x', enemyInjured = (int)'#', enemyMissed = (int)'o'};
enum ShotResult {unknown = (int)' ', missed = (int)'o', injured = (int)'#', killed};

const std::string DELIMITER_STRING_GAP = " ";
const std::string DELIMITER_STRING_DOUBLE_GAP = "  ";
const std::string LONG_DELIMITER = "       ";
const char DELIMITER_LINE = '\n';
const char DELIMITER_GAP = ' ';
const char DELIMITER_BRACKET_OPEN = '(';
const char DELIMITER_BRACKET_CLOSE = ')';
const char DELIMITER_DOT = '.';
const char DELIMITER_COMMA = ',';
const std::string DELIMITER_COLON = ": ";

const std::string GETCHAR = "Please press ENTER ";
const std::string UNKNOWN_WRONG_INPUT = "Wrong input.";
const std::string WRONG_CURRENT_POINT_INPUT = "Wrong point input: ";
const std::string WRONG_CURRENT_POINT_OUT_OF_FIELD_RANGES = "This point is out of field ranges: ";
const std::string WRONG_CURRENT_POINT_ALREADY_CHECKED = "You have already checked this point: ";
const std::string WRONG_CURRENT_POINT_ALREADY_USED = "You have already used this point: ";
const std::string SUGGESTION_TO_TRY_AGAIN = "Please, try again";
const std::string TO_QUIT = "to quit.";
const std::string TO_CONTINUE = "to continue.";
const std::string TO_CHECK_POINT_AT_USER_FIELD = "to check this point at your field.";
const std::string TO_SET_USER_SHIPS_RANDOMLY = "Ok! Your ships will be set randomly.";
const std::string TO_START= "if you are ready to start.";
const std::string TO_RESTART = "and restart the game.";
const std::string USER_WON = "Congratulations!";
const std::string USER_LOSE = "Unfortunately, you lose.";
const std::string NOBODY_WON = "Friendship won";
const std::string SMILE = ":)";
const std::string CHOOSE_FIRST_PLAYER = "Well ok now let's choose the player who will start: ";
const std::string SUGGESTION_TO_ENTER_POINT = "Enter a point to shoot:";
const std::string SUGGESTION_TO_SET_SHIPS_RANDOMLY = "If you are lazy, bot can do it for you randomly, just type \"r\":";
const std::string SUGGESTION_TO_SET_SHIPS = "Set your ships.";
const std::string USER_FIELD = "This is your field:";
const std::string USER_ENEMY_FIELD = "And this is your enemy's field:";
const std::string FIRST_FIELD = "First player's field:";
const std::string SECOND_FIELD = "Second player's field:";
const std::string ENEMY_IS_READY = "Your enemy is ready!";
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
const char END_LINE = '\n';

const char ADDENDUM_FOR_NUMBER = '0';
const char ADDENDUM_FOR_LETTER_UPPERCASE = 'A';
const char ADDENDUM_FOR_LETTER_LOWERCASE = 'a';
const char RANDOM_KEY_LOWERCASE = 'r';
const char RANDOM_KEY_UPPERCASE = 'R';
const int RANDOM_KEY_POINT_PARAMETERS = 1;
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
const int MIN_I = 0;
const int MIN_J = 0;
const int USER_DOESNT_PARTICIPATE = -1;
const int FIRST_ROUND = 0;
const int UNKNOWN_WINNER = 0;
const int ONE_ROUND = 1;

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
const int DEFAULT_ROUNDS_NUMBER = 1;
const std::string DEFAULT_PLAYER_TYPE = RANDOM;
const int CHOOSING_PLAYER_SLEEP = 2000000;
const int SHOW_COMPUTER_TURN_SLEEP = 2500000;
const std::string BLUE_SCREEN_WHITE_TEXT = "color 17";
const int USER_DIDNT_ENTERED_ANYTHING = 0;
const int I_RANDOM = -1;
const int J_RANDOM = -1;

const int HELP_INDEX = 0;
const int ROUND_NUMBER_INDEX = 1;
const int USER_TYPES_INDEX = 2;

const int SUCCESSFUL_DIRECTION_IS_NOT_DEFINED = 1;
const int NO_SUCCESSFUL_SHOTS = 0;
const int NO_POINTS_TO_USE = 0;
const int POINT_WAS_NOT_USED = 0;