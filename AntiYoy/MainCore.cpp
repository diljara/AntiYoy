#include "MainCore.h"
#include "Player.h"
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
    std::vector<int> d(400), p(400);
    used[s] = true;
    p[s] = -1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (unsigned int i = 0; i < adj_list[v].size(); ++i)
        {
            int to = adj_list[v][i];
            if (!used[to] &&
                (Map[to / 20][to % 20].Player_status == Map[s / 20][s % 20].Player_status ||
                 Map[to / 20][to % 20].Player_status == 0))
            {
                if (Map[v / 20][v % 20].Player_status)
                {
                    used[to] = true;
                    q.push(to);
                    d[to] = d[v] + 1;
                    p[to] = v;
                }
                else
                {
                    used[to] = true;
                    q.push(to);
                    d[to] = d[v] + 100;
                    p[to] = v;
                }
            }
        }
    }

    std::vector<Cell *> can_go;
    for (unsigned int to = 0; to < 400; to++)
    {
        if (d[to] <= 3 && to != s) can_go.push_back(Map[to / 20][to % 20]);
        // std::vector<int> path;
        // for (int v = to; v != -1; v = p[v])
        //     path.push_back(v);
        // std::reverse(path.begin(), path.end());
        // if (path.size() - 1 < 3)
        //     can_go.push_back(to);
    }
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
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
            }
            if (i == 0 && (j > 0 && j < 19))
            {
                adj_list[i * 20 + j].push_back(j - 1);
                adj_list[i * 20 + j].push_back(j + 1);
                adj_list[i * 20 + j].push_back(20 + j);
                adj_list[i * 20 + j].push_back(20 + j - 1);
            }
            if (i == 19 && (j > 0 && j < 19))
            {
                adj_list[i * 20 + j].push_back(i * 20 + j - 1);
                adj_list[i * 20 + j].push_back(i * 20 + j + 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
            }
            if ((i > 0 && i < 19) && (j > 0 && j < 19))
            {
                adj_list[i * 20 + j].push_back(i * 20 + j - 1);
                adj_list[i * 20 + j].push_back(i * 20 + j + 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
                adj_list[i * 20 + j].push_back((i + 1) * 20 + j);
                if (i % 2 == 0)
                {
                    adj_list[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                    adj_list[i * 20 + j].push_back((i + 1) * 20 + j - 1);
                }
                else
                {
                    adj_list[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                    adj_list[i * 20 + j].push_back((i + 1) * 20 + j + 1);
                }
            }
            if ((i > 0 && i < 19) && j == 0)
            {
                adj_list[i * 20 + j].push_back(i * 20 + j + 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
                adj_list[i * 20 + j].push_back((i + 1) * 20 + j);
                if (i % 2 == 1)
                {
                    adj_list[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                    adj_list[i * 20 + j].push_back((i + 1) * 20 + j + 1);
                }
            }
            if ((i > 0 && i < 19) && j == 19)
            {
                adj_list[i * 20 + j].push_back(i * 20 + j - 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
                adj_list[i * 20 + j].push_back((i + 1) * 20 + j);
                if (i % 2 == 0)
                {
                    adj_list[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                    adj_list[i * 20 + j].push_back((i + 1) * 20 + j - 1);
                }
            }
        }
    }
}

MainCore::MainCore()
{
    gamestatus = 1;
    GraphicsCore = GameCore();
    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 20; y++)
        {

            // Map[x][y] = Cell(x, y, GraphicsCore.window);
            // Map_pointer[x][y] = &Map[x][y];
            Map[x][y] = Cell(x, y, GraphicsCore.window);
        }
    }

    /*Player1 = Player(&Map[20][20]);
    Player2 = Player(&Map[0][0]);*/
}
