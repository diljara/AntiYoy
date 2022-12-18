#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Entity.h"

Cell::Cell(int x, int y)
{
    /*sf::CircleShape hexagon(25, 6);*/

    map_coord[0] = x;
    map_coord[1] = y;
    /*hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::White);
    hexagon.setOrigin(25, 25);*/
    /*this->window = window;
    this->Player_status = 0;*/
    entity_pointer = nullptr;
    entity_status = false;
    player_status = 0;
    size = 20;
    startx = 100 + 3 * size * x / 2;
    starty = 100 + x % 2 * size * sqrt(3) / 2 + sqrt(3) * size * y;
    centr[0] = (int)startx + size;
    centr[1] = (int)starty + size / 2;

}
//
//Cell::Cell(sf::Vector2f coordinates, sf::RenderWindow* win, Entity* entity_ptr)
//{
//    sf::CircleShape hexagon(25, 6);
//    coord = coordinates;
//    hexagon.setOutlineColor(sf::Color::Black);
//    hexagon.setOutlineThickness(5);
//    hexagon.setFillColor(sf::Color::White);
//    hexagon.setOrigin(25, 25);
//    window = win;
//    Player_status = 0;
//    entity_pointer = entity_ptr;
//}

Cell::Cell() {}
//
//void Cell::render()
///*draws hexagon aka cell*/
//{
//    sf::CircleShape hexagon(25, 6);
//    hexagon.setOutlineColor(sf::Color::Black);
//    hexagon.setOutlineThickness(5);
//    hexagon.setFillColor(sf::Color::Green);
//    hexagon.setPosition(coord);
//    window->draw(hexagon);
//    window->draw(entity_pointer->sprite);
//
//}
//
//sf::Vector2f Cell::get_coord()
//{
//    return coord;
//}
//
//bool Cell::IsinCell(sf::Vector2i point)
///*
//doesn't work as needed, should add check for other 4 sides
//*/
//{
//    float x = point.x - coord.x;
//    float y = point.y - coord.y;
//    float distsq = x * x + y * y;
//    if (distsq > 25 * 25) return false;
//    if (4 * distsq <= 3 * 25 * 25) return true;
//    return false;
//
//}