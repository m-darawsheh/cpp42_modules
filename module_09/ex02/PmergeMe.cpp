#include "PmergeMe.hpp"
#include <cctype>

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
    size_t i = 0;
    while (i < token.size())
    {
    if (!std::isdigit(static_cast<unsigned char>(token[i])))
        {
            return false ;
        }
        i++;
    }
    return true;
}

void PmergeMe::validation(std::string arg)
{
   std::istringstream istream(arg);
   std::string token;
   while(getline(istream,token,' '))
   {
        if (token.empty())
            continue; // skip extra spaces
        if (token[0] == '-' || !isnum(token))
        {
            std::cerr<<"Error" << std::endl;
            exit(1);
            return ;
        }
   }
}

template <typename Container>
void print_vec(const Container &c)
{
    typename Container::const_iterator it = c.begin();
    while (it != c.end())
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

void sort_vec(std::string arg)
{
    std::vector<int> v_tem;
    std::istringstream istream(arg);
    std::string token;
    while (getline(istream, token, ' '))
    {
        if (token.empty())
            continue;
        v_tem.push_back(std::atoi(token.c_str()));
    }
    std::vector< std::pair<int,int> > pairs;
    bool has_unpaired = false;
    int unpaired_value = 0;
    for (size_t i = 0; i < v_tem.size(); i += 2)
    {
        if (i + 1 < v_tem.size())
        {
            int a = v_tem[i];
            int b = v_tem[i + 1];
            if (a > b) std::swap(a, b);
            pairs.push_back(std::make_pair(a, b));
        }
        else
        {
            has_unpaired = true;
            unpaired_value = v_tem[i];
        }
    }

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        std::cout << "pair " << i << ": [" << pairs[i].first << ", " << pairs[i].second << "]" << std::endl;
    }
    if (has_unpaired)
    {
        std::cout << "unpaired: " << unpaired_value << std::endl;
    }
}

PmergeMe::PmergeMe(std::string arg)
{
    validation(arg);
    sort_vec(arg);
}