#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP


#define RRF_SIGN_GRADE 72
#define RRF_EXEC_GRADE 45
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& obj);
    RobotomyRequestForm& operator=(const RobotomyRequestForm &obj);

    RobotomyRequestForm(const std::string &target);
    void execute(Bureaucrat const & executor) const ;
    class FailedCreatRobot : public std::exception
    {
        const char*what ()  const throw();
    };
};

#endif
