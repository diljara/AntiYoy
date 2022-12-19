#include "Button.h"
#include <SFML/Graphics.hpp>

Button::Button()
{
}

Button::Button(sf::Vector2f coord, sf::RenderWindow* win, std::string txt, std::string nm)
{
	if (file_name != "") {
		file_name = nm;
		tex.loadFromFile(file_name);
		tex.setSmooth(true);
		sprite.setTexture(tex);
		sprite.setScale(0.3, 0.3);
		sprite.setPosition(coord);
	}
	window = win;
	font.loadFromFile("font.ttf");
	text.setString(txt);
	text.setCharacterSize(35);
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(coord);
	
}

void Button::render() 
{
	if (file_name != "") window->draw(sprite);
	// set the text style
	
	window->draw(text);
	
}

void Button::change_txt(std::string txt)
{
	text.setString(txt);
}
