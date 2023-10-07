#ifndef ABONAMENTE_H
#define ABONAMENTE_H
#include <iostream>

class abonament{
protected:
    int pret;
    int nr_minute;
    int nr_sms;
    const int nr_caractere;

public:
    abonament(int nr_caractereInit);
    abonament(int pretInit, int nr_minuteInit, int nr_sms, int nr_caractereInit);
    virtual ~abonament() {};
    void showInfo()const;
    virtual int getPret()const;
    virtual int getMinute()const;
    virtual int getSms()const;
};

class abonament_standard: public abonament{
public:
    abonament_standard(int pretInit, int nr_minuteInit, int nr_sms, int nr_caractereInit);
};

class abonament_vedere: public abonament{
    public:
    abonament_vedere(int pretInit, int nr_minuteInit, int nr_sms, int nr_caractereInit);
};

class abonament_auz: public abonament{
    public:
    abonament_auz(int pretInit, int nr_minuteInit, int nr_sms, int nr_caractereInit);
};


#endif // ABONAMENTE_H
