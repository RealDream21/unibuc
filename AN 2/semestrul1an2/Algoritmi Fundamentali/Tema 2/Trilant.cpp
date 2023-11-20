#include<bits/stdc++.h>

using namespace std;

ifstream fin("trilant.in");
ofstream fout("trilant.out");

const int INF = INT_MAX;
const int NMAX = 1005;
int n;

vector<pair<int, int>> graf[NMAX];
void print_lant(int a, int * parinte, int x)
{
    vector<int> order;
    int next = a;
    while(next != 0)
    {
        order.push_back(next);
        next = parinte[next];
    }
    fout << order.size() << " ";
    for(int i = order.size() - 1; i >= 0; i--)
        fout << order[i] << " ";
    fout << endl;
}

vector<int> findPath(int start, int target)
{
    bool vizitat[n + 1];
    int parinte[n + 1];
    parinte[start] = start;
    queue<int> q;
    int x = start;
    q.push(x);

    while(!q.empty())
    {
        x = q.front();
        q.pop();
        if(x == target)
            break;
        for(auto p: graf[x])
        {
            int next = p.first;
            if(!vizitat[next])
            {
                vizitat[next] = true;
                parinte[next] = x;
                q.push(next);
            }
        }
    }
    vector<int> sol;
    while(target != start)
    {
        sol.push_back(target);
        target = parinte[target];
    }
    return sol;
}


int gaseste_nod_comun(int a, int b, int c)
{
    //prima data a -> b si dupa a -> c => gasesc muchia comuna
    int fv[n + 1];
    for(int i = 0; i <= n; i++)
        fv[i] = 0;
    vector<int> t;
    t = findPath(a, b);
    for(int i = 0; i < t.size(); i++)
        fv[t[i]]++;
    t = findPath(b, c);
    for(int i = 0; i < t.size(); i++)
        fv[t[i]]++;
    t = findPath(a, c);
    for(int i = 0; i < t.size(); i++)
        fv[t[i]]++;

    int comun = -1;
    for(int i = 0; i <= n; i++){
        if(fv[i] == 3){
            comun = i;
            break;
        }
    }
    return comun;
}


class Compare
{
public:
    bool operator()(pair<int, int> drum1, pair<int, int> drum2){
        return drum1.second > drum2.second;
    }
};

int main()
{
    int m, a, b, c;
    fin >> n >> m;
    fin >> a >> b >> c;
    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        fin >> x >> y >> w;
        graf[x].push_back(make_pair(y, w));
        graf[y].push_back(make_pair(x, w));
    }

    int x = gaseste_nod_comun(a, b, c);

    int start = x;
    int dist[n + 1];
    int parinte[n + 1];
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;

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
        pair<int, int> elem = heap.top();
        heap.pop();
        int u = elem.first;
        if(dist[u] != elem.second)
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

    fout << dist[a] + dist[b] + dist[c] << endl;
    print_lant(a, parinte, x);
    print_lant(b, parinte, x);
    print_lant(c, parinte, x);

    return 0;
}
