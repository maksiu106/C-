#include <iostream>

unsigned long long fib_i(int x) //funkcja wyliczajaca iteracyjnie wyrazy ciagu Fibonacciego
{
    if (x==0) return 0;
    else if (x==1) return 1;
    int a0=0;
    int a1=1;
    unsigned long long wynik=0;
    for (int i=1; i<x; ++i)
    {
        wynik = a0+a1;
        a0 = a1;
        a1 = wynik;
    }
    return wynik;
}

unsigned long long fib_r(int x) //funkcja wyliczajaca rekurencyjnie wyrazy ciagu Fibonacciego
{
    if (x==0) return 0;
    else if (x==1) return 1;
    else return (fib_r(x-1)+fib_r(x-2));
}

int main()
{
    char metoda;
    std::cout << "Wybierz metode, jaka program ma obliczyc 40 pierwszych wyrazow ciagu Fibonacciego\ni - iteracyjnie        r - rekurencyjnie" << std::endl;
    std::cin >> metoda;
    unsigned long long k = 40;
    if (metoda=='i')
    {
        for (int i=0; i<=k; ++i) std::cout << i << "-y wyraz ciagu Fibonacciego wynosi " << fib_i(i) << std::endl;
    }
    else if (metoda=='r')
    {
        for (int i=0; i<=k; ++i) std::cout << i << "-y wyraz ciagu Fibonacciego wynosi " << fib_r(i) << std::endl;
    }
}