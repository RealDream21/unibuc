#include <iostream>
#include <vector>
#include <unordered_map>
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

    int searchBridge(int startAs, int i, int j, map<pair<int, int>, bool>& seen, vector<vector<int>>& grid){
        pair<int, int> t(i, j);
        if(seen[t])
            return (grid.size() + 1);
        seen[t] = true;
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid.size())
            return (grid.size() + 1);
        if(grid[i][j] != 0 && grid[i][j] != startAs)
            return 0;

        seen[t] = true;
        int sus = searchBridge(startAs, i - 1, j, seen, grid);
        int jos = searchBridge(startAs, i + 1, j, seen, grid);
        int stanga = searchBridge(startAs, i, j - 1, seen, grid);
        int dreapta = searchBridge(startAs, i, j + 1, seen, grid);
        seen[t] = false;
        if(grid[i][j] == startAs)
            return 0 + min(min(min(sus, jos), stanga), dreapta);
        else
            return 1 + min(min(min(sus, jos), stanga), dreapta);
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        bool mapped = false;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] != 0)
                {
                    mapIsland(i, j, grid);
                    mapped = true;
                    break;
                }
            if(mapped == true)
                break;
        }

        map<pair<int, int>, bool> seen;
        //unordered_map<int, unordered_map<int,bool>> seen;
        int min_bridge = grid.size() + 1;
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 2)
                {
                    seen.clear();
                    min_bridge = min(min_bridge, searchBridge(grid[i][j], i, j, seen, grid));
                }
            }
        }
        return min_bridge;
    }
};

int main()
{
    Solution p;
    vector<vector<int>> grid = {{0,1,0,0,0,0},{0,1,1,1,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{1,1,0,0,0,0}};
    cout << p.shortestBridge(grid);

    return 0;
}
