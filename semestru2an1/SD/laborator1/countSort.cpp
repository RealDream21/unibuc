#include <iostream>
using namespace std;

int main()
{
    int n, v[100], nmax;
    cin >> n >> v[0];
    nmax = v[0];

    for(int i = 1; i < n; i++)
    {
        cin >> v[i];
        if(v[i] > nmax) nmax = v[i];
    }

    int fv[nmax];

    for(int i = 0; i <= nmax; i++) fv[i] = 0;

    for(int i = 0; i < n; i++) fv[v[i]]++;

    for(int i = 0; i <= nmax; i++)
    {
        while(fv[i] != 0)
        {
            cout << i << " ";
            fv[i]--;
        }
    }
    return 0;
}
