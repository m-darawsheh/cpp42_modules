#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>


class BitcoinExchange
{
    private:
    std::map<std::string, float> data_base;
    public:
    BitcoinExchange ();
    BitcoinExchange(std::string input_file);
    BitcoinExchange(const BitcoinExchange &obj);
    BitcoinExchange &operator=(const BitcoinExchange &obj);
    ~BitcoinExchange();


};


#endif