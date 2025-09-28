#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename X>
void iter (T addarr, const int len, X function)
{
    if (len <= 0)
    return;
    for (int i = 0 ; i < len ; i++)
    {
        function(addarr[i]);
    }
}




#endif