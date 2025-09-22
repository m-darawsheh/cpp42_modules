#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
int main() {
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf == 0)
    {
        std::cout << "The form name is incorrect" << std::endl;
        return 1;
    }
    
    Bureaucrat bob("Bob", 1);
    bob.signForm(rrf);
    bob.executeForm(*rrf);
    delete rrf;
    return 0;
}