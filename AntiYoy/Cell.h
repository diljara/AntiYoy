#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Cell
{
public:
	Cell(int x, int y, sf::RenderWindow* window, Entity* entity_pointer = nullptr);
	Cell();
	sf::RenderWindow* get_window();
	void render();
	sf::Vector2f get_coord();
	bool IsinCell(sf::Vector2i mouse_pos);
	Entity* entity_pointer;//may be use optional
	int map_coord[2];
	unsigned short int Player_status; /*0, if there no player, Player_num if there is*/

private:
	sf::Vector2f coord;/*координаты*/
	sf::RenderWindow* window;
};