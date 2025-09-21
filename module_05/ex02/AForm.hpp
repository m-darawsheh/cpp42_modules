#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <exception> 

class Bureaucrat;

class AForm 
{
    private:
    const std::string name ;
    bool is_sign ;
    const int sign_grade;
    const int exec_grade;
    std::string target;
    public:
    // orth style 
    AForm();//
    virtual ~AForm();//
    AForm(const AForm &obj);//
    AForm (const std::string name, const std::string target, const int sign_grade, const int exec_grade);//
    AForm& operator=(const AForm &obj);//
    // geters
    std::string getName()const;//
    std::string getTarget()const;
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
    class FormNotSigned : public std::exception
    {
      const char*what ()  const throw();
    };

    //members
    void beSigned(Bureaucrat &obj);
    virtual void execute(Bureaucrat const & executor) const = 0 ;
};

// std::ostream &operator<<(std::ostream &os ,const  Form &obj);

#endif

// pordox