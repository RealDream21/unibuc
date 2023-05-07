#include "retea.h"

int retea::prefix = 0;

retea::retea(std::string& nume_reteaInit): nume_retea(nume_reteaInit)
{
    std::cout << "Created retea";
    prefix++;
}

void retea::Register(std::string& nume_abonat, std::shared_ptr<abonament> ab)
{
    std::string numar_telefon = "07";
    numar_telefon += char('0' + prefix);
    numar_telefon += "420";
    abonati.push_back(std::make_shared<abonat>(nume_abonat, numar_telefon, ab));
}

void retea::showAll()
{
    for(int i = 0; i < abonati.size(); i++)
        abonati[i]->showInfo();
}
