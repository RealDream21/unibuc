#include <iostream>
#include <vector>
using namespace std;

vector <int> radix[9];

void afis(int *p, int n)
{
    for(int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << endl;
    return;
}

///pop_back(), push_back();

int main()
{
    int v[100], n, max_cif = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        int aux = v[i];
        int cif = 1;
        while(aux >= 10)
        {
            cif++;
            aux /= 10;
        }
        if(cif > max_cif) max_cif = cif;
    }
    int p = 1;
    for(int i = 0; i < max_cif; i++)
    {
        int k = 0;
        cout << "Impart la " << p << endl;
        for(int j = 0; j < n; j++)
        {

            if(v[j]/p%10 == 0)
            {
                radix[v[j]/p%10].push_back(v[j]);
                k++;
            }
            afis(v, n);
        }
        for(int j = 0; j <= 9; j++)
        {

            while(radix[j].empty() == 0)
            {
                v[k++] = radix[j].back();
                radix[j].pop_back();
            }
        }
        p *= 10;
    }

    for(int i = 0; i < n; i++) cout << v[i] << " ";
    return 0;
}
