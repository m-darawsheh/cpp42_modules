#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:

        MutantStack(): std::stack<T>(){};
        ~MutantStack() {};
        MutantStack(const MutantStack &obj): std::stack<T>(obj){};
        MutantStack& operator=(const MutantStack &obj)
        {
            std::stack<T>::operator=(obj);
            return (*this);
        };

        typedef typename std::deque<T>::iterator iterator;

        iterator begin()
        {
           return(this->c.begin());
        }
        iterator end()
        {
            return (this->c.end());
        }


};

#endif
