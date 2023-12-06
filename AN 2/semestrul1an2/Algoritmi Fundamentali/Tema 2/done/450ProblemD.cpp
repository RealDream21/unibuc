#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5 + 5;

vector<pair<int, long long>> g[NMAX];
long long d[NMAX];
bool vis[NMAX];
int paths[NMAX];
vector<pair<int, long long>> trains;
set<pair<long long, int>> s;

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
    for(int i = 1; i <= k; i++) {
        int y;
        long long c;
        cin >> y >> c;
        trains.push_back({y, c});
        g[1].push_back({y, c});
    }
    for(int i = 1; i <= n; i++) {
        d[i] = 1e18;
    }
    d[1] = 0;
    s.insert(make_pair(d[1], 1));
    while(!s.empty()) {
        auto it = s.begin();
        int node = (*it).second;
        s.erase(it);
        
        if(vis[node])
            continue;
        vis[node] = 1;
        for(int i = 0; i < (int)g[node].size(); i++) {
            auto next = g[node][i];
            if(!vis[next.first]) {
                if(d[next.first] > d[node] + next.second)
                {
                    auto it = s.find({d[next.first], next.first});
                    if(it != s.end()) {
                        s.erase(it);
                    }
                    paths[next.first] = 1;
                    d[next.first] = next.second + d[node];
                    s.insert({d[next.first], next.first});
                } else {
                    if(d[next.first] == d[node] + next.second) {
                        paths[next.first]++;
                    }
                }
            }
        }
    }

    int sine_ramase = 0;
    for(auto it : trains) {
        if(d[it.first] == it.second) {
            if(paths[it.first] > 1) {
                paths[it.first]--;
            } else {
                sine_ramase++;
            }
        }
    }

    cout << k - sine_ramase;

    return 0;
}
