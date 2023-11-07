class Solution {
    int mapping(char& a)
    {
        return a-'a';
    }
    int findGroup(int element, int * group)
    {
        while(element != group[element])
            element = group[element];
        return element;
    }

public:
    bool equationsPossible(vector<string>& equations) {
        int max_alphabet = 30;
        int group[max_alphabet];
        for(int i = 0; i < max_alphabet; i++)
            group[i] = -1;
        for(int i = 0; i < equations.size(); i++)
        {
            group[mapping(equations[i][0])] = mapping(equations[i][0]);
            group[mapping(equations[i][3])] = mapping(equations[i][3]);
        }

        for(int i = 0; i < equations.size(); i++)
        {
            if(equations[i][1] == '=')
            {
                //=> should be in the same group
                group[findGroup(mapping(equations[i][0]), group)] = findGroup(mapping(equations[i][3]), group);
            }
        }



        for(int i = 0; i < equations.size(); i++)
        {
            if(equations[i][1] == '!')
            {
                if(findGroup(mapping(equations[i][0]), group) == findGroup(mapping(equations[i][3]), group))
                   return false;
            }
        }
        return true;
    }
};
