#include "contract.h"

Contract::Contract(std::string nume, std::shared_ptr<Proprietate> p)
            :nume(nume), prop(p)
{}

void Contract::showInfo()const
{
    std::cout << "Nume client: " << nume << std::endl;
    std::cout << "Informatii despre proprietate" << std::endl;
    prop->showInfo();
}

Chirie::Chirie(std::string nume, int perioada, std::shared_ptr<Proprietate> p)
        :Contract(nume, p), perioada(perioada)
{}

int Chirie::getChirie()const
{
    return prop->getChirie(perioada);
}

void Chirie::showInfo()const
{
    std::cout << "Perioada chiriei: " << perioada << std::endl;
    Contract::showInfo();
}

Vanzare::Vanzare(int l, int a, int l_i, int a_i, std::string nume, std::shared_ptr<Proprietate> p)
        :Contract(nume, p), luna(l), an(a), luna_i(l_i), an_i(a_i)
{
    if(12* (an_i - an)  + luna_i - luna > 240)
        throw std::invalid_argument("Ratele sunt mai multe de 240");
}

void Vanzare::showInfo()const
{
    std::cout << "Pretul este: " << getPret() << std::endl;
    Contract::showInfo();
}

int Vanzare::getPret()const
{
    float reducere = 0;
    if(luna == luna_i && an == an_i)
        reducere = 0.1;
    else if(12* (an_i - an)  + luna_i - luna <= 60)
        reducere = 0.07;
    else if(12* (an_i - an)  + luna_i - luna <= 120)
        reducere = 0.05;
    return 240 * prop->getChirie(1) * (1 - reducere);
}
