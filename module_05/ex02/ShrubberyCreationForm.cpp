#include "ShrubberyCreationForm.hpp"
#include"Bureaucrat.hpp"

ShrubberyCreationForm :: ShrubberyCreationForm():AForm("ShrubberyCreationForm", "default", SCF_SIGN_GRADE, SCF_EXEC_GRADE)
{
}

ShrubberyCreationForm :: ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
    (void) other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    (void) other;
    return *this;
}

ShrubberyCreationForm :: ~ShrubberyCreationForm(){}

ShrubberyCreationForm :: ShrubberyCreationForm(const std::string &target):AForm("ShrubberyCreationForm", target, SCF_SIGN_GRADE, SCF_EXEC_GRADE)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)const
{
    if(!this->getIsSign())
        throw FormNotSigned();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    std::string file_name = getTarget()+"_shrubbery";
    std::fstream outfile(file_name);
    if (!outfile.is_open())
       throw FileNotOpen();

    
    
}


char *ShrubberyCreationForm::FileNotOpen::what()const throw()
{
    return "file not open";
}