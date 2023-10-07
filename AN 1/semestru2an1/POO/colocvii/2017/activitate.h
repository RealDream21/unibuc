#ifndef ACTIVITATE_H
#define ACTIVITATE_H
#include "participant.h"

class Activitate
{
protected:
    std::vector<std::shared_ptr<Participant>> participanti;
    std::string denumire;
    std::string data;
    Activitate(std::string& denumire, std::string& data);
    friend class ManagerActivitati;
public:
    virtual ~Activitate() = default;
    virtual void addPersoana(std::shared_ptr<Participant> part);
    virtual void showPersoane();
};

class ConcursTematic: public Activitate
{
protected:
    std::vector<std::shared_ptr<Participant>> premianti;
private:
    int durata;
public:
    ConcursTematic(int durataInit, std::string& denumireInit, std::string& dataInit);
    void afiseazaPremianti()const;
};

class CursPerfectionare: public Activitate
{
private:
    int nrCredite;
public:
    CursPerfectionare(int nrCredite, std::string&, std::string&);
    virtual void cateCredite();
};

class ConcursTematicOnline: public ConcursTematic
{
    std::string site;
public:
};

class CursPerfectionareOnline: public CursPerfectionare
{
public:
    CursPerfectionareOnline(int nrCredite, std::string&, std::string&);
    void cateCredite();
};

class ManagerActivitati
{
    static std::vector<std::shared_ptr<Activitate>> activitati;
    static ManagerActivitati* manager_;
    ManagerActivitati() = default;
public:
    static ManagerActivitati* get_manager();
    static void printActivitateLaData(std::string& LaData);
    static void addActivitate(std::shared_ptr<Activitate>);
    static void showActivitati();
    static void addParticipantToActivitate(int index, std::shared_ptr<Participant> toAdd);
};



#endif // ACTIVITATE_H
