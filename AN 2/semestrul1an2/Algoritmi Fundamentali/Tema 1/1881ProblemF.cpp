#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

//ifstream fin("date.in");

const int nmax = 2*1e5 + 1;
vector<int> G[nmax];
bool marked[nmax];
int dist[nmax];

void resetValues()
{
    for(int i = 0; i < nmax; i++)
    {
        G[i].clear();
        marked[i] = false;
        dist[i] = 0;
    }
}

void resetSearchValues()
{
    for(int i = 0; i < nmax; i++)
    {
        dist[i] = 0;
    }
}

int furthestNode(int node, int & l)
{
    int maxDist = -1;
    int furthestNode = node;
    queue<int> nodeq;
    nodeq.push(node);
    dist[node] = 1;
    while(!nodeq.empty())
    {
        node = nodeq.front();
        nodeq.pop();
        if(marked[node])
        {
            if(dist[node] > maxDist)
            {
                maxDist = dist[node];
                furthestNode = node;
            }
        }

        for(auto p : G[node])
        {
            if(dist[p] == 0)
            {
                dist[p] = 1 + dist[node];
                nodeq.push(p);
            }
        }
    }
    l = maxDist;
    return furthestNode;
}

int main()
{
    int t;
    cin >> t;
    while(t)
    {
        int n, k;
        cin >> n >> k;
        resetValues();
        int start;
        for(int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            start = x;
            marked[x] = true;
        }
        for(int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        if(k == 1)
        {
            t--;
            cout << 0 << endl;
            continue;
        }
        int l;
        start = furthestNode(start, l);
        resetSearchValues();
        furthestNode(start, l);
        cout << l/2 << endl;
        t--;
    }
    return 0;
}
