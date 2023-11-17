#include<bits/stdc++.h>

using namespace std;

ifstream fin("camionas.in");
ofstream fout("camionas.out");

const int INF = INT_MAX;

class Compare
{
public:
    bool operator()(pair<int, int> drum1, pair<int, int> drum2){
        return drum1.second > drum2.second;
    }
};

int main()
{
    int n, m, g;
    fin >> n >> m >> g;
    vector<pair<int, int>> graf[n + 1];
    for(int i = 0; i < m; i++)
    {
        int x, y, gdrum;
        fin >> x >> y >> gdrum;
        if(g > gdrum){
            graf[x].push_back(make_pair(y, 1));
        }
        else{
            graf[x].push_back(make_pair(y, 0));
        }
    }


    int start = 1;
    int dist[n + 1];
    int parinte[n + 1];
    bool inQ[n + 1];
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;//1 daca exista, 2 daca trebuie sa creasca capacitatea

    dist[start] = 0;
    parinte[start] = 0;
    for(int i = 2; i <= n; i++)
    {
        inQ[i] = false;
        dist[i] = INF;
        parinte[i] = 0;
    }

    inQ[start] = true;
    heap.push(make_pair(start, dist[start]));

    while(!heap.empty())
    {
        pair<int, int> elem = heap.top();
        heap.pop();
        int u = elem.first;
        if(elem.second != dist[u])
            continue;
        for(int i = 0; i < graf[u].size(); i++)
        {
            int v = graf[u][i].first;
            int distXY = graf[u][i].second;
            int alt = dist[u] + distXY;
            if(alt < dist[v])
            {
                dist[v] = alt;
                parinte[v] = u;
                heap.push(make_pair(v, alt));
            }
        }
    }

    cout << dist[n];

    return 0;
}
