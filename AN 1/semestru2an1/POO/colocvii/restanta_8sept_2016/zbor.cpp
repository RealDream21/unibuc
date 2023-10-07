#include "zbor.h"

int Zbor::cnt = 0;


Zbor::Zbor():Zbor_Baza()
{
    Zbor::cnt++;
    id = cnt;
}

Zbor::Zbor(std::string o, std::string z, std::string d, std::string du, int pret, int discount = 0)
    :oras(o), zi(z), destinatie(d), durata(du), discount(discount), pret(pret)
{
    cnt++;
    id = cnt;
}

void Zbor::showInfo()const
{
    std::cout << "ID: " << id << std::endl;
    std::cout << "Plecare: " << oras << std::endl;
    std::cout << "Destinatie: " << destinatie << std::endl;
    std::cout << "Zi: " << zi << std::endl;
    std::cout << "Durata: " << durata << std::endl;
}

void Zbor::citeste()
{
    std::cout << "Plecare:\n";
    std::string p;
    std::cin >> p;
    std::cout << "Zi:\n";
    std::string z;
    std::cin >> z;
    std::cout << "Dest:\n";
    std::string d;
    std::cout << "Durata zbor:\n";
    std::cin >> durata;
}

ZborSpecial::ZborSpecial(std::string o, std::string z, std::string d, std::string du, int pret, int per, int disc = 0)
        :Zbor(o, z, d, du,pret, disc), perioada(per)
{}

void ZborSpecial::showInfo()const
{
    Zbor::showInfo();
    std::cout << "Perioada de activare: " << perioada << "\n";
}

void ZborSpecial::citeste()
{
    Zbor::citeste();
    std::cout << "Perioada de activare:\n";
    int per;
    std::cin >> per;
    if(per < 0)
        throw std::invalid_argument("Perioada nu este valida");
    std::cout << "Durata efectuare:\n";
    std::cin >> durataEfectuare;
    perioada = per;
}
