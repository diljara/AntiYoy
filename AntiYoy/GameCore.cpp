#include <iostream>

#include "GameCore.h"
#include "Player.h"
#include "Cell.h"
#include "Entity.h"
#include "Button.h"


void GameCore::update(int elapsed) //event handler
{
    sf::Event event;
    bool drag = false;
    window->setFramerateLimit(60);
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                window->close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition() - window->getPosition();
                std::cout << '1';


            }
        }

    }
}

void GameCore::draw()
/*what needs to be drawn should be asked to render here*/
{
    window->clear();
    /*sf::Vector2f coord;
    coord.x = 500;
    coord.y = 500;*/
    //Button button = Button("coin.png", coord, window, "wubba lubba dub dub");
    //button.render();
    /*Entity ent("wild.png", coord);
    Cell cell(coord, window, &ent);
    cell.render();*/

    

    window->display();
}

void GameCore::start()
{
    sf::Clock clc;
    while (window->isOpen()) {
        int elapsed = clc.restart().asMilliseconds();
        update(elapsed);
        draw();
    }

}

GameCore::GameCore()

{
    window = new sf::RenderWindow({ 1100, 900 }, "Antiyoy", sf::Style::None);
}

//GameCore::~GameCore()
//{
//    delete window;
//}