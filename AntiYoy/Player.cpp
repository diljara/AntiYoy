#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Cell.h"
#include <vector>

Player::Player(sf::Color col) {
	money = 20;
	movestatus = true;
	color = col;
}

Player::Player(){}