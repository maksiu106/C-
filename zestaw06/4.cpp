#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> vec(15);
    std::iota(vec.begin(), vec.end(), 1);
    auto nazwa = [](std::string arg1, int arg2) {return (arg1+"-"+std::to_string(arg2));};
    auto s = std::accumulate(std::next(vec.begin()), vec.end(), std::to_string(vec[0]), nazwa);
    std::cout << "Uworzony string:\n" << s << std::endl;
}