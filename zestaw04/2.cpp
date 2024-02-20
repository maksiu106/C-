#include <iostream>
#include <cmath>

class TComplex
{
public:
    TComplex(double re, double im): re(re), im(im) {} //konstruktor z inicjalizacja
    friend std::ostream& operator<<(std::ostream& os, TComplex const liczba); //deklaracja przyjazni z przeciazonym operatorem globalnym <<
    
    TComplex operator()(double re, double im) const {return TComplex (re,im);} //operator funkcyjny
    TComplex operator+(const TComplex& liczba) {return TComplex((re+liczba.re), (im+liczba.im));} //przeciazony operator dodawania
    TComplex operator-(const TComplex& liczba) {return TComplex((re-liczba.re), (im-liczba.im));} //przeciazony operator odejmowania
    
    TComplex conj() const {return TComplex(re, (-im));} //metoda zwracajaca sprzezenie zespolone
    double abs() const {return sqrt(im*im + re*re);} //metoda zwracajaca modul liczby
    
    TComplex operator*(const TComplex& liczba) {return TComplex((re*liczba.re-im*liczba.im), (re*liczba.im+im*liczba.re));} //przeciazony operator mnozenia
    TComplex operator/(const TComplex& liczba) //przeciazony operator dzielenia
    {
        double dzielnik = liczba.im*liczba.im + liczba.re*liczba.re;
        return TComplex(((re*liczba.re+im*liczba.im)/dzielnik), ((liczba.re*im-liczba.im*re)/dzielnik));
    }    
    
private:
    double re{0}, im{0};
};

std::ostream& operator<<(std::ostream& os, TComplex const liczba) //przeciazony operator <<
{
    os << "(" << liczba.re << "," << liczba.im << ")" << std::flush;
    return os;
}

int main()
{
    TComplex liczba1(2,3); //uzycie konstruktora i inicjalizacja
    TComplex liczba2(7,12);
    std::cout << "Pierwsza liczba wynosi: " << liczba1 << ", natomiast druga: " << liczba2 << std::endl;
    std::cout << "Ich sprzezenia to odpowiednio: " << liczba1.conj() << " oraz " << liczba2.conj() << std::endl;
    std::cout << "moduly to odpowiednio: " << liczba1.abs() << " oraz " << liczba2.abs() << std::endl;
    std::cout << "Wynik ich dodawania to: " << liczba1+liczba2 << std::endl;
    std::cout << "Wynik ich odejmowania to: " << liczba1-liczba2 << std::endl;
    std::cout << "Wynik ich mnozenia to: " << liczba1*liczba2 << std::endl;
    std::cout << "Wynik ich dzielenia to: " << liczba1/liczba2 << std::endl;
}