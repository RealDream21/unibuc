#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

const int NMAX = 1e5;
vector<int> G[NMAX + 1];
int d[NMAX + 1];
int vis[NMAX + 1];

void BFS(int x){
    queue<int> q;
    q.push(x);
    d[x] = 0;
    vis[x] = 1;
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(auto next : G[x])
        {
            if(!vis[next])
            {
                q.push(next);
                vis[next] = 1;
                d[next] = d[x] + 1;
            }
        }
    }
    return;
}

int main()
{
    int n, m, S;
    fin >> n >> m >> S;
    int x, y;
    for(int i = 1; i <= m; i++)
    {
        fin >> x >> y;
        G[x].push_back(y);
    }
    BFS(S);
    for(int i = 1; i <= n; i++){
        if(i != S && d[i] == 0)
            fout << "-1 ";
        else
            fout << d[i] << " ";
    }

    return 0;
}
