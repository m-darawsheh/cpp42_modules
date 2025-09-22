#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP


#define SCF_SIGN_GRADE 145
#define SCF_EXEC_GRADE 137
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
    public:
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &obj);

    ShrubberyCreationForm(const std::string &target);
    void execute(Bureaucrat const & executor) const ;
    class FileNotOpen : public std::exception
    {
        const char *what()const throw();
    };
};
#endif
