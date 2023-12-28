#include <bits/stdc++.h>

using namespace std;

ifstream fin("cartite.in");
ofstream fout("cartite.out");

//1 -> vulpe, 2 -> galerie, 4-> cartita(desi cred ca nu conteaza), 3 -> cartita + galerie

const int NMAX = 205;
int graf[NMAX][NMAX];
int cerinta, xc, yc, nrvulpi, nrgalerii;
vector<int> graf2[NMAX];
map<pair<int, int>, int> coordToGal;
map<int, pair<int, int>> galToCoord;
int n, m;

bool bounded(int x, int y)
{
   if(x >= 1 && x <= n && y >= 1 && y <= m)
        return true;
   return false;
}

void adauga_vulpe(int xv, int yv, int tip)
{
    if(tip == 0){
        graf[xv][yv] = 1;
        return;
    }
    else if(tip == 1)
    {
        //121
        int xcolt = xv - 1, ycolt = yv - 1;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                int xnew = xcolt + i, ynew = ycolt + j;
                if((i == 1 || j == 1) && bounded(xnew, ynew))
                    graf[xnew][ynew] = 1;
            }
        }
        return;
    }
    else
    {
        int xcolt = xv - 2, ycolt = yv - 2;
        //13531
        vector<int> pattern = {1,3,5,3,1};
        for(int i = 0; i < pattern.size(); i++)
        {
            int xnew = xcolt + i;
            int cnt = pattern[i];
            for(int j = 0; j < cnt; j++)
            {
                int ynew = ycolt + (5-cnt)/2 + j;
                if(bounded(xnew, ynew))
                    graf[xnew][ynew] = 1;
            }
        }
        return;
    }
}

void solve_cerinta1()
{
    if(graf[xc][yc] == 2)
    {
        fout << xc << " " << yc << " " << 0;
        return;
    }

    int dist[n + 2][m + 2];
    memset(dist, 0, (n + 2)*(m + 2)*sizeof(int));

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    queue<pair<int, int>> nodeq;
    nodeq.push(make_pair(xc, yc));

    while(!nodeq.empty())
    {
        pair<int, int> node = nodeq.front();
        nodeq.pop();
        int i = node.first;
        int j = node.second;

        if(graf[i][j] >= 2)//e galerie
        {
            fout << i << " " << j << " " << dist[i][j];
            return;
        }

        for(int k = 0; k < 4; k++)
        {
            int newi = i + dx[k];
            int newj = j + dy[k];
            if(bounded(newi, newj) && dist[newi][newj] == 0)
            {
                if(graf[newi][newj] != 1)
                {
                    dist[newi][newj] = dist[i][j] + 1;
                    nodeq.push(make_pair(newi, newj));
                }
            }
        }
    }
}

void solve_cerinta2(int xstart, int ystart)
{
    int node = coordToGal[make_pair(xstart, ystart)];
    vector<int> st;
    st.push_back(node);
    vector<int> sol;
    while(!st.empty())
    {
        node = st.back();
        if(graf2[node].size() == 0)
        {
            sol.push_back(node);
            st.pop_back();
        }
        else
        {
            int next = graf2[node].back();
            for(auto it = graf2[next].begin(); it != graf2[next].end(); it++)
            {
                if((*it) == node)
                {
                    graf2[next].erase(it);
                    break;
                }
            }
            graf2[node].pop_back();
            st.push_back(next);
        }
    }
    for(int i = 0; i < sol.size(); i++)
    {
        fout << galToCoord[sol[i]].first << " " << galToCoord[sol[i]].second << endl;
    }
}


int main()
{
    fin >> cerinta;
    fin >> n >> m;
    fin >> xc >> yc;
    //graf[xc][yc] = 3;
    fin >> nrvulpi;
    for(int i = 0; i < nrvulpi; i++)
    {
        int xv, yv, tip;
        fin >> xv >> yv >> tip;
        adauga_vulpe(xv, yv, tip);
    }
    fin >> nrgalerii;
    int k = 1;
    int xstart = -1, ystart = -1;
    for(int i = 0; i < nrgalerii; i++)
    {
        int xg1, yg1, xg2, yg2;
        fin >> xg1 >> yg1 >> xg2 >> yg2;
        if(coordToGal[make_pair(xg1, yg1)] == 0)
        {
            coordToGal[make_pair(xg1, yg1)] = k;
            galToCoord[k] = make_pair(xg1, yg1);
            k++;
        }
        if(coordToGal[make_pair(xg2, yg2)] == 0)
        {
            coordToGal[make_pair(xg2, yg2)] = k;
            galToCoord[k] = make_pair(xg2, yg2);
            k++;
        }

        graf2[coordToGal[make_pair(xg1, yg1)]].push_back(coordToGal[make_pair(xg2, yg2)]);
        graf2[coordToGal[make_pair(xg2, yg2)]].push_back(coordToGal[make_pair(xg1, yg1)]);

        graf[xg1][yg1] += 2;
        graf[xg2][yg2] += 2;

        if(xstart == -1)
        {
            if(graf[xg1][yg1] == 2)
            {
                xstart = xg1;
                ystart = yg1;
            }
            else if(graf[xg2][yg2] == 2)
            {
                xstart = xg2;
                ystart = yg2;
            }
        }
    }

    if(cerinta == 1)
    {
        solve_cerinta1();
    }
    else if(cerinta == 2)
    {
        solve_cerinta2(xstart, ystart);
    }
    return 0;
}
