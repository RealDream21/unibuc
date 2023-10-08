#include "proprietate.h"

Proprietate::Proprietate(std::string a, int s, int c)
            :adresa(a), suprafata(s), chirie(c)
{}

void Proprietate::showInfo()const
{
    std::cout << "Adresa: " << adresa<< std::endl;
    std::cout << "Suprafata: " << suprafata<< std::endl;
    std::cout << "Chirie: " << chirie << std::endl;
}

Casa::Casa(int n, int cu, std::string a, int s, int c)
            :Proprietate(a, s, c), niveluri(n), curte(cu)
{}

void Casa::showInfo()const
{
    Proprietate::showInfo();
    std::cout << "Niveluri: " << niveluri << std::endl;
    std::cout << "Curte: " << curte << std::endl;
}

int Casa::getChirie(int perioada)const
{
    float discount = 0;
    if(perioada > 12)
        discount = 0.05;
    else if(perioada > 24)
        discount = 0.1;
    return chirie * (suprafata - 0.2 * curte) * (1 - discount);
}

Apartament::Apartament(int e, int ca, std::string a, int s, int c)
            :Proprietate(a, s, c), etaj(e), camere(ca)
{}

void Apartament::showInfo()const
{
    Proprietate::showInfo();
    std::cout << "Etaj: " << etaj << std::endl;
    std::cout << "Camere: " << camere << std::endl;
}

int Apartament::getChirie(int perioada)const
{
    float discount = 0;
    if(perioada > 12)
        discount = 0.05;
    else if(perioada > 24)
        discount = 0.1;
    return chirie * suprafata * (1 - discount);
}
