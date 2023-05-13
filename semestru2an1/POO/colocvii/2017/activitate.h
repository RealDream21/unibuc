#ifndef ACTIVITATE_H
#define ACTIVITATE_H
#include "participant.h"

class Activitate{
    vector<Participant*> participanti;
    std::string denumire;
    std::string data;
    Activitate(std::string& denumire, std::string& data);
public:
    virtual ~Activitate();
    virtual void addPersoana();
};

class ActivitateOnline: public Activitate{
    std::string nume_site;
public:
    ActivitateOnline(std::string& nume_siteInit, std::string& denumire, std::string& data)
};

class ActivitateOffline: public Activitate{
    const int durata;
public:
    ActivitateOffline(std::string& denumire, std::string& data, const int durataInit);
};

class CursuriPerfectionareOnline: public ActivitateOnline{
    int numar_credite;
public:
    CursuriPerfectionareOnline(int numar_crediteInit, std::string& nume_siteInit, std::string& denumire, std::string& data);
};

class ConcursuriTematice{
    vector<Participant*> premianti;
public:
    virtual void addPremiant();
};

class ConcursuriTematiceOnline: public ActivitateOnline, public ConcursuriTematice{
    std::nume_site;
public:
};

class ConcursuriTematiceOffline: public ActivitateOffline{
    vector<Participant*> premianti;
};

#endif // ACTIVITATE_H
