#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity
{
private:
	unsigned short int money_cost;
public:
	Entity(int x, int y, int player_num);
	Entity();
	int map_coord[2];
	int player_status;
	bool move_status; /*if alive = 1, else 0*/
	~Entity();
};
