#ifndef BILET_H
#define BILET_H
#include <string>
#include <iostream>

class Bilet
{
protected:
    std::string plecare, sosire, data, ora_plecare, cod, durata, serie;
    int distanta;
    float pret;
public:
    Bilet(int distanta, std::string plecare, std::string sosire, std::string data, std::string ora_plecare, std::string cod, std::string durata);
    virtual ~Bilet() = default;
    void showInfo()const;
};

class Clasa1: public Bilet
{

public:
    Clasa1(int nr, int distanta, std::string plecare, std::string sosire, std::string data, std::string ora_plecare, std::string cod, std::string durata);
    void meniuMancare()const;
};

class Clasa2: public Bilet
{


public:
    Clasa2(int nr, int distanta, std::string plecare, std::string sosire, std::string data, std::string ora_plecare, std::string cod, std::string durata);
};

#endif // BILET_H
