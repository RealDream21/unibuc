#include <bits/stdc++.h>

using namespace std;


ifstream fin("senat.in");
ofstream fout("senat.out");

const int nmax = 205;

int capacitate[nmax][nmax];
//unordered_map<int, int> capacitate[nmax];
int tati[nmax];
bool pastrat[nmax];

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
            //int flow = capacitate[next][node];
            if(capacitate[node][next] == 1 && !pastrat[next])
            {
                //cout << node << " " << next << endl;
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
    fin.get();
    int s = 0, t = n + m + 1;

    for(int i = 1; i <= n; i++)
    {
        graf[0].push_back(i);
        graf[i].push_back(0);
        capacitate[0][i] = 1;
    }
    for(int i = n + 1; i <= n + m; i++)
    {
        string linie;
        getline(fin, linie);
        istringstream numere_stream(linie);
        //fin.get();
        int nr;
        while(numere_stream >> nr)
        {
            graf[nr].push_back(i);
            graf[i].push_back(nr);
            capacitate[nr][i] = 1;
        }
        //-cout << endl;
    }

    for(int i = n + 1; i <= n + m; i++)
    {
        graf[i].push_back(t);
        graf[t].push_back(i);
        capacitate[i][t] = 1;
    }

    int total_flow = 0;
    do
    {
        bfs(s, t);
        if(tati[t] == -1)
            break;
        augment(total_flow, s, t);
    }while(tati[t] != -1);

    //cout << total_flow;

    if(total_flow != m)
    {
        fout << "0";
        return 0;
    }

    taietura();

    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < graf[i].size(); j++)
            cout << i << " " << graf[i][j] << " " << capacitate[i][graf[i][j]] << "-" << capacitate[graf[i][j]][i] << endl;
    }*/


    /*for(int i = 1; i <= n; i++)
    {
        if(!pastrat[i])
            cout << i << endl;
    }*/

    for(int i = n + 1; i <= n + m; i++)
    {
        for(int j = 0; j < graf[i].size(); j++)
        {
            int u = graf[i][j];
            if(u != t && capacitate[i][u] == 1)
                fout << u << endl;


        }


    }

    return 0;
}
