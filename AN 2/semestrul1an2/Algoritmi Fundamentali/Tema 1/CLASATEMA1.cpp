#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solutii
{
    bool solvable;
    void solveCourseSchedule2(int, unordered_map<int, vector<int>>&, unordered_map<int, bool>&, vector<int>&, unordered_map<int, bool>&);
public:
    vector<int> findOrder(int, vector<vector<int>>&);
};

int main()
{



    return 0;
}

void Solutii::solveCourseSchedule2(int course, unordered_map<int, vector<int>>& req, unordered_map<int, bool>& seen, vector<int>& sol, unordered_map<int, bool>& inStack)
{
    if((seen[course] && !inStack[course] && !req[course].empty()) || solvable == false)
    {
        solvable = false;
        return;
    }
    seen[course] = true;
    if(req[course].empty() && !inStack[course])
    {
        sol.push_back(course);
        inStack[course] = true;
        return;
    }

    //vector<int> newStack;
    for(auto nextCourse: req[course])
    {
        solveCourseSchedule2(nextCourse, req, seen, sol, inStack);
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

