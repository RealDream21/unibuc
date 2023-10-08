#include "servicii.h"

bool Precomanda::enabled = false;
int Designated_driver::tarif_fix = 0;

Standard::Standard(int km)
    :km(km)
{}

void Standard::showInfo()const
{
    std::cout << "km: " << km << std::endl;
}

Precomanda::Precomanda(int km, std::string nume ,std::string data, std::string ora, std::string sursa, std::string destinatie)
            :Standard(km), nume(nume), data(data), ora(ora), sursa(sursa), destinatie(destinatie)
{
    if(Precomanda::enabled == false)
        throw std::invalid_argument("Aceasta firma nu accepta precomanda\n");
}

void Precomanda::showInfo()const
{
    Standard::showInfo();
    std::cout << "nume: " << nume << std::endl;
    std::cout << "data: " << data << std::endl;
    std::cout << "ora: " << ora << std::endl;
    std::cout << "sursa: " << sursa << std::endl;
    std::cout << "destinatie: " << destinatie << std::endl;
}

void Precomanda::enablePrecomanda()
{
    enabled = true;
}

int Cost_control::getCost(int tarif, int km, std::string sursa, std::string destinatie)
{
    std::cout << "Costul de la " << sursa << " la " << destinatie << "este de: ";
    std::cout << km * tarif;
    return km * tarif;
}

Designated_driver::Designated_driver(int km, std::string n1,std::string l1, std::string n2, std::string l2)
                    :Standard(km), nume1(n1), licenta1(l1), nume2(n2), licenta2(l2)
{}

void Designated_driver::showInfo()const
{
    std::cout << "km: " << km << std::endl;
    std::cout << "nume1: " << nume1 << std::endl;
    std::cout << "licenta1: " << licenta1 << std::endl;
    std::cout << "nume2: " << nume2 << std::endl;
    std::cout << "licenta2: " << licenta2 << std::endl;
}

int Designated_driver::getCost(int tarif_firma)const
{
    return Cost_control::getCost(tarif_firma, km, nume1, nume2) + tarif_fix;
}

std::shared_ptr<Comanda> Precomanda_handler::generatePrecomanda(int km, std::string nume ,std::string data, std::string ora, std::string sursa, std::string destinatie)
{
    return std::make_shared<Precomanda>(km, nume, data, ora, sursa, destinatie);
}

std::shared_ptr<Comanda> Designated_handler::generateDesignated(int km, std::string n1,std::string l1, std::string n2, std::string l2)
{
    return std::make_shared<Designated_driver>(km, n1, l1, n2, l2);
}

std::shared_ptr<Comanda> Standard_handler::generateStandard(int km)
{
    return std::make_shared<Standard>(km);
}
