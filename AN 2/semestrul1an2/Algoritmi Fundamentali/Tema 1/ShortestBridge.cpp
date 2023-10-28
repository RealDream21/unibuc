#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>
using namespace std;


//PENTRU OPTIMIZARE DE INCEPUT DINTR O COADA CU TOATE NODURILE SAU DOAR DIN MARGINI SI NU TREC DE 2 ORI PESTE ACELASI

class Solution {
    void mapIsland(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid.size())
            return;
        if(grid[i][j] == 2 || grid[i][j] == 0)
            return;
        if(grid[i][j] == 1)
            grid[i][j] = 2;
        mapIsland(i + 1, j, grid);
        mapIsland(i, j + 1, grid);
        mapIsland(i - 1, j, grid);
        mapIsland(i, j - 1, grid);
    }

    int min_dist_between_islands(queue<pair<int, int>> & nodeq, vector<vector<int>> & grid)
    {
        int n = grid.size();
        int dist[n][n];
        memset(dist, 0, n*n*sizeof(int));

        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};// => sus stanga jos dreapta

        while(!nodeq.empty())
        {
            pair<int, int> node = nodeq.front();
            nodeq.pop();
            int i = node.first;
            int j = node.second;

            if(grid[i][j] == 1)
                return dist[i][j] - 2;
            else if(grid[i][j] == 2)
                dist[i][j] = 1;

            for(int k = 0; k < 4; k++)
            {
                int newi = i + dx[k];
                int newj = j + dy[k];
                if(newi >= 0 && newi < n && newj >= 0 && newj < n && dist[newi][newj] == 0)
                {
                    if(grid[newi][newj] == 2)
                        dist[newi][newj] = 1;
                    else
                        dist[newi][newj] = dist[i][j] + 1;
                    nodeq.push(make_pair(newi, newj));
                }
            }
        }
        return -1;
    }


public:
    int shortestBridge(vector<vector<int>>& grid) {
        bool mapped = false;
        for(int i = 0; i < grid.size() && !mapped; i++)
        {
            for(int j = 0; j < grid[i].size() && !mapped; j++)
                if(grid[i][j] == 1)
                {
                    mapIsland(i, j ,grid);
                    mapped = true;
                }
        }

        queue<pair<int, int>> nodeq;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 2)
                {
                    if(i == 0 || j == 0 || i == grid.size() - 1 || j == grid.size() - 1)
                        nodeq.push(make_pair(i, j));
                    else if(grid[i - 1][j] == 0 || grid[i + 1][j] == 0 || grid[i][j - 1] == 0 || grid[i][j + 1] == 0)
                        nodeq.push(make_pair(i, j));
                }
            }
        }

        return min_dist_between_islands(nodeq, grid);
    }
};

int main()
{
    Solution p;
    vector<vector<int>> grid = {{0, 1}, {1, 0}};
    cout << p.shortestBridge(grid);

    return 0;
}
