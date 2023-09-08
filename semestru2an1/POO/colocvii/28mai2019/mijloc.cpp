#include "mijloc.h"

Manager* Manager::instance = nullptr;

Manager* Manager::getInstance()
{
    if(instance == nullptr)
        instance = new Manager();
    else return instance;
}

void Manager::adaugaStatie()
{
    std::cout << "De ce tip sa fie statia?\n1.Urbana\n2.Extraurbana:\n";
    std::string input;
    std::cin >> input;
    if(input == "1"){
        std::shared_ptr<Statie> newStatie = std::make_shared<Urbana>();
        newStatie->readInfo();
        statii.push_back(newStatie);
    }
    else if(input == "2"){
        std::shared_ptr<Statie> newStatie = std::make_shared<Extraurbana>();
        newStatie->readInfo();
        statii.push_back(newStatie);
    }
}

void Manager::enter()
{
    std::cout << "Bun venit\n";
    std::string input;
    while(true)
    {
        std::cout << "Ce vrei sa faci?\n0.Iesi\n1.Adauga o statie noua:\n2.Afisare detalii statii\n";
        std::cin >> input;
        if(input == "0")
            break;
        if(input == "1"){
            adaugaStatie();
        }
        else if(input == "2"){
            std::cout << "Introduceti nume de statie:\n";
            std::string nume;
            std::cin >> nume;
            (*this)[nume]->showInfo();
        }
    }
}

std::shared_ptr<Statie> Manager::operator[](std::string nume)
{
    std::vector<std::shared_ptr<Statie>>::iterator p;
    for(p; p != statii.end(); p++){
        if((*p)->getNume() == nume)
            return *p;
    }
    throw std::out_of_range("Nu am gasit statia");
}
