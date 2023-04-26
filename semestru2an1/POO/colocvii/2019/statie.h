#ifndef STATIE_H
#define STATIE_H
#include <iostream>
#include <cstring>


class Statie
{
protected:
    static int id_statie;
    int cod_statie;
    std::string cod_unic_statie;
    std::string strada;
    int numar;
    int sector;
public:
    Statie(std::string& stradaInit, const int numarInit, const int sectorInit);
    virtual ~Statie() = default;
    virtual void showStatie() = 0;
    //virtual void set_cod_statie() = 0;
    virtual std::string get_cod_statie() = 0;
};

class Statie_urbana: public Statie{

public:
    Statie_urbana(std::string& stradaInit, const int numarInit, const int sectorInit);
    void showStatie()override;
    std::string get_cod_statie() override;
    //void set_cod_statie() override;
};

class Statie_extraurbana: public Statie{

public:
    Statie_extraurbana();

};


#endif // STATIE_H
