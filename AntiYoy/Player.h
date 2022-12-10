#pragma once

#include "Cell.h"
#include "Entity.h"
#include <vector>

class Player {
private:

public:
	Player();
	Player(Cell* start_cell);
	unsigned short int money;
	std::vector<Cell*> self_cells;
	std::vector<Cell*> self_entity_cells; /*Cells, where there are entities*/
	bool movestatus; /*1 if Player's move now*/
};