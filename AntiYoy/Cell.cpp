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

Cell::Cell() {}

sf::RenderWindow* Cell::get_window()
{
    return window;
}

void Cell::render()
/*рисует шестиугольник aka клетку*/
{
    sf::CircleShape hexagon(25, 6);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::Green);
    hexagon.setPosition(coord);

    sf::RenderWindow* win = this->get_window();
    win->draw(hexagon);

}

sf::Vector2f Cell::get_coord()
{
    return coord;
}

bool Cell::IsinCell(sf::Vector2i point)
/*проблема с типами кое-как решилась.
* сам метод не работает как надо
* нужно добавить проверку на остальные 4 стороны
*/
{
    float x = point.x - coord.x;
    float y = point.y - coord.y;
    float distsq = x * x + y * y;
    if (distsq > 25 * 25) return false;
    if (4 * distsq <= 3 * 25 * 25) return true;
    return false;

}