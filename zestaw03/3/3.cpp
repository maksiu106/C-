#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

int nwierszy(string macierz) //funkcja policzy ilosc wierszy
{
    int n = count(macierz.begin(), macierz.end(), '\n');
    return n+1;
}

int nkolumn(string macierz, int wiersze) //funkcja policzy ilosc kolumn
{
    int n = count(macierz.begin(), macierz.end(), ' ');
    return ((n/wiersze)+1);
}

int main()
{
   //wczytanie plikow do stringow i okreslenie liczby wierszy i kolumn
    string A, B, C;
    ifstream plikA;
    ifstream plikB;
    plikA.open("A.txt");
    plikB.open("B.txt");
    stringstream strumien;
    strumien << plikA.rdbuf();
    A = strumien.str();
    strumien.str("");
    strumien << plikB.rdbuf();
    B = strumien.str();
    int wA = nwierszy(A);
    int wB = nwierszy(B);
    int kA = nkolumn(A, wA);
    int kB = nkolumn(B, wB);
    cout << "Macierz A:\n" << A << "\n\nMacierz B:\n" << B << endl;
    if (wA != kB) {cout << "Nie da sie pomnozyc tych macierzy. Liczba wierszy macierzy A musi byc rowna liczbie wierszy macierzy B" << endl; return 0;}
    int macierzA[wA][kA];
    int macierzB[wB][kB];
    
    //wpisywanie stringu do macierzy A
    int i,k,usun;
    for (i=0; i<wA; i++)
    {
        for (k=0; k<kA; k++)
        {
            macierzA[i][k]=stoi(A);
            usun = to_string(macierzA[i][k]).length() + 1;
            A.erase(0, usun);
        }
        A.erase(0,1);
    }

    //wpisywanie stringu do macierzy B
    for (i=0; i<wB; i++)
    {
        for (k=0; k<kB; k++)
        {
            macierzB[i][k]=stoi(B);
            usun = to_string(macierzB[i][k]).length() + 1;
            B.erase(0, usun);
        }
        B.erase(0,1);
    }
    
    //mnozenie macierzy i zapisywanie wyniku do stringu
    string output;
    int wynik [kA][wB]; //macierz na wynik
    int j;
    for(i = 0; i < wA; i++)
    {
        for(j = 0; j < kB; j++)
        {
            wynik[i][j] = 0;
            for(k = 0; k < kA; k++)
            {
                wynik[i][j] += macierzA[i][k] * macierzB[k][j];
            }
            output += (to_string(wynik[i][j]));
            output += " ";
        }
        output += "\n";
    }
    
    //zapisywanie wyniku do pliku
    cout << "\nWynik:\n" << output << endl;
    ofstream plikwynikowy("C.txt");
    plikwynikowy << output;
    plikwynikowy.close();
}