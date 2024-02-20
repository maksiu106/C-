#include <iostream>

class A
{
private:
    int i;
public:
    A(int n=0) : i(n) {} //konstruktor klasy z inicjalizacja
    A& operator++() {++i; return *this;} //operator inkrementacji prefiksowej
    A operator++(int) //operator inkrementacji postfiksowej
    {
        A tymczasowy = *this;
        ++*this;
        return tymczasowy;
    }
    A& operator--() {--i; return *this;} //operator dekrementacji prefiksowej
    A operator--(int) //operator dekrementacji postfiksowej
    {
        A tymczasowy = *this;
        --*this;
        return tymczasowy;
    }
    A& operator+() {i=(+i); return *this;} //jednoargumentowy operator +
    A& operator-() {i=(-i); return *this;} //jednoargumentowy operator -
    A operator+(const A& wartosc) {return A(i+wartosc.i);} //dwuargumentowy operator +
    A operator-(const A& wartosc) {return A(i-wartosc.i);} //dwuargumentowy operator -
    friend std::ostream& operator<<(std::ostream& os, A const liczba); //deklaracja przyjazni z przeciazonym operatorem globalnym <<
};

std::ostream& operator<<(std::ostream& os, A const liczba) //przeciazony operator <<
{
    os << liczba.i << std::flush;
    return os;
}

int main()
{
    A obiekt(5);
    A drugi(7);
    std::cout << "Ilosc operatorow prefiksowych, ktore mozna postawic przed obiektem, zeby kod dzialal - dowolna - niezaleznie od tego, czy plusow, czy minusow, aczkolwiek dokladne dzialanie programu jest rozne dla ilosci parzystej oraz nieparzystej - jako ze dla nieparzystych jeden ze znakow traktowany jest wowczas jako operator jednoargumentowy + lub - (i to on dziala pierwszy na obiekt), nie jako operator inkrementacji.\n" << std::endl;
    std::cout << "Dla operatorow postfiksowych natomiast niezaleznie od tego, ile bedzie znakow, operacja inkrementacji/dekrementacji wykona sie jedynie raz - przynajmniej w zastosowanej przeze mnie implementacji problemu\n" << std::endl;
    std::cout << "Skladowa obiektu wynosi " << obiekt << ". Po zastosowaniu szesciu plusow w prefiksie wynosi ona " << ++++++obiekt << std::endl;
    std::cout << "Dla otrzymanej wartosci " << obiekt << " zastosowanie szesciu plusow w postfiksie spowoduje otrzymanie wartosci " << std::flush;
    obiekt++++++;
    std::cout << obiekt << std::endl << std::endl;
}