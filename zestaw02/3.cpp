#include <iostream>
#include <initializer_list>
#include <iterator>

auto fun(const auto& arg)
{
    double suma;
    for(auto iterator = arg.begin(); iterator != arg.end(); ++iterator) // konstruujemy iterator, ktory przejdzie po wszystkich elementach listy i wyliczy sumę
    {
        suma += *iterator;
    }
    return suma;
}

int main()
{
    std::initializer_list<int> arg = {1,2,5,64};
    std::cout << "Dla argumentow: " << std::flush;
    for(auto iterator = arg.begin(); iterator != arg.end(); ++iterator) std::cout << *iterator << "  " << std::flush; // konstruujemy iterator, ktory przejdzie po liscie i wypisze argumenty
    std::cout << "\nsuma wynosi: " << fun(arg) << std::endl;
}