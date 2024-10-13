#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<vector<float>> semiplane_ox;
vector<vector<float>> semiplane_oy;

pair<float, float> gaseste_intersectia(vector<float>& semiplan1, vector<float>& semiplan2)
{
    float a1 = semiplan2[0], b1 = semiplan2[1], c1 = semiplan2[2];
    float a2 = semiplan1[0], b2 = semiplan1[1], c2 = semiplan1[2];
    float x = (c2*b1 - c1*b2) / (a1*b2 - a2*b1);
    float y = (-1 * c1 - a1 * x) / b1;
    return make_pair(x, y);
}

vector<float> gaseste_semiplan_ox(pair<float, float>& punct)
{
    for(auto semiplan: semiplane_ox)
    {
        if (semiplan[0] * punct.first + semiplan[2] == 0)
            return semiplan;
    }
    return {};
}

vector<float> gaseste_semiplan_oy(pair<float, float>& punct)
{
    for(auto semiplan: semiplane_oy)
    {
        if (semiplan[1] * punct.second + semiplan[2] == 0)
            return semiplan;
    }
    return {};
}

bool dreptunghi_valid(pair<float, float>& punct1, pair<float, float>& punct2)
{
    auto semiplan_ox_punct1 = gaseste_semiplan_ox(punct1);
    auto semiplan_oy_punct1 = gaseste_semiplan_oy(punct1);
    auto semiplan_ox_punct2 = gaseste_semiplan_ox(punct2);
    auto semiplan_oy_punct2 = gaseste_semiplan_oy(punct2);
    if (semiplan_ox_punct1[0] < 0 && semiplan_oy_punct1[1] > 0  && semiplan_ox_punct2[0] > 0 && semiplan_oy_punct2[1] < 0)
        return true;
    return false;
}

bool punct_in_dreptunghi(pair<float, float>& punct, vector<pair<float, float>>& dreptunghi)
{
    if (punct.first > dreptunghi[0].first && punct.second < dreptunghi[0].second && punct.first < dreptunghi[1].first && punct.second > dreptunghi[1].second)
        return true;
    return false;
}

int arie(vector<pair<float, float>>& dreptunghi)
{
    return int((dreptunghi[1].first - dreptunghi[0].first)*(dreptunghi[0].second - dreptunghi[1].second));
}

bool comparator(pair<float, float>& pct1, pair<float, float>& pct2)
{
    return pct1.second > pct2.second;
}


int main()
{
    int n, m;
    vector<pair<float, float>> puncte_intersectie;
    vector<vector<pair<float, float>>> dreptunghiuri_interesante;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        float a, b, c;
        cin >> a >> b >> c;
        auto semiplan = vector<float>{a, b,c};
        if(semiplan[0] == 0){
            semiplane_oy.push_back(semiplan);
        }
        else if(semiplan[1] == 0){
            semiplane_ox.push_back(semiplan);
        }
    }

    for(auto semiplan1: semiplane_ox)
    {
        for(auto semiplan2: semiplane_oy)
        {
            auto punct = gaseste_intersectia(semiplan1, semiplan2);
            puncte_intersectie.push_back(punct);
        }
    }

    sort(puncte_intersectie.begin(), puncte_intersectie.end(), comparator);

    for(int i = 0; i < puncte_intersectie.size(); i++)
    {
        for(int j = i + 1; j < puncte_intersectie.size(); j++)
        {
            auto punct1 = puncte_intersectie[i];
            auto punct2 = puncte_intersectie[j];
            if(dreptunghi_valid(punct1, punct2))
                dreptunghiuri_interesante.push_back({punct1, punct2});
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        float a, b;
        cin >> a >> b;
        pair<float, float> punct = make_pair(a,b);
        float min_area = 999999;
        for (auto dreptunghi: dreptunghiuri_interesante)
        {
            if(punct_in_dreptunghi(punct, dreptunghi)){
                if (min_area > arie(dreptunghi))
                    min_area = arie(dreptunghi);
            }
        }
        if(min_area == 999999){
            cout << "NO" << endl;
        }else{
            cout<<"YES" << endl;
            cout << min_area << endl;
        }
    }
    return 0;
}
