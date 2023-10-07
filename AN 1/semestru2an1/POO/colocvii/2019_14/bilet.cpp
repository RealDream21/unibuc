#include "bilet.h"

Bilet::Bilet(int distanta, std::string plecare,std::string sosire, std::string data, std::string ora_plecare,std::string cod,std::string durata)
    :distanta(distanta), plecare(plecare), sosire(sosire), data(data), ora_plecare(ora_plecare), cod(cod), durata(durata)
{
    serie = cod;
}

void Bilet::showInfo()const
{
    std::cout << "Plecare: " << plecare << std::endl;
    std::cout << "Sosire: " << sosire << std::endl;
    std::cout << "Cod: " << cod << std::endl;
    std::cout << "Serie: " << serie << std::endl;
}

Clasa1::Clasa1(int nr, int distanta, std::string plecare, std::string sosire, std::string data, std::string ora_plecare, std::string cod, std::string durata)
        :Bilet(distanta, plecare, sosire, data, ora_plecare, cod, durata)
{
    serie += "I";
    std::string toAdd = "";
    while(nr){
        toAdd += '0' - nr%10;
        nr/=10;
    }
    serie += toAdd;
    if(cod == "R")
        pret = 0.39 * distanta;
    else if (cod == "IR")
        pret = 0.7 * distanta;
    pret = pret + 0.2* pret;
}

void Clasa1::meniuMancare()const
{
    std::cout << "Shaorma mare mare\n" << std::endl;
}

Clasa2::Clasa2(int nr, int distanta, std::string plecare, std::string sosire, std::string data, std::string ora_plecare, std::string cod, std::string durata)
        :Bilet(distanta, plecare, sosire, data, ora_plecare, cod, durata)
{
    serie += "II";
    std::string toAdd = "";
    while(nr){
        toAdd += '0' - nr%10;
        nr/=10;
    }
    serie += toAdd;
    if(cod == "R")
        pret = 0.39 * distanta;
    else if (cod == "IR")
        pret = 0.7 * distanta;
}

