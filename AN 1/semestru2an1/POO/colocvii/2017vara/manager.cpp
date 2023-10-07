#include "manager.h"

Manager* Manager::instance;

Manager::~Manager()
{
    delete instance;
}

Manager* Manager::getInstance()
{
    if(instance == nullptr)
        instance = new Manager();
    return instance;
}


void Manager::addProprietate()
{
    std::cout << "Adresa:\n";
    std::string adr;
    std::cin >> adr;
    std::cout << "Suprafata:\n";
    int supr;
    std::cin >> supr;
    std::cout << "Chirie:\n";
    int chr;
    std::cin >> chr;
    std::cout << "De ce tip este proprietatea?\n1.Casa\n2.Apartament\n";
    std::string tip;
    std::cin >> tip;
    if(tip == "1"){
        std::cout << "Ai ales casa\n";
        std::cout << "Niveluri:\n";
        int niv;
        std::cin >> niv;
        std::cout << "Curte:\n";
        int cur;
        std::cin >> cur;
        std::shared_ptr<Proprietate> newProp = std::make_shared<Casa>(niv, cur, adr, supr, chr);
        proprietati.push_back(newProp);
    }
    else if(tip == "2"){
        std::cout << "Ai ales apartament\n";
        std::cout << "Etaj:\n";
        int etaj;
        std::cin >> etaj;
        std::cout << "Camere:\n";
        int camere;
        std::cin >> camere;
        std::shared_ptr<Proprietate> newProp = std::make_shared<Apartament>(etaj, camere, adr, supr, chr);
        proprietati.push_back(newProp);
    }
}

void Manager::addContract()
{
    std::string nume;
    std::cout << "Numele persoanei:\n";
    std::cin >> nume;
    std::cout << "Alege o proprietate dupa nr ei de ordine:\n";
    int i;
    std::cin >> i;
    std::cout << "Ce fel de contract este?\n1.Chirie\n2.Vanzare\n";
    if(i > proprietati.size())
        throw std::out_of_range("Nu exista aceasta locuinta");
    std::string tip;
    std::cin >> tip;
    if(tip == "1"){
        std::cout <<"Ai ales chirie:\n";
        int per;
        std::cout << "Perioada:\n";
        std::cin >> per;
        std::shared_ptr<Contract> newContract = std::make_shared<Chirie>(nume, per, proprietati[i]);
        contracte.push_back(newContract);
        proprietati.erase(proprietati.begin() + i);
    }
    else if(tip == "2"){
        std::cout << "Ai ales vanzare\n";
        int luna, an, luna_i, an_i;
        std::cout <<"Informatii despre luna si an\n";
        std::cin >> luna, an, luna_i, an_i;
        std::shared_ptr<Vanzare> newContract = std::make_shared<Vanzare>(luna, an, luna_i, an_i, nume, proprietati[i]);
        proprietati.erase(proprietati.begin() + i);
    }
}

void Manager::afiseazaProprietati()const
{
    for(int i = 0; i < proprietati.size(); i++)
    {
        proprietati[i]->showInfo();
        std::cout << std::endl;
    }
}

void Manager::afiseazaCase()const
{
    for(int i = 0; i < proprietati.size(); i++)
    {
        if(std::dynamic_pointer_cast<Casa>(proprietati[i]) != nullptr){
            proprietati[i]->showInfo();
            std::cout << std::endl;
        }
    }
}

void Manager::afiseazaApartamente()const
{
    for(int i = 0; i < proprietati.size(); i++)
    {
        if(std::dynamic_pointer_cast<Apartament>(proprietati[i]) != nullptr){
            proprietati[i]->showInfo();
            std::cout << std::endl;
        }
    }
}

void Manager::afiseazaContracteChirie()const
{
    for(int i = 0; i < contracte.size(); i++)
    {
        if(std::dynamic_pointer_cast<Chirie>(contracte[i]) != nullptr)
        {
            contracte[i]->showInfo();
            std::cout << std::endl;
        }
    }
}

void Manager::afiseazaContracteVanzare()const
{
    for(int i = 0; i < contracte.size(); i++)
    {
        if(std::dynamic_pointer_cast<Vanzare>(contracte[i]) != nullptr)
        {
            contracte[i]->showInfo();
            std::cout << std::endl;
        }
    }
}
