class Solution {
void solve(int* discoveryTime, int* lowestTime, int* parinti, int nod, int time, unordered_map<int, vector<int>>& listaVecini, vector<vector<int>>& sol)
{
    discoveryTime[nod] = time;
    lowestTime[nod] = time;
    time++;
    for(auto p : listaVecini[nod])
    {
        if(discoveryTime[p] && p != parinti[nod])
        {
            lowestTime[nod] = min(lowestTime[nod], discoveryTime[p]);
            continue;
        }
        if(discoveryTime[p])
            continue;
        parinti[p] = nod;
        solve(discoveryTime, lowestTime, parinti, p, time, listaVecini, sol);
        lowestTime[nod] = min(lowestTime[nod], lowestTime[p]);
        if(lowestTime[p] > discoveryTime[nod])
            sol.push_back(vector<int> {nod, p});
    }
}

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> listaVecini;
        int discoveryTime[n];
        int lowestTime[n];
        int parinti[n];
        for(int i = 0; i < connections.size(); i++)
        {
            discoveryTime[connections[i][0]] = 0;
            discoveryTime[connections[i][1]] = 0;
            lowestTime[connections[i][0]] = 0;
            lowestTime[connections[i][1]] = 0;
            parinti[connections[i][0]] = 0;
            parinti[connections[i][1]] = 0;

            listaVecini[connections[i][0]].push_back(connections[i][1]);
            listaVecini[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> sol;
        solve(discoveryTime, lowestTime, parinti, 0, 1, listaVecini, sol);
        return sol;
    }
};
