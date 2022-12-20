#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Cell
{
public:
	Cell();
	Cell(int x, int y);

	sf::Vector2f get_coord();
	
	Entity* entity_pointer;//may be use optional
	bool entity_status;
	int map_coord[2];//coordinates for map
	int centr[2];
	int size;
	sf::Color color;
	float startx;
	void draw(sf::RenderWindow* window);
	float starty;
	unsigned short int player_status; /*0, if there no player, Player_num if there is*/
	void draw_point(sf::RenderWindow* window);
private:

};