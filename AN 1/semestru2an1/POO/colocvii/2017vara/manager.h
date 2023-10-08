#ifndef MANAGER_H
#define MANAGER_H

#include "contract.h"
#include <vector>

class Manager
{
    std::vector<std::shared_ptr<Proprietate>> proprietati;
    std::vector<std::shared_ptr<Contract>> contracte;
    Manager() = default;
    static Manager* instance;
    Manager& operator=(Manager&) = delete;
    Manager(Manager&) = delete;
public:
    ~Manager();
    static Manager* getInstance();
    void addProprietate();
    void addContract();
    void afiseazaProprietati()const;
    void afiseazaCase()const;
    void afiseazaApartamente()const;
    void afiseazaContracteChirie()const;
    void afiseazaContracteVanzare()const;
};



#endif // MANAGER_H
