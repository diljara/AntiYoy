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
    centr[0] = startx + size + 5;
    centr[1] = starty + size * sqrt(3);
    color = sf::Color(255, 255, 255);

}
void Cell::draw_point(sf::RenderWindow* window) {
    sf::CircleShape point(10.f);

    point.setFillColor(sf::Color(0, 0, 0));
    sf::CircleShape* pont = &point;
    float centr_f[2] = {startx + size + 5, starty + size * sqrt(3)};
    point.setPosition(sf::Vector2f(centr_f[0], centr_f[1]));
    window->draw(point);
}

void Cell::draw(sf::RenderWindow* window, sf::ConvexShape* arr) {
    sf::ConvexShape* hex;
    hex = arr;
    hex->setPointCount(6);
    int a = size;
    float startx = 100 + 3 * a * map_coord[0] / 2;
    float starty = 100 + map_coord[0] % 2 * a * sqrt(3) / 2 + sqrt(3) * a * map_coord[1];
    hex->setPoint(0, sf::Vector2f(startx, starty));
    hex->setPoint(1, sf::Vector2f(startx + a / 2, starty - a * sqrt(3) / 2));
    hex->setPoint(2, sf::Vector2f(startx + a * 3 / 2, starty - a * sqrt(3) / 2));
    hex->setPoint(3, sf::Vector2f(startx + 2 * a, starty));
    hex->setPoint(4, sf::Vector2f(startx + a * 3 / 2, starty + a * sqrt(3) / 2));
    hex->setPoint(5, sf::Vector2f(startx + a / 2, starty + a * sqrt(3) / 2));
    hex->setFillColor(color);
    hex->setOutlineThickness(1.f);
    hex->setOutlineColor(sf::Color(100, 150, 50));
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