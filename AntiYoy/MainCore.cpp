#include "Player.h"
#include "MainCore.h"
#include "Gamecore.h"
#include "Entity.h"
#include "Cell.h"
#include <vector>
#include <queue>
#include <algorithm>

std::vector<Cell *> MainCore::entity_steps(Cell* StartCell)
{
    int s = StartCell->map_coord[0] * 20 + StartCell->map_coord[1];

     std::queue<int> q;
     q.push(s);
     std::vector<bool> used(400);
     std::vector<int> d(400, 1000000), p(400);
     used[s] = true;
     d[s] = 0;
     p[s] = -1;
     while (!q.empty())
     {
         int v = q.front();
         q.pop();
         if (Map[v / 20][v % 20].player_status) 
         {
             for (unsigned int i = 0; i < adj_list[v].size(); ++i)
             {
                 int to = adj_list[v][i];
                 if (!used[to] &&
                     (Map[to / 20][to % 20].player_status == Map[s / 20][s % 20].player_status ||
                     Map[to / 20][to % 20].player_status == 0))
                 {
                     used[to] = true;
                     q.push(to);
                     d[to] = d[v] + 1;
                     p[to] = v;
                 }
             }
         }
     }

     std::vector<Cell *> can_go;
     for (unsigned int to = 0; to < 400; to++)
         if (d[to] <= 3 && to != s) 
             can_go.push_back(&Map[to / 20][to % 20]);
     return can_go;

    //std::vector<Cell *> can_go;
    //for (unsigned int to = 0; to < adj_list[s].size(); to++)
    //    can_go.push_back(&Map[adj_list[s][to] / 20][adj_list[s][to] % 20]);
    //return can_go;
}


