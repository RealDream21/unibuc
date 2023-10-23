#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

ifstream fin("padure.in");
ofstream fout("padure.out");

vector<pair<int, int>> directii = {make_pair(1, 0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1)};

const int costMax = 1e7;


int main()
{

    int n, m, is, ij, ifin, jfin;
    fin >> n >> m >> is >> ij >> ifin >> jfin;
    int padure[n + 1][m + 1];
    int cost[n + 1][m + 1];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            fin >> padure[i][j];
            cost[i][j] = costMax;
        }
    cost[is][ij] = 0;

    queue<pair<int,int>> nodeq;
    nodeq.push(make_pair(is, ij));

    while(!nodeq.empty())
    {
        int i = nodeq.front().first;
        int j = nodeq.front().second;
        nodeq.pop();
        for(int t = 0; t < directii.size(); t++)
        {
            int nexti = i + directii[t].first;
            int nextj = j + directii[t].second;
            if(nexti < 1 || nexti > n || nextj < 1 || nextj > m)
                continue;
            int aux = cost[nexti][nextj];
            if(padure[nexti][nextj] == padure[i][j])
                cost[nexti][nextj] = min(cost[nexti][nextj], cost[i][j]);
            else
            {
                cost[nexti][nextj] = min(cost[nexti][nextj], 1 + cost[i][j]);
            }
            if(aux != cost[nexti][nextj])
                nodeq.push(make_pair(nexti, nextj));
        }
    }

    fout << cost[ifin][jfin];
    return 0;
}
