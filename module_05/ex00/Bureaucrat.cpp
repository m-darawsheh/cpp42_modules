#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat():name("de"), grade(77){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& obj):name(obj.name),grade(obj.grade)
{
}

Bureaucrat::Bureaucrat(const std::string name , const int grade):name(name),grade(grade)
{
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat::GradeTooHighException");
}



const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat::GradeTooLowException");
}

void Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    ++grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat&obj)
{
    os << obj.getName()<< ", bureaucrat grade  " << obj.getGrade()<< ".";
    return os;
}