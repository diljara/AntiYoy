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
	bool gamestatus;
	Player Player1;
	Player Player2;

	Player* players[2]; /*[Player1, Player2*/

	void createEnt(int x, int y, int map_num);
	Cell Map[20][20];
	Cell* Map_pointer[20][20];
	void processing();

	std::vector<Entity> ent;
	std::vector<Entity*> Entities; 
	std::vector<Cell *> entity_steps(Cell* StartCell);
	std::vector<std::vector<int>> adj_list;
	void fill_adj_list();
};