#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct Drum
    {
        int masca, node, dist;
        Drum(int a, int b, int c)
            :masca(a), node(b), dist(c)
        {}
    };

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int masca_vizitati = (1 << n) - 1;
        queue<Drum> q;
        //unordered_map<int, bool> vizitat[masca_vizitati + 1];
        bool vizitat[masca_vizitati + 1][n + 1];

        for(int i = 0; i < n; i++)
        {
            Drum t((1 << i), i, 0);
            q.push(t);
            vizitat[(1 << i)][i] = true;
        }

        while(!q.empty())
        {
            Drum t = q.front();
            q.pop();

            int node = t.node;
            int masca = t.masca;
            int dist = t.dist;
            if(masca == masca_vizitati)
                return t.dist;

            for(int i = 0; i < graph[node].size(); i++)
            {
                int next = graph[node][i];
                int next_masca = masca | (1 << next);
                if(!vizitat[next_masca][next])
                {
                    Drum t(next_masca, next, dist + 1);
                    q.push(t);
                    vizitat[next_masca][next] = true;
                }
            }
        }
        return -1;
    }
};




int main()
{
    Solution t;
    vector<vector<int>> graph = {{1},{0,2,4},{1,3,4},{2},{1,2}};
    cout << t.shortestPathLength(graph);




    return 0;
}
