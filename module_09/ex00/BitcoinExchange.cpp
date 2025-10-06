#include "BitcoinExchange.hpp"

BitcoinExchange :: BitcoinExchange ()
{

}


BitcoinExchange :: BitcoinExchange(const BitcoinExchange &obj)
{
    this->data_base  = obj.data_base;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if(this != &obj)
    {
        this->data_base  = obj.data_base;
    }
    return (*this);
}

BitcoinExchange ::~BitcoinExchange()
{
}

