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

Op_type type_of_op(std::string token)
{
    if (token == "+")
        return ADD;
    else if (token == "-")
        return SUBTRACT;
    else if (token == "*")
        return MULTIPLY;
    else
        return DIVIDE;
}

int RPN::checks(std::string token)
{
    Op_type type;
    int top ;
    int top2;
    int res;
    if  (this->stack.size() >= 2)
    {
        top = this->stack.top();
        this->stack.pop();
        top2 = this->stack.top();
        this->stack.pop();
        type = type_of_op(token);
        if (type == ADD)
            res = top2 + top ;
        else if (type == SUBTRACT)
            res = top2 - top;
        else if (type == MULTIPLY)
            res = top2 * top;
        else
        {
            if (top == 0)
            {
                return 0 ;
            }
            res = top2 / top;
        }
        this->stack.push(res);
    }
    return 1;
}

bool is_num(std::string token)
{
    if (isdigit(token[0]))
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
            std::cerr<< "Error" << std::endl;
            return;
        }
        if (is_num(token))
        {
            this->stack.push(atoi(token.c_str()));
            continue;
        }
        if(!checks(token))
        {
            std::cout << "Error" << std::endl;
            return ;
        }

    }
    if (this->stack.size() == 1)
        std::cout << "res is : " <<this->stack.top() << std::endl;
    else 
        std::cerr << "Error" << std::endl;
}


RPN::RPN(std::string expression)
{
    calculate_expression(expression);

}