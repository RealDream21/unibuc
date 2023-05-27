#ifndef SERVICII_H
#define SERVICII_H
#include <string>
#include <iostream>
#include <memory>

class Comanda
{



public:
    virtual ~Comanda() = default;
    virtual void showInfo()const = 0;
};

class Standard: public Comanda
{
protected:
    int km;
public:
    Standard(int km);
    virtual ~Standard() = default;
    virtual void showInfo()const;
};

class Handler{};

class Standard_handler: public Handler
{
private:

public:
    static std::shared_ptr<Comanda> generateStandard(int km);
};

class Precomanda: public Standard
{
    std::string nume, data, ora, sursa, destinatie;
    static bool enabled;
public:
    void enablePrecomanda();
    Precomanda() = default;
    Precomanda(int km, std::string nume ,std::string data, std::string ora, std::string sursa, std::string destinatie);
    void showInfo()const override;
};

class Precomanda_handler: public Handler
{
private:
public:
    Precomanda_handler() = default;
    static std::shared_ptr<Comanda> generatePrecomanda(int km, std::string nume ,std::string data, std::string ora, std::string sursa, std::string destinatie);
};

class Cost_control
{
private:
public:
    Cost_control() = default;
    static int getCost(int tarif, int km, std::string sursa, std::string destinatie);
};

class Designated_driver: public Standard
{
    std::string nume1, licenta1, nume2, licenta2;
    static int tarif_fix;
public:
    Designated_driver(int km, std::string n1,std::string l1, std::string n2, std::string l2);
    int getCost(int tarif_firma)const;
    void showInfo()const;
};

class Designated_handler: public Handler
{
private:
public:
    static std::shared_ptr<Comanda> generateDesignated(int km, std::string n1,std::string l1, std::string n2, std::string l2);
};



#endif // SERVICII_H
