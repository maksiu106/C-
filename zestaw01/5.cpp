#include <iostream>

int main()
{
    int x;
    unsigned long long wyniki [50];
    for (x=0; x<50; x++) wyniki[x]=0;
    std::cout << "Ten program liczy wyrazy ciagu Fibonacciego\nJesli chcesz zakonczyc jego dzialanie, wprowadz ctrl+d" << std::endl;
    do
    {
        std::cout << "Ktory wyraz ciagu Fibonacciego chcesz obliczyc?" << std::endl;
        std::cin >> x;
        if (x==EOF);
        else if (wyniki[x]!=0) std::cout << "Ten wyraz ciagu wynosi: " << wyniki[x] << "\n" << std::endl;
        else
        {
            unsigned long long wynik=0;
            if (x==0) wynik=0;
            else if (x==1) wynik=1;
            else
            {
                int a0=0;
                int a1=1;
                for (int i=1; i<x; ++i)
                {
                    wynik = a0+a1;
                    a0 = a1;
                    a1 = wynik;
                    wyniki[i+1] = wynik;
                }
            }
            std::cout << "Ten wyraz ciagu wynosi: " << wynik << "\n" << std::endl;
        }
    } while (!std::cin.eof());
    return 0;
}