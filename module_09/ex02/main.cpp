#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cerr<<"Error"<<std::endl;
        return 1;
    }
    std::string argv = argv[1];
    PmergeMe(argv);
}