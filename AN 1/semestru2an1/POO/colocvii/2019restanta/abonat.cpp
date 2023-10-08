#include "abonat.h"

abonat::abonat(std::string& numeInit, std::string& numar_telefonInit, std::shared_ptr<abonament>& abInit): nume(numeInit), numar_telefon(numar_telefonInit), ab(abInit)
{
    std::cout << "Created abonat\n";
}

void abonat::showInfo()const
{
    std::cout << "Nume: " << nume << std::endl;
    std::cout << "Numar telefon: " << numar_telefon << std::endl;
    ab->showInfo();
}
