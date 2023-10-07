#include "statie.h"

int main()
{
    std::string strada = "muie steaua";
    Statie_urbana A(strada, 12, 4);
    Statie_urbana B(strada, 14, 690);
    std::cout << A.get_cod_statie() << std::endl;
    std::cout << B.get_cod_statie() << std::endl;
    return 0;
}
