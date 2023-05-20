#include "copii.h"
int Copil::ID = 0;

Copil::Copil(std::string& n, std::string&p, std::string& ad, int v, int f)
    :nume(n), prenume(p), adresa(ad), varsta(v), fapte(f)
{
    id_spec = ID;
    ID++;
}

std::string Copil::getNume()const
{
    return nume;
}

void Copil::showInfo()const
{
    std::cout << "Nume: " << nume << std::endl;
    std::cout << "Prenume: " << prenume << std::endl;
    std::cout << "Adresa: " << adresa << std::endl;
    std::cout << "Varsta: " << varsta << std::endl;
    std::cout << "Fapte: " << fapte << std::endl;
    std::cout << "Jucarii: " << std::endl;
    for(int i = 0; i < jucarii.size(); i++)
        jucarii[i]->showInfo();
    std::cout << std::endl;
}

void Copil::adaugaJucarie(std::shared_ptr<Jucarie> juc)
{
    jucarii.push_back(juc);
}

Cuminte::Cuminte(int d, std::string& n, std::string& p, std::string& ad, int v, int f)
        :Copil(n, p, ad, v, f), dulciuri(d)
{}

void Cuminte::showInfo()const
{
    Copil::showInfo();
    std::cout << "Nr. Dulciuri: " << dulciuri << std::endl;
}

Neastamparat::Neastamparat(int c, std::string& n, std::string& p, std::string& ad, int v, int f)
                :Copil(n, p, ad, v, f), carbuni(c)
{}

void Neastamparat::showInfo()const
{
    Copil::showInfo();
    std::cout << "Nr. Carbuni: " << carbuni << std::endl;
}
