#include<bits/stdc++.h>

using namespace std;

ifstream fin("trilant.in");
ofstream fout("trilant.out");

const long long INF = LONG_LONG_MAX;
const int NMAX = 100005;
int n;

vector<pair<int, long long>> graf[NMAX];

class Compare
{
public:
    bool operator()(pair<int, long long> drum1, pair<int, long long> drum2){
        return drum1.second > drum2.second;
    }
};

void dijkstra(int* parinte, long long* dist, int start)
{
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, Compare> heap;

    for(int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        parinte[i] = 0;
    }
    dist[start] = 0;

    for(int i = 1; i <= n; i++)
        heap.push(make_pair(i, dist[i]));

    while(!heap.empty())
    {
        pair<int, long long> elem = heap.top();
        heap.pop();
        int u = elem.first;
        if(dist[u] != elem.second)
            continue;
        for(int i = 0; i < graf[u].size(); i++)
        {
            int v = graf[u][i].first;
            long long distXY = graf[u][i].second;
            long long alt = dist[u] + distXY;
            if(alt < dist[v])
            {
                dist[v] = alt;
                parinte[v] = u;
                heap.push(make_pair(v, alt));
            }
        }
    }
}

void print_lant(int nod, int* parinte)
{
    int cnt = 0;
    int aux = nod;

    while(parinte[nod] != 0)
    {
        cnt++;
        nod = parinte[nod];
    }
    cnt++;
    fout << cnt << " ";
    nod = aux;
    while(parinte[nod] != 0)
    {
        fout << nod << " ";
        nod = parinte[nod];
    }
    fout << nod << endl;
}


int main()
{
    int m, a, b, c;
    fin >> n >> m;
    fin >> a >> b >> c;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        long long w;
        fin >> x >> y >> w;
        graf[x].push_back(make_pair(y, w));
        graf[y].push_back(make_pair(x, w));
    }

    int start1 = a;
    int parinte1[n + 1];
    long long dist1[n + 1];
    dijkstra(parinte1, dist1, start1);
    int start2 = b;
    int parinte2[n + 1];
    long long dist2[n + 1];
    dijkstra(parinte2, dist2, start2);
    int start3 = c;
    int parinte3[n + 1];
    long long dist3[n + 1];
    dijkstra(parinte3, dist3, start3);

    long long cost_minim = INF;
    int nod = -1;
    for(int i = 1; i <= n; i++)
    {
        if(dist1[i] + dist2[i] + dist3[i] <= cost_minim)
        {
            cost_minim = dist1[i] + dist2[i] + dist3[i];
            nod = i;
        }
    }

    fout << cost_minim << endl;

    print_lant(nod, parinte1);
    print_lant(nod, parinte2);
    print_lant(nod, parinte3);

    return 0;
}
