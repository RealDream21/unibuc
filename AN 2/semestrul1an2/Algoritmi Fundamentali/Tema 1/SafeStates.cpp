#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    bool isSafe(int node, unordered_map<int, bool>& visited, vector<vector<int>>& graph)
    {
        if(graph[node].empty())
            return true;
        if(visited[node])
            return false;
        visited[node] = true;
        for(auto next: graph[node])
        {
            if(!isSafe(next, visited, graph))
                return false;
        }
        graph[node].clear();
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> sol;
        unordered_map<int, bool> visited;
        for(int i = 0; i < graph.size(); i++)
        {
            if(isSafe(i, visited, graph))
                sol.push_back(i);
        }
        return sol;
    }
};

int main()
{
    Solution p;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> sol = p.eventualSafeNodes(graph);
    for(int i = 0; i < sol.size(); i++)
        cout << sol[i] << " ";
    return 0;
}
