#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <sstream>
#include <cstdlib>



enum Op_type {
    ADD,     
    SUBTRACT,
    MULTIPLY,
    DIVIDE   
};

class RPN {
    private:
    std::stack<int> stack;
    public:
    RPN();
    ~RPN();
    RPN(const RPN &obj);
    RPN(std::string expression);
    RPN &operator=(const RPN &obj);
    void calculate_expression(std::string &expression);
    int checks(std::string token);

};

#endif