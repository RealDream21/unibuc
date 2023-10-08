#include "statie.h"

int Statie::id_statie = 0;

Statie::Statie(std::string& stradaInit, const int numarInit, const int sectorInit): strada(stradaInit), numar(numarInit), sector(sectorInit)
{
    cod_statie = id_statie;
    id_statie++;
}

Statie_urbana::Statie_urbana(std::string& stradaInit, const int numarInit, const int sectorInit): Statie(stradaInit, numarInit, sectorInit)
{
    std::string numar_ordine = "";
    int aux = id_statie;
    while(aux)
    {
        numar_ordine += char(aux%10 + '0');
        aux /= 10;
    }

    cod_unic_statie += "SU";
    cod_unic_statie += "-";
    for(int i = numar_ordine.size() - 1; i >= 0; i--)
        cod_unic_statie += numar_ordine[i];
}

void Statie_urbana::showStatie()
{
    std::cout << cod_unic_statie;
}

std::string Statie_urbana::get_cod_statie()
{
    return cod_unic_statie;
}
