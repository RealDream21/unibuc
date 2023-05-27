#include "tren.h"

int Tren::nr_ordine = 0;

Regio::Regio()
{
    tip = "R";
}

IRegio::IRegio()
{
    tip = "IR";
}

std::string Regio::getTip()const
{
    return tip;
}

std::string IRegio::getTip()const
{
    return tip;
}

void IRegio::addBilet()
{
    nr_ordine++;
    std::string a = "a";
    std::string b = "a";
    std::string c = "a";
    std::string d = "a";
    std::string e = "a";
    std::string f = "a";
    std::string g = "a";
    int distanta = 30;
    std::string cod_tren = "IR";
    std::shared_ptr<Bilet> newBilet = std::make_shared<Clasa1>(nr_ordine, distanta, a, b, c, d, cod_tren, f);
    bilete.push_back(newBilet);
}

void Regio::addBilet()
{
    nr_ordine++;
    std::string a = "a";
    std::string b = "a";
    std::string c = "a";
    std::string d = "a";
    std::string e = "a";
    std::string f = "a";
    std::string g = "a";
    int distanta = 30;
    std::string cod_tren = "R";
    std::shared_ptr<Bilet> newBilet = std::make_shared<Clasa2>(nr_ordine, distanta, a, b,c,d,cod_tren,f);
    bilete.push_back(newBilet);
}

void Tren::showBilete()const
{
    for(int i = 0; i < bilete.size(); i++)
        bilete[i]->showInfo();
}
