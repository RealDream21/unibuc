
#include "manager.h"

int main()
{
    Manager* meniu = Manager::getInstance();

    std::string input;
    while(true){
        std::cout << "Salut, ce vrei sa faci\n";
        std::cout << "0. Iesi\n";
        std::cout << "1. Adauga proprietati\n";
        std::cout << "2. Adauga contracte\n";
        std::cout << "3. Vezi contracte chirie\n";
        std::cout << "4. Vezi contracte vanzare\n";
        std::cout << "5. Vezi toate proprietatile\n";
        std::cin >> input;
        if(input == "0")
            break;
        if(input == "1")
            meniu->addProprietate();
        else if(input == "2")
            meniu->addContract();
        else if(input == "3")
            meniu->afiseazaContracteChirie();
        else if(input == "4")
            meniu->afiseazaContracteVanzare();
        else if(input == "5")
            meniu->afiseazaProprietati();
    }
    return 0;
}
