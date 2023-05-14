#include "activitate.h"

Activitate::Activitate(std::string& denumireInit, std::string& dataInit): denumire(denumireInit), data(dataInit){}

void Activitate::addPersoana(std::shared_ptr<Participant> part)
{
    participanti.push_back(part);
}

void Activitate::showPersoane()
{
    for(auto p = participanti.begin(); p != participanti.end(); p++)
        std::cout << **p << std::endl;
}

ConcursTematic::ConcursTematic(int durataInit, std::string& denumireInit, std::string& dataInit): Activitate(denumireInit, dataInit), durata(durataInit)
{}

std::vector<std::shared_ptr<Activitate>> ManagerActivitati::activitati;
ManagerActivitati* ManagerActivitati::manager_ = nullptr;

ManagerActivitati* ManagerActivitati::get_manager()
{
    if(manager_ == nullptr)
        manager_ = new ManagerActivitati();
    else return manager_;
}

void ManagerActivitati::printActivitateLaData(std::string& LaData)
{
    for(int i = 0; i < activitati.size(); i++){
        if(activitati[i]->data == LaData){
            std::cout << activitati[i]->denumire << " " << std::endl;
            activitati[i]->showPersoane();
        }
    }
}

void ManagerActivitati::addActivitate(std::shared_ptr<Activitate> activ)
{
    activitati.push_back(activ);
}

void ManagerActivitati::showActivitati()
{
    for(int i = 0; i < activitati.size(); i++){
        std::cout << i << ". " << activitati[i]->denumire << std::endl;
    }
}

void ManagerActivitati::addParticipantToActivitate(int index, std::shared_ptr<Participant> toAdd)
{
    activitati[index]->addPersoana(toAdd);
}

