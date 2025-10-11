#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr<<"Error"<< std::endl;
    }
    std::string ex = argv[1];
    RPN(ex);
    return 0;
}