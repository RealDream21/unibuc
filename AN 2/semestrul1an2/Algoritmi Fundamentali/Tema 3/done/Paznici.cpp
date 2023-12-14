#include <bits/stdc++.h>

using namespace std;

ifstream fin("paznici.in");
ofstream fout("paznici.out");

const int nmax = 60;

//int capacitate[nmax][nmax];
unordered_map<int, int> capacitate[nmax];
int tati[nmax];
vector<int> graf[nmax];
bool pastrat[nmax];

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
    int st = 0, dr = 0;
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


void taietura()
{
    int node = 0;
    queue<int>q;
    pastrat[node] = true;
    q.push(node);

    while(!q.empty())
    {
        node = q.front();
        q.pop();
        for(int i = 0; i < graf[node].size(); i++)
        {
            int next = graf[node][i];
            //int flow = 1 - capacitate[next][node];
            if(capacitate[node][next] == 1 && !pastrat[next])
            {
                pastrat[next] = true;
                q.push(next);
            }
        }
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
        string input;
        fin >> input;
        graf[0].push_back(i);
        graf[i].push_back(0);
        capacitate[0][i] = 1;
        for(int j = 0; j < input.size(); j++)
        {
            if(input[j] == '1')
            {
                capacitate[i][n + j + 1] = 1;
                graf[i].push_back(n + j + 1);
                graf[n + j + 1].push_back(i);
            }
        }
    }
    for(int i = n + 1; i <= t; i++)
    {
        graf[i].push_back(t);
        graf[t].push_back(i);
        capacitate[i][t] = 1;
    }

    int total_flow = 0;
    do{
        bfs(s, t);
        if(tati[t] == -1)
            break;
        augment(total_flow, s, t);
    }while(tati[t] != -1);

    //cout << total_flow << endl;
    taietura();
    for(int i = 1; i <= n; i++)
    {
        if(!pastrat[i])
            fout << char('A' + i - 1);
    }
    for(int j = n + 1; j < t; j++)
    {
        if(pastrat[j])
            fout << char('a' + j - n - 1);
    }


    return 0;
}