void MainCore::fill_adj_list()
{
    adj_list.resize(400, std::vector<int>());

    for (unsigned int i = 0; i < 20; i++)
    {
        for (unsigned int j = 0; j < 20; j++)
        {
            if (i == 0 && j == 0)
            {
                adj_list[i * 20 + j].push_back(1);
                adj_list[i * 20 + j].push_back(20);
            }
            if (i == 19 && j == 0)
            {
                adj_list[i * 20 + j].push_back((i - 1) * 20);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + 1);
                adj_list[i * 20 + j].push_back(i * 20 + 1);
            }
            if (i == 0 && j == 19)
            {
                adj_list[i * 20 + j].push_back(18);
                adj_list[i * 20 + j].push_back(38);
                adj_list[i * 20 + j].push_back(39);
            }
            if (i == 19 && j == 19)
            {
                adj_list[i * 20 + j].push_back(i * 20 + j - 1);
                // adj_list[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
            }
            if (i == 0 && (j > 0 && j < 19))
            {
                adj_list[i * 20 + j].push_back(j - 1);
                adj_list[i * 20 + j].push_back(j + 1);
                adj_list[i * 20 + j].push_back(20 + j);
                if (j % 2)
                {
                    adj_list[i * 20 + j].push_back(20 + j - 1);
                    adj_list[i * 20 + j].push_back(20 + j + 1);
                }
            }
            if (i == 19 && (j > 0 && j < 19))
            {
                adj_list[i * 20 + j].push_back(i * 20 + j - 1);
                adj_list[i * 20 + j].push_back(i * 20 + j + 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
                if (j % 2)
                {
                    adj_list[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                    adj_list[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                }
            }
            if ((i > 0 && i < 19) && (j > 0 && j < 19))
            {
                adj_list[i * 20 + j].push_back(i * 20 + j - 1);
                adj_list[i * 20 + j].push_back(i * 20 + j + 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
                adj_list[i * 20 + j].push_back((i + 1) * 20 + j);
                if (i % 2)
                {
                    adj_list[i * 20 + j].push_back((i + 1) * 20 + j - 1);
                    adj_list[i * 20 + j].push_back((i + 1) * 20 + j + 1);
                }
                else
                {
                    adj_list[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                    adj_list[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                }
            }
            if ((i > 0 && i < 19) && j == 0)
            {
                adj_list[i * 20 + j].push_back(i * 20 + j + 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                adj_list[i * 20 + j].push_back((i + 1) * 20 + j);
                // if (i % 2 == 1)
                // {
                //     adj_list[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                //     adj_list[i * 20 + j].push_back((i + 1) * 20 + j + 1);
                // }
            }
            if ((i > 0 && i < 19) && j == 19)
            {
                adj_list[i * 20 + j].push_back(i * 20 + j - 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
                adj_list[i * 20 + j].push_back((i + 1) * 20 + j);
                adj_list[i * 20 + j].push_back((i + 1) * 20 + j - 1);

                // if (i % 2 == 0)
                // {
                //     adj_list[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                //     adj_list[i * 20 + j].push_back((i + 1) * 20 + j - 1);
                // }
            }
        }
    }
}
void MainCore::draw_way(Cell* StartCell, sf::RenderWindow* window){
    std::vector<Cell*> way_array = entity_steps(StartCell);
    for (int counter_way = 0; counter_way < way_array.size(); counter_way++) {
        way_array[counter_way]->draw_point(window);
    }
}

MainCore::MainCore()
{
    gamestatus = true;
    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 20; y++)
        {

            Map[x][y] = Cell(x, y);
            Map_pointer[x][y] = &Map[x][y];
        }
    }

    Player1 = Player(sf::Color(120, 0, 0));
    Player2 = Player(sf::Color(0, 0, 120));

    Map[0][0].player_status = 2;
    Map[0][0].color = Player2.color;
    Map[0][0].player_status = 2;
    Map[19][19].player_status = 1;
    Map[19][19].color = Player1.color;
    Map[19][19].player_status = 1;

    players[0] = &Player1;
    players[1] = &Player2;
}

void MainCore::createEnt(int x, int y, int player_num) {
    ent.push_back(Entity(x, y, player_num));
    Entities.push_back(&ent[ent.size() - 1]);
    Map[x][y].entity_status = 1;
    Map[x][y].entity_pointer = Entities[Entities.size() - 1];

}

int MainCore::get_x(sf::RenderWindow* window) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition() - window->getPosition();
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if ((mouse_pos.x - Map[i][j].centr[0]) * (mouse_pos.x - Map[i][j].centr[0]) + (mouse_pos.y - Map[i][j].centr[1]) * (mouse_pos.y - Map[i][j].centr[1]) <= 300) {
                return i;
            }
        }
    }

}

int MainCore::get_y(sf::RenderWindow* window) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition() - window->getPosition();
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if ((mouse_pos.x - Map[i][j].centr[0]) * (mouse_pos.x - Map[i][j].centr[0]) + (mouse_pos.y - Map[i][j].centr[1]) * (mouse_pos.y - Map[i][j].centr[1]) <= 300) {
                return j;
            }
        }
    }

}

void MainCore::processing() {
    Player1.movestatus = true;
    Player2.movestatus = true;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (Map[i][j].player_status == 1) {
                Player1.money += 1;
            }
            if (Map[i][j].player_status == 2) {
                Player2.money += 1;
            }
        }
    }
}

//void MainCore::processing() {
//    for (int i = 0; i < 2; i++) {
//        players[i]->money += players[i]->self_cells.size();
//        int debt = 0;
//        for (int j = 0; j < players[i]->self_entity_cells.size(); j++) {
//            debt = players[i]->self_entity_cells[j]->power;
//        }
//        if (debt > players[i]->money) {
//            for (int entity_count = 0; entity_count < players[i]->self_entity_cells.size(); entity_count++) {
//                delete players[i]->self_entity_cells[entity_count];
//            }
//        }
//        else {
//            players[i]->money = players[i]->money - debt;
//        }
//        
//    }
//    std::vector<Cell*> virtent;
//    for (int i = 0; i < players[0]->self_entity_cells.size() + players[1]->self_entity_cells.size(); i++) {
//
//    }
//}
