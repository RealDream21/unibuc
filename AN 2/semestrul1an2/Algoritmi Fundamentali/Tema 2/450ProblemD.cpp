#include<bits/stdc++.h>

using namespace std;

//ifstream fin("date.in");

const int INF = INT_MAX;

class Compare
{
public:
    bool operator()(pair<int, int> drum1, pair<int, int> drum2)
    {
        return drum1.second < drum2.second;
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int train_route[n + 1];
    vector<pair<int, int>> graf[n + 1];
    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graf[x].push_back(make_pair(y, w));
        graf[y].push_back(make_pair(x, w));
    }
    for(int i = 0; i < k; i++)
    {
        int y, w;
        cin >>y >> w;
        graf[1].push_back(make_pair(y, w));
        train_route[y] = w;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;

    int dist[n + 1];
    int start = 1;
    dist[start] = 0;
    heap.push(make_pair(start, dist[start]));
    for(int i = 2; i <= n; i++)
        dist[i] = INF;


    while(!heap.empty())
    {
        pair<int, int> elem = heap.top();
        heap.pop();
        int u = elem.first;
        if(dist[u] != elem.second)
            continue;
        for(int i = 0; i < graf[u].size(); i++)
        {
            int v = graf[u][i].first;
            int alt = dist[u] + graf[u][i].second;
            if(alt < dist[v])
            {
                dist[v] = alt;
                heap.push(make_pair(v, dist[v]));
            }
        }
    }

    int sine_scoase = 0;
    for(int i = 0; i < graf[1].size() - k; i++)
    {
        int v = graf[1][i].first;
        if(train_route[v] != 0)
        {
            if(dist[v] < train_route[v])
                sine_scoase++;
        }
    }
    cout << sine_scoase;


    return 0;
}
