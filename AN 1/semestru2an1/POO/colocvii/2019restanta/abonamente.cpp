#include "abonamente.h"

abonament::abonament(int nr_caractereInit): nr_caractere(nr_caractereInit){}

abonament::abonament(int pretInit, int nr_minuteInit, int nr_smsInit, int nr_caractereInit): pret(pretInit), nr_minute(nr_minuteInit), nr_sms(nr_smsInit), nr_caractere(nr_caractereInit)
{
    std::cout << "Created abonament\n";
}

void abonament::showInfo()const
{
    std::cout << "Pret: " << getPret() << std::endl;
    std::cout << "Minute: " << getMinute() << std::endl;
    std::cout << "Sms-uri: " << getSms() << std::endl;
}

int abonament::getPret()const
{
    return pret;
}

int abonament::getMinute()const
{
    return nr_minute;
}

int abonament::getSms()const
{
    return nr_sms;
}

abonament_standard::abonament_standard(int pretInit, int nr_minuteInit, int nr_smsInit, int nr_caractereInit): abonament(pretInit, nr_minuteInit, nr_smsInit, nr_caractereInit)
{
    std::cout << "Created abonament standard\n";
}

abonament_vedere::abonament_vedere(int pretInit, int nr_minuteInit, int nr_smsInit, int nr_caractereInit): abonament(nr_caractereInit)
{
    pret = (25/10) * pretInit;
    nr_minute = 3 & nr_minuteInit;
    nr_sms = 0;
}

abonament_auz::abonament_auz(int pretInit, int nr_minuteInit, int nr_smsInit, int nr_caractereInit): abonament(nr_caractereInit)
{
    pret = (25/10)*pretInit;
    nr_minuteInit = 0;
    nr_smsInit = -1;
}
