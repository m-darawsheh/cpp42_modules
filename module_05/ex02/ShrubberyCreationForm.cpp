#include "ShrubberyCreationForm.hpp"

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