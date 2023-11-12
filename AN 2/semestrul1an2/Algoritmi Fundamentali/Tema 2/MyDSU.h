#include <iostream>
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
