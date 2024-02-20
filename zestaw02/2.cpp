#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

#define MAX 10000

using namespace std;

void losuj(vector <int> &tablica) //funkcja generuje losowe liczby i wrzuca je do tablicy
{
    for (int i=0; i<MAX; ++i)
    {
        random_device rd;  // seed dla generaotra
        mt19937 generator(rd()); // generuje liczbę z seeda
        uniform_int_distribution<> zakres(1, MAX);
        int n = zakres(generator);
        tablica.push_back(n); //wrzucamy do tablicy to, co wygenerowalismy
    }
}

void wypisz(vector <int> tablica) //funkcja wypisuje wszystko, co jest w tablicy
{
    for (int i=0; i<tablica.size(); i++)
    {
        if (i%10 == 0) cout << endl;
        cout <<  setw(6) << tablica[i] << "   " << flush;
    }
    cout << endl;
}

void sortuj(vector <int> &tablica, int poczatek, int koniec) //funkcja stosujaca algorytm quicksort
{
    int i = poczatek, j = koniec;
    int pivot = tablica[(poczatek+koniec)/2];
    while (i<=j)
    {
        while(tablica[i]<pivot) i++;
        while(tablica[j]>pivot) j--;
        if(i<=j)
        {
            swap(tablica[i], tablica[j]);
            i++;
            j--;
        }
    }
    if(poczatek<j) sortuj(tablica, poczatek, j);
    if(koniec>i) sortuj(tablica, i, koniec);
    return;
}
    

int main()
{
    vector <int> liczby;
    losuj(liczby);
    cout << "Wygenerowane nieuporzadkowane liczby:" << flush;
    wypisz(liczby);
    sortuj(liczby, 0, MAX);
    cout << "\nPo uporzadkowaniu:" << flush;
    wypisz(liczby);    
}