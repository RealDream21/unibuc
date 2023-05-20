#include "container.h"

void Container::showAll()
{
    for(int i = 0; i < copii.size(); i++)
        copii[i]->showInfo();
}

void Container::addChild(std::shared_ptr<Copil> ch_ptr)
{
    copii.push_back(ch_ptr);
}

std::shared_ptr<Copil> Container::operator[](std::string& toSearch)
{
    bool found = true;
    for(int i = 0; i < copii.size(); i++)
        if(toSearch == copii[i]->getNume())
            return copii[i];
    throw std::invalid_argument("Nu exista un copil cu acest nume!");
}
