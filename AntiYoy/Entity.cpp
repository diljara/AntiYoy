#include <SFML/Graphics.hpp>
#include "Entity.h"

Entity::Entity(std::string name, int x, int y, bool stat, unsigned short int money) {
	tex.loadFromFile(name);
	tex.setSmooth(true);
	sprite.setTexture(tex);
	sprite.setScale(0.3, 0.3);
	map_coord[0] = x;
	map_coord[1] = y;
	coord = sf::Vector2f((y % 2 ? 75 : 50) + x * 50.f, 50 + y * 40.f);
	sprite.setPosition(coord);
	power = 0;
	alive_status = stat;
	money_cost = money;
}

Entity::Entity()
{
}

Entity::Entity(std::string name, sf::Vector2f coordinates, bool stat, unsigned short int money)
{
	tex.loadFromFile(name);
	tex.setSmooth(true);

	sprite.setTexture(tex);
	sprite.setScale(0.3, 0.3);

	coord = coordinates;
	sf::Vector2f delta(0.f, -10.f);
	sprite.setPosition(coord + delta);
	power = 0;
	alive_status = stat;
	money_cost = money;
}

void Entity::get_killed() {
	alive_status = 0;
}