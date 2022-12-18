#pragma once

#include "Cell.h"
#include "Entity.h"
#include <vector>

class Player {
private:

public:
	Player();
	Player(Cell* start_cell, sf::Color col);
	sf::Color color;
	sf::Color ent_color;
	unsigned short int money;
	std::vector<Cell*> self_cells;
	std::vector<Entity*> self_entity_cells; /*Cells, where there are entities*/
	bool movestatus; /*1 if Player's move now*/
};