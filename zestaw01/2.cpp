#include <iostream>
#include <string.h>

int main()
{
    char napis1[100], napis2[100];
    std::cout << "Wpisz pierwszy ciag znakow" << std::endl;
    std::cin.getline(napis1, 100);
    std::cout << "Wpisz drugi ciag znakow" << std::endl;
    std::cin.getline(napis2, 100);
    if ((strcasecmp(napis1,napis2))==0) std::cout << "Napisy sa takie same" << std::endl;
    else std::cout << "Napisy sa rozne" << std::endl;
    return 0;
}