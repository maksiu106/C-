#include <iostream>

int main()
{
    auto fibo = [](int n) //wyrażenie lambda zewnętrzne
    {
        auto inner_fibo = [](int n, const auto& impl) //wyrażenie lambda wewnętrzne
        {
            if (n==0) return 0;
            else if (n==1) return 1;
            else return (impl((n-1),impl)+impl((n-2),impl)); //wywołanie rekurencyjnie impl
        };
        return inner_fibo(n, inner_fibo);
    };
    
    std::cout << "Wypiszmy wartosci ciagu Fibonacciego" << std::endl;
    for (int i=0; i<=20; ++i)
    {
        std::cout << i << ". element ciagu Fibonacciego wynosi: " << fibo(i) << std::endl;
    }
}