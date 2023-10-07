#ifndef PROPRIETATE_H
#define PROPRIETATE_H

#include <string>
#include <iostream>

class Proprietate
{
protected:
    std::string adresa;
    int suprafata, chirie;
public:
    Proprietate(std::string a, int s, int c);
    virtual ~Proprietate() = default;
    virtual int getChirie(int perioada)const = 0;
    virtual void showInfo()const;
};

class Casa: public Proprietate
{
    int niveluri, curte;
public:
    Casa(int n, int cu, std::string a, int s, int c);
    int getChirie(int perioada)const override;
    void showInfo()const override;

};

class Apartament: public Proprietate
{
    int etaj, camere;
public:
    Apartament(int e, int ca, std::string a, int s, int c);
    int getChirie(int perioada)const override;
    void showInfo()const override;
};



#endif // PROPRIETATE_H
