#include "Button.h"
#include <SFML/Graphics.hpp>

Button::Button()
{
}

Button::Button(std::string name, sf::Vector2f coord, sf::RenderWindow* win, std::string txt)
{
	tex.loadFromFile(name);
	tex.setSmooth(true);
	sprite.setTexture(tex);
	sprite.setScale(0.3, 0.3);
	sprite.setPosition(coord);
	window = win;
	font.loadFromFile("font.ttf");
	text.setString(txt);
	text.setCharacterSize(50);
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(coord);
	
}

void Button::render() 
{
	window->draw(sprite);
	// set the text style
	
	window->draw(text);
	
}
