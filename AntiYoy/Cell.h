#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Cell
{
public:
	Cell();
	Cell(int x, int y, sf::RenderWindow* win, Entity* entity_ptr = nullptr);
	Cell(sf::Vector2f coordinates, sf::RenderWindow* win, Entity* entity_ptr = nullptr);//DON'T DELETE, CONSTRUCTOR FOR TESTS

	sf::Vector2f get_coord();
	bool IsinCell(sf::Vector2i mouse_pos);
	void render();
	
	Entity* entity_pointer;//may be use optional
	int map_coord[2];//coordinates for map
	unsigned short int Player_status; /*0, if there no player, Player_num if there is*/

private:
	sf::Vector2f coord;/*coordinates(in pixels) for drawing*/
	sf::RenderWindow* window;
};