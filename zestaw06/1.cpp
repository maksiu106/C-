#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>
#include <ctime>
#include <string>

void wypisz(std::vector<int> vec) {for (int &i: vec) std::cout << i << ' ';} //wypisanie elementów wektora

struct Sortowanie
{
    void operator()(std::vector<int>& vec)
    {
        std::sort(vec.rbegin(), vec.rend());
    }
};

int main()
{
    std::vector <int> vec(100);
    std::iota(vec.begin(), vec.end(), 1); //wypełnienie go wartościami od 1 do 100
    
    std::mt19937 generator(time(NULL)); //konstruktor z seedem dla generatora liczb pseudolosowych
    std::shuffle(vec.begin(), vec.end(), generator);
    std::cout << "Liczby w wektorze po uzyciu shuffle: " << std::endl;
    wypisz(vec);
    
    std::sort(vec.rbegin(), vec.rend()); //używanie odwróconych iteratorów; idzie od końca do początku
    std::cout << "\n\nLiczby w wektorze po posortowaniu za pomoca sort: " << std::endl;
    wypisz(vec);
    
    std::shuffle(vec.begin(), vec.end(), generator); //mieszanie ponowne
    Sortowanie obiekt_sortujacy;
    obiekt_sortujacy(vec);
    std::cout << "\n\nWypisanie znowu po sortowaniu za pomoca obiektu funkcyjnego w strukturze: " << std::endl;
    wypisz(vec);
    
    std::shuffle(vec.begin(), vec.end(), generator); //mieszanie ponowne
    std::sort(vec.begin(), vec.end(), [](int a, int b) //sortowanie za pomoca wyrazenia lambda porownujacego najpierw pierwsze liczby
    {
        std::string napis_a = std::to_string(a);
        std::string napis_b = std::to_string(b);
        if (napis_a[0] == napis_b[0]) return a<b;
        else return napis_a[0]<napis_b[0];
    });
    std::cout << "\n\nWypisanie znowu po sortowaniu za pomoca wyrazenia lambda i nietypowego kryterium " << std::endl;
    wypisz(vec);
}