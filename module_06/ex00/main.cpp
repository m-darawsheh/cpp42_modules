#include "ScalarConverter.hpp"
#include <iomanip>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr<<"invalid args\n";
        return 1;
    }
    std::cout<<std::fixed << std::setprecision(1);
    ScalarConverter::convert(argv[1]);
    return 0;
}