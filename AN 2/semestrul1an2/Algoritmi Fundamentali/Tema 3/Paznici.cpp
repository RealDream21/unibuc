#include <bits/stdc++.h>

using namespace std;

ifstream fin("paznici.in");
ofstream fout("paznici.out");

const int nmax = 60;

//int capacitate[nmax][nmax];
unordered_map<int, int> capacitate[nmax];
int tati[nmax];
vector<int> graf[nmax];

void bfs(int s, int t)
{
    for(int i = 0; i <= t; i++)
        tati[i] = -1;
    int node = s;
    queue<int> q;
    q.push(node);
    tati[t] = -1;
    tati[node] = node;
    while(!q.empty() && tati[t] == -1)
    {
        node = q.front();
        q.pop();
        for(int i = 0; i < graf[node].size(); i++)
        {
            int v = graf[node][i];
            if(tati[v] == -1 && capacitate[node][v] > 0)
            {
                tati[v] = node;
                q.push(v);
            }
        }
    }
}

void augment(int& total_flow, int s, int t)
{
    if (tati[t] != -1)
    {
        int maxflow = INT_MAX;
        int aux = t;

        while (aux != tati[aux])
        {
            int u = tati[aux];
            maxflow = min(maxflow, capacitate[u][aux]);
            capacitate[u][aux] -= maxflow;
            capacitate[aux][u] += maxflow;
            aux = u;
        }

        total_flow += maxflow;
    }
}


int main()
{

    int n, m;
    fin >> n >> m;
    int s = 0;
    int t = n + m + 1;


    string input;
    fin.get();
    for(int i = 1; i <= n; i++)
    {
        fin >> input;
        fin.get();
        cout << input;
    }

    int total_flow = 0;

    cout << "DA";
    do{
        bfs(s, t);
        if(tati[t] == -1)
            break;
        augment(total_flow, s, t);
    }while(tati[t] != -1);

    fout << total_flow;

    return 0;
}
