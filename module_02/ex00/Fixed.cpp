#include "Fixed.hpp"

Fixed ::Fixed ()
{
    std::cout<<"Default constructor called\n";
    value = 0;
}

Fixed ::~Fixed()
{
    std::cout<<"destructor \n";
}

Fixed ::Fixed(const Fixed &copy)
{
    std::cout<<"Copy constructor called\n";
    this->value = copy.value;
}

Fixed &Fixed::operator = (const Fixed &copy)
{
    std::cout<<"Copy assignment operator called\n" ;
    if (this != &copy)
    {
        this->value = copy.value;
    }
    return *this;
}

int Fixed:: getRawBits(void) const 
{
    std::cout << "getRawBits member function called\n";
    return value;
}

void Fixed:: setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->value = raw;
}