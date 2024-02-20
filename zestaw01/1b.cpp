#include <iostream>
#include <format>
#include <string>

using namespace std;

void wypiszpelen() // x - ilosc gwiazdek do wypisania
{
    cout << format("{:*^10}", '*') << endl;
    return;
}

void wypiszpusty() // x - grubość, y - wewnetrzny bok, k - mówi o parzystości boków
{
    string spacje = format("{: ^6}", ' ');
    cout << format("{:*^10}", spacje) << endl;
}

int main()
{
    int zew = 10, wew = 6;
    int i;
    int grubosc = (zew-wew)/2; //grubość 
    for (i=0; i<grubosc; ++i) wypiszpelen(); //wypisywanie pelnych
    for (i=0; i<wew; ++i) wypiszpusty(); //wypisywanie pustych
    for (i=0; i<grubosc; ++i) wypiszpelen(); //wypisywanie pelnych
}