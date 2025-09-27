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

    const unsigned long pos = str.find('.');
    if(pos != std::string::npos)
    {
        str.erase(pos,1);
    }
    else
        return false;

    int f = str.length() - 1;
    if (str[f] == 'f')
        str.erase(f,1);
    else
        return false;
    if (str.find_first_not_of("1234567890") != std::string::npos)
        return false;
    return true;
}

static bool is_double(std::string str)
{
    int i = 0;
    if(str[i] == '-')
    {
        str.erase(0,1);
    }
    const unsigned long pos = str.find('.');
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


static bool is_char(std::string str)
{
    if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
        return true;
    return false;
}



// paths

static void int_path(std::string str)
{
    int value = std::atoi(str.c_str());
    std::cout << "Int: " << value << std::endl;
    std::cout << "Char: ";
    if (value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (isprint(value))
    {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "Float: " << static_cast<float>(value)<< "f" << std::endl;
    std::cout << "Double: " << static_cast<double>(value)<< std::endl;
}


static void float_path(std::string str)
{
    float value = static_cast<float>(std::atof(str.c_str()));
    std::cout << "Int: " << static_cast<int>(value) << std::endl;
    std::cout << "Char: ";
    if (value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (isprint(static_cast<int>(value)))
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "Float: " << value << "f" << std::endl;
    std::cout << "Double: " << static_cast<double>(value) << std::endl;
}


static void double_path(std::string str)
{
    double value = strtod(str.c_str(),0);
    std::cout << "Int: " << static_cast<int>(value) << std::endl;
    std::cout << "Char: ";
    if (value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (isprint(static_cast<int>(value)))
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "Float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "Double: " << value << std::endl;
}

static void char_path(std::string str)
{
    char value = str[0];
    std::cout << "Int: " << static_cast<int>(value) << std::endl;
    std::cout << "Char: '" << value << "'" << std::endl;
    std::cout << "Float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "Double: " << static_cast<double>(value) << std::endl;
}

static void default_path(std::string str)
{
    if (str.compare("nan") == 0 || str.compare("nanf") == 0)
    {
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
    }
    else if (str.compare("+inf") == 0 || str.compare("+inff") == 0)
    {
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Float: +inff" << std::endl;
        std::cout << "Double: +inf" << std::endl;
    }
    else if (str.compare("-inf") == 0 || str.compare("-inff") == 0)
    {
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Float: -inff" << std::endl;
        std::cout << "Double: -inf" << std::endl;
    }
    else
    {
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Float: impossible" << std::endl;
        std::cout << "Double: impossible" << std::endl;
    }
}




static void convert_to_units(std::string literal, int type)
{
    if (type == 1)
        int_path(literal);
    else if (type == 2)
        float_path(literal);
    else if (type == 3)
        double_path(literal);
    else if (type == 4)
        char_path(literal);
    else
        default_path(literal);
}

// ----------------------->>>>>>>>>>>>>>>>>>>>>>-------------------


void ScalarConverter::convert(const std::string &literal)
{
    if (is_int(literal))
        convert_to_units(literal, 1);
    else if (is_float(literal))
        convert_to_units(literal, 2);
    else if (is_double(literal))
        convert_to_units(literal, 3);
    else if (is_char(literal))
        convert_to_units(literal, 4);
    else
        convert_to_units(literal, 5);
}