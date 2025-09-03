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

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout<<"Copy assignment operator called\n" ;
    if (this != &copy)
    {
        this->value = copy.value;
    }
    return *this;
}

int Fixed :: getRawBits(void) const 
{
    std::cout << "getRawBits member function called\n";
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->value = raw;
}

Fixed::Fixed(const int number) : value(number<<fractional_bits)
{
    std ::cout <<"Int constructor called\n";
}

Fixed::Fixed(const float number) : value(static_cast<int>(roundf(number * (1<<fractional_bits))))
{
    std::cout<<"Float constructor called\n";
}

int	Fixed::toInt() const
{
	return (this->value >> fractional_bits);
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(this->value) / (1 << fractional_bits));
}

std::ostream& operator<<(std::ostream&os, const Fixed &object)
{
    os << object.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& num) const
{
    return (this->value > num.value);
}

bool Fixed::operator<(const Fixed& num) const
{
    return (this->value < num.value);
}

bool Fixed::operator>=(const Fixed& num) const
{
    return (this->value >= num.value);
}

bool Fixed::operator<=(const Fixed& num) const
{
    return (this->value <= num.value);
}

bool Fixed::operator==(const Fixed& num) const
{
    return (this->value == num.value);
}

bool Fixed::operator!=(const Fixed& num) const
{
    return (this->value != num.value);
}


Fixed Fixed::operator+(const Fixed& num) const
{
    return (Fixed(this->toFloat() + num.toFloat()));
}

Fixed Fixed::operator-(const Fixed& num) const
{
    return (Fixed(this->toFloat() - num.toFloat()));
}

Fixed Fixed::operator*(const Fixed& num) const
{
    return (Fixed(this->toFloat() * num.toFloat()));
}

Fixed Fixed::operator/(const Fixed& num) const
{
    return (Fixed(this->toFloat() / num.toFloat()));
}

Fixed &Fixed::operator++()
{
    this->value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->value++;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->value--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}
