#include <iostream>

class A
{
private:
    int i;
public:
    A(int n=0) : i(n) {} //konstruktor z inicjalizacja
    void fun() {std::cout << "Wywolano na obiekcie funkcje, ktora w sumie nic nie robi. Skladowa obiektu wynosi " << i << std::endl;}
};

class TSmartPtr
{
private:
    A* wskaznik; //wskaznik na obiekt
public:
    TSmartPtr(A *obiekt = nullptr) : wskaznik(obiekt) {} //konstruktor klasy
    ~TSmartPtr(){} //destruktor klasy
    A* operator->() {return wskaznik;} //przeladowany operator ->
    A& operator*() {return *(operator->());} //przeladowany operator*
};

int main()
{
    A obiekt(9); //konstrukcja klasy A
    TSmartPtr wskaznik = &obiekt; //konstrukcja klasy TSmartPrt
    wskaznik->fun(); //zastosowanie przeladowanego operatora ->
    (*wskaznik).fun(); //zastosowanie przeladowanego opeartora *
}