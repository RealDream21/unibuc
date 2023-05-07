#ifndef ABONAT_H
#define ABONAT_H
#include "abonamente.h"
#include <string>
#include <memory>


class abonat
{
    std::string nume;
    std::string numar_telefon; //unic, cu prefix
    std::shared_ptr<abonament> ab;
public:
    abonat(std::string& numeInit, std::string& numar_telefonInit, std::shared_ptr<abonament>& abInit);
    void showInfo()const;
};

#endif // ABONAT_H
