#ifndef CONTRACT_H
#define CONTRACT_H
#include "proprietate.h"
#include <memory>

class Contract
{
protected:
    std::string nume;
    std::shared_ptr<Proprietate> prop;
public:
    virtual ~Contract() = default;
    Contract(std::string nume, std::shared_ptr<Proprietate> p);
    virtual void showInfo()const = 0;
};

class Chirie: public Contract
{
    int perioada;
public:
    Chirie(std::string nume, int perioada, std::shared_ptr<Proprietate> prop);
    int getChirie()const;
    void showInfo()const override;
};

class Vanzare: public Contract
{
    int luna, an, luna_i, an_i;
public:
    Vanzare(int l, int a, int l_i, int a_i, std::string nume, std::shared_ptr<Proprietate> p);
    int getPret()const;
    void showInfo()const override;
};


#endif // CONTRACT_H
