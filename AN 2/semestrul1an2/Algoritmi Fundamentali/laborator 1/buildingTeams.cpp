#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("BT.in");
ofstream fout("BT.out");

const int NMAX = 1e5;
int col[NMAX + 1];
vector<int> G[NMAX + 1];

bool bipartit(int x){
    queue<int> q;
    q.push(x);
    col[x] = 1;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(auto next : G[x])
        {
            if(!col[next])
            {
                q.push(next);
                col[next] = 3 - col[x];
            }
            else if(col[next] == 3 - col[x])
                return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    bool ok = true;
    int x, y;
    for(int i = 1; i <= m; i++)
    {
        fin >> x >> y;
        G[x].push_back(y);
        //G[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!col[i])
            ok = bipartit(i);
        if(!ok)
            break;
    }
    if(ok == true){
        for(int i = 1; i <= n; i++)
            cout << col[i] << " ";
    }
    else
        cout << "Nu";
    return 0;
}
