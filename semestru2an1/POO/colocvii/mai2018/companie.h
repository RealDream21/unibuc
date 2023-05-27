#ifndef COMPANIE_H
#define COMPANIE_H
#include <string>
#include <iostream>
#include <vector>
#include "servicii.h"

class Companie
{
    std::string denumire, cod;
    std::vector<std::shared_ptr<Comanda>> istoric;
    std::vector<std::shared_ptr<Handler>> permisiuni;
public:
    Companie(std::string denumire, std::string cod);
    virtual ~Companie() = default;
    virtual void showInfo()const;
};

class Companie_tip2
{



};



#endif // COMPANIE_H
