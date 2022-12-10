#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Entity.h"

Cell::Cell(int x, int y, sf::RenderWindow* window, Entity* entity_ptr)
{
    sf::CircleShape hexagon(25, 6);

    map_coord[0] = x;
    map_coord[1] = y;
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::White);
    hexagon.setOrigin(25, 25);
    coord = sf::Vector2f((y % 2 ? 75 : 50) + x * 50.f, 50 + y * 40.f);
    this->window = window;
    this->Player_status = 0;
    entity_pointer = entity_ptr;
}

Cell::Cell(sf::Vector2f coordinates, sf::RenderWindow* win, Entity* entity_ptr)
{
    sf::CircleShape hexagon(25, 6);
    coord = coordinates;
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::White);
    hexagon.setOrigin(25, 25);
    window = win;
    Player_status = 0;
    entity_pointer = entity_ptr;
}

Cell::Cell() {}

void Cell::render()
/*draws hexagon aka cell*/
{
    sf::CircleShape hexagon(25, 6);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::Green);
    hexagon.setPosition(coord);
    window->draw(hexagon);
    window->draw(entity_pointer->sprite);

}

sf::Vector2f Cell::get_coord()
{
    return coord;
}

bool Cell::IsinCell(sf::Vector2i point)
/*
doesn't work as needed, should add check for other 4 sides
*/
{
    float x = point.x - coord.x;
    float y = point.y - coord.y;
    float distsq = x * x + y * y;
    if (distsq > 25 * 25) return false;
    if (4 * distsq <= 3 * 25 * 25) return true;
    return false;

}