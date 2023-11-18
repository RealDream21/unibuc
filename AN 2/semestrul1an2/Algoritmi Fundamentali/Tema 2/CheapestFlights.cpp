#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = INT_MAX;
        int dist[n + 1];
        for(int i = 0; i < n; i++)
            dist[i] = INF;

        dist[src] = 0;

        for(int i = 0; i <= k; i++)
        {
            int aux_dist[n + 1];
            for(int i = 0; i < n; i++)
                aux_dist[i] = dist[i];

            for(int t = 0; t < flights.size(); t++)
            {
                int u = flights[t][0];
                int v = flights[t][1];
                if(dist[u] == INF)
                    continue;
                int cost = flights[t][2];
                int alt = dist[u] + cost;
                if(alt < dist[v])
                    aux_dist[v] = alt;
            }

            for(int i = 0; i < n; i++)
                dist[i] = aux_dist[i];
        }
        if(dist[dst] != INF)
            return dist[dst];
        return -1;
    }
};
int main()
{
    int n = 4, src = 0, dst = 3, k = 1;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    Solution s;
    cout << s.findCheapestPrice(n, flights, src, dst, k);


    return 0;
}
