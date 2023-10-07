#include <iostream>
#include "activitate.h"
#include "participant.h"

using namespace std;

int main()
{
    ManagerActivitati* manager = ManagerActivitati::get_manager();
    std::string denumire;
    std::string data;
    denumire = "KANGURU";
    data = "14 aprilie";
    std::shared_ptr<Activitate> CT1 = std::make_shared<ConcursTematic>(13, denumire, data);
    denumire = "SALUTARE";
    std:;shared_ptr<Activitate> CT2 = std::make_shared<ConcursTematic>(14, denumire, data);
    denumire = "SAdaLUTEAR";
    std::shared_ptr<Activitate> CT3 = std::make_shared<ConcursTematic>(14, denumire, data);
    manager->addActivitate(CT1);
    manager->addActivitate(CT2);
    manager->addActivitate(CT3);

    std::string meniuInput = "";
    while(true){
        std::cout << "Alege o optiune din meniu: \n";
        std::cout << "1. Adauga n participanti la o activitate aleasa\n";
        std::cout << "2. Afiseaza participanti pe activitatea aleasa\n";
        std::cout << "3. Afiseaza alfabetic participanii la activitatile dintr o zi aleasa\n";
        std::cout << "4. Iesi\n";
        std::cin >> meniuInput;
        if(meniuInput == "1"){
            std::cout << "Ati ales optiunea 1\n";
            std::cout << "Alegeti activitatea\n";
            manager->showActivitati();
            int indexActivitate;
            std::cin >> indexActivitate;
            int n;
            cin >> n;
            for(int i = 0; i < n; i++){
                std::string nume_participant;
                std::string cnp;
                std::cout << "Dati numele participantului\n";
                std::cin >> nume_participant;
                std::cout << "Dati cnp-ul participantului\n";
                std::cin >> cnp;
            }
        }

    }





    return 0;
}
