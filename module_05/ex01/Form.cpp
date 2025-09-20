#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():name("default"), is_sign(false), sign_grade(10), exec_grade(10)
{
}

Form::~Form(){}

Form::Form (const Form &obj):name(obj.name), is_sign(obj.is_sign), sign_grade(obj.sign_grade), exec_grade(obj.exec_grade)
{}

Form& Form::operator=(const Form&obj)
{
    (void) obj;
    return *this;
}


std::string Form :: getName()const
{
    return name;
}

bool Form :: getIsSign()const 
{
    return is_sign;
}

int Form::getSignGrade()const
{
    return sign_grade;
}

int Form::getExecGrade()const
{
    return exec_grade;
}

const char* Form::GradeTooHighException::what()const throw()
{
    return("Form::GradeTooHighException\n");
}

const char* Form::GradeTooLowException::what()const throw()
{
    return ("Form::GradeTooLowException\n");
}



void Form::beSigned(Bureaucrat obj)
{
    if (obj.getGrade() > sign_grade )
        return throw Form::GradeTooLowException();
    is_sign = true;
}





std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << obj.getName()<< ", form signable: " << obj.getIsSign() << ", form sign grade: "<<obj.getSignGrade()<<", form execute grade: "<< obj.getExecGrade()<< ".\n";
    return os;
}







