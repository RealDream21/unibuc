#include <bits/stdc++.h>

using namespace std;

ifstream fin("banuti.in");
ofstream fout("banuti.out");

const int INF = INT_MAX;
const int NMAX = 50005;

int cost[NMAX];
bool viz[NMAX];

int main()
{
    int t;
    vector<int> bancnote;
    fin >> t;
    int n = INT_MAX;
    for(int i = 0; i < t; i++)
    {
        int x;
        fin >> x;
        bancnote.push_back(x);
        if(n > x)
            n = x;
    }

    vector<int> muchii_aux(n);
    for(int i = 0; i < muchii_aux.size(); i++)
        muchii_aux[i] = INT_MAX;

    for(int i = 0; i < bancnote.size(); i++)
    {
        int cost = bancnote[i];
        if(muchii_aux[cost%n] > cost)
            muchii_aux[cost%n] = cost;
    }
    vector<int> muchii;
    for(int i = 0; i < muchii_aux.size(); i++)
    {
        if(muchii_aux[i] != INT_MAX)
            muchii.push_back(muchii_aux[i]);
    }


    //Incep Dijkstra
    set<pair<int, int>> heap;
    for(int i = 0; i < n; i++)
        cost[i] = INF;

    cost[0] = 0;
    heap.insert({cost[0], 0});
    while(!heap.empty())
    {
        auto it = heap.begin();
        heap.erase(it);
        int u = it->second;
        int costu = it->first;
        if(viz[u] == 1)
            continue;
        viz[u] = 1;
        for(int i = 0; i < muchii.size(); i++) // ma uit la muchiile din u spre v
        {
            int v = (u + muchii[i])%n;
            int costv = muchii[i];
            if(u != v)
            {
                if(!viz[v] && cost[v] > costv + costu)
                {
                    cost[v] = costu + costv;
                    heap.insert({cost[v], v});
                }
            }
        }
    }

    int maxc = 0;
    bool hasSol = true;
    for(int i = 0; i < n; i++)
    {
        if(maxc < cost[i])
            maxc = cost[i];
        if(cost[i] == INT_MAX)
            hasSol = false;
    }
    if(hasSol)
        fout << maxc - n;
    else
        fout << -1;

    return 0;
}
