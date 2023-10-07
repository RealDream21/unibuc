#ifndef STATIEE_H
#define STATIEE_H

#include <iostream>
#include <string>
#include <vector>

template<typename T, typename T1>
bool existaLinieDirecta(T& statie1, T1& statie2)
{
    for(int i = 0; i < statie1.transport; i++){
        for(int j = 0; j < statie2.transport; j++)
            if(statie1[i] == statie2[j])
                return true;
    }
    return false;
}


class I_O
{
    virtual void showInfo()const = 0;
    virtual void readInfo() = 0;
public:
    friend std::ostream& operator<<(std::ostream&, const I_O& other);
    friend std::istream& operator>>(std::istream&, I_O& other);
};

class Statie: public I_O
{
protected:
    static int cnt;
    std::string adresa, nume, cod_st;
    std::vector<int> transport;
    int cod;
public:
    Statie(std::string a = "", std::string n = "")
        :adresa(a), nume(n){
    cnt++;
    cod = cnt;
    }
    void adaugaTransport(int codT);
    virtual void showInfo()const override;
    virtual void readInfo()override;
    virtual std::string tip()const = 0;
    std::string getNume()const;
};

class Urbana: public Statie
{
    bool punct;
public:
    Urbana(bool punct = false, std::string adresa = "", std::string nume = "")
        :Statie(adresa, nume)
    {
        std::string nr;
        int aux = cod;
        while(aux)
        {
            nr += (aux%10) - '0';
            aux/=10;
        }
        std::string cod_st = "SU";
        cod_st += "-";
        cod_st += nr;
    }
    void showInfo()const;
    void readInfo();
    std::string tip()const;
};

class Extraurbana: public Statie
{

public:
    Extraurbana(std::string a = "", std::string n = "")
        :Statie(a, n)
    {
        std::string nr;
        int aux = cod;
        while(aux)
        {
            nr += (aux%10) - '0';
        }
        std::string cod_st = "SE";
        cod_st += "-";
        cod_st += nr;
    }
    void showInfo()const override;
    void readInfo()override;
    std::string tip()const override;
};





#endif // STATIEE_H
