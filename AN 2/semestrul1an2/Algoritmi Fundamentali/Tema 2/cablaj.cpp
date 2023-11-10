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

    int multime[n + 1]; //pentru union find ca sa vad daca inchide ciclu
    for(int i = 0; i < n; i++)
        multime[i] = i;

    double s = 0;
    for(int i = 0; i < distante.size(); i++)
    {
        //X Y => multime(X) = multime(Y)
        int x = distante[i].first.first;
        int y = distante[i].first.second;
        double len = distante[i].second;

        int multimeX = gasesteMultime(multime, x);
        int multimeY = gasesteMultime(multime, y);
        if(multimeX != multimeY)
        {
            s += len;
            multime[multimeX] = multimeY;
        }
    }

    cout << setprecision(2) << s << endl;

    return 0;
}
