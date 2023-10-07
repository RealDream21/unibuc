#ifndef COPII_H
#define COPII_H
#include "jucarie.h"
#include <memory>
#include <vector>

class Copil
{
protected:
    static int ID;
    int id_spec;
    std::string nume, prenume, adresa;
    int varsta, fapte;
    std::vector<std::shared_ptr<Jucarie>> jucarii;
    Copil(std::string& n, std::string& p, std::string& ad, int v, int f);
public:
    virtual std::string getNume()const;
    virtual ~Copil() = default;
    virtual void showInfo()const;
    virtual void adaugaJucarie(std::shared_ptr<Jucarie>);
};

class Cuminte: public Copil
{
    int dulciuri;
public:
    Cuminte(int d, std::string& n, std::string& p, std::string& ad, int v, int f);
    void showInfo()const override;
};

class Neastamparat: public Copil
{
    int carbuni;
public:
    Neastamparat(int c, std::string& n, std::string& p, std::string& ad, int v, int f);
    void showInfo()const;
};


#endif // COPII_H
