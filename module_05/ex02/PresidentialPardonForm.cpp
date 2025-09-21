#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
PresidentialPardonForm :: PresidentialPardonForm():AForm("PresidentialPardonForm", "default", PPF_SIGN_GRADE, PPF_EXEC_GRADE)
{
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
{
    (void) obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm&obj)
{
    (void) obj;
    return *this;
}



PresidentialPardonForm::PresidentialPardonForm(const std::string &target):AForm("PresidentialPardonForm", target, PPF_SIGN_GRADE, PPF_EXEC_GRADE)
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)const
{
    if (!this->getIsSign())
        throw FormNotSigned();
    if(executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    std::cout << getTarget() << "has been pardoned by Zaphod Beeblebrox .";
}