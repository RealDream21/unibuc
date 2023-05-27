#ifndef MIJLOC_H
#define MIJLOC_H

#include "statiee.h"
#include <memory>

class Manager
{
    std::vector<std::shared_ptr<Statie>> statii;
    static Manager* instance;
    Manager() = default;
    Manger(const Manager&) = delete;
    Manager& operator=(const Manager&) = delete;
    void adaugaStatie();
public:
    static Manager* getInstance();
    void enter();
    std::shared_ptr<Statie> operator[](std::string nume);
};


#endif // MIJLOC_H
