#ifndef CONTAINERAIRLINE_H
#define CONTAINERAIRLINE_H

#include "zbor.h"
#include <vector>
#include <memory>

class Ruta
{
    std::vector<std::shared_ptr<Zbor>> zboruri;
    std::string dela, panala;
    int pret;
    int nr_curse;
public:
    Ruta() = default;
    void setInfo();
    friend std::ostream& operator<<(std::ostream& os, const Ruta& other);
    void showZboruri()const;
    void showZboruriSpeciale();
    void addZbor();
};

class Container
{
    std::vector<std::shared_ptr<Ruta>> rute;
    static Container* instance;
    Container() = default;
    Container(const Container&) = delete;
    Container& operator=(const Container&) = delete;
    void adaugaRuta();
    void showRute();
    void addCursa(std::shared_ptr<Ruta> rut);
public:
    static Container* getInstance();
    void enterContainer();
    std::shared_ptr<Ruta> operator[](int i);
};



#endif // CONTAINERAIRLINE_H
