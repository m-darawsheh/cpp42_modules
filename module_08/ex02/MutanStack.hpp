#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:

        MutanStack(): std::stack<T>(){};
        ~MutanStack() {};
        MutanStack(const MutanStack &obj): std::stack<T>(obj);
        MutanStack& operator=(const MutanStack &obj)
        {
            std::stack<T>::opreator=(obj);
            return (*this);
        };

        typedef typename std::deque<T>::iterator iterator;

        iterator begin()
        {
            this->c.begin();
        }
        iterator end()
        {
            this->c.end()
        }


};

#endif
