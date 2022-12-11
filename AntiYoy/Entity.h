#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity
{
private:
	sf::Texture tex;
	sf::Vector2f coord;//float->coordinates in pixels for drawing
	unsigned short int money_cost;
public:
	Entity(std::string name, int x, int y, bool stat = 1, unsigned short int money = 0);
	Entity();
	Entity(std::string name, sf::Vector2f coordinates, bool stat = 1, unsigned short int money = 0);//DON'T DELETE, CONSTRUCTOR FOR TESTS
	int map_coord[2];//coordinates for map
	sf::Sprite sprite;
	unsigned short int power;
	bool alive_status; /*if alive = 1, else 0*/
	void get_killed();
	//in order to draw use win->draw(sprite);
	~Entity();
};
