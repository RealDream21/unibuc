#include "companie.h"

Companie::Companie(std::string denumire, std::string cod)
            :denumire(denumire), cod(cod)
{
    std::shared_ptr<Handler> a = std::make_shared<Standard_handler>();
    permisiuni.push_back(a);
}

void Companie::showInfo()const
{
    std::cout << "Nume: " << denumire << std::endl;
    std::cout << "cod_fiscal: " << cod << std::endl;
}
