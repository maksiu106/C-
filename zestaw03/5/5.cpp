#include <iostream>
#include "sha256.h"
#include <string>
#include <chrono>

SHA256 sha256;

#define ZERA 5 //ilosc zer, jakie bedziemy probowali miec na poczatku generowanego hasha
#define MAX_NONCE 10000000

std::string generuj(int nbloku, std::string dane, std::string stary_hash)
{
    std::string zera(ZERA, '0'); //stworzenie stringa do porownywania w petli
    std::string hash;
    unsigned long nonce;
    auto poczatek = std::chrono::high_resolution_clock::now();
    for (nonce=0; nonce<MAX_NONCE; ++nonce)
    {
        std::string napis = std::to_string(nbloku)+dane+stary_hash+std::to_string(nonce);
        hash = sha256(napis);
        if (hash.rfind(zera,0)==0)
        {
            std::cout << "Udalo ci sie znalezc odpowiedni nonce: " << nonce << std::endl << "Hash ma postac: " << hash << std::endl;
            auto koniec = std::chrono::high_resolution_clock::now();
            auto czas = std::chrono::duration_cast<std::chrono::seconds>(koniec-poczatek);
            std::cout << "Czas kopania wyniosl: " << czas.count() << " sekund" << std::endl;
            return hash;
        }
    }
    std::cout << "Nie udalo ci sie znalezc potrzebnego nonce i poprawnie zakodowac transakcji" << std::endl;
    return hash;
}

int main()
{
    std::string dane = "Symulacja zapisu jakichś transakcji o jakichś wartościach pieniężnych";
    std::cout << "Zaczynam kopanie" << std::endl;
    std::string wynik = generuj(1, dane, "00000000839a8e6886ab5951d76f411475428afc90947ee320161bbf18eb6048"); //kod pierwszego bloku bitcoina
}