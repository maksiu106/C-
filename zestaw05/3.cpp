#include <iostream>
#include <string>

using namespace std;

class MozeWykBadania
{
    bool wykonuje;
public:
    MozeWykBadania(bool wykonuje) : wykonuje(wykonuje) {}
    virtual ~MozeWykBadania() {}
    virtual void czywykonuje()
    {
        if (wykonuje) cout << "Wykonuje badania" << endl;
        else cout << "Aktualnie nie wykonuje badan" << endl;
    }
};

class MozeNauczac
{
    string przedmiot;
public:
    MozeNauczac(const string& przedmiot) : przedmiot(przedmiot) {}
    virtual ~MozeNauczac() {}
    virtual void naucza() {cout << "Przedmiot, ktory prowadzi: " << przedmiot << endl;}
};

class TOsoba 
{
    string imie;
public:
    TOsoba(const string& imie) : imie(imie) {}
    virtual ~TOsoba() {}
    virtual void nazwisko() {cout << "Nazywa sie " << imie << endl;}
};

class MozeBycStudentem
{
    bool studiuje;
public:
    MozeBycStudentem(bool a) : studiuje(a) {}
    virtual ~MozeBycStudentem() {}
    virtual void czystudiuje()
    {
        if (studiuje) cout << "Jest studentem" << endl;
        else cout << "Nie jest studentem" << endl;
    }
};

class TAsystentBadan : virtual public MozeWykBadania, virtual public TOsoba
{
    bool czyjestasystentem;
public:
    TAsystentBadan(const string& imie, bool odpowiedz) : MozeWykBadania(true), TOsoba(imie), czyjestasystentem(odpowiedz) {}
    virtual ~TAsystentBadan() override {}
    virtual void asystuje()
    {
        if (czyjestasystentem) cout << "Jest asystentem badan" << endl;
        else cout << "Nie jest asystentem badan" << endl;
    }
};

class TStudent : virtual public TOsoba, virtual public MozeBycStudentem
{
    string kierunek;
public:
    TStudent(const string& imie, const string& kierunek) : TOsoba(imie), MozeBycStudentem(true), kierunek(kierunek) {}
    virtual ~TStudent() override {}
    virtual void costudiuje() {cout << "Studiuje na kierunku " << kierunek << endl;}
};

class TDoktorant : virtual public TStudent
{
    bool doktorant;
public:
    TDoktorant(const string& kierunek, const string& imie, bool doktorant) : TOsoba(imie), MozeBycStudentem(true), TStudent(imie, kierunek), doktorant(doktorant) {}
    virtual ~TDoktorant() override {}
    virtual void czyjestdoktorantem()
    {
        if (doktorant) cout << "Jest doktorantem" << endl;
        else cout << "Nie jest doktorantem" << endl;
    }
};

class TDoktorantNaucz : virtual public MozeNauczac, virtual public TDoktorant
{
    bool nauczyciel;
public:
    TDoktorantNaucz(const string& imie, const string& kierunek, const string& przedmiot, bool nauczyciel) : MozeNauczac(przedmiot), TOsoba(imie), MozeBycStudentem(true), TStudent(imie, kierunek), TDoktorant(kierunek, imie, true), nauczyciel(nauczyciel) {}
    virtual ~TDoktorantNaucz() override {}
    virtual void czynaucza()
    {
        if (nauczyciel) cout << "Jest nauczycielem akademickim" << endl;
        else cout << "Nie naucza" << endl;
    }
};

class TDoktorantBadacz : virtual public TAsystentBadan, virtual public TDoktorant
{
public:
    TDoktorantBadacz(const string& imie, const string& kierunek) : MozeWykBadania(true), TOsoba(imie), TAsystentBadan(imie, true), MozeBycStudentem(true), TStudent(imie, kierunek), TDoktorant(kierunek, imie, true) {}
    virtual ~TDoktorantBadacz() override {}
    void opowiedz() {cout << "Ogolem jest to osoba bardzo wszechstronna - dziedziczy z dwoch klas, poniewaz zarowno jest asystentem badan, jak i doktorantem" << endl; }
};

int main()
{
    //tworzymy Doktoranta Nauczyciela
    cout << "Tworzymy obiekt typu doktorant-nauczyciel akademicki, ktory nastepnie zastosuje metody z kazdej klasy, z ktorej dziedziczy" << endl;
    TDoktorantNaucz doktorant("Jerzy Jez", "Filozofia", "Etyka", true);
    doktorant.nazwisko();
    doktorant.czystudiuje();
    doktorant.costudiuje();
    doktorant.czyjestdoktorantem();
    doktorant.czynaucza();
    
    //tworzymy studenta
    cout << "\nTworzymy obiekt typu student, ktory nastepnie zastosuje metody z kazdej klasy, z ktorej dziedziczy" << endl;
    TStudent student("Maciej Szybki", "Kognitywistyka");
    student.nazwisko();
    student.czystudiuje();
    student.costudiuje();
    
    //tworzymy Doktoranta Badacza
    cout << "\nTworzymy obiekt typu doktorant-badacz, ktory nastepnie zastosuje metody z kazdej klasy, z ktorej dziedziczy" << endl;
    TDoktorantBadacz badacz("Barbara Zlotopolska", "Porownawcze Studia Cywilizacji");
    badacz.nazwisko();
    badacz.czystudiuje();
    badacz.costudiuje();
    badacz.czyjestdoktorantem();
    badacz.czywykonuje();
    badacz.asystuje();
    badacz.opowiedz();
}