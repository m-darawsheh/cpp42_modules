#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>  

template<typename T>
void easyfind(T container, int i)
{
    typename T::iterator occ = std::find (container.begin(), container.end(), i);
    if (occ == container.end())
        throw std::exception();
    std::cout<< "find occ in your set : " <<  *occ << std::endl;
}


#endif
