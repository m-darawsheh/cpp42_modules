#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    public:
    AForm* makeForm(std::string name_of_form, std::string target);
    Intern();
    ~Intern();
    Intern(const Intern &obj);
    Intern & operator=(const Intern &obj);

};


#endif