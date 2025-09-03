#ifndef FIXED_HPP
 #define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed
{
    private:
    int value;
    static const int fractional_bits = 8;
    public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &copy);
    Fixed &operator = (const Fixed &copy);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    Fixed(const int number);
    Fixed(const float number);
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os,const Fixed &object);


#endif