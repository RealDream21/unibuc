#include "retea.h"


int main()
{
    std::string nume_retea = "Telekom";
    retea h(nume_retea);
    std::shared_ptr<abonament> ab = std::make_shared<abonament_auz>(1, 2, 3, 4);
    std::string nume_abonat = "Costel";
    h.Register(nume_abonat, ab);

    h.showAll();

    return 0;
}
