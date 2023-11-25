#include <bits/stdc++.h>

using namespace std;

ifstream fin("oracol.in");
ofstream fout("oracol.out");

int mat[1001][1001];
int d[1001];
bool vis[1001];

int main()
{
    int n, x;
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n - i + 1; j++)
        {
            fin >> x;
            if(j == 1)
            {
                mat[i - 1][i] = x;
                mat[i][i - 1] = x;
            }
            else
            {
                mat[i - 1][i - 1 + j] = x;
                mat[i - 1 + j][i - 1] = x;
            }
        }
        d[i - 1] = 1e8;
    }
    d[n] = 1e8;
    d[0] = 0;

    int sol = 0;
    for(int i = 0; i <= n; i++)
    {
        int minim = 1e8;
        int pos = 0;
        for(int j = 0; j <= n; j++)
        {
            if(!vis[j] && d[j] < minim)
            {
                minim = d[j];
                pos = j;
            }
        }

        sol += minim;
        vis[pos] = 1;
        for(int j = 0; j <= n; j++)
        {
            if(!vis[j] && d[j] > mat[pos][j])
                d[j] = mat[pos][j];
        }
    }

    fout << sol;

    return 0;
}
