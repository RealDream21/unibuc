#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("rusuoaica.in");
ofstream fout("rusuoaica.out");

class DisjointSetUnion{
private:
    int n;
    int* parinti;
    int* inaltime;
    DisjointSetUnion() = delete;
public:
    DisjointSetUnion(int n)
    {
        this->n = n;
        this->parinti = new int[n + 5];
        this->inaltime = new int[n + 5];
        for(int i = 0; i <= n; i++)
        {
            parinti[i] = i;
            inaltime[i] = 1;
        }
    }
    ~DisjointSetUnion()
    {
        delete[] parinti;
        delete[] inaltime;
    }

    int find_set(int u)
    {
        while(parinti[u] != u)
            u = parinti[u];
        return u;
    }

    void unite(int u, int v)
    {
        int setU = find_set(u);
        int setV = find_set(v);
        if(inaltime[setU] > inaltime[setV])
            parinti[setV] = setU;
        else{
            parinti[setU] = setV;
            if(inaltime[setU] == inaltime[setV])
                inaltime[setV] = inaltime[setV] + 1;
        }
    }

    int find_distinct_sets()
    {
        int cnt_multimi[n + 1];
        int multimi_distincte = 0;
        for(int i = 0; i <= n; i++)
            cnt_multimi[i] = 0;
        for(int i = 0; i <= n; i++)
            cnt_multimi[find_set(i)]++;
        for(int i = 0; i <= n; i++)
            multimi_distincte += bool(cnt_multimi[i]);
        return multimi_distincte;
    }
};


bool cmpCosturi(pair<pair<int, int>, int> drum1, pair<pair<int, int>, int> drum2)
{
    return drum1.second < drum2.second;
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

    DisjointSetUnion myset(n);
    int costTotal = 0;
    for(int i = 0; i < costuri.size(); i++)
    {
        bool construit = false;
        int x = costuri[i].first.first;
        int y = costuri[i].first.second;
        int multimeX = myset.find_set(x);
        int multimeY = myset.find_set(y);
        int cost = costuri[i].second;

        if(cost <= a)
        {
            //cazul in care poate pun drumul
            if(multimeX != multimeY)
            {
                myset.unite(x, y);
                costTotal += cost;
                construit = true;
            }
        }
        else
        {
            //sterg drumul si pun unul mai ieftin, facand profit
            if(multimeX != multimeY)
            {
                myset.unite(x, y);
                costTotal += (a - cost);
                construit = true;
            }
        }
        if(!construit)
            costTotal -= cost;
    }
    int multimiDistincte = myset.find_distinct_sets() - 1;
    fout << costTotal + a * (multimiDistincte - 1);

    return 0;
}
