#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception> 

class Bureaucrat;

class AForm 
{
    private:
    const std::string name ;
    bool is_sign ;
    const int sign_grade;
    const int exec_grade;
    public:
    // orth style 
    AForm();//
    ~AForm();//
    AForm(const AForm &obj);//
    AForm& operator=(const AForm &obj);//
    // geters
    std::string getName()const;//
    bool getIsSign()const;//
    int getSignGrade()const;//
    int getExecGrade()const;//

    //exception
    class GradeTooHighException : public std::exception
    {
        const char*what()const throw();
    };
    class GradeTooLowException : public std::exception
    {
      const char*what ()  const throw();
    };

    //members
    virtual void beSigned(Bureaucrat obj) = 0;
};

// std::ostream &operator<<(std::ostream &os ,const  Form &obj);

#endif

// pordox