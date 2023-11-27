#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");

const int NMAX = 3 * 1e5;

vector<pair<long long, int>> g[NMAX];
long long d[NMAX];
bool inq[NMAX];
bool vis[NMAX];
bool train_to[NMAX];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        long long x;
        cin >> u >> v >> x;
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }
    for(int i = 1; i <= k; i++)
    {
        int y;
        long long c;
        cin >> y >> c;
        g[1].push_back({y, c});
    }

    for(int i = 1; i <= n; i++)
        d[i] = LONG_LONG_MAX;

    set<pair<long long, int>> s;
    d[1] = 0;
    s.insert(make_pair(d[1], 1));

    while(!s.empty())
    {
        auto it = s.begin();
        s.erase(it);
        int node = (*it).second;
        if(vis[node])
            continue;
        vis[node] = 1;
        for(int i = 0; i < g[node].size(); i++)
        {
            auto next = g[node][i];
            if(!vis[next.first] && d[next.first] > d[node] + next.second)
            {
                if(node == 1 && i >= g[node].size() - k) // e sina de tren
                {
                        train_to[next.first] = true;
                }
                else
                    train_to[next.first] = false;
                d[next.first] = next.second + d[node];
                s.insert({d[next.first], next.first});
            }
        }
    }

    int sine_ramase = 0;

    for(int i = 2; i <= n; i++)
    {
        sine_ramase += train_to[i];
    }

    cout << k - sine_ramase;

    return 0;
}
