#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

#define SZEROKOSC 40

using namespace std;

void dodajspacje(string &tekst)
{
    int i=1;
    string roboczy = tekst; //operowanie na kopii argumentu, nie na oryginale
    int pozycjaspacji=roboczy.find(' ');  //znajduje pierwsza spacje w tekscie
    while (roboczy[SZEROKOSC] != ' ') //petla idzie dopoki na pozycji konca wersu nie bedzie spacji
    {
        i++; //licznik tego, ile spacji dodano
        roboczy.insert(pozycjaspacji, " "); //dodaje spacje obok spacji, ktora byla juz wczesniej
        pozycjaspacji = roboczy.find(' ', pozycjaspacji+i); //szuka nastepnej spacji
        int nastepnaspacja = roboczy.find(' ', pozycjaspacji+i); 
        if (nastepnaspacja > SZEROKOSC) pozycjaspacji=roboczy.find(' '); //jesli pozycjaspacji wskazuje na ostatnia spacje w wersie, nastepna spacje dodamy na poczatek
    }
    for (i=0; i<SZEROKOSC; i++) cout << roboczy[i]; //wypisuje stworzony w ten sposob wers
    cout << endl;
    roboczy = tekst;
    roboczy.erase(SZEROKOSC, roboczy.npos); //przycinamy string roboczy do szerokosci jednego wersu
    int indekserase = roboczy.rfind(' '); //szukamy ostatniej spacji, a wiec miejsca, do ktorego juz wypisalismy
    tekst.erase(0,indekserase+1); //w oryginalnym stringu usuwamy wszystko, co juz wypisalismy
}

int main()
{
    ifstream plik("text.txt"); //wczytuje plik
    string tekst((istreambuf_iterator<char>(plik)), istreambuf_iterator<char>()); //zapisanie tresci pliku w stringu
    while (tekst.size() > SZEROKOSC) dodajspacje(tekst); //funkcja, ktora wypisuje kazda linie, dodaje spacje, po czym usuwa ze stringu to, co wypisala
    cout << tekst << endl; //wypisanie ostatniej linii
}