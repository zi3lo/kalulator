#include <iostream>
#include <string>
#include <Kalkulator.h>

using namespace std;

int main()
{
    string in_s;
    Kalkulator kalk; // tworzymy obiekt klasy
    kalk.rules(); // zasady na ekran
    do
    {
        cout << "?> ";
        getline(cin, in_s);
        kalk.licz(in_s);
    }
    while (in_s != "000");
   // kalk.licz("add 2 3");

    return 0;
}
