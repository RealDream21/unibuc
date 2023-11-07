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
