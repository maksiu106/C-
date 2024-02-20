#include <iostream>

using namespace std;

#define P(x) std::cout << x << std::endl

class A1
{
    int i { 5 };
public:
    A1(bool) { P("A1 c-tor"); }
    virtual ~A1() { P("A1 d-tor"); }
    int get() const { return i; }
};

class V1 : virtual public A1
{
public:
    V1(bool) : A1(true) { P("V1 c-tor"); }
    virtual ~V1() override { P("V1 d-tor"); }
};

class C1 : virtual public V1
{
public:
    C1(bool) : A1(true), V1(true) {P("C1 c-tor");}
    virtual ~C1() override {P("C1 d-tor");}
};

class B2
{
public:
    B2(bool) {P("B2 c-tor");}
    virtual ~B2() {P("B2 d-tor");}
};

class B3
{
public:
    B3(bool) {P("B3 c-tor");}
    virtual ~B3() {P("B3 d-tor");}
};

class V2 : virtual public A1, public B2
{
public:
    V2(bool) : A1(true), B2(true) {P("V2 c-tor");}
    virtual ~V2() override {P("V2 d-tor");}
};

class C2 : virtual public V2, public B3
{
public:
    C2(bool) : A1(true), V2(true), B3(true) {P("C2 c-tor");}
    virtual ~C2() override {P("C2 d-tor");}
};

class M1
{
public:
    M1(bool) {P("M1 c-tor");}
    virtual ~M1() {P("M1 d-tor");}
};

class M2
{
public:
    M2(bool) {P("M2 c-tor");}
    virtual ~M2() {P("M2 d-tor");}
};

class X : public C1, public C2
{
    M1 m1;
    M2 m2;
public:
    X() : A1(true), V1(true), V2(true), C1(true), C2(true), m1(true), m2(true) {P("X c-tor");}
    virtual ~X() override {P("X d-tor");}
};

int main()
{
    A1 *pa = new X;
    cout << pa->get() << endl;
    delete pa;
}

//(a) jeśli z kodu usunę "override'y" służące zasłonięciu destruktorów kolejnych klas bazowych oraz "virtual" z destruktora klasy bazowej (w tym wypadku zaznaczającym, że destruktor będzie zasłaniany), po linijce kodu "delete pa" wywoływany jest od razu bezpośrednio destruktor klasy bazowej A1, bez wszystkich pośrednich destruktorów, jak to ma miejsce w przypadku pełnego, powyższego kodu; nie zostają zastosowane destruktory wszystkich klas potomnych.
//(b) jeśli zamiast dziedziczenia wirtualnego użyje się dziedziczenia zwykłego klasy A1, powstaje wiele kopii jej składowych i wieloznaczność podczas odnoszenia się do składowej klasy A1.
