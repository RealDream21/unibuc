#include "manager.h"

int main()
{
    Manager* myMan = Manager::getInstance();
    myMan->addTren();
    myMan->enterMenu();

    return 0;
}
