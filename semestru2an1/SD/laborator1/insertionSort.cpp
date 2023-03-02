#include <iostream>
using namespace std;

int v[100];

int main()
{
    int i, j, n, key;
    cout << "n = ";
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 1; i < n; i++)
    {
        j = i - 1;
        key = v[i];
        while(j >= 0 && key < v[j])
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }

    for(int i = 0; i < n; i++) cout << v[i] << " ";
    return 0;
}
