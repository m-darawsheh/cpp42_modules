#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <sstream>

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
    void RPN::checks();

};

#endif