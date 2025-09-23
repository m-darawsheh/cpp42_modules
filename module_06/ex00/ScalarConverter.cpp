#include "ScalarConverter.hpp"



ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter&obj)
{
    (void) obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    (void)obj;
    return *this;
}

//checks
static bool is_int(std::string str)
{
    int i = 0;
    if(str[i] == '-')
    {
        str.erase(0,1);
    }
    else if(str.find_first_not_of("1234567890") != std::string::npos)
    {
        return false;
    }
    return true;




}


static bool is_float(std::string str)
{
    int i = 0;
    if(str[i] == '-')
    {
        str.erase(0,1);
    }

    int pos = str.find('.');
    if(pos != std::string::npos)
    {
        str.erase(pos,1);
    }
    else
        return false;

    pos = str.find('f');
    if(pos != std::string::npos)
    {
        str.erase(pos,1);
    }
    else
        return false;
    if (str.find_first_not_of("1234567890") != std::string::npos)
        return false;
    return true;
}


static bool is_double(std::string str)
{
    
}


static bool is_char(std::string str)
{
    
}



// paths

static void int_path(std::string str)
{
    
}


static void float_path(std::string str)
{
    
}


static void double_path(std::string str)
{
    
}


static void char_path(std::string str)
{
    
}

static void default_path(std::string str)
{

}

// ----------------------->>>>>>>>>>>>>>>>>>>>>>-------------------


void ScalarConverter::convert(const std::string &literal)
{
    if (is_int(literal))
        int_path(literal);
    else if (is_float(literal))
        float_path(literal);
    else if (is_double(literal))
        double_path(literal);
    else if (is_char(literal))
        char_path(literal);
    else
        default_path(literal);
}