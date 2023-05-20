#include <iostream>
#include "container.h"

int main()
{
    std::string input;
    Container index_copii;
    while(true)
    {
        std::cout << "Salut, ce vrei sa faci?\n";
        std::cout << "1. Adauga un copil nou\n";
        std::cout << "2. Afiseaza toti copiii\n";
        std::cout << "3. Adauga un cadou la un copil dupa nume\n";
        std::cout << "10. Iesi\n";
        std::cin >> input;
        if(input == "1"){
            std::cout << "Nume copil\n";
            std::string nume;
            std::cin >> nume;
            std::cout << "Prenume copil\n";
            std::string prenume;
            std::cin >> prenume;
            std::cout << "Adresa copil\n";
            std::string adresa;
            std::cin >> adresa;
            std::cout << "Varsta\n";
            int varsta;
            std::cin >> varsta;
            std::cout << "Fapte bune\n";
            std::cout << "A fost bun sau rau?\n1.Bun\n2.Rau\n";
            std::string tip;
            std::cin >> tip;
            if(tip == "1"){
                std::cout << "Introduceti un numar de fapte bune(>10)";
                int fapte;
                std::cin >> fapte;
                while(fapte < 10){
                    std::cout << "Numar prea mic de fapte, introduceti alt numar\n";
                    std::cin >> fapte;
                }
                std::cout << "Introduceti un numar de dulciuri\n";
                int d;
                std::cin >> d;
                std::shared_ptr<Copil> newCopil = std::make_shared<Cuminte>(d, nume, prenume, adresa, varsta, fapte);
                index_copii.addChild(newCopil);
            }
            else if(tip == "2"){
                std::cout << "Introduceti un numar de fapte bune(<10)";
                int fapte;
                std::cin >> fapte;
                while(fapte >= 10){
                    std::cout << "Numar prea mare de fapte, introduceti alt numar\n";
                    std::cin >> fapte;
                }
                std::cout << "Introduceti un numar de carbuni\n";
                int d;
                std::cin >> d;
                std::shared_ptr<Copil> newCopil = std::make_shared<Neastamparat>(d, nume, prenume, adresa, varsta, fapte);
                index_copii.addChild(newCopil);
            }
        }
        else if(input == "2"){
            index_copii.showAll();
        }
        else if(input == "3"){
            std::string nume;
            std::cin >> nume;
            try{
                index_copii[nume]->showInfo();
                std::cout << "Denumire cadou\n";
                std::string denumire;
                std::cin >> denumire;
                std::cout << "Dimensiune cadou\n";
                int dim;
                std::cin >> dim;
                std::cout << "Tip cadou\n";
                std::string tip;
                std::cin >> tip;
                std::cout << "De ce tip este jucarie?\n1. Clasica\n2. Educativa\n3. Electronica\n4. Moderna\n";
                std::string tip_juc;
                std:: cin >> tip_juc;
                if(tip_juc == "1"){
                    std::cout << "Material\n";
                    std::string mat;
                    std::cin >> mat;
                    std::cout << "Culoare\n";
                    std::string cul;
                    std::cin >> cul;
                    std::shared_ptr<Jucarie> newJucarie = std::make_shared<Clasica>(mat, cul, denumire, tip, dim);
                    index_copii[nume]->adaugaJucarie(newJucarie);
                }
                else if(tip_juc == "2"){
                    std::cout << "Abilitate\n";
                    std::string abilitate;
                    std::cin >> abilitate;
                    std::shared_ptr<Jucarie> newJucarie = std::make_shared<Educativa>(abilitate, denumire, tip, dim);
                    index_copii[nume]->adaugaJucarie(newJucarie);
                }
                else if(tip_juc == "3"){
                    std::cout <<"Nr.baterii\n";
                    int nr;
                    std::cin >> nr;
                    std::shared_ptr<Jucarie> newJucarie = std::make_shared<Electronica>(nr, denumire, tip, dim);
                    index_copii[nume]->adaugaJucarie(newJucarie);
                }
                else if(tip_juc == "4"){
                    std::cout << "Brand\n";
                    std::string brand;
                    std::cin >> brand;
                    std::cout << "Model\n";
                    std::string model;
                    std::cin >> model;
                    std::shared_ptr<Jucarie> newJucarie = std::make_shared<Moderna>(brand, model, denumire, tip, dim);
                    index_copii[nume]->adaugaJucarie(newJucarie);
                }
            }
            catch(std::exception& err){
                std::cout << err.what() << std::endl;
            }
        }
        else if(input == "10")
            break;
    }
    return 0;
}
