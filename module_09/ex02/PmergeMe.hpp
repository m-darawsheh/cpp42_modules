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
    std::vector<int> ve_list;
    std::deque<int> q_list;
    public:
    PmergeMe();
    PmergeMe(char *arg[]);
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
    ~PmergeMe();
    void validation(std::string nums);


    
};


#endif