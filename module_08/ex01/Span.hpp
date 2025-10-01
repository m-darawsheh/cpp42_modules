#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cmath>


class Span
{
    private:
        unsigned int N;
        std::vector<int> span;
    public:
        Span();
        Span(unsigned int n);
        ~Span();
        Span(const Span &obj);
        Span& operator=(const Span &obj);
        void addNumber(const int n);
        int  shortestSpan();
        int  longestSpan();
        void  addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        class OutOfScop : public std::exception
        {
            const char *what()const throw();
        };
        class NoElement : public std::exception
        {
            const char *what()const throw();
        };
        class OneElement : public std::exception
        {
            const char *what()const throw();
        };
};

#endif