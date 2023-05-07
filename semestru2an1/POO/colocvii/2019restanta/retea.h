#ifndef RETEA_H
#define RETEA_H
#include <vector>
#include "retea.h"
#include "abonamente.h"
#include "abonat.h"


class retea{
    std::vector<std::shared_ptr<abonament>> abonamente;
    std::vector<std::shared_ptr<abonat>> abonati;
    std::string nume_retea;
    static int prefix;
public:
    retea(std::string& nume_reteaInit);
    void Register(std::string& nume_abonat, std::shared_ptr<abonament> ab);
    void addAbonamentType(std::shared_ptr<abonament> ab); //downcasting incercand sa gasesc tipul
    void showAll();
};


#endif // RETEA_H
