#pragma once
#include <SFML/Graphics.hpp>
class Button
{
private:
	sf::Texture tex;
	sf::Vector2f coord;
	sf::RenderWindow* window;
	sf::Font font;
	std::string file_name;
public:
	sf::Sprite sprite;
	sf::Text text;
	std::string basic_text;
	Button();
	Button(sf::Vector2f coord, sf::RenderWindow* win, std::string txt = "", std::string name = "");
	void render();

};

