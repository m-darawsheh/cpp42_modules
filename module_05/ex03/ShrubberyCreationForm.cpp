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
    std::ofstream outfile(file_name.c_str());
    if (!outfile.is_open())
       throw FileNotOpen();
    
    outfile << "       oxoxoo    ooxoo\n"
            << "  ooxoxo oo  oxoxooo\n"
            << " oooo xxoxoo ooo ooox\n"
            << " oxo o oxoxo  xoxxoxo\n"
            << "  oxo xooxoooo o ooo\n"
            << "    ooo\\oo\\  /o/o\n"
            << "        \\  \\/ /\n"
            << "         |   /\n"
            << "         |  |\n"
            << "         | O |\n"
            << "         |   |\n"
            << "         |   |\n"
            << "       /_/_\\_\\\n";
    
    outfile.close();
    
}


const char *ShrubberyCreationForm::FileNotOpen::what()const throw()
{
    return "file not open";
}