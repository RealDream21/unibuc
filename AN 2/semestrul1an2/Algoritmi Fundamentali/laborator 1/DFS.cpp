#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

const int NMAX = 1e5;
vector<int> G[NMAX + 1];
int vis[NMAX + 1];

void DFS(int x)
{
    vis[x] = 1;
    for(int i = 0; i < G[x].size(); i++)
    {
        if(!vis[G[x][i]])
            DFS(G[x][i]);
    }
}

int main()
{
    int n, m;
    fin >> n >> m;
    int x, y;
    for(int i = 1; i <= m; i++)
    {
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int cc = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i])
        {
            cc++;
            DFS(i);
        }
    }
    fout << cc;

    return 0;
}
