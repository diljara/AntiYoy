#pragma once

#include "Cell.h"
#include "Entity.h"
#include <vector>

class Player {
private:

public:
	Player();
	Player(sf::Color col);
	sf::Color color;
	unsigned short int money;
	bool movestatus; /*1 if Player's move now*/
};