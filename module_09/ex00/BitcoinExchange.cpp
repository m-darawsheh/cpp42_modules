#include "BitcoinExchange.hpp"

#include <cctype> 
// Trim whitespace from both ends of a string
std::string trim(const std::string& str) {
    size_t start = 0;
    while (start < str.size() && isspace(str[start])) ++start;

    if (start == str.size()) return ""; 
    size_t end = str.size() - 1;
    while (end > start && isspace(str[end])) --end;

    return str.substr(start, end - start + 1);
}
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

// string substr (size_t pos = 0, size_t len = npos) const;
// size_t find(char c, size_t pos = 0) const;

 int BitcoinExchange ::valid_date(std::string date)
{
    // 2009-01-02
    std::string year;
    std::string day;
    std::string month;
    if (!(date[4] == '-' && date[7] == '-'))
        return 0;
    date.erase(7,1);
    date.erase(4,1);
    year = date.substr(0, 4);
    month = date.substr(4, 2);
    day = date.substr(6, 2);
    std::string hole_date =  year + month + day;
    for (size_t i = 0 ; i < hole_date.length(); i++)
    {
        if (!isdigit(hole_date[i]))
            return 0;
    }
    int int_year =  atoi (year.c_str());
    int int_month = atoi (month.c_str());
    int int_day = atoi (day.c_str());
    if (int_year < 2009 || int_year > 2022)
        return 0;
    if (int_month <= 0 || int_month > 12)
        return 0;
    if (int_day <= 0 || int_day > 31)
        return 0;
    return 1;
}

static int check_float(std::string  num, int flage)
{
    (void)flage;
    float tem;
    char *end;
    tem = strtof(num.c_str(), &end);
    if (*end != '\0' || num.empty())
        return 0;
    // if (flage == 1)
    // {
    //     if (tem < 0 || tem > 1000)
    //         return 0;
    // }
    // else
    // {
    //     if (tem < 0)
    //         return 0;
    // } 
    return 1;

}

static int check_header_data_base(std::string date, std::string exchange_rate)
{
    if (date != "date" || exchange_rate != "exchange_rate")
        return 0;
    return 1;
}

std::map<std::string, float>  BitcoinExchange::readData ()
{
    std::ifstream Data("data.csv");
    std::map<std::string, float> tem;
    std::string buff;
    std::string first;
    std::string second;
    int quma_pos;
    int iter = 0;
    while(getline(Data, buff))
    {
        quma_pos = buff.find(",", 0);
        first = buff.substr(0,quma_pos);
        trim(first);
        second = buff.substr(quma_pos + 1, buff.length());
        trim(second);
        if (iter == 0)
        {
            if (!check_header_data_base(first, second))
            {
                std::cerr << "date set not valid <header>\n";
                exit(1);
            }
            iter++;
            continue;
        }
        if (!valid_date(first))
        {
            std::cout <<first << std::endl;
            std::cerr << "data set not valid <date>\n";
            exit(1);
        }
        if (!check_float(second, 0))
        {
            std::cout <<second << std::endl;
            std::cerr << "data set not valid <exchange_rate>\n";
            exit(1);
        }
        tem[first] = std::atof(second.c_str());
    }
    return (tem);
}

void BitcoinExchange::print (std::string date, std::string value)
{
    trim(date);
    date.erase(10, date.length());
    trim(value);
    value.erase(0,1);
    // std::cout << date << "=>" << value << std::endl;

    if (!this->is_valid_date)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return ;
    }
    if (!this->is_valid_num)
    {
        if (std::atof(value.c_str()) < 0)
            std::cout << "Error: not a positive number." << std::endl;
        else if (std::atof(value.c_str()) > 1000)
            std::cout << "Error: too large a number." << std::endl;
        else
            std::cout << "Error: bad input => " << value << std::endl;
        return ;
    }
    if (std::atof(value.c_str()) < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return ;
    }
    if (std::atof(value.c_str()) > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return ;
    }
    // std::cout<< date << " " << value << std::endl;
    // = this->data_base.find(trim(date))
    std::map<std::string, float>::iterator it = this->data_base.lower_bound(date);
    // std::cout << "it->first" << it->first << std::endl;
    // std::cout << "it->second" << it->second << std::endl;


    if (it != this->data_base.end())
    {
        std::cout << date << " => " << value << " = " << (std::atof(value.c_str()) * it->second) << std::endl;
    }
    else 
    {
        std::cout << "lower\n";
    }
    return;
}


int check_header_file_input(std::string date, std::string bitcoin)
{
    if (trim(date) != "date" || trim(bitcoin) != "value")
        return 0;
    return 1;
}

void BitcoinExchange::readInputFile(std::string file)
{
    std::ifstream read_input_file(file.c_str());
    std::string buffer;
    std::string first;
    std::string second;
    int pipe_pos;
    this->is_valid_date = true;
    this->is_valid_num = true;
    int iter = 0;
    while (getline(read_input_file, buffer))
    {
        pipe_pos = buffer.find('|', 0);
        first  = buffer.substr(0,pipe_pos);
        trim(first);
        second = buffer.substr(pipe_pos + 1 , buffer.length());
        trim(second);
        if (iter == 0)
        {
            std::cout<< first << " " << second << std::endl;
            if (!check_header_file_input(first, second))
            {
                std::cerr << "Error: bad input => " << buffer << std::endl;
                exit(1);
            }
            iter++;
            continue;
        }
        if (!valid_date(first))
        { 
            this->is_valid_date = false;
        }
        if (!check_float(second,1))
        {
            this->is_valid_num = false;
        }
        print(first, second);
    }
    return;
}

BitcoinExchange :: BitcoinExchange (std::string file)
{

    this->data_base = readData();
    std::cout << "skip database\n";
    readInputFile(file);
}
