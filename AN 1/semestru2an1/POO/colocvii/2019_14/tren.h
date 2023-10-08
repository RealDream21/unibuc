#ifndef TREN_H
#define TREN_H
#include "bilet.h"
#include <vector>
#include <memory>

class Tren
{
protected:
    static int nr_ordine;
    std::vector<std::shared_ptr<Bilet>> bilete;
    std::string tip;
public:
    virtual std::string getTip()const = 0;
    Tren() = default;
    virtual ~Tren() = default;
    virtual void addBilet() = 0;
    virtual void showBilete()const;
};

class Regio: public Tren
{
    std::string getTip()const;
public:
    Regio();
    void addBilet()override;
};

class IRegio: public Tren
{
    std::string getTip()const;
public:
    IRegio();
    void addBilet()override;
};

#endif // TREN_H
