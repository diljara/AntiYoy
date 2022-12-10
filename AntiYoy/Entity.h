#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity
{
private:
	sf::Texture tex;
	sf::Vector2f coord;
	unsigned short int money_cost;
public:
	Entity(std::string name, float x, float y, bool stat = 1, unsigned short int money = 0);
	sf::Sprite sprite;
	unsigned short int power;
	bool alive_status; /*if alive = 1, else 0*/
	void get_killed();
};
