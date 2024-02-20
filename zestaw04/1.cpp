#include <iostream>
#include <string>
#include <cstring>
#include <compare>

using namespace std;

class TKlasa {
public:
    TKlasa(const char* c): str(c) {} //konstruktor z inicjalizacja
    const char* operator[](const char* s) const
    {
        const char* kopia = str.c_str();
        const char* wynik = strstr(kopia,s);
        return wynik;
    }
    auto operator<=>(const TKlasa& s) const
    {
        return (str <=> s.str);
    }
private:
    string str;
};

int main()
{
    TKlasa napis1("Mam bardzo stara dusze, czasem czuje, jak wypelnia mnie kosmos.");
    TKlasa napis2("Kiedys wszyscy bedziemy gwiazdami na firmamencie wszechswiata");

    cout << "Dla napisu 1 szukany jest ciag znakow 'czuje, jak wypelnia mnie kosmos'" << endl;
    const char* wynik = napis1.operator[]("czuje, jak wypelnia mnie kosmos");
    if (wynik != nullptr) cout << "Dany ciag znakow wystapil w napisie" << endl;
    else cout << "Nie ma takiego ciagu w napisie" << endl;

    cout << "Dla napisu 2 szukany jest ciag znakow 'czuje, jak wypelnia mnie kosmos'" << endl;
    wynik = napis2.operator[]("czuje, jak wypelnia mnie kosmos");
    if (wynik != nullptr) cout << "Dany ciag znakow wystapil w napisie" << endl;
    else cout << "Nie ma takiego ciagu w napisie" << endl;

    napis1.operator<=>(napis2);
}