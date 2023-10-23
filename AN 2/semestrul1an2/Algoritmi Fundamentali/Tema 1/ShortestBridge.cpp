#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

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

    int searchBridge(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid.size())
            return (grid.size() + 1);
        queue<int> q;
        map<pair<int, int>, int> nivel;
        q.push(i);
        q.push(j);
        map<pair<int, int>, bool> seen;
        nivel[pair<int, int>(i, j)] = 0;
        while(!q.empty())
        {
            int newi = q.front();
            q.pop();
            int newj = q.front();
            q.pop();
            pair<int, int> t1(newi, newj);
            if(!(newi < 0 || newi >= grid.size() || newj < 0 || newj >= grid.size() || seen[t1]))
            {
                seen[t1] = true;
                if(grid[newi][newj] == 1)
                    return nivel[pair<int, int>(newi, newj)] - 1;

                q.push(newi - 1);
                q.push(newj);
                if(!(newi - 1 < 0 || newi - 1 >= grid.size() || newj < 0 || newj >= grid.size()) && grid[newi - 1][newj] == 2)
                    nivel[pair<int, int>(newi - 1, newj)] = 0;//nivel[pair<int, int>(newi, newj)];
                else
                    nivel[pair<int, int>(newi - 1, newj)] = nivel[pair<int, int>(newi, newj)] + 1;

                q.push(newi + 1);
                q.push(newj);
                if(!(newi + 1 < 0 || newi + 1 >= grid.size() || newj < 0 || newj >= grid.size()) && grid[newi + 1][newj] == 2)
                    nivel[pair<int, int>(newi + 1, newj)] = 0;//nivel[pair<int, int>(newi, newj)];
                else
                    nivel[pair<int, int>(newi + 1, newj)] = nivel[pair<int, int>(newi, newj)] + 1;

                q.push(newi);
                q.push(newj - 1);
                if(!(newi < 0 || newi >= grid.size() || newj - 1 < 0 || newj - 1 >= grid.size()) && grid[newi][newj - 1] == 2)
                    nivel[pair<int, int>(newi, newj - 1)] = 0;//nivel[pair<int, int>(newi, newj)];
                else
                    nivel[pair<int, int>(newi, newj - 1)] = nivel[pair<int, int>(newi, newj)] + 1;

                q.push(newi);
                q.push(newj + 1);
                if(!(newi < 0 || newi >= grid.size() || newj + 1 < 0 || newj + 1 >= grid.size()) && grid[newi][newj + 1] == 2)
                    nivel[pair<int, int>(newi, newj + 1)] = 0;//nivel[pair<int, int>(newi, newj)];
                else
                    nivel[pair<int, int>(newi, newj + 1)] = nivel[pair<int, int>(newi, newj)] + 1;
            }
        }
        return -1;
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        bool mapped = false;
        int starti, startj;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] != 0)
                {
                    mapIsland(i, j, grid);
                    mapped = true;
                    starti = i;
                    startj = j;
                    break;
                }
            if(mapped == true)
                break;
        }
        int min_bridge = grid.size();
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 2)
                    min_bridge = min(min_bridge, searchBridge(i, j, grid));
            }
        }

        return min_bridge;
    }
};

int main()
{
    Solution p;
    vector<vector<int>> grid = {{0,1,0,0,0},{0,1,0,1,1},{0,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0}};
    cout << p.shortestBridge(grid);

    return 0;
}
