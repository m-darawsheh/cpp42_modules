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
    std::vector<int> ::iterator first = tem.begin();
    std::vector<int> ::iterator second  = tem.begin() + 1;
    int x  = std::abs(*second - *first) ; 
    for (int i = 0; i < static_cast<int> (this->span.size()) ; i++)
    {
        int distance = std::abs(*second - *first);
        if (distance < x)
            x = distance;
        second ++; 
        first ++;
    }
    return x;
}


void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->span.size() + std::distance(begin, end) > N)
        throw OutOfScop();
    this->span.insert(this->span.end(), begin , end);
}