#pragma once
#include <vector>
#include "GameCore.h"
#include "Player.h"
#include "Cell.h"
#include "Entity.h"




class MainCore {

private:

public:
	MainCore();
	GameCore GraphicsCore;
	bool gamestatus;
	Player Player1;
	Player Player2;
	Player* players; /*[Player1, Player2*/
	Cell Map[20][20];
	std::vector<Entity*> Entities;
	std::vector<Cell *> entity_steps(Cell *StartCell);
	std::vector<std::vector<int>> adj_list;
	void fill_adj_list();
};