#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm :: RobotomyRequestForm():AForm("RobotomyRequestForm", "default", RRF_SIGN_GRADE, RRF_EXEC_GRADE)
{
    
}


RobotomyRequestForm :: RobotomyRequestForm(const RobotomyRequestForm &other)
{
    (void) other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    (void) other;
    return *this;
}


RobotomyRequestForm :: ~RobotomyRequestForm(){}

RobotomyRequestForm :: RobotomyRequestForm(const std::string &target):AForm("RobotomyRequestForm", target, RRF_SIGN_GRADE, RRF_EXEC_GRADE)
{
}