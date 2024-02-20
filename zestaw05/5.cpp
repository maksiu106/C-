#include <iostream>
#include <memory>

using namespace std;

class DisplayDriver
{
public:
    virtual ~DisplayDriver() {}
    virtual void wykonaj() {}
};

class PrinterDriver
{
public:
    virtual ~PrinterDriver() {}
    virtual void wykonaj() {}
};

class HRDD
{
public:
    void sterowniki() {cout << "Program symuluje pobranie wysokiej rozdzielczosci sterownikow ekranu" << endl;}
};

class LRDD
{
public:
    void sterowniki() {cout << "Program symuluje pobranie niskiej rozdzielczosci sterownikow ekranu" << endl;}
};

class HRPD
{
public:
    void sterowniki() {cout << "Program symuluje pobranie wysokiej rozdzielczosci sterownikow drukarki" << endl;}
};

class LRPD
{
public:
    void sterowniki() {cout << "Program symuluje pobranie niskiej rozdzielczosci sterownikow drukarki" << endl;}
};

class HighResDispDrvr : public DisplayDriver
{
private:
    unique_ptr<HRDD> obiekt;
public:
    HighResDispDrvr(){}
    void wykonaj() override {obiekt->sterowniki();}
};

class LowResDispDrvr : public DisplayDriver
{
private:
    unique_ptr<LRDD> obiekt;
public:
    LowResDispDrvr(){}
    void wykonaj() override {obiekt->sterowniki();}
};

class HighResPrtDrvr : public PrinterDriver
{
private:
    unique_ptr<HRPD> obiekt;
public:
    HighResPrtDrvr(){}
    void wykonaj() override {obiekt->sterowniki();}
};

class LowResPrtDrvr : public PrinterDriver
{
private:
    unique_ptr<LRPD> obiekt;
public:
    LowResPrtDrvr(){}
    void wykonaj() override {obiekt->sterowniki();}
};

class ResFactory
{

public:
    virtual unique_ptr<PrinterDriver> getPrtDrvr() = 0;
    virtual unique_ptr<DisplayDriver> getDispDrvr() = 0;
    virtual void reset() {}
};

class LowResFactory : public ResFactory
{
public:
    unique_ptr<PrinterDriver> getPrtDrvr() override {return make_unique<LowResPrtDrvr>();}
    unique_ptr<DisplayDriver> getDispDrvr() override {return make_unique<LowResDispDrvr>();}
};

class HighResFactory : public ResFactory
{
public:
    unique_ptr<PrinterDriver> getPrtDrvr() override {return make_unique<HighResPrtDrvr>();}
    unique_ptr<DisplayDriver> getDispDrvr() override {return make_unique<HighResDispDrvr>();}
};

int main() {
unique_ptr<ResFactory> fabryka(new LowResFactory);
unique_ptr<DisplayDriver> ddrv = fabryka->getDispDrvr();
unique_ptr<PrinterDriver> pdrv = fabryka->getPrtDrvr();
ddrv->wykonaj();
pdrv->wykonaj();

fabryka.reset(new HighResFactory);
ddrv = fabryka->getDispDrvr();
pdrv = fabryka->getPrtDrvr();
ddrv->wykonaj();
pdrv->wykonaj();
}