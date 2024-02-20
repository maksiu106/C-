#include <iostream>
#include <iomanip>

using namespace std;

void wypiszpelen(int x) // x - ilosc gwiazdek do wypisania
{
    cout << setfill('*') << setw(x) << "*" << endl;
    return;
}

void wypiszpusty(int x, int y, int k) // x - grubość, y - wewnetrzny bok, k - mówi o parzystości boków
{
    if (k==0) // jeśli oba kwadraty mają taką samą parzystość
    {
        cout << setfill('*') << setw(x) << "*" << setfill(' ') << setw(y) << " " << setfill('*') << setw(x) << "*" << endl;
    }
    else // jeśli kwadraty sa roznej parzystosci
    {
        cout << setfill('*') << setw(x) << "*" << setfill(' ') << setw(y) << " " << setfill('*') << setw(x+1) << "*" << endl;
    }
}

int main()
{
    int zew, wew;
    cout << "Ten program narysuje kwadrat w kwadracie specjalnie dla Ciebie. \nPodaj dlugosc zewnetrznego boku" << endl;
    cin >> zew;
    cout << "Podaj dlugosc wewnetrznego boku" << endl;
    cin >> wew;
    if (wew+2 > zew) {cout << "Wprowadziles niewlasciwe dane" << endl; return 0;}
    int i;
    int grubosc = (zew-wew)/2; //grubość 
    int k = (zew-wew)%2; // mówi o tym, czy kwadraty mają tą samą parzystość
    if (k==0) // jeśli oba kwadraty mają taką samą parzystość
    {
        for (i=0; i<grubosc; ++i) wypiszpelen(zew); //wypisywanie pelnych
        for (i=0; i<wew; ++i) wypiszpusty(grubosc,wew,k); //wypisywanie pustych
        for (i=0; i<grubosc; ++i) wypiszpelen(zew); //wypisywanie pelnych
    }
    else
    {
        for (i=0; i<grubosc; ++i) wypiszpelen(zew); //wypisywanie pelnych
        for (i=0; i<wew; ++i) wypiszpusty(grubosc,wew,k); //wypisywanie pustych
        for (i=0; i<grubosc+1; ++i) wypiszpelen(zew); //wypisywanie pelnych
    }
    return 0;
}