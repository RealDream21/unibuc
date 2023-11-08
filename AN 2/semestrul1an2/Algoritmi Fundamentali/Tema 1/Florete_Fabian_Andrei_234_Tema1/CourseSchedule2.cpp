class Solution {
    vector<int> G[2005];
    int d[2005];
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; i++)
            d[i] = 0;

        for(int i = 0; i < prerequisites.size(); i++)
        {
            G[prerequisites[i][1]].push_back(prerequisites[i][0]);
            d[prerequisites[i][0]]++;
        }
        queue<int> nodeq;
        vector<int> courseOrder;
        for(int i = 0; i < numCourses; i++)
            if(d[i] == 0)
                nodeq.push(i);

        while(!nodeq.empty())
        {
            int node = nodeq.front();
            nodeq.pop();
            courseOrder.push_back(node);
            for(auto next: G[node])
            {
                d[next]--;
                if(d[next] == 0)
                    nodeq.push(next);
            }
        }
        if(courseOrder.size() - 1 != numCourses - 1){
            return vector<int> {};
        }
        return courseOrder;
    }
};
