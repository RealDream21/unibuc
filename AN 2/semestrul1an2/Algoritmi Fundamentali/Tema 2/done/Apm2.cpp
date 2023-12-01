#include <bits/stdc++.h>

using namespace std;

ifstream fin("apm2.in");
ofstream fout("apm2.out");

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
};

struct muchie
{
    int x, y, d;
    muchie(int a, int b, int c)
        :x(a), y(b), d(c)
    {}
};

bool cmpCosturi(muchie m1, muchie m2)
{
    return m1.d < m2.d;
}

int main()
{
    int n, m, q;
    fin >> n >> m >> q;
    vector<muchie> costuri;
    vector<muchie> drumuri_noi;
    for(int i = 0; i < m; i++)
    {
        int a, b ,c;
        fin >> a >> b >> c;
        costuri.push_back(muchie(a, b, c));
    }

    for(int i = 0; i < q; i++)
    {
        int x, y;
        fin >> x >> y;
        drumuri_noi.push_back(muchie(x, y, -1));
    }

    sort(costuri.begin(), costuri.end(), cmpCosturi);

    DisjointSetUnion myset(n + 1);

    for(int i = 0; i < costuri.size(); i++)
    {
        int x = costuri[i].x;
        int y = costuri[i].y;
        int cost = costuri[i].d;

        int multimeX = myset.find_set(x);
        int multimeY = myset.find_set(y);

        if(multimeX != multimeY)
        {
            myset.unite(x, y);
            for(int j = 0; j < drumuri_noi.size(); j++)
            {
                int u = drumuri_noi[j].x;
                int v =  drumuri_noi[j].y;
                if(myset.find_set(u) == myset.find_set(v) && drumuri_noi[j].d == -1)
                {
                    drumuri_noi[j].d = cost - 1;
                }
            }
        }
    }

    for(int i = 0; i < drumuri_noi.size(); i++)
    {
        fout << drumuri_noi[i].d << endl;
    }

    return 0;
}
