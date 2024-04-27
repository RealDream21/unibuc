#include <bits/stdc++.h>
using namespace std;

int stangaSauDreapta(int xp, int yp, int xq, int yq, int xr, int yr)
{
    return xq * yr + xr * yp + xp * yq - xq * yp - xr * yq - xp * yr;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

bool egalitate(pair<int, int> a, pair<int, int> b)
{
    return(a.first == b.first && a.second == b.second);
}



int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> puncte;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        puncte.push_back(make_pair(x, y));
    }

    sort(puncte.begin(), puncte.end(), compare);

    vector<pair<int, int>> frontiera_jos;
    frontiera_jos.push_back(puncte[0]);
    frontiera_jos.push_back(puncte[1]);
    for(int i = 2; i < puncte.size(); i++){
        auto punct = puncte[i];
        frontiera_jos.push_back(punct);
        int sz = frontiera_jos.size();
        while(sz > 2 && !(stangaSauDreapta(frontiera_jos[sz - 3].first, frontiera_jos[sz - 3].second,
                                           frontiera_jos[sz - 2].first, frontiera_jos[sz - 2].second,
                                           frontiera_jos[sz - 1].first, frontiera_jos[sz - 1].second) > 0 ))
        {
            frontiera_jos.erase(frontiera_jos.end() - 2);
            sz = frontiera_jos.size();
        }
    }

    vector<pair<int, int>> frontiera_sus;
    frontiera_sus.push_back(puncte[0]);
    frontiera_sus.push_back(puncte[1]);
    for(int i = 2; i < puncte.size(); i++){
        auto punct = puncte[i];
        frontiera_sus.push_back(punct);
        int sz = frontiera_sus.size();
        while(sz > 2 && !(stangaSauDreapta(frontiera_sus[sz - 3].first, frontiera_sus[sz - 3].second,
                                           frontiera_sus[sz - 2].first, frontiera_sus[sz - 2].second,
                                           frontiera_sus[sz - 1].first, frontiera_sus[sz - 1].second) < 0 ))
        {
            frontiera_sus.erase(frontiera_sus.end() - 2);
            sz = frontiera_sus.size();
        }
    }




    for(int i = 0; i < frontiera_jos.size(); i++){
        inFrontiera[frontiera_jos[i]] = true;
    }

    for(int i = frontiera_sus.size() - 1; i >= 0; i--){
        if(!inFrontiera[frontiera_sus[i]]){
            frontiera_jos.push_back(frontiera_sus[i]);
            inFrontiera[frontiera_sus[i]] = true;
        }
    }

    cout << frontiera_jos.size() << endl;
    for(auto punct: frontiera_jos){
        cout << punct.first << " " << punct.second << endl;
    }

    return 0;
}
