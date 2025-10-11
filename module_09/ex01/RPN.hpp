#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <list>

class RPN {
    private:
    
    public:
    RPN();
    ~RPN();
    RPN(const RPN &obj);
    RPN(std::string expression);
    RPN &operator=(const RPN &obj);
};

#endif