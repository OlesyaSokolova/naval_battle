#pragma once
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

const int SHIP_TYPES_NUMBER = 4;

const int SHIPS_NUMBER = BATTLESHIPS_NUMBER + CRUISERS_NUMBER + DESTROYERS_NUMBER + TORPEDO_BOATS_NUMBER;
const int PLAYERS_NUMBER = 2;
const int DIRECTIONS = 8;
const int POINT_PARAMETERS = 2;

//enum ShotDescription {unknown, missed, injured, killed, suggested};
enum PointCondition { blank = (int)' ', missed, injured = (int)'x' };

const std::string DELIMITER_1 = " ";
const char DELIMITER_2 = '\n';

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

const int MAX_INPUT_LINE_SIZE = 11;
const int INDEX_SHIFT = 1;
const int SHIP_SIZE_SHIFT = 1;
const int K_VARIANTS_FOR_LINES = 2;
const int shipFirstDi[DIRECTIONS] = { -1, 1, 1, 1, 1, -1, -1, -1 };
const int shipFirstDj[DIRECTIONS] = { 1, 1, 1, -1, -1, -1, -1, 1 };

const int shipLastDi[DIRECTIONS] = { 1, -1, -1, -1, -1, 1, 1, 1 };
const int shipLastDj[DIRECTIONS] = { -1, -1, -1, 1, 1, 1, 1, -1 };
const int kForLines[DIRECTIONS_NUMBER][K_VARIANTS_FOR_LINES] = { 6, 3,
7, 2,
4, 1,
0, 5,
};