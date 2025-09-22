#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern(){}
Intern::Intern(const Intern &obj)
{
    (void) obj;
}

Intern & Intern::operator=(const Intern &obj)
{
    (void) obj;
    return *this;
}

AForm* Intern::makeForm(std::string name_of_form, std::string target)
{

    std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int index = 99;

    for (int i = 0 ; i < 3; i++)
    {
        if (form_names[i].compare(name_of_form) == 0)
        {
            index = i;
            break;
        }
    }
    switch (index)
    {
    case 0:
        std::cout << "Intern creates " << form_names[0] << std::endl;
        return new ShrubberyCreationForm(target);
    case 1:
        std::cout << "Intern creates " << form_names[1] << std::endl;
        return new RobotomyRequestForm(target);
    case 2:
        std::cout << "Intern creates " << form_names[2] << std::endl;
        return new PresidentialPardonForm(target);
    default:
        return 0;
    }

}

