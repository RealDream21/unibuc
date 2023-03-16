#include <iostream>
using namespace std;

void merge_function(int * v, int st, int mij, int dr){
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

void mergeSort(int *v, int st, int dr){
    if(st < dr){
        int mij = (dr - st)/ 2 + st;
        mergeSort(v, st, mij);
        mergeSort(v, mij + 1, dr);
        merge_function(v, st, mij, dr);
    }
    else return;
}



int main(){
    int v[100], n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    mergeSort(v, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";



    return 0;
}
