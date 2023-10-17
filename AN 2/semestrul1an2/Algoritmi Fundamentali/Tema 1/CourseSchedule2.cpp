#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//idee: incep cu un nod si ma uit ce cursuri trebuie sa fac pentru el
//continui ducandu ma la acele cursuri pana dau de unu gratis
//daca am facut bucla => fail

class Solution {
    bool solvable;
    void solve(int course, unordered_map<int, vector<int>>& req, unordered_map<int, bool>& seen, vector<int>& sol, unordered_map<int, bool>& inStack){
        if((seen[course] && !inStack[course] && !req[course].empty()) || solvable == false)
        {
            solvable = false;
            return;
        }
        seen[course] = true;
        if(req[course].empty() && !inStack[course]){
            sol.push_back(course);
            inStack[course] = true;
            return;
        }

        //vector<int> newStack;
        for(auto nextCourse: req[course])
        {
            solve(nextCourse, req, seen, sol, inStack);
            if(!inStack[nextCourse])
            {
                sol.push_back(nextCourse);
                inStack[nextCourse] = true;
            }
        }
        if(!inStack[course])
        {
            sol.push_back(course);
            inStack[course] = true;
        }
        //req[course] = newStack;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> req;
        unordered_map<int, bool> seen;
        unordered_map<int, bool> inStack;
        vector<int> sol;
        for(int i = 0; i < prerequisites.size(); i++)
            req[prerequisites[i][0]].push_back(prerequisites[i][1]);
        solvable = true;
        for(int i = 0; i < numCourses; i++)
        {
            if(req[i].empty() && !inStack[i])
            {
                sol.push_back(i);
                inStack[i] = true;
            }
            else solve(i, req, seen, sol, inStack);
        }
        if(solvable)
            return sol;
        else return vector<int> {};
    }
};


int main()
{
    Solution p;
    int n = 2;
    vector<vector<int>> pres = {{1, 0}, {0, 1}};
    vector<int> t = p.findOrder(n, pres);
    for(auto p: t)
        cout << p << " ";

    return 0;
}
