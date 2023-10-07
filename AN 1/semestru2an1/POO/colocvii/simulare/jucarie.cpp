#include "jucarie.h"

Jucarie::Jucarie(const std::string& den, const std::string& t, const int dim):denumire(den), tip(t), dimensiune(dim)
{}

void Jucarie::showInfo()const
{
    std::cout << "Denumire " << denumire << std::endl;
    std::cout << "Tip: " << tip << std::endl;
    std::cout << "Dimensiune: " << dimensiune << std::endl;
}


Clasica::Clasica(const std::string& mat, const std::string& cul, const std::string& den, const std::string& t, const int dim)
        :Jucarie(den, t, dim), material(mat), culoare(cul)
{}

void Clasica::showInfo()const
{
    Jucarie::showInfo();
    std::cout << "Culoare: " << culoare;
    std::cout << "Dimensiune " << dimensiune;
}

Educativa::Educativa(const std::string& abil, const std::string& den, const std::string& t, const int dim)
            :Jucarie(den, t, dim), abilitate(abil)
{}

void Educativa::showInfo()const
{
    Jucarie::showInfo();
    std::cout << "Abilitate dezvoltata: " << abilitate << std::endl;
}

Electronica::Electronica(const int nr, const std::string& den, const std::string& t, const int dim)
            :Jucarie(den, t, dim), nr_baterii(nr)
{}

void Electronica::showInfo()const
{
    Jucarie::showInfo();
    std::cout << "Baterii: " << nr_baterii << std::endl;
}

Moderna::Moderna(const std::string& br, const std::string& mod, const std::string& den, const std::string& t, const int dim)
        :Educativa(br, den, t, dim), Electronica(1, den, t, dim), brand(br), model(mod)
{
    Educativa::abilitate = "generala";
}

void Moderna::showInfo()const
{
    Educativa::showInfo();
    Electronica::showInfo();
    std::cout << "Brand: " << brand;
    std::cout << "Model: " << model;
}
