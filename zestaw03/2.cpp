#include <iostream>
#include <string>
#include <stdlib.h>

class BigInt
{
    private:
        std::string liczba;
    public:    
        BigInt(const std::string &wartosc): liczba(wartosc){} //konstruktor
        ~BigInt() {;} //destruktor
        BigInt &operator=(std::string x) {liczba = x; return *this;} //operator przypisania
        BigInt add(const BigInt &x)
        {
            std::string zwracane;
            int length2 = (x.liczba).length(); //dlugosc liczby 2
            int length1 = liczba.length(); //dlugosc liczby 1
            int i, k=length2-1, przeniesienie=0;
            for (i=length1-1; i>=0; k--, i--)
            {
                int wynik;
                if (k>=0) wynik = (x.liczba[k] - '0')+(liczba[i] - '0')+przeniesienie;
                else wynik = (liczba[i] - '0')+przeniesienie;
                if (wynik>9) {przeniesienie=wynik/10; wynik = wynik%10;}
                else przeniesienie=0;
                zwracane.insert(zwracane.begin(), (wynik+'0'));
            }
            if (przeniesienie>0) zwracane.insert(zwracane.begin(),(przeniesienie+'0'));
            return zwracane;
        }
        BigInt subtract(const BigInt &x)
        {
            std::string zwracane;
            int length2 = (x.liczba).length(); //dlugosc liczby 2
            int length1 = liczba.length(); //dlugosc liczby 1
            int i, k=length2-1, pozyczka=0;
            for (i=length1-1; i>=0; k--, i--)
            {
                int wynik;
                if (k>=0) wynik = (liczba[i] - '0')-(x.liczba[k] - '0')-pozyczka;
                else wynik = (liczba[i] - '0')-pozyczka;
                if (wynik<0) {pozyczka=1; wynik+=10;}
                else pozyczka=0;
                zwracane.insert(zwracane.begin(), (wynik+'0'));
            }
            if (zwracane[0]=='0') zwracane.erase(0,1);
            return zwracane;
        }
        BigInt print() const
        {
            std::cout << liczba << std::endl;
            return *this;
        }
};

int main()
{
    std::string s1, s2;
    std::cout << "Wprowadz pierwsza liczbe" << std::endl;
    std::cin >> s1;
    std::cout << "Wprowadz druga liczbe" << std::endl;
    std::cin >> s2;
    bool znak1=0, znak2=0, zamiana=0; //domyslnie - dodatnie znaki obu wartosci oraz nie zamieniono s1 i s2
    if (s1[0]=='-') {znak1=1; s1.erase(0,1);} //ujemny znak
    if (s2[0]=='-') {znak2=1; s2.erase(0,1);} //ujemny znak
    if ((s1.length() < s2.length()) || ((s1.length() == s2.length()) && (s2.at(0) > (s1.at(0))))) {s2.swap(s1); zamiana=1;} //liczba 1 zawsze bedzie wieksza od liczby 2
    BigInt liczba1(s1);
    BigInt liczba2(s2);
    BigInt suma(liczba1.add(liczba2));
    BigInt roznica(liczba1.subtract(liczba2));
    
    //dla dwoch dodatnich
    if (znak1==0 && znak2==0)
    {
        std::cout << "Suma wynosi: " << std::flush;
        suma.print();
        if (zamiana==0) std::cout << "Roznica wynosi: " << std::flush;
        else std::cout << "Roznica wynosi: -" << std::flush; //dodawanie minusa, jesli liczba 2 byla wieksza od pierwszej
        roznica.print();
    }
    
    //dla dwoch ujemnych
    if (znak1==1 && znak2==1)
    {
        std::cout << "Suma wynosi: -" << std::flush;
        suma.print();
        if (zamiana==0) std::cout << "Roznica wynosi: -" << std::flush;
        else std::cout << "Roznica wynosi: " << std::flush;
        roznica.print();
    }
    
    //dla pierwszej dodatniej, drugiej ujemnej
    if (znak1==0 && znak2==1)
    {
        if (zamiana==0) std::cout << "Suma wynosi: " << std::flush;
        else std::cout << "Suma wynosi: -" << std::flush;
        roznica.print();
        std::cout << "Roznica wynosi: " << std::flush;
        suma.print();
    }
    
    //dla pierwszej ujemnej, drugiej dodatniej
    if (znak1==1 && znak2==0)
    {
        if (zamiana==0) std::cout << "Suma wynosi: -" << std::flush;
        else std::cout << "Suma wynosi: " << std::flush;
        roznica.print();
        std::cout << "Roznica wynosi: -" << std::flush;
        suma.print();
    }
}