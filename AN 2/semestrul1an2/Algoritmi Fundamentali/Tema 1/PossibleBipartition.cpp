#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        queue<int> nodeq;
        unordered_map<int, int> team;
        for(int i = 1; i <= n; i++)
        {
            nodeq.push(i);
            if(team[i] == 0)
                team[i] = 1;
            while(!nodeq.empty())
            {
                int next = nodeq.front();
                nodeq.pop();
                for(auto p : dislikes[next])
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

int main()
{
    Solution p;
    int n = 4;
    vector<vector<int>> dislikes = {{1,2},{1,3},{2,4}};
    cout << p.possibleBipartition(n, dislikes);
    return 0;
}
