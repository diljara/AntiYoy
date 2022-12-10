#pragma once
#include <SFML/Graphics.hpp>
class Button
{
private:
	sf::Texture tex;
	sf::Vector2f coord;
	sf::RenderWindow* window;
	sf::Font font;
public:
	sf::Sprite sprite;
	sf::Text text;
	Button();
	Button(std::string name, sf::Vector2f coord, sf::RenderWindow* win, std::string txt = "");
	void render();

};

