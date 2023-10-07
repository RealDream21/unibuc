#ifndef ZBOR_H
#define ZBOR_H

#include <string>
#include <iostream>

class Zbor_Baza
{

public:
    Zbor_Baza() = default;
    virtual ~Zbor_Baza() = default;
    virtual void showInfo()const = 0;
    virtual void citeste() = 0;
};

class Zbor: public Zbor_Baza
{
protected:
    static int cnt;
    int id, discount, pret;
    std::string oras, zi, destinatie, durata;
public:
    Zbor();
    virtual ~Zbor() = default;
    Zbor(std::string o, std::string z, std::string d, std::string du, int pret, int disc);
    virtual void showInfo()const;
    virtual void citeste();
    void setDiscount(int d);
};

class ZborSpecial: public Zbor
{
    int perioada, durataEfectuare;
public:
    ZborSpecial() = default;
    ZborSpecial(std::string o, std::string z, std::string d, std::string du, int pret,  int per, int disc);
    void showInfo()const override;
    void citeste();
};



#endif // ZBOR_H
