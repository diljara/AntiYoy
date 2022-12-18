#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity
{
private:
	unsigned short int money_cost;
public:
	Entity(int x, int y, bool stat = 1, unsigned short int money = 0);
	Entity();
	int map_coord[2];
	bool alive_status; /*if alive = 1, else 0*/
	~Entity();
};
