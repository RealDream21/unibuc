#include <bits/stdc++.h>

using namespace std;


class Solution {
    unordered_map<int, vector<int>> graf;
    unordered_map<int, int> ies_din;
    unordered_map<int, int> intra_in;
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        vector<vector<int>> sol;
        vector<int> sol_nodes;

        for(int i = 0; i < pairs.size(); i++)
        {
            graf[pairs[i][0]].push_back(pairs[i][1]);
            intra_in[pairs[i][1]]++;
            ies_din[pairs[i][0]]++;
        }
        int node = -1;
        for(int i = 0; i < pairs.size(); i++)
        {
            if(ies_din[pairs[i][0]] - intra_in[pairs[i][0]] == 1)
                node = pairs[i][0];
            if(node != -1)
                break;
        }

        if(node == -1)
            node = pairs[0][0];

        vector<int> q;
        q.push_back(node);

        while(!q.empty())
        {
            if(ies_din[node])
            {
                q.push_back(node);
                int next = graf[node].back();
                ies_din[node]--;
                graf[node].pop_back();

                node = next;
            }
            else
            {
                sol_nodes.push_back(node);
                node = q.back();
                q.pop_back();
            }
        }

        for(int i = sol_nodes.size() - 1; i >= 1; i--)
        {
            sol.push_back(vector<int>{sol_nodes[i], sol_nodes[i - 1]});
        }
        return sol;
    }
};


int main()
{
    vector<vector<int>> pairs = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};
    Solution t;
    vector<vector<int>> vt;
    vt = t.validArrangement(pairs);
    for(int i = 0; i < vt.size(); i++)
    {
        cout << vt[i][0] << " " << vt[i][1] << endl;
    }

}
