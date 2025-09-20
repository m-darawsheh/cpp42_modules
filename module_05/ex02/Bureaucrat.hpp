#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception> 

class AForm;

class Bureaucrat 
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat (const Bureaucrat &obj);
    Bureaucrat & operator=(const Bureaucrat &obj);
    Bureaucrat (const std::string name , const int grade);

    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();//
    void decrementGrade();//

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
        // this throw() tell compiler what function can not make throw exception
        // this important because if you throw obj GTHX and you call what to know
        // what is the error and what function in the same time make throw you
        // the program will terminate cause the programe in catch status and can not 
        // so the programe terminate because he can not deal with new catch cause he
        // already in chatch status
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    void signForm(AForm *obj);
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat&obj);

#endif