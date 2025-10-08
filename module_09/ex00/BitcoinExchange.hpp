#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cctype> 
#include <cstdlib>  
class BitcoinExchange
{
    private:
    std::map<std::string, float> data_base;

    bool is_valid_date;
    bool is_valid_num;
    public:
    BitcoinExchange ();
    BitcoinExchange(std::string input_file);
    BitcoinExchange(const BitcoinExchange &obj);
    BitcoinExchange &operator=(const BitcoinExchange &obj);
    ~BitcoinExchange();
    std::map<std::string, float> readData();
    void readInputFile(std::string file);
    int valid_date(std::string date);
    void print(std::string date, std::string value);



};


#endif