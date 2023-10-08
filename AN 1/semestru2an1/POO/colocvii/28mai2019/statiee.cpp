#include "statiee.h"

int Statie::cnt = 0;

std::ostream& operator<<(std::ostream& os, const I_O& other)
{
    other.showInfo();
    return os;
}

std::istream& operator>>(std::istream& is, I_O& other)
{
    other.readInfo();
    return is;
}

void Statie::adaugaTransport(int codT)
{
    transport.push_back(codT);
}

void Statie::showInfo()const
{
    std::cout << "Codul statiei: " << cod_st << std::endl;
    std::cout << "Nume: " << nume << std::endl;
    std::cout << "Adresa: " << adresa << std::endl;
    std::cout << "Transporturi in comun:\n";
    for(int i = 0; i < transport.size(); i++)
        std::cout << transport[i] << " ";
}

void Statie::readInfo()
{
    std::cout <<"Adresa, nume";
    std::string ad, nu;
    std::cin >> ad >> nu;
    adresa = ad;
    nume = nu;
    std::cout << "Numar mijl de transport:\n";
    int nr;
    std::cin >> nr;
    if(nr < 0)
        throw std::invalid_argument("Numar de transporturi mai mic ca 0");
    int x;
    for(int i = 0; i < nr; i++){
        std::cin >> x;
        if(x < 0)
            throw std::invalid_argument("Nu exista acest mijloc de transport");
        transport.push_back(x);
    }
}

std::string Statie::getNume()const
{
    return nume;
}

void Urbana::showInfo()const
{
    std::cout << "Este si punct de informare?" << punct << std::endl;
    Statie::showInfo();
}

void Urbana::readInfo()
{
    std::cout <<"Este punct de informare?\n";
    std::cin >> punct;
    Statie::readInfo();
}


std::string Urbana::tip()const
{
    return "SU";
}

void Extraurbana::showInfo()const
{
    std::cout << "Statia exte extraurbana:\n";
    Statie::showInfo();
}

void Extraurbana::readInfo()
{
    Statie::readInfo();
}

std::string Extraurbana::tip()const
{
    return "SE";
}

