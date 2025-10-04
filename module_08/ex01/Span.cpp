#include "Span.hpp"

Span :: Span(unsigned int N)
{
    this->N = N;
}


Span :: ~Span()
{
    
}

Span :: Span()
{
    this -> N  = 0;
}

Span :: Span (const Span &obj)
{
    *this = obj;
}

Span &Span::operator=(const Span &obj)
{
    if (this != &obj)
    {
        this->N = obj.N;
        this->span = obj.span;
    }
    return (*this) ;
}


const char *Span::OutOfScop::what()const throw()
{
    return ("can not add num or nums, the SPAN IS FULL\n");
}

const char *Span::NoElement::what()const throw()
{
    return ("there is no element \n");
}

const char *Span::OneElement::what()const throw()
{
    return ("JUST ONE ELEMENT \n");
}


void Span::addNumber(const int n)
{
    if (this->span.size() == this->N)
        throw OutOfScop();
    this->span.push_back(n);
}

int Span::longestSpan()
{
    if (this->span.size() == 0)
        throw NoElement();
    if (this->span.size() == 1)
        throw OneElement();
    std::vector <int> tem = this->span;
    std::sort(tem.begin(), tem.end());
    return (tem[tem.size() - 1] - tem[0]);
}

int Span::shortestSpan()
{
    if (this->span.size() == 0)
        throw NoElement();
    if (this->span.size() == 1)
        throw OneElement();
    std::vector <int> tem = this->span;
    std::sort(tem.begin(), tem.end());
    int minSpan = std::abs(tem[1] - tem[0]);
    for (size_t i = 2; i < tem.size(); ++i)
    {
        int diff = std::abs(tem[i] - tem[i - 1]);
        if (diff < minSpan)
            minSpan = diff;
        if (minSpan == 0) 
            break;
    }
    return minSpan;
}


void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->span.size() + std::distance(begin, end) > N)
        throw OutOfScop();
    this->span.insert(this->span.end(), begin , end);
}