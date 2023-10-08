#include "containerAirline.h"

Container* Container::instance = nullptr;

void Ruta::setInfo()
{
    std::cout << "Plecare:\n";
    std::cin >> dela;
    std::cout << "Sosire:\n";
    std::cin >> panala;
    std::cout << "Pretul/bilet:\n";
    std::cin >> pret;
    if(pret < 0)
        throw std::invalid_argument("Pretul nu este valid");
    std::cout << "Numarul de curse:\n";
    std::cin >> nr_curse;
    if(nr_curse < 0)
        throw std::invalid_argument("Numarul de curse nu este valid");
    for(int i = 0; i < nr_curse; i++){
        addZbor();
    }
}

void Ruta::showZboruri()const
{
    std::vector<std::shared_ptr<Zbor>>::iterator p;
    for(p; p != zboruri.end(); p++)
    {
        (*p)->showInfo();
    }
}

void Ruta::showZboruriSpeciale()
{
    std::vector<std::shared_ptr<Zbor>>::iterator p;
    for(p; p != zboruri.end(); p++)
    {
        if(typeid(**p) == typeid(ZborSpecial))
            (*p)->showInfo();
    }
}

void Ruta::addZbor()
{
    std::cout << "De ce tip este cursa?\n1.Normala\n2.Speciala:\n";
    std::string input;
    std::cin >> input;
    if(input == "1"){
        std::shared_ptr<Zbor> newZbor = std::make_shared<Zbor>();
        newZbor->citeste();
        zboruri.push_back(newZbor);
    }
    else if(input == "2"){
        std::shared_ptr<Zbor> newZbor = std::make_shared<ZborSpecial>();
        newZbor->citeste();
        zboruri.push_back(newZbor);
    }
}

std::ostream& operator<<(std::ostream& os, const Ruta& other)
{
    std::cout << "Ruta incepe din " << other.dela << " si se termina la " << other.panala << std::endl;
    other.showZboruri();

}

Container* Container::getInstance()
{
    if(instance == nullptr)
        instance = new Container();
    return instance;
}

void Container::adaugaRuta()
{
    std::shared_ptr<Ruta> newRuta = std::make_shared<Ruta>();
    newRuta->setInfo();
    rute.push_back(newRuta);
}

void Container::enterContainer()
{
    while(true)
    {
        std::cout << "Salut, ce vrei sa faci?\n0.Iesi\n1.Adauga o ruta noua\n2.Afiseaza toate rutele\n3.Adauga o cursa pe o ruta\n";
        std::string input;
        std::cin >> input;
        if(input == "0")
            break;
        else if (input == "1")
            adaugaRuta();
        else if(input == "2"){
            for(int i = 0; i < rute.size(); i++){
                std::cout << *rute[i];
            }
        }
        else if(input == "3"){
            int i;
            std::cout << "Dati indice:\n";
            std::cin >> i;
            (*this)[i]->addZbor();
        }
    }
}

std::shared_ptr<Ruta> Container::operator[](int i)
{
    if(i < 0 || i > rute.size())
        throw std::out_of_range("Nu exista aceasta ruta");
    else return rute[i];
}
