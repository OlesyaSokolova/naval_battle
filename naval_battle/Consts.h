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

const int SHIPS_NUMBER = BATTLESHIPS_NUMBER + CRUISERS_NUMBER+DESTROYERS_NUMBER + TORPEDO_BOATS_NUMBER;
const int PLAYERS_NUMBER = 2;
const int DIRECTIONS = 8;

//enum ShotDescription {unknown, missed, injured, killed, suggested};
enum PointCondition {blank = (int)' ', missed, injured = (int)'X' };

const std::string BATTLESHIP = "Battleship";
const std::string CRUISER = "Cruiser";
const std::string DESTROYER = "Destroyer";
const std::string TORPEDO_BOAT = "Torpedo-boat";

const std::string USER = "user";
const std::string RANDOM = "random";
const std::string OPTIMAL = "optimal";

const std::string GRAPHIC_VIEW = "graphic";
const std::string CONSOLE_VIEW = "console";

const int INDEX_SHIFT = 1;
const int SHIP_SIZE_SHIFT = 1;
