#include "participant.h"

std::vector<std::string> Participant::cnp_util;

char* InvalidCnp::what()
{
    std::cout << "CNP-ul este invalid\n";
}

int checkCnp(const std::string& cnp)
{
    //0 nu e bun, 1 => 18-, 2 => 18+
    bool isKid = false;
    if(cnp.size() != 13)
        return 0;
    if((23 - ((cnp[1]) - '0') * 10 + cnp[2] - '0') < 10)
        return 0;
    if(((23 - ((cnp[1]) - '0') * 10 + cnp[2] - '0') >= 10) && (23 - ((cnp[1]) - '0') * 10 + cnp[2] - '0') <= 18)
        isKid = true;

    if(cnp[3] - '0' > 1)
        return 0;
    if((cnp[5] - '0') * 10 + cnp[6] - '0' > 31)
        return 0;
    if(isKid == true)
        return 1;
    return 2;
}

Participant::Participant(std::string& numeInit, std::string& cnpInit): nume(numeInit)
{
    if(checkCnp(cnpInit) == 0)
        throw InvalidCnp();
    else{
        for(int i = 0; i < cnp_util.size(); i++)
            if(cnpInit == cnp_util[i]){
                throw InvalidCnp();
            }
        cnp = cnpInit;
        cnp_util.push_back(cnp);
        varsta = (23 - ((cnpInit[1]) - '0') * 10 + cnpInit[2] - '0');
    }
}

Participant::Participant(const std::string& numeInit,const std::string& cnpInit, const int rezultatConcursInit): nume(numeInit), rezultatConcurs(rezultatConcursInit)
{
    if(checkCnp(cnpInit) == 0)
        throw InvalidCnp();
    else{
        for(int i = 0; i < cnp_util.size(); i++)
            if(cnpInit == cnp_util[i]){
                throw InvalidCnp();
            }
        cnp = cnpInit;
        cnp_util.push_back(cnp);
        varsta = (23 - ((cnpInit[1]) - '0') * 10 + cnpInit[2] - '0');
    }
}

std::ostream& operator<<(std::ostream& os , const Participant& part)
{
    os << "NUME: " << part.nume << std::endl;
    os << "CNP: " << part.cnp << std::endl;
    os << "VARSTA: " << part.varsta << std::endl;
}
