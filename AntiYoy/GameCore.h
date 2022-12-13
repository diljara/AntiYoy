#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Cell.h"
#include "Entity.h"

class GameCore {

	

public:
	void update(int elapsed);/*elapsed �����, ����� �������� ���� �������,
	� �� �������.������ ��������, ��� �� �����������*/
	void draw();
	GameCore();
	void start();
	/*~GameCore();*/
	sf::RenderWindow* window;/*��������� �� ����*/

};
