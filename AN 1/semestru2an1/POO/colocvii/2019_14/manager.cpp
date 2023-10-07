#include "manager.h"

Manager* Manager::instance;

Manager* Manager::getInstance()
{
    if(instance == nullptr)
        instance = new Manager();
    return instance;
}

void Manager::addTren()
{
    std::string input;
    std::cout << "1.Tren Regio\n2.Tren InterRegion:\n";
    std::cin >> input;
    if(input == "1"){
        std::shared_ptr<Tren> newTren = std::make_shared<Regio>();
        trenuri.push_back(newTren);
    }
    else if(input == "2"){
        std::shared_ptr<Tren> newTren = std::make_shared<IRegio>();
        trenuri.push_back(newTren);
    }
}

std::shared_ptr<Tren> Manager::operator[](int i)
{
    if(i > trenuri.size())
        throw std::out_of_range("Nu exista acest tren");
    else return trenuri[i];
}


void Manager::enterMenu()
{
    while(true)
    {
        std::cout << "Salut, ce vrei sa faci?\n";
        std::string input;
        std::cin >> input;
        if(input == "6")
            break;


    }


}
