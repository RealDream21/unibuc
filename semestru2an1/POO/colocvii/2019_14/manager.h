#ifndef MANAGER_H
#define MANAGER_H

#include "tren.h"

class Manager
{
    std::vector<std::shared_ptr<Tren>> trenuri;

    Manager() = default;
    Manager(Manager&) = delete;
    Manager& operator=(Manager&) = delete;
    static Manager* instance;
public:
    static Manager* getInstance();
    void addTren();
    std::shared_ptr<Tren> operator[](int i);
    void enterMenu();

};

#endif // MANAGER_H
