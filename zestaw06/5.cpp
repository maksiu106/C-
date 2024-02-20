#include <iostream>
#include <list>
#include <set>

int main()
{
    std::list<char> lista = {'a','c','b','d','f','e','h','g'};
    auto lambda = [&](const auto& a, const auto& b)->bool
    {
        auto indeks_a = std::find(lista.begin(), lista.end(), a);
        auto indeks_b = std::find(lista.begin(), lista.end(), b);
        if (indeks_a == lista.end() || indeks_b == lista.end()) {std::cout << "Znaku nie ma na liscie" << std::endl; return false;}
        return (std::distance(lista.begin(), indeks_a) < std::distance(lista.begin(), indeks_b)); //zwroci true jesli a jest blizej poczatku listy i false jesli b jest blizej poczatku listy
    };
    
    std::set<char, decltype(lambda)> kontener({'a', 'a', 'a', 'g', 'c', 'b', 'f', 'h', 'c', 'e', 'd', 'e'}, lambda); //tworzenie obiketu typu set z zadanym przez lambdę kryterium sortowania
    for (char c : kontener) std::cout << c;
}