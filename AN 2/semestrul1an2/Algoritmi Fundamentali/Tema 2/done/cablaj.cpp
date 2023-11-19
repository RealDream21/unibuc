#include<bits/stdc++.h>

using namespace std;

ifstream fin("cablaj.in");
ofstream fout("cablaj.out");

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

class Compare
{
public:
    bool operator()(pair<pair<int, int>, double> drum1, pair<pair<int, int>, double> drum2){
        return drum1.second > drum2.second;
    }
};


int main()
{
    vector<pair<int, int>> localitati;
    priority_queue<pair<pair<int, int>, double>, vector<pair<pair<int, int>, double>>, Compare> heap;
    int n;
    fin >> n;
    int aux = n;
    bool cablat[n + 5];

    for(int i = 0; i < n; i++)
        cablat[i] = false;

    while(n)
    {
        int x, y;
        fin >> x >> y;
        localitati.push_back(make_pair(x, y));
        n--;
    }

    int next = 0, cablate = 0;
    n = aux;
    double total = 0;
    while(cablate < n - 1)
    {
        cablat[next] = true;
        for(int i = 0; i < localitati.size(); i++)
        {
            if(cablat[i])
                continue;
            pair<int, int> drumXY(next, i);
            pair<pair<int, int>, double> distXY (drumXY, dist(localitati[next].first, localitati[next].second, localitati[i].first, localitati[i].second));
            heap.push(distXY);
        }

        while(!heap.empty())
        {
            pair<pair<int, int>, double> elem = heap.top();
            heap.pop();
            int X = elem.first.first;
            int Y = elem.first.second;
            if(cablat[X] && cablat[Y])
                continue;
            if(!cablat[X])
            {
                cablate++;
                total += elem.second;
                next = X;
                break;
            }
            if(!cablat[Y])
            {
                cablate++;
                total += elem.second;
                next = Y;
                break;
            }
        }
    }

    fout << setprecision(3) << fixed << total;
    return 0;
}

    /*pair<int, int> drumXY(1, 2);
    pair<pair<int, int>, double> distXY(drumXY, 1.523);
    heap.push(distXY);

    pair<int, int> drumYZ(2, 10);
    pair<pair<int, int>, double> distYZ(drumXY, 2.31);
    heap.push(distYZ);

    pair<pair<int, int>, double> val;
    val = heap.top();
    cout << val.second;*/
