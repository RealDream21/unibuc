#include <bits/stdc++.h>
using namespace std;

long long stangaSauDreapta(long long xp, long long yp, long long xq, long long yq, long long xr, long long yr)
{
    return xq * yr + xr * yp + xp * yq - xq * yp - xr * yq - xp * yr;
}

bool compare(pair<long long, long long> a, pair<long long, long long> b)
{
    return (a.first < b.first);
}

bool egalitate(pair<long long, long long> a, pair<long long, long long> b)
{
    return(a.first == b.first && a.second == b.second);
}



int main()
{
    long long n;
    cin >> n;
    vector<pair<long long, long long>> puncte;
    for(long long i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        puncte.push_back(make_pair(x, y));
    }

    sort(puncte.begin(), puncte.end(), compare);

    vector<pair<long long, long long>> frontiera_jos;
    frontiera_jos.push_back(puncte[0]);
    frontiera_jos.push_back(puncte[1]);
    for(long long i = 2; i < puncte.size(); i++){
        auto punct = puncte[i];
        frontiera_jos.push_back(punct);
        long long sz = frontiera_jos.size();
        while(sz > 2 && !(stangaSauDreapta(frontiera_jos[sz - 3].first, frontiera_jos[sz - 3].second,
                                           frontiera_jos[sz - 2].first, frontiera_jos[sz - 2].second,
                                           frontiera_jos[sz - 1].first, frontiera_jos[sz - 1].second) > 0 ))
        {
            frontiera_jos.erase(frontiera_jos.end() - 2);
            sz = frontiera_jos.size();
        }
    }

    vector<pair<long long, long long>> frontiera_sus;
    frontiera_sus.push_back(puncte[0]);
    frontiera_sus.push_back(puncte[1]);
    for(long long i = 2; i < puncte.size(); i++){
        auto punct = puncte[i];
        frontiera_sus.push_back(punct);
        long long sz = frontiera_sus.size();
        while(sz > 2 && !(stangaSauDreapta(frontiera_sus[sz - 3].first, frontiera_sus[sz - 3].second,
                                           frontiera_sus[sz - 2].first, frontiera_sus[sz - 2].second,
                                           frontiera_sus[sz - 1].first, frontiera_sus[sz - 1].second) < 0 ))
        {
            frontiera_sus.erase(frontiera_sus.end() - 2);
            sz = frontiera_sus.size();
        }
    }


    map<pair<long long, long long>, bool> inFrontiera;

    for(long long i = 0; i < frontiera_jos.size(); i++){
        inFrontiera[frontiera_jos[i]] = true;
    }

    for(long long i = frontiera_sus.size() - 1; i >= 0; i--){
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
