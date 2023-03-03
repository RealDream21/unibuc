#include <iostream>

using namespace std;

class Test
{
    int nota;
    string text;

public:
    Test(int nr)
    {
        nota = nr;
    }
    Test(int nr, string s)
    {
        nota = nr;
        text = s;
    }
    Test()
    {
        nota = 4;
    }
    int getNota()
    {
        return nota;
    }
    friend string getText(Test*);
};

string getText(Test* xd)
{
    return (*xd).text;
}


int main()
{
    Test mate(4, "rauuul");
    cout << getText(&mate);
    return 0;
}
