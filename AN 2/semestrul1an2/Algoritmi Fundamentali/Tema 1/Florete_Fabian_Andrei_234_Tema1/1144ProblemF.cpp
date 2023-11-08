#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

ifstream fin("1144.in");
const int nmax = 1e7;

vector<int> G[nmax + 1];
vector<pair<int, int>> history;

bool coloreaza(int x, int* color)
{
    queue<int> nodeq;
    nodeq.push(x);
    color[x] = 1;
    while(!nodeq.empty())
    {
        int nod = nodeq.front();
        nodeq.pop();
        for(auto p: G[nod])
        {
            if(!color[p])
            {
                color[p] = 3 - color[nod];
                nodeq.push(p);
            }
            else if(color[p] == color[nod])
                return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int color[n + 2];
    for(int i = 1; i <= n; i++)
        color[i] = 0;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        history.push_back(make_pair(x, y));
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!color[i])
        {
            if(!coloreaza(i, color))
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < history.size(); i++)
    {
        int from = history[i].first;
        int to = history[i].second;
        if(color[from] == 1)
            cout << "1";
        else
            cout << "0";
    }
    return 0;
}
