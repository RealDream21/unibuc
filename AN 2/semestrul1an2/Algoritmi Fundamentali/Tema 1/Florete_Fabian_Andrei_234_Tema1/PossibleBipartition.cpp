class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        queue<int> nodeq;
        unordered_map<int, vector<int>> listaVecini;
        unordered_map<int, int> team(0);

        for(int i = 0; i < dislikes.size(); i++){
                listaVecini[dislikes[i][0]].push_back(dislikes[i][1]);
                listaVecini[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        for(int i = 1; i <= n; i++)
        {
            nodeq.push(i);
            if(team[i] == 0)
                team[i] = 1;
            while(!nodeq.empty())
            {
                int next = nodeq.front();
                nodeq.pop();
                for(auto p : listaVecini[next])
                {
                    if(!team[p])
                    {
                        nodeq.push(p);
                        team[p] = 3 - team[next];
                    }
                    else if(team[p] == team[next])
                        return false;
                }
            }
        }
        return true;
    }
};
