#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("algsort.in");
ofstream fout("algsort.out");

int n;
const int NMAX = 1e6;

void shellsort(long long * v){
    long long gap = 2;
    while(n/gap){
        int gap_size = n/gap;
        for(int i = 0; i + gap_size < n; i++)
            if(v[i] > v[i + gap_size])
                swap(v[i], v[i + gap_size]);
        gap *= 2;
    }
}

void radixSort(long long * const v, const long long base){
    vector<vector<long long>> buckets(base);
    long long p = 1;
    while(buckets[0].size() != n){
        for(int i = 0; i < base; i++)
            buckets[i].clear();

        for(int i = 0; i < n; i++)
            buckets[v[i]/p%base].push_back(v[i]);

        int k = 0;
        for(int i = 0; i < base; i++){
            for(int j = 0; j < buckets[i].size(); j++)
                v[k++] = buckets[i][j];
        }
        p *= base;
    }
    return;
}

void merge_function(long long * v, int st, int mij, int dr){
    int i = st;
    int j = mij + 1;
    int aux[dr - st + 1];
    int k = 0;
    while(i <= mij && j <= dr){
        if(v[i] > v[j])
            aux[k++] = v[j++];
        else
            aux[k++] = v[i++];
    }
    while(i <= mij)
        aux[k++] = v[i++];
    while(j <= dr)
        aux[k++] = v[j++];
    k = 0;
    for(int i = st; i <= dr; i++){
        v[i] = aux[k++];
    }
}

void mergeSort(long long *v, int st, int dr){
    if(st < dr){
        int mij = (dr - st)/ 2 + st;
        mergeSort(v, st, mij);
        mergeSort(v, mij + 1, dr);
        merge_function(v, st, mij, dr);
    }
    else return;
}

int main()
{
    fin >> n;
    long long *v;
    v = new long long[n];
    for(int i = 0; i < n; i++)
        fin >> v[i];
    shellsort(v);
    for(int i = 0; i < n; i++)
        fout << v[i] << " ";


    fin.close();
    fout.close();
    return 0;
}
