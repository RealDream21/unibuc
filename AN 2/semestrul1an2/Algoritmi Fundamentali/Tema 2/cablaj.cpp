#include <iostream>
#include <fstream>
#include <utility>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream fin("cablaj.in");
ofstream fout("cablaj.out");

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
        this->parinti = new int[n + 1];
        this->inaltime = new int[n + 1];
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
        bool cnt_multimi[n + 1];
        int multimi_distincte = 0;
        for(int i = 0; i <= n; i++)
            cnt_multimi[i] = false;
        for(int i = 0; i <= n; i++)
            cnt_multimi[find_set(i)] = true;
        for(int i = 0; i <= n; i++)
            multimi_distincte += bool(cnt_multimi[i]);
        return multimi_distincte;
    }
};

double calculeaza_distanta(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

bool comparareDrumuri(pair<pair<int, int>, double> drum1, pair<pair<int, int>, double> drum2)
{
    return drum1.second < drum2.second;
}

int gasesteMultime(int* multime, int elem)
{
    while(multime[elem] != elem)
        elem = multime[elem];
    return multime[elem];
}

int main()
{
    vector<pair<pair<int, int>, double>> distante;
    vector<pair<int, int>> coordonate;
    int n;
    fin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        fin >> x >> y;
        coordonate.push_back(make_pair(x, y));
    }

    //orasele sunt in ordine incepand cu 0

    for(int i = 0; i < coordonate.size() - 1; i++)
    {
        for(int j = i + 1; j < coordonate.size(); j++)
        {
            double len = calculeaza_distanta(coordonate[i].first, coordonate[i].second, coordonate[j].first, coordonate[j].second);
            pair<int, int> drumXY(i, j);
            pair<pair<int, int>, double> distXY(drumXY, len);
            distante.push_back(distXY);
        }
    }
    sort(distante.begin(), distante.end(), comparareDrumuri);

    DisjointSetUnion myset(n);

    double s = 0;
    for(int i = 0; i < distante.size(); i++)
    {
        //X Y => multime(X) = multime(Y)
        int x = distante[i].first.first;
        int y = distante[i].first.second;
        double len = distante[i].second;

        int multimeX = myset.find_set(x);
        int multimeY = myset.find_set(y);
        if(multimeX != multimeY)
        {
            s += len;
            myset.unite(x, y);
        }
    }

    cout << setprecision(4) << s << endl;

    return 0;
}
