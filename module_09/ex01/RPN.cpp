#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}


RPN::RPN(const RPN &obj)
{
    (void) obj;
}

RPN &RPN::operator=(const RPN &obj)
{
    (void)obj;
    return *this;
}

bool is_valid_token(const std::string &token)
{
    if (token.length() == 1 && (isdigit(token[0]) || token == "+" || token == "-" || token == "*" || token == "/"))
    {
        return true;
    }
    return false;
}

// top
// size
// empty
// push
// pop
// swap
void RPN::checks()
{

}

bool is_operator(std::string token)
{
    if (token == "+" ||  token == "-" || token == "*" || token == "/")
        return true;
    return false ;
}

void RPN::calculate_expression(std::string &expression)
{
    std::istringstream my_expr(expression);
    std::string token;
    while(getline(my_expr, token, ' '))
    {
        if(!is_valid_token(token))
        {
            return;
        }
        // if(is_operator(token) && this->stack.size() == )

    }
}


RPN::RPN(std::string expression)
{
    calculate_expression(expression);

}