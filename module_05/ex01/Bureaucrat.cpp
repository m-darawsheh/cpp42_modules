#include "Bureaucrat.hpp"
#include "Form.hpp"


Bureaucrat::Bureaucrat():name("default"), grade(77){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& obj):name(obj.name),grade(obj.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat&obj)
{
    (void) obj;
    return *this;
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


void Bureaucrat::signForm(Form obj)
{
    try
    {
        obj.beSigned(*this);
        std ::cout<< this->getName() << " signed " << obj.getName()<< "\n";        
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn’t sign " << obj.getName()<< " because "<<e.what() << '\n';
    }
    

}

std::ostream &operator<<(std::ostream &os, const Bureaucrat&obj)
{
    os << obj.getName()<< ", bureaucrat grade  " << obj.getGrade()<< ".\n";
    return os;
}

