#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const 
{
    if (!this->getIsSign())
        throw FormNotSigned();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    std::cout << "Attempting robotomy...\a" << std::endl;
    
    std::srand(std::time(0));
    bool result = std::rand() % 2;
    if (!result)
        throw FailedCreatRobot();
    std::cout << this->getTarget() << " has been robotomized successfully \n";

}


const char *RobotomyRequestForm::FailedCreatRobot::what () const throw()
{
    return "FailedCreatRobot";
}