#include <bits/stdc++.h>

using namespace std;

ifstream fin("ghizi.in");
ofstream fout("ghizi.out");

const int nmax = 5005;
const int TMAX = 100;

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
        //cout << node << ' ';
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
    //cout << '\n';
}

void augment(int& total_flow, int s, int t)
{
    if (tati[t] != -1)
    {
        int maxflow = INT_MAX;
        int aux = t;

        while (aux != tati[aux])
        {
            //cout << aux << ' ';
            int u = tati[aux];
            maxflow = min(maxflow, capacitate[u][aux]);
            //capacitate[u][aux] -= maxflow;
            //capacitate[aux][u] += maxflow;
            aux = u;
        }

        aux = t;

        while (aux != tati[aux])
        {
            //cout << aux << ' ';
            int u = tati[aux];
            maxflow = min(maxflow, capacitate[u][aux]);
            capacitate[u][aux] -= maxflow;
            capacitate[aux][u] += maxflow;
            aux = u;
        }
        //cout << aux << '\n';
        //cout << '\n';

        total_flow += maxflow;
    }
}

int main()
{
    int n, k;
    fin >> n >> k;
    vector<pair<int, int>> input;
    int max_interval = 0;

    for(int i = 1; i <= n; i++)
    {
        int x, y;
        fin >> x >> y;
        if(y > max_interval)
            max_interval = y;
        input.push_back({x, y});
        graf[x].push_back(y);
        graf[y].push_back(x);
        capacitate[x][y]++;
    }

    graf[TMAX].push_back(TMAX + 1);
    graf[TMAX + 1].push_back(TMAX);
    //cout << k << '\n';
    capacitate[TMAX][TMAX + 1] = k;

    int total_flow = 0;
    int s = 0;
    int t = TMAX + 1;
    do
    {
        bfs(s, t);
        if(tati[t] == -1)
            break;
        augment(total_flow, s, t);
        //cout << total_flow << '\n';
    }while(tati[t] != -1);

    int cnt = 0;
    vector<int> sol;
    for(int i = 0; i < input.size(); i++)
    {
        int x = input[i].first;
        int y = input[i].second;
        if(capacitate[y][x] > 0) {
            cnt++;
            sol.push_back(i + 1);
            capacitate[y][x]--;
        }
    }
    //fout << cnt << endl;
    fout << sol.size() << '\n';

    for(int i = 0; i < sol.size(); i++)
    {
        fout << sol[i] << '\n';
        // int x = input[i].first;
        // int y = input[i].second;
        // if(capacitate[y][x] > 0)
        //     fout << i + 1 << " ";
    }




    return 0;
}
