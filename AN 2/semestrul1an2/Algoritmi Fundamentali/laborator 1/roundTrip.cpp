#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

ifstream fin("RT.in");
bool globalFound = false;

const int NMAX = 1e7 + 1;
vector<int> G[NMAX + 1];

void trip(int start, int x, unordered_map<int, bool> visited, vector<int> sol)
{
    if(globalFound == true)
        return;
    sol.push_back(x);
    visited[x] = true;
    for(auto next : G[x])
    {
        if(sol.size() >= 3 && next == start){
            sol.push_back(next);
            cout << sol.size() << endl;
            for(auto p : sol)
                cout << p << " ";
            cout << endl;
            globalFound = true;
            break;
            return;
        }
        else if(!visited[next]){
            trip(start, next, visited, sol);
        }
        if(globalFound == true)
            return;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        unordered_map<int, bool> visited;
        visited.clear();
        vector<int> sol;
        sol.clear();
        trip(i, i, visited, sol);
        if(globalFound == true)
            break;
    }
    if(globalFound == false)
        cout << "IMPOSSIBLE";

    return 0;
}
