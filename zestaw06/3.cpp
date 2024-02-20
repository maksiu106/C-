#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <numeric>

int main()
{
    std::map<int,std::string> mis = {{0,"zero"},{1,"jeden"},{2,"dwa"},{3,"trzy"},{4,"cztery"},{5,"piec"},{6,"szesc"},{7,"siedem"},{8,"osiem"},{9,"dziewiec"}};
    std::vector<int> liczby(10);
    std::iota(liczby.begin(), liczby.end(), 1); //wypełnienie wektora wartościami od 1 do 10
    std::ostream_iterator<std::string> wypisz(std::cout,"\n");
    std::transform(liczby.begin(), liczby.end(), wypisz, [&mis](int i) {return mis[i];});
}