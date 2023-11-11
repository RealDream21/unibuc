#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

ifstream fin("rusuoaica.in");
ofstream fout("rusuoaica.out");

bool cmpCosturi(pair<pair<int, int>, int> drum1, pair<pair<int, int>, int> drum2)
{
    return drum1.second < drum2.second;
}

int gasesteMultime(vector<int>& multime, int elem)
{
    while(elem != multime[elem])
        elem = multime[elem];
    return elem;
}

int main()
{
    int n, m, a;
    vector<pair<pair<int, int>, int>> costuri;
    fin >> n >> m >> a;
    for(int i = 0; i < m; i++)
    {
        int x, y, c;
        fin >> x >> y >> c;
        pair<int, int> tunelXY(x, y);
        pair<pair<int, int>, int> costXY(tunelXY, c);
        costuri.push_back(costXY);
    }


    sort(costuri.begin(), costuri.end(), cmpCosturi);

    vector<int> multime;
    for(int i = 0; i <= n + 1; i++)
        multime.push_back(i);

    int costTotal = 0;
    for(int i = 0; i < costuri.size(); i++)
    {
        bool construit = false;
        int x = costuri[i].first.first;
        int y = costuri[i].first.second;
        int multimeX = gasesteMultime(multime, x);
        int multimeY = gasesteMultime(multime, y);
        int cost = costuri[i].second;

        if(cost <= 5)
        {
            //cazul in care poate pun drumul
            if(multimeX != multimeY)
            {
                multime[multimeX] = multimeY;
                costTotal += cost;
                construit = true;
            }
        }
        else
        {
            //sterg drumul si pun unul mai ieftin, facand profit
            if(multimeX != multimeY)
            {
                multime[multimeX] = multimeY;
                costTotal += (a - cost);
                construit = true;
            }
        }
        if(!construit)
            costTotal -= cost;
    }

    for(int i = 1; i < multime.size(); i++)
        multime[i] = gasesteMultime(multime, i);



    vector<int>::iterator it;
    it = unique(multime.begin() + 1, multime.end());
    fout << costTotal + a * (multime.end() - it - 1);

    return 0;
}
