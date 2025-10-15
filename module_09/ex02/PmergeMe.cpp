#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}


PmergeMe::~PmergeMe()
{
    
}


PmergeMe::PmergeMe(const PmergeMe &obj)
{
    (void)obj;
}


PmergeMe  &PmergeMe::operator=(const PmergeMe &obj)
{
    (void)obj;
    return *this;
}

bool isnum(std::string token)
{
    int i = 0;
    while (i < token.size())
    {
        if (!isdigit(token[i]))
        {
            return false ;
        }
    }
    return true;
}

void PmergeMe::validation(std::string arg)
{
   std::istringstream istream(arg);
   std::string token;
   while( getline(istream,token,' '))
   {
        if (token[0] == '-' || !isnum(token))
        {
            std::cerr<<"Error" << std::endl;
            return ;
        }
   }
}


PmergeMe::PmergeMe(std::string arg)
{
    validation(arg);
}