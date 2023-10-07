#ifndef CONTAINER_H
#define CONTAINER_H
#include "copii.h"

class Container
{
    std::vector<std::shared_ptr<Copil>> copii;
public:
    Container() = default;
    ~Container() = default;
    void showAll();
    void addChild(std::shared_ptr<Copil>);
    std::shared_ptr<Copil> operator[](std::string&);
};

#endif // CONTAINER_H
