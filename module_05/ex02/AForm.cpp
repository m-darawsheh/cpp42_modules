#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm():name("default"), is_sign(false), sign_grade(10), exec_grade(10)
{
}

AForm::~AForm(){}

AForm::AForm (const AForm &obj):name(obj.name), is_sign(obj.is_sign), sign_grade(obj.sign_grade), exec_grade(obj.exec_grade)
{}

AForm& AForm::operator=(const AForm&obj)
{
    (void) obj;
    return *this;
}


std::string AForm :: getName()const
{
    return name;
}

bool AForm :: getIsSign()const 
{
    return is_sign;
}

int AForm::getSignGrade()const
{
    return sign_grade;
}

int AForm::getExecGrade()const
{
    return exec_grade;
}

const char* AForm::GradeTooHighException::what()const throw()
{
    return("AForm::GradeTooHighException\n");
}

const char* AForm::GradeTooLowException::what()const throw()
{
    return ("AForm::GradeTooLowException\n");
}



void AForm::beSigned(Bureaucrat obj)
{
    if (obj.getGrade() > sign_grade )
        return throw AForm::GradeTooLowException();
    is_sign = true;
}





// std::ostream &operator<<(std::ostream &os, const AForm &obj)
// {
//     os << obj.getName()<< ", Aform signable: " << obj.getIsSign() << ", Aform sign grade: "<<obj.getSignGrade()<<", Aform execute grade: "<< obj.getExecGrade()<< ".\n";
//     return os;
// }






