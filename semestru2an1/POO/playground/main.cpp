#include <iostream>
#include <new>

using namespace std;

int main()
{
    int a;
    int *b = &a;
    a = 10;
    (*b)++;
    cout << a << (*b);

    return 0;
}
