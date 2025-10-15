#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>

class PmergeMe
{
    private:
    std::vector<int> list;
    std::deque<int> list;
    public:
    PmergeMe();
    PmergeMe(std::string arg);
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
    ~PmergeMe();
    void validation(std::string nums);
    
};


#endif