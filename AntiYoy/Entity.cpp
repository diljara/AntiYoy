#include <SFML/Graphics.hpp>
#include "Entity.h"

Entity::Entity(std::string name, float x, float y, bool stat, unsigned short int money) {
	tex.loadFromFile(name);
	tex.setSmooth(true);
	sprite.setTexture(tex);
	sprite.setScale(0.3, 0.3);
	sf::Vector2f delta;
	sprite.setPosition(coord);
	power = 0;
	alive_status = stat;
	money_cost = money;
}

void Entity::get_killed() {
	alive_status = 0;
}