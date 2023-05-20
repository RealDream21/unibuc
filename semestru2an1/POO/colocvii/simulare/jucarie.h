#ifndef JUCARIE_H
#define JUCARIE_H
#include <string>
#include <iostream>


class Jucarie
{
protected:
    std::string denumire, tip;
    int dimensiune;
    Jucarie(const std::string& den, const std::string& t, const int dim);
    Jucarie() = default;
public:
    virtual ~Jucarie() = default;
    virtual void showInfo() const;
};

class Clasica: public Jucarie
{
    std::string material, culoare;
public:
    Clasica(const std::string& material, const std::string& culoare, const std::string& den, const std::string& t, const int dim);
    ~Clasica() = default;
    void showInfo()const override;
};

class Educativa: virtual public Jucarie
{
protected:
    std::string abilitate;
public:
    Educativa(const std::string& abilitate, const std::string& den, const std::string& t, const int dim);
    void showInfo()const override;
};

class Electronica: virtual public Jucarie
{
    int nr_baterii;
public:
    Electronica(const int nr_baterii, const std::string& den, const std::string& t, const int dim);
    void showInfo()const override;
};

class Moderna: public Educativa, public Electronica
{
    std::string brand, model;
public:
    Moderna(const std::string& brand, const std::string& model, const std::string& den, const std::string& t, const int dim);
    void showInfo()const override;
};

#endif // JUCARIE_H
