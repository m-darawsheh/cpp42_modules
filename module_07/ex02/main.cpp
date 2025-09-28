#include "Array.hpp"

int main()
{
    Array<int> a(5);
    for (size_t i = 0; i < a.size(); i++)
    {
        a[i] = i * 2;
    }
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    try
    {
        std::cout << a[10] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}