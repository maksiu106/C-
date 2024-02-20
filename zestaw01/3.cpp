#include <iostream>
#include <string>
#include <cstring>

int main()
{
    std::string napis;
    std::cout << "Wprowadz napis. Program sprawdzi, czy wprowadziles palindrom" << std::endl;
    std::getline(std::cin,napis);
    napis.erase(remove_if(napis.begin(), napis.end(), isspace), napis.end()); //znajduje biale znaki i usuwa je
    std::string napis2 = napis;
    reverse(napis2.begin(), napis2.end()); //odwraca kolejnosc w napisie2
    if ((strcasecmp(napis.c_str(), napis2.c_str()))==0) std::cout << "Napis jest palindromem" << std::endl;
    else std::cout << "Napis nie jest palindromem" << std::endl;
}