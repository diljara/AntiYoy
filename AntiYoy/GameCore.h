#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Cell.h"
#include "Entity.h"

class GameCore {

	

public:
	void update(int elapsed);/*elapsed нужен, чтобы движение было плавным,
	а не рывками.вполне возможно, что не понадобится*/
	void draw();
	GameCore();
	void start();
	/*~GameCore();*/
	sf::RenderWindow* window;/*указатель на окно*/

};
