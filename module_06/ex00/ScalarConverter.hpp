#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include<string>
#include<iostream>
#include<sstream>
#include<cstdlib>

class ScalarConverter
{
    private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter&obj);
    ScalarConverter& operator=(const ScalarConverter&obj);
    public:
     static void convert(const std::string &literal);
};


#endif