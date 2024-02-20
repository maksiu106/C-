#include <iostream>
#include <stdlib.h>

void konwerter(int x)
{
    while (x>0)
    {
        if (x>=1000) {std::cout << "M" << std::flush; x-=1000;}
        else if (x>=900) {std::cout << "CM" << std::flush; x-=900;}
        else if (x>=500) {std::cout << "D" << std::flush; x-=500;}
        else if (x>=400) {std::cout << "CD" << std::flush; x-=400;}
        else if (x>=100) {std::cout << "C" << std::flush; x-=100;}
        else if (x>=90) {std::cout << "XC" << std::flush; x-=90;}
        else if (x>=50) {std::cout << "L" << std::flush; x-=50;}
        else if (x>=40) {std::cout << "XL" << std::flush; x-=40;}
        else if (x>=10) {std::cout << "X" << std::flush; x-=10;}
        else if (x>=9) {std::cout << "IX" << std::flush; x-=9;}
        else if (x>=5) {std::cout << "V" << std::flush; x-=5;}
        else if (x>=4) {std::cout << "IV" << std::flush; x-=4;}
        else {std::cout << "I" << std::flush; x-=1;}
    }
}

int main(int argc, char *argv[])
{
    int x = atoi(argv[1]); //konwertujemy znakowy argument wywolania funkcji na integer
    if (x<1 || x>3999) std::cout << "Wprowadziles zly argument wywolania programu. Ten program dziala na liczbach 1-3999 i konwertuje je na zapis rzymski." << std::endl;
    else
    {
        std::cout << "Wprowadziles liczbe: " << x << ". W zapisie rzymskim ma ona postac: " << std::flush;
        konwerter(x);
    }
}