#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Cell.h"
#include <vector>

Player::Player(Cell* start_cell) {
	money = 20;
	self_cells.push_back(start_cell);
	movestatus = true;
}

Player::Player(){}